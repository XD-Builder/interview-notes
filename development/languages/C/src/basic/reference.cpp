// A reference variable is an alias, that is, another name for an already existing variable.
// Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.

// References vs Pointers
// Three major differences
// You cannot have NULL references. You must always be able to assume that a reference is connected to a legitimate piece of storage.
// Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time.
// A reference must be initialized when it is created. Pointers can be initialized at any time.

// Creating References in C++
// Think of a variable name as a label attached to the variable's location in memory. 
// You can then think of a reference as a second label attached to that memory location.
// Therefore, you can access the contents of the variable through either the original variable name or the reference.
// int i = 17; int& r = i; // "r is an integer reference initialized to i"

#include <iostream>
 
using namespace std;
 
int main () {
   // declare simple variables
   int    i;
   double d;
 
   // declare reference variables
   int&    r = i;
   double& s = d;
   
   i = 5;

   cout << "Address of i : " << &i << endl;
   cout << "Address of i reference : " << &r  << endl;

   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;

   r = 10;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
 
   d = 11.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;


   s = 20.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
   
   return 0;
}