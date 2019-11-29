# Abstract

- This document introduces basic monitoring commands and their usage

## vmstat

1. Def
   1. Report virtual memory statistics
   2. Reports information about processes, memory, paging, block IO, traps, and cpu activity.
2. Syntax
   1. vmstat [options]delay [count]]
   2. delay => delay between updates in seconds
   3. count => number of updates. If count is absent and delay is defined, then defualt is infinite.
3. Use Cases
   1. Display processes, memory stat + active and inactive memory info + io + system stat + cpu + timestamp
      1. vmstat -atw
   2. Display read/writes and IO data for all disks
      1. vmstat -dw
   3. Display disk summary statistics about disk activity
      1. vmstat -D

## ps

1. Def
   1. report a snapshot of the current processes.
   2. displays information about a selection of the active processes. If you want a repetitive update of the selection and the displayed information, use top(1) instead
2. Use Cases
   1. Display stats
      1. Display general stats about processes
         1. ps -eo [options...]
      2. Find major and minor faults occurred by a process
         1. ps -o pid,comm,minflt,majflt <pid>
      3. Find security information
         1. ps -eo euser,ruser,suser,fuser,f,comm,label
   2. Filter processes
      1. every process running as root (real & effective ID) in user format
         1. ps -U root -u root u
3. Options
   1. %cpu - cpu utilization of the process in "##.#" format. Currently, it is the CPU time used divided by the time the process has been running (cputime/realtime ratio), expressed as a percentage.
   2. %mem - ratio of the process's resident set size to the physical memory on the machine, expressed as a percentage
   3. args - command with all its arguments as a string
   4. cgname - display name of control groups to which the process belongs.
   5. ppid - parent pid
   6. security related
      1. euid => effective user id
      2. euser => effective user
      3. egid => effective group id
      4. egroup => effective group
      5. suid => saved user id
      6. f => flags associated with the process, 1 for forked but didn't exec, 4 for used super-user privileges
      7. rss => resident set size, the non-swapped physical memory that a task has used
      8. ruid => real user id
      9. sig => signal pending

## Miscellaneous commands

1. free -mw
   1. free displays the total amount of free and used physical and swap memory in the system, as well as the buffers and caches used by the kernel. The information is gathered by parsing /proc/meminfo.
   2.
