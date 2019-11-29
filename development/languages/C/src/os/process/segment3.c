// This program has two initialized global and static variable. 
// This means initialized DATA segment would increase by 4 Bytes
// It also has two initialized global and static variables.
// This means Uninitialized BSS segment would increase by 4 Bytes


#include<stdio.h>

int myglobalint1 = 500;
int myglobalint2;
int main() {
   static int mystaticint1;
   static int mystaticint2 = 100;
   printf("Hello World\n");
   return 0;
}