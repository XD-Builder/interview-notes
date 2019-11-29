## Background
1. A general-purpose, interpreted, interactive, OO, and high level programming language created by Guido van Rossum during 1985-1990. It's available under the GNU General Public License (GPL). It's named after a TV show called "Monty Python's Flying Circus". 
2. Python 3.0 was released in 2008 and is not backward incompatible.

## What's new in Python3
1. The __future__ module
   1. Python3's integer division behavior can be simulated by adding import statement
      1. from __future__ import division
2. The print Function
   1. print function must have parenthesis in Python3
3. Reading Input from Keyboard
   1. raw_input() is deprecated and the received data is always treated as string.
4. Integer Division
   1. Python3 evaluates 3/2 == 1.5 by default and Python2 results division to the nearest integer 3/2 == 1.
5. Unicode Representation
   1. Python3 stores strings as Unicode(utf-8) by default, and 2 byte classes, byte and byte arrays whereas Python2 mark a string with a u if you want to store it as Unicode
6. xrange() Function removed
   1. Python3 range() function is removed and xrange() has been renamed as range() and supports slicing whereas Python2 range() returns a list and xrange() returns an object that will only generate the items in the range when needed, saving memory.
7. Raise Exception
   1. Python2 accepts both notations, the 'old' and the 'new' syntax whereas Python3 requires parenthesis.
8. Arguments in Exceptions
   1. Python3 arguments to exception should be declared with 'as' keyword
      1. Ex. except Myerror as err
9.  next() Function and .next() method
   2. In Python2, next() is a method of generator object is allowed whereas it's discontinued in Python3. Use next() keyword in Python3
10. 2to3 Utility
    1.  Along with Python 3 interpreter, 2to3.py script reads Python2 source code and applies a series of fixers to transform it into a valid Python3 code.

## Basic Syntax
1. Identifier
   1. A name used to identify a variable, function, class, module, or other object. [A-Za-z_] followed by zero or more letters underscore and digits.
   2. It does not support @, $, and % within identifier
2. Reserved Words
   1. and, exec, not, as, finally, or, assert, for, pass, break, from, print, class, global, raise, continue, if, return, def, import, try, del, in, while, elif, is, with, else, lambda, yield, except
3. Lines and Indentation
   1. No support for braces for blocks of code used as a map constructor.
4. Multi-line statements
   1. Statements end with a new line and use continuation character (\) to denote that the line should continue. However, statements contianed within [], {}, () brackets do not need to use the line continuation characters.
5. Quotation
   1. It's okay to use single double and triple quotes.
6. Multiple statements on a single line
   1. Ex. improt sys; x = 'foo'; sys.stdout.write(..)
7. Multiple statement group as suites
   1. Group of individual statements which make a single code block. Header lines begin the statement and terminate with a colon and followed by one or more lines which make up the suite

## Variable Types
1. What is
   1. Reserved memory locations to store values and it happens every time you create a new variable. Based on the data type of a variable, the interpreter allocates memory and dedicates what can be stored in the reserved memory. You can assign different data types to the variables.
2. Assign variables
   1. No explicit variable declaration needed to reserve memory space.
3. Multiple Assignment
   1. a,b = 1, "john" # is allowed
4. Standard Data Types
   1. Numbers, string, list, tuple, dictionary
5. Numbers
   1. Three different python numerical types are int, float, and complex. The **del** keyword deletes the reference to a number object.
6. Strings
   1. A contiguous set of characters represented in the quotation mark. It allows either pair of single or double quotes and substring slicing operations.
7. Lists
   1. Most versatile, a list contains items separated by commas and enclosed within square brackets []. It allows slicing, indexing operation as well as concatenation and repeat via + or * operator.
8. Tuple
   1. Another sequence data type similar to list, enclosed in () parenthesis. Elements and size can't be changed.
9. Dictionary
   1.  Enclosed by curly braces {} and values can be assigned and accessed via []

## Notable Basic Operators
1. Logical Operator
   1. and => Logical AND
   2. or => Logical OR
   3. not => Logical NOT
2. Membership Operator
   1. in => variable in a set
   2. not in => variable not in a set
3. Identity Operator
   1. is => true if same object
   2. is not => vice versa
   
## Iterator and Generator
1. Iterator
   1. An object which allows a programmer to traverse through all the elements of a collection, regardless of a specific implementation
   2. It implements iter() and next() methods
2. Generator
   1. A function that produces or yields a sequence of values using yield method.
   2. When next() method is called for the first time the function starts executing  until it reaches the yield statement, which returns the yielded value.
      1. It keeps track of local variable for that function call until finally exit.

## Number
1. Number Type Conversion
   1. int(x), long(x), float(x), complex(x), complex(x,y)
2. Random Number Functions
   1. choice(seq), a random item from a list, tuple, string
   2. randrange(start, stop, step), a randomly selected element from a range
   3. random(), a random float, 0< f < 1
   4. seed([x]), sets the integer starting value used in generating random numbers.
   5. shuffle(lst), randomizes the items of a list in place.
      1. Useful if you want to randomly select out of a population.
   6. uniform(x,y), A random float r such that x < r < y

## Strings
1. Accessing Values in Strings
   1. Python does not support character type and each character are treated as strings of length one and thus considered a substring.
   2. Use the same list slicing syntax for string

## Lists
1. What is
   1. Most versatile data type.
2. Access and updating?
   1. Can be accessed via [] notation and set using [x] notation to the left side of assignment.
3. Deleting?
   1. use del statement if you know exact [x] or using .remove() method if you do not.
4. List functions
   1. list.count(obj) => return how many counts of an object
   2. list.reverse() => reverses objects in the list
   3. list.sort([func]) => sorts objects of list, use compare func if given.

## Dictionary
1. About Dictionary
   1. Each key is separated from its value by a colon (:), the items are separated by commas, and the whole thing is enclosed in curly braces. Empty dictionary is without any item {}.
   2. Keys are unique within a dictionary while values may not. Values of a dictionary can be of any type but the keys must be of an immutable data type such as strings, numbers, or tuples.
2. Accessing Values in Dictionary
   1. Accessing a value using bracket notation and if the elements is not within the dictionary then a key error will be thrown if accessed.
3. Deleting Dictionary Elements
   1. del dict[x] # deletes a specific element
   2. dict.clear() # clears all entries in dict
   3. del dict # delete entire dictionary.
4. Dict functions
   1. dict.update(dict2) => adds dict2 key-value pair to dict
   2. dict.values() => returns list of dict's values
   3. dict.keys() => returns list of dict's keys
   4. dict.items() => returns a list of dict's tuple pairs

## Date & Time
1. Intro
   1. Python can handle date and time in several ways. Converting between date formats is a common task and Python's time and calendar modules help track dates and times.
2. What is Tick?
   1. Time intervals are **floating numbers in units of seconds**. Particular instants in time are expressed in seconds since 12:00am, January 1, 1970(epoch)
   2. There is a popular time module in which provides functions.
      1. time.time() returns current system time in ticks since 12:00am, January 1, 1970(epoch)
3. TimeTuple
   1. Many of time module's functions handle time as a tuple of 9 numbers
      1. 0 => 4-digit year, 1,2,3,4,5 => Month, day, hour, minute and second
      2. 6,7,8 => Day of week, day of year, daylight savings
4. Getting formatted time
   1. time.asctime(time.localtime(time.time())) # returns asctime using localtime
5. Getting caldendar for a month
   1. calendar.month(2019, 2) # returns calendar for 2019 Feb.
6. Timezone
   1. time.timezone # returns timezone offset in seconds of the local time zone

## Functions
1. Intro
   1. A block of organized, reusable code that is used to perform a single, related action and provides better modularity.
2. Defining a Function
   1. Function blocks begin with the keyword def followed by the function name and parenthesis
   2. An input param should be placed within these parentheses.
   3. The first statement of a function can be an optional statement - the documentation string **docstring**
   4. The code block within every function starts with a colon (:) and is indented.
   5. The statement **return [expression]** exits a function, optionally passing back an expression to the caller.
3. Calling a Function
   1. Once the basic structure of a function is finalized, you can execute it by calling it from another function or directly from the Python prompt.
4. Pass by Reference vs Value
   1. All parameters are passed by reference. It means if you change what a parameter refers to within a function, the change also reflects back in the calling function.
5. Types of formal arguments
   1. Required Arguments
      1. Arguments passed to a function in correct positional order. The number of arguments in the function call should match exactly with the function definition.
   2. Keyword Arguments
      1. Arguments related to the function call. When you use keyword arguments in a function call, the caller identifies the arguments by the parameter name.
      2. Ex. def printme( str ); printme( str = "My string") # sets identifier value
   3. Default Arguments
      1. An argument that assumes a default value if a value is not provided in the function call for that argument.
      2. def printinfo( name, age = 35 )
   4. Variable-length Arguments
      1. You may need to process a function for more arguments than you specified while defining the function. These arguments are called variable-length arguments and are not named in the function definition, unlike required and default arguments.
      2. Asterisk (*) is placed before the variable name that holds the values of all nonkeyword variable arguments. The tuple remains empty if no additional arguments are specified during the function call.
      3. Ex. def printinfo( arg1, *vartuple ); printinfo( 70, 60, 50 ) # sets vartuple to (60, 50)
6. The anonymous functions
   1. Functions are called anonymous because they are not declared in the standard manner by using the def keyword.
   2. The **lambda** keyword is used to create small anonymous functions
      1. Lambda forms take any number of arguments but return just one value in the form of an expression. They cannot contain commands or multiple expressions.
      2. An anonymous function cannot be a direct call to print because lambda requires an expression.
      3. Lambda functions have their own local namespace and cannot access variables other than those in their parameter list and those in the global namespace.
      4. Although it appears that lambdas are a one-line version of a function, they are not equivalent to inline statements in C or C++, whose purpose is to stack allocation by passing function, during invocation for performance reasons.
   3. Ex. lambda [arg1 [,arg2,... argn]]:expression
7. The return statement
   1. exits a function optionally passing back an expression to the caller. A return statement with no arguments is the same as return None
8. Scope of Variables
   1. All variables in a program may not be accessible at all locations in that program.
   2. The scope of a variable determines the portion of a program where you can access a particular identifier. Two basic scopes are:
      1. Global variable and local variables
9. Global vs Local variables
   1. Variables defined inside a function body have a local scope and those outside have a global scope.

## Modules
1. Intro
   1. Module allows you to logically organize your Python code. Grouping related code into a module makes the code easier to understand and use.
   2. A module is a Python object with arbitrarily named attributes that you can bind and reference. Simply, it's a file consisting of Python code which defines functions, classes and variables.
2. The import statement
   1. Syntax
      1. import module1[, module2[,...moduleN]]
   2. When the interpreter encounters an import statement, it imports the module if the module is present in the search path, a list of directories that the interpreter searches before importing a module.
3. The from...import statement
   1. Lets you import specific attributes from a module into the current namespace.
   2. Syntax
      1. from modname import name1[,...nameN] # imports a specific name from a module
      2. from modname import * # imports all the names from a module into the current namespace
4. Executing Modules as Scripts
   1. Within a module, the module's name (as a string) is available as the value of the global variable `__name__`. The code in the module will be executed, just as if you imported, but with the `__name__` set to `__main__`.
5. Locating Modules
   1. When you import a module, the Python interpreter searches for the module in the following sequences
      1. The current directory
      2. If the module is not found, it searches each directory in the shell variable PYTHONPATH.
      3. If all else fails, Python checks the default path. On unix it's /usr/local/lib/python3/
6. Namespace and Scoping
   1. Variables are names that map to objects. A namespace is a dictionary of variable names (keys) and their corresponding objects (values)
      1. Python statement can access variables in a local namespace and in the global namespace but local namespace has higher precedence.
      2. Each function has its own local namespace. Class methods follow the same scoping rule as ordinary functions.
      3. Python makes educated guesses on whether variables are local or global. It assumes that any variable assigned a value in a function is local.
      4. Therefore, in order to assign a value to a global variable within a function, you must first use the global statement.
      5. The statement global VarName tells Python that VarName is a global variable. Python stops searching the local namespace for the variable.
      6. UnboundLocalError can happen when a local variable is accessed before setting it.
7. The dir() Function
   1. A built-in function returns a sorted list of strings containing the names defined by a module.
8. The globals() and locals() Functions
   1. The globals() and locals() functions can be used to return the names in the global and local namespaces depending on the location from where they are called.
      1. If locals() is called from within a function, it will return all the names that can be accessed locally from that function.
      2. If globals() called from within a function, it will return all the names that can be accessed globally from that function.
         1. The return type of both is dictionary and therefore names can be extracted using keys() function
9. The reload() Function
   1. When a module is imported into a script, the code in the top-level portion of a module is executed only once. To re-execute the top level code in a module, you can use the reload() function which imports a previously imported module again.
      1. reload(module_name)

## File I/O
1. Printing to the Screen
   1. print statement passes zero or more expressions separated by commas and the function converts the expressions into a string and writes the result to standard output
2. Reading Keyboard Input
   1. input Function reads data from keyboard as string irrespective of whether it is enclosed with quotes or not.
3. Opening and Closing Files
   1. open(file_name [, access_mode[,buffering]]]) 
      1. file_name - a string value that contains the name of the file that you want to access
      2. access_mode - determines the mode in which the file has to be opened, read, write, append, etc.
      3. buffering - if the buffering set to 0, no buffering takes place. if 1, line buffering is performed while accessing a file. If greater than 1, the buffering action is performed with the indicated buffer size. If negative, the buffer size is the system default.
4. The file Object Attributes
   1. Once a file is opened you have one file object which contains various information related to that file.
      1. file.closed - true if file is closed, false otherwise
      2. file.mode - returns access mode with which file was opened
      3. file.name - returns name of the file
5. Reading and Writing Files
   1. The write() method writes any string to an open file and it does not add a newline character ('\n') to the end of the string
   2. The **read([count])** method reads a string from an open file with number of bytes as param.
   3. The **read()** without count starts reading from the beginning of the file.
6. File Positions
   1. The **tell()** method tells you the current position within the file; in other words, the next read or write will occur at that many bytes from the beginning of the file
   2. The **seek(offset[, from])** method changes the current file position. The offset argument indicates the number of bytes to be moved. The **from** argument specifies the reference position from where the bytes are to be moved.
7. Renaming and Deleting Files
   1. os module provides method to perform file-processing operations, such as renaming and deleting files.
      1. os.rename(current_file_name, new_file_name)
      2. os.remove(file_name)
      3. os.mkdir("new_dir")
      4. os.chdir("new_working_dir")
      5. os.getcwd() # display current working directory
      6. os.rmdir("dir_to_be_removed")
      7. 