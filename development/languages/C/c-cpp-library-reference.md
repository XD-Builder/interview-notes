# Abstract

- This document lists C/C++ libraries and their functions

## C Library

1. About C Language Library
   1. The C++ library includes the **same definitions as the C language library** organized in the same structure of header files, with the following differences
      1. **Each header file has the same name as the C language version but with a "c" prefix and no extension**.
         1. Ex. C++ equivalent for the C language header file \<cstdlib.h\> is \<cstdlib\>
         2. **Every element of the library is defined within the std namespace**.
   2. The are also certain specific changes in the C++ implementation:
      1. **wchar_t, char16_t, char32_t and bool are fundamental types in C++ and therefore are not defined in the corresponding header where they appear in C**. The same applies to several macros in the header \<iso646.h\>, which are keywords in C++.
      2. The following functions have **changes in their declarations related to the constness of their parameters: strchr, strpbrk, strrchr, strstr, memchr.**
      3. **The functions atexit, exit and abort, defined in \<cstdlib\> have additions to their behavior in C++**.
      4. Overloaded versions of some functions are provided with additional types as parameters and the same semantics, like float and long double versions of the functions in the cmath header file, or long versions for abs and div.
2. Note on versions
   1. **C++98 includes the C library as described by the 1990 ISO C standard and its amendment #1 (ISO/IEC 9899:1990 and ISO/IEC 9899:1990/DAM 1)**.
   2. **C++11 includes the C library as described by the 1999 ISO C standard and its Technical Corrigenda 1, 2 and 3 (ISO/IEC 9899:1999 and ISO/IEC 9899:1999/Cor.1,2,3), plus \<cuchar\> (as by ISO/IEC 19769:2004)**.
   3. **Other introductions by the 2011 ISO C standard are not compatible with C++**.
3. Libraries
   1. \<cassert\> (assert.h)
      1. C Diagnostics Library
      2. assert.h defines **one macro functio**n that can be **used as a standard debugging tool**.
   2. \<cctype\> (ctype.h)
      1. Character handling functions
      2. This header declares **a set of functions to classify and transform individual characters**.
   3. \<cerrno\> (errno.h)
      1. C Errors
      2. C Header that defines the following macro
         1. errno, Last error number (macro )
   4. \<cfenv\> (fenv.h) - C++11
      1. Floating-point environment
      2. This header declares a set of functions and macros to **access the floating-point environment, along with specific types**.
      3. The **floating-point environment** maintains a series of status flags and specific control modes. Specific about the contents of the floating-point environment depend on the implementation, but the status flags generally include the floating-point exceptions and their associated information, and the control modes include at least the rounding direction.
   5. \<cfloat\> (float.h)
      1. Characteristics of floating-point types
      2. This header describes **the characteristics of floating types for the specific system and compiler implementation used**.
   6. \<cinttypes\> (inttypes.h) - C++11
      1. C integer types
      2. Header with library support for width-based integral types.
      3. Including this header automatically includes also \<cstdint\> (which defines width-based integral types).
   7. \<ciso646\> (iso646.h)
      1. ISO 646 Alternative operator spellings
      2. This header **defines eleven macro constants with alternative spellings for those C++ operators not supported by the ISO646 standard character set**
   8. \<climits\> (limits.h)
      1. Sizes of integral types
      2. This header defines constants with the limits of fundamental integral types for the specific system and compiler implementation used.
   9. \<clocale\> (locale.h)
      1. C localization library
      2. The C language supports **localization specific settings, such as culture-specific date formats or country-specific currency symbols**.
   10. \<cmath\> (math.h)
       1. C numerics library
       2. Header \<cmath\> declares **a set of functions to compute common mathematical operations and transformations**
   11. \<csetjmp\> (setjmp.h)
       1. Non local jumps
       2. The tools provided through this header file allow the programmer to **bypass the normal function call and return discipline, by providing the means to perform jumps preserving the calling environment**.
   12. \<csignal\> (signal.h)
       1. C library to handle signals
       2. Some running environments use **signals to inform running processes of certain events**. These events may be related to errors performed by the program code, like a wrong arithmetical operation or to exceptional situations, such as a request to interrupt the program.
       3. Signals generally represent situations where the program has either been requested to terminate or an unrecoverable error has happened, therefore handling a signal allows for either perform pre-termination cleanup operations or try to recover from the error in some way.
   13. \<cstdarg\> (stdarg.h)
       1. Variable arguments handling
       2. This header defines macros to access the individual arguments of a list of unnamed arguments whose number and types are not known to the called function.
       3. A function may **accept a varying number of additional arguments without corresponding parameter declarations by including a comma and three dots (,...) after its regular named parameters**
   14. \<cstdbool\> (stdbool.h) - C++11
       1. Boolean type
       2. The purpose in **C of this header is to add a bool type and the true and false values as macro definitions**.
       3. In C++, which supports those directly, the header simply contains a macro that can be used to check if the type is supported
   15. \<cstddef\> (stddef.h)
       1. C Standard definitions
       2. **This header defines several types implicitly generated or used by certain language expressions**.
   16. \<cstdint\> (stdint.h) - C++11
       1. Integer types
       2. This header **defines a set of integral type aliases with specific width requirements, along with macros specifying their limits and macro functions to create values of these types**.
   17. \<cstdio\> (stdio.h)
       1. C library to perform Input/Output operations
       2. Input and Output operations can also be performed in C++ using the C Standard Input and Output Library (cstdio, known as stdio.h in the C language). This library **uses what are called streams to operate with physical devices such as keyboards, printers, terminals or with any other type of files supported by the system. Streams are an abstraction to interact with these in an uniform way; All streams have similar properties independently of the individual characteristics of the physical media they are associated with**.
       3. Streams are handled in the cstdio library as **pointers to FILE objects**. A pointer to a FILE object **uniquely identifies a stream, and is used as a parameter in the operations involving that stream**.
       4. There also exist **three standard streams: stdin, stdout and stderr, which are automatically created and opened for all programs using the library**.
   18. \<cstdlib\> (stdlib.h)
       1. C Standard General Utilities Library
       2. This header **defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting**.
   19. \<cstring\> (string.h)
       1. C Strings
       2. This header file **defines several functions to manipulate C strings and arrays**.
   20. \<ctgmath\> (tgmath.h) - C++11
       1. Type-generic math
   21. \<ctime\> (time.h)
       1. C Time Library
       2. This header file contains definitions of functions to get and manipulate date and time information
   22. \<cuchar\> (uchar.h) - C++11
       1. Unicode characters
       2. This header provides **support for 16-bit and 32-bit characters, suitable to be encoded using UTF-16 and UTF-32**.
   23. \<cwchar\> (wchar.h)
       1. Wide characters
       2. This header file defines **several functions to work with C wide strings**.
   24. \<cwctype\> (wctype.h)
       1. Wide character type
       2. This header declares a set of functions to classify and transform individual wide characters.

## Containers

1. Background - Standard Containers
   1. A container is **a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements**.
   2. The container **manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers)**.
   3. Containers **replicate structures very commonly used in programming: dynamic arrays (vector), queues (queue), stacks (stack), heaps (priority_queue), linked lists (list), trees (set), associative arrays (map)...**
   4. **Many containers have several member functions in common, and share functionalities. The decision of which type of container to use for a specific need does not generally depend only on the functionality offered by the container, but also on the efficiency of some of its members (complexity)**. This is especially true for sequence containers, which offer different trade-offs in complexity between inserting/removing elements and accessing them.
   5. **stack, queue and priority_queue are implemented as container adaptors. Container adaptors are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes (such as deque or list) to handle the elements**. The underlying container is encapsulated in such a way that its elements are accessed by the members of the container adaptor independently of the underlying container class used.
2. Libraries
   1. \<array\> - C++11
      1. Header that defines the fixed-size array container class
   2. \<deque\>
      1. Header that defines the deque container class
   3. \<forward_list\> - C++11
      1. Header that defines the forward_list container class, a single-linked list
   4. \<list\>
      1. Header that defines the list container class, a doubly-linked list
   5. \<map\>
      1. Header that defines the map and multimap container classes.
      2. Multimap is a multi-key map, a combination of a key value and a mapped value
   6. \<queue\>
      1. Header that defines the queue and priority_queue container adaptor classes
   7. \<set\>
      1. Header that defines the set and multiset container classes
      2. multiset is a multi-key set
   8. \<stack\>
      1. Header that defines the stack container class
   9. \<unordered_map\> - C++11
      1. Header that defines the unordered_map and unordered_multimap container classes:
   10. \<unordered_set\> - C++11
       1. Header that defines the unordered_set and unordered_multiset container classes
   11. \<vector\>
       1. Header that defines the vector container class

## Input/Output

1. About
   1. The iostream library is an OO library that **provides input and output functionality using streams**
      1. A stream is an abstraction that represents a device on which input and output operations are performed. It can be represented as a source or destination of characters of indefinite length.
      2. Streams are generally **associated to a physical source or destination of characters, like a disk file, the keyboard, or the console, so the characters gotten or written to/from our abstraction called stream are physically input/output to the physical device**.
         1. For example, file streams are C++ objects to manipulate and interact with files; Once a file stream is used to open a file, any input or output operation performed on that stream is physically reflected in the file.
2. Operating with streams
   1. C++ provides the standard iostream library which contains
      1. Basic class template
         1. The base of the iostream library is the hierarchy of class templates. The class templates provide most of the functionality of the library in a type-independent fashion
      2. Class template instantiations
         1. The library incorporates two standard sets of instantiations of the entire iostream class template hierarchy: one is narrow-oriented, to manipulate elements of type **char** and another one, wide-oriented, to manipulate elements of type **wchar_t**.
      3. Standard Objects
         1. As part of the iostream library, the header file \<iostream\> declares certain objects that are used to perform input and output operations on the standard input and output. These include cin, cout,cerr and clog for narrow-oriented objects and wcin, wcout, wcerr and wclog for wide-oriented objects.
      4. Types
         1. The iostream classes barely use fundamental types on their member's prototypes. They generally use defined types that depend on the traits used in their instantiation.
      5. Manipulators
         1. Manipulators are **global functions designed to be used together with insertion (\<<) and extraction (\>>) operators performed on iostream stream objects**
3. Libraries
   1. \<fstream\>
      1. Header providing file stream classes
   2. \<iomanip\>
      1. Header providing parametric manipulators
      2. Examples like set field width, fill character, decimal precision, format flags, etc.
   3. \<ios\>
      1. Header providing base classes and types for the IOStream hierarchy of classes
   4. \<iosfwd\>
      1. Input-Output forward declarations
      2. This header provides forward declarations for the types of the standard input/output library.
   5. \<iostream\>
      1. Standard Input / Output Streams Library
      2. Header that defines the standard input/output stream objects
   6. \<istream\>
      1. Input stream
      2. Header providing the standard input and combined input/output stream classes
   7. \<ostream\>
      1. Output stream
      2. Header providing the standard output stream class
   8. \<sstream\>
      1. String streams
      2. Header providing string stream classes
   9. \<streambuf\>
      1. Stream buffer
      2. Header providing the streambuf buffer class, to be used in combination with input/output streams

## Multi-threading

1. About
   1. Atomic and thread support
   2. Support for atomics and threads
2. Libraries - C++11 only
   1. \<atomic\>
      1. Atomic types are types that encapsulate a value whose access is **guaranteed to not cause data races** and can be used to **synchronize memory accesses among different threads**.
      2. **This header declares two C++ classes, atomic and atomic_flag, that implement all the features of atomic types in self-contained classes**. The header also declares an entire set of C-style types and functions compatible with the atomic support in C.
   2. \<condition_variable\>
      1. Header that declares condition variable types
   3. \<future\>
      1. **Header with facilities that allow asynchronous access to values set by specific providers, possibly in a different thread**
      2. Each of these providers (which are either promise or packaged_task objects, or calls to async) share access to a shared state with a future object: **the point where the provider makes the shared state ready is synchronized with the point the future object accesses the shared state**
   4. \<mutex\>
      1. Header with facilities that allow **mutual exclusion (mutex) of concurrent execution of critical sections of code, allowing to explicitly avoid data races**.
   5. \<thread\>
      1. Header that declares the thread class and the this_thread namespace

## Other

1. About
   1. Standard Library - Miscellaneous headers
   2. Other headers part of the C++ standard library
2. Libraries
   1. \<algorithm\>
      1. The header \<algorithm\> defines **a collection of functions especially designed to be used on ranges of elements**.
      2. **A range is any sequence of objects that can be accessed through iterators or pointers, such as an array or an instance of some of the STL containers**. Notice though, that algorithms operate through iterators directly on the values, not affecting in any way the structure of any possible container (it **never affects the size or storage allocation** of the container)
   2. \<bitset\>
      1. Header that defines the bitset class
   3. \<chrono\> C++11
      1. chrono is the name of a header, but also of a sub-namespace: **All the elements in this header (except for the common_type specializations) are not defined directly under the std namespace (like most of the standard library) but under the std::chrono namespace**
      2. The elements in this header deal with time. This is done mainly by means of three concepts, duration, time points, and clocks.
   4. \<complex\>
      1. The complex library implements the complex class to contain complex numbers in cartesian form and several functions and overloads to operate with them:
   5. \<exception\>
      1. Standard exceptions
      2. This header defines the base class for all exceptions thrown by the elements of the standard library: exception, along with several types and utilities to assist handling exceptions.
   6. \<functional\>
      1. Function objects
      2. Function objects are objects specifically designed to be used with a syntax similar to that of functions. In C++, this is achieved by defining member function operator() in their class
   7. \<iterator\>
      1. An iterator is any object that, pointing to some element in a range of elements (such as an array or a container), has the ability to iterate through the elements of that range using a set of operators (with at least the increment (++) and dereference (*) operators).
   8. \<limits\>
      1. Numeric limits
      2. This header defines elements with the characteristics of arithmetic types. More specifically, it defines a numeric_limits class template and a specialization of it for each of the fundamental types
   9. \<memory\>
      1. This header defines general utilities to manage dynamic memory.
   10. \<new\>
       1. Dynamic memory
       2. This header describes functions used to manage dynamic storage in C++
   11. \<random\> - C++11
       1. The header introduces random number generation facilities.
       2. This library allows to produce random number using combinations of generators and distributions
   12. \<regex\> - C++11
       1. Regular Expressions
       2. The standard C++ library provides support for regular expressions in the \<regex\> header through a series of operations.
   13. \<string\>
       1. This header introduces string types, character traits and a set of converting functions
   14. \<tuple\>
       1. Tuples are objects that pack elements of -possibly- different types together in a single object, just like pair objects do for pairs of elements, but generalized for any number of elements
