# Full Interview Loop

1. System Interview

   - Abstract
     - Discussions regarding core concepts of systems administration like DNS, web servers, databases, security, storage (RAID types), and troubleshooting will start off fairly high level and progressively get more in depth. You may also be asked scenario type questions about when something has failed, and you needed to find the issue and then a solution to fix it.
   - Todo
     - Systems interview may be done on a white board or in a conversation. This interview will assess your knowledge of UNIX/Linux theory and practical troubleshooting of Linux systems.
     - Demonstrate understandings:
       - How systems boot and load Linux
       - The shell, and how it interacts with the underlying operating system
       - UNIX filesystems and storage
       - The Linux virtual memory model
       - Techniques for resource control
       - Common system troubleshooting tools and techniques
     - Demonstrate practical skills:
       - On the practical side, you will likely get one or more troubleshooting problems. These problems might have you debugging an issue with one server, or multiple servers in a distributed system. We want to know how you apply your knowledge to solve problems that you will likely encounter in the real world.
         - Try real world troubleshooting on your own server
         - Try understand the meaning of outputs produced by different system admin/troubleshooting commands such iostat/vmstat/top/netstat/dmesg/sysctl, performance commands such as "perf", concepts of system calls such as exec, ioctl, and many different system logging

2. Coding Interview

   - Abstract
     - You will be asked technical questions which require code or algorithms, so be prepared to show your work and be as concise and efficient as possible with your answers. Take hints from the interviewer and be open to other solutions as you go. The interviewer will assess efficiency, structure, syntax, bugs, and working code.
   - Todo
     - This interview will assess the coding skills you’ll use every day, including text manipulation, handling input/output, automating tasks, interfacing with external systems/processes, etc. The questions can be a real problem, or something contrived to use these skills.
     - Demonstrate qualities:
       - Ask questions and resolve ambiguity first
       - Have solution plan in mind before coding
       - Think out loud and speak of defensive coding to impress
       - Explain decisions made and change your mind if needed to
       - Obtain a working solution first
       - No support from the Internet

3. Networking Interview

   - Abstract
     - Study the tcp/ip stack and make sure you know it inside and out. Be prepared to have discussions around load balancers, networking tools, troubleshooting etc, Your interviewer will ask you about your experience working with various networking protocols and may ask you to design a network.
   - Todo
     - This interview will assess your knowledge of theoretical and practical networking between UNIX hosts, potentially at every level of the networking stack.
     - Demonstrate theoretical understanding of:
       - Basic network protocols, such as ICMP, TCP, and UDP
       - How packets are constructed
       - TCP/IP connection establishment and teardown
       - How common internet application protocols such as DNS, HTTP, and DHCP are designed, how they work in practice, and common pitfalls with them.
       - How to design your own application networking protocol, or changes you might recommend to existing application networking protocols.
       - IPv4/IPv6 differences
       - Host and application level networking options in Linux/UNIX, and where and how they are used
       - How load balancing works, different load balancing methods, and pros and cons of each.
       - Basic network design concepts
     - Demonstrate theoretical knowledge to solving actual problems:
       - Common host-level networking troubleshooting scenarios
       - How — and where — to use network troubleshooting tools such as tcpdump/Wireshark, ping, and traceroute.
     - Practice and understand what's under the hood
       - ping
       - traceroute
       - tcpdump -> load the pcap into Wireshark
     - What's not covered
       - Unless you know that you are interviewing for a network engineering role, this interview won’t cover WANs, routing protocol details (e.g., BGP, OSPF), or dedicated networking hardware (e.g., routers, switches).

4. Design/Architecture Interview

   - Abstract
     - This interview will test your abilities to design systems/processes that scale in Facebook’s environment. The interviewer may give you a system we currently have in place and have you make suggestions on how it can be improved. They may also have you design a system completely from scratch on the whiteboard (i.e. design an infrastructure that will handle 10M users for our new XXXXXX system) Questions can range from "How would you scale a service from 1 million to 100 million users" to something general like "Design Facebook."
   - Todo
     - This interview will require you to design a large-scale product or infrastructure component. For example: “Design a URL shortening service like bit.ly”.
     - Demonstrate below qualities as part of system designing question:
       - Ask questions and resolve ambiguity first
       - Identify most critical components of the design first, then drive overall design based on that.
       - Describe your system design and overall architecture at high level first
       - Draw diagrams that CLEARLY describe the RELATIONSHIP among different system components
       - Identify and think out loud your reasoning on the trade-offs of your design (**Consistency, availability, partitioning, performance**)
       - Calculate resources necessary for your design (Storage, CPU, RAM, Disk type, bandwidth, etc...)
       - Plan for system design requirements/constraints change
       - Determine how your system will scale and possible bottleneck/limitation of your design
       - Explain how it handles both success and failure scenario
     - Work through all of below:
       - Design a URL shortening service like bit.ly.
       - How would you implement the Google search?
       - Design a client-server application which allows people to play chess with one another.
       - How would you store the relations in a social network like Facebook and implement a feature where one user receives notifications when their friends like the same things as they do?

5. Soft Skills
   - Abstract
     - You’ll meet with one of the Production Engineering managers, and they will ask you questions about any significant projects you have worked on to get a feel of your capabilities and how you work on teams and with other groups across an organization. There may also be questions to learn more about how you’ve dealt with conflicts in the past or to describe a project you worked on that brings you pride. The questions “why Facebook” and “what is your understanding of production engineering” will also likely be asked.
   - Todo
     - Production Engineers partner with their teammates, software engineers, project managers, and other Facebookers every day. During this interview, we want to learn how you have worked in a team, deal with conflict, and overcome challenges. For recent graduates, we’ll discuss any internships, as well as interesting academic and side projects. Unlike the technical interviews for coding, systems and design, this interview focuses on your unique experiences and approaches to solving non-technical problems. For this interview, you’ll be meeting with a leader in Production Engineering.
     - Prepare for:
       - Quick “elevator pitch”, high-level descriptions of completed or in progress projects.
       - Clear descriptions of your role in the projects, who you worked with, and the challenges you faced, rather than what the specific work was.
       - Things don’t always go as planned, so think through failures you’ve encountered in the past. Share what could have been done differently and what you learned from the experience.
       - Your reasons and motivations for why you changed roles in the past and why you find PE exciting. If you’re currently a software engineer, or other type of engineer, think through why Production Engineering is a good fit for you. Pedro’s SREcon talk is a great resource for understanding Production Engineering.
     - Work through all of below:
       - Tell me about a recent project you are proud of.
       - Tell me about a design decision you made that you later regretted.
       - Tell me about a disagreement or conflict between you and a coworker.
       - What motivates you to leave your current role?
       - Describe your ideal day at work.
       - What is your understanding of Production Engineering?
       - "Why Facebook?”

# Interview Prep Tips

1. Prepare for technical questions involving coding or algorithms (in your preferred programming language), design patterns, and specific questions to your background. It may also help to review core computer science concepts (data structures, binary trees, linked lists, object-oriented analysis/design, etc.) as well as subjects pertaining to the scale of our technology.
2. Practice writing code and designing systems/networks by hand on paper or a whiteboard. During the interview, explain your thought process out loud. Create a working solution (even if it feels inefficient) and then iterate rather than immediately trying to jump to the clever solution. Tip: If you cannot explain your solution clearly in 5 minutes, it's probably too complex for the interview question at hand.
3. Discuss your solution. If the interviewer gives you hints, be ready to discuss them against other options and implement them if appropriate. It is good to adjust and work through the problems with the interviewer to show your thought process and problem solving ability.
4. Explain your motivation for pursuing an opportunity at Facebook. Be prepared to answer the question, "Why Facebook?”
5. Complete your solution. Done is better than perfect,but be able to identify any bugs and assumptions. The interviewer will be looking for an intersection between speed and accuracy.
6. Pace Yourself. The duration of the interviews will be ~45 minutes. It helps to time yourself when practicing at home. If your answers are taking longer, aim for simpler solutions.

## Facebook Value

1. **A drive to help the world connect and share**
   - Facebook is changing how people around the world build community. Our production engineers are passionate about solving the challenges associated with connecting the next four billion people who are not yet online.
2. **Ownership of projects from start to finish**
   - Facebook engineers are always building new things, and have a demonstrated ability of owning projects from start to finish. Our engineers are able to take on every aspect of a project – from design and development to implementation and support.
3. **Ability to thrive in a flexible, flat environment**
   - Facebook has a relatively flat organization, and all of our engineers are flexible and agile enough to stop what they’re doing and jump into code. **All our production engineers are software engineers, and everyone is hands-on.**
4. **Daringness to be bold**
   - Facebook engineers have consistently taken on challenging projects throughout their education and careers. When you speak with engineers on our production engineering teams, you’ll hear stories about times when they weren’t quite sure about how they were going to accomplish a project, but dared to be bold, iterated quickly and found a solution. Our engineers love working on the most difficult challenges. They embrace uncertainty, take risks and learn from failure.

## PE Team

1. Production Engineering in Menlo Park-focus areas
   - Production engineers help software engineers understand how the software is interacting with its environment. The team accomplishes this through automation, building new tools, performance analysis, and hardcore systems debugging. For example, when a software engineer is on-call, they not only have the instrumentation at their fingertips, but the necessary tools to be able to resolve the problems at their fingertips as well. PEs try to abstract away a lot of what the infrastructure currently is using, so that software engineers don't have to understand the nuances of configuration management and software deployment, starting and stopping systems, etc. PEs tend to focus on solving problems related to service stability and performance, partnering with software engineers, who tend to focus on customer and back-end features. PEs typically emphasize integration and operations and may be responsible for managing service deployment, interaction, and efficiently troubleshooting at scale.
2. Developer Infrastructure
   - PE DevInfra’s main goal is to keep Facebook running with stable and tested code. The team maintains a large heterogenous infrastructure for continuous integration including hundreds of Linux, Windows, macOS servers, and mobile handsets form the testing system. PE DevInfra also works with developer efficiency teams like Source Control and End-to-End Testing to build fast and reliable developer workflows that scale. Every single change to our iOS and Android applications, web and desktop applications, internal tools and infrastructure services is asynchronously tested in dozens of ways before it even makes it through code review. PE DevInfra builds and maintains these systems, working on both the software and the hardware to make them fast, reliable, and scalable.
3. Core Systems
   - The Core Systems Production Engineering team is responsible for helping the foundational layer of Facebook services run reliably and efficiently. This team builds common infrastructure components that are used across many different services, ensuring that each team has the tools necessary to deploy and scale their service and build products in production without having to reinvent the wheel. The services for which this team is responsible for include Facebook’s internal container management system, service discovery infrastructure, and configuration management system, among others.
4. Posix Storage
   - The POSIX Storage Production Engineering team manages the infrastructure for POSIX-addressed, distributed storage within the Facebook production stack. This team currently supports both open source (GlusterFS) and commercial solutions with both footprints being many PB in total capacity. POSIX Storage Production Engineering overall goal is to provide easy to use, scalable, storage services that integrate with the Facebook infrastructure and the applications that run on it. They work closely with teams needing POSIX access semantics to tailor solutions to different use cases. The team is an active committer to the upstream Gluster project and an influential customer in the enterprise storage space, solving data movement and access issues at a global scale while maintaining production automation to perform much of the administrative heavy lifting.
