# Abstract

This document explains computer languages, operating system and kernel data structures

# Intro

1. A program is a set of computer instructions that perform a particular task.
   1. That program can be written in assembler, a very low level computer language, or in a high level, machine independent language such as the C programming language.
   2. An operating system is a special program which allows the user to run applications such as spreadsheets and word processors.

# Computer Languages

## Assembly Languages

1. What is Assembly Languages?
   1. The instructions that a CPU fetches from memory and executes are not at all understandable to human beings. They are machine codes which tell the computer precisely what to do.
   2. One of the first software tools invented for the earliest computers was an assembler, a program which takes a human readable source file and assembles it into machine code.
      1. Assembly languages explicitly handle registers and operations on data and they are specific to a particular microprocessor.
      2. The assembly language for an Intel X86 microprocessor is very different to the assembly language for an Alpha AXP microprocessor.
2. Characteristics
   1. Assembly level programs are tedious and tricky to write and prone to errors.
   2. Very little of the Linux kernel is written in assembly language and those parts that are are written only for efficiency and they are specific to particular microprocessors.

## The C Programming Language and Compiler

1. Why C?
   1. Writing large programs in assembly language is a difficult and time consuming task. It is prone to error and the resulting program is not portable, being tied to one particular processor family. It is far better to use a machine independent language like C.
   2. C allows you to describe programs in terms of their logical algorithms and the data that they operate on. Special programs called compilers read the C program and translate it into assembly language, generating machine specific code from it.
   3. A good compiler can generate assembly instructions that are nearly as efficient as those written by a good assembly programmer. Most of the Linux kernel is written in the C language.
2. Characteristics
   1. Large programs like the Linux kernel comprise many separate C source modules each with its own routines and data structures. These C source code modules group together logical functions such as filesystem handling code.
   2. C supports many types of variables, a variable is a location in memory which can be referenced by a symbolic name. A programmer does not care where in memory the variables are put, it is the linker (see below) that has to worry about that. Some variables contain different sorts of data, integer and floating point and others are pointers.
   3. Pointers are variables that contain the address, the location in memory of other data. Consider a variable called x, it might live in memory at address 0x80010000. You could have a pointer, called px, which points at x. px might live at address 0x80010030. The value of px would be 0x80010000: the address of the variable x.

## Linkers

1. What is?
   1. Linkers are programs that link together several object modules and libraries to form a single, coherent, program. Object modules are the machine code output from an assembler or compiler and contain executable machine code and data together with information that allows the linker to combine the modules together to form a program. For example one module might contain all of a program's database functions and another module its command line argument handling functions.
   2. Linkers fix up references between these object modules, where a routine or data structure referenced in one module actually exists in another module. The Linux kernel is a single, large program linked together from its many constituent object modules.

# What is OS?

1. What is?
   1. A collection of system programs which allow the user to run application software. The operating system abstracts the real hardware of the system and presents the system's users and its applications with a virtual machine.
   2. Linux is made up of a number of functionally separate pieces that, together, comprise the operating system. One obvious part of Linux is the kernel itself; but even that would be useless without libraries or shells.
2. interactions
   1. \$ ls
      1. The \$ is a prompt put out by a login shell (in this case bash). This means that it is waiting for you, the user, to type some command. Typing ls causes the keyboard driver to recognize that characters have been typed. The keyboard driver passes them to the shell which processes that command by looking for an executable image of the same name. It finds that image, in /bin/ls. Kernel services are called to pull the ls executable image into virtual memory and start executing it. The ls image makes calls to the file subsystem of the kernel to find out what files are available.
      2. The filesystem might make use of cached filesystem information or use the disk device driver to read this information from the disk. It might even cause a network driver to exchange information with a remote machine to find out details of remote files that this system has access to (filesystems can be remotely mounted via the Networked File System or NFS). Whichever way the information is located, ls writes that information out and the video driver displays it on the screen.

## Memory Management

1. What is?
   1. One of the basic tricks of any operating system is the ability to make a small amount of physical memory behave like rather more memory. This apparently large memory is known as virtual memory. The idea is that the software running in the system is fooled into believing that it is running in a lot of memory. The system divides the memory into easily handled pages and swaps these pages onto a hard disk as the system runs. The software does not notice because of another trick, multi-processing.

## Processes

1. What is?
   1. A program in action; each process is a separate entity that is running a particular program. If you look at the processes on your Linux system, you will see that there are rather a lot.
      1. Kernel runs each of all processes for a short period known as time-slice and it's known as multi-processing or scheduling and it fools each process into thinking that it is the only process.
      2. It is isolated from other processes crashing or malfunction achieved by kernel giving each process a separate address space with allowed access.

## Device Drivers

1. What is?
   1. A major part of the Linux kernel.
   2. Operates in highly privileged environment and is highly disastrous if it get things wrong. It controls OS/hardware interaction.
   3. Device drivers are specific to the controller chip that they are driving, so driver and controller version must match.

## The Filesystems

1. What is?
   1. A Linux/Unix filesystem follow a single filesystem tree structure and new filesystems are mounted onto a mount directory under the root.
   2. FS gives the user a sensible view of files and directories by abstracting the underlying filesystem types and characteristics
   3. The block device driver abstracts differences between physical block devices so it can be viewed as a linear collections of blocks of data.

# Kernel Data Structures

1. What is?
   1. It keeps track current state of the system using data structures.
      1. The kernel must create a data structure representing the new process and link it with the data structures representing all of the other processes in the system.
   2. Most of these data structures exist in physical memory and are accessible only by the kernel and its subsystems.
      1. Data structures help understand Linux Kernel.

## Linked Lists

1. What is?

   1. Linked lists are handy ways of tying data structures together.
   2. Single linked List
      1. For a process or network device, the kernel must be able to find all of the instances
   3. Doubly linked list
      1. Makes it easier to add or remove elements from the middle of list although you do need more memory. Memory vs CPU cycles

## Hash Tables

1. What is?
   1. An array or vector of pointers that is accessed by index which is an offset into the array.
   2. Speeds up access to commonly used data structures.
   3. Linux implements caches using hash tables for access data quickly. One drawback to cache is that they are more complex to use and maintain than simple linked lists or hash tables.
      1. If data can be found in the cache (known as cache hit), it's good. If not, then all relevant data structures must be searched and, if the data structure exists at all, it must be added into the cache.
      2. Linux decides whether or not to discard old data structure for a new one.

## Abstract Interface

1. What is?
   1. A collection of routines and data structures which operate in a particular way
      1. For example all network device drivers have to provide certain routines in which particular data structures are operated on.
      2. This way there can be generic layers of code using the services (interfaces) of lower layers of specific code.
         1. The network layer is generic and it is supported by device specific code that conforms to a standard interface.
      3. Often these lower layers register themselves with the upper layer at boot time. This registration usually involves adding a data structure to a linked list.
      4. Registration data structure often includes pointer to functions, addresses to perform particular tasks. These functions/routines can then be called by kernel.
