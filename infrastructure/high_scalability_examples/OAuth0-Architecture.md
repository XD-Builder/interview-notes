# Abstract

- This document explores Auth0 Architecture - Running In Multiple Cloud Providers And Regions

## Architecture

1. Def
   1. OAuth0 provides authentication, authorization, and SSO on services for apps of any type: mobile, web, native; on any stack
   2. Runs anywhere, multiple-cloud providers and multiple regions simultaneously.
2. **Core Service Architecture**
    1. Front-end servers- X-large VMs
       1. running Ubuntu on Microsoft Azure.
    2. Store
       1. Mongodb, running on dedicated memory optimized X-large VMs.
    3. Intra-node service routing
       1. nginx
3. **Multi-Cloud/HA**
   1. Route 53 DNS (With DNS failover) => Firewall(In multiple regions) => Load Balancer (scales VM) => Ubuntu VM (Scaled) => MongoDB Replica Set (Failover replica and read only replica in different regions)
   2. Failover Scenario - Azure suffered a global outage that lasted for hours last week. During that time, HA plan activated and traffics were switched to AWS.
      1. The services runs primarily on Microsoft Azure (IaaS). Secondary nodes on stand-by always ready on AWS.
      2. We use **Route53 with a failover policy**. TTL at 60 seconds. **The Route53 health check detects using a probe against primary DC, if it fails (3 times, 10 seconds interval) it changes the DNS entry to point to secondary DC**. So max downtime in case of primary failure is ~2 minutes.
   3. **We use puppet to deploy on every "push to master". Using puppet allows us to be cloud independent on the configuration/deployment process**. Puppet Master runs on our build server (TeamCity)
   4. MongoDB is replicated often to secondary DC and it's configured as read-only.
   5. **We replicate all the configuration needed for a login to succeed(app info, secrets, connections, users, etc)**. We don't replicate transactional data (token, logs)
   6. In case of failover, there might be some logging records that are lost. We are planning to improve that by having real-time replica across Azure and AWS.
   7. We use our own version of chaos monkey to test the resiliency of our infrastructure.
4. **Automated Testing**
   1. We have **1000+ unit and integration tests**
   2. **We use saucelabs to run cross-browser (desktop/mobile) integration tests for Lock, our JavaScript login widget.**
   3. We use phantomjs/casper for integration tests. **We test, for instance, that a full flow login with Google and other providers works fine.**
   4. All these run before every push for production.
5. **CDN**
   1. **Assets and configuration data is uploaded to S3**. It has to support TLS on our own custom domain. We ended up building our own CDN.
      1. We tried 3 reputable CDN providers, but run into a whole variety of issues:
         1. The CDN was too expensive if you want SSL and customer domain. We had issues configuring it to work with gzip and S3. Since S3 cannot serve both version (zipped or not) of the same file and this CDN doesn't have content negotiation, some browsers don't play well with this. We moved to another CDN which was much cheaper.
         2. The second CDN we had a handful of issues and we couldn't understand the root cause of them. Their support was on chat and it took time to get answers. Sometimes it seemed to be S3 issues, sometimes they had issues on routing, etc.
         3. Third CDN. Given that this CDN is being used by high load services like GitHub we thought it was going to be fine. However, our requirements were different from GitHub. If the CDN doesn't work for GitHub, you won't see an image on the README.md. In our case, our customer depends on the CDN to serve the Login Widget, which means that if it doesn't work, then their customers can't login.
      2. **We ended up building our own CDN using nginx, varnish and S3. It's hosted on every region on AWS and so far it has been working great(no downtime). We use Route53 latency based routing**.
6. Sandbox (Used to run Untrusted Code)
   1. **One of the features we provide is the ability to run custom code as part of the login transaction**. Customers can write these rules and we have a public repository for commonly used rules.
      1. **The sandbox is built on CoreOS, Docker and etcd**.
      2. **There is a pool of Docker instances that gets assigned to a tenant on-demand**.
      3. **Each tenant gets its own docker instance and there is a recycling policy based on idle time**.
      4. T**here is a controller doing the recycling policy and a proxy that routes the request to the right container**.
7. Monitoring
   1. Initially we used pingdom, but we decided to develop our own health check system that can run arbitrary health checks based on node.js scripts. These run from all AWS regions
      1. It uses the same sandbox we developed for our service. We call the sandbox via an http API and send the node.js script to run as HTTP POST.
      2. We monitor all the components and we also do synthetic transactions against the service
      3. If a health check fails, we get notified through Slack. We have two Slack channels #p1 and #p2. If the failure happens 1 time, it gets posted to #p2. If it happens 2 times in a row it gets posted to #p1 and all members of devops get an SMS (via Twilio)
   2. For detailed performance counters and response times, we use **statsd and we send all the metrics to Librato**.
   3. We also setup alert based on derivative metrics (i.e. how much something grows or shrinks in a time period).
      1. Ex. We have one based on logins => if Derivate(logins) > X => send an alert to Slack.
   4. Finally, we have alerts coming from **NewRelic for infrastructure components**.
   5. For logging, we use **ElasticSearch, Logstash and Kibana**. We are storing logs from nginx and mongodb at this point. **We are also parsing mongo logs using logstash in order to identify slow queries (anything with a high number of collscans)**
8. Website
   1. All related web properties: the auth0.com site, our blog, etc. run completely separate from the app and runtime, on their own Ubuntu  + Docker VMs.
9. Future
   1. We are moving to CoreOS and Docker. **We want to move to a model where we manage clusters as a whole instead of doing configuration management over individual nodes**. Docker helps also by removing some moving parts by doing image-based deployment (and be able to rollback at that level as well)
   2. **MongoDB will be geo-replicated** across DCs between AWS and Azure. We are testing latency.
   3. **For all the search related features we are moving to ElasticSearch to provide search based on any criteria. MongoDB didn't work out well in this scenario**. (given our multi-tenancy)
