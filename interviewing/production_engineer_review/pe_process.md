# Abstract

This document defines and summarizes many aspects of a process and thread, their differences, lifecyles and interactions managed by linux kernel.

# Process Creation, Execution and Destruction

1. What is?
   1. An instance of a computer program that is being executed.
2. What is Multitasking?
   1. A method to allow multiple processes to share CPUs and other system resources
   2. Time-sharing is one of the forms
      1. context switches are performed rapidly, which makes it seem like multiple processes are being executed simultaneously on the same processor.
3. Creation
   1. Process is created by being loaded from a secondary storage device into main memory. After the is process created, a process scheduler assigns it the "waiting" state.
4. Execution
   1. When the process is "waiting", a process scheduler does the context switch and load the process into the processor. The process state then becomes "running" and the processor executes the process instructions.
5. Destruction
   1. Once process finishes execution, or is terminated by the OS, it is no longer needed. The process is removed instantly or to the "terminated" state.
   2. When removed, it just waits to be removed from main memory.

# Differences between Processes and Threads

1. What's the difference?
   1. Processes are typically independent, while thread exists as subsets of process
   2. Processes carry considerably more state information than threads; multiple threads within a process share process state as well as memory and other resources
   3. Processes have separate address spaces, whereas threads share their address space
   4. Processes interact only through system-provided inter-process communication mechanisms
   5. Context switching between threads in the same process is typically faster than context switching between processes
