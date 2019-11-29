# Abstract
This document covers general information regarding OS and hardware, network, troubleshooting and scaling.

# OS and Hardware
1. What's the characteristics of a UNIX system?
    1. There are uniform ways to access information (Everything is just a file)
        1. File, network sockets, IPC channels, kernel parameters and block devices are treated as a file
    2. The underlying system is transparent
        1. Every program operates under the same rules and can be observed, analyzed and debugged the same way
    3. Settings are readable, editable and can be backed up
    4. Mantra is "do one thing, do it well" but not "do it all in once"
        1. Avoids complex intertwined code and security issues
    5. fork()
        1. New programs are started by an existing program cloning itself. This makes easy to apply the same security settings and restrictions to new programs, share memory or setup an IPC mechanism. Low process starting cost.
    6. File system is one tree
        1. Other disk partitions and network shares are mounted under one single root
        2. One universal way of mounting disk partitions and accessing data
    7. Built for low user privileges
        1. After login, every user except root is confined their own resources, running applications and files only. Network services reduce their privileges as soon as possible
        2. One single clear way to get more privileges or ask someone to execute a privileged job on their behalf. Every other call is limited by the restrictions and limitations of the program
    8. Stores settings in a hidden file/folder of the user home directory - no attempts to write global setting file
    9. Loosely coupled components
        1.  Openly described communication mechanisms over secret mechanisms. Vendors and SWE are encouraged to do the same.

2. How does a UNIX system work?
    1. Layering boot perspective
        1. Program bootloader - locates and loads the OS kernel.
        2. Program kernel 
            1. Interacts with hardware for disk, memory, video, sound, etc..
            2. Defines a virtual environment to start programs
            3. Uses many drivers it is bundled with to deal with a variety of hardware devices
            4. Allows programs to be build because it manages lower level ops with consistency
        3. Program background subsystems - network services
            1. Allows remote login, central message bus, hardware/network based event actions
        4. Program command line tools
            1. Little programs for text editing, file downloads, system administration
        5. Program graphical user interface
        6. draws windows at the screen instead of printing text
    2. Shared libs
        1. Why? - allows common UI, networking, filesystem operations to be reused
        2. Allows programmers build high quality applications with less code
    3. Inter process communication
        1. Allows programs to communicate with other programs
            * A piece of shared memory
            * A small channel set up between two programs to exchange data
            * A central message bus on which each program to send and receive messages
            * A global communication where it's unknown which program can respond
    4. Libraries to OS
        1. What is OS?
            * It's a complete suite of all kinds of applications for system services, user administration, configuration, administration, office work, entertainment, etc., built and based on the foundation of libraries, IPC and the kernel.
        2. What's program?
            *. They are all services, system admin tools, etc.

3. How are processes created?
    1. Created with the **fork** system call - hence **forking a process**
        * Each process is named by a process ID number
        * child process created by fork is a copy of the original parent process, except that it has its own process ID
        * The parent process can wait for child process by calling **wait** or **waitpid**
        * The forked child process will continue executing the same program as its parent.
    2. Processes
        1. init
            * Created at system boot time.
            * The root of the process tree
        2. Child Processes
            1. Created by a parent process
    3. Unix Process Creation
        1. fork()
            1. Allocates new address space; moves text, data, & stack into new address space; provides child with access to open files.
        2. exec()
            1. Allows child to run a new program
        3. wait()
            1. allows parent to wait for a child to terminate

4. How do processes communicate?
    1. Signals
        1. What is?
            1. One of the oldest inter process  communication methods used by Unix system. It's used to signal asynchronous events to one or more processes.
        2. Where is it from?
            1. Can be from a keyboard interrupt (^D) or an error condition such as the process attempting to access non-existent location in its virtual memory
        3. What for?
            1. For shells to signal job control commands to their child processes.
        4. Available signals and process/signal characteristics?
            1. SIGHUP(1), SIGINT(2), SIGQUIT(3), SIGTRAP(5), SIGKILL(9), SIGTERM(15), SIGSTOP(19) and more up to 30
            2. Linux implements signals using information stored in **task_struct**
            3. The number of supported signals is limited to the word size of the processor.
            4. The currently pending signals are kept in the signal field with a mask of blocked signals held in blocked
                1. sigpending() returns the set of signals that are pending for delivery to the calling thread.
                2. signals such as sigterm, sigkill, sigstop, ... that are waiting until the process comes out of the D (**uninterruptible sleep**) state.
                3. Usually a process is in that state when it is waiting for I/O. That sleep can't be interrupted. Even sigkill (kill -9) can't and the kernel waits until the process wakes up (the signal is pending for delivery so long).
                4. 
            5.  Linux holds information about how each process handles every possible signal and this is held in an array of **sigaction** data structures pointed at by the **task_struct** for each process. Amongst other things it contains either the address of a routine that will handle the signal or a flag which tells Linux that the process either wishes to ignore this signal or let the kernel handle the signal for it.
            6. If a blocked signal is generated, it remains pending until it is unblocked.
            7. Signals are not presented to the process immediately they are generated., they must wait until the process is running again. Every time a process exits from a system call its signal and blocked fields are checked and, if there are any unblocked signals, they can now be delivered.
                1. The Linux signal processing code looks at the **sigaction** structure for each of the current unblocked signals.
            8.  The process modifies the default signal handling by making system calls and these calls alter the **sigaction** for the appropriate signal as well as the blocked mask.
            9.  Two exceptional signals are:
                1. SIGSTOP(19) - causes a process to halt its execution
                2. SIGKILL(9) - causes a process to exit
            10. If a process has not blocked the signal and is waiting but interruptible (in state **Interruptible**) then it is woken up by changing its state to Running and making sure that it is in the run queue. That way the scheduler will consider it a candidate for running when the system next schedules.
            11. A SIGSTOP signal's default handler will change the current process's state to **Stopped** and then run the scheduler to select a new process to run.
        5. Who can send signals to a process
            1.  Kernel and super users can all processes
            2.  Normal processes can only send signals to processes with the same uid and gid or to processes in the same process group
        6. What kernel does does to signals
            1. It handles exceptions such as SIGFPE to core dump and exit.
            2. It calls the process's signal handling routine and how this happens is processor specific but all CPUs must cope with the fact that the current process is running in kernel mode and is just about to return the process that called the kernel or system routine in user mode.
                1. The Kernel solves this by manipulating the stack and registers of the process.
                2. The Kernel sets the process's program counter to the address of its signal handling routine and the parameters to the routine are added to the call frame or passed in registers.
                3. When the process resumes operation it appears as if the signal handling routine were called normally.
        7. **blocked** mask
            1.  Process can specify which signals are blocked when a particular signal handling routine is called. This means changing the blocked mask during the call to the process signal handler.
                1.  The blocked mask must be returned to its original value when the signal handling routine has finished.
                2.  Therefore there is a call routine to restore the original blocked mask onto the call stack of the signalled process.
    2. Pipes
        1. What is pipe?
            1. A unidirectional byte stream that connects the **standard output** from one process to the **standard input** of another process.
                1. Neither processes is aware of the redirection
                2. It is the shell which sets up these temporary pipes between the processes.
        2. How is it implemented?
            1. Implemented using two file data structures which both point at the same temporary VFS inode which itself points at a physical page within memory. 
                1. Each file data structure contains pointers to different file operation routine vectors; one for writing to the pipe, the other for reading from the pipe.
                2. This hides the underlying differences from the generic system calls which read and write to ordinary files. As the writing process writes to the pipe, bytes are copied into the shared data page and when the reading process reads from the pipe, bytes are copied from the shared data page. 
                3. Linux must synchronize access to the pipe. It must make sure that the reader and the writer of the pipe are in step and to do this it uses locks, wait queues and signals.
        3. Read-write process
            1. When the writer wants to write to the pipe it uses the standard write library functions. These all pass file descriptors that are indices into the process's set of file data structures, each one representing an open file or, as in this case, an open pipe. The Linux system call uses the write routine pointed at by the file data structure describing this pipe. That write routine uses information held in the VFS inode representing the pipe to manage the write request.
            2. If there is enough room to write all of the bytes into the pipe and, so long as the pipe is not locked by its reader, Linux locks it for the writer and copies the bytes to be written from the process's address space into the shared data page. If the pipe is locked by the reader or if there is not enough room for the data then the current process is made to sleep on the pipe inode's wait queue and the scheduler is called so that another process can run. It is interruptible, so it can receive signals and it will be woken by the reader when there is enough room for the write data or when the pipe is unlocked. When the data has been written, the pipe's VFS inode is unlocked and any waiting readers sleeping on the inode's wait queue will themselves be woken up.
                1. Reading data from the pipe is a very similar process to writing to it.
            3. Processes are allowed to do non-blocking reads (it depends on the mode in which they opened the file or pipe) and, in this case, if there is no data to be read or if the pipe is locked, an error will be returned. This means that the process can continue to run. The alternative is to wait on the pipe inode's wait queue until the write process has finished. When both processes have finished with the pipe, the pipe inode is discarded along with the shared data page.
        4. Named Pipe
            1. Linux also supports named pipes, also known as FIFOs because pipes operate on a First In, First Out principle. The first data written into the pipe is the first data read from the pipe. 
            2. Unlike pipes, FIFOs are not temporary objects, they are entities in the file system and can be created using the mkfifo command. 
            3. Processes are free to use a FIFO so long as they have appropriate access rights to it. 
            4. The way that FIFOs are opened is a little different from pipes. A pipe (its two file data structures, its VFS inode and the shared data page) is created in one go whereas a FIFO already exists and is opened and closed by its users. 
            5. Linux must handle readers opening the FIFO before writers open it as well as readers reading before any writers have written to it. That aside, FIFOs are handled almost exactly the same way as pipes and they use the same data structures and operations.
    3. Unix Domain Sockets
        1. What is?
            1. A **data communications endpoint** for exchanging data between processes executing on the same host operating system
            2. Supports reliable stream of bytes (SOCK_STREAM, like TCP), ordered and reliable transmission of datagrams (SOCK_SEQPACKET, SCTP), and unordered and nnreliable transmission of datagrams (SOCK_DGRAM, like UDP)
        2. Characteristics?
            1. The API is similar to that of an Internet socket, but rather than using an underlying network protocol, all communication occurs entirely within the OS kernel.
            2. It uses the filesystem as their address name space. Processes reference sockets as file system inodes, so two processes can communicate by opening the same socket.
            3. In addition to sending data, processes may send file descriptors across a socket connection using the sendmsg() and recvmsg() system calls.
                1. This allows the sending processes to grant the receiving process access to a file descriptor for which the receiving process otherwise does not have access.
    4. System V IPC Mechanisms
        1. History & Background
            1. Linux supports three types of interprocess communication mechanisms that first appeared in Unix System V (1983). They are message queues, semaphores and shared memory. These all share common authentication methods.
        2. Characteristics?
            1. Processes may access these resources only by passing a unique reference identifer to the kernel via system calls. 
            2. The access rights to the System V IPC object is set by the creator of the object via system calls.
            3. The object's reference ID is used by each mechanism as an index into a table of resources.
            4. IPC mechanism is a structure which contains the owner and creator process's user and group identifiers. 
            5. IPC object's key is used as a way of locating object reference ID. Two sets of keys are supported: public and private. If the key is public then any process in the system, subject to rights checking, can find the reference identifier for the System V IPC object. System V IPC objects can never be referenced with a key, only by their reference identifier.
    5. Message Queues
        1. Characteristics?
            1. Allow one or more processes to write messages, which can be read by one or more reading processes.
            2. Linux maintains a list of message queues, the msgque vector; each element of which points to a msqid_ds data structure that fully describes the message queue. When message queues are created, a new msqid_ds data structure is allocated from system memory and inserted into the vector
            3. Each msqid_ds data structure contains an ipc_perm data structure and pointers to the messages entered onto this queue. In addition, Linux keeps queue modification times such as the last time that this queue was written to and so on. The msqid_ds also contains two wait queues; one for the writers to the queue and one for the readers of the message queue.
        2. Read/Write Ops
            1. Each time a process attempts to write a message to the write queue its effective user and group identifiers are compared with the mode in this queue's ipc_perm data structure. If the process can write to the queue then the message may be copied from the process's address space into a msg data structure and put at the end of this message queue. Each message is tagged with an application specific type, agreed between the cooperating processes. However, there may be no room for the message as Linux restricts the number and length of messages that can be written. In this case the process will be added to this message queue's write wait queue and the scheduler will be called to select a new process to run. It will be woken up when one or more messages have been read from this message queue.
            2. Reading from the queue is a similar process. Again, the processes access rights to the write queue are checked. A reading process may choose to either get the first message in the queue regardless of its type or select messages with particular types. If no messages match this criteria the reading process will be added to the message queue's read wait queue and the scheduler run. When a new message is written to the queue this process will be woken up and run again.
    6. Semaphores
        1. What is?
            1. A location in memory whose value can be tested and set by more than one process.
        2. Characteristics
            1. The test and set operation is, so far as each process is concerned, uninterruptible or atomic; once started nothing can stop it. The result of the test and set operation is the addition of the current value of the semaphore and the set value, which can be positive or negative.
            2. Depending on the result of the test and set operation one process may have to sleep until the semphore's value is changed by another process. Semaphores can be used to implement critical regions, areas of critical code that only one process at a time should be executing.
        3. How it works?
            1. System V IPC semaphore objects each describe a semaphore array and Linux uses the semid_ds data structure to represent this. All of the semid_ds data structures in the system are pointed at by the semary, a vector of pointers. There are sem_nsems in each semaphore array, each one described by a sem data structure pointed at by sem_base. All of the processes that are allowed to manipulate the semaphore array of a System V IPC semaphore object may make system calls that perform operations on them. The system call can specify many operations and each operation is described by three inputs; the semaphore index, the operation value and a set of flags. The semaphore index is an index into the semaphore array and the operation value is a numerical value that will be added to the current value of the semaphore. 
            2. First Linux tests whether or not all of the operations would succeed. An operation will succeed if the operation value added to the semaphore's current value would be greater than zero or if both the operation value and the semaphore's current value are zero. If any of the semaphore operations would fail Linux may suspend the process but only if the operation flags have not requested that the system call is non-blocking. If the process is to be suspended then Linux must save the state of the semaphore operations to be performed and put the current process onto a wait queue. It does this by building a sem_queue data structure on the stack and filling it out. The new sem_queue data structure is put at the end of this semaphore object's wait queue (using the sem_pending and sem_pending_last pointers). The current process is put on the wait queue in the sem_queue data structure (sleeper) and the scheduler called to choose another process to run.
            3. If all of the semaphore operations would have succeeded and the current process does not need to be suspended, Linux goes ahead and applies the operations to the appropriate members of the semaphore array. Now Linux must check that any waiting, suspended, processes may now apply their semaphore operations. It looks at each member of the operations pending queue (sem_pending) in turn, testing to see if the semphore operations will succeed this time. If they will then it removes the sem_queue data structure from the operations pending list and applies the semaphore operations to the semaphore array. It wakes up the sleeping process making it available to be restarted the next time the scheduler runs. Linux keeps looking through the pending list from the start until there is a pass where no semaphore operations can be applied and so no more processes can be woken.
            4. There is a problem with semaphores, deadlocks. These occur when one process has altered the semaphores value as it enters a critical region but then fails to leave the critical region because it crashed or was killed. Linux protects against this by maintaining lists of adjustments to the semaphore arrays. The idea is that when these adjustments are applied, the semaphores will be put back to the state that they were in before the a process's set of semaphore operations were applied. These adjustments are kept in sem_undo data structures queued both on the semid_ds data structure and on the task_struct data structure for the processes using these semaphore arrays.
            5. Each individual semaphore operation may request that an adjustment be maintained. Linux will maintain at most one sem_undo data structure per process for each semaphore array. If the requesting process does not have one, then one is created when it is needed. The new sem_undo data structure is queued both onto this process's task_struct data structure and onto the semaphore array's semid_ds data structure. As operations are applied to the semphores in the semaphore array the negation of the operation value is added to this semphore's entry in the adjustment array of this process's sem_undo data structure. So, if the operation value is 2, then -2 is added to the adjustment entry for this semaphore.
            6. When processes are deleted, as they exit Linux works through their set of sem_undo data structures applying the adjustments to the semaphore arrays. If a semaphore set is deleted, the sem_undo data structures are left queued on the process's task_struct but the semaphore array identifier is made invalid. In this case the semaphore clean up code simply discards the sem_undo data structure.
    7. Shared Memory
        1. Characteristics
            1. Allows one or more processes to communicate via memory that appears in all of their virtual address spaces. The pages of the virtual memory is referenced by page table entries in each of the sharing processes' page tables. It does not have to be at the same address in all of the processes' virtual memory. As with all System V IPC objects, access to shared memory areas is controlled via keys and access rights checking. Once the memory is being shared, there are no checks on how the processes are using it. They must rely on other mechanisms, for example System V semaphores, to synchronize access to the memory.
            2. Each newly created shared memory area is represented by a shmid_ds data structure. These are kept in the shm_segs vector. The shmid_ds data structure decribes how big the area of shared memory is, how many processes are using it and information about how that shared memory is mapped into their address spaces. It is the creator of the shared memory that controls the access permissions to that memory and whether its key is public or private. If it has enough access rights it may also lock the shared memory into physical memory.
            3. Each process that wishes to share the memory must attach to that virtual memory via a system call. This creates a new vm_area_struct data structure describing the shared memory for this process. The process can choose where in its virtual address space the shared memory goes or it can let Linux choose a free area large enough. The new vm_area_struct structure is put into the list of vm_area_struct pointed at by the shmid_ds. The vm_next_shared and vm_prev_shared pointers are used to link them together. The virtual memory is not actually created during the attach; it happens when the first process attempts to access it.
            4. The first time that a process accesses one of the pages of the shared virtual memory, a page fault will occur. When Linux fixes up that page fault it finds the vm_area_struct data structure describing it. This contains pointers to handler routines for this type of shared virtual memory. The shared memory page fault handling code looks in the list of page table entries for this shmid_ds to see if one exists for this page of the shared virtual memory. If it does not exist, it will allocate a physical page and create a page table entry for it. As well as going into the current process's page tables, this entry is saved in the shmid_ds. This means that when the next process that attempts to access this memory gets a page fault, the shared memory fault handling code will use this newly created physical page for that process too. So, the first process that accesses a page of the shared memory causes it to be created and thereafter access by the other processes cause that page to be added into their virtual address spaces.
            5. When processes no longer wish to share the virtual memory, they detach from it. So long as other processes are still using the memory the detach only affects the current process. Its vm_area_struct is removed from the shmid_ds data structure and deallocated. The current process's page tables are updated to invalidate the area of virtual memory that it used to share. When the last process sharing the memory detaches from it, the pages of the shared memory current in physical memory are freed, as is the shmid_ds data structure for this shared memory.
            6. Further complications arise when shared virtual memory is not locked into physical memory. In this case the pages of the shared memory may be swapped out to the system's swap disk during periods of high memory usage.




## Terminologies
1. Core Dump - memory dump, or system dump consists of the recorded state of the working memory of a computer program at a specific time, generally when the program has crashed or otherwise terminated abnormally
