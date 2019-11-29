# Abstract

- This document explores debugger and compiler and their implementations

## Debugger

1. What is
   1. A debugger tool is a computer program that is used to test and debug other programs (the "target" program).
      1. The code to be examined might alternatively be running on an **Instruction set simulator (ISS), a technique that allows a great power in its ability to halt when specific conditions are encountered**, but which will typically be somewhat slower than executing the code directly on the appropriate( or the same) processor.
      2. Some debuggers offer two modes of operation, full or partial simulation, to limit this impact.
   2. A "trap" occurs when **the program cannot normally continue because of a programming bug or invalid data**.
      1. Ex. the program might have tried to use an instruction not available on the current version of the CPU or attempted to access unavailable or protected memory memory.
         1. When the program "traps" or reaches a preset condition, the debugger typically shows the location in the original code if it is a **source-level debugger or symbolic debugger, commonly now seen in a integrated development environment.** If it is a **low-level debugger or a machine-language debugger, it shows the line in the disassembly** (unless it also has online access to the original source code and can display the appropriate section of code from the assembly or compilation)
2. Features
   1. General features
      1. Debuggers offer a **query processor, symbol resolver, an expression interpreter, and a debug support interface at its top level**. It also offer more sophisticated functions such as running a program **step by step**, stopping(breaking) at some event or specified instruction by means of a breakpoint, and tracking the values of variables.
      2. Some debuggers have the ability to modify program state while it is running. It **may also be possible to continue execution at a different location in the program to bypass a crash or logical error**.
      3. Uses
         1. The same functionality that makes a debugger useful for eliminating bugs allows it to be **used as a software cracking tool to evade copy protection, digital rights management, and other software protection features**. It often also makes it useful as **general verification tool, fault coverage, and performance analyzer**, especially if instruction path lengths are shown.
      4. Main stream debugging engines
         1. Includes gdb, dbx
            1. Provides console-based command line interfaces. Debugger front-ends are popular extensions to debugger engines that provide IDE integration, program animation, and visualization features.
   2. Reverse debugging
      1. Known as "historical debugging" or "backwards debugging" makes it possible to step a program's execution backwards in time.
      2. Reverse debugging can slow down performance but **it is very useful for certain types of problems, but is still not commonly used yet**.
3. Language dependency
   1. **Some debugger operate on a single specific language while others can handle multiple languages transparently**.
      1. Ex. If the main target program is written in COBOL but calls assembly language subroutines and PL/1 subroutines, the debugger may have to dynamically switch modes to accommodate the changes in language as they occur.
4. Memory protection
   1. Some debugger also incorporate **memory protection to avoid storage violations such as buffer overflow. This may be extremely important in transaction processing environments** where memory is dynamically allocated from memory 'pools' on a task by task basis
5. Hardware support for debugging
   1. Most modern microprocessors have at least one of these features in their CPU design to make debugging easier
      1. Hardware support for **single-stepping a program, such as the trap flag.**
      2. **An instruction set that meets the Popek and Goldberg virtualization requirements makes it easier to write debugger software that runs on the same CPU as the software being debugged**; such a CPU can execute the inner loops of the program under test at full speed, and still remain under debugger control.
      3. **In-system programming allows an external hardware debugger to reprogram a system under test** (for example, adding or removing instruction breakpoints). Many systems with such ISP support also have other hardware debug support.
      4. **Hardware support for code and data breakpoints**, such as address comparators and data value comparators or, with considerably more work involved, page fault hardware.
      5. **JTAG access to hardware debug interfaces such as those on ARM architecture processors or using the Nexus command set.** Processors used in embedded systems typically have extensive JTAG debug support.
      6. **Micro controllers with as few as six pins need to use low pin-count substitutes for JTAG**, such as BDM, Spy-Bi-Wire, or debugWIRE on the Atmel AVR. DebugWIRE, for example, uses bidirectional signaling on the RESET pin.
