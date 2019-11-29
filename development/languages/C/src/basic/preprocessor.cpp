// The preprocessors are the directives, which give instructions to the compiler to preprocess the information before actual compilation starts.

// All preprocessor directives begin with #, and only white-space characters may appear before a preprocessor directive on a line.
// Preprocessor directives are not C++ statements, so they do not end in a semicolon (;).

// You already have seen a #include directive in all the examples. This macro is used to include a header file into the source file.

// There are number of preprocessor directives supported by C++ like #include, #define, #if, #else, #line, etc.

// The #define Preprocessor
// The #define preprocessor directive creates symbolic constants. The symbolic constant is called a macro and the general form of the directive is
// #define macro-name replacement-text

// The # and ## Operators
// #define MKSTR( x ) #x
// The # and ## preprocessor operators are available in C++ and ANSI/ISO C. 
// The # operator causes a replacement-text token to be converted to a string surrounded by quotes.

#include <iostream>
using namespace std;

#define DEBUG
#define PI 3.14159
#define MIN(a, b) (((a) < (b)) ? a : b)
#define MKSTR( x, y  ) #x#y
#define CONCAT( x, y )  x ## y

int main()
{   int xy = 100;
    #ifdef DEBUG
        cout << "Debug enabled. Debugging now..." << endl;
        cout << MKSTR(HELLO C++, YY) << endl;
        cout << CONCAT(x, y) << endl;

        // Predefined macro
        cout << "Value of __LINE__ : " << __LINE__ << endl;
        cout << "Value of __FILE__ : " << __FILE__ << endl;
        cout << "Value of __DATE__ : " << __DATE__ << endl;
        cout << "Value of __TIME__ : " << __TIME__ << endl;
    #endif
    #ifndef TEST
        #define TEST 0
    #endif

    cout << "Is TEST macro defined? " << (TEST == 0) << endl;
    if (TEST == 0){
        cout << "Yes TEST is defined" << endl;
    }
    // symbolic constant macro
    cout << "Value of PI :" << PI << endl;

    // function like macro
    int i = 100, j = 30;
    cout << "The minimum is " << MIN(i, j) << endl;

    return 0;
}