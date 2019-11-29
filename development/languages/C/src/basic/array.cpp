// C++ provides a data structure, the array, which stores a fixed-size sequential collection of elements of the same type.
// An array is used to store a collection of data, but it is often more useful to think of an array as a collection of variables of the same type.

// Instead of declaring individual variables, such as number0, number1, ..., and number99,
// you declare one array variable such as numbers and use numbers[0], numbers[1], and ..., numbers[99] to represent individual variables.
// A specific element in an array is accessed by an index.

// All arrays consist of contiguous memory locations. The lowest address corresponds to the first element and the highest address to the last element.

// Declaring array - type arrayName [ arraySize ];
// Initializing array - double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};

#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

int main()
{
    int n[10]; // n is an array of 10 integers

    // initialize elements of array n to 0
    for (int i = 0; i < 10; i++)
    {
        n[i] = i + 100; // set element at location i to i + 100
    }
    cout << "Element" << setw(13) << "Value" << endl;

    // output each array element's value
    for (int j = 0; j < 10; j++)
    {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    return 0;
}