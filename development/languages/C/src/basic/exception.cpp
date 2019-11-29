// An exception is a problem that arises during the execution of a program. A C++ exception is
// a response to an exceptional circumstance that arises while a program is running, such as an attempt to divide by zero.

// Exceptions provide a way to transfer control from one part of a program to another.
// C++ exception handling is built upon three keywords: try, catch, and throw.
// throw − A program throws an exception when a problem shows up. This is done using a throw keyword.
// catch − A program catches an exception with an exception handler at the place in a program where
//          you want to handle the problem. The catch keyword indicates the catching of an exception.
// try − A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks
// try {
//    // protected code
// } catch( ExceptionName e1 ) {
//    // catch block
// } catch( ExceptionName e2 ) {
//    // catch block
// } catch( ExceptionName eN ) {
//    // catch block
// }

// Throwing Exceptions
// double division(int a, int b) {
//    if( b == 0 ) {
//       throw "Division by zero condition!";
//    }
//    return (a/b);
// }

// If you want to specify that a catch block should handle any type of exception that is thrown in a try block,
// you must put an ellipsis, ..., between the parentheses enclosing the exception declaration as follows
// try {
//    // protected code
// } catch(...) {
//   // code to handle any exception
// }

// C++ Standard Exceptions
// C++ provides a list of standard exceptions defined in <exception> which we can use in our programs.

#include <iostream>
#include <exception>
using namespace std;

double division(int a, int b);
void catchDivisionByZeroStringException();
int catchCustomException();
int main()
{
    catchCustomException();
    catchDivisionByZeroStringException();
    return 0;
}

void catchDivisionByZeroStringException()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
}

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}
// inherit public exception class
struct MyException : public exception
{
    // Here, what() is a public method provided by exception class and it has been overridden
    // by all the child exception classes. This returns the cause of an exception.
    const char *what() const throw()
    {
        return "C++ Exception";
    }
};

int catchCustomException()
{
    try
    {
        throw MyException();
        return 0;
    }
    catch (MyException &e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (std::exception &e)
    {
        return 1;
        //Other errors
    }
}