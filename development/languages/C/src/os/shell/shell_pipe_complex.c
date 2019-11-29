#include <unistd.h> // sys calls
#include <stdio.h>
#include <errno.h> // errors
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[])
{
    // declare process id for commands and pipe fd
    int pid, pid_ls, pid_grep;
    int pipefd[2];

    // Syntax: test . filename
    if (argc < 3)
    {
        // write to err if number of arguments is less than 3
        fprintf(stderr, "Please specify the directory to search and the filename to search for\n");
        return -1;
    }
    fprintf(stdout, "parent: Grepping %s for %s\n", argv[1], argv[2]);

    // Create an unnamed pipe and populate pipefd, 0 if success, -1 if failure
    if (pipe(pipefd) == -1)
    {
        fprintf(stderr, "parent: Failed to create pipe\n");
        return -1;
    }

    // Fork a process to run grep, if return value -1, no child process is called, 0 is the child, child pid is the parent
    pid_grep = fork();
    if (pid_grep == -1)
    {
        fprintf(stderr, "parent: Could not fork process to run grep\n");
        return -1;
    }
    // this process will be on the read end of the pipe. The last command in the pipeline
    else if (pid_grep == 0)
    {
        fprintf(stdout, "child: grep child will now run\n");
        // Set fd[0] (stdin) to the read end of the pipe from the parent pipe(pipefd) syscall
        // The current process stdin is set to pipefd read end, no other settings needed.
        if (dup2(pipefd[READ_END], STDIN_FILENO) == -1)
        {
            fprintf(stderr, "child: grep dup2 failed\n");
            return -1;
        }

        // Close the pipe now that we've duplicated it, the actual pipe is not closed unless zero references.
        close(pipefd[READ_END]);
        close(pipefd[WRITE_END]);

        // Setup the arguments/environment to call
        char *new_argv[] = {"/usr/bin/grep", argv[2], 0};
        char *envp[] = {"HOME=/", "PATH=/bin:/usr/bin", 0};

        // Call execve(2) which will replace the executable image of this
        // process, it will never return on success, only failures.
        execve(new_argv[0], &new_argv[0], envp);

        // Execution will never continue in this process unless execve returns
        // because of an error
        fprintf(stderr, "child: Oops, grep failed!\n");
        return -1;
    }

    // Fork a process to run ls
    pid_ls = fork();

    if (pid_ls == -1)
    {
        fprintf(stderr, "parent: Could not fork process to run ls\n");
        return -1;
    }
    // this process is the second last command in the pipeline
    else if (pid_ls == 0)
    {
        fprintf(stdout, "child: ls child will now run\n");
        fprintf(stdout, "---------------------\n");

        // Set fd[1] (stdout) to the write end of the pipe
        if (dup2(pipefd[WRITE_END], STDOUT_FILENO) == -1)
        {
            fprintf(stderr, "ls dup2 failed\n");
            return -1;
        }

        // Close the pipe now that we've duplicated it
        close(pipefd[READ_END]);
        close(pipefd[WRITE_END]);

        // Setup the arguments/environment to call
        char *new_argv[] = {"/bin/ls", "-laF", argv[1], 0};
        char *envp[] = {"HOME=/", "PATH=/bin:/usr/bin", 0};

        // Call execve(2) which will replace the executable image of this
        // process
        execve(new_argv[0], &new_argv[0], envp);

        // Execution will never continue in this process unless execve returns
        // because of an error
        fprintf(stderr, "child: Oops, ls failed!\n");
        return -1;
    }

    // Parent doesn't need the pipes
    close(pipefd[READ_END]);
    close(pipefd[WRITE_END]);

    fprintf(stdout, "parent: Parent will now wait for children to finish execution\n");

    // Wait for all children to finish
    while (wait(NULL) > 0)
        ;

    fprintf(stdout, "---------------------\n");
    fprintf(stdout, "parent: Children has finished execution, parent is done\n");

    return 0;
}