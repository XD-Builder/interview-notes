// A good understanding of how dynamic memory really works in C++ is essential to becoming a good C++ programmer.
// Memory in your C++ program is divided into two parts
// The stack − All variables declared inside the function will take up memory from the stack.
// The heap − This is unused memory of the program and can be used to allocate the memory dynamically when program runs.

// You can allocate memory at run time within the heap for the variable of a given type using a special operator in C++
// which returns the address of the space allocated. This operator is called new operator.

// If you are not in need of dynamically allocated memory anymore, you can use delete operator, which de-allocates
// memory that was previously allocated by new operator.

// new and delete Operators

// new data-type;
// Here, data-type could be any built-in data type including an array or any user defined data types include class or structure
// The memory may not have been allocated successfully, if the free store had been used up. So it is good practice to check
// if new operator is returning NULL pointer

// double* pvalue  = NULL;
// if( !(pvalue  = new double )) {
//     cout << "Error: out of memory." <<endl;
//     exit(1);
// }
// The malloc() function from C, still exists in C++, but it is recommended to avoid using malloc() function.
// The main advantage of new over malloc() is that new doesn't just allocate memory, it constructs objects which is prime purpose of C++.

// At any point, when you feel a variable that has been dynamically allocated is not anymore required,
// you can free up the memory that it occupies in the free store with the ‘delete’ operator as follows
// delete pvalue;        // Release memory pointed to by pvalue
#include <iostream>
using namespace std;

class Box
{
public:
    Box()
    {
        cout << "Constructor called!" << endl;
    }
    ~Box()
    {
        cout << "Destructor called!" << endl;
    }
};
int main()
{
    // New with arrays and objects
    Box *myBoxArray = NULL;

    if (!(myBoxArray = new Box[2]))
    {
        cout << "Error: out of memory." << endl;
        exit(1);
    }

    delete[] myBoxArray; // Delete array

    // New with built-in types
    double *pvalue = NULL; // Pointer initialized with null
    pvalue = new double;   // Request memory for the variable

    *pvalue = 29494.99; // Store value at allocated address
    cout << "Value of pvalue : " << *pvalue << endl;

    delete pvalue; // free up the memory.

    return 0;
}