## Unix System Calls

1. Systems
   1. System History
      1. Widely used systems include Linux, Mac OS X, FreeBSD, OpenBSD
      2. Linux & BSD are free software whereas Mac OS X is proprietary.
      3. Android system is created by Google and iOS system is created by Apple
   2. System Standards
      1. POSIX (Portable Operating System Interface for Unix)
      2. SUS (Single Unix Specification)
         1. Two standards created between late 1980s and early 1990s. Their goal is to solve system compatibility.
   3. What defines a operating system?
      1. Defined by what system calls it makes available.
      2. System calls are functions in the operating system code which programs can invoke using a special instruction. These functions are the primary means by which the operating system exposes functionality to programs so they can interact with hardware - network, disk, memory, storage, etc.
         1. Each process is run effectively confined to its own box, or its own part of memory. The instruction to system call breaks out of that box. That instruction should specify the number of system call to invoke and that cause CPU to look up an address which corresponds to that number in "special table".
      3. Most of the syscalls are placed inside the address space of each process just above stack memory space. These syscall memory pages are marked unaccessible to the process only **when the process invokes a syscall via special instruction does the execution jump up to the kernel code** and that syscall creates a new stack frame on the current process stack to avoid context switches (swapping in/out memory tables of the current process) and keep current process context during execution.
         1. This allows syscalls to be naturally interrupted, suspended and then resumed later. If the syscall is to run outside the context of a process that would make a trigger for the OS to suspend a process while it's invoking a syscall.
   4. Process
      1. A process can be running (currently executing), waiting (**waiting for the scheduler to put it into the running state**), or blocked (**won't be scheduled until it's unblocked to be put back to waiting state**).
         1. A process can be **blocked when calling certain syscalls**. Ex. reading from a file. The reading of a file takes a longer time relatively speaking to CPU, therefore CPU can do nothing to proceed until the read completes. Therefore, it's good to have **a process be blocked so it don't consume CPU cycles**. OS will unblock the process once the data is ready in memory.
      2. Therefore, the flow can be
         1. running => waiting
         2. running => blocked => waiting => running
   5. Syscall categories
      1. Processes => these are for managing processes, starting terminating processes, reading status of processes, etc.
      2. Files => read/write/delete files, changing permissions
      3. Networking sockets => for network communication between systems
      4. Signals => A notification of some event sent from OS from one process to another process. Ex. memory violation exception, like hardware exception raised to be received by the OS and then delivered to that process by the OS. When the process receives the signal from the OS, it gets interrupted and executes a signal handler for that signal.
      5. Inter-process communication => Some kind of mechanism for processes to communicate with each other. It also includes networking sockets. In the same system, there are more efficient IPC mechanisms
      6. Terminal
      7. Threads => Each process has by default one thread of execution (one code pointer to what current instruction is) and one stack keeps track of the functions invoked. Multiple threads mean multiple threads of execution, each with its own code pointer and stack. Threads in a process are scheduled independently but share the same address space so that data on the heap can be read and written by any thread in the process.
      8. I/O devices => Everything from the sys clock to the video adapter to storage devices. Read/write data to those devices in the form of files. UNIX treats I/O devices as files.
   6. How to invoke a syscall
      1. A syscall is invoked in a special instruction, and that instruction is encoded in assembly. C code invokes assembly code defined in standard libraries which defines syscall. Invoking a syscall in Python will invoke a compiled C code which calls the syscall.
      2. The C language has no exception mechanism so we have to deal with errors basically when we invoke a function we have to check the return value for error condition.
      3. There are many things can go wrong during a syscall. Ex. when you open file to read/write a file and that file does not exist, then the syscall has to return some error code so you can check that.
   7. Process details
      1. A process contains **address space, user ids, file descriptors, environment and current and root directory**
      2. Kernel code => unaccessible part of memory of the process mapped by the OS. Only accessible when called by a special syscall instruction.
      3. process memories
         1. Stack => variable size, increased as new function calls are stacked.
         2. heap => variable size, data allocated at run time
         3. If accessing a heap memory not allocated by the OS a invalid memory access error signal will be sent to the process.
         4. uninitialized data => fixed size, program's compiled variable with uninitialized data.
         5. initialized data => fixed size, program's compiled data with value defined in the executable
         6. code => fixed size, aka "text" points to application instructions.
      4. Address space operation syscalls
         1. mmap => memory map pages to the process address space
            1. Allocates a specified amount of memory and the OS has to find an address to allocate a memory chunk and return the address of the first element of that memory chunk.
            2. This memory chunk returned can be used to read/write data to store in memory
         2. munmap => memory unmap pages from the process address space
            1. When memory chunk is no longer needed, this syscall will deallocate the memory so it can be used by other processes.
         3. Efficient memory allocation
            1. In C/C++, memory management can be done at program level instead of OS level by allocating a large chunk of memory in the very beginning so that frequent syscall to allocate memory can be avoided and thus increase performance.
         4. Garbage collection
            1. Done in interpreted languages like Java, Python.
            2. Only Assembly, C/C++ needs to explicitly allocate memory and deallocate it when done.
         5. fork()
            1. When fork() process calls, the OS creates a child process and both parent and child will resume at the same line of code with the return value of fork() being evaluated. The child process will have return value of zero and the parent process will have the pid of the child.
            2. A fork() syscall may be very expensive by copying all data in one process to another, that's what happened in older UNIX systems. In newer UNIX systems with virtual memories, we only need to copy all the memory tables(magnitudes of KB) to the new process, vs contents of memory tables (magnitudes of MB or GB).
               1. Copy On Write => As soon as a process, be it the parent or the child, writes to a page,it will be copied to its own memory space and write from there. Allows cheap process replication.
         6. exec
            1. discards all existing address spaces and creates a new one to load code, and other address spaces and without heap and stack until after it's executed.
            2. the child process still retains most of the other resources of parent process such as environment and file descriptors
         7. \_exit
            1. a syscall that terminates the calling process. It indicates to other programs the status code of syscall.
         8. wait
            1. a syscall that waits in a blocked state for the child process to exit and reads its exit status code.
         9. Environment variables
            1. variables are stored directly in the heap of the process and address of the variables in heap is stored in a global variable in data section
            2. C library provides function to manipulate them and you don't want to manually modify them as it's format sensitive.
            3. exec call has to copy the environment out of the address space to some temporary location before it wipes the address space and then copy it back to the new address space.
      5. Processes & permissions
         1. Each process not only have an associated PID, they also have an associated user id which owns this process. User accounts with its associated set of privileges can be applied by that process run by the user.
            1. This means when a process executes certain syscalls, those syscalls may fail because the user which owns the process does not have the privilege to perform that action. Ex. a user who owns a process doesn't have the access to write to a certain file then any attempt to write to that file will fail.
         2. All accounts in the system is stored in /etc/passwd. etc is mainly used for configuration files.
            1. superuser/root = user id 0, is privileged to do anything it wants. Syscall of a process own by a superuser will never fail for privilege reasons/
         3. Each process has three user ids
            1. "real" id => the owning user
            2. "effective" id => determines privileges
            3. "saved" id => set by exec to match the effective id
               1. Each file or directory however, only has one user id.
               2. The exec syscall may change the effective and saved id. It does this when the binary file or the executable file being loaded has a special flag set on it called the set uid bit and when this flag is on, the effective and saved IDs get set to the user ID of the owner of that executable.
                  1. Ex. If one exec a execute a binary /bin/su, and the file has setuid set and owned by user 30 then effective and saved id will both be set to 30
                  2. The reason for setuid is when we want a user with non super user privileges to be able to run a program with super user privileges. Thus, if that executable file is owned by the super user and has a setuid bit on then anytime it is executed it will have privilege of the super user.
               3. Syscalls and how it affect user ids
                  1. exec => sets effective and saved ids when binary file has setuid bit
                  2. seteuid => sets effective user id
                  3. setuid => sets real, effective, and saved user ids
                     1. Only root user can invoke the system call to set up process id to anything it wants. Processes without super user privileges can only set the effective ID to match real id or saved id and nothing else.
         4. What happens when a process starts
            1. When the system starts, the process init is owned by super user and it's ran with super user privileges. init process then spawns a login process, run with super user privileges, to prompt a user to login.
            2. Once login is successful, the login process spawns a shell process that is some sort of interface process either in CLI or GUI and that shell is owned by your user account, the user who just logged in and it runs with the limited privileges of your user account
         5. Process start flow
            1. init creates a login by calling fork then exec to create user login.
            2. After successful login, login process fork itself, setuid for the user, and exec the shell program.
               1. Program can have user account that's created by the program itself and it's represented by a number in the system. This allows a program to create files that's owned simply by the program and nothing else.
         6. User groups
            1. /etc/group
               1. user may belong to multiple groups but has one "primary" group
               2. each file and directory is owned by one group
               3. each process has a real, effective, and saved group id
               4. binary files have setgid bit
               5. setegid and setgid
                  1. groups exists so we can designate a set of user account to have privileges with a file or directory and it's a legacy for linux systems
         7. Permissions
            1. For each file there are three permission classes, user, group and other classes.
            2. For each class there is a read/write/execute permission and each of which is either on or off.
            3. Which class of permission applies to a process is determined by the simple rule
               1. user class if file_user_id == effective_user_id
               2. group class if file_group_id == effective_group_id
               3. other if above two doesn't match
         8. File permissions
            1. read => can read bytes of a file
            2. write => can modify bytes of a file
            3. execute can exec file
         9. Directory permissions -> less intuitive
            1. read => can get name of files which that directory contains as well as list the directory
            2. write => can add/remove/rename files in that directory
            3. execute => can use in file paths
               1. if you don't have execute permission, then you can't use it in any file path and any syscall for that directory in the file path will fail. You won't see the files being listed because of a lack of execute permission.

## Unix System Calls #2

1. Syscalls that deals with files
   1. open => open/create a file and return a file descriptor
   2. close => release file descriptor
   3. read => copy bytes from a file to memory (may block)
      1. The data is copied from file disk to a buffer in the OS and then from there copied to the process. This is done mainly for performance reasons.
         1. The purpose of the read buffer is to read more than is requested and then store it in the read buffer so the subsequent syscalls to the read can read directly from the in memory read buffer and thus increase the performance.
      2. The read syscall works by default by first checking the buffer and seeing if the data is it wants is already there, if not the process will block while data is read into the buffer. Once the data is there, the process will unblock.
      3. The read syscall can read variable amount of data or fixed data by specifying it.
         1. If it's empty, then it's the EOF and it should close the file and do post processing.
   4. write => copy bytes of memory to a file (may block)
      1. file descriptor is passed to read/write syscall instead of a filepath
      2. Ex. if we are writing to a storage device like a HD, the data is not directly copied from the process to the storage device but to copied from the process to a buffer in memory outside of the process controlled by the OS. Then OS will write buffer to the storage devices.
         1. This makes sense for security as well as ensuring that process only have to wait to write to a buffer, the speed will be fast once in memory buffer is copied. The OS will take care copying from a buffer to the HD.
      3. With write syscall your process can never be certain when your data is written or whether it is written to disk. Therefore, the process can terminate even before the data is being written to disk.
   5. lseek => long sized integer seek
      1. passing the byte in which you wish to pass the marker to read a part of the file.
      2. this syscall can be used to move the marker to the relative location in a file for search, end of a file or pass file for write.
      3. marker
         1. a number that points to a specific byte location in a file.
      4. file descriptor
         1. A number in a process used to uniquely to identify an underlying data structure called description and description identifies the open file and represents the actual open file and which contains the marker. A descriptor can get copied and you ends up with 2 separate descriptors which both point to the same description, or the same underlying shared file marker.
         2. Ex. f = open ('/f1'); f2 = open('/f2); write(f, 'bla bla'); data = read(f2);
            1. Both calls to open always return a new descriptor. Therefore both write and read are done at the start of the file.
            2. Q ? Does read reads the data of the write syscall
               1. premise: descriptor => descriptions => buffer => file on disk, and buffer usually is shared.
               2. What happens: each write happens in the buffer and each read also happens in the buffer at that time. Thus, the read and write requires no coordination and will not ensure atomicity and transaction.
   6. file permission syscall
      1. umask => get/set default permissions for new files/directories
      2. chmod => change mode, set permissions of an existing file/directory
         1. the invoking user must have a pid of 0 or one who owns the file or else it will fail for a file the user doesn't own.
   7. file systems
      1. File inode
         1. Each storage device is separated into different partitions and within each partitions there is a filesystem and within each filesystem, each file and directory is known by a unique inode number, a number which uniquely identifies that file or directories in that partition.
         2. The root directory is always inode 2, and the inode 1 is a list that keeps track bad sections in the partition that are unusable, and inode 0 is usually used as a null pointer for no such file.
      2. mkdir => make directory
      3. rmdir => remove a file or directory
         1. files has no understanding of names. Only directories has a list of filenames and its associated inodes. The filesystem is basically uniquely identified by inodes not filenames.
      4. link => add directory entry
         1. the same inode is referenced by a file name. This is adds an inode reference count to a file. If the inode reference count is zero then that inode will be removed.
      5. unlink => remove directory entry
      6. getdents => get directory entries
         1. It returns some number of entries inside that directory. If zero entry then no more entry to read.
      7. mount => attach partition to the unified file system
      8. umount => detach partition from the unified file system
      9. chdir => change cwd
      10. File types
      11. 'regular' file
          1. files with data on a storage device
      12. directory
          1. listings of files and other directories
      13. symbolic link
          1. a file written to disk but doesn't have content, it's marked and has a link points to an inode.
      14. character device file
      15. block device file
      16. pipe
          1. for ipc between two processes in the same system
      17. socket
          1. for ipc between different machines across the network.
      18. symlink => creates a symbolic link
   8. Device CPU Communication
      1. CPU reads/writes to device registers
         1. CPU can read registers in a device by itself or interrupted by a device which causes it to read its registers
      2. A Device file
         1. When open, we can read and write data from it, which causes the CPU to read/write registers.
      3. A Block Device
         1. A device with large storage areas.
         2. An inode can be stored in many blocks noncontiguously. A file at least take one block.
         3. There is a buffer for read/write blocks and there 1-to-1 mapping between blocks and buffers
         4. What is a block device file
            1. a file that represents the entire storage area.
      4. Character Devices
         1. A device doesn't need to store data. Data gets in and out of data in sequence
         2. Character device file
            1. A process reads input buffer in memory from a character device file
            2. A process writes to output buffer in memory and to the device.
            3. Character device file buffers
               1. Called FIFO (First in, first out)
               2. data is taken from the beginning and is appended to the end of buffer
               3. They are not backed by storage whereas block device buffers are.
            4. It includes terminal, printers
            5. It can be seeked for a specific byte whereas block device can do lseek.
         3. Pseudo-device files // character device files abstracted by OS.
            1. /dev/zero => returns zeroed bytes
            2. /dev/random => returns random data
            3. /dev/null => discards data; returns no bytes at all.
      5. Pipe (FIFO as a file)
         1. read takes data in the beginning
         2. write appends data in the end of the pipe
         3. Syscalls
            1. mknode => creates a regular file, device file, or named pipe
               1. mknode('/dir/to/path', BLOCK|CHR|FIFO, devNum)
                  1. deviceNum is a unique value across all devices.
                  2. With a path, it's called a named pipe
                  3. Used for one way communication between two unrelated processes.
            2. pipe => creates a new, anonymous pipe and returns two file descriptors
               1. fs = pipe() => return fs[2], where fs[0] is for reading and fs[1] is for writing.
               2. It's for one way communication between two related processes.
               3. It's for related processes where the parent can pass the pipe file descriptor down to child processes.
      6. Memory-mapped files
         1. Pages in a process's address space are marked so that the reads and writes to those addresses actually trigger that of the underlying file.
         2. mmap(value, f, offset) => maps a process's memory to the actual file
            1. This maps 500 bytes of a file descriptor with offset of 200 bytes to the process's page address space. So when read/write to that address space actually triggers read/write to the actual file.
         3. munmap(address) => unmaps actual file from the process's memory
         4. close(f) => closes the file.
      7. Signals
         1. Sent by
            1. the kernel
            2. the kill system call
            3. Processes owned by a user can only receive signal from processes owned by the same user.
            4. Processes owned by one user can't be killed by other user but by super user.
         2. Hardware Interrupt
            1. Sent by hardware devices to the CPU
            2. Four signals found on all UNIX
               1. SIGSEGV
                  1. Segmentation Fault // memory error, when process access invalid memory address. A handler can be registered to handle cleanup.
               2. SIGFPE
                  1. Floating point error // ex. divide by zero error
               3. SIGSTOP
                  1. Stop
               4. SIGCONT
                  1. Continue
         3. Software Interrupt
            1. Sent by the OS to a process which must deal with the signal
         4. The receiving process
            1. performs a default action
            2. invokes a handler function
            3. blocks it
            4. ignores it
         5. Syscalls
            1. kill(35, SIGSTOP) => sends a signal to a process
            2. signal(func, SIGFPE) => set a signal to be handled, ignored, or trigger its default action.
