# Abstract

- This document introduces how shell works and its attributes.

## How shell runs command

1. A parent shell runs a command process by calling "fork, exec, wait".
2. In a subshell, **a parent shell first fork itself a subshell then runs "fork, exec, wait" in that child process or subshell**.
   1. In the subshell, whatever changes made does not affect the parent shell
   2. (command-list) - executed in a subshell
      1. (cd /; ls -la;) // this will create a subshell and the cd command only affects the cwd of the subshell not the parent shell.
   3. { command-list } - executed in the current shell
      1. { cd /; ls -la; } // { is a built-in command and therefore the space before and after {, } are important.
      2. useful when there is a need to redirect the output of a group of commands into another command
3. &-terminated pipeline runs "in background"
   1. Shell doesn't wait for the pipeline
      1. It will give the control back to listen to user input
   2. Pipeline runs in a subshell
      1. Subshell will wait for commands of the pipeline
   3. The pipeline may not read the terminal
      1. Because otherwise it will interfere normal operations of the shell
   4. The pipeline may (not) write to the terminal
      1. Because writing to the shell will interfere normal operations of the shell
   5. Ex.
      1. foo & bar ; fizz ; buzz &
      2. First foo will be run in the background in a subshell
      3. then bar and fizz will be run in the foreground in shell
      4. then buzz will be run in a subshell
      5. ( cd /; ls -la;) &
      6. { cd /; ls -la; } &
      7. Both above commands have the similar result because they are all run in a subshell.

## Shell

1. Session
   1. When one creates a new terminal a new shell session is created. That session only contains one job that runs the shell process. If the shell runs a pipeline in a foreground, it will be run as a member of the existing job, same shell as the existing one.
   2. When a shell creates a subshell, that subshell runs a separate job.
2. Controlling Terminal
   1. A terminal the original process uses as the standard input and output. In any moment in time only one job in a session is running in the foreground and all other jobs are marked as running in the background.
      1. **Processes in the foreground job can read and write to the terminal**.
      2. **Processes in the background job can send signal SIGTTIN when they attempt to the read the controlling terminal**. **They are prevented from reading the terminal**.
      3. C-Z sends signal SIGSTP to processes of the foreground job; also sends signal SIGCONT (CONTINUE) to processes of a background job and moves that job to the foreground.
3. Commands
   1. Job controls
      1. jobs // list background jobs and their job numbers
      2. bg jobNumber // send SIGCONT to a background job and resumes suspended or stopped jobs.
      3. fg jobNumber // send SIGCONT to a background job and move it to the foreground.
   2. Script executions
      1. source file // executes the shell commands defined in the file in the current shell. The changes will have immediate effect on the current shell.
      2. /bin/bash foo.sh // executes shell command defined in foo.sh in a subshell without modify the parent shell, essentially a different program context instead of shell context.
   3. Shebang
      1. #!/bin/bash // defined inside the bash command files and with it you don't have to explicitly pass command and a file to execute shell commands. Instead of writing /bin/bash foo.sh, you can write ./foo.sh. Ensure the file has execute permission on the file.
         1. The command run this way will be run in a subshell.
