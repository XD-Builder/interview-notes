# Abstract

- This document introduces commands related to filesystem and devices.

## mount

1. Background
   1. Used to mount a filesystem
   2. All files accessible in a Unix system are arranged in one big tree, the file hierarchy, rooted at / and these files can be spread out over several devices. The **mount command serves to attach the filesystem found on some device to the big file tree**. The umount command will detach it.
   3. The fs is used to control how data is stored on the device or provided in a virtual way by the network or another services.
2. Syntax
   1. mount [-l|-h-V]
      1. show labels in the mount output, help or version
   2. mount -a [-fFnrsvw][-t fstype] [-O optlist]
      1. mount all filesystem mentioned in fstab
   3. mount [-fnrsvw][-o options] device|dir
   4. mount [-fnrsvw][-t fstype] [-o options] device dir
3. System configuration and mounts
   1. The files /etc/fstab, /etc/mtab and /proc/mounts
      1. Ex. mount -a [-t type][-o optlist]
         1. **Causes all filesystem mentioned in fstab to be mounted** as indicated, except for those whose line contains the noauto keyword. Adding **-F option will make mount fork,** so that filesystems are mounted simultaneously.
   2. No-super usermounts
      1. Normally only the superuser can mount filesystems. However, when fstab contains the **user** option on a line, anybody can mount the corresponding filesystem.
         1. Ex. /dev/cdrom /cd iso9660 ro,user,noauto,unhide
            1. any user can mount the filesystem found on an inserted CDROM using the command
            2. mount /cd
   3. Other features worth looking into
      1. Bind mounts
      2. mount move operation
      3. Shared subtree operations
4. Use cases
   1. mount a specific device to a directory
      1. Ex mount -t type device dir
         1. Tells the kernel to attach the filesystem found on device at the directory dir. The -t option is optional but sets fs type for that mounted device.
   2. List the mounts
      1. Ex. mount -l -t ext4
      2. lists all mounted devices and filters it for fs type of ext4 to be displayed.
   3. Indicating the device and filesystem
      1. Ex. lsblk --fs
         1. provides an overview of filesystems, LABELS and UUIDs on available block devices.
      2. Ex. lsblk -p <device>
         1. provides details about a filesystem on the specific device
5. Filesystem-independent mount options
   1. Options
      1. async - All I/O to the fs should be asynchronously
      2. noatime - do not update inode access times on this filesystem. It works for all inode types including directory
      3. auto - can be mounted with -a option
      4. defaults - use default option, rw, suid, dev, exec, auto, nouser, and async
      5. dev - interpret character or block special devices on the filesystem
      6. exec - permit execution of binaries
      7. group - allow an ordinary user to mount the fs if one of that user's groups matches the group of the device.
      8. relatime - update inode access times relative to modify or change time. Access time is only updated if the previous access time was earlier than the current modify or change time.
      9. suit - allow set-user-id or set-group-id bits to take effect
      10. owner - allow an ordinary user to mount the filesystem if that user is the owner of the device.
6. Loop device
   1. A device that allows you to mount a file act as a block device. The file itself is an ordinary file.
   2. Ex. mount -o loop demo.img /mnt/DEMO/
      1. mounts the image file to a directory
7. Files
   1. /etc/fstab - filesystem table
   2. /etc/mtab - table of mounted filesystems
   3. /etc/filesystems - list of filesystem types of try
