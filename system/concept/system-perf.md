# Performance

## Major System Resource Types and performance components & Tools
1. Major System Resource Types
    1. CPU
    2. Memory
    3. Disk Space
    4. Communications lines
    5. I/O Times
    6. Network Time
    7. Applications Programs
2. Performance Components - Five major components which take up the system time
    1. User State CPU
        1. The actual amount of time the CPU spends running the users' program in the user state. It includes the time spent executing library calls, but does not include the time spent in the kernel on its behalf.
    2. System State CPU
        1. Amount of time the CPU spends in the system state on behalf of this program. All I/O routines require kernel services. The programmer can affect this value by blocking I/O transfers
    3. I/O Time and Network Time
        1. The amount of time spent moving data and servicing I/O requests
    4. Virtual memory Performance
        1. Context Switching and swapping
    5. Application Program
        1. Time spent running other programs - when the system is not servicing this application because another application currently has the CPU.
3. Tools
    1. nice/renice
        1. Runs a program with modified scheduling priority
    2. netstat
        1. prints network connections, routing tables, interface statistics, masquerade connections, and multicast memberships
    3. time
        1. Helps time a simple command or give resource usage
    4. Uptime
        1. System Load Average
    5. ps
        1. Snapshot of current processes
    6. vmstat
        1. virtual memory statistics reports
    7. gprof
        1. call graph profile data
    8. prof 
        1. Facilitates Process Profiling
    9. top
        1.  Displays system tasks