# General Role Description

## Description

1. FB is seeking talented Systems Engineers who are passionate about systems infra engineering. A Sys Engineer owns and supports many of core infra systems and have direct impact on system design, enhancements, and support practices. Engineers need expertise in storage, virtualization, messaging, open source technologies, data networking, and back office foundational infrastructure.

## Responsibilities

1. **Build, scale and secure Oculus corporate infra**, focusing on both Windows and Linux environments.
2. Combine open-source and commercial technologies to build services that will have an impact on the business
3. **Leverage the scale and complexity of the larger facebook.com infra** to solve problems for all of Oculus
4. Deploy, configure, and maintain servers and other critical infra to support **all Enterprise teams**
5. Perform **server performance tuning and capacity planning** alongside FB **monitoring and platform teams**
6. Collaborate with project managers and 3rd party/in-house developers on unique technical projects.
7. Produce systems that are **scalable, automated, and well-documented**, and train others to take on operations.
8. **Maintain technical documentation library and internal wikis**
9. Synopsis
   1. FB needs System Engineers who are OS, security and security focused, open-source and commercial technologies aware, performance, capacity and infra oriented and industry standard, automation, documentation and communication minded.

# Minimum Qualification

1. B.S. degree in technical discipline
2. 6+ years working in a large-scale server admin or data support role
3. 6+ years System Engineering experience with Linux Server (CentOS, Ubuntu) or Windows Server(2008R2/2012) and associated technology support
4. Minimum 2 years of experience coding with Python, GO and Bash.
5. Understanding of networking protocols (**TCP/IP, DNS, DHCP, NTP, SNMP, IPTables, Active Directory, WSUS, WDS**, etc.)
6. Understanding of network protocols and network design principles
7. Experience with open source monitoring and methodologies (**Zabbix, OpenNMS, Nagios**)
8. Understanding of Datacenter technologies (SAN/CDN)
9. Synopsis
   1. FB needs System Engineers who are experienced with supporting large scale server admin and data support, who understands network design and principles, data center technologies and open source monitoring tools and methodologies, and minimal understanding in coding.

# Interview Specifics

## EE Role and Tasks

1. Understand what Enterprise Engineering team do
   1. Enterprise Engineering **builds infrastructure and tooling to support a very broad set of functions and customers** within the organization.
      1. Some of its customers include Oculus, Workplace and WhatsApp, Sales, Finance, Community Operations, and others.
   2. The team provides infrastructure **from physical servers to virtualization to containers and cluster/application scheduling systems**.
   3. Provides **internal networking for more than 200 offices globally along with multiple database and data analytics systems**.
   4. The team develops **tools for monitoring, automation and self-service**.
2. Synopsis
   1. EE team develop and maintain automation and monitoring tools, systems and infra for application teams to consume in a self-service manner.

## EE - [Cracking the coding interview](./ctci.pdf)

1. Steps
   1. Listen - make sure close attention to any hints or cues from the interviewer as it most likely is very important for an optimal solution.
   2. Example - make sure your solution fits in a variety of inputs, different edge cases.
   3. Brute Force - mentally find a solution as fast as possible even if it's a brute force solution.
   4. Optimize - mentally BUD optimize, and look for efficient solution with intuitive and counter-intuitive thinkings
      1. BUD stands for bottlenecks, unnecessary work, and duplicated work.
   5. Walk Through - Walk through your approach in detail and understand them before coding.
   6. Implement - use best coding practices and design/refactor your code beautiful and efficiently.
   7. Test - mentally test, look for unusual code, hot spots like null checks, special cases and edge cases. Then fix bugs carefully.
2. Approaches
   1. BUD - look for any work that can reduce to a bottleneck or how to eliminate bottlenecks
   2. Simplify & Generalize - Solve a simpler version then the harder one
   3. Base Case & Build - Solve for the base cases then build from there.
   4. Data Structure Brainstorm - Try various data structures.
3. best Conceivable Runtime (BCR)
   1. The runtime you know you can't beat.
   2. The minimum amount of time that you can never exceed computing.
4. Must know
   1. Data Structures - hash tables, linked lists, stacks, queues, trees, **tries**, **graphs**, **vectors**, **heaps**
   2. Algorithms - **quick sort, merge sort**, **binary search**, **breadth-first/depth-first search**
   3. Concepts - Big-O Time, Big-O Space, **Recursion & Memoization**, **Probability**, **Bit Manipulation**.

## EE Prep - [System Engineering Phone Prep](se_prep.pdf)

1. Coding Prep
   1. The coding interview will be conducted on coderpad.io which a variety of language selection. The question will be related to skills of everyday Systems Engineers to do **text manipulation, handling input/output, automating tasks, interfacing with external systems/processes, etc**.
   2. The primary goal is to have a working solution to each problem in a reasonable amount of time.
   3. Tips include careful solution planning before implementation; defensive coding and ask interviewer for understanding if time is running out; don't stuck in syntax, stub it, solve the problem and move on; letting interviewer know your decision making process throughout; using language you're strongest in; don't be afraid to point out the weakness of your solution or change your mind;
2. System Prep
   1. The system interview covers generally linux internals and troubleshooting
      1. Linux Internals
         1. Topics include process execution and/or threads, memory usage, raid level, the kernel and how it interacts with other system components, system calls, signals and signal handlers, modern web architectures and webservers.
         2. Everything from the kernel to the user space can be considered as a reasonable target for interview and breadth and depth of knowledge is required.
      2. Troubleshooting
         1. The problem will be related to seeing a system related issue in the infra and how do you troubleshoot it. Ask you progress in your solution, the interviewer will provide hypothetical system output to prompt you to the next step.
         2. Ex. You are seeing this in the infra, how do you troubleshoot it?; I'd check this first; Ok, you get this response, what next; I'd run this next
         3. What to prepare
            1. Ensure a structured, methodical approach to problems by narrowing down potential issues systematically as you zero in on the root cause.
            2. Review troubleshooting tools for system-level performance issues and debugging application-level perf issues or bugs
         4. What to say
            1. be open about what you don't know. Let interviewer know the limits of your knowledge and how you react outside of that so always attempt to answer the question at hand.

## EE Prep - [Phone Screen - Coding Prep](coding_phone_prep.docx)

1. Approach - Before Interview
   1. Mental Prep
      1. Plan your approach to always go brute force then optimize which means to code up a working solution then iterate on it. Prepared to clarify questions along with your solutioning and practice talking during coding.
   2. Technical Prep
      1. Spend time brushing up on CS fundamentals algorithms data structures,etc.
         1. Arrays, lists, binary trees, hash tables, stacks and queues, basic graph representations. Pointers
         2. Time and space complexity O(n) vs O(1)
         3. Know how to implement iterators, binary search, hashing, sorting, merge, quick, bucket sorts, graph traversal (BFS, DFS), recursion.
