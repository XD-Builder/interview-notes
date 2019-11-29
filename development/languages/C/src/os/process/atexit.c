#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exitfunc()
{
    printf("Called cleanup function - exitfunc()\n");
    return;
}

int main()
{
    atexit(exitfunc);
    printf("Hello, World!\n");
    // does call clean up method, exit func
    //    exit (0);
    // does not call clean up method, exit func
    _exit(0);
}
