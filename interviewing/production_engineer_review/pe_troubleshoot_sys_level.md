# Abstract

1. OS performance issues commonly involve process and memory management and scheduling. This document will cover aspects of system level perf issues and tools that troubleshoots those issues.

# What are system-level performance issues?

1. OS perf issues are related to I/O bandwidth, CPU power, and swap space. They can be divided into following categories:
   1. Using Operating System Caches
   2. Memory Usage
   3. Using OS Resource Managers

## Using Operating System Caches

1. Issue statement
   1. OS and device controllers provide data caches. These structures can consume resources while offering little or no benefit to performance
      1. filesystem may cache files in data structure whereas application has its own file cache
2. Possible cache solutions
   1. Asynchronous I/O
      1. Processing continues while I/O request is submitted and processed. It avoids perf bottleneck. (Non-blocking)
   2. FILESYSTEMIO_OPTIONS Initialization Parameter
      1. ASYNCH: enable asynchronous I/O on file system files, which has no timing requirement for transmission.
      2. DIRECTIO: enable direct I/O on file system files, which bypasses the buffer cache.
      3. SETALL: enable both asynchronous and direct I/O on file system files.
      4. NONE: disable both asynchronous and direct I/O on file system files.

## Memory Usage

1. Issue Statement
   1. Memory usage is affected by both buffer cache limits and initialization parameters
2. Possible memory solutions
   1. Buffer Cache Limits
      1. Cache consumes OS memory resources.
      2. UNIX buffer cache may be allocated a set amount of memory and it's common today for more sophisticated memory management mechanisms to be used. These allow free memory pages to be used to cache I/O.
         1. In such systems, it's common for OS reporting tools to show no free memory but is not a problem because when memory usage pressure increases, the memory caching I/O data is usually released to allow the process memory to be allocated.
   2. Parameters Affecting Memory Usage
   3. OS Resource Managers
      1. Designed to reduce the impact of peak load use patterns by prioritizing access to system resources. It implements administrative policies that govern which resources users can access and how much.
      2. Domains provide one or more completely separated environments within one system. Disk, CPU, memory, and all other resources are dedicated to each domain and cannot be accessed from any other domain.
      3. Prioritize resource allocation within a global pool of resources, usually a domain or an entire system. Processes are assigned to groups, which are in turn assigned resources anywhere within the resource pool.

## Solving Operating System Problems

1. Performance Hints
   1. Try to establish a good ratio between the amount of time the OS spends fulfilling system calls and doing process scheduling and the amount of time the app runs.
      1. The goal should be to run most of the time in app mode, user mode, rather than system mode.
   2. The ratio of time spent in each mode is only a symptom of the underlying problem:
      1. Paging or swapping
      2. Executing too many system calls
      3. Running too many processes
         1. The more time you can release from the OS side, the more transactions an app can perform
   3. Consider the paging parameters
      1. On a busy system, free memory likely contains a page belonging to one or more currently active process.
         1. When that access occurs, a "soft page fault" takes place, and the page is included in the working set of the process.
      2. If the process cannot expand its working set, then one of the pages currently mapped by the process must be moved to the free set.
   4. Memory size
      1. Any number of processes might have pages of shared memory within their working sets. The sum of the sizes of the working sets can thus exceed the available memory.

## Understanding CPU

1. Cases for CPU
   1. System is idle, average workloads and peak workloads.
   2. System must be designed to handle peak workload and thus wastes resources when it's not at peak, low CPU utilization
2. CPU capacity issues can be addressed by
   1. Tuning, the process of detecting and solving CPU problems from excessive consumption
   2. Increasing hardware capacity, including changing the system architecture
   3. Reducing the impact of peak load use patterns by prioritizing CPU resource allocation.

## Finding System CPU Utilization

1. Why?
   1. Every process running on your system affects the available CPU resources
   2. Useful statistics are:
      1. Number of CPUs, utilization, load, paging, physical memory
2. Checking Memory Management
   1. Paging and Swapping
      1. Tools to investigate the cause of paging and swapping
   2. Oversized Page Tables
      1. If processing space becomes too large, it can result in the page tables becoming too large
3. Checking I/O Management
   1. Def Thrashing
      1. Swapping and paging processes in and out of memory
   2. Thrashing is an I/O management issue. Ensure that your workload fits into memory, so the system is not thrashing.
      1. If thrashing happens, then your app may be running 50% of the CPU time slot allocated.
4. Checking Network Management
   1. Client/server round trips
      1. An overhead in processing messages is when an app generates many messages that need to be sent through the network, the latency of sending a message can result in **CPU overload**.
   2. Solution
      1. bundle multiple messages together rather than perform lots of round trips.
5. Checking Process Management
   1. scheduling and switching
      1. The OS can spend excessive time scheduling and switching process.
      2. Examine processes being run in the OS
   2. Context switching
      1. It's expensive. However it's not an perf issue on Windows, which has only one process for each instance. All threads share the same page table.
   3. Post-wait Driver
      1. A process needs to be able to post to another process and wait to be posted
      2. Implemented through UNIX semaphores and resource intensive.
   4. Memory-mapped System Timer
      1. Querying system time for timing information via costly context switch is not effective.
      2. Some platforms implements memory-mapped timer that uses an address within the processes virtual address space to contain the current time information. Reading from this memory-mapped time is less expensive than the overhead of a context switch sys call.
   5. List I/O interfaces to submit multiple asynchronous I/Os in One Call
      1. List I/O
         1. an API that allows several async I/O requests to be submitted in a single syscall. Main benefit is to reduce the number of context switches required
   6. Starting New OS Processes
      1. Cost in starting new OS processes is high.
      2. Creating, exiting and creating single-purpose processes consumes excessive amounts of CPU because kernel needs to build the page tables each time.
         1. The problem is aggravated when you pin or lock shared memory, because you have access to every page.

# General Troubleshooting Guideline

1. Initial analysis
   1. Identify Resources which are culprit for system slow/perf issues.
   2. It may be a bug in kernel or app or a mal-functioning hardware sub-system.
   3. Thus, we need to thoroughly study system and identify the hot spots. Once identified, further analysis would be easy
2. Mindset
   1. It's better start identifying causes at system level, then customer issue level with a background understanding/knowledge of recent changes.
3. General probing
   1. When exact cause is not known, one should start by checking "load average" to test CPU. If it's fine, we test memory, network, etc.
   2. Filter SAR (System Activity Report) dump data for load and check based on when perf glitch was reported
4. Check recent system logs
   1. /var/log/messages to notice if any failed/error/warning messages
5. Run "vmstat 1 50"
   1. prints continuously system statistics of 50 samples (process status, memory details, memory details, swapped in/out, IO in/out, CPU usage details, interrupt details etc.,). Check for un-usual trend
6. If glitch is when accessing network share or remote transfer, troubleshoot networking
7. Once main component identified, check tuning or component upgrade necessary
8. If no abnormalities in hardware component then there could be a bug which is either app or OS related, sometimes due to improper tuning of an app.
9. If system is not meeting minimum requirements of an app then we can't expect a good & steady perf. Check sys hardware are in agreement with app prerequisite.

# What are troubleshooting tools for system-level performance issues?

1. Resource Utilization Tools
   1. vmstat
   2. sar
   3. iostat
2. Topics
   1. Most Powerful Tool
      1. atop -> Advanced Linux System & process monitor
         1. Very powerful and an interactive monitor to view the load on system.
         2. Displays most critical hardware resources from perf point of view.
         3. Quicly see CPU, memory, disk and network performance
         4. It shows which processes are responsible for the indicated load concerning CPU and memory load on a process level.
      2. /proc/\*
         1. cpuinfo, meminfo, zoneinfo, mounts
      3. strace -o output.txt -p <pid_under_test>
         1. shows system calls made by the process
      4. Nagios
         1. Linux server/networ monitoring
         2. Easily monitor all your hosts, network equipment and services and alerts you when bad things happen.
      5. Cacti
         1. A complete network graphing solution designed to harness the power of RRDTool's data storage and graphing functionality.
      6. lsof
         1. Lists all the open files and the processes including disk files, network sockets, pipes, devices and processes
   2. CPU
      1. `uptime`
         1. shows CPU load average, number of days up and number of users logged in
         2. How load avg is calculated?
            1. Calculated based on number of processors(logical) available.
            2. A single processor with load avg of 1 is as busy as 4 CPU with load avg of 4
            3. Any value below 1 indicates normal working & minimum wait time. Whereas, any value above 1 indicates resource saturation and some amount of wait time.
      2. `top`
         1. Opens up in monitor mode window which dynamically populates data
         2. Options
            1. A - for quick identification of perf hungry tasks
      3. `vmstat` - Virtual memory statistics -> belongs to procps package
         1. Procs
            1. r => The number of runnable processes (running, waiting)
            2. b => The number of processes in uninterruptible sleep
         2. Memory
            1. swpd => vm used
            2. free => idle memory
            3. buff => memory used as buffers
            4. cache => memory used as cache
            5. Enabled with -a option
               1. inact => inactive memory
               2. active => active memory
         3. Swap
            1. si => Swapped in from disk (/s)
            2. so => Swapped to disk (/s)
         4. IO
            1. bi => Blocks received from a block device (block/s)
            2. bo => Blocks sent to a block device (block/s)
         5. System
            1. in => Interrupts per second, including the clock
            2. cs => context switches per second
         6. CPU
            1. us => non-kernel code user time, including nice time
            2. sy => kernel code system time
            3. id => idle time
            4. wa => waiting for IO time
            5. st => virtual machine stolen time
      4. `dstat` or `sar` -> belongs to **sysstat** package
         1. sar
            1. time serious of system activity stats
         2. dstat
            1. dstat -vsyst 1 10
               1. shows procs, memory, paging, disk total, system, total cpu usage, swap, and time in a color coded manner
         3. Popular commands under this package
            1. iostat, mpstat(processor related stat), pidstat
            2. mpstat -P ALL 1 3
               1. Known as multiprocessor stat
               2. prints all processor stats in three seconds every second
      5. CPU Issue Resolution
         1. Stop unnecessary processes
         2. Reduce priority of a process if that is consuming more CPU cycles.
         3. "renice" command should be used to change priority of a process.
            1. Ranges fro -20 (highest) to 19 (lowest)
            2. Renice a high CPU process with less priority is a good option.
         4. If there is a need to check the CPU statistics for earlier day when we could use 'sar' data (/var/log/sa) and observe the stats:
            1. #LANG=C /usr/bin/sar -P ALL -f /var/log/sa/sa<XX>
         5. Find top 5 CPU resource hogs
            1. ps -eo pcpu,pmem,pid,ppid,user,stat,args | sort -k 1 -r | head -6|sed 's/\$/\n/'
   3. Memory
      1. `free` => top or vmstat can be also used for similar purpose
         1. Analyze high memory and check on memory available which is a combination for free+buffers+cacahed pages
         2. vmstat -m
            1. show memory utilization slabinfo
         3. vmstat -a
            1. show active and inactive memory pages
      2. free -m
         1. shows memory information
      3. `cat /proc/meminfo | egrep -w "Buffers|Cached|MemFree"`
         1. prints detailed information about memory
      4. dstat -mst 2 5
         1. prints memory status every 2 seconds 5 times
      5. sar -B
         1. prints page faults happened between certain timestamp
            1. If there are major faults then it would certainly delay since page needs to be moved from disk to memory
      6. dstat --vm
         1. Used to view major/minor page faults dynamically
      7. ps -o pid,comm,minflt,majflt <ProcessID>
         1. To view a specific pid major/minor page faults
      8. pidstat -l -r | sort -k8r
         1. Find out memory usage of active process
      9. Memory Issue Resolution
         1. If a system is showing high memory usage and also swap space is being consumed, then it may be a symptom for system under high memory pressure.
         2. Swap space being used does not indicate a memory bottleneck but rather proves how efficiently Linux handles system resources.
            1. Swap in indicates when a swapped out pages is swapped in when there is a process that needs it.
         3. High amount of page cache
            1. This is data/files which gets copied over to RAM when kernel performs read/write operation on a disk. It's kept there for perf.
            2. Sometimes this can be an issue when system is swapping pages to disk but mostly not a problem
         4. Implement hugetlb, increase/decrease page size, stop unnecessary services/daemons, add more memory if there is a physical memory crunch
         5. If there is a high pressure of cache memory, then one could start flushing out dirty data sooner than defaults by tuning "dirty_background_ratio" to lower values.
            1. In some cases, when kernel starts to swap-out pages instead of reclaiming from cache then one should lower the "vm.swappiness" to decrease rate at which pages are swapped out.
            2. A lower swappiness value is recommended for database workloads. Oracle recommends 10 and default is 60
         6. dirty_ratio (upper limit for dirty_background_ratio)
            1. defines a percentage value. Write-out of dirty data to disk begins when dirty data comprises this percentage of total system memory. Default is 20, lower to 15 for database workload
            2. This blocks all writes until some of the dirty pages get written to disk
         7. dirty_background_ratio
            1. Write-out of dirty data begins in the background when dirty data comrpises this percentage of total memory. Default 10, database recommends 3
         8. valgrind
            1. If you believe a process is having memory leak, this command is going to identify them.
   4. Disk I/O
      1. iostat -xd
         1. reads data from /proc/diskstats &belongs to sysstat package)
         2. "wait" => average wait time
         3. "svctm" => service time
         4. "avgrq-sz" => average size of request
         5. "avgqu-sz" => average queue length
         6. rrqm/s & wrqm/s => read/write requests merged per second
      2. iotop
         1. displays current I/O usage by processes or threads on the system.
      3. LANG=C /usr/bin/sar -dp
         1. Can show I/O percentage
      4. Commands
         1. vmstat
      5. IO issue Resolution
         1. High IO wait percentage
            1. If machine is running I/O bound applications, then it's not a concern.
            2. If Slowness by disk responding could be due to an issue with kernel which needs further analysis and tuning. Check hardware disk drive vendor to see if device is at optimal best or if firmware update is necessary
         2. Default elevator (disk elevator or IO scheduler)
            1. Sometimes it may be required to change the default elevator
         3. If hard drive being used consists of both spindle based drives and SSD then speed could be improved by making SSD as a cache device for large hard drives.
   5. Network
      1. Issue Resolution
         1. Pre-checks for resolution
            1. Network drivers/firmware of system are updated. Interface speed is matching with router/gateway speed since overall network speed would operate on slowest network component.
      2. Commands
         1. netstat
            1. Provide details about open network connections and stack statistics. Pulls data from /proc/net/[dev|tcp|unix] and other files stored under "/proc/net"
            2. netstat -tulpn
         2. ethtool -s <interface>
            1. Find out packet drops/losses at hardware level
         3. tcpdump
            1. Capture dump data to analyze further
            2. tcpdump -s 0 -i {INTERFACE} -w {FILEPATH} [filter expression]
         4. sar -n DEV
            1. can be used to see network packet flow for earlier days between specific time
      3. Issue Resolution
         1. Want to know about drops/errors/collision
            1. ip -s link
         2. Want to test network bandwidth
            1. use qperf, iperf, netcat, dd..
   6. Interrupt
   7. Time Used
      1. Processor time
      2. User Time
      3. Privileged time
