#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   // forks to main process => subprocess1
   fork();
   // forks main process => subprocess2, subprocess1 => subprocess3
   fork();
   // main and subprocess1-3, executes below.
   printf("Called fork() system call\n");
   return 0;
}