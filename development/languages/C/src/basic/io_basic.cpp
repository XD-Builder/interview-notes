// C++ I/O occurs in streams, which are sequences of bytes.
// If bytes flow from a device like a keyboard, a disk drive, or a network connection etc. to main memory, this is called input operation
// and if bytes flow from main memory to a device like a display screen, a printer, a disk drive, or a network connection, etc., this is called output operation.

// <iostream>
// This file defines the cin, cout, cerr and clog objects, which correspond to the standard input stream, the standard output stream, the un-buffered standard error stream and the buffered standard error stream, respectively.
// <iomanip>
// This file declares services useful for performing formatted I/O with so-called parameterized stream manipulators, such as setw and setprecision.
// <fstream>
// This file declares services for user-controlled file processing.

// Object cout is an instance of ostream class and is said to be "connected to" the standard output device.
// The << operator is overloaded to output data items of built-in types integer, float, double, strings and pointer values.

// Object cin is an instance of istream class and is said to be attached to the standard input device.
// The stream extraction operator >> may be used more than once in a single statement
// such as cin >> name >> age; which is equivalent to cin >> name; cin >> age;

// Object cerr is an instance of ostream class and is said to be attached to the standard error device
// object cerr is un-buffered and each stream insertion to cerr causes its output to appear immediately

// Object clog is an instance of ostream class and is said to be attached to the standard error device
// object clog is buffered

#include <iostream>

using namespace std;

int main()
{
   // cin, cout
   char name[50];
   cout << "Please enter your name: ";
   cin >> name;
   cout << "Your name is: " << name << endl;

   char str[] = "Hello C++";
   cout << "Value of str is : " << str << endl;

   // cerr, clog
   char str2[] = "Unable to read....";

   cerr << "Error message : " << str2 << endl;

   clog << "Error message : " << str2 << endl;
}
