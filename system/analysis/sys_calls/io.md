# Abstract

- This document explains syscalls related to device IO

## ioctl

1. Background
   1. Abbrev. for Control device
   2. Manipulates the underlying device parameters of special files. In particular, **many operating characteristics of character special files (e.g., terminals) may be controlled with ioctl() requests**.
      1. The second argument of this syscall is a device-dependent request code.
      2. The third argument is an untyped pointer to memory traditionally char _argp (before void _ was valid C)
   3. Macros specifying an ioctl request are located in the file <sys/ioctl.h>
   4. Return Value => on success zero is returned. On error, -1 is returned and errno is set appropriately
2. Conforming to standards?
   1. No single standard. Arguments, returns, and semantics of ioctl() vary according to the device driver in question.
3. Syntax
   1. #include <sys/ioctl.h>
   2. int ioctl(int fd, unsigned long request, ...);
