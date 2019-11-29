# Abstract

- This document explores the definition of process, process interactions through IPC, process states and communications.

## Process Information

1. Definitions
   1. What is a process?
      1. A program in execution.
   2. What is a program?
      1. A file containing the information of a process and how to build it during run time.
      2. When you start execution of the program, it is loaded into RAM and starts executing.
   3. How a process is identified in a system?
      1. It's identified by a unique positive integer called as process ID or PID. Kernel limits the PID to 32767(configurable), 2^15. When the PID reaches this limit, it's reset

## Process Image

1. Definition
   1. What is a process image?
      1. An executable file required while executing the program. It usually contains a code/text segment, data segment, stack segment and heap segment.
   2. Memory View
      1. Address View Higher Address <===============> Lower Address
      2. Segments View STACK <=> | <=> HEAP <=> BSS <=> DATA <=> TEXT
2. Process Image Composition
   1. Code/text segment (fixed size, program code)
      1. A portion of object file or program's virtual address space that consists of executable instructions. It's usually read-only data segment and has fixed size
      2. Data segment is of two types, initialized, and un-initialized.
      3. Initialized - DATA segment (fixed size, initialized global and static variables)
         1. A portion of the object file or program's virtual address space that consists of initialized static and global variables.
         2. Variables are read/write-able and and could be changed at runtime
      4. Un-initialized - BSS segment (fixed size, uninitialized global & static variables)
         1. A portion of the object file or program's virtual address space that consists of uninitialized static and global variables. It's also called BSS (Block Started by Symbol) segment.
   2. Stack Segment (variable size, variable frames consisting of parameters, return address & local variables)
      1. An area of memory allotted for automatic variables and function parameters. It also stores a return address while executing function calls.
      2. It uses LIFO mechanism for storing local or automatic variables, function parameters and storing next address or return address. The return address refers to the address to return after completion of function execution.
      3. This segment size is variable as per local variables, function parameters, and function calls and grows from a higher address to a lower address.
   3. Heap segment (variable size, dynamic variables, managed by malloc(), free(), etc.)
      1. An area of memory allotted for dynamic memory storage such as for malloc() and calloc() calls. This segment size is also vairable as per user allocation and grows from a lower address to a higher address.

## Process Creation & Termination

1. Definition
   1. When a program (a file) is being executed, then a process is created and would be terminated after the completion of the execution.
      1. What if we need to create a process within the program and may be wanted to schedule a different task for it.
2. Process creation is achieved through the **fork() system call**.
   1. The newly created process is called the child process and the process that initiated it is called the parent process.
   2. After the fork() system call, now we have two processes, parent and child processes. Differentiating which is parent and which is child is through their return values.
   3. fork() syscall returns either of the three values
      1. Negative value indicate an error, i.e., unsuccessful in creating the child process.
      2. Returns a zero for child process.
      3. Return a positive value for the parent process. This value is the PID of the newly created child process.
3. Process termination can in either of the two ways
   1. Abnormally, occurs on delivery of certain signals, say terminate signal.
   2. Normally, using \_exit() system call or exit() library function
      1. \_exit() is different from exit() in that exit() does some cleanup before returning the control back to the kernel, while the \_exit() would return the control back to the kernel immediately.
      2.

## IPC Mechanisms

1. Communication Types
   1. Between related processes initiating from only one process, such as parent and child process
   2. Between unrelated processes, or two or more different processes.

## Signal & Trap

1. What is Signals
   1. Signals are software interrupts sent to a program to indicate that an important event has occurred.
   2. It can vary from user requests to illegal memory access errors.
   3. Signals such as interrupt, indicate that a user has asked a program to do something that is not in the usual flow of control.
   4. Signals
      1. 1, SIGHUP, hang up detected on controlling terminal or death of controlling process
      2. 2, SIGINT, issued if the user sends an interrupt signal (Ctrl + C)
      3. 3, SIGQUIT, issued if the user sends a quit signal (Ctrl + D)
      4. 9, SIGKILL, If a proces gets this, it must quit immediately and will not perform any clean up ops
      5. 14, SIGALRM, Alarm clock signal for timers
      6. 15, SIGTERM, software termination signal (sent by kill, its default)
2. Default actions to signals
   1. Every signal has a default action associated with it.
   2. Some of the possible default actions are
      1. Terminate the process
      2. Ignore the signal
      3. Dump core. It creates a file called core containing the memory image of the process when it received the signal
      4. Stop the process
      5. Continue a stopped process
3. Signal Trapping
   1. Why Trapping Signals
      1. When you send a SIGINT signal to a program, that program is immediately terminated and you end up leaving a bunch of temp files uncleaned.
      2. Trapping signal command allows you to perform cleanup tasks when a signal is received.
   2. Ex.
      1. Clean up Temp Files after program exit
         1. trap "rm -f $WORKDIR/work1$\$$WORKDIR/dataout\$\$; exit" 2
         2. trap "rm $WORKDIR/work1$\$$WORKDIR/dataout\$\$; exit" 1 2
      2. Ignore Signals
         1. trap '' 1 2 3 15
      3. Reset Traps
         1. trap 1 2 3 15

## Zombie and Orphan Process

1. Zombie Process
   1. Normally when a child process is killed, the parent process is updated via **SIGCHLD** signal. Then parent can do some other task or restart a new child as needed.
   2. The **ps** listing may still show the process with a **Z** state. This is a zombie or defunct process. The process is dead and not being used. These processes are different from the orphan process. They have completed execution but still find an entry in the process table.
2. Orphaned processes
   1. Sometimes the parent process is killed before its child is killed. In this case, the "parent of all processes", the init process, becomes the new PPID.
3. Daemon Processes
   1. System-related background processes that often run with the permissions of root and services request from other processes.
   2. No controlling terminal and cannot open /dev/tty. All daemons will have ? for tty field.
   3. It's a process that runs in the background, usually waiting for something to happen that it is capable of working with.
   4. Necessary if you have a program that calls for lengthy processing.

## Zombie and Orphan Process #2

1. Parent Process and Child Process
   1. Parent Process
      1. Every process except process 0 is created when process executes the fork() syscall and **the process that invoked fork is the parent process** and the newly-created process is the child process.
      2. Every process except process 0 has one parent process but can have many child processes.
      3. The OS kernel identifies each process by its pid. PID 0 is a special process that is created when the system boots. After forking a child process, PID 1, process 0 becomes the swapper process (sometimes known as the "idle task"). **PID 1, known as init, is the ancestor of every other process in the system**.
   2. Child Process
      1. A child process is a process created by another process (the parent process). It inherits most of its attributes such as open files, from its parent. The child process can overlay itself with a different program using "exec" as required.
         1. In UNIX, a child process is in fact created using fork as a copy of the parent
      2. Each process may create many child processes but will have at most one parent process; if a process does not have a parent this usually indicates that it was created directly by the kernel.
      3. Other parentless processes may be launched to carry out various daemon tasks in userspace. Another way for a process to end up without a parent is if its parent dies, leaving an orphan process; but in this case it will shortly be adopted by init (PID 1).
   3. Orphan Process
      1. A computer process whose parent process has finished or terminated though it remains running itself.
      2. In a Unix-like OS any orphaned process will be immediately adopted by the special init system process. This operation is call **re-parenting and occurs automatically**. Even though technically the process has the init process as its parent, it is still called an orphan process since the process that originally created it no longer exists.
      3. Unintentionally orphaned process
         1. Happens when the parent process terminates or crashes. The **process group mechanism in most Unix-like OS can be used to help protect against accidental orphaning, where in coordination with the user's shell will try to terminate all the child processes with the SIGHUP process signal**, rather than letting them continue to run as orphans.
      4. Intentionally orphaned process
         1. Happens so that it can be detached from the user's session and left running in the background; allows a long-running job to complete without further user attention, or to start an indefinitely running service. Under Unix, the later kinds of processes are typically called a daemon processes. The Unix **nohup** command allows to run a command as a daemon using similar mechanisms.
      5. How to find orphaned process
         1. ps -elf | awk '{if ($3 == 1){print $4" "$3" "$15}}'
            1. The command gets a list of process with PPID of 1 and returns the current PID, PPID and command.
   4. Daemon Process
      1. Definition
         1. Daemon process is a process orphaned intentionally.
         2. **A daemon is a computer program that runs as a background process**, rather than being under the direct control of an interactive user. Typically **daemon names end with the letter d**, for example, syslogd is the daemon that implements the system logging facility and sshd is a daemon that services incoming SSH connections.
      2. In a Unix environment, the parent process of a daemon is often, but not always, the init process. **A daemon is usually created by a process forking a child process and then immediately exiting, thus causing init to adopt the child process**. In addition, a daemon or the OS typically perform other operations, such as dissociating the process from any controlling terminal (tty). Such procedures are often implemented in various convenience routines such as daemon(3) (a library call) in Unix.
   5. Zombie Process
      1. Definition
         1. A zombie process or defunct process is a process that has completed execution but still has an entry in the process table. This entry is still needed to allow the parent process to read its child's exit status.
         2. The child has "died" but has not yet been "reaped" and kill command has no effect on a zombie process.
      2. What happens your child process dies without its status being read
         1. When a process ends, all of the memory and resources associated with it are deallocated so they can be used by other processes. However, the process's entry in the process table remains. The parent can read the child's exit status by executing the wait system call, where upon the zombie is removed. **The wait call may be executed in sequential code, but it commonly executed in a handler for the SIGCHLD signal, which the parent receives whenever a child has a died**.
         2. After the zombie is removed, its PID and entry in the process table can then be reused. However, **if a parent fails to call wait, the zombie will be left in the process table**. In some situations this may be desirable, for example if the parent creates another child process it ensures that it will not be allocated the same PID.
         3. On modern UNIX-like systems, the following special case applies: if the parent explicitly ignores SIGCHLD by setting its handler to SIG_IGN (rather than simply ignoring the signal by default) or has the SA_NOCLDWAIT flag set, all child exit status information will be discard and no zombie processes will be left.
         4. A zombie process is not the same as an orphan process
            1. An orphan proces is a process that is still executing, but whose parent has died. **They do not become zombie process but instead are adopted by init, which waits on its children**.
      3. to kill a zombie process is to kill its parents or to send a signal to that parent so its zombie child process will be killed, run following commands
         1. ps -p zombie_pid -o ppid
         2. kill -17 ppid
            1. which will send signal SIGCHLD(17) to the parent process which will kill the zombie child.
         3. kill -HUP $(ps -A -ostat,ppid | grep -e '[zZ]'| awk '{ print $2 }')
            1. kills in one command

## Commands

1. Show process with a controlling terminal for current user
   1. `ps`
2. Show process without a controlling terminal for current user
   1. `ps -x`
3. Show all process on a system
   1. `ps -e`
4. Show full-format listing
   1. `ps -f`
5. Commonly used syntax to achieve seeing every process on the system using BSD syntax
   1. `ps aux`
      1. It provides additional fields such as %CPU, %MEM, VSZ, RSS, TT, STAT, STARTED
6. List all processes for a user
   1. `ps -u <username>`
7. List all processes for a group
   1. `ps -g <group-id-or-name>`
8. List all processes by process number
   1. `ps -p <pid> <pid>...`
9. List all processes by executable name
   1. `ps -C <executable-name>`
10. List process hierarchy tree
    1. `ps -eH`
    2. `ps -e --forest` => Show hierarchy in ASCII format
11. Search processes id
    1. `pgrep <name-of-command>` - by cmd name
    2. `pgrep -u <user-name>` - by user name
    3. `pgrep -G <groupid-name>` - by group name
12. Kill a process
    1. `kill $(ps -e | grep <name-of-command> | awk '{print $1}')` - kill by subshell and param substitution
    2. `pkill sleep` - kill by search command name

## Process state codes

1. Background
   1. commands like ps can give state code of a process in abbreviation. It's cryptic therefore, the following table provides reference
2. process state table
   1. D => uninterruptible sleep (usually IO)
   2. R => running or runnable (on run queue)
   3. S => interruptible sleep (waiting for an event to complete)
   4. T => stopped by job control signal
   5. t => stopped by debugger during the tracing
   6. W => paging (not valid since the 2.6.xx kernel)
   7. X => dead (should never be seen)
   8. Z => defunct ("zombie") process, terminated but not reaped by its parent.
3. BSD formats when the stat keyword is used
   1. < => high priority (not nice to other users)
   2. N => low priority
   3. L => has pages locked into memory (for real-time custom IO)
   4. s => session leader
      1. a process where session id == process id.
   5. I => is multi-thread (using CLONE_THREAD, like NPTL pthreads do)
   6. \+ => is in the foreground process group

## Fields

1. Fields
   1. %cpu - percentage CPU usage
   2. %mem - percentage memory usage
   3. VSZ - virtual size in Kbytes
   4. RSS - resident set size
   5. PID - process id
   6. PPID - parent process id
   7. TTY - full name of control terminal
   8. CMD - name of the command that launched the process
   9. C/CPU - short-term cpu usage factor
   10. STIME - process Start time
   11. TIME - accumulated CPU time, user + system (alias cputime)

## Terminology

1. Pipes
   1. Communication between two related processes. Half duplex means the first process communicates with the second process. Full duplex means second process communicates with the first using another pipe.
2. FIFO
   1. Communication between two unrelated processes. It's a full duplex meaning the first process can communicate with the second process and vice versa at the same time.
3. Message Queues
   1. Communication between two or more processes with full duplex capacity. Communication is done by posting and retrieving message out of the queue. Once retrieved message is gone.
4. Shared Memory
   1. Communication between two or more processes is achieved through a shared piece of memory among all processes. The shared memory needs to be protected from each other by synchronizing access to all the processes.
5. Semaphores
   1. For synchronizing access to multiple processes. When one process wants to access the memory (for r/w), it needs to be locked and unlocked when the access is removed. This needs to be repeated by all the processes to secure data.
6. Signals
   1. For communication between multiple processes by way of signaling. This means a source process will send a signal (identified by a number) and the destination process will handle it accordingly
