#include <stdio.h>
#include <assert.h>
#include <unistd.h>

int main(void) {
    void *b = sbrk(0);
    int *p = (int *)b;

    /* Move it 2 ints forward */
    brk(p + 2);

    /* Use the ints. */
    *p = 1;
    *(p + 1) = 2;
    assert(*p == 1);
    assert(*(p + 1) == 2);
    printf("p is set to %i\n", *p);
    printf("p1 is set to %i", *(p+1));

    /* Deallocate back. */
    brk(b);

    return 0;
}
