# Abstract

This document covers devices and device drivers and their interaction with OS

## Intro

1. Linux supports three types of hardware device: character, block and network.
   1. Character devices are read and written directly without buffering.
   2. Block devices can only be written to and read from in multiples of the block size, typically 512 or 1024 bytes.
      1. They are accessed via the buffer cache and may be randomly accessed.
      2. Only a block device can support a mounted fs.
   3. Network devices are accessed via the BSD socket interface and the networking subsystems.
2. Common attributes of Linux kernel device drivers
   1. Kernel code => They are part of the kernel
   2. Kernel interfaces => They must provide a standard interface to the kernel
   3. Kernel mechanisms and services => Makes use of standard kernel services such as memory allocation, interrupt delivery and wait queues to operate
   4. Loadable => They can be loaded on demand as kernel modules when they are needed and unloaded when no longer used. This is efficient for sys resources
   5. Dynamic => Doesn't cause harm if device being controller by a particular driver does not exist.

## Polling and Interrupt

1. Why polling and interrupt?
   1. Each time a device is given a command to run, the driver has two ways to find out if that command is done. It can poll the device or use interrupts.
2. What is polling?
   1. The act of reading device status registry every so often until the device's status changes to indicate that it has completed the request.
   2. Polling by means of timers is at best approximate. Interrupts are much more efficient.
3. What is Interrupt?
   1. An interrupt driven device driver is one where the hardware device being controlled will raise a hardware interrupt whenever it needs to be serviced.
      1. An ethernet device driver would interrupt whenever it receives an ethernet packet from the network.
      2. Linux kernel needs to be able to deliver the interrupt from the hardware device to the correct device driver. Done by the device driver registering its usage of the interrupt with the kernel.
      3. It registers the address of an interrupt handling routine and the interrupt number that it wishes to own.
   2. Interrupts are located at /proc/interrupts
      1. The requesting of interrupt resources is done at driver initialization time.
         1. Some of the interrupts in the system are fixed. Ex. floppy disk controller always uses interrupt 6
         2. Other interrupts are allocated at boot time. Ex. Interrupts from PCI devices
      2. Device drivers must first discover the interrupt number (IRQ) of the device that it is controlling before it requests ownership of that interrupt. For PCI interrupts, Linux supports standard PCI BIOS callbacks to determine information about the devices in the system, including their IRQ numbers.
   3. How an interrupt is delivered to the CPU?
      1. Architecture dependent, most is delivered in a special mode that stops other interrupts from happening in the system.
      2. A device driver should do as little possible in its interrupt handling routine so that the kernel can dismiss the interrupt and return to what it was doing before it was interrupted.
      3. Device drivers that need to do a lot of work as a result of receiving an interrupt can use the kernel's bottom half handlers or task queues to queue routines to be called later on.

## Direct Memory Access (DMA)

1. Problem?
   1. Interrupt driven device drivers transfer data to or from hardware devices works well only when the amount of data is reasonably low.
   2. 9600 baud modem can transfer approximately one character every millisecond.
2. What is?
   1. A DMA controller allows devices to transfer data to or from the system's memory without the intervention of the processor(CPU).
   2. DMA controller has 8 DMA channels of which 7 are available for use for use by the device drivers.
   3. Each DMA channel has associated with it a 16 bit address register and a 16 bit count register. To initiate a data transfer the device driver sets up the DMA channel's address and count registers together with the direction of the data transfer, read or write. It then tells the device that it may start the DMA when it wishes. When the transfer is complete the device interrupts the PC. Whilst the transfer is taking place the CPU is free to do other things.
3. What to think about?

   1. Device drivers have to be careful when using DMA. First of all the DMA controller knows nothing of virtual memory, it only has access to the physical memory in the system. Therefore the memory that is being DMA'd to or from must be a contiguous block of physical memory. This means that you cannot DMA directly into the virtual address space of a process. You can however lock the process's physical pages into memory, preventing them from being swapped out to the swap device during a DMA operation. Secondly, the DMA controller cannot access the whole of physical memory. The DMA channel's address register represents the first 16 bits of the DMA address, the next 8 bits come from the page register. This means that DMA requests are limited to the bottom 16 Mbytes of memory.
   2. Linux tracks the usage of the DMA channels using a vector of dma_chan data structures (one per DMA channel). The dma_chan data structure contains just two fields, a pointer to a string describing the owner of the DMA channel and a flag indicating if the DMA channel is allocated or not. It is this vector of dma_chan data structures that is printed when you cat /proc/dma.

## Memory

1. Device drivers have to be careful when using memory


## GPT vs MBR

1. Abstract
   1. MBR(Master Boot Record) and GPT (GUID Partition Table) are two different ways of storing the partitioning information on a drive. This information includes where partitions start and begin so your OS knows which sectors belong to each partition and which partition is bootable. Thus you have to choose one of them before creating partitions on a drive.
2. MBR's Limitations
   1. Definition & Characteristics
      1. It is a special boot sector located at the beginning of a drive.
      2. The sector contains a boot loader for the installed OS and information about the drive's logical partitions.
      3. The boot loader is a small bit of code that loads the larger boot loader from another partition on a drive.
   2. Limits
      1. It works with disks up to 2TB in size but not more.
      2. It only supports up to four primary partitions and if you want more you have to make one of your primary partitions an "extended partition" and create logical partitions inside it.
3. GPT's Advantages
   1. Definition & Characteristics
      1. Stands for GUID Partition Table, a new standard that's gradually replacing MBR.
      2. It's associated with UEFI (a replacement for BIOS), and GPT replaces the clunky old MBR partitioning system with what's called GUID partition Table.
         1. GPT means every partition on your drive has a "globally unique identifier", a random string so long that every GPT partition on earth likely has its own unique identifier
   2. Benefits
      1. The system doesn't have MBR limits.
      2. Drives can be much larger and sie limits will depend on OS and fs. GPT allows for nearly unlimited amount of partitions, and the limit here will be your OS. Windows allows up to 128 partitions on a GPT drive without having to create an extended partition
4. MBR vs GPT
   1. Critical data store
      1. On MBR disk, the partitioning and boot data is stored in one place and if this data is overwritten or corrupted, you're done.
      2. In contrast, GPT stores multiple copies of this data across the disk, so it's much more robust and can recover if the data is corrupted.
   2. Data integrity
      1. GPT also stores cyclic redundancy check (CRC) values to check that its data is intact. If the data is corrupted, GPT can notice the problem and attempt to recover the damaged data from another location on the disk.
      2. MBR has no way of knowing if its data was corrupted - you'd only see there was a problem when the boot process failed or your drive's partitions vanished.

## How ISO image is burned into a disk?
