# Abstract

- This document describes context switch in detail

## Details

1. What is
   1. Context Switching involves **storing the context or state of a process so that it can be reloaded when required and execution can be resumed from the same point as earlier**. This is a feature of a multitasking operating system and allows a single CPU to be shared by multiple process.
   2. A simple example.
      1. Process 1 is running.
      2. Then Process 1 switched out by the CPU and Process 2 is switched in **because of an interrupt or a system call**.
         1. Context switching involves **saving the state of Process 1 into PCB1 and loading the state of process 2 from PCB2**.
      3. After some time again a context switch occurs and **Process 2 is switched out** and Process 1 is switched in again.
         1. This involves saving the state of Process 2 into PCB2 and loading the state of Process 1 from PCB1
2. Major triggers of context switching
   1. **Multitasking**
      1. In a multitasking environment, a process is switched out of the CPU so another process can be run. The state of the old process is saved and the state of the new process is loaded. **On a pre-emptive system, processes may be switched out by the scheduler**.
   2. **Interrupt Handling**
      1. The hardware switches a part of the context when an interrupt occurs. This happens automatically. **Only some of the context is changed to minimize the time required to handle the interrupt**.
   3. **User and Kernel Mode Switching**
      1. A context switch may take place when a transition between the user mode and kernel mode is required in the operating system.
3. Steps of a Context Switching
   1. **Save the context of the process** that is currently running on the CPU. **Update the process control block and other important fields**.
   2. Move the **process control block of the above process into the relevant queue such as the ready queue, I/O queue etc**.
   3. **Select a new process for execution.**
   4. **Update the process control block of the selected process.** This includes updating the process state to **running**.
   5. **Update the memory management data structures** as required.
   6. **Restore the context of the process that was previously running when it is loaded again on the processor**. This is **done by loading the previous values of the process control block and registers**.
4. Cost of Context Switching
   1. Context Switching leads to **an overhead cost** because of **TLB flushes, sharing the cache between multiple tasks, running the task scheduler etc**. Context switching **between two threads of the same process is faster than between two different processes as threads have the same virtual memory maps.** Because of this **TLB flushing is not required**.
5. Notes
   1. Syscalls does not necessarily require a context switch in general but rather a privilege switch. The user process will have a new stack function call created for the syscall.