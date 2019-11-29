# C Lang

## Overview

1. What is C?
   1. A general-purpose, imperative computer programming language
   2. Developed in 1972 by Dennis M. Ritchie at the Bell Telephone Laboratories to develop the UNIX OS.
   3. Most widely used computer language
2. Widely used because
   1. It's easy to learn, structured language which produces efficient programs and can handle low-level activities and compiled on a variety of compute platforms
3. Facts about C
   1. Invented to write an OS called UNIX
   2. A successor of B language introduced around the early 1970s
   3. Formalized in 1988 by ANSI
   4. UNIX OS was written in C.
   5. Most widely used and popular System Programming Language
   6. Most of the state-of-the-art software have been implemented using C.
   7. Most popular Linux OS and RDBMS MySQL have been written in C
4. Why use C?
   1. Initially used for system development but was adopted as system development language because it produces code that runs nearly as fast as the code written in assembly language.
   2. Use of C includes OS, language compilers, assemblers, text editors, print spoolers, network drivers, modern programs, databases, language interpreters, utilities.

## Environment

1. What do you need?
   1. To develop in C, you need a text editor and a C compiler
1. C Compiler
   1. The source code written in human readable source for your program and it needs to be "compiled" into machine language so that your CPU can actually execute the program as per the instruction given.
   2. The most frequently used and free available compiler is the GNU C/C++ compiler.

## Program Structure

1. C program parts
   1. Preprocessor Commands
   2. Functions
   3. Variables
   4. Statements & Expressions
   5. Comments

## Syntax

1. Tokens in C
   1. A C program consists of various tokens
   2. A token is either a keyword, an identifier, a constant, a string literal, or a symbol
   3. Tokens of printf("hello, world");
      1. printf, (, "hello, world", ), ;
   4. Comments
      1. like helping text and are ignored by the compiler and starts with /_ ends with _/
   5. Identifiers
      1. Name used to identify a variable, function, or any other user-defined item.
      2. Starts with letter A to Z, a to z, or an underscore '\_' followed by zero or more letters, underscores, and digits
      3. Case sensitive
   6. Keywords
      1. Reserved words in C and may not be used as constants or variables or any other identifier names
   7. White space
      1. Ignored by C compiler

## Data Types

1. Types
   1. Basic Types
      1. Arithmetic types and are further classified into (a) integer types and (b) floating point types
   2. Enumerated Types
      1. They are again arithmetic types and they are used to define variables that can only assign certain discrete integer values throughout the program
   3. The type void
      1. The type specifier void indicates that no value available
   4. Derived types
      1. They include (a) Pointer types, (b) Array types, (c) Structure types, (d) Union types and (e) Function types
2. Integer types
   1. ((un)signed) char, (unsigned) (int, short, long).
   2. **sizeof(type)** operator yields the storage size of the object or type in bytes.
3. Floating-Point Types
   1. float 4 byte, 6 decimal places
   2. double 8 byte, 15 decimal places
   3. long double, 10 byte, 19 decimal places

## The void Type

1. The void type specifies that no value is available. It is used in three kinds of situations
   1. Function returns as void
      1. There are various functions in C which do not return any value or you can say they return void. A function with no return value has the return type as void.
      2. Ex. void exit(int status);
   2. Function arguments as void
      1. There are various functions in C which do not accept any parameter. A function with no parameter can accept a void.
      2. Ex. int rand(void);
   3. Pointers to void
      1. A pointer of type void \* represents the address of an object, but not its type.
      2. Ex. \*malloc(size_t size); // returns a pointer to void which can be casted to any data type.

## Variables

1. What is a variable
   1. Nothing but a name given to a storage area that our programs can manipulate.
      1. Each variable in C has a specific type, which determines the size and layout of the variable's memory.
      2. The range of values that can be stored within that memory.
      3. The set of operations that can be applied to the variable.
2. Types
   1. char => typically a single octet, an integer type
   2. int => the most natural size of integer for the machine
   3. float => a single-precision floating point value
   4. double => a double-precision floating point value.
   5. void => represents the absence of type
3. Variable definition
   1. Tells compiler **where and how much storage to create** for the variable. It specifies a data type and contains a list of one or more variables of the type as
      1. type variable_list;
         1. **type** must be a valid C data type including char, w_char, int float, double, bool or any user-defined object; and variable_list may consist of one or more identifer names separated by commas.
4. Variable Declaration
   1. Provides assurance to the compiler that there **exists** a variable with the given type and name so that the compiler can proceed to further compilation without requiring the complete detail about the variable.
   2. Has meaning at the time of compilation only, the compiler needs actual variable definition at the time of linking the program.
   3. It's useful when you are using multiple files and you define your variable in one of the files which will be available at the time of linking of the program.
      1. Use keyword **extern** to declare a variable at any place. Though you can declare a variable multiple times in your C program, it can be defined only once in a file, a function, or a block of code.
5. Lvalues and Rvalues in C
   1. lvalue => expressions that refer to a memory location are called "lvalue" expressions. An lvalue may appear as either the left-hand or right-hand side of an assignment.
   2. rvalue => The term rvalue refers to a data value that is stored at some address in memory. An rvalue is an expression that cannot have a value assigned to it which means an rvalue may appear on the right-hand side but not on the left-hand side of an assignment.
   3. Ex.
      1. int g = 20; // valid as lvalue g, variable memory reference is on the left side, and 20, data value that is stored in memory on the right side
      2. 10 = 20; // invalid because 10, lvalue, or a data value can't be assigned another value because it's not a variable memory reference.

## Constants & Literals

1. What is Constants & literals
   1. Fixed values of a program cannot be altered during its execution.
   2. Can be of any basic data types
   3. Treated just like regular variables except their values cannot be modified after their definition
2. Integer Literals
   1. An integer literal can be a decimal, octal, or hexadecimal constant which can be distinguished by the prefix. Ex. 0x for hex, 0 for octal, and nothing for decimal
   2. Integer literal suffix is a combination of U and L for unsigned and long respectively.
   3. Ex. 30l, 30ul, 0213
3. Floating-point literals
   1. Has an integer part, a decimal point, a fractional part, and an exponent part and it can be represented either in decimal or exponential form.
   2. You must include the decimal point, the exponent or both while you represent decimal form and the **signed exponent is introduced by e or E**
   3. Ex. 3.14159, 314159E-5L
4. Character Constants
   1. Enclosed in a single quotes, like 'x' stored in a simple variable char type.
5. String Literals
   1. Constants are enclosed in double quotes "". A string contains characters that are similar to character literals, plain characters, escape sequence, and universal characters.
6. How to define constants
   1. #define preprocessor
      1. #define identifier value // defines a constant using preprocessor.
   2. const
      1. const type variable = value; // declare and initialize constants with specific type.

## Storage Class

1. What is?
   1. Defines the **scope(visibility) and life-time** of **variable** and/or functions within a C program.
   2. Storage classes in C program include auto, register, static, extern
2. The auto Storage Class
   1. The default storage class for all local variables
   2. Ex. auto int month; // can only used within functions
3. Register Storage Class
   1. Used to define local variables that should be stored in a register instead of RAM. This means that the variable has maximum size equal to the register size(usually one word) and can't have the unary '&' operator applied to it because it doesn't have a memory location.
   2. Ex. register int miles; // should only be used for variables that require quick access such as counters.
4. The static Storage Class
   1. Instructs the compiler to keep a local variable in existence during the life-time of the program instead of creating and destroying it each time it comes into and goes out of scope. Therefore, making local variable static allows them to maintain their values between function calls.
   2. The static modifier can be applied to global variables and this causes that variable's scope to be restricted to the file in which it is declared.
   3. In C, when static is used on a global variable, it causes **only one copy of that member** to be shard by all the objects of its class.
   4. A local static variable is initialized once at the time of declaration only and is not accessible by other files using extern keyword
5. The extern Storage Class
   1. Used to give a reference of a global variable that is visible to ALL the program files. When you use 'extern', the variable cannot be initialized however, it points the variable name at a storage location that has been previously defined.
      1. It is used to declare a global variable or function in another file.
      2. It is commonly used when there are two or more files sharing the same global variables or functions.

## Operator

1. What is?
   1. A symbol that tells the compiler to perform specific mathematical or logical functions.
   2. C lang provides following types of operators - arithmetic, relational, logical, bitwise, assignment and miscellaneous operators.
2. Miscellaneous Operators
   1. sizeof() => returns the size of a variable
   2. & => returns the address of a variable
   3. \* => pointer to a variable
   4. ? : => conditional expression
3. Operator Precedence
   1. Posfix > Unary > Multiplicative > Additive > Shift > Relational > Equality, Bitwise AND, OR > Logical AND, OR > Conditional > Assignment > Comma

## Decision Making

1. What is
   1. A structure that the programmer specifies one or more conditions to be evaluated and tested by the program, along with a statement or statements to be executed if the condition is determined to be true, and optionally, other statements to be executed if the condition is determined to be false.
2. What is true?
   1. Any non-zero and non-null values are true and else false.
3. Decision Statements
   1. if statement, if..else statement, nested if statements, switch statement, nested switch statement.

## Loops

1. What is
   1. A statement that allows us to execute a statement or a group of statements multiple times.
2. Looping Statements
   1. while loop, for loop, do..while loop, nested loops
3. Loop Control Statements
   1. break statement, terminates the loop or switch statement and transfers execution to the statement immediately following the loop or switch.
   2. continue statement, causes the loop to skip the remainder of its body and immediately retest its condition prior to reiterating.
   3. goto statement, transfers control to the labeled statement
4. Infinite Loop
   1. A loop becomes an infinite loop if a condition never becomes false. The for loop is traditionally used for this purpose since none of the three expressions that form the 'for' loop are required, you can make an endless loop by leaving the conditional expression empty.
   2. Ex. for (; ;) // When the conditional expression is absent, it is assumed to be true.

## Functions

1. What is
   1. A group of statements that together perform a task. Every C program has at least one function called main() and all the most trivial programs can define additional functions.
   2. Codes are divided up into separate functions.
      1. A **function declaration** tells the compiler about a **function's name**, return type, and parameters. A **function definition** provides the **actual body of the function**
      2. The C standard library provides numerous built-in functions that your program can call to manipulate strings and memory, etc.
   3. It's also referred to as a method or a sub-routine or a procedure, etc.
2. Declaration
   1. Ex. return_type function_name(parameter list) { body of the function }
   2. Declaration tells the compiler about a function name and how to call the function. The body of a function can be defined separately.
3. Function Calling
   1. When a function calls a function, the program control is transferred to the called function. A called function performs a defined task and when its return statement is executed or when its function-ending closing brace is reached, it returns the program control back to the main program.
4. Function Arguments
   1. If a function is to use arguments, it must declare variables that accept the values of the arguments. These variables are called the formal parameters of the function and they behave like other local variables inside the function and are created upon entry into the function and destroyed upon exit.
   2. Arguments can be passed by
      1. Call by value
         1. The method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.
      2. Call by reference
         1. The method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.
   3. C uses pass by value.

## Scope Rules

1. What is
   1. A scope in any programming is a region of the program where a defined variable can have its existence and beyond that, it cannot be accessed. There are three places where variables can be declared in C
      1. Inside a function or a block which is called local variable
      2. Outside of all functions which is called global variables
      3. In the definition of function parameters which are called formal parameters.
2. Local Variables
   1. Variables that are declared inside a function or block and they can be used only by statements that are inside that function or block of code.
3. Global Variables
   1. Defined outside a function, usually on top of the program. It holds value throughout the lifetime of your program and they can be accessed inside any of the functions defined for the program.
   2. Can be accessed by any function.
4. Initializing local and global variables
   1. When **a local variable is defined**, it is **not initialized** by the system, you must initialize it yourself. Global variables are initialized automatically by the system when you define them.
   2. Global variables default initialization data type and initial default value map
      1. int => 0, char => '\0', float => 0, double => 0, pointer => NULL

## Arrays

1. What is
   1. A kind of data structure that can store fixed-size sequential collection of elements of the same type.
2. Declaring Arrays
   1. type arrayName [ arraySize ];
      1. arraySize must be an integer constant greater than zero and type can be any valid C data type.
      2. Ex. double balance[10]
3. Initializing Arrays
   1. double balance[5] = {1000.0, 2.0, 3.4, 7.0}
      1. Declares and initializes variable with size of 5 and defined with data in {}.
   2. double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
      1. Declares and initializes variables with size of the variable defined in {} and defined with data in {}.
4. Pointer to an Array in C
   1. An array name is a constant pointer to the first element of the array
   2. It is legal to use array names as constant pointers, and vice versa.

## Pointers

1. Why Pointers
   1. Some C programming tasks are performed more easily with pointers, and other tasks, such as dynamic memory allocation, **cannot be performed without using pointers**.
   2. Every variable is a memory location and every memory location has its address defined which can be accessed using ampersand (&) operator, which denotes an address in memory.
2. What is Pointer
   1. Pointer is a variable whose value is the address of another variable.
      1. type \*var-name;
         1. type is the pointer's base type and must be a valid C data type
         2. var-name is the name of the pointer variable.
         3. Asterisk is used to declare a pointer.
3. How to use pointers
   1. define a pointer variable
   2. assign the address of a variable to a pointer
   3. finally access the value at the address available in the pointer variable using asterisk
4. NULL Pointer
   1. A pointer that is assigned NULL is called a null pointer and is a constant with a value of zero defined in several standard libraries.
      1. In most of OS, programs are not permitted to access memory at address 0 because that memory is reserved by the OS. However, the memory address 0 has special significance; it signals that the pointer is not intended to point to an accessible memory location.
      2. By convention, if a pointer contains the null (zero) value, it is assumed to point to nothing.
5. Pointer to a pointer
   1. Can be defined with \*_ stars instead of single _.
   2. Value must be accessed via double \*.
6. Return pointer from functions in C
   1. Declare function like int \* function1(){..}
   2. It is not a good idea to return the address of a local variable outside the function, so you have to define the local variable as static variable

## Strings

1. What is
   1. One dimensional array of characters terminated by a null character '\0'. Thus a string contains the characters that comprise the string followed by a null
   2. Declaration and initialization in the following creates the word "Hello"
      1. char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
      2. char greeting[] = "Hello";
         1. Here the last null character is created by C compiler automatically and placed at the end of the string when it initializes the array

## Structures

1. What is
   1. Arrays allow to define type of variables that can hold several data items of the same kind. Similarly structure is another user defined data type available in C that allows to combine data items of different kinds.
2. Defining a Structure
   1. struct [structure tag] { member def; ...} [one or more structure variables];
      1. The only way to define a structure is to use a struct statement.
      2. structure tag is optional
      3. Each member definition is a normal variable definition.
      4. At the end of the structure's definition, before the final semicolon, you can define one or more structure variables but it is optional.
      5. Example
         1. struct Books { char title[50]; char author[50], char subject[100]; int book_id;} book;
3. Accessing Structure Members
   1. Use the (.) to access any member of a structure. The (.) must be between the structure variable name and the structure member to be accessed.
   2. Declare a variable
      1. struct Books book1;
   3. Access a variable
      1. book1.title;
4. Miscellaneous
   1. Structures as a function argument
      1. void printBook( struct Books book );
   2. Pointer to Structures
      1. void printBook( struct Books \*book );
         1. book->title;
      2. printBook( &Book1 );
   3. Bit Fields
      1. Allows the packing of data in a structure especially useful when memory or data storage is at a premium. Typical examples include
         1. Packing several objects into a machine word. e.g. 1 bit flags can be compacted.
         2. Reading external file format -- non-standard file formats could be read in, .e.g., 9-bit integers.
      2. C allows us to do this in a structure definition by putting :bit length after the variable.
         1. struct packed_struct { unsigned int f1:1; unsigned int f2:1;unsigned int f3:1; unsigned int f4:1; unsigned int type:4; unsigned int my_int:9;}
            1. Here the packed_struct contains 6 members, four 1 bit flags f1..f3, a 4-bit type and a 9-bit my_int.
            2. C automatically packs the above bit fields as compactly as possible, provided that the maximum length of the field is than or equal to the integer word length of the computer. If this is not the case, then some compilers may allow memory overlap for the fields while other would store the next field in the next word.
      3. Syntax
         1. struct { type [member_name] : width ; };
            1. type -> An integer type that determines how a bit-field's value is interpreted. can be int, signed int, or unsigned int
            2. member_name -> the name of the bit-field
            3. width -> the number of bits in the bit-field. The width must be less than or equal to the bit width of the specified type.
      4. Ex.
         1. struct { unsigned int widthValidated; unsigned int heightValidated; } status1;
         2. struct { unsigned int widthValidated : 1; unsigned int heightValidated : 1; } status2;
            1. printf( "Memory size occupied by status1 : %d\n", sizeof(status1)); // print 8
            2. printf( "Memory size occupied by status2 : %d\n", sizeof(status2)); // print 4
      5. Ex Error.
         1. struct { unsigned int age : 3; } Age; // def age to use 3 bits only
         2. printf( "Sizeof( Age ) : %d\n", sizeof(Age) ); // size is 4 for Age
         3. Age.age = 4; // value will be 4
         4. Age.age = 8; // value will be 0 because only 3 bit allowed and it **won't overflow other bit fields**.

## Union

1. What is
   1. A special data type available in C that allows to store different data types in the same memory location.
   2. Though you can define a union with many members, but only one member can contain a value at any given time. Union provide an efficient way of using the same memory location for multiple-purpose.
2. Defining a union
   1. union [union tag] { member definition;.. } [one or more union variables];
      1. union tag is optional and each member definition.
      2. At the end of the union's definition, before the final semicolon, you can specify one or more union variables but it is optional.
      3. All of its members are stored in the same memory location and can be used to store multiple types of data.
      4. The memory occupied by union will be large enough to hold the largest member of the union.
      5. Example
         1. union Data { int i; float f; char str[20]} data;
         2. printf("%d", sizeof(data)); // this prints 20 because the largest member defined above.
3. Accessing Union Members
   1. Dot notation is used to access a member of a union.
   2. When setting variables inside one union member and getting value of another, the second variable will be evaluated using the bits set by the first variable.
   3. However, if setting individual variable and evaluating it immediately will always get the desired bits and thus evaluated correctly.

## typedef

1. What is
   1. A language keyword used to give a type a new name.
   2. Ex - built-in data types.
      1. typedef unsigned char BYTE; // This defines the a type called BYTE for one-byte numbers
      2. BYTE b1, b2; // BYTE used as an data type that's an abbreviation for the type unsigned char
   3. Ex - user-defined data types;
      1. typedef struct Books { char title[50]; char author[50]; char subject[100]; int book_id; } Book; // type Book now is an abbreviation for type Books.
1. typedef vs #define
   1. #define is a C-directive which is also used to define the aliases for various data types similar to typedef but with the following differences
      1. typedef is limited to giving symbolic names to types only whereas #define can be used to define alias for values as well, you can define 1 as ONE etc..
      2. typedef interpretation is performed by the compiler whereas #define statements are processed by the pre-processor.
   2. Ex. #define
      1. #define TRUE 1
      2. #define FALSE 0
      3. printf( "Value of TRUE : %d\n", TRUE); // 1
      4. printf( "Value of FALSE : %d\n", FALSE); // 0

## Input and Output

1. Input
   1. Feed some data into a program, given in the form of a file or from the command line.
   2. C provides a set of built-in functions to read the given input and feed it to the program as per requirement.
2. Output
   1. Display some data on screen, printer, or in any file.
   2. C provides a set of built-in functions to output the data on the screen as well as to save it in text or binary files
3. The standard files
   1. C treats **all the devices as files** so devices such as the display are **addressed in the same way as files** and the following three files are **automatically opened when a program executes** to **provide access to the keyboard and screen**.
      1. Standard input - fp (stdin) - device (keyboard)
      2. Standard output - fp (stdout) - device (screen)
      3. Standard error - fp (stderr) - device (screen)
4. The getchar() and putchar() functions
   1. int getchar(void)
      1. reads the next available character from the screen and returns it as an integer. It reads only one single character at a time. This method can be used in loop if more character read needed.
   2. int putchar(int c)
      1. puts the passed character on the screen and returns the same character.
5. The gets() and puts() functions
   1. char *gets(char *s)
      1. reads a line from stdin into the buffer pointed to by s until either a terminating newline or EOF.
   2. int puts(const char \*s)
      1. writes the string 's' and a trailing newline to the stdout.
6. The scanf() and printf() functions
   1. int scanf(const char \*format, ...)
      1. reads the input from the standard input stream stdin and scans that input according to the format provided.
      2. stops reading as soon as a space is encountered.
   2. int printf(const char \*format, ...)
      1. writes the output to the standard output stream stdout and produces the output according to the format provided.
         1. The format can be %s, %d, %c, %f, etc..

## File I/O

1. What is
   1. Defines how to create, open, close text or binary files for their data storage.
   2. A file represents a sequence of bytes, regardless of it being a text file or a binary file.
   3. File I/O provides high level functions as well as low level OS calls to handle file on your storage devices.
2. Opening files
   1. FILE _fopen( const char _ filename, const char \* mode );
      1. creates a new file or open an existing file.
      2. Initializes an object of the type FILE, which contains all the information necessary to control the stream.
      3. Mode can be read, write, append, r+ for reading and writing, w+ for reading and writing but t**runcates the file to zero length if exists** else creates new file, a+ for reading and writing and creates new file if not exist and **reading will start from the beginning** but **writing can only be appended**.
      4. for binary files, add "b" to the mode. Ex. "rb, wb, r+b"
3. Closing a file
   1. int fclose( FILE \*fp );
      1. returns zero on success or EOF if there is an error in closing the file.
      2. flushes any data pending in the buffer to the file, closes the file, and releases any memory used for the file.
      3. EOF is a constant defined in the header file stdio.h
      4. There are various functions provided by C standard library to read and write a file, character by character, or in the form of a fixed length string.
4. Writing a file
   1. int fputc(int c, FILE \*fp);
      1. writes the character value of the argument c to the output stream referenced by fp.
      2. It returns the written character on success or EOF if an error.
   2. int fputs(const char * s, FILE *fp );
      1. writes the string s to the output stream referenced by fp.
      2. returns a non-negative value on success, EOF in case of any error.
      3. int fprintf(FILE *fp, cont char *format, ...)
         1. This also writes a string into a file.
5. Reading a file
   1. int fgetc(FILE \*fp);
      1. reads a character from the input file referenced by fp. The return value is the character read, or in case of any error, it returns EOF.
   2. int *fgets(char *buf, int n, FILE \*fp);
      1. reads up to n-1 characters from the input stream referenced by fp. It copies the read string into the buffer buf, appending a null character to terminate the string.
      2. If this function encounters a newline character '\n' or the end of the file EOF before they have read the maximum number of characters, then it returns only the characters read up to the point including the new line character.
   3. int fscanf(FILE *fp, const char *format, ...)
      1. reads strings from a file but stops reading after encountering the first space character.
6. Binary I/O functions
   1. There are two functions that can be used for binary input and ouput
      1. size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
      2. size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
         1. Both functions are used to read/write blocks of memories usually arrays or structures.

## Pre-processors

1.  What is
    1. Not a part of the compiler but is a separate step in the compilation process.
    2. A text substitution tool and it instructs the compiler to do required pre-processing before the actual compilation.
    3. Referred to as C Preprocessor or CPP
    4. **All preprocessor commands begin with a hash symbol (#)**. It must be the first non-blank character, and for readability, a pre-processor directive should begin in the first column.
2.  Directives & Description
    1. #define => substitutes a preprocessor macro
    2. #include => inserts a particular header from another file
    3. #undef => undefines a preprocessor macro
    4. #ifdef => returns true if this macro is defined
    5. #ifndef => returns true if this macro is not defined
    6. #if => tests if a compile time condition is true
    7. #else => the alternative of #if
    8. #elif => #else and #if in one statement.
    9. #endif => ends preprocessor conditional
    10. #error => prints error message on stderr
    11. #pragma => issues special commands to the compiler, using a standardized method.
3.  Ex.
    1.  #define MAX_ARRAY_LENGTH 20
        1. tells CPP to replace instances of MAX_ARRAY_LENGTH with 20.
    2.  #include <stdio.h>
        1. tells CPP to get stdio.h from System Libraries and add the text to the current source file.
    3.  #include "myheader.h"
        1. tells CPP to get myheader.h from the local directory and add the content to the current source file.
    4.  #undef FILE_SIZE
    5.  #define FILE_SIZE 42
        1. tells CPP to undefine existing FILE_SIZE and define it as 42
    6.  #ifndef MESSAGE
    7.      #define MESSAGE "You wish!"
    8.  #endif
        1. tells CPP to define MESSAGE only if MESSAGE isn't already defined
    9.  #ifdef DEBUG
    10.     /* debugging statements */
    11. #endif
        1. tells CPP to process the statement enclosed if DEBUG is defined
        2. if -DDEBUG flag is passed to gcc compiler at the time of compilation, this will define DEBUG and you can debug on and off on the fly during compilation.
4.  Predefined Macros
    1. ANSI C defines a number of macros and are available for use in programming but the predefined macros should not be directly modified. They are:
       1. **DATE** => The current date as a character literal in "MMM DD YYYY" format
       2. **TIME** => The current time as a character literal in "HH:MM:SS" format
       3. **FILE** => This contains the current filename as a string literal.
       4. **LINE** => This contains the current line number as a decimal constant
       5. **STDC** => Defined as 1 when the compiler complies with the ANSI standard
5.  Processor Operators
    1.  The Macro Continuation forward slash Operator (\\).
        1. The macro normally confined to a single line but continuation operator is used to continue a macro that is too long for a single line
        2. #define message_for(a,b) \
           1. printf(#a " and " #b ": we love you!\n")
    2.  The Stringize (#) Operator
        1. The stringize or number-sign operator ('#') when used within a macro definition, converts a macro parameter into a string constant.
    3.  The Token Pasting (##) Operator
        1. combines two arguments. It permits two separate tokens in the macro definition to be joined into a single token.
        2. #define tokenpaster(n) printf ("token" #n " = %d", token##n)
           1. tokenpaster(34);
              1. This executes printf ("token" #n " = %d", token34);
    4.  Defined() Operator
        1.  The preprocessor defined operator is used in constant expressions to determine if an identifier is defined using #define.
            1. If the specified identifier is defined, the value is true (non-zero).
            2. If the symbol is not defined, the value is false (zero).
        2.  The defined operator is specified as
        3.  #if !defined (MESSAGE)
        4.      #define MESSAGE "You wish!"
        5.  #endif
            1. After this define statement, MESSAGE constant will be defined
6.  Parameterized Macros
    1. One of the powerful functions of the CPP is the ability to simulate functions using parameterized macros.
       1. int square(int x) { return x \* x; }
          1. can be re-written as #define square(x) ((x) \* (x))
             1. Macros with arguments must be defined using the #define directive before they can be used. The argument list is enclosed in parentheses and must immediately follow the macro name.
             2. Spaces are not allowed between the macro name and open parenthesis for macro name definition.
       2. Ex.
          1. #define MAX(x,y) ((x) > (y) ? (x) : (y))

## Header Files

1. What is
   1. A file with extension .h which contains C function declarations and macro definitions to be shared between several source files.
   2. Two types of header files
      1. The files that the programmer writes
      2. The files that comes with your compiler.
         1. You request to use a header file in your program by including it with the **C preprocessing directive #include**, like you have seen inclusion of stdio.h header file, which **comes along with your compiler**.
   3. Including a header file
      1. **equivalent to copying the content of the header file**
      2. But it is **error-prone to copy the content of a header file in the source files**, especially if we have multiple source files in a program.
      3. A simple practice in C/C++ programs is that we keep all the constants, macros, system wide global variables, and function prototypes in the header files and include that header file wherever it is required.
   4. Include Syntax
      1. #include <file>
         1. This form is used for system header files. It searches for a file named 'file' in a standard list of system directories. You can prepend directories to this list with the -I option while compiling the source code.
      2. #include "file"
         1. This form is used for header files of your own program. It searches for a file named 'file' in the directory containing the current file. You can prepend directories to this list with the -I option while compiling the source code.
2. Include Operation
   1. #include directive works by directing the C preprocessor to scan the specified file as input before continuing with the rest of the current source file.
      1. The **output from the preprocessor** contains the **output already generated**, followed by **the output resulting from the included file**, followed by the **output that comes from the text after the #include directive**.
   2. Ex.
      1. char \*test (void); // "header.h" file
      2. int x; #include "header.h" int main (void) { puts (test ()); }
      3. int x; char \*test (void); int main (void) { puts (test ()); } // after preprocessing.
3. Once-Only Headers
   1. If a header file happens to be included twice, the **compiler will process its contents twice and it will result in an error**. The standard way to prevent this is to enclose the entire real contents of the file in a conditional like
      1. #ifndef HEADER_FILE #define HEADER_FILE the entire header file file #endif
         1. This construct is commonly known as a wrapper #ifndef.
         2. When the header is included again, the conditional will be false because it's defined. The preprocessor will skip over the entire contents of the file, and the compiler will not see it twice.
4. Computed Includes
   1. Sometimes it is necessary to **select one of the several different header files** to be included into your program. For instance, they might specify **configuration parameters to be used on different sorts of OS**.
   2. Ex.
      1. #if SYSTEM_1 # include "system_1.h" #elif SYSTEM_2 # include "system_2.h" #elif SYSTEM_3 ... #endif
   3. But as conditionals grow, it becomes tedious.
      1. Computed include is that instead of writing a header name as the direct argument of #include, you simply put a macro name there
         1. #define SYSTEM_H "system_1.h"
         2. #include SYSTEM_H
            1. The SYSTEM_H could be defined by your Makefile with a -D option.

## Type Casting

1. What is
   1. A way to convert a variable from one data type to another data type
      1. If you want to store a 'long' value into a simple integer then you can type cast 'long' to 'int'.
2. Cast operator
   1. (type_name) expression
   2. Ex. int sum =17, count =5; double mean = (double) sum / count;
      1. Type conversion can be implicit which is performed by the compiler automatically, or it can be specified explicitly through the use of the cast operator. It's always good to use cast operator when necessary.
3. Integer Promotion
   1. The process by which **values of integer type "smaller" than int or unsigned int are converted either to int or unsigned int**.
   2. Ex. int i = 17; char c = 'c'; /_ ascii value is 99 _/ int sum; sum = i + c;
      1. here character c is promoted by compiler to be an int for addition.
4. Usual Arithmetic Conversion
   1. Implicitly performed to cast their values to a common type.
      1. The **compiler first performs integer promotion**; if the operands still have different types, then they are converted to the type that appears highest in the hierarchy below
         1. int -> unsigned int -> long -> unsigned long -> long long -> unsigned long long -> float -> double -> long double
   2. Ex.
      1. int i = 17; char c = 'c'; /_ ascii value is 99 _/ float sum; sum = i + c;
         1. Here char c is first converted into a integer because the other operand is an integer
         2. Compiler converts both c and i into float type because the finally value is float
         3. The compiler compiles the addition and returns a float.

## Error Handling

1. Intro
   1. C does not provide direct support for error handling but being a system programming language, it provides you access at lower level in the form of return values.
   2. Most of the C or even Unix function calls return **-1 or NULL** in case of any error and set an error code **errno** as a global variable and indicates an error occurred during any function call.
      1. Various error codes are defined in <error.h> header file
      2. Thus a C program can check the returned values and take appropriate action depending on the return value. It's a good practice to set errno to 0 at the time of initializing a program, 0 indicating there is no error.
2. errno, perror(), and strerror()
   1. perror() and strerr() are used to display the text message associated with an errno.
      1. perror() displays the string you pass to it, followed by a colon, a space, then the textual representation of the current errno value.
      2. strerror() returns a pointer to the textual representation of the current errno value.

## Recursion

1. What is
   1. The process of repeating items in a self-similar way.
   2. If a program allows you to call a function inside the same function, then it is called a recursive call of the function
   3. Things to think about?
      1. Careful to define an exit condition from the function or it will go an infinite loop.
      2. Very useful to solve many mathematical problems.

## Variable Arguments

1. Intro
   1. Sometimes you want to have a function which can take variable number of arguments. C provides that feature.
2. How it works
   2. how to start - steps
      1. Define a function with its last parameter as ellipses and the one just before the ellipses always an int which will represent the number of arguments.
      2. Create a va_list type variable in the function definition. This type is defined in the stdarg.h header file
      3. **Use int parameter and va_start macro to initialize the va_list variable** to an argument list. The macro va_start is defined in the stdarg.h header file.
      4. use va_arg macro and va_list variable to access each item in argument list.
      5. Use a macro va_end to clean up the memory assgiend to va_list variable.
   3. Ex.
      1. #include <stdio.h> #include <stdarg.h>
      2. double average(int num,...) { va_list valist; double sum = 0.0; int i; /_ initialize valist for num number of arguments _/ va_start(valist, num); /_ access all the arguments assigned to valist _/ for (i = 0; i < num; i++) { sum += va_arg(valist, int); } /_ clean memory reserved for valist _/ va_end(valist); return sum/num; }

## Memory Management

1. Intro
   1. C provides several functions for memory allocation and management and they are defined in the <stdlib.h> header file.
   2. Ex.
      1. void \*calloc(int num, int size);
         1. Allocates an array of **num** elements each of which wil have **size** bytes
      2. void free(void \*address);
         1. Releases a block of memory block specified by address.
      3. void \*malloc(int num);
         1. Allocates an anarray of **num** bytes and leave them uninitialized.
      4. void *realloc(void *address, int newsize);
         1. Re-allocates memory extending it upto **newsize**
2. Allocating Memory Dynamically
   1. When to use?
      1. If you are aware of the size of an array, then it is easy to define an array with a specific size like - char name[100];
      2. However, if you have no idea about the length of the text you need to store, you need to define a pointer to character without defining how much memory is required and during runtime, you can decide how much memory to allocate.
   2. Calloc vs Malloc
      1. Use calloc when you don't know the underlying system's size of a specific type but you need say 100 integer type storage space.
      2. Use Malloc when you are sure exactly how many bytes you want to store something very specific to your own specific usage.
3. Resizing and Releasing Memory
   1. **When you program comes out, OS automatically release all the memory allocated by your program**
      1. But as a good practice when you are not in need of memory anymore you should release that memory by calling the function free();
   2. You can increase or decrease the size of an allocated memory block by calling the function realloc();

## Command Line Arguments

1. Intro
   1. It is possible to pass some values from the CLI to your C program when they are executed. These values are called CLI arguments and many times are important for your program.
   2. The CLI arguments are handled using main() function arguments where **argc** refers to the number of arguments passed, and argv[] is a pointer array which points to each argument passed to the program.
2. How to pass arguments
   1. CLI arguments are passed by separating them using a space. If argument itself has a space then you can pass such arguments by putting them inside double quotes or single quotes.
   2. argv[0]
      1. holds the name of the program itself
