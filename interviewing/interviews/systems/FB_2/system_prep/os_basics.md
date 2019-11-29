# Abstract

- This document introduces os basics

## Operating System

1. Def
   1. Manages the hardware and running programs
   2. It loads and manages processes, provides interfaces to hardware via system calls, provides a filesystem and basic user interface.
2. Device Driver
   1. OS plug-in module for controlling a particular device
      1. Software drivers drive hardware devices.
3. Processes running
   1. CPU alternate processes on each cores one at a time.
   2. OS scheduler decides, after a process has used its allotted time, which process to run next.
   3. Pre-emptive multitasking (usually invoked every 20 ms by the CPU clock)
      1. CPU receives interrupt
      2. Interrupt stores program counter
      3. interrupt invokes handler
      4. handler saves rest of state of the CPU for the process
      5. handler does its business and invokes the scheduler
      6. scheduler selects a process to run
      7. scheduler restores state of the CPU for that process
      8. scheduler jumps execution to that process
   4. Privileges
      1. When OS code runs, the CPU is put into a privilege level that allows it to access I/O devices and any address of memory.
      2. When a process runs, the CPU is put into a privileged level that triggers a hardware exception when the code attempts to directly access the I/O devices or addresses not allowed for that process.
4. Process Memory
   1. Each process uses a portion of its memory for a stack, heap and text. The binary instructions are stored in a contiguous chunk of memory and never modified for the duration of the process except for the dynamic linking with shared libraries.
   2. Stack and heap are both used for storing data.
      1. The stack stores local variables
      2. The heap stores everything else
      3. Stack - Ex
         1. A function calls main, which creates a new frame on a stack, with no return address
         2. It then calls cat function which creates its own frame storing local variables of it along with the size of the frame, the return address and the address to jump back to when execution returns from cat.
         3. When cat function completes, the return address of its frame is used to jump execution to that address.
      4. Stack Pointer
         1. The size of a stack is kept track of by the stack boundary kept in another CPU register. If this register has a value exceeds the stack boundary, it will trigger a hardware exception and the exception handler may increase the stack space by moving the stack boundary.
         2. However if the exception handler may decide that the stack has grown too large and refuse to increase the stack size and terminate the process.
         3. Generally A Megabyte of stack is at the high end.
      5. Stack Overflow
         1. When a program exceeds its available stack space, an error called stack overflow occurs. The OS usually terminates the errant process.
   3. Text
      1. Is stored in the bottom of the program memory
   4. Heap
      1. No heaps in when the program first started and is allocated with system calls.
      2. Heap address allocated may not be contiguous.
      3. Memory space can be fragmented when heaps are added or removed.
      4. Memory is mapped by the OS to the Physical RAM.
   5. Memory Management
      1. OS keeps separate memory table for each process.
      2. If a process tries to access some other memory that doesn't belong to the process. The CPU triggers a hardware exception and OS typically aborts the process with an error message about page fault because the maps chunks of memory is called pages. a chunk of memory is usually 4KB.
      3. The OS may decide to swap out memory to Hard drives and in the process memory table, these heap pages have been marked as swapped. An attempt to access swapped page will trigger a hardware exception and the OS will copy the swap page back to RAM and adjust the memory table.
5. Process Scheduling
   1. Process created by OS is first entered into waiting state to be selected by the scheduler. Then it enters running state by scheduler scheduling it. Then it will be put into waiting state again to allow other processes to run.
   2. The process can also be blocked, waiting for some external event of the system(like a system call to read file, network) before it can proceed rather than waiting to be scheduled.