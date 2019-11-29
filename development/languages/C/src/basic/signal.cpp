// Signals are the interrupts delivered to a process by the operating system which can terminate a program prematurely.
// You can generate interrupts by pressing Ctrl+C on a UNIX, LINUX, Mac OS X or Windows system.

// There are signals which can not be caught by the program but there is a following list of signals which you can catch
// in your program and can take appropriate actions based on the signal. These signals are defined in C++ header file <csignal>.
// SIGABRT      Abnormal termination of the program, such as a call to abort
// SIGFPE       An erroneous arithmetic operation, such as a divide by zero or an operation resulting in overflow.
// SIGILL       Detection of an illegal instruction.
// SIGINT       Receipt of an interactive attention signal.
// SIGSEGV      An invalid access to storage.
// SIGTERM      A termination request sent to the program.

// The signal() Function
// C++ signal-handling library provides function signal to trap unexpected events
// void (*signal (int sig, void (*func)(int)))(int);
// It receives two arguments: first argument as an integer which represents signal number and second argument as a pointer to the signal-handling function
// Whatever signal you want to catch in your program, you must register that signal using signal function and associate it with a signal handler.

// The raise() Function
// You can generate signals by function raise(), which takes an integer signal number as an argument and has the following syntax
// int raise (signal sig);

#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program

    exit(signum);
}

int main()
{
    int i = 0;
    // register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);

    while (++i)
    {
        cout << "Going to sleep...." << endl;
        if (i == 10)
        {
            raise(SIGINT);
        }
        sleep(1);
    }

    return 0;
}