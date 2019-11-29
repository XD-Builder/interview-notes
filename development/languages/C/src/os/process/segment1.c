// In this program, an uninitialized static variable is added. 
// This means uninitialized segment (BSS) size would increase by 4 Bytes. 
// In Linux OS, the size of int is 4 bytes but it's dependent on the compiler and OS support

#include<stdio.h>

int main() {
   static int mystaticint1;
   printf("Hello World\n");
   return 0;
}