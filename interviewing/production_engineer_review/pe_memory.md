# Abstract

This document defines and summarizes memory and memory management by the linux kernel.

# Memory Management

1. Memory is the one of the most important parts of the OS. Virtual memory makes the system appear to have more memory than it actually has by sharing it between competing processes as they need it.

# Introduction

1. Linux memory management subsystem provides:
   1. Large Address Spaces
      1. OS makes the system appear a larger amount of memory, possibly many times larger than physical memory in the system
   2. Protection
      1. Virtual address spaces allocated to each process are completely separate from each other and the hardware virtual memory mechanisms allow areas of memory to be protected against writing by rogue applications
   3. Memory Mapping
      1. Maps image and data files into a process address space. The contents of a file are linked directly into a virtual address space of a process.
   4. Fair Physical Memory Allocation
      1. Allows each running process in the system a fair share of the physical memory
   5. Shared Virtual Memory
      1. Allows reading of binaries and dynamic libraries.
         1. For example there could be several processes in the system running the bash command shell. Rather than have several copies of bash, one in each processes virtual address space, it is better to have only one copy in physical memory and all of the processes running bash share it. Dynamic libraries are another common example of executing code shared between several processes.
      2. Allows IPC between processes
         1. Two or more processes exchanging information via memory common to all of them. Linux supports the Unix System V shared memory IPC

## An Abstract Model of Virtual Memory

1. Intro

   1. Virtual memory uses
      1. As the processor executes a program it reads an instruction from memory and decodes it. In decoding the instruction it may need to fetch or store the contents of a location in memory. The processor then executes the instruction and moves onto the next instruction in the program. In this way the processor is always accessing memory either to fetch instructions or to fetch and store data.
      2. In a virtual memory system all of these addresses are virtual addresses and not physical addresses. These virtual addresses are converted into physical addresses by the processor based on information held in a set of tables maintained by the operating system.
      3. To make this translation easier, virtual and physical memory are divided into handy sized chunks called pages. These pages are all the same size, they need not be but if they were not, the system would be very hard to administer. Linux on Intel x86 systems uses 4 Kbyte pages. Each of these pages is given a unique number; the page frame number (PFN).
      4. In this paged model, a virtual address is composed of two parts; an offset and a virtual page frame number(VPFN). If the page size is 4 Kbytes, bits 11:0 of the virtual address contain the offset and bits 12 and above are the virtual page frame number. Each time the processor encounters a virtual address it must extract the offset and the virtual page frame number. The processor must translate the virtual page frame number into a physical one and then access the location at the correct offset into that physical page.
         1. To do this the processor uses page tables.
   2. Virtual page frame
      1. The processor uses the virtual page frame number as an index into the processes page table to retrieve its page table entry. If the page table entry at that offset is valid, the processor takes the physical page frame number from this entry. If the entry is invalid, the process has accessed a non-existent area of its virtual memory. In this case, the processor cannot resolve the address and must pass control to the operating system so that it can fix things up.
      2. Just how the processor notifies the operating system that the correct process has attempted to access a virtual address for which there is no valid translation is specific to the processor. However the processor delivers it, this is known as a page fault and the operating system is notified of the faulting virtual address and the reason for the page fault.
      3. Assuming that this is a valid page table entry, the processor takes that physical page frame number and multiplies it by the page size to get the address of the base of the page in physical memory. Finally, the processor adds in the offset to the instruction or data that it needs.
         1. If process Y's virtual page frame number 1 is mapped to physical page frame number 4 which starts at 0x8000 (4 x 0x2000). Adding in the 0x194 byte offset gives us a final physical address of 0x8194.
      4. No ordering required for VPFN to PFN.

2. Demand Paging

   1. Intro
      1. Reasoning for demand paging
         1. Since physical memory is much less than virtual memory, OS needs to use physical memory efficiently.
         2. Load virtual pages that are currently being used by the executing program. This technique of only loading virtual pages into memory as they are accessed is known as **demand paging**
      2. Page Fault
         1. If a processor cannot translate a VPFN into a PFN, it notifies the OS that a page fault has occurred
         2. If the faulting virtual address is invalid, then a process has attempted to access a VPFN that it should not have. The OS will terminate the process so other process will be not be affected
         3. If the faulting virtual address was valid but the page that it refers to is not currently in memory, the OS must bring the appropriate page into memory from the image on disk.
            1. Disk access takes a long time, relatively speaking, and so the process must wait quite a while until the page has been fetched. If there are other processes that could run then the operating system will select one of them to run.
            2. The fetched page is written into a free physical page frame and an entry for the virtual page frame number is added to the processes page table. The process is then restarted at the machine instruction where the memory fault occurred. This time the virtual memory access is made, the processor can make the virtual to physical address translation and so the process continues to run.
      3. Demand paging uses
         1. Linux uses demand paging to load executable images into a processes virtual memory. Whenever a command is executed, the file containing it is opened and its contents are mapped into the processes virtual memory. This is done by modifying the data structures describing this processes memory map and is known as memory mapping.
         2. However, only the first part of the image is actually brought into physical memory. The rest of the image is left on disk. As the image executes, it generates page faults and Linux uses the processes memory map in order to determine which parts of the image to bring into memory for execution.

3. Swapping

   1. Why swapping?
      1. When a process needs to bring a virtual page into a physical memory and there are no free physical pages available, the OS must make room for this page by discarding another page from physical memory
         1. If the page to be discarded from physical memory came from an image or data file and has not been written to then the page does not need to be saved. Instead it can be discarded and if the process needs that page again it can be brought back into memory from the image or data file.
         2. However, if the page has been modified, the operating system must preserve the contents of that page so that it can be accessed at a later time. This type of page is known as a dirty page and when it is removed from memory it is saved in a special sort of file called the swap file. Accesses to the swap file are very long relative to the speed of the processor and physical memory and the operating system must juggle the need to write pages to disk with the need to retain them in memory to be used again.
   2. Downsides
      1. If the swap algorithm is not efficient then a condition known as thrashing occurs. Pages are constantly being written to disk and then being read back and the OS is too busy to allow much real work to be performed.
      2. The set of pages that a process is currently using is called the working set. An efficient swap scheme would make sure that all processes have their working set in physical memory.
   3. How is it implemented in Linux?
      1. Linux uses a Least Recently Used (LRU) page aging technique to fairly choose pages which might be removed from the system. This scheme involves every page in the system having an age which changes as the page is accessed. The more that a page is accessed, the younger it is; the less that it is accessed the older and more stale it becomes. Old pages are good candidates for swapping.

4. Shared Virtual Memory

   1. Characteristics?
      1. All memory access are made via page tables and each process has its own separate page table. For two processes sharing a physical page of memory, its physical page frame number must appear in a page table entry in both of their page tables.

5. Physical and Virtual Addressing Modes

   1. What is?
      1. Most multi-purpose processors support the notion of a physical address mode as well as a virtual address mode.
         1. Physical addressing mode requires no page tables and the processor does not attempt to perform any address translations in this mode. The Linux kernel is linked to run in physical address space.
      2. Ex. No Physical Addressing Mode?
         1. The Alpha AXP processor does not have a special physical addressing mode. Instead, it divides up the memory space into several areas and designates two of them as physically mapped addresses. This kernel address space is known as KSEG address space and it encompasses all addresses upwards from 0xfffffc0000000000. In order to execute from code linked in KSEG (by definition, kernel code) or access data there, the code must be executing in **kernel mode**. The Linux kernel on Alpha is linked to execute from address 0xfffffc0000310000.

6. Access Control
   1. Page table entries contain access control information
      1. Executable code is naturally read only memory
      2. Pages containing data can be written to but attempts to execute would fail
      3. Kernel code should not be executed by a user
      4. Kernel data structures should be accessible except in kernel mode.
   2. Access control in Page Table Entry (PTE) - meanings
      1. V => valid PTE entry; if yes, then it's in memory else in swap file
      2. FOE, FOW; FOR => Fault on execute, write, read
      3. ASM => Address Space Match, used when the operating system wishes to clear only some of the entries from the Translation Buffer
      4. KRE => Code running in kernel mode can read this page
      5. URE => Code running in user mode can read this page
      6. GH => Granularity hint when mapping an entire block with a single Translation Buffer entry rather than many
      7. KWE => Code running in kernel mode can write to this page
      8. UWE => Code running in user mode can write to this page
      9. Page Frame number => If V bit is set, this field contains the physical PFN for this PTE. For invalid PTEs, if this field is not zero, it contains information about where the page is in the swap file.
      10. \_PAGE_DIRTY => If set, the page needs to be written out to the swap file
      11. \_PAGE_ACCESSED => Used by Linux to mark a page as having been accessed.

## Caches

1. Introduction
   1. Both OS and processor designers try hard to extract more performance from the system. Apart from making the processors, memory faster, the best approach is to maintain caches of useful information and data that make some operations faster.
2. Caches:
   1. Buffer Cache
      1. Contains data buffers that are used by the block device drivers
      2. The buffer cache is indexed via the device identifier and the desired block number and is used to quickly find a block of data.
      3. Block devices are only ever accessed via the buffer cache. If data can be found in the buffer cache then it does not need to be read from the physical block device, for example a hard disk, and access to it is much faster.
   2. Page Cache
      1. Used to speed up access to images and data on disk
      2. Used to cache the logical contents of a file a page at a time and is accessed via the file and offset within the file. As pages are read into memory from disk, they are cached in the page cache
   3. Swap Cache
      1. Only modified (dirty) pages are saved in the swap file
      2. So long as these pages are not modified after they have been written to the swap file then the next time the page is swapped out there is no need to write it to the swap file as the page is already in the swap file. Instead the page can simply be discarded. In a heavily swapping system this saves many unnecessary and costly disk operations.
   4. Hardware Caches
      1. A common hardware cache is inside a processor, a cache of Page Table Entries.
         1. Processor doesn't always read the page table directly but instead caches translations for pages as it needs them. These are called Translation Look-aside Buffers and contain cached copies of the page table entries from one or more processes in the system.
      2. Translation in action
         1. When the reference to the virtual address is made, the processor will attempt to find a matching TLB entry. If it finds one, it can directly translate the virtual address into a physical one and perform the correct operation on the data. If the processor cannot find a matching TLB entry then it must get the operating system to help. It does this by signalling the operating system that a TLB miss has occurred.
         2. A system specific mechanism is used to deliver that exception to the operating system code that can fix things up. The operating system generates a new TLB entry for the address mapping. When the exception has been cleared, the processor will make another attempt to translate the virtual address. This time it will work because there is now a valid entry in the TLB for that address.
   5. Drawbacks
      1. The drawback of using caches, hardware or otherwise, is that in order to save effort Linux must use more time and space maintaining these caches and, if the caches become corrupted, the system will crash.

## Linux Page Tables

1. Characteristics - Find Physical page via page tables?
   1. Linux assumes that there are three levels of page tables. Each Page Table accessed contains the page frame number of the next level of Page Table
   2. To translate a virtual address into a physical one, the processor must take the contents of each level field, convert it into an offset into the physical page containing the Page Table and read the page frame number of the next level of Page Table. This is repeated three times until the page frame number of the physical page containing the virtual address is found. Now the final field in the virtual address, the byte offset, is used to find the data inside the page.
      1. Each platform that Linux runs on must provide translation macros that allow the kernel to traverse the page tables for a particular process. This way, the kernel does not need to know the format of the page table entries or how they are arranged.

## Page Allocation and De-allocation

1. Uses?
   1. There are many demands on the physical pages in the system.
      1. For example, when an image is loaded into memory the operating system needs to allocate pages. These will be freed when the image has finished executing and is unloaded.
      2. Another use for physical pages is to hold kernel specific data structures such as the page tables themselves. The mechanisms and data structures used for page allocation and deallocation are perhaps the most critical in maintaining the efficiency of the virtual memory subsystem.
2. Characteristics
   1. All of the physical pages in the system are described by the mem_map data structure which is a list of mem_map_t
   2. Important mem_map_t fields:
      1. count - A count of the number of users of this page. > 1 when shared between processes
      2. age - used to decide if a page is a good candidate for discarding and swapping
      3. map_nr - physical page frame number this structure describes
   3. free_area vector is used by the **page allocation** code to find and free pages.
      1. Each element of free_area contains information about blocks of pages.
         1. The first element in the array describes single pages, the next blocks of 2 pages, the next blocks of 4 pages and so on upwards in power of two.
      2. The list element is used as a queue head and has pointers to the page data structures in the mem_map array. Free blocks of pages are queued here. map is a pointer to a bitmap which keeps track of allocated groups of pages of this size. Bit N of the bitmap is set if the Nth block of pages is free.

### Page Allocation

1. Characteristics?
   1. Linux uses the Buddy algorithm to effectively allocate and de-allocate blocks of pages. The page allocation code attempts to allocate a block of one or more physical pages. So long as there are enough free pages in the system to grant this request (nr_free_pages > min_free_pages) the allocation code will search the free_area for a block of pages of the size requested. Each element of the free_area has a map of the allocated and free blocks of pages for that sized block.
   2. Allocation algorithm searches for blocks of pages of the size requested. If no blocks of pages of the requested size are free, blocks of next size are looked for. This process continues until all of the free_area has been searched or until a block of pages has been found. If the block of pages found is larger than that requested it must be broken down until there is a block of the right size.
   3. Because the blocks are each a power of 2 pages big then this breaking down process is easy as you simply break the blocks in half. The free blocks are queued on the appropriate queue and the allocated block of pages is returned to the caller.

### Page De-allocation

1. Characteristics
   1. Allocating blocks of pages tends to fragment memory with larger blocks of free pages being broken down into smaller ones. The page de-allocation code recombines pages into larger blocks of free pages whenever it can and the page block size is important as it allows for each combination of blocks into larger blocks.
   2. Whenever a block of pages is freed, the adjacent or bubddy block of the same size is checked to see if it's free. If it is, then it is combined with the newly freed block of pages to form a new free block of pages for the next size block of pages.
   3. Each time two blocks of pages are recombined into a bigger block of free pages, the page de-allocation code attempts to recombine that block into a yet larger one. This way the blocks of free pages are as large as memory usage will allow

## Memory Mapping

1. Characteristics
   1. When an image is executed, the contents of the executable image must be brought into the processes virtual address space. The same is also true of any shared libraries that the executable image has been linked to use. The executable file is not actually brought into physical memory, instead it is merely linked into the processes virtual memory. Then, as the parts of the program are referenced by the running application, the image is brought into memory from the executable image. This linking of an image into a processes virtual address space is known as memory mapping.
   2. Every processes virtual memory is represented by an mm_struct data structure. This contains information about the image that it is currently executing (for example bash) and also has pointers to a number of vm_area_struct data structures. Each vm_area_struct data structure describes the start and end of the area of virtual memory, the processes access rights to that memory and a set of operations for that memory. These operations are a set of routines that Linux must use when manipulating this area of virtual memory.
      1. For example, one of the virtual memory operations performs the correct actions when the process has attempted to access this virtual memory but finds (via a page fault) that the memory is not actually in physical memory. This operation is the nopage operation. The nopage operation is used when Linux demands pages of an executable image into memory.
      2. When an executable image is mapped into a processes virtual address a set of vm_area_struct data structures is generated. Each vm_area_struct data structure represents a part of the executable image; the executable code, initialized data (variables), unitialized data and so on. Linux supports a number of standard virtual memory operations and as the vm_area_struct data structures are created, the correct set of virtual memory operations are associated with them.

## Demand Paging

1. Characteristics - Execution and fault handling?
   1. Once an executable image has been memory mapped into a processes virtual memory it can start to execute. As only the very start of the image is physically pulled into memory it will soon access an area of virtual memory that is not yet in physical memory. When a process accesses a virtual address that does not have a valid page table entry, the processor will report a page fault to Linux.
   2. The page fault describes the virtual address where the page fault occurred and the type of memory access that caused. Linux must find the vm_area_struct that represents the area of memory that the page fault occurred in. As searching through the vm_area_struct data structures is critical to the efficient handling of page faults, these are linked together in an AVL (Adelson-Velskii and Landis) tree structure. If there is no vm_area_struct data structure for this faulting virtual address, this process has accessed an illegal virtual address. Linux will signal the process, sending a SIGSEGV signal, and if the process does not have a handler for that signal it will be terminated.
   3. Linux next checks the type of page fault that occurred against the types of accesses allowed for this area of virtual memory. If the process is accessing the memory in an illegal way, say writing to an area that it is only allowed to read from, it is also signalled with a memory error.
   4. Now that Linux has determined that the page fault is legal, it must deal with it. Linux must differentiate between pages that are in the swap file and those that are part of an executable image on a disk somewhere. It does this by using the page table entry for this faulting virtual address. If the page's page table entry is invalid but not empty, the page fault is for a page currently being held in the swap file.
   5. The generic Linux nopage operation is used for memory mapped executable images and it uses the page cache to bring the required image page into physical memory. However the required page is brought into physical memory, the processes page tables are updated. It may be necessary for hardware specific actions to update those entries, particularly if the processor uses translation look aside buffers. Now that the page fault has been handled it can be dismissed and the process is restarted at the instruction that made the faulting virtual memory access.

## The Linux Page Cache

1. Characteristics?
   1. Speeds up access to files on disk. Memory mapped files are read a page at a time and these pages are stored in the page cache
   2. Each file in Linux is identified by a VFS inode data structure and each VFS inode is unique and fully describes one and only one file. The index into the page table is derived from the file's VFS inode and the offset into the file.
   3. Whenever a page is read from a memory mapped file, for example when it needs to be brought back into memory during demand paging, the page is read through the page cache. If the page is present in the cache, a pointer to the mem_map_t data structure representing it is returned to the page fault handling code. Otherwise the page must be brought into memory from the file system that holds the image. Linux allocates a physical page and reads the page from the file on disk.
   4. If it is possible, Linux will initiate a read of the next page in the file. This single page read ahead means that if the process is accessing the pages in the file serially, the next page will be waiting in memory for the process.
   5. Over time the page cache grows as images are read and executed. Pages will be removed from the cache as they are no longer needed, say as an image is no longer being used by any process. As Linux uses memory it can start to run low on physical pages. In this case Linux will reduce the size of the page cache.

## Swapping Out and Discarding Pages

1. Characteristics?
   1. When physical memory becomes scarce the Linux memory management subsystem must attempt to free physical pages. This task falls to the kernel swap daemon
   2. The kernel swap daemon is a special type of process, a kernel thread. Kernel threads are processes have no virtual memory, instead they run in kernel mode in the physical address space. The kernel swap daemon is slightly misnamed in that it does more than merely swap pages out to the system's swap files. Its role is make sure that there are enough free pages in the system to keep the memory management system operating efficiently.
2. How it works
   1. The Kernel swap daemon (kswapd) is started by the kernel init process at startup time and sits waiting for the kernel swap timer to periodically expire.
   2. Every time the timer expires, the swap daemon looks to see if the number of free pages in the system is getting too low. It uses two variables, free_pages_high and free_pages_low to decide if it should free some pages. So long as the number of free pages in the system remains above free_pages_high, the kernel swap daemon does nothing; it sleeps again until its timer next expires.
   3. If the number of free pages in the system has fallen below free_pages_high or worse still free_pages_low, the kernel swap daemon will try three ways to reduce the number of physical pages being used by the system:
      1. Reducing the size of the buffer and page caches
      2. Swapping out System V shared memory pages
      3. Swapping out and discarding pages
   4. After it has free sufficient pages, the swap daemon sleeps again until its timer expires. If the reason that the kernel swap daemon freed pages was that the number of free pages in the system had fallen below free_pages_low, it only sleeps for half its usual time. Once the number of free pages is more than free_pages_low the kernel swap daemon goes back to sleeping longer between checks.

## The Swap Cache

1. Operations?
   1. The pages held in the page and buffer caches are good candidates for being freed into the free_area vector. The Page Cache, which contains pages of memory mapped files, may contain unneccessary pages that are filling up the system's memory. Likewise the Buffer Cache, which contains buffers read from or being written to physical devices, may also contain unneeded buffers.
   2. Every time the Kernel swap daemon tries to shrink these caches, it examines a block of pages in the mem_map page vector to see if any can be discarded from physical memory.
   3. Pages are cached in the buffer cache (or rather the buffers within the pages are cached) to make buffer allocation and deallocation more efficient. The memory map shrinking code tries to free the buffers that are contained within the page being examined.
   4. If all the buffers are freed, then the pages that contain them are also be freed. If the examined page is in the Linux page cache, it is removed from the page cache and freed.

## Swapping Out System V Shared Memory Pages

1. Operations?
   1. System V shared memory is an inter-process communication mechanism which allows two or more processes to share virtual memory in order to pass information amongst themselves.
   2. Each area of System V shared memory is described by a shmid_ds data structure. This contains a pointer to a list of vm_area_struct data structures, one for each process sharing this area of virtual memory. The vm_area_struct data structures describe where in each processes virtual memory this area of System V shared memory goes. Each vm_area_struct data structure for this System V shared memory is linked together using the vm_next_shared and vm_prev_shared pointers. Each shmid_ds data structure also contains a list of page table entries each of which describes the physical page that a shared virtual page maps to.
   3. The kernel swap daemon also uses a clock algorithm when swapping out System V shared memory pages. Each time it runs it remembers which page of which shared virtual memory area it last swapped out. It does this by keeping two indices, the first is an index into the set of shmid_ds data structures, the second into the list of page table entries for this area of System V shared memory. This makes sure that it fairly victimizes the areas of System V shared memory.
