## Production Engineer

1. Linux Internals

   1. what is happening under the hood of a Unix/Linux system.
   2. Lower level systems knowledge is more generic and more transferrable.
   3. If you understand how the system itself works, it’s much easier to troubleshoot an application running on top of it.
   4. Topics
      1. Process Creation, Execution and Destruction
      2. Differences between Processes and Threads
      3. Memory Management
      4. System Calls
      5. Signals and Signal Handlers
      6. Unix Filesystem Structure
      7. User and Kernel space boundaries and interactions
         1. Examples might include: ioctls, sysctls, context switches.

2. Troubleshooting
   1. Understanding how a Unix/Linux system works is one set of skills. Being able to effectively use that knowledge to troubleshoot a running system is actually a slightly different set of skills
   2. Do two things effectively
      1. Gain knowledge of the tools that are available to troubleshoot a system and data that these tools give you.
      2. Have good approach to troubleshooting a problem. Know how to follow a path of investigation where you are progressively ruling out potential problems until you arrive at the root cause of the problem.
         1. Propose a course of action like running a command or looking for a specific output
   3. Question Scenario - 1
      - Q - Someone says their application is not running. How would you troubleshoot it?
      - A - I'd log into the machine and run df –h to see if the disks were full
      - Q - OK, none of the disks are over 50% full. What next?
      - A - I'd run this command next
   4. What to be?
      - Know no one tool or topic is critical, but a broad familiarity with each of these spaces and the ability to apply that knowledge to new situations is important
      - Everything from the kernel to the user space is fair game so gain both breadth and depth of knowledge.
   5. Topics
      2. Troubleshooting tools for system-level performance issues
      3. Troubleshooting tools for debugging application-level performance issue

# System Calls References

1. System Calls
   1. https://www.tutorialspoint.com/unix_system_calls/index.htm
2. Command List
   1. https://www.tutorialspoint.com/unix_commands/index.htm
