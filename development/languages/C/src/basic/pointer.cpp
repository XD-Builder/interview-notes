#include <iostream>

using namespace std;
void printStackVariableAddress();
void usePointer();

int main()
{
    printStackVariableAddress();
    usePointer();
    return 0;
}

// Def Pointer
// A pointer is a variable whose value is the address of another variable.
// Like any variable or constant, you must declare a pointer before you can work with it.
// The general form of a pointer variable declaration is type *var-name;

// Using Pointers in C++
// (a) We define a pointer variable.
// (b) Assign the address of a variable to a pointer.
// (c) Finally access the value at the address available in the pointer variable.
// This is done by using unary operator * that returns the value of the variable located at the address specified by its operand.

void printStackVariableAddress()
{
    int var1;
    char var2[10];

    cout << "Address of var1 variable: ";
    cout << &var1 << endl;

    cout << "Address sof var2 variable: ";
    cout << &var2 << endl;
}

void usePointer()
{
    int var = 20; // actual variable declaration.
    int *ip;      // pointer variable

    ip = &var; // store address of var in pointer variable

    cout << "Value of var variable: ";
    cout << var << endl;

    cout << "address of var variable: ";
    cout << &var << endl;

    // print the address stored in ip pointer variable
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // access the value at the address available in pointer
    cout << "Value of *ip variable: ";
    cout << *ip << endl;
}