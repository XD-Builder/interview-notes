// A preprocessor command which tells compiler to include the comments of stdio.h file in the program.
// stdio.h contains functions such as scanf() and print()
#include <stdio.h>

// main execution of C
int main()
{
   // printf() is a library function to send formatted output to the screen defined in stdio.h
   printf("Hello, World!");
   int t = 20;
   printf("%d", (int *) t);
   // Exit status of the program 
//    int a = 0;
//    printf("%d\n", &a);
   return 0;
}
