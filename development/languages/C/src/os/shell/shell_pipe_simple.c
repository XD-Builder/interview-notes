#include <unistd.h> // standard symbolic constants and types, and some functions syscalls. like close, dup2, execve
#include <stdio.h>  // Standard Input and Output Library, like fprintf
#include <fcntl.h>  // file control options, like O_WRONLY
int main(void)
{

    char *argv[] = {"/bin/ls", "-la", 0};
    char *envp[] =
        {
            "HOME=/",
            "PATH=/bin:/usr/bin",
            "USER=harold",
            0};
    int fd = open("/Users/harold/ls.log", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    dup2(fd, 1); // stdout is file descriptor 1
    close(fd);
    execve(argv[0], &argv[0], envp);
    fprintf(stderr, "Oops!\n");
    return -1;
}