# Abstract
* This document explores fundamentals of Java language

## JNI
1. Why JNI
    1. Though famous for its strength in its portability, we do actually ned to use code that's natively-compiled for a specific architecture
    2. Reasons for needing to use native code can be the need to handle some hardware, performance improvement for a very demanding process, an existing library that we want to reuse instead of rewriting it in Java.
    3. JNI in Java acts as a bridge between the bytecode running in our JVM and the native code (written in C or C++)
2. Native Methods
    1. "native" keyword in Java is used to indicate that the method implementation will be provided by a native code.
    2. Two options for making a native executable program.
        1. Static libs
            1. All library binaries will be included as part of our executable during the linking process. Thus, we won't ned the libs anymore, but it will increase the size of our executable file.
        2. Shared libs
            1. The final executable only has references to the libs, not the code itself. It requires that the environment in which we run our executable has access to all the files of the libs used by our program.
            2. This is used in JNI because we can't mix bytecode and natively compiled code into the same binary file.
            3. Our shared lib will keep the native code separately within its .so/.dll/dylib file depending on OS **instead of being part of our class**
    3. Native keyword transforms our method into a sort of abstract method
        1. private native void aNativeMethod()
            1. With the main difference that instead of being implemented by another Java class, it will be implemented in a separated native shared library.
            2. A table with pointers in memory to the implementation of all of our native methods will be constructed so they can be called from our Java code.
3. Required Componenets
    1. Java Code => Will include at least one native method
    2. Native Code => The actual logic of our native method usually in C/C++
    3. JNI header file => The header file for C/C++ (include jni.h into the JDK directory) includes all definitions of JNI elements that we may use into our native programs
    4. C/C++ Compiler => Choose between GCC, Clang, VS, or any other as far as it's able to generate native shared library for the target platform.
4. JNI Elements in Code
    1. Java
        1. "native" keyword => any method marked as native must be implemented in a native, shared lib.
        2. "System.loadLibrary(String libname) => A static method that loads a shared library from the file system into memory and makes its exported funtions available for Java code.
    2. C/C++ elements (many of them defined within jni.h)
        1. JNIEXPORT => Marks the function into the shared lib as exportable so it will be included in the function table, and thus JNI can find it
        2. JNICALL => combined with JNIEXPORT, it ensures that our methods are available for the JNI framework
        3. JNIEnv => A structure containing methods that we can use our native code to access Java elements.
        4. JavaVM => A structure that lets us manipulate a running JVM (or even start a new one), adding threads to it, destroying it, etc.
