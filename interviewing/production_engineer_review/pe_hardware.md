# Abstract
This document covers hardware, CPU, 


# Introduction
An operating system has to work closely with the hardware system that acts as its foundations. The operating system needs certain services that can only be provided by the hardware.

# The CPU
1. What is?
    1. A microprocessor calculates, performs logical operations and manages data flows by reading instructions from memory and then executing them. 
    2. Microprocessors operate on binary data; that is data composed of ones and zeros.
2. Characteristics?
    1. Microprocessors can perform arithmetic operations such as add, multiply and divide and logical operations such as ``is X greater than Y?''.
    2. The processor's execution is governed by an external clock. This clock, the system clock, generates regular clock pulses to the processor and, at each clock pulse, the processor does some work.
        1. A 100Mhz processor will receive 100,000,000 clock ticks every second; it is misleading to describe the power of a CPU by its clock rate as different processors perform different amounts of work per clock tick.
    3.  The instructions executed by the processor are very simple; for example "read the contents of memory at location X into register Y". Registers are the microprocessor's internal storage, used for storing data and performing operations on it. The operations performed may cause the processor to stop what it is doing and jump to another instruction somewhere else in memory. 
        1.  These tiny building blocks give the modern microprocessor almost limitless power as it can execute millions or even billions of instructions a second.
    4.  Most processors have the following special purpose, dedicated, registers:
        1.  Program Counter (PC)
            1. This register contains the address of the next instruction to be executed. The contents of the PC are automatically incremented each time an instruction is fetched
        2. Stack Pointer (SP)
            1. Processors have to have access to large amounts of external read/write random access memory (RAM) which facilitates temporary storage of data. The stack is a way of easily saving and restoring temporary values in external memory. Usually, processors have special instructions which allow you to push values onto the stack and to pop them off again later. 
            2. The stack works on a last in first out (LIFO) basis. In other words, if you push two values, x and y, onto a stack and then pop a value off of the stack then you will get back the value of y. Some processor's stacks grow upwards towards the top of memory whilst others grow downwards towards the bottom, or base, of memory. Some processor's support both types, for example ARM.
        3. Processor Status (PS)
            1. Instructions may yield results; for example "is the content of register X greater than the content of register Y?" will yield true or false as a result. The PS register holds this and other information about the current state of the processor. For example, most processors have at least two modes of operation, kernel (or supervisor) and user. The PS register would hold information identifying the current mode.

# Memory
1. What is?
    1. All systems have a memory hierarchy with memory at different speeds and sizes at different points in the hierarchy. The fastest memory is known as cache memory and is what it sounds like - memory that is used to temporarily hold, or cache, contents of the main memory. This sort of memory is very fast but expensive, therefore most processors have a small amount of on-chip cache memory and more system based (on-board) cache memory. 
2. Characteristics?
    1. The cache and main memories must be kept in step (coherent). In other words, if a word of main memory is held in one or more locations in cache, then the system must make sure that the contents of cache and memory are the same. The job of cache coherency is done partially by the hardware and partially by the operating system. This is also true for a number of major system tasks where the hardware and software must cooperate closely to achieve their aims.

# Buses
1. What is?
    1. The individual components of the system board are interconnected by multiple connection systems known as buses.
2. Characteristics
    1. The system bus is divided into three logical functions; the address bus, the data bus and the control bus. 
        1. The address bus specifies the memory locations (addresses) for the data transfers. 
        2. The data bus holds the data transferred. The data bus is bidirectional; it allows data to be read into the CPU and written from the CPU. 
        3. The control bus contains various lines used to route timing and control signals throughout the system. Many flavours of bus exist, for example ISA and PCI buses are popular ways of connecting peripherals to the system.

# Controllers and Peripherals
1. What is?
    1. Peripherals are real devices, such as graphics cards or disks controlled by controller chips on the system board or on cards plugged into it. The IDE disks are controlled by the IDE controller chip and the SCSI disks by the SCSI disk controller chips and so on. 
    2. These controllers are connected to the CPU and to each other by a variety of buses.
    3. The controllers are processors like the CPU itself, they can be viewed as intelligent helpers to the CPU. The CPU is in overall control of the system.
2. Characteristics
    1. All controllers are different, but they usually have registers which control them. Software running on the CPU must be able to read and write those controlling registers. 
    2. One register might contain status describing an error. Another might be used for control purposes; changing the mode of the controller. 
    3. Each controller on a bus can be individually addressed by the CPU, this is so that the software device driver can write to its registers and thus control it. 

# Address Spaces
1. What is?
    1. The system bus connects the CPU with the main memory; it is separate from the buses connecting the CPU with the system's hardware peripherals. 
    2. Collectively the memory space that the hardware peripherals exist in is known as I/O space. I/O space may itself be further subdivided, but we will not worry too much about that for the moment. 
    3. The CPU can access both the system space memory and the I/O space memory, whereas the controllers themselves can only access system memory indirectly and then only with the help of the CPU. 
2. From the point of view of the device, say the floppy disk controller, it will see only the address space that its control registers are in (ISA), and not the system memory. Typically a CPU will have separate instructions for accessing the memory and I/O space. 
    1. For example, there might be an instruction that means ``read a byte from I/O address 0x3f0 into register X''. This is exactly how the CPU controls the system's hardware peripherals, by reading and writing to their registers in I/O space. Where in I/O space the common peripherals (IDE controller, serial port, floppy disk controller and so on) have their registers has been set by convention over the years as the PC architecture has developed. The I/O space address 0x3f0 just happens to be the address of one of the serial port's (COM1) control registers.

# Timers
1. What is?
    1. All OS need to know the time
    2. Modern PC includes a special peripheral called the Real Time Clock (RTC).
2. Characteristics
    1. A reliable time of day and an accurate timing interval. 
        1. The RTC has its own battery so that it continues to run even when the PC is not powered on, this is how your PC always ``knows'' the correct date and time. 
        2. The interval timer allows the operating system to accurately schedule essential work.