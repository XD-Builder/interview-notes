# Abstract

- This document explores phone prep areas for the interview

## Online Assessment - Coding

1. Online Assessment
   1. The coding test is 90 minutes long with 15 minutes for a multiple choice question and a brief survey afterward. You can't stop a section once you've begun.
   2. Interview link is valid for 7 days
2. Preparation
   1. Fundamentals
      1. Data structures and algorithms.
      2. Space and time complexity
      3. Applications like Hashmaps, b+trees (and variants), caches (and associated algorithms)
      4. [code chef](https://www.codechef.com)
   2. Project Euler
      1. [Project Euler](https://www.projecteuler.net)
      2. Build useful library
   3. [Google coding contest](http://code.google.com/codejam/contests.html)
   4. [High Scalability Architecture](http://highscalability.com/blog/category/example)
   5. [Demo Assessment](http://www.myamcat.com/amazon-lateral-demo)


## Technical Topics to Review

1. Programming Languages
   1. You should be familiar with syntax of language as well as some of the language's nuances, such as how memory management works, or the most commonly used collections or libraries, etc.
2. Data Structures
   1. Most of the work we do involves storing and providing access to data in efficient ways. This necessitates a very strong background in data structures.
      1. You'll be expected to understand the inner workings of common dat structures and be able to compare and contrast their usage in various applications.
      2. You will be expected to know the runtimes for common operations as well as how they use memory. (Tips use wiki)
   2. By Jeff Bezos
      1. "Random forest, naive Bayesian estimators, RESTful services, gossip protocols, eventual consistency, data sharding, anti-entropy, Byzantine quorum, erasure coding, vector clocks, ... walk into certain Amazon meetings, and you may momentarily think you've stumbled into a computer science lecture."
3. Algorithms
   1. Have a good understanding of the most common algorithm will make solving some of the questions they ask a lot easier.
   2. Review traversals, divide and conquer, and any other common algorithms you feel might be worth brushing up on.
   3. Understand how and when to use a breadth-first search vs a depth-first search, and what the tradeoffs are. Know the runtimes, theoretical limitations, and basic implementation strategies of different classes of algorithms is more important than memorizing the specific details of any given algorithm.
      1. BFS
         1. Searches siblings first
         2. Usually implemented with queues
         3. A complete algorithm and will give you the optimal solution
         4. Space Complexity O(b^d) a lot of memory
            1. based on the branching factor and the depth searched.
      2. DFS
         1. Searches children first
         2. Uses stack
         3. Searching for a path from one vertex to another may produce suboptimal solution before you find the real shortest path.
         4. Space Complexity is O(|V|) meaning the most memory it can take up is the longest possible path.
      3. Both have the same time complexity
4. Coding
   1. Expected to write syntactically correct code - no pseudo code.
      1. If you feel a bit rusty coding without an IDE or coding in a specific language, it is probably a good idea to dust off the cobwebs and get comfortable coding with a pen and paper.
   2. The most important thing as SWE does at Amazon is write scalable, robust, and well-tested code.
      1. These are main criteria by which your code will be evaluated, so make sure that you check for edge cases and validate that no bad input can slip through.
   3. The goal is to write code that's as close to production ready as possible
      1. A few missed commas or typos here and there aren't that big of a deal. This is your chance to show off your coding ability.
5. OO Design
   1. Good design is paramount to extensible, bug free, long-lived code
      1. It's possible to solve any given software problem in an almost limitless number of ways, but when software needs to be extensible and maintainable, good software design is critical to success.
   2. Have a working knowledge of a few common and useful design patterns as well
   3. Write software in an OO way with appropriate inheritance and aggregation
      1. You won't be asked to describe the details of how specific design patterns work, but expected to defend your design choices.
6. Databases
   1. Most of the software we write is backed by a data store.
      1. Challenges arise when trying to figure out how to most efficiently retrieve or store data for future use.
   2. Amazon is at the forefront of the non-relational DB movement.
      1. We have made Amazon Web Services such as DynamoDB available for developer community that let them easily leverage the benefits of non-relational databases.
   3. The more you know about how relational and non-relational databases work what tradeoffs exist between them, the better prepared you will be.
7. Distributed Computing
   1. Systems at Amazon have to work under very strict tolerances at a high load. It's important to have an understanding of a few basic distributed computing concepts.
      1. Having an understanding of topics such as service oriented architectures, map-reduce, distributed caching, load balancing, etc. could help you formulate answers to some of the more complicated distributed architecture questions you might encounter.
8. Operating Systems
   1. You won't need to know how to build your own OS from scratch
   2. You need to be familiar with some OS topics that can affect code performance, such as: memory management, processes, threads, synchronization, paging, and multithreading.
9. Internet Topics
   1. Amazon does a lot of business online, and they expect their engineers to be familiar with at least the basics of how the Internet works.
   2. Brush up on how browsers work at a high level, from DNS lookups and TCP/IP, to socket connections.
   3. They look for a solid understanding of the fundamentals of how the web works.
10. What the Interviewer is looking for?
    1. The interviewer won't be evaluating your ability to memorize all of the details about each of above topics. What they will be looking for is your ability to apply what you know to solve problems efficiently and effectively.
    2. Given a limited amount of time to prepare for a technical interview, **practicing coding outside of an IDE and reviewing CS fundamentals will likely yield the best results for your time**


## Other Tips

1. Be prepared to discuss technologies listed on your resume.
   1. Expect technical question about your experience with languages and technologies you use.
2. Ask questions if you need clarification.
   1. Expect a collaborative interview process.
   2. They want to learn what it would be like to work with you on a day-to-day basis in their open environment.
   3. If not enough information given to solve a problem, drill down to get the information that you need and if that information isn't available, fous on how you would attempt to solve the problem given the limited information you have.
      1. Often times at Amazon, we have to make quick decisions based on some of the relevant data.
3. Be concise and detailed in your response as possible
   1. It's hard to gauge how much information is too much versus not sufficient enough.
   2. Pause after your succinct response to ask if you've provided enough detail, or if the interviewer would like you to go into more depth.
4. We want to hire smart, passionate people.
   1. Reflect how you think a career with Amazon would be mutually beneficial and be prepared to speak to it.
   2. "Why Amazon?" is a standard type of question.
      1. They want to understand how working together with you would be great, so they get a better sense of who you are
      2. Their interviewers also appreciate an opportunity to shrae their thoughts and experiences, so take a moment to prepare a couple of questions for the interviewer.

## EC2 High Level Requirement

1. About Amazon
   1. A place where builders can build.
   2. They hire the world's brightest mind and give them room to invent and innovate to improve the experience for our customers. They want employees who will help share and shape their mission to be Earth's most customer-centric company.
   3. The company solves complex technical and business problems every day with ingenuity and simplicity.
   4. Their engineers tackle some of the most complex challenges in large-scale computing. SWE, technical program managers, test engineers, and user-interface experts work in small teams across the company to contribute to the e-commerce platform that's used by over 150 million active Amazon customer accounts, over 2 million active seller accounts and hundreds of thousands of external developers with one obsession: our customers.
2. About Team
   1. EC2 enables customers of all sizes to run their applications on industry leading cloud infrastructure.
   2. Customers around the world, from startups, to research institutes, to established enterprises, use EC2 spot to rapidly scale their compute capacity, while staying on budget and saving up to 90% of EC2 costs.
   3. EC2 spot team is growing rapidly to significantly expand their feature set and increase scale.
3. Personality match
   1. Excited to solve problems at the cutting edge of cloud computing.
   2. Willingness to build and own services and infrastructure.
   3. Passionate in building large scale software, enhancing customer satisfaction, growing market segment share, and operational excellence.
4. About Role
   1. Why this role - EC2 networking is crucial from Amazon's long term success as a technology services company.
   2. You're passionate about writing software for managing large dynamic networks.
   3. You're with a solid background of delivering innovative solutions.
   4. Own major deliverables and all aspects of the development cycle.
   5. You're encouraged to exercise your judgment in proactively determining and recommending the best features, designs, and support models based on business objectives, timelines, and resource constraints.
   6. Good understanding of data consistency and transactions between distributed services.
   7. Experience with web-services, especially at massive scale.
5. Requirements
   1. Strong coding, language proficiency, web services design and implementation.
   2. 5 years of software development experience and leads high performance engineering teams
   3. Knowledge of professional software engineering practices for full SDLC lifecycle.
   4. Excellent understanding of resource and design requirements for highly scalable systems.
   5. Strong analytical skills with excellent problem solving abilities.
   6. Knowledge of system performance and opeational readiness monitoring.
   7. Strong desire to build, deliver results, take ownership, and drive projects.
