# Abstract

- This document lists what you need to know about shell and its process interactions

## Shell foreground process? - GENERAL

1. Background
   1. Most commands issued from an interactive shell run in foreground. It means you must wait for the executed command to stop before doing something else.
2. Attributes & Behaviors
   1. Foreground processes are initialized and controlled through a terminal session. In other words, there has to be a user connected to the system to start such processes; they haven't started automatically as part of the system functions/services.

## Shell background process? - GENERAL

1. Background
   1. For long/complex programs or scripts, the alternative is to run them in the background
2. Attributes & Behaviors
   1. A job running in background starts and returns you to the prompt where you can enter further commands while the background process continues. However, it can still write to the current terminal window.
   2. Background command is not detached from your tty. And if you end your terminal session, background jobs may be also killed
   3. You can either start a job in background or send it to background after it started.
   4. It is a process that is not connected to a terminal; they don't expect any user input
3. How run a process in background
   1. Run a command with & appended in the end
   2. Run a command in the foreground and type <ctrl-z> to move it to the background, then type "bg" command which will run the program to let it continue in the background.
      1. This will send a SIGSTOP signal to the process and it will be in the a stopped state
   3.

## Difference between foreground process and background process of a shell?

1. They are controlled by a controlling terminal but have different process groups - foreground vs background.
   1. foreground process can read/write to controlling terminal.
   2. background processes can't access terminal directly but can send signal SIGTTIN when they attempt to the read the controlling terminal.

## How shell interact with background process?

1. Through signals, IPC mechanism, process groups.

## What are the linux signals and when will they be invoked?

1. A IPC mechanism mediated by kernel and sent to processes. They are invoked by CPU, exceptions in processes, or processes sending signals to other processes.

## How shell save inactive process memory and when is memory saved to swap file.

1. Kernel manages system memory and when there are memory pressures, it will decide to save swap out physical pages to disk.

## How processes context switch

1. Multitasking by Kernel, Interrupt by Devices, Exception by CPU, or signals by processes.

## Signals security between processes

1. What processes can a signal be sent
   1. A process can't send signals to privileged processes or processes running as other users.

## Job Control

1. Def
   1. Control of jobs by a shell, especially interactively, where a "job" is a shell's representation for a process group.
   2. Basic job control features are the **suspending, resuming, or terminating of all processes in the job/process group**; more advanced features can be performed by sending signals to the job.
   3. **It is of particular interest in Unix due to its multiprocessing**, and should be distinguished from job control generally, which is frequently applied to sequential execution
2. Overview
   1. When using Unix OS via terminal, a user will initially only have a single process running, their login shell.
      1. Most tasks (directory listing, editing files, etc.) can easily be accomplished by letting the program take control of the terminal and returning control to the shell when the program exits - formally by attaching to standard input and standard output to the shell, which reads or writes from the terminal, and catching signals sent from the keyboard, like the interrupt signal resulting from pressing C-c.
   2. The **concept of a job maps the (shell) concept of a single shell command to the OS concept of the possibly many processes that the command entails**.
      1. Ex. grep title somefile.txt | sort | less
         1. This creates at least three processes for each command. Job control allows the shell to control these related processes as one entity, and when a user issues the appropriate key combination (usually C-z), the entire group of processes get suspended.
      2. Jobs are managed by the OS as a single process group, and the job is the shell's internal representation of such group.
         1. POSIX definition - a set of processes, comprising a shell pipeline, and any processes descended from it, that are all in the same process group.
         2. A job can be referred to by a handle called the job control ID or job ID, which is used by shell builtins to refer to the job.
            1. Job ID begins with the % character; %n identifies job n, while %% identifies the current job.
   3. Job control and job IDs are typically only used in interactive use, where they simply referring to process groups; in script, PGIDs are used instead, as they are more precise and robust, and indeed job control is disabled by default in bash scripts.
3. Implementation
   1. Background
      1. The shell keeps **a list of jobs in a job table**.
         1. A job corresponds to a process group, which consists of all members er of a pipeline and their descents.
            1. Ex. jobs
               1. the command will list the background jobs existing in the job table, along with their job number and job state (stopped or running).
         2. When a session ends when the user logs out which terminates the session leader process, the shell process sends SIGHUP to all jobs, **and waits for the process groups to end before terminating itself.**
      2. **To remove jobs from the job table**
         1. Ex. disown
            1. A command to remove jobs from job table, so that **when the session ends the child process groups are not sent SIGHUP, nor does the shell wait for them to terminate**. They thus **become orphan processes, and may be terminated by OS, though more often this is used so the processes are adopted by init** (the kernel sets their parent process to init) and continue executing as daemons.
         2. Command nohup and using a terminal multiplexer can also prevent jobs form being terminated
      3. **To stop a job running in the foreground**
         1. It can be stopped by typing the **suspend character (C-z) which sends the "terminal stop" signal (SIGSTP) to the process group**.
            1. By default, **SIGSTP** causes processes receiving it to stop. However, a process can register a signal handler for or ignore SIGSTP. A process **can be paused with the "stop" signal, which cannot be caught or ignored**.
      4. **To interrupt a job running in the foreground**
         1. A job running in the foreground can be interrupted by typing the interruption character C-c and this sends the "interrupt" signal (SIGINT) which defaults to terminating the process.
      5. **To resume a stopped job in the background or foreground**
         1. bg built-in, for which shell redirects I/O appropriately in the background jobs, and sends the **SIGCONT** signal to the process, which causes the OS to resume its execution.
         2. fg built-in, for which shell redirects I/O appropriately in the foreground job and attach to terminal, and sends the **SIGCONT** signal to the process, which caues the OS to resume its exceution.
         3. In Bash, a program can be started as a background by appending "&" to the command line; its output is directed to the terminal(potentially interleaved with other program's output), but it cannot read from the terminal input.
      6. **Background process interacting with controlling terminal**
         1. A **background process that attempts to read from or write to its controlling terminal** is sent a **SIGTTIN (for input) or SIGTTOU (for output) signal**. (background processes can ask for STDIN and STDOUT of the terminal via signals SIGTTIN, SIGTTOU)
            1. **These signals stop the process by default**, but they may also be handled in other ways. **Shell often override the default stop action of SIGTTOU so that background processes deliver their output to the controlling terminal by default**.

## Pipeline

1. What is?
   1. A mechanism for IPC using message passing. It is a set of processes chained together by their standard streams, so that the output text of each process(stdout) is passed directly as input to the next one.
      1. The first process is not completed before the second is started, but they are **executed concurrently**
      2. The data written by one process is **buffered by the OS until it is read by the next process, and this a uni-directional channel disappears when the processes are completed**.
         1. It **uses anonymous pipes**, which means data written by one process is buffered by the OS until it is read by the next process, and this is a uni-directional channel disappears when the processes are completed. Anonymous pipes differ from **named pipes**, where messages are passed to or from pipe that is **named by making it a file, and remains after the processes are completed**.
2. Pipelines in command line interfaces
   1. All widely used Unix shells have a special syntax construct for the creation of pipelines. In all usage one writes the commands in sequence, separated by the ASCII vertical bar character "|" which starts the processes and arranges for the necessary connections between their standard streams
   2. Error Stream
      1. The **standard error stream ("stderr")** of the processes in a pipeline **are not passed on through the pipe; instead, they are merged and directed to the console**.
   3. Pipemill
      1. In the most commonly used simple pipelines the shell connects a series of sub-processes via pipes, and executes external commands within each sub-process. Thus the shell itself is doing no direct processing of the data flowing through the pipeline.
      2. Pipemill or mill
         1. A construct used for shell to perform processing directly.
         2. command | while read var1 var2 ...; do; ...; done
3. Creating pipelines programmatically
   1. How
      1. Pipelines can be created under program control using system call `pipe()` which constructs a new anonymous pipe object and **results in two new, opened file descriptors in the process**: the read-only and write-only ends and the **pipe ends appear to be normal, anonymous file descriptors, except that they have no ability to seek**.
      2. To **avoid deadlock and exploit parallelism**, the Unix process with one or more new pipes will then generally, call fork() to create new processes. **Each process will then close the end(s) of the pipe that will not be using before producing or consuming any data**. Alternatively, a process might create a new thread and use the pipe to communicate between them.
   2. Named pipes
      1. Created using mkfifo() or mknod() and then presented as input or output file to programs as they are invoked. They **allow multi-path pipes to be created and are especially effective when combined with standard error redirection, or with tee**.
4. Implementation
   1. All processes of a pipeline are started at the same time, with their streams appropriated connected, and managed by the scheduler together with all other processes running on the machine.
      1. An important aspect of this, **setting Unix pipes apart from other pipe implementations, is the concept of buffer**: for example a sending program may produce 5000 bytes per second, and a receiving program only be able to accept 100 bytes per second, but no data is lost. Instead, the output of the sending program is held in the buffer. When the receiving program is ready to read data, the next program in the pipeline reads from the buffer. In Linux, the size of the buffer is 65,536 bytes (64KB).
   2. Network pipes
      1. Tools like netcat and socat can connect pipes to TCP/IP sockets.
