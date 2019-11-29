// Multithreading is a specialized form of multitasking and a multitasking is the feature that allows your computer to run
// two or more programs concurrently. In general, there are two types of multitasking: process-based and thread-based.

// Process-based multitasking handles the concurrent execution of programs.
// Thread-based multitasking deals with the concurrent execution of pieces of the same program.

// A multithreaded program contains two or more parts that can run concurrently.
// Each part of such a program is called a thread, and each thread defines a separate path of execution.

// C++ does not contain any built-in support for multithreaded applications.
// Instead, it relies entirely upon the operating system to provide this feature.

// POSIX Threads, or Pthreads provides API which are available on many Unix-like POSIX systems such as FreeBSD, NetBSD, GNU/Linux, Mac OS X and Solaris.

// Creating Threads
// pthread_create (thread, attr, start_routine, arg)
//      thread - An opaque, unique identifier for the new thread returned by the subroutine.
//      attr - An opaque attribute object that may be used to set thread attributes. You can specify a thread attributes object, or NULL for the default values.
//      start_routine - The C++ routine that the thread will execute once it is created.
//      arg - A single argument that may be passed to start_routine. It must be passed by reference as a pointer cast of type void.
//              NULL may be used if no argument is to be passed.
// pthread_create creates a new thread and makes it executable.

// Terminating Threads
// pthread_exit (status)
// If main() finishes before the threads it has created, and exits with pthread_exit(), the other threads will continue to execute.
// Otherwise, they will be automatically terminated when main() finishes.

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;
    cout << "PrintHello(void *threadid) : Hello World! Thread ID, " << tid << endl;
    pthread_exit(NULL);
}

void runThreadsSimple()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
}

void *wait(void *t)
{
    int i = 2;
    long tid = (long)t;

    cout << "Sleeping in thread " << tid << endl;
    sleep(1);
    cout << "Thread with id: " << tid << "  ...exiting " << endl;
    
    // exit status can be set but must not be local pointer variable
    pthread_exit(t);
}

void runThreadComplex()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;

    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], &attr, wait, (void *)i);
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // free attribute and wait for the other threads
    pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i;
        cout << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
}

int main()
{
    cout << "Creating threads to run without join" << endl;
    runThreadsSimple();
    sleep(2);
    cout << endl << endl << "Creating threads to run with join" << endl;
    runThreadComplex();
    pthread_exit(NULL);
}