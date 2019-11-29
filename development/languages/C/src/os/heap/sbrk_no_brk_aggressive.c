#include <assert.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    void *b;
    char *p, *end;

    b = sbrk(0);
    p = (char *)b;
    end = p + 0x1000100;
    // uncomment if increase the limit increases to the end.
    // brk(end);
    while (p < end) {
        *(p++) = 1;
        printf("p is set to %i\n", *(p-1));
    }
    // return the break back to b.
    brk(b);
    return 0;
}