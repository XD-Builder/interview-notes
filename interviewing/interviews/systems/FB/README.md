# Abstract

- This document outlines covered topics and sub-topics for a production engineer

## Topics

1. pe_general
   1. PE Responsibilities and day-to-day activities
   2. Why it is crucial to hire PEs who know all aspects of production systems.
2. pe_process
   1. Process Creation, Execution and Destruction
   2. Differences between Processes and Threads
3. pe_memory - Memory Management
   1. An Abstract Model of Virtual Memory
   2. Caches
   3. Linux Page Tables
   4. Page Allocation
   5. Memory Mapping
   6. Demand Paging
   7. The Linux Page Cache
4. pe_kernel
   1. System Calls
   2. Signals and Signal Handlers
5. Unix Filesystem Structure
   1. The Second Extended File system (EXT2)
   2. The Virtual File System (VFS)
   3. The Buffer Cache
   4. The /proc File System
   5. Device Special Files
6. User and Kernel space boundaries and interactions
   1. Examples might include: ioctls, sysctls, context switches.

## Tips

    1. Develop in-depth knowledge of the tools available for troubleshooting a system and a deep understanding of results returned by those tools.
    2. Develop a good approach to troubleshooting problems. A good approach may be the ability to follow a path of investigation where you progressively rule out potential problems until root cause is identified.

## Troubleshooting

1. Troubleshooting tools for system-level performance issues
2. Troubleshooting tools for debugging application-level performance issue
