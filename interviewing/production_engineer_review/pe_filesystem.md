# Abstract
This document covers Extended File System, Virtual File System, Buffer Cache, /proc File System and Device Special Files

# Features
1. One of the most important features of Linux is its support for many different file systems. This makes it very flexible and well able to coexist with many other operating systems. Separate file systems the system may use are not accessed by device identifiers (such as a drive number or a drive name) but instead they are combined into a single hierarchical tree structure that represents the file system as one whole single entity. Linux adds each new file system into this single file system tree as it is mounted. All file systems, of whatever type, are mounted onto a directory and the files of the mounted file system cover up the existing contents of that directory. This directory is known as the mount directory or mount point. When the file system is unmounted, the mount directory's own files are once again revealed.

# Characteristics
1. Disk is initialized with logical partitions with each holding a single file system.
2. File systems organize files into logical hierarchical structures with directories, soft links and so on held in blocks on physical devices.
3. Devices that can contain file systems are known as block devices. The IDE disk partition /dev/hda1, the first partition of the first IDE disk drive in the system, is a block device.The Linux file systems regard these block devices as simply linear collections of blocks, they do not know or care about the underlying physical disk's geometry. 
4. It is the task of each block device driver to map a request to read a particular block of its device into terms meaningful to its device; the particular track, sector and cylinder of its hard disk where the block is kept. A file system has to look, feel and operate in the same way no matter what device is holding it.
5. Moreover, using Linux's file systems, it does not matter (at least to the system user) that these different file systems are on different physical media controlled by different hardware controllers. The file system might not even be on the local system, it could just as well be a disk remotely mounted over a network link.
6. Virtual File System (VFS) allows Linux to support many, often very different, file systems, each presenting a common software interface to the VFS.


## The Second Extended File system (EXT2)
1. What is?
    1. EXT2 is devised as an extensible and powerful file system for Linux
    2. Built on the premise that the data held in files is kept in data blocks all of the same length. Every file's size is rounded up to an integral number of blocks.
        1. If block size is 1024 bytes, then a file of 1025 bytes will occupy two 1024 byte blocks.
    3. Not all of the blocks in the file system hold data, some must be used to contain the information that describes the structure of the file system.
        1. EXT2 defines the file system topology by describing each file in the system with an inode data structure which describes in which blocks the data within a file occupies as well as the access rights of the file, the file's modification times and the type of the file.
    4. Every file in the EXT2 file system is described by a single inode and each inode has a single unique number identifying it. The inodes for the file system are all kept together in inode tables. 
    5. EXT2 directories are simply special files (themselves described by inodes) which contain pointers to the inodes of their directory entries.
    6. A file system does not need to concern itself with where on the physical media a block should be put, that is the job of the device's driver. Whenever a file system needs to read information or data from the block device containing it, it requests that its supporting device driver reads an integral number of blocks. The EXT2 file system divides the logical partition that it occupies into Block Groups. Each group duplicates information critical to the integrity of the file system as well as holding real files and directories as blocks of information and data.  
   
### EXT2 Inode 
1. Intro
    1. EXT2 inodes for each Block Group are kept in the inode table together with a bitmap that allows the system to keep track of allocated and unallocated inodes
2. Struct Fields
    * **mode**
        * holds two piece of information. what this inode describes(file,directory, symlink, block device, character device or FIFO) and the permissions that users have to it.
    * **Owner Information**
        * The user and group identifiers of the owners of this file or directory. This allows the file system to correctly allow the right sort of accesses.
    * **Size**
        * The size of the file in bytes
    * **Timestamps**
        * The time that the inode was created and the last time that it was modified
    * **Datablocks**
        * Pointers to the blocks that contain the data that this inode is describing. The first twelve are pointers to the physical blocks containing the data described by this inode and the last three pointers contain more and more levels of indirection.
            * For example, the double indirect blocks pointer points at a block of pointers to blocks of pointers to data blocks. This means that files less than or equal to twelve data blocks in length are more quickly accessed than larger files.

### EXT2 Superblock
1. Intro
    1. Contains description of the basic size and shape of this file system. It allows the file system manager to use and maintain the file system. Usually only the Superblock in Block Group 0 is read when the file system is mounted but each Block Group contains a duplicate copy in case of file system corruption.
2. Struct Fields
    * **Magic Number**
        * This allows the mounting software to check that this is indeed the Superblock for an EXT2 file system.
    * **Revision Level**
        * The major and minor revision levels allow the mounting code to determine whether or not this file system supports features that are only available in particular revisions of the file system. There are also feature compatibility fields which help the mounting code to determine which new features can safely be used on this file system.
    * **Mount Count and Maximum Mount Count**
        * Together these allow the system to determine if the file system should be fully checked. The mount count is incremented each time the file system is mounted and when it equals the maximum mount count the warning message `maxmial mount count reached, running e2fsck is recommended" is displayed.
    * **Block Group Number**
        * The Block Group number that holds this copy of the Superblock
    * **Block Size**
        * The size of the block for this file system in bytes, ex. 1024 bytes
    * **Blocks per Group**
        * The number of blocks in a group. 
    * Free Blocks
        * The number of free blocks in the file system
    * Free Inodes
        * The number of free Inodes in the file system
    * First Inode
        * The inode number of the first inode in the file system.
        * The first inode in an EXT2 root file system would be the directory entry for the '/' directory

### EXT2 Group Descriptor
1. Intro
    1. Each Block Group has a data structure describing it. Like the Superblock, all the group descriptors for all of the Block Groups are duplicated in each Block Group in case of file system corruption.
    2. The group descriptors are placed on after another and together they make the group descriptor table. Each Blocks Group contains the entire table of group descriptors after its copy of the Superblock. Only the first copy (in Block Group 0) is actually used by the EXT2 file system. The other copies are there, like the copies of the Superblock, in case the main copy is corrupted.
2. Struct Fields
    * **Blocks Bitmap**
        * The block number of the block allocation bitmap for this Block Group. This is used during block allocation and deallocation
    * **Inode Bitmap**
        * The block number of the inode allocation bitmap for this Block Group. This is used during inode allocation and deallocation
    * **Inode Table**
        * The block number of the starting block for the inode table for this Block Group. Each inode is represented by the EXT2 inode data structure
    * **Free blocks count, Free Inodes count, Used directory count**

### EXT2 Directories
1. Intro
    1. Directories are special files that are used to create and hold access paths to the files in the file system. 
    2. The first two entries for every directory are always the standard '.' and '..' entries meaning 'this directory' and 'the parent directory' respectively.
2. Struct Fields
    * **Inode**
        * The inode for this directory entry. An index into the array of inodes held in the Inode Table of the Block Group.
    * **name length**
        * The length of this directory entry in bytes
    * **name**
        * The name of this directory entry

### How Linux finds a file in an EXT2 File System
1. Intro
    1. Linux does not care about the format of the filename itself; it can be any length and consist of any of the printable characters. To find the inode representing the file within an EXT2 file system the system must **parse the filename a directory at a time** until we get to the file itself.
2. How does it work under the hood?
    1. The first inode we need is the inode for **the root** of the file system and we find its number in the **file system's superblock**. To read an EXT2 inode we must look for it in the **inode table** of the appropriate **Block Group**.
        1. Ex. the root inode number if is 42, then we need the 42nd inode from the inode table of Block Group 0.
        2. The root inode is for an EXT2 directory, in other words the mode of the root inode describes it as a directory and its data blocks contain EXT2 directory entries.
    2. "/home" is just one of the many directory entries and this directory entry gives us the number of the inode describing the "/home" directory.
    3. We read this directory by first reading its inode and then reading the directory entries from the data blocks described by its inode to find the "rusling" entry which gives the number of inode describing "/home/rusling" directory.
    4. Finally we read the directory entries pointed at by the inode describing the "/home/rusling" directory to find the inode number of the .cshrc file and from this we get the data blocks containing the information in the file.


## The Virtual File System (VFS)
1. Introduction
    1. VFS manages all of the different file systems that are mounted at any given time and it does this by maintaining data structures that describe the whole virtual file system and the real, mounted, filesystems.
2. Characteristics
    1. Its data structure is similar to physical filesystem
    2. Each file system registers itself with VFS as it's initialized. This happens at boot time. FS modules are loaded as needed.
        1. If VFAT fs is implemented as kernel module, it is only loaded when a VFAT fs is mounted
        2. When a block device based fs is mounted, including root fs, the VFS must read its superblocks. Each fs type's superblock read routine must work out the fs' topology and map that info onto a VFS superblock data structure.
        3. The VFS keeps a list of the mounted fs in the system together with their VFS superblocks. Each of which contains info and pointers to routines that perform particular functions and the VFS superblock contains a pointer to the first VFS inode on the fs, which in a root fs, represents the '/' directory.
    3. As the sys's processes access dirs and files, sys routines are called that traverse the VFS inodes in the sys.
        1. `ls, cat`  commands causes the VFS to search through VFS inodes that represent the fs. Frequently accessed VFS inode will be stored in inode cache.

### Registering the FS
1. How it works?
    1. When the Linux kernel is built, the fs startup code contains calls to initialization routines of all of the built in fs.
    2. Fs can also be built as modules and they may be demand loaded as they are needed or loaded by hand using insmod. Whenever it's loaded it registers itself with the kernel and unregisters itself when it's unloaded.
    3. Each fs initialization routine registers itself with the VFS and is represented by file_system_type data structure which contains the name of the fs and a pointer to its VFS superblock read routine.

### Mounting a FS
1. How it works
    1. When a super user attempts to mount a fs, the Linux kernel must first validate the arguments passed in the sys call.
        1. Ex. mount -t iso9660 -o ro /dev/cdrom /mnt/cdrom
            1. Kernel matches fs type
                1. This mount command will pass the kernel three pieces of information; the name of the file system, the physical block device that contains the file system and, thirdly, where in the existing file system topology the new file system is to be mounted.
                2. The kernel searches through VFS to find the fs. If a matching fs type supported it knows the address of the fs specific routine for reading this fs superblock. If not, then all is not lost if the kernel is built to demand load kernel modules.
            2. Mounting the fs
                1. If physical device passed by mount is not already mounted, it must find the VFS inode of the directory that is to be the new fs mount point.
                2. At this point the VFS mount code must allocate a VFS superblock and pass it the mount information to the superblock read routine for this file system. All of the system's VFS superblocks are kept in the super_blocks vector of super_block data structures and one must be allocated for this mount. 
                3. Each mounted fs is described by a vfsmount data structure and queued on a list pointed at by vfsmntlist

### Finding a File in VFS
1. How it works
    1. VFS must resolve the name a directory a time, looking up the VFS inode presenting each of the intermediate directories in the name.
    2. Each directory lookup involves calling the file system specific lookup whose address is held in the VFS inode representing the parent directory. This works because we always have the VFS inode of the root of each file system available and pointed at by the VFS superblock for that system. 
    3. Each time an inode is looked up by the real file system it checks the directory cache for the directory. If there is no entry in the directory cache, the real file system gets the VFS inode either from the underlying file system or from the inode cache. 

### Unmounting a FS
1. How it works
    1. A file system cannot be unmounted if something in the system is using one of its files.
    2. If anything is using the file system to be unmounted there may be VFS inodes from it in the VFS inode cache, and the code checks for this by looking through the list of inodes looking for inodes owned by the device that this file system occupies. 
    3. If the VFS superblock for the mounted file system is dirty, that is it has been modified, then it must be written back to the file system on disk. Once it has been written to disk, the memory occupied by the VFS superblock is returned to the kernel's free pool of memory. Finally the vfsmount data structure for this mount is unlinked from vfsmntlist and freed.

## The Buffer Cache
1. Why?
    1. To speed up access to the physical block devices, Linux maintains a cache of block buffers. All of the block buffers in the system are kept somewhere in this buffer cache, even the new, unused buffers. This cache is shared between all of the physical block devices; at any one time there are many block buffers in the cache, belonging to any one of the system's block devices and often in many different states.
    2. If valid data is available from the buffer cache this saves the system an access to a physical device. Any block buffer that has been used to read data from a block device or to write data to it goes into the buffer cache. Over time it may be removed from the cache to make way for a more deserving buffer or it may remain in the cache as it is frequently accessed.
2. Characteristics?
    1. Block buffers within the cache are uniquely identified by the owning device identifier and the block number of the buffer. The buffer cache is composed of two functional parts.
        1. The first part is the lists of free block buffers. There is one list per supported buffer size and the system's free block buffers are queued onto these lists when they are first created or when they have been discarded. 
        2. The second functional part is the cache itself. This is a hash table which is a vector of pointers to chains of buffers that have the same hash index. The hash index is generated from the owning device identifier and the block number of the data block. 
    2. Block buffers are either in one of the free lists or they are in the buffer cache. When they are in the buffer cache they are also queued onto Least Recently Used (LRU) lists. There is an LRU list for each buffer type and these are used by the system to perform work on buffers of a type, for example, writing buffers with new data in them out to disk.

## The /proc File System
1. What is?
    1. /proc fs does not really exist, neither its directories and sub-dirs. 
    2. /proc fs registers itself with VFS.
    3. When the VFS makes calls to it requesting inodes as its files and directories are opened, the /proc file system creates those files and directories from information within the kernel. 
        1. For example, the kernel's /proc/devices file is generated from the kernel's data structures describing its devices.
    4. The /proc file system presents a user readable window into the kernel's inner workings. 

## Device Special Files
1. What is?
    1. /dev/null is the null device
    2. A device file does not use any data space in the file system, it is only an access point to the device driver. 
    3. EXT2 fs and Linux VFS both implement device files as special types of inode. 
    4. Character devices allow I/O operations in character mode and block devices require that all I/O is via the buffer cache. 
    5. When an I/O request is made to a device file, it is forwarded to the appropriate device driver within the system. 
    6.  Device files are referenced by a major number, which identifies the device type, and a minor type, which identifies the unit, or instance of that major type. For example, the IDE disks on the first IDE controller in the system have a major number of 3 and the first partition of an IDE disk would have a minor number of 1. Ex. "/dev/hda1"