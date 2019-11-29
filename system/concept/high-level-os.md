# Abstract

- This document explores high level OS functions

## Overview

1. Def
   1. OS is an **interface between a computer user and computer hardware** and it **performs all the basic tasks** like file management, memory management, process management, handling input and output, and controlling peripheral devices such as disk drives and printers.
2. Memory Management
   1. Memory management refers to **management of Primary Memory or Main Memory**. Main memory is a large array of words or bytes where each word or byte has its own address.
   2. Main memory provides a fast storage that can be accessed directly by the CPU.
3. Processor Management
   1. In multiprogramming environment, the OS decides **which process gets the processor when and for how much time**. This function is called process scheduling.
4. Device Management
   1. An Operating System **manages device communication via their respective drivers**.
      1. It keeps tracks of all devices. Program responsible for this task is known as the I/O controller.
      2. It decides which process gets the device when and for how much time.
5. File Management
   1. A file system is normally organized into directories for easy navigation and usage. These directories may contain files and other directories.
      1. It keeps track of information, location, uses, status etc. The collective facilities are often known as file system.
      2. It decides who gets the resources.
6. Other Important Activities
   1. Security − By means of password and similar other techniques, it **prevents unauthorized access to programs and data**.
   2. Control over system performance − **Recording delays between request for a service and response from the system**.
   3. Job accounting − Keeping **track of time and resources used by various jobs and users**.
   4. Error detecting aids − **Production of dumps, traces, error messages, and other debugging and error detecting aids**.
   5. Coordination between other softwares and users − **Coordination and assignment of compilers, interpreters, assemblers and other software to the various users of the computer systems**.

## OS Types

1. Intro
   1. **OS are there from the very first computer generation and they keep evolving with time**.
2. Batch OS
   1. The users of a batch operating system do not interact with the computer directly. **Each user prepares his job on an off-line device like punch cards and submits it to the computer operator**.
3. Time-sharing OS
   1. Time-sharing is a technique which enables **many people, located at various terminals, to use a particular computer system at the same time**. Time-sharing or multitasking is a logical extension of multiprogramming. **Processor's time which is shared among multiple users simultaneously is termed as time-sharing**.
   2. The objective is to minimize response time.
4. Distributed OS
   1. Distributed systems **use multiple central processors to serve multiple real-time applications and multiple users**. Data processing jobs are distributed among the processors accordingly.
   2. **The processors communicate with one another through various communication lines (such as high-speed buses or telephone lines)**. These are referred as loosely coupled systems or distributed systems. Processors in a distributed system may vary in size and function. These processors are referred as sites, nodes, computers, and so on.
5. Network operating System
   1. A Network Operating System **runs on a server and provides the server the capability to manage data, users, groups, security, applications, and other networking functions**. The primary purpose of the network operating system is to **allow shared file and printer access among multiple computers in a network, typically a local area network (LAN), a private network or to other networks**.
      1. Examples of network operating systems include Microsoft Windows Server 2003, Microsoft Windows Server 2008, UNIX, Linux, Mac OS X, Novell NetWare, and BSD.
      2. The advantages of network operating systems are centralized servers are **highly stable**, **security is server managed**, upgrades to new technologies and hardware can be easily integrated into the system and **remote access to servers is possible from different locations and types of systems**.
6. Real Time OS
   1. A data processing system in which **the time interval required to process and respond to inputs is so small that it controls the environment**. The time taken by the system to respond to an input and display of required updated information is termed as the response time.
   2. Used when there are **rigid time requirements on the operation of a processor or the flow of data** and real-time systems can be **used as a control device in a dedicated application**.
   3. Applications include scientific experiments, medical imaging systems, industrial control systems, weapon systems, robots, air traffic control systems, etc.
   4. Two types of real-time OS
      1. Hard real-time OS
         1. **It guarantee that critical tasks complete on time**. In hard real-time systems, secondary storage is limited or missing and the data is stored in ROM. In these systems, virtual memory is almost never found.
      2. Soft real-time systems
         1. Soft real-time systems are less restrictive. **A critical real-time task gets priority over other tasks and retains the priority until it completes**. Soft real-time systems have **limited utility than hard real-time systems**.
         2. Applications include multimedia, virtual reality, Advanced Scientific Projects like undersea exploration and planetary rovers, etc.

## OS Services

1. Intro
   1. OS provides programs an environment to execute and users services to execute programs in a convenient manner.
   2. Common services provided by OS include program execution, I/O operations, file system manipulation, error detection, resource allocation and protection.
2. Program execution
   1. Operating systems **handle many kinds of activities from user programs to system programs** like printer spooler, name servers, file server, etc. Each of these activities is encapsulated as a process.
   2. A process **includes the complete execution context** (code to execute, data to manipulate, registers, OS resources in use).
   3. Major activities of an OS with respect to program management include loading a program into memory, executing the program, handling program execution, providing mechanism for process synchronization, communication and deadlock handling.
3. I/O operation
   1. An I/O subsystem comprises of I/O devices and their corresponding driver software. **Drivers hide the peculiarities of specific hardware devices from the users**.
4. File system manipulation
   1. **A file represents a collection of related information**. Computers can store files on the disk (secondary storage), for long-term storage purpose. Examples of storage media include magnetic tape, magnetic disk and optical disk drives like CD, DVD. **Each of these media has its own properties like speed, capacity, data transfer rate and data access methods**.
   2. Major activities of an OS with respect to file management include managing programs needing to read/write to a file, giving permission to program for operation on file, providing interface to the user to create/delete files and directories and create backup of file system.
5. Communication
   1. In case of **distributed systems which are a collection of processors that do not share memory, peripheral devices, or a clock**, the operating system manages communications between all the processes. Multiple processes communicate with one another through communication lines in the network.
   2. The OS handles routing and connection strategies, and the problems of contention and security.
   3. Major activities of an OS with respect to communication include **enabling communication amongst processes on the same computer or different computers through a network via shared memory or by message passing.**
6. Error handling
   1. Error can occur anytime and anywhere. An error may occur in CPU, in I/O devices or in the memory hardware.
   2. Major activities of an OS with respect to error handling include constantly checking for possible errors and taking appropriate actions to ensure correct and consistent computing.
7. Resource Management
   1. In case of **multi-user or multi-tasking environment, resources such as main memory, CPU cycles and file storage are to be allocated to each user or job**.
   2. Major activities of an OS with respect to resource management include managing all kinds of resources using schedulers and using schedulign algorithms for better utilization of CPU.
8. Protection
   1. Considering a computer system having multiple users and concurrent execution of multiple processes, **the various processes must be protected from each other's activities.**
   2. Protection refers to **a mechanism or a way to control the access of programs, processes, or users to the resources defined by a computer system**.
   3. Major activities of an OS with respect to protection include ensuring all access to system resources is controlled, external I/O devices are protected from invalid access attempts and providing authentication features for each user by means of passwords.

## Process

1. Def
   1. A program in execution and it must progress in a sequential fashion.
   2. When a program is loaded into the memory and it becomes a process, it can be divided into four sections ─ stack, heap, text and data.
   3. Process components
      1. Stack - The process Stack contains the temporary data such as method/function parameters, return address and local variables.
      2. Heap - This is dynamically allocated memory to a process during its run time.
      3. Text - This includes the current activity represented by the value of Program Counter and the contents of the processor's registers.
      4. Data - This section contains the global and static variables.
2. Process Lifecycle
   1. When a process executes it passes different states including start, ready, running, waiting and terminated or Exit.
      1. Start is when the process is in started/created state; ready is when the process is waiting to be assigned to a processor; running is the process is assigned to a processor by the OS scheduler; waiting is when process moves into the waiting state when it needs to wiat for a resource; terminated or exit means process finishes its execution.
3. PCB (process control block)
   1. A data structure maintained by the OS for every process. PCB is identified by an integer process id (PID) and it keeps all information needed to keep etrack of a process including:
      1. **Process state** - the current state of the process (running, waiting,...)
      2. **Process privileges** - allow/disallow access to sys resources
      3. **Process ID** - PID
      4. **Pointer to parent PCB** - pointer to parent process
      5. **Program Counter** - pointer to address of the next instruction to be executed
      6. **CPU Registers** - Various registers where process need to be restored for execution in running state.
      7. **CPU Scheduling Information** - **Process priority and other scheduling information** which is required to schedule the process.
      8. **Memory management information** - includes the information of **page table, memory limits, segment table** depending on memory used by OS
      9. **Accounting information** - includes the amount of CPU used for process execution, time limits, execution ID etc.
      10. **IO status information** - includes **a list of I/O devices allocated to the process**s.

## Process Scheduling

1. Process Scheduling Queues
   1. **The OS maintains all PCBs in Process Scheduling Queues**. The OS maintains **a separate queue for each of the process states and PCBs of all processes in the same execution state are placed in the same queue**. When the state of a process is changed, its PCB is unlinked from its current queue and moved to its new state queue.
   2. Following important process scheduling queues are maintained by OS
      1. Job queue - This queue keeps all the processes in the system.
      2. Ready queue - This queue keeps a set of all processes **residing in main memory, ready and waiting to execute**. A new process is always put in this queue.
      3. Device queues − **The processes which are blocked due to unavailability of an I/O device constitute this queue**.
   3. OS can use different to manage each queue. The OS scheduler determines how to move processes between the ready and run queues which can only have one entry per processor core on the system.
2. Schedulers
   1. Schedulers are special system software which handle process scheduling in various ways.
   2. Long-Term Scheduler
      1. It selects processes from the queue and loads them into memory for execution. Process loads into the memory for CPU scheduling.
      2. The primary objective of the job scheduler is to p**rovide a balanced mix of jobs, such as I/O bound and processor bound**. It also controls the degree of multiprogramming. If the degree of multiprogramming is stable, then **the average rate of process creation must be equal to the average departure rate of processes leaving the system**.
   3. Short Term Scheduler
      1. Its main objective is **to increase system performance in accordance with the chosen set of criteria**. It is the change of ready state to running state of the process. CPU scheduler selects a process among the processes that are ready to execute and allocates CPU to one of them.
      2. Short-term schedulers, also **known as dispatchers, make the decision of which process to execute next**. Short-term schedulers are faster than long-term schedulers.
   4. Medium Term Scheduler
      1. Medium-term scheduling is **a part of swapping**. It removes the processes from the memory. **It reduces the degree of multiprogramming. The medium-term scheduler is in-charge of handling the swapped out-processes**.
3. Context Switch
   1. A context switch is **the mechanism to store and restore the state or context of a CPU in Process Control block so that a process execution can be resumed from the same point at a later time**. Using this technique, **a context switcher enables multiple processes to share a single CPU**. Context switching is an **essential part of a multitasking operating system features**.
   2. When the scheduler switches the CPU from executing one process to execute another, **the state from the current running process is stored into the process control block**. After this, the state for the process to run next is loaded from its own PCB and used to set the PC, registers, etc. At that point, the second process can start executing.

## Multi-Threading

1. What is Thread?
   1. A thread is **a flow of execution through the process code, with its own program counter that keeps track of which instruction to execute next, system registers which hold its current working variables, and a stack which contains the execution history**.
   2. A thread shares with its peer threads few information like code segment, data segment and open files. **When one thread alters a code segment memory item, all other threads see that**.
   3. A thread is also called **a lightweight process**. Threads provide a way to **improve application performance through parallelism**. Threads represent a software approach to improving performance of operating system by reducing the overhead thread is equivalent to a classical process.
   4. **Each thread belongs to exactly one process and no thread can exist outside a process**. Each thread represents **a separate flow of control**. Threads have been successfully **used in implementing network servers and web server**. They also provide **a suitable foundation for parallel execution of applications on shared memory multiprocessors**.
2. Difference between processes and thread
   1. Process is heavy weight or resource intensive whereas thread is light weight, taking lesser resources than a process.
   2. Process switching needs interaction with OS whereas thread switching does not need to interact with OS.
   3. In multiple processing environment each process executes the same code but has its own memory and file resources whereas all threads can share same set of open files, child processes.
   4. **If one process is blocked, then no other process can execute until the first process is unblocked while one thread is blocked and waiting, a second thread in the same task can run**.
   5. Multiple processes without using threads use more resources whereas multiple threaded processes use fewer resources.
   6. In multiple processes each process operates independently of the other whereas one thread can read, write or change another thread's data.
3. Advantages of thread
   1. It minimizes the context switching time.
   2. It provides concurrency within a process and allows efficient communication.
   3. **It is more economical to create and context switch threads**.
   4. **Threads allow utilization of multiprocessor architectures to a greater scale and efficiency**.
4. Types of Thread
   1. User Level Threads - User managed threads
   2. Kernel Level Threads - OS managed threads acting on kernel, an OS core.
5. User Level Threads
   1. In this case, the thread management kernel is not aware of the existence of threads. **The thread library contains code for creating and destroying threads, for passing message and data between threads, for scheduling thread execution and for saving and restoring thread contexts. The application starts with a single thread**.
   2. Advantages
      1. **Thread switching does not require Kernel mode privileges**.
      2. **User level thread can run on any OS**.
      3. Scheduling can be application specific in the user level thread.
      4. **User level threads are fast to create and manage**.
   3. Disadvantages
      1. In a typical OS, most system calls are blocking
      2. Multithreaded application cannot take advantage of multiprocessing (Utilizing multiple processor). However, it's possible however that the kernel would support mapping multiple user threads to kernel threads to run on multiple cores.
6. Kernel Level Threads
   1. In this case, **thread management is done by the Kernel**. There is no thread management code in the application area. **Kernel threads are supported directly by the operating system**. Any application can be programmed to be multithreaded. **All of the threads within an application are supported within a single process**.
   2. **The Kernel maintains context information for the process as a whole and for individuals threads within the process**. Scheduling by the Kernel is done on a thread basis. **The Kernel performs thread creation, scheduling and management in Kernel space. Kernel threads are generally slower to create and manage than the user threads**.
   3. Advantages
      1. Kernel can simultaneously schedule multiple threads from the same process on multiple processes.
      2. If one thread in a process is blocked, the Kernel can schedule another thread of the same process.
      3. Kernel routines themselves can be multithreaded.
   4. Disadvantages
      1. Kernel threads are **generally slower to create and manage than the user threads**.
      2. **Transfer of control from one thread to another within the same process requires a mode switch to the Kernel**.
7. Multithreading Models
   1. Some OS provides a **combined user level thread and Kernel level thread facility**.
      1. Solaris is a good example of this combined approach. **In a combined system, multiple threads within the same application can run in parallel on multiple processors and a blocking system call need not block the entire process**.
   2. Multithreading models are three types
      1. Many to Many
      2. Many to One
      3. One to One
8. Many to Many Model
   1. It multiplexes any number of user threads onto an equal or smaller number of kernel threads.
   2. This model provides the **best accuracy on concurrency and when a thread performs a blocking system call, the kernel can schedule another thread for execution**.
9. Many to One Model
   1. It **maps many user level threads to one Kernel-level thread**. Thread management is done in user space by the thread library. **When thread makes a blocking system call, the entire process will be blocked**. Only one thread can access the Kernel at a time, so multiple threads are unable to run in parallel on multiprocessors.
   2. If the user-level thread libraries are implemented in the operating system in such a way that the system does not support them, then the Kernel threads use the many-to-one relationship modes.
10. One to One Model
    1. There is one-to-one relationship of user-level thread to the kernel-level thread. This model **provides more concurrency than the many-to-one model**. It also allows another thread to run when a thread makes a blocking system call. It supports multiple threads to execute in parallel on microprocessors.
    2. Disadvantage of this model is that **creating user thread requires the corresponding Kernel thread. OS/2, windows NT and windows 2000 use one to one relationship model**.
11. Difference between kernel and user level thread
    1. User level threads are faster to create and manage whereas kernel level threads are slower.
    2. User level threads implementation is by a thread library at the user level whereas kernel level threads are supported by OS.
    3. User level threads are generic and can run on any operating system whereas kernel level threads are specific to OS
    4. User level threads cannot take advantage of multiprocessing whereas kernel level threads can.

## Memory Management

1. Intro
   1. **Memory management is the functionality of an OS which handles or manages primary memory and moves processes back and forth between main memory and disk during execution**. Memory management keeps track of each and every memory location, regardless of either it is allocated to some process or it is free.
      1. It checks how much memory is to be allocated to processes.
      2. It decides which process will get memory at what time.
      3. It tracks whenever some memory gets freed or unallocated and correspondingly it updates the status.
2. Process Address Space
   1. The process address space is the set of logical addresses that a process references in its code.
      1. For example, when 32-bit addressing is in use, **addresses can range from 0 to 0x7fffffff; that is, 2^31 possible numbers**, for a total theoretical size of 2 gigabytes.
   2. The OS takes care of **mapping the logical addresses to physical addresses at the time of memory allocation to the program**. There are **three types of addresses used in a program before and after memory is allocated**.
      1. Symbolic Addresses
         1. The addresses used in a source code. **The variable names, constants, and instruction labels are the basic elements of the symbolic address space**.
      2. Relative Addresses
         1. **At the time of compilation**, a compiler converts symbolic addresses into relative addresses.
      3. Physical addresses
         1. The loader generates these addresses at the time **when a program is loaded into main memory**.
   3. Virtual and physical addresses are the same in compile-time and load-time address-binding schemes but they differ in execution-time address-binding scheme.
      1. The set of all logical addresses generated by a program is referred to as a **logical address space**. The set of all physical addresses corresponding to these logical addresses is referred to as a **physical address space**.
      2. **The runtime mapping from virtual to physical address is done by the memory management unit (MMU) which is a hardware device**. MMU uses following mechanism to convert virtual address to physical address.
         1. The value in the base register is added to every address generated by a user process, which is treated as offset at the time it is sent to memory.
            1. For example, if the base register value is 10000, then an attempt by the user to use address location 100 will be dynamically reallocated to location 10100.
         2. **The user program deals with virtual addresses; it never sees the real physical addresses**.
3. Static vs Dynamic Loading
   1. The choice between Static or Dynamic Loading is to be **made at the time of computer program being developed**.
      1. If you have to load your program statically, then at the time of compilation, **the complete programs will be compiled and linked without leaving any external program or module dependency**. The linker combines the object program with other necessary object modules into an absolute program, which also includes logical addresses.
      2. If you are writing a Dynamically loaded program, then **your compiler will compile the program and for all the modules which you want to include dynamically, only references will be provided** and rest of the work will be done at the time of execution.
         1. At the time of loading, with static loading, the absolute program (and data) is loaded into memory in order for execution to start.
         2. If you are using dynamic loading, **dynamic routines of the library are stored on a disk in relocatable form and are loaded into memory only when they are needed by the program**.
4. Static vs Dynamic Linking
   1. As explained above, when static linking is used, **the linker combines all other modules needed by a program into a single executable program to avoid any runtime dependency**.
   2. When dynamic linking is used, it is not required to link the actual module or library with the program, rather **a reference to the dynamic module is provided at the time of compilation and linking**. Dynamic Link Libraries (DLL) in Windows and Shared Objects in Unix are good examples of dynamic libraries.
5. Swapping
   1. Swapping is **a mechanism in which a process can be swapped temporarily out of main memory (or move) to secondary storage (disk) and make that memory available to other processes**. At some later time, the system swaps back the process from the secondary storage to main memory.
   2. Though performance is usually affected by swapping process but it helps in running multiple and big processes in parallel and that's the reason Swapping is also known as **a technique for memory compaction**.
6. Memory Allocation
   1. Main memory usually has two partitions
      1. Low Memory - OS resides in this memory
      2. High Memory - User processes are held in this memory
7. Fragmentation
   1. As processes are loaded and removed from memory, the free memory space is broken into little pieces. It happens **after sometimes that processes cannot be allocated to memory blocks considering their small size and memory blocks remains unused**. This problem is known as Fragmentation.
   2. External fragmentation can be reduced by compaction or shuffle memory contents to place all free memory together in one large block. To make compaction feasible, relocation should be dynamic.
      1. The internal fragmentation can be reduced by effectively assigning the smallest partition but large enough for the process.
8. Paging
   1. A computer can address more memory than the amount physically installed on the system. This extra memory is actually called virtual memory and it is a section of a hard that's set up to emulate the computer's RAM. **Paging technique plays an important role in implementing virtual memory**.
   2. **Paging is a memory management technique in which process address space is broken into blocks of the same size called pages (size is power of 2, between 512 bytes and 8192 bytes). The size of the process is measured in the number of pages**.
   3. Similarly, **main memory is divided into small fixed-sized blocks of (physical) memory called frames and the size of a frame is kept the same as that of a page to have optimum utilization of the main memory and to avoid external fragmentation**.
9. Address Translation
   1. Page address is called logical address and represented by page number and the offset.
      1. Logical Address = Page number + page offset
   2. Frame address is called physical address and represented by a frame number and the offset.
      1. Physical Address = Frame number + page offset
   3. A data structure called **page map table is used to keep track of the relation between a page of a process to a frame in physical memory**.
   4. Page Table Flow
      1. When the system allocates a frame to any page, it translates this logical address into a physical address and **create entry into the page table to be used throughout execution of the program**.
      2. When a process is to be executed, its corresponding pages are loaded into any available memory frames. Suppose you have a program of 8Kb but your memory can accommodate only 5Kb at a given point in time, then the paging concept will come into picture. When a computer runs out of RAM, the operating system (OS) will move idle or unwanted pages of memory to secondary memory to free up RAM for other processes and brings them back when needed by the program.
      3. **This process continues during the whole execution of the program where the OS keeps removing idle pages from the main memory and write them onto the secondary memory and bring them back when required by the program.**
   5. Advantages and Disadvantages of Paging
      1. Paging reduces external fragmentation, but still suffer from internal fragmentation.
      2. Paging is simple to implement and assumed as an efficient memory management technique.
      3. Due to equal size of the pages and frames, swapping becomes very easy.
      4. Page table requires extra memory space, so may not be good for a system having small RAM.
10. Segmentation
    1. Segmentation is **a memory management technique in which each job is divided into several segments of different sizes, one for each module that contains pieces that perform related functions. Each segment is actually a different logical address space of the program**.
    2. When a process is to be executed, its corresponding segmentation are loaded into non-contiguous memory though every segment is loaded into a contiguous block of available memory.
       1. Segmentation memory management works very similar to paging but here **segments are of variable-length where as in paging pages are of fixed size**.
       2. A program segment contains the program's main function, utility functions, data structures, and so on. **The operating system maintains a segment map table for every process and a list of free memory blocks along with segment numbers, their size and corresponding memory locations in main memory**. For each segment, the table stores the starting address of the segment and the length of the segment. A reference to a memory location includes a value that identifies a segment and an offset.

## Virtual Memory

1. Def
   1. The extra memory stored in a section of a hard disk that's set up to emulate the computer's RAM.
   2. Commonly implemented by demand paging and can be implemented in a segmentation system. It's also used to provide VM.
2. Demand Paging
   1. When a context switch occur, the OS does not copy any of the old program's pages out to the disk or any of new program's pages into the main memory. **Instead OS begins executing the new program after loading the first page and fetches that program's pages as they are referenced**.
   2. While executing a program, if the program references a page which is no available in the main memory because it was swapped out a little ago, **the processor treats this invalid memory references as a page fault and transfers control from the program to the OS to demand the page back into the memory**.
   3. Advantage
      1. Large VM
      2. More efficient use of memory
      3. No limit on degree of multiprogramming.
   4. Disadvantage
      1. Number of tables and the amount of processor overhead for handling page interrupts.
3. Page Replacement Algorithm
   1. Techniques used by OS to decide which memory pages to swap out, write to disk when a page of memory needs to be allocated.
      1. It happens (paging) whenever a page fault occurs and a free page cannot be used for allocation purpose accounting **to reason that pages are not available or the number of free pages ahis lower than required pages**.
      2. When the page that was selected for replacement and was paged out, is referenced again, **it has to read in from disk, and this requires for I/O completion**. This process determines the **quality of the page replacement algorithm:** the lesser the time waiting for page-ins, the better is the algorithm.
   2. Definition
      1. A page replacement algorithm **looks at the limited information about accessing the pages provided by hardware, and tries to select which pages should be replaced to minimize the total number of page misses, while balancing it with the costs of primary storage and processor time of the algorithm itself**.
   3. Common page replacement algorithms are
      1. FIFO algorithm
      2. Optimal Page Algorithm
         1. Replace the page that will not be used for the longest period of time. Keeps the time all pages are used.
      3. LRU algorithm
         1. Easy to implement, keep a list and replace pages by looking back into time.
      4. Page Buffering algorithm
      5. Least Frequently Used algorithm
      6. Most Frequently Used algorithm

## I/O Hardware

1. Overview
   1. OS's main job is to manage various I/O devices including mouse, keyboards, touch pad, disk drives, display adapters, USB devices, Bit-mapped screen, LED, Analog-to-digital converter, On/off switch, network connections, audio I/O, printer, etc.
   2. I/O system requires taking an application I/O request and send it to the physical device and take device response and send it to the application.
   3. IO device categories are:
      1. Block device
      2. Character devices
2. Device Controllers
   1. **Device Drivers** are software modules that can be plugged into an OS to handle a particular device. OS interacts with device drivers which handles I/O ops for all IO devices.
   2. **Device Controller** works like an interface between a device and a device driver. It may be able to handle multiple devices. **As an interface its main task is to convert serial bit stream to block of bytes, perform error correction as necessary**.
   3. Any device connected to the computer is connected by a plug and socket, and the **socket is connected to a device controller**.
3. Sync vs Async I/O
   1. Sync IO waits while I/O proceeds
   2. Async IO proceeds concurrently with CPU execution
4. Communication to IO devices
   1. **Three approaches available to communicate with the CPU and Device**
      1. Serial Instruction IO
      2. Memory-mapped IO
      3. Direct Memory Access (DMA)
   2. Special Instruction IO
      1. It uses **CPU instructions that are specifically made for controlling IO devices**. These instructions typically allow data to be sent to an IO device and read from an IO device.
   3. Memory-mapped I/O
      1. When using memory-mapped I/O, **the same address space is shared by memory and I/O devices**. The device is **connected directly to certain main memory locations so that I/O device can transfer block of data to/from memory without going through CPU**.
      2. While using memory mapped IO, **OS allocates buffer in memory and informs I/O device to use that buffer to send data to the CPU. I/O device operates asynchronously with CPU, interrupts CPU when finished**.
      3. The advantage to this method is that **every instruction which can access memory can be used to manipulate an I/O device**. Memory mapped IO is **used for most high-speed I/O devices like disks, communication interfaces**.
   4. DMA
      1. **Slow devices like keyboards will generate an interrupt to the main CPU after each byte is transferred**. If a fast device such as a disk generated an interrupt for each byte, the operating system would spend most of its time handling these interrupts. So a typical computer uses direct memory access (DMA) hardware to reduce this overhead.
      2. Direct Memory Access (DMA) means **CPU grants I/O module authority to read from or write to memory without involvement**. DMA module itself controls exchange of data between main memory and the I/O device. CPU is only involved at the beginning and end of the transfer and interrupted only after entire block has been transferred.
      3. Direct Memory Access **needs a special hardware called DMA controller (DMAC) that manages the data transfers and arbitrates access to the system bus**. The controllers are programmed with source and destination pointers (where to read/write the data), counters to track the number of transferred bytes, and settings, which includes I/O and memory types, interrupts and states for the CPU cycles.
5. Polling vs Interrupts IO
   1. Def
      1. **A computer must have a way of detecting the arrival of any type of input**. There are two ways that this can happen, known as polling and interrupts. Both of these techniques **allow the processor to deal with events that can happen at any time and that are not related to the process it is currently running**.
   2. Polling IO
      1. The simplest way for an I/O device to communicate with the processor. **The process of periodically checking status of the device to see if it is time for the next I/O operation, is called polling**. The I/O device simply p**uts the information in a Status register, and the processor must come and get the information**.
         1. Most of the time, devices will not require attention and when one does it will have to wait until it is next interrogated by the polling program. **This is an inefficient method and much of the processors time is wasted on unnecessary polls**.
         2. Compare this method to a teacher continually asking every student in a class, one after another, if they need help. **Obviously the more efficient method would be for a student to inform the teacher whenever they require assistance**.
   3. Interrupt IO
      1. An alternative scheme for dealing with I/O is the interrupt-driven method. **An interrupt is a signal to the microprocessor from a device that requires attention**.
      2. **A device controller puts an interrupt signal on the bus when it needs CPU’s attention when CPU receives an interrupt, it saves its current state and invokes the appropriate interrupt handler using the interrupt vector (addresses of OS routines to handle various events)**.
         1. **When the interrupting device has been dealt with, the CPU continues with its original task as if it had never been interrupted.**

## IO Software

1. IO software by layers
   1. User Level Libraries
      1. simple interface to user program to perform IO. Ex include stdio provided by C and C++
   2. Kernel Level Modules
      1. **Device driver to interact with the device controller and device independent IO modules used by the device drivers**.
   3. Hardware
      1. This includes actual hardware and hardware controller which interact with the device drivers and make hardware alive.
2. Device Drivers
   1. **Software modules that can be plugged into an OS to handle a particular device**. Operating System takes help from device drivers to handle all I/O devices. **Device drivers encapsulate device-dependent code and implement a standard interface in such a way that code contains device-specific register reads/writes**. Device driver, is generally written by the device's manufacturer and delivered along with the device on a CD-ROM.
3. Interrupt handlers
   1. **An interrupt handler, also known as an interrupt service routine or ISR, is a piece of software or more specifically a callback function in an operating system or more specifically in a device driver, whose execution is triggered by the reception of an interrupt**.
   2. When the interrupt happens, the interrupt procedure does whatever it has to in order to **handle the interrupt, updates data structures and wakes up process that was waiting for an interrupt to happen**.
   3. **The interrupt mechanism accepts an address ─ a number that selects a specific interrupt handling routine/function from a small set. In most architectures, this address is an offset stored in a table called the interrupt vector table. This vector contains the memory addresses of specialized interrupt handlers**.
4. Device-Independent IO Software
   1. **The basic function of the device-independent software is to perform the I/O functions that are common to all devices and to provide a uniform interface to the user-level software**. Though it is difficult to write completely device independent software but we can write some modules which are common among all the devices.
5. User-Space IO Software
   1. These are the **libraries which provide richer and simplified interface to access the functionality of the kernel or ultimately interactive with the device drivers**. Most of the user-level I/O software consists of library procedures with some exception like spooling system which is a way of dealing with dedicated I/O devices in a multiprogramming system.
   2. **I/O Libraries (e.g., stdio) are in user-space to provide an interface to the OS resident device-independent I/O SW**. For example putchar(), getchar(), printf() and scanf() are example of user level I/O library stdio available in C programming.
6. Kernel IO Subsystem
   1. Responsible to provide many servicse related to IO
      1. Scheduling
         1. Kernel schedules a set of I/O requests to determine a good order in which to execute them. **When an application issues a blocking I/O system call, the request is placed on the queue for that device**. The Kernel I/O scheduler rearranges the order of the queue to improve the overall system efficiency and the average response time experienced by the applications.
      2. Buffering
         1. Kernel I/O Subsystem **maintains a memory area known as buffer that stores data while they are transferred between two devices or between a device with an application operation**. Buffering is **done to cope with a speed mismatch between the producer and consumer of a data stream or to adapt between devices that have different data transfer sizes**.
      3. Caching
         1. Kernel **maintains cache memory which is region of fast memory that holds copies of data**. Access to the cached copy is more efficient than access to the original.
      4. Spooling and Device Reservation
         1. **A spool is a buffer that holds output for a device, such as a printer, that cannot accept interleaved data streams. The spooling system copies the queued spool files to the printer one at a time**. In some operating systems, spooling is managed by a system daemon process. In other operating systems, it is handled by an in kernel thread.
      5. Error handling
         1. **An operating system that uses protected memory can guard against many kinds of hardware and application errors**.

## Linux

1. Def
   1. Linux is one of popular version of UNIX operating System.
   2. It is open source as its source code is freely available. It is free to use. Linux was designed considering UNIX compatibility. Its functionality list is quite similar to that of UNIX.
2. Components of Linux System
   1. Kernel
      1. Kernel is the core part of Linux. It is responsible for all major activities of this operating system. **It consists of various modules and it interacts directly with the underlying hardware.** Kernel provides the required abstraction to hide low level hardware details to system or application programs.
   2. System Library
      1. System libraries are **special functions or programs using which application programs or system utilities accesses Kernel's features**. These libraries **implement most of the functionalities of the operating system and do not requires kernel module's code access rights**.
   3. System Utility
      1. **System Utility programs are responsible to do specialized, individual level tasks**.
3. Kernel Model vs User Mode
   1. **Kernel component code executes in a special privileged mode called kernel mode with full access to all resources of the computer**. This code represents a single process, executes in single address space and do not require any context switch and hence is very efficient and fast. **Kernel runs each processes and provides system services to processes, provides protected access to hardware to processes**.
   2. Support code which is not required to run in kernel mode is in System Library. **User programs and other system programs works in User Mode which has no access to system hardware and kernel code**. User programs/ utilities use System libraries to access Kernel functions to get system's low level tasks.
4. Architecture
   1. Hardware layer − Hardware consists of all peripheral devices (RAM/ HDD/ CPU etc).
   2. Kernel − It is the core component of Operating System, interacts directly with hardware, provides low level services to upper layer components.
   3. Shell − An interface to kernel, hiding complexity of kernel's functions from users. The shell takes commands from the user and executes kernel's functions.
   4. Utilities − Utility programs that provide the user most of the functionalities of an operating systems.
