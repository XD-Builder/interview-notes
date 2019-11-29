# Thread

## Overview
1. What is a Thread?
    1. An independent stream of instructions that can be scheduled to run as such by the OS.
2. UNIX processes and threads
    1. A process created by OS contains information about program resources and program execution state, including
        1. Process Id, Process Group ID, user ID and group ID
        2. Environment, working directory, program instructions, registers
        3. Stack, heap, file descriptors, signal actions, shared libraries, and inter process communication tools (such as message queues, pipes, semaphores, or shared memory)
    2. Threads exist within process resources and yet are able to be scheduled by the OS and run as independent entities largely because they duplicate only the bare essential resources that enable them to exist as executable code.
    3. The independent flow of control by a thread is accomplished by maintaining its own
        1. Stack pointer, registers (for next instruction), scheduling properties (policy or priority), set of pending and blocked signals, thread specific data.
    4. Property of unix thread
        1. Exists within a process and uses the process resources
        2. Has its own independent flow control as long as its parent process exists and the OS supports it.
        3. Duplicates only the essential resources it needs to be independently schedulable.
        4. May share the process resources with other threads.
        5. Dies if the parent process dies.
        6. Is "lightweight" because most of the overhead has already been accomplished through the creation of its process.
    5. Implication of shared resources by threads
        1. Changes made by one thread to shared system resources will be seen by all other threads such as closing a file.
        2. Two pointers having the same value point to the same data.
        3. Reading and writing to the same memory locations is possible, and therefore requires explicit synchronization by the programmer.
    6. Creation Time - Thread vs Process
        1. UNIX fork() system call creates a new process and pthread_create() creates a thread. On average, fork() takes 10 to 30 times longer to finish than pthread_create() depending on the CPU.
3. Modes of threaded programs
    1. Manager/worker
        1. A single thread, the manager assigns work to other threads, the workers. Typically, the manager handles all input and parcels out work to the other tasks. At least two forms of the manager/worker model are common: static worker pool and dynamic worker pool.
    2. Pipeline
        1. A task is broken into a series of sub-operations, each of which is handled in series, but concurrently, by a different thread.
    3. Peer
        1. Similar to manager/worker model, but after the main thread creates other threads, it participates in the work.
4. Shared Memory Model and Thread Safety
    1. Shared Memory Model
        1. All threads have access to the same global, shared memory
        2. They also have their own private data
        3. Programmers are responsible for synchronizing access (protecting) globally shared data.
    2. Thread-safety
        1. Application's ability to execute multiple threads simultaneously without "clobbering" shared data or creating "race" conditions.
        2. Ex. "clobbering" shared data || "race" conditions
            1. If your application creates several threads, each of which makes a call to the same library routine. If the library routine access/modifies a global structure or location in memory, as each thread calls this routine it is possible that they may try to modify this global structure/memory location at the same time. If the routine does not employ some sort of synchronization constructs to prevent data corruption, then it's not thread-safe.

## UNIX Pthreads API
1. The original Pthreads API was defined in the ANSI/IEEE POSIX 1003.1 - 1995 standard. The subroutines which comprise the API can be put into four major groups
    1. Thread management
        1. Routines that work directly on threads - creating, detaching, joining, etc. They include functions to set/query thread attributes (joinable, scheduling etc.)
    2. Mutexes
        1. Routines that deal with synchronization, called a "mutex", which is an abbreviation for "mutual exclusion". It provides functions for creating, destroying, locking and unlocking mutexes. 
    3. Condition Variables
        1. Routines that address communication between threads that share a mutex. Based upon programmer specified conditions, this include functions to create, destroy, wait and signal based upon specified variable values. Functions to set/query condition variable attributes are also included.
    4. Synchronization
        1. Routines that manage read/write locks and barriers
2. API overview
    1. Naming convention - all identifiers in the threads library begin with pthread_
        1. pthread_ => Threads themselves and miscelaneous subroutines
        2. pthread_attr_ => thread attributes objects
        3. pthread_mutex_ => Mutexes
        4. pthread_mutexattr_ => Mutexes attribute objects
        5. pthread_cond_ => Condition variables
        6. pthread_condattr_ => Condition attributes objects
        7. pthread_key_ => Thread-specific data keys
        8. pthread_rwlock_ => Read/write locks
        9. pthread_barrier_ => Synchronization barriers
3.  Terminating Threads & pthread_exit()
    1. Ways in which a thread may be terminated
        1. The thread returns normally from its starting routine. Its work is done.
        2. The thread makes a call to the pthread_exit subroutine - whether its work is done or not
        3. The thread is canceled by another thread via the pthread_cancel routine
        4. The entire process is terminated due to making a call to either the exec() or exit()
        5. The main() finishes first, without calling pthread_exit explicitly itself.
    2. pthread_exit() routine
        1. It allows the programmer to specify an optional termination status parameter. This optional parameter is typically returned to the threads "joining" the terminated thread.
        2. it does not close files; **any files opened inside the thread will remain open after the thread is terminated**
    3. Calling pthread_exit() from main()
        1. There is a definition problem if main() finishes before the threads it spawned if you don't call pthread_explicitly. All of the threads it created will terminate because main() is done and no longer exists to support the threads.
        2. By having main() explicitly call pthread_exit() as the last thing it does, **main() will block and be kept alive to support the threads it created until they are done**.
4. Thread Management
    1. Passing arguments to threads
        1. pthread_create() routine permits the programmer to pass one argument to the thread start routine.
        2. For cases where multiple arguments must be passed, this limitation is easily overcome by creating a structure which contains all of the arguments, and then passing a pointer to that structure in the pthread_create() routine.
        3. All arguments must be passed by reference and cast to (void *)
        4. What's not thread-safe?
            1. Passing an address of a parent local variable to threads created will share the same memory location for the variable and thus creating unsafe shared memory and race conditions.
    2. Joining and Detaching Threads
        1. Routines
            1. pthread_join (threadid, status)
            2. pthread_detach (threadid)
            3. pthread_attr_setdetachstate (attr, detachstate)
            4. pthread_attr_getdetachstate (attr, detachstate)
        2. Joining
            1. A way to accomplish synchronization between threads
                1. Master thread => pthread_create() => worker thread(s) => master thread: pthread_join() <=> worker thread: pthread_exit() => exit in main thread
            2. The pthread_join() subroutine blocks the calling thread until the specified threadid thread terminates
            3. The programmer is able to obtain the target thread's termination return status if it was specified in the target thread's call to pthread_exit()
            4. A joining thread can match one pthread_join() call. It is a logical error to attempt multiple joins on the same thread.
            5. Two other synchronization methods are mutexes and condition
        3. Joinable or Not?
            1. When a thread is created, one of its attributes defines whether it is joinable or detached. Only threads that are created as joinable can be joined. If a thread is created as detached, it can neer be joined.
            2. To explicitly create a thread as joinable or detached, the attr argument in the pthread_create() routine is used. It's a four step process
                1. Declare a pthread attribute variable of the pthread_attr_t data type
                2. Initialize the attribute variable with pthread_attr_init()
                3. Set the attribute detached status with pthread_attr_setdetachstate()
                4. When done, free library resources used by the attribute with pthread_attr_destroy()
        4. Detaching
            1. The pthread_detach() routine can be used to explicitly detach a thread even though it was created as joinable.
            2. However if a thread is created detached it can't be joinable
    3. Stack Management
        1. Routines
            1. pthread_attr_get(set)stacksize (attr, stacksize)
            2. pthread_attr_get(set)stackaddr (attr, stackadr)
        2. Preventing Stack Problems
            1. POSIX standard does not dictate the size of a thread's stack and thus it's implementation dependent.
            2. Exceeding the default stack limit is often every easy to do, with the **usual results: program termination and/or corrupted data**
            3. Safe and portable programs do not depend upon the default stack limit, but instead, explicitly allocate enough stack for each thread by using the pthread_attr_setstacksize routine
            4. The pthread_attr_getstackaddr and pthraed_attr_setstackaddr routines can be used by applications in an environment where the stack for thread must be placed in some particular region of memory.
    4. Miscellaneous Routines
        1. pthread_self()
            1. returns the unique, system assigned thread ID of the calling thread.
        2. pthread_equal(thread1, thread2)
            1. compares two thread ids. If two ids are different 0 is returned, otherwise a non-zero value is returned.
        3. pthread_once(once_control, init_routine)
            1. Executes the init_routine exactly once in a process. The first call to this routine by any thread in the process executes the given init_routine, without parameters. Any subsequent call will have no effect.
            2. Init_routine is typically an initialization routine
            3. The once_control parameter is a synchronization control structure that requires initialization prior to calling pthread_once
5. Mutex Variables
    1. Overview
        1. Mutex is an abbreviation for "mutual exclusion". It is one of the primary means of implementing thread synchronization and for protecting shared data when multiple writes occur.
        2. It acts like a "lock protecting access to a shared data resource. The basic concept of a mutex as used in Pthreads is that only one thread can lock (or own) a mutex variable at any given time. Thus, even if several threads try to lock a mutex only one thread will be successful. 
        3. Mutexes can be used to prevent "race" conditions.
        4. Very often the action performed by a thread owning a mutex is the updating of global variables. This is a safe way to ensure that when several threads update the same variable, the final value is the same as what it would be if only one thread performed the update. The variable being updated belong to a "critical section"
        5. A typical sequence in the use of a mutex
            1. Create/initialize a mutex variable
            2. Several threads attempt to lock the mutex
            3. Only one succeeds and that thread owns the mutex
            4. The owner thread performs some set of actions
            5. The owner unlocks the mutex
            6. Another thread acquires the mutex and repeats the process
            7. Finally the mutex is destroyed.
        6. When several threads compete for a mutex, the loser block at that call - an unblocking call is available with "trylock" instead of the "lock" call.
        7. When protecting shared data, it is the programmer's responsibility to make sure every thread that needs to use a mutex does so.
            1. Ex. if 4 threads updating the same data but only one uses a mutex, the data can still be corrupted.
    2. Creating/Destroying Mutexes
        1. Routines
            1. pthread_mutex_init (mutex, attr)
            2. pthread_mutex_destroy (mutex)
            3. pthread_mutexattr_init (attr)
            4. pthread_mutexattr_destroy (attr)
        2. Mutex variables must be declared with type pthread_mutex_t and must be initialized before they can be used.
        3. Ways to initialize a mutex variable - It is initially unlocked
            1. Statically, when it is declared
                1. Ex. pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
            2. Dynamically, with the pthread_mutex_init() routine. This permits setting mutex object attributes, attr.
        4. The attr object used to establish properties for the mutex object, must be of type pthread_mutexattr_t if used (NULL for default). The Pthreads standard defines three optional attributes
            1. protocol: The protocol used to prevent priority inversions for a mutex.
            2. Prioceiling: Specifies the priority ceiling of a mutex.
            3. Process-shared: Specifies the process sharing of a mutex.
        5. The pthread_mutexattr_init() and pthread_mutexattr_destroy() routines are used to create and destroy mutex attribute objects respectively.
        6. pthread_mutex_destroy() should be used to free a mutex object which is no longer needed.
    3. Locking and Unlocking Mutexes
        1. Routines
            1. pthread_mutex_lock (mutex)
            2. pthread_mutex_trylock (mutex)
            3. pthread_mutex_unlock (mutex)
        2. Usage
            1. pthread_mutex_lock() routine is used by a thread to acquire a lock on the specified mutex variable. If the mutex is already locked by another thread, this call will block the calling thread until the mutex is unlocked.
            2. pthread_mutex_trylock() will attempt to lock a mutex. However, if the mutex is already locked, the routine will return immediately with a "busy" error code. This routine may be useful in preventing deadlock conditions, as in a priority inversion situation.
            3. pthread_mutex_unlock() will unlock a mutex if called by the owning thread. Calling this routine is required after a thread has completed its use of protected data if other threads are to acquire the mutex for their work with the protected data. An error will be returned if the mutex was already unlocked or if the mutex is owned by another thread.
                1. Note there is nothing "magical" about mutexes. In fact they are akin to a "gentleman's agreement" between participating threads. It is up to the code writer to insure that the necessary threads all make the mutex lock and unlock calls correctly.
        3. 