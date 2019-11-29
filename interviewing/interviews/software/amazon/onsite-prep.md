# Abstract

- This document explores onsite-prep areas for the interview

## Amazon Onsite Prep

1. Products
   1. Research, create an account, try out [products](https://aws.amazon.com/?nc2=h_lg)
   2. You may be asked why you want to work at Amazon.
      1. Note: they are very passionate about their products & the way in which they're building it, so they want to hire people who are also pioneers and love it!
2. Onsite Interview Highlights
   1. Interviews are structured in two buckets **'technical' and leadership principles (LP's), you should study/prepare for both** portions in order to achieve the best outcome.
   2. Familiarize yourself with their leadership principles, **make sure you're comfortable with them and can tie 7+ of your previous examples back into them**.
   3. Write out a few of your examples and highlight areas that you think may exemplify their LP's, doing this will be a good indication that you're presenting the best types of examples.
3. Leadership principles
   1. **Each interviewer will ask you at least 2 leadership principle questions**, so take the time to write out two examples for each principle so you have a solid handle on your projects and stories.
4. Behavioral Interview
   1. **Recall recent situations that show favorable behaviors or actions, especially involving work experience, leadership, teamwork, initiative, planning and customer service**.
   2. Prepare a short description of each situation; be ready to give details if asked.
   3. Be sure each story has a beginning, middle and an end. Be ready to describe the situation, including the task at hand, your action, and the outcome of the result.
   4. Use first person "I"
   5. Be sure that the outcome reflects positively on you even if the result itself was not favorable, we want to know what you learned from things gone wrong and how you'd do things differently now.
   6. Be honest, be specific, and vary your examples.
5. Sample Behavioral Interview Questions
   1. Tell me about a time when you have been faced with a challenge where the best way forward or strategy to adopt was not "clear cut". How did you decide the best way forward?
   2. Give me an example of a time when something you tried to accomplish and failed.
   3. Give me an example of when you showed initiative an took the lead.
   4. Give me an example of a time when you motivated others
   5. Tell me about a time when you delegated a project effectively.
   6. Give me an example of a time when you used your fact-finding skills to solve a problem.
      1. Use STAR method, Situation, Task, Action, Result
6. Technical Interviews
   1. Write real code instead of pseudocode
   2. Make sure you create an optimal solution eventually
   3. Ask clarifying and qualifying questions
7. Preparing for Whiteboard Coding Session
   1. Coding - (logical and maintainable)
   2. Coding - Data Structures and Algorithms
   3. Coding - Problem Solving
   4. System Design (Scalability and operational performance)
8. Other preps
   1. Video
      1. [URL](http://vimeo.com/65432090)
      2. Password - amzninterviewday

## How Leadership Principles Relate to Personal Experience

1. Experience
   1. DU is moving to the AWS cloud and it needs a way to ensure concerns that is relevant to all services can be handled transparently and ensure high maintainability of a suite of micro-services.
      1. DU AWS Cloud Components - Config Service, OAuth Integration and Job Service to enable software and production engineers fast micro-services development, task scheduling and maintenance.
   2. Business is pushing to release fast, the performance testing is always a bottleneck because it takes at least 2 weeks to complete.
      1. Performance Testing Framework - With Gatling as a Maven dependency, the performance testing framework binds user provided YAML file to an internal model using Jackson-databind and delegates performance testing task to Gatling APIs in a way such that it iterates over a list of performance test scenarios with variable substitution, response key-value extraction and substitution for subsequent scenarios and generates an web page with performance metrics.
      2. Solution: To help customer save time and deploy more often, I researched JMeter, Gatling and LoadRunner frameworks and eventually decided that Gatling will help reduce the gap from 2 weeks down to minutes. As a result, developers can push code to production more often and business will be happy seeing more customer satisfaction all without knowing anything about the performance frameworks. (Know YAML DSL for this framework)
   3. Bank Customers want to have their borrowers quickly validated for qualification of a loan and since the bank already has the borrower data, it's an opportunity to have banks submit verification of deposit reports to FNMA so it can verify loans instantly instead of waiting weeks to months.
      1. Implementation of NetPay ensures that the contract between FNMA and banks are set up correctly with security. It links to internal validation services for validating customer income and assets as part of SSV initiative.
   4. DU Production Support L3 teams are having the toil to web UI test hundreds of different end points in all different environments for successful loan submission flows in hours and create a report to the team its health. It's laborious and doesn't provide value as environment health is constantly changing. We need a web ui testing framework to test endpoints automatically in an hourly interval so we can inform customers of the outage.
      1. Java Selenium project automates DU PODs UI shakeout every hour using a simple user provided YAML and automatically emails shakeout results to customers after shakeout completion. It increases customer satisfaction.
   5. There is a production issue where DU is not able to process some of its production transaction and development teams are not able to figure out why from the code as it's written in C++, long and complicated and no one wants to touch the code. As a result, the problem caused lots of customer un-satisfaction and reputation issues.
      1. Individually designed and implemented a Java project to automate DU Production transaction log failure reporting for servers in Urbana and Reston that helped company notify customer for transaction failures via email automatically.
   6. VDRS performance test is slow and it takes hours to run.
      1. Refactored and optimized Vendor Data Reference System (VDRS) test project code to support concurrent integration testing.
   7. DU legacy services use queues to process request inputs and produces an output that will be put into another a queue. To test a legacy service component, a full end-to-end submission is required and takes minutes to manually submit the loan and see the response and cause a lot of loads in the lower environment and it's not programmable into the CICD pipeline and thus slowing the development speed down to the time it takes for a developer talking to a business E2E testing person and relying the response back to the developer via email, which takes about 30 minutes to a day.
      1. To solve this issue, I extracted and refactored DU Loan Processing Workflow client code which enabled development teams with the capability to component test their micro-services as part of CICD pipeline in addition to their E2E testing.

2. Customer Obsession
   1. 1,2,3,4
3. Ownership
   1. 1,2,3,4
4. Invent and Simplify
   1. 2, 4,5,7
5. Are Right, A Lot
   1. 1-7
      1. All of the services developed are used in production and it helps customer raise their satisfaction level. Right meaning used in production.
6. Hire and Develop the Best
   1. 1-7
      1. Relentlessly try to increase customer satisfaction and faster deployment to production through automation.
7. Insist on the Highest Standards
   1. 1-7
      1. Provide solutions in a timely and effective manner. Adhere to the highest standard whenever rewards fit in a limited time that business is willing to pay for.
8. Think big
   1. 1-7
      1. Think big for benefiting the entire DU train, the production stack and ultimately the customer.
      2. Think big for developers to quickly onboard to a project via better naming convention, design and logics separation via OOD.
9. Bias for Action
    1. 4-7
10. Frugality
    1. 4-7
       1. Individually complete rather than a team.
11. Learn and Be Curious
    1. 1-7
       1. The career growth are as a result of this leadership principle
12. Earn Trust of Others
    1. 1-7
       1. The trust engineers put
13. Dive Deep
    1. 1-7
14. Have Backbone; Disagree and Commit
    1. 1-7
15. Deliver Results
    1. 1-7

## Leadership Principles

1. Status Quo
   1. Currently employs more than 100,000 people around the world. Their Leadership Principles are the foundation of their culture and guide each Amazonian.
   2. Whether you are an individual contributor or a manager of a large team, you are an Amazon leader.
2. Qualities and Principles
   1. Customer Obsession
      1. Leaders start with the customer and work backwards. They work vigorously to earn and keep customer trust. Although leaders pay attention to competitors, they obsess over customers.
   2. Ownership
      1. Leaders are owners. They think long term and don't sacrifice long-term value for short-term results. They act on behalf of the entire company, beyond just their own team. They never say "that's not my job"
   3. Invent and Simplify
      1. Leaders expect and require innovation and invention from their teams and always find ways to simplify. They are externally aware, look for new ideas from everywhere, and are not limited by "not invented here". As we do new things, we accept that we may be misunderstood for long periods of time
   4. Are Right, A Lot
      1. Leaders are right a lot. They have strong judgment and good instincts. They seek diverse perspectives and work to disconfirm their beliefs.
   5. Hire and Develop the Best
      1. Leaders raise the performance bar with every hire and promotion. They recognize exceptional talent, and willingly move them throughout the organization. Leaders develop leaders and take seriously their role in coaching others. We work on behalf of our people to invent mechanisms for development like Career Choice.
   6. Insist on the Highest Standards
      1. Leaders have relentlessly high standards - many people may think these standards are unreasonably high. Leaders are continually raising the bar and drive their teams to deliver high quality products, services and processes. Leaders ensure that defect do not get sent down the line and that problems are fixed so they stay fixed.
   7. Think big
      1. Thinking small is a self-fulfilling prophecy. Leaders create and communicate a bold direction that inspires results. They think differently and look around corners for ways to serve customers.
   8. Bias for Action
      1. Speed matters in business. Many decisions and actions are reversible and do not need extensive study. They value calculated risk taking
   9. Frugality
      1. Accomplish more with less. Constraints breed resourcefulness, self-sufficiency and invention. There are no extra point for growing headcount, budget size or fixed expense.
   10. Learn and Be Curious
       1. Leaders are never done learning and always seek to improve themselves. They are curious about new possibilities and act to explore them.
   11. Earn Trust of Others
       1. Leader listen attentively, speak candidly, and treat others respectfully. They are vocally self-critical, even when doing so is awkward or embarrassing. Leaders do not believe their or their team's body odor smells of perfume. They benchmark themselves and their teams against the best.
   12. Dive Deep
       1. Leaders operate at all levels, stay connected to the details, audit frequently, and are skeptical when metrics and anecdote differ. No mask is beneath them.
   13. Have Backbone; Disagree and Commit
       1. Leaders are obligated to respectfully challenge decisions when they disagree, even when doing so is uncomfortable or exhausting. Leaders have conviction and are tenacious. They do not compromise for the sake of social cohesion. Once a decision is determined, they commit wholly.
   14. Deliver Results
       1. Leaders focus on the key inputs for their business and deliver them with the right quality and in a timely fashion. Despite setbacks, they rise to the occasion and never settle.

## System Design

1. About Amazon
   1. A place where builders can build. We hire the world's brightest minds and offer them an environment in which they can invent and innovate to improve the experience of our customers. We want employees who will help share and shape our mission to be Earth's most customer-centric company.
   2. **Amazon's evolution from Web site, to e-commerce partner, to development platform, is driven by the spirit of invention that is part of our DNA.**
2. Answering the System Design Question
   1. When interviewing for a SDE, a Software Development Manager, or a Technical Program Manager position at Amazon, you will likely have at least one interview focused on software systems design.
      1. This is very important interview, so it's critical to prepare for it thoroughly.
   2. Answering this question will be very interactive; the interviewer will ask you lots of questions related to the design and you are encouraged to ask the interviewer any necessary questions to complete your design. If you're suggesting technology to solve a problem, please make sure you understand how that technology works.
      1. It's more important that you understand how your solution solves the problem than specific technology solutions. It helps to think out loud and take hints from the interviewer. You will most likely be diagramming your design on a white board.
3. Topics to Review
   1. Often times, software systems need software components, something to store data, something to make decisions and APIs, component relationships, and data flows. Reviewing software system design diagram (SOA or distributed software system) can be helpful for preparation.
   2. Scaling is a critical component of software design at Amazon. It's important to consider scaling when diagramming and designing your software system. Prior to your interview be sure to research scalability concepts and technology prior to your interview such as caching, load balancing, non-relational databases, microservices and sharding.
   3. Knowledge of **distributed systems, SOA (comes with a messaging middleware or direct data passing, bigger and heavy-weight compared to microservices), and n-tiered software architecture** is very important in answering systems design questions.
   4. Large software system designs often need to trade off availability, consistency, and other desirable performance characteristics. Discuss trade offs
4. Steps in System Design Interview
   1. Ask clarifying questions; while the interviewer won't try to trick you, they might be intentionally vague. It's important to know what sort of design the interviewer is looking for, so ask questions.
      1. Asking a question should start with the customer in mind. Who is the customer and what problem are you solving for them?
   2. As you ask clarifying questions, begin writing a list of requirements on the board. This should typically be the first thing you add to the white board.
   3. Once you have a good idea on the sort of problems the system you are designing is supposed to solve, begin drawing a diagram on the white board to express your ideas. A great way to do this is to draw shapes to represent different software components and data sources and then arrows connecting them to show web services, APIs, and interactions between components.
   4. Be prepared to discuss trade-offs in your design. With any software system there are multiple ways to design it. What advantages would yours have? Disadvantages? What if you were to change a component or process? Be prepared to discuss these questions.
   5. Operational performance of your design is important as well. Be prepared to answer the following: how will you ensure this system is working at an acceptable level of performance? If a problem occurs, what will be involved in troubleshooting and resolving it quickly? What are the possible points of failure and how can they be made more robust against failure?

## SDE Principles

1. Drive Quality
   1. SDEs assume responsibility for quality; have relentlessly high standards and write good code in order for the product/service to work right the first time; own problems found with their own code; get design and code reviewed, clearly document code and rigorously review other developers' code; test code thoroughly
2. Have Excellent Functional Skills
   1. SDEs are excellent problem solvers, analytical thinkers and possess excellent job-relevant technical skills (e.g. design, development, building schedules, coding, etc); understand performance operational issues; are flexible, adaptable, and able to multi-task; have knowledge of and continue to develop an extensive software development toolbox.
3. Deliver Results
   1. SDEs **own and drive tasks to completion; work efficiently to meet deadlines - including setting and meeting milestones**; prioritize competing tech projects to deliver the right results. Despite setbacks, they rise to the occasion, maintain focus and never settle.
4. Innovate & Simplify
   1. SDEs are resourceful and discover ways to innovate and invent while also finding the simplest solution; do not needlessly complicate; continually think outside the box to address problems creatively.
5. Have Operational & Customer Focus
   1. SDEs focus on making things better for customers by quickly and thoroughly resolving defects; always research and seek the root cause to solve problems; understand the business context and impact of their work and consider scaling issues; provide excellent on-call customer support; are advocates for customers - both internal and external.
6. Communicate Clearly
   1. SDEs keep teammates informed of issues that affect the team by clearly and directly communicating, escalate issues and concerns promptly and appropriately.
7. Exercise Judgment
   1. SDEs have strong judgment, clarity of thought and good instincts that inform their software development decisions; garner respect and are able to drive consensus and influence others by being right a lot; are smart about working on the right stuff and working through applicable tradeoffs.
8. Demonstrate Engagement & Teamwork
   1. SDEs have a high level of ownership for their work and professional development; are proactive and demonstrate a positive, can-do attitude; are respected members of the team; work across organizations effectively; mentor other engineers; learn from others and from their own mistakes.

## Hiring Decisions

1. Core Values
   1. Customer Obsession
      1. Obsession with customer is a base for making decisions. **Think about how changes will impact customers first and work backwards from there.**
   2. Dive Deep
      1. **Don't focus problems and features on the surface level**.
      2. Dive deep the to the problems and let data guide decisions
   3. Think Big
      1. **Not satisfied with taking incremental and obvious steps forward. We like to think big and take leaps forward**.
      2. **When things don't go as planned, we take a step back and analyze what we could have done better.** Be vocally self-critical and not make the same mistake twice.
   4. Ownership
      1. Everyone is expected to be an owner of the company and has a bias for action
      2. Employees should not only have big ideas but to drive those big ideas into production.
2. Technical Interviews
   1. All interviews for software development break down into three main areas: problem solving, design, coding
3. Data Structures & Algorithms
   1. Array, LinkedList, Tree, Heap, Hash Table, Stack, Queue, Graph, Merge Sort, Quick Sort, Radix Sort, Data Structure Traversals
