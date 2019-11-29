// This program has an initialized static variable which means it will increase DATA segment by 4 bytes

#include<stdio.h>

int main() {
   static int mystaticint1;
   static int mystaticint2 = 100;
   printf("Hello World\n");
   return 0;
}