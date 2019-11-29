# Abstract

- This document explores the journey of how ip data serves 25 million Geolocation API calls from 10 infinitely scalable global endpoints for \$150 A Month by Jonathan Kosgei.

## Background

1. I woke up on Black Friday last year to a barrage of emails from users **reporting 503 errors from the ipdata API**.
   1. Our users typically call our API on each page request on their websites to geolocate their users and localize their content. So this particular failure was directly impacting our users' websites on the biggest sales day of the year.
   2. I only lost one user that day but I came close to losing many more.
      1. **This sequence of events and their inexplicable nature** - cpu, mem and i/o were nowhere near capacity. As well as **concerns on how well we would scale, given our outage, were a big wake up call to rethink our existing infrastructure**.
2. Tech stack At the Time
   1. Japronto Python Framework, Redis, AWS EC2 nodes, Elastic Loadbalancers, Route53 Latency Based Routing
3. Choosing A New Tech Stack
   1. API Gateway <=> Lambda <=> DynamoDB
   2. Around the time, the Author started to seriously look into using API Gateway with AWS Lambda given their
      1. Favorable pricing - $3.5 per million on API Gateway and $0.2 per million for AWS Lambda
      2. Infinite scale and high throughput - **the account limit on API Gateway is 10,000 requests per second or about 864M calls daily. A limit that is possible to lift by opening a support request.**
   3. This also made it economically viable to have endpoints in numerous AWS regions to provide low latencies to all Ipdata's users all over the globe.

## Designing a Multi-Regional API Gateway API

1. Architecture challenges to be solved include
   1. **Each lambda function in each region needed to be able to lookup usage data in a database in the same region to minimize latency**.
   2. Need to figure out a way to determine the number of API calls made by each IP Address, Referrer and API Key
   3. A means to sync the usage data in all regions.
      1. Ex. If Route53 sent 10,000 requests to Sydney endpoint then decided to send the next 50,000 to Seoul endpoint (depending on which had the least network latency at that point in time). **Each lambda function would need to know that the user had made 60,000 requests in total to properly handle rate limiting**.
   4. Authorization
      1. **API Gateway provides usage plans and API key generation and allows you to link an API key to a usage plan**. With the added advantage that you don't get charged for requests users made beyond their quotas.
      2. However it's not used because **it was important the Ipdata to provide no sign-up, no credit card free tier**.

## Accessing the Usage Data Locally (For Each Lambda Function)

1. Using DynamoDB
   1. It was cost effective at scale and fast with the first 200M requests per month free.
   2. It provides consistently low read latencies of 1-2ms
   3. It can be sped up into microsecond range with DynamoDB Accelerator (DAX)

## Collecting Usage Data For All Identifiers

1. Solving the challenge on counting in real time the number of requests made per IP address, Referrer or API key.
   1. The simplest solution would be to update a count in a dynamodb table on each call. However, this would introduce database writes on each call to the API, potentially introducing significant latency.
   2. A Simple and elegant solution is
      1. First, print a log (a JSON object) with all the request identifiers on each request. That is the IP address, Referer and API key if present. Really just; print(event).
      2. **Add a Cloudwatch Subscription Filter to the Cloudwatch Log Stream of each Lambda function in each region and push all the logs into a Kinesis stream**. This would allow me to **process log events from every region in a central place. I chose Kinesis over SQS (Amazon’s Simple Queue Service) because of the ability to play back events. SQS deletes the event as soon as a consumer reads it.** And I wanted the ability to be able to recover from node failures and data loss.
      3. **Read from the Kinesis stream and update a Local Dynamodb instance with the usage data**
      4. Use the **Dynamodb Cross Regional Replication Library to stream all changes to my local dynamodb instance to all the tables in all regions in real time.**

## Authenticating Requests

1. I handle this by **replicating keys to every region on signup, so that no matter what endpoint a user hits, the lambda function they hit can verify their key by checking in it’s local Dynamodb table within a millisecond**.
   1. This also stores the user’s plan quota and can in a single read verify the key and if it exists get the plan quota to compare usage against and determine whether to accept or reject the request.

## Lessons

1. Cloudwatch can be surprisingly costly — and not log storage — we only store cloudwatch logs for 24hrs. **Alarms, metrics and cloudwatch requests can really add up**.
2. **On API Gateway the more requests you get the lower your latencies will be due to fewer cold starts**, because of this I’ve seen latencies as low as 17ms in our busiest region (Frankfurt) to 40ms in our less busy regions such as Sydney
3. Dynamodb is fast and will cost you less than you think (or not, see https://segment.com/blog/the-million-dollar-eng-problem/). I initially thought I’d get charged per the number of RCUs and WCUs I’d provision. **However billing seems to be only par usage, so if you provision 1000 RCUs and 1000 WCUs but only use 5 RCUs and WCUs you’ll only get charged for your usage. This aspect of Dynamodb pricing was a bit tough to wrap my head around at the beginning**.
4. **Increasing your lambda RAM can halve your execution time and make response times more consistent** (as well as double your costs!)
5. **Kinesis has proven to be very reliable under high throughput**. Relaying all our log events for processing in near real time.
6. **Local Dynamodb is only limited by your system resources, which makes it great for running table scans or queries (for example when generating reports) that would otherwise be expensive to do on AWS’s Dynamodb**. Keep in mind that **Local Dynamodb is really just Dynamo wrappings around SQLite** :). It’s useful and convenient for our usecase but might not be so for you.