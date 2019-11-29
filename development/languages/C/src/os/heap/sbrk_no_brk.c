#include <unistd.h>
#include <stdio.h>

int main(void) {
    /* Get the first address beyond the end of the heap. */
    void *b = sbrk(0);
    int *p = (int *)b;
    /* May segfault because it is outside of the heap. */
    // but it may not hit a new page and thus no segfault.
    *p = 1;
    printf("p is set to %i", *p);
    return 0;
}