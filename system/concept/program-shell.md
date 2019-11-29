# Shell

## Overview
1. What is shell?
   1. Your interface to OS as it acts as a command interpreter. It passes commands to the OS and then displays the results on your screen.
   2. Widespread use of shells include 
      1. Bourne shell (Original Unix shell written by Steve Bourne)
      2. C shell (By Berkley, Cali. It provides a C like language with which to write shell scripts)
      3. Korn shell (ksh), written by David Korn, is now provided as the standard shell on Unix systems.
      4. TC Shell (tcsh), features of the C shell together with EMACS style editing of the CLI.
      5. Bourne Again Shell (bash), written by the FSF under the GNU initiative utilmately intended to be a full implementation of the IEEE Posix Shell and Tools specification. Widely used within the academic community.
2. Know your shell
   1. Your login shell is usually established by the local System Administrator when your userid is created.
      1. echo $SHELL
   2. Default shell prompt
      1. $ -> sh, ksh, bash
      2. % -> csh, tcsh
   3. Features available for certain shells
      1. TC, Korn, Bash
         1. Programming language, shell variables, command alias, command history, filename completion, command line editing, job control
      2. sh
         1. Programming language, shell variables
3. Processes in a shell
   1. A login shell is a process, created for you upon logging in and existing until you logout.
   2. UNIX is a multi-tasking OS and therefore any user can have multiple processes running simultaneously.
   3. Every process in a UNIX system has a unique PID
   4. ps - displays information about processes
   5. kill - sends a signal to a process.
   6. "command &" - background job and won't block current shell
   7. jobs - shows all jobs
   8. fg %1 - moves background job to the foreground
   9. stop %1 - stops a job running in the background
   10. Ctrl-Z - suspends a process
4.  Redirection
    1. Changing the shell's normal method of handling stdout, stdin and stderr for processes.
       1. 2> => redirect stderr, >& => redirect stderr and stdout
       2. < => redirect stdin
       3. myprog > out 2> err => redirects stdout to out, stderr to err
       4. myprog > output 2>&  => redirects stdout to output then stderr to output
5. Pipes
   1. Used by the shell to connect the stdout of one command directly to the stdin of another command
   2. Pipe accomplish with one command what otherwise would take intermediate files and multiple commands
      1. who | sort  => the output of who is piped without a reference to a file. It's faster because operation is in memory
      2. who > temp ; sort temp => the output is sent to a file, and sort have to operate on a file. Slower because the operation is in file I/O.
6. Filters
   1. Commands that processes an input stream of data to produce an output stream of data.
      1. who | sort | lp => pipes output stream for printing.
      2. Programs in UNIX combine simple tools to perform complex tasks.
7. Logout Files
   1. Specify commands which the shell wil execute upon logout.
   2. They are kept in a file located in the top level of your home directory
      1. .bash_logout => for bash






## Features
1. Why shell?
   1. Most Unix system commands take input from your terminal and send the resulting output back to your terminal.
      1. A command normally reads its input from the standard input, which happens to be your terminal by default.
      2. A command normally writes its output to standard output, which is your terminal.
2. Output Redirection
   1. Output from a command intended for standard output can be easily diverted to a file instead, and this capability is called output redirection
   2. The notation `>` writes the output to a file.
   3. The notation `>>` appends the output in an existing file
      1. Ex. `who > users`
3. Input Redirection
   1. Just as the output of a command can be redirected to a file, so can the input of a command be redirected from a file.
   2. The notation `<` is used to redirect the input of a command
      1. Ex. `wc -l < users`
4. Here Document
   1. For directing input into an interactive shell script or program
   2. The notation `<<` is used to supply required input for the interactive program
      1. Ex. `wc -l << EOF\nfor good (and bad) restaurants\nin Cape Town.\nEOF`
5. Discard the output
   1. Sometimes you need to execute a command, but you don't want the output displayed on the screen, you can do so by redirecting it to the file /dev/null
      1. Ex. `command > /dev/null`
   2. To discard both output of a command and its error output, user standard redirection to direct STDERR to STDOUT
      1. Ex. `command /dev/null 2>&1`
         1. 2 represents STDERR and 1 represents STDOUT
   3. To display message on to STDERR by redirecting STDOUT into STDERR
      1. Ex. `echo message 1>&2`
6. Examples
   1. `pgm > file` => Output of pgm is redirected to file
   2. `pgm < file` => Program pgm reads its input from file
   3. `pgm >> file` => Output of pgm is appended to file
   4. `n > file` => Output from stream with descriptor n redirected to file
   5. `n >> file` => Output from stream with descriptor n appended to file
   6. `n >& m` => Merges output from stream n with stream m
   7. `n <& m` => Merges input from stream n with stream m
   8. `|` => takes output from one program, or process, and sends it to another
      1. 0 is STDIN, 1 is STDOUT, 2 STDERR


## How Linux Pipes work under the hood
1. Why Pipe?
   1. It is one of the core concepts of Linux & Unix based OS that allows you to chain together commands in a very elegant way, passing output from one program to the input of another to get a desired end result.
2. Pipes implementation overview - high level
   1. Linux has VFS module called pipefs, that gets mounted in kernel space during boot.
   2. pipefs is mounted alongside the root fs but not in it.
   3. pipefs cannot be directly examined by the user unlike most fs.
   4. The entry point to pipefs is the pipe(2) syscall
   5. The pipe(2) syscall is used by shells and other programs to implement piping, and just create a new file in pipefs, returning two file descriptors ( one for read and one for write)
   6. pipefs is stored using an in-memory fs.
3. Pipe I/O, buffering, and capacity
   1. A pipe has limited capacity. When it's full, a write(2) will block or fail if the O_NONBLOCK flag is set.
      1. The application should be designed to consume data as soon as it's available.
      2. Since Linux 2.6.35, the default pipe capacity is 2^16 or 65,536 bytes
   2. Conditions
      1. When a process attempts to read from an empty pipe, read(2) will block until data is available in the pipe.
         1. If all file descriptors pointing to the write end of the pipe have been closed, reading from the pipe will return EOF read(2) return will 0.
      2. When a process attempts to write a full pipe, write(2) will block until enough data has been read from the pipe to allow the write call to succeed.
         1. If all file descriptor pointing to the read end of the pipe have been closed, writing to the pipe will raise the SIGPIPE signal. If this is ignored, write(2) fails with the error EPIPE.
            1. These are important for understanding pipe perf. The speed of reading and writing should be similar to have a good perf or else, slowest read or write is the bottleneck.
      3. How Shells do piping?
         1. The parent process calls pipe once for each two processes that get piped together. In the case of bash command `ls -la | sort | less`, it would need to call pipe twice to create two pipes, one for piping ls to sort, and one to pipe sort to less.
            1. Bash forks itself once for each process (3 times). Each child will run one command. However, before the children run their commands, they will overwrite one of stdin or stdout or both if in the middle of a long pipe.
            2. command under the hood
               1. Base will create two pipes, one to pipe ls to sort, and one to pipe sort to less
               2. Bash will fork itself 3 times ( 1 parent process and 3 children, for each command)
               3. child 1 (ls) will set its stdout file descriptor to the write end of pipe A
               4. child 2 (sort) will set its stdin file descriptor the the read end of the pipe A
               5. child 2 (sort) will set its stdout file descriptor to the write end of pipe B
               6. child 3 (less) will set its stdin file descriptor to the read end of pipe B
               7. each child will run their commands
         2. Scheduling
            1. Kernel automatically schedules processes so they roughly run in parallel. If child 1 writes too much to pipe A before child 2 has read it, child 1 will block for a while until child 2 has had time to read from the pipe. This allows for high levels of efficiency as one process doesn't have to wait for the other to complete to start processing data. Another reason for blocking is that pipes have a limited size normally a single page of memory.
   3. Named vs Unamed Pipes
      1. Unamed pipes
         1. Temporary pipes and are discarded once your program finishes or all of their file descriptors are closed. They are most common type of pipe
      2. Named pipes
         1. Known as FIFOs get created as a named file on your hard disk and they allow multiple unrelated programs to open and use them. You can have multiple writers quite easily, with one reader.
         2. mkfifo command is used to make a named pipe. Other than how it's created, it works the same as unamed pipes.
         3. Once created, you can open them using open. You must open the read end using O_RDONLY or write end using O_WRONLY. Most OS implements unidirectional pipes, so you can't open them in both read/write mode
         4. FIFOs are often used as a unidirectional IPC technique, for a system with multiple processes.
         5. A multithreaded application may also use named or unamed pipes, as well as other IPC techniques such as shared memory segments.
         6. FIFOs are created as a single inode with the property i_pipe set as a reference to the actual pipe. While the name may exist on your fs, pipe don't cause I/O to the underlying device, as once the inode is read, FIFOs behave like unamed pipes and operate in-memory

## How bash redirection works under the hood
1. When a process wants to execute another process, it generally works like
   1. The main process (e.g. bash) forks itself using the fork glibc wrapper implemented using the clone(2) syscall, not the fork(2) syscall.
   2. The forked process sees that output redirection was entered on the command line and opens the specified file using the open(2) syscall.
   3. The forked process calls dup2 to copy the freshly opened file descriptor over stdin/stdout/stderr.
   4. The forked process closes the original file handler to avoid resource leaks
   5. The forked process proceeds as normal by calling the execve(2) syscall or something similar to replace the executable image with taht of the process to be run (e.g. ls)

## Understanding how Linux creates processes
1. Steps to create a process
   1. If a process wants to run another process, such as "ls" to list files and directories
   2. The process (bash) forks itself using fork or clone syscall
   3. Forked processes are basically exact copies of their parent process, and resume execution at the exact same fork instruction. You normally check if you're the forked process by checking the return code of the fork or clone syscall. It will return different values for the parent and the child process. The parent will then go on to do something like call wait(2) to wait for the child process to complete execution
   4. The child process inherits pipes, file descriptors, state, etc from the parent process, but a lot of that isn't needed now so the child may clean up by closing open file descriptors and sockets, etc.
   5. The child calls execve or another exec syscall to replace itself with the target process. A few things about the exec syscalls. They replace the current process with another process. The text, data and stack of the calling process are overwritten by the new process. However, most process attributes are preserved, such as the stdin,err,out file descriptors.
