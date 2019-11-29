# Abstract

1. This document provides information on how to debug application level performance issues in Java, Python, and C++

# What are application-level performance issues

1. Application performance management (APM)
   1. The monitoring and management of performance and availability of software applications.
   2. Strives to detect and diagnose complex application perf problems to maintain an expected level of service.
   3. It has dimensions:
      1. End User Experience (Primary)
      2. Runtime Application Architecture
      3. Business Transactions (Primary)
      4. Deep Dive Component Monitoring
      5. Analytics/Reporting (Primary)

# What are troubleshooting tools for debugging application-level performance issues or bubs

1. Application agnostic profilers
   1. `perf`
      1. perf record -p <pid>
         1. records perf data
      2. perf report -stdio
         1. analyze recorded data
2. Language-specific profiler
   1. Java
      1. Standard JVM Profilers
         1. Tracks every detail of the JVM such as CPU, thread, memory, garbage collection, etc
         2. Tools like
            1. VisualVM, JProfiler, YourKit, Java Mission Control
               1. Allows method, thread profiling and debugging, etc...
               2. Allows finding out memory leaks, classes/objects, CPU usage, etc..
         3. Cons of JVM Profilers
            1. Slows down your application.
      2. Lightweight profilers that highlights app with abstraction
         1. Tools
            1. XRebel and Stackify
         2. Injects instrumentation code into your application.
         3. Aspect Profilers use AOP to inject code into the start and end of specified methods. The injected code can start a timer and then report the elapsed time when the method finishes.
      3. APM tools used for monitoring applications live in production environments
         1. Tools like
            1. New Relic, AppDynamics, Stackify Retrace, Dynatrace
         2. Expensive but good for production performance
   2. Python
      1. (c)profile
         1. deterministic profiling Python programs
         2. A profile is a set of statistics that describes how often and for how long various parts of the program executed. These statistics can be formatted into reports via the pstats module.
