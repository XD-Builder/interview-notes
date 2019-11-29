# Abstract

This document defines and summarizes system calls, signals and their handlers and other aspects of a linux kernel.

# Kernel Mechanisms

1. Bottom Half Handling
   1. Device drivers should not spend too much time handling interrupts as, during this time, nothing else in the system can run. There is often some work that could just as well be done later on.
   2. Linux's bottom half handlers were invented so that device drivers and other parts of the Linux kernel could queue work to be done later on.
2. Task Queue
   1. Kernel's way of deferring work until later.
   2. Used in conjunction with bottom half handlers
   3. Linked list data structure each contains the address of a routine and pointer to some data
3. Timer
   1. An OS needs to be able to schedule an activity sometime in the future
   2. Two types of system timers are available:
      1. Old timer mechanism, a static array of 32 pointers to timer_structure and a mask of active timers
4. Wait Queues
   1. When a process must wait for a system resource. Ex. a process may need VFS inode describing a directory in the fs and that inode may not be in the buffer cache.
5. Buzz Locks
   1. Better known as spin locks and they are primitive way of protecting a data structure or a piece of code. It only allows one process at a time to be within a critical region of code.
6. Semaphores

   1. Used to protect critical regions of code or data structures.

## System Calls

1. Wikipedia
   1. Def
      1. A programmatic way in which a computer program requests a service from the kernel of the operating system it is executed on.
         1. This may include hardware-related services (hard drive access.), creation and execution of new processes, and communication with integral kernel services such as process scheduling.
   2. Categories of Sys calls
      1. Process control
         1. load, execute, end, abort, create process, terminate process, get/set process attribute, wait for time, event, signal, allocate, free memory
      2. File Management
         1. create file, delete file, open, close, read, write, reposition, get/set file attributes
      3. Device Management
         1. request device, release device, read, write, reposition, get/set device attributes, logically attach or detach devices
      4. Information Maintenance
         1. get/set time or date, system data, process, file, device attributes
      5. Communications
         1. create, delete communication connection, send, receive messages, transfer status information, attach and detach remote devices
   3. Context switch
      1. Sys calls in most Unix-like system are processed in kernel mode, which is accomplished by changing the processor execution mode to a more privileged one, but no process context switch is necessary.
      2. Though privilege context switch does occur, the hardware sees the world in terms of the execution mode according to the processor status register, and processes are an abstraction provided by the OS.
      3. A syscall does not generally require a context switch to another process; instead it is processed in the same context of whichever process invoked it.

### context switches

1. Wikipedia
   1. What is?
      1. The process of storing the state of a process or of a thread, so that it can be restored and execution resumed from the same point later. It allows multiple processes to share a single CPU, an essential feature of a multitasking OS.
      2. Can occur as the result of an interrupt, such as when a task needs to access disk storage, freeing up CPU time for other tasks. Some OS require a context switch to move between user mode and kernel mode tasks.
      3. It has a negative impact on sys perf, although the size of this effect depends on the nature of the switch being performed.
   2. What triggers context switch
      1. Multitasking
         1. Within some scheduling scheme, one process must be switched out of the CPU so another process can run. It can be triggered by the process making itself unrunnable such as by waiting for an I/O or synchronization operation to complete.
         2. On a pre-emptive multitasking system, the scheduler may switch out processes which are still runnable. It often configure a timer interrupt to fire when a process exceeds its time slice ensuring that the scheduler will gain control to perform a context switch
      2. Interrupt handling
         1. Modern architectures are interrupt driven and it means that if the CPU requests data from a disk, it does not need busy-wait until the read is over. It can issue the read data from disk request and continue with other executions and when the read is over, the CPU can be interrupted and presented with the read.
         2. When an interrupt occurs, the hardware automatically switches a part of the context. Often a minimal part of the context is changed in order to minimize the amount of time spent handling the interrupt.
         3. The kernel does not spawn or schedule special process to handle interrupts, but instead the handler executes in the context established at the beginning of interrupt handling. Once interrupt servicing is complete, the context in effect before the interrupt occurred is restored so that the interrupted process can resume execution in its proper state.
      3. User and kernel mode switching
         1. When a transition between user mode and kernel mode is required in an OS, a context switch is not necessary; a mode transition is not by itself a context switch. However, depending on the OS, a context switch may also take place at this time.

## Signals & Signal Handlers

1. What is?
   1. A form of IPC used in \*nix OS.
   2. An asynchronous notification sent to a process or to a specific thread within the same process in order to notify it of an event that occurred.
   3. When a signal is sent, the OS interrupts the target process' normal flow of execution to deliver the signal. Execution can be interrupted during any non-atomic instruction.
      1. If the process has previously registered a signal handler, that routine is executed. Else default signal handler is used.
2. What's the difference between signals and interrupts?
   1. Interrupt?
      1. A signal to the processor emitted by hardware or software indicating an event that needs immediate attention. It's high priority and requires suspending all current activities and states. Then it will execute a function call interrupt handler to deal with the event.
      2. Hardware interrupt is caused by external devices.
      3. Software interrupt is an exception/trap used for errors and exceptional events such as divide by zero.
   2. Interrupts are mediated by the processor and handled by the kernel while signals are mediated by kernel (possibly via system calls) and handled by processes.
   3. The kernel may pass an interrupt as a signal to the process that caused it (Ex. SIGSEGV, SIGBUS, SIGILL, SIGFPE)

### What's ioctls

1. Wikipedia
   1. What is?
      1. Input/output control - A system call for device-specific input/output operations and other operations which cannot be expressed by regular system calls.
      2. Allows access to non-standard hardware peripherals.
         1. By necessity, most hardware peripherals (devices) are directly addressable only within the kernel.
         2. Non-standard peripherals are not, therefore in order for userspace to talk to devices directly, **ioctl** interface, a single system call, is needed
      3. A single system call by which userspace may communicate with device drivers. Requests on a device driver are vectored with respect to this ioctl system call, typically by a handle to the device and a request number.
         1. The basic kernel allows the userspace to access device driver without knowing anything about the facilities supported by the device, and without needing an unmanageably large collection of syscalls.
   2. Characteristics
      1. It specifies a request code to create a call. Codes are device-specific.
         1. Ex. CD-ROM device driver can instruct a physical device to eject a disc. It would provide an 'ioctl' request code to do that.
         2. This device-independent request codes are used to give userspace access to kernel functions.
      2. **ioctl** can communicate with USB devices and discover drive-geomtry information of the attached storage-devices
      3. ioctl is exposed in code of terminal I/O.
         1. Unix CLI are built on pseudo terminals (ptys), which emulate hardware text terminals and it's controlled and configured as if it were a hardware device using **ioctl** calls.
      4. ioctl calls provide a convenient way to bridge userspace code to kernel extensions when application need to extend the kernel to accelerate networking, etc..
         1. A kernel extension can provide a location in the filesystem that can be opened by name, through which an arbitrary number of ioctl calls can be dispatched, **allowing the extension to be programmed without adding system calls to the OS**
   3. In UNIX
      1. ioctl call takes params:
         1. a file descriptor
         2. a request code number
         3. an integer value, unsigned or a pointer to data
      2. Efficient for transferring bulk data between a device and a user space application.

### What's sysctls

1. Wikipedia

   1. What is?

      1. A software Utility that reads and modifies the attributes of the system kernel such as its version number, maximum limits, and security settings.
      2. Allows one to change kernel parameters at runtime. It is implemented in procfs, the virtual process file system at /proc/
      3. It's available both as a system call for compiled programs, and an administrator command for interactive use and scripting.
      4. Linux additionally expose sysctl as a virtual file system
         1. Helps tune the OS to increase performance in networking, security and defends against DOS attacks

## Kernel Space vs userspace, and User/Kernel Space Interactions

1. Wikipedia
   1. What is Kernel Space?
      1. Modern OS segregates vm into kernel space and user space as a mean for memory and hardware protection from malicious or errant software behavior
      2. Strictly reserved for running privileged os kernel, kernel extension, and most device drivers.
   2. What is User Space?
      1. Space allocated to user to execute software and some driver
      2. userland(user space) refers to all code that runs outside the os kernel. It refers to various programs and libraries that the os uses to interact with the kernel
