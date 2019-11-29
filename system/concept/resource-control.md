# Abstract
* This document provides an introduction to mechanisms in UNIX to allow resource control and rate limiting.

## Control Groups
1. Definition
   1. cgroups, or Linux control groups, are a Linux kernel feature which allow processes to be organized into hierarchical groups whose usage of various types of resources can then be limited and monitored.
   2. The kernel's cgroup interface is provided through a pseudo-filesystem called **cgroupfs**. Grouping is implemented in the **core cgroup kernel code**, while **resource tracking and limits are implemented in a set of per-resource-type subsystems** (memory, CPU, and so on).
2. Terminology
   1. cgroup - a collection of processes that are bound to a set of limits or parameters defined via the group filesystem.
   2. subsystem - a kernel component tha modifies the behavior of the processes in a cgroup. Various subsystems have been implemented making it possible to do things such as limiting the amount of CPU time and memory available to a cgroup, accounting for the CPU time used by a cgroup, and freezing and resuming execution of the process in a cgroup.
      1. They are sometimes referred to as resource controllers or simply controllers.
   3. hierarchy - An arrangement for cgroups of a controller. A hierarchy is defined by creating, removing and renaming subdirectories within the cgroup filesystem. At each level of this hierarchy, attributes can be defined. The limits, control, and accounting provided by cgroups generally have effect throughout the subhierarchy underneath the cgroup where the attributes are defined.
      1. Thus, the limits placed on a cgroup at a higher level in the hierarchy cannot be exceed by descendant cgroups.
3. Cgroups version 1 and Version 2
   1. The initial release of cgroups implementation was in Linux 2.6.24. Overtime, v**arious cgroup controllers have been added** to allow the management of various types of resources.
   2. There are **problems with the initial cgroups implementation, starting in Linux 3.10**, work began on a new, orthogonal implementation to remedy these problems. **The new version (cgroups version 2) was eventually made official with the release of Linux 4.5**. 
   3. Differences between the two versions:
      1. Although cgroups v2 is intended as a replacement for cgroups v1, the older system continues to exist (and for compatibility reasons is unlikely to be removed). Currently cgroups v2 implements only a subset of the controllers available in cgroups v1. The two systems are implemented so that **both v1 controllers and v2 controllers can be mounted on the same system**.
         1. Thus, for example, it is possible to use those controllers that are supported under version 2, while also using version 1 controllers where version 2 does not yet support those controllers. The only restriction is that **a controller can't be simultaneously employed in both a cgroup v1 hierarchy and in the cgroups v2 hierarchy**.
4. cgroups V1
   1. Intro
      1. Each controller may be mounted against a separated cgroup filesystem that provides its own hierarchical organization of the processes on the system. It is also possible to comount multiple cgorups v1 controllers against the same cgroup filesystem, meaning that the mounted controllers manage the same hierarchical organization of processes.
      2. For each mounted hierarchy, the directory tree mirrors the control group hierarchy. Each control group is represented by a directory, with each of its child control cgroups represented as a child directory. 
         1. Ex. /usr/joe/1.session
            1. 1.session which is a child of cgroup joe, which is a child of /user. 
         2. Under each cgroup directory is a set of files which can be read/written to, reflecting resource limits and a few general cgroup properties.
   2. Tasks (threads) vs processes
      1. A process can consist of multiple tasks (threads from a user-space perspective). It's possible to independently to manipulate the cgroup memberships of the threads in a process.
      2. Its ability to split threads across different cgroups caused problems in some cases.
         1. Ex. It made no sense for the memory controller, since all of the threads of a process share a single address space. Thus this is removed in the initial cgroups v2 implementation and subseuqently restored in a more limited form (thread mode)
   3. Mounting v1 controllers
      1. The use of cgroups requires **a kernel built with the CONFIG_CGROUP option**. In addition, each of the **v1 controllers has an associated configuration option that must be set in order to employ that controller**.
      2. In order to use a v1 controller, it must be mounted against a cgroup filesystem. The usual place for such mount is under a **tmpfs** file system mounted at **/sys/fs/cgroup**
      3. One might mount the cpu controller like
         1. Ex. mount -t cgroup -o cpu none /sys/fs/cgroup/cpu
      4. One might comount multiple controllers (cpu and cpuacct) against the same hierarchy
         1. Ex. mount -t cgroup -o cpu,cpuacct none /sys/fs/cgroup/cpu,cpuacct
         2. Comounting controllers has the effect that a process is in the same cgroup for all of the comounted controllers. Separately mounting controllers allows a process to be in cgroup /foo1 for one controller while being in foo2/foo3 for another.
      5. It's possible to cmount all v1 controllers against the same hierarchy
         1. mount -t cgroup -o all cgroup /sys/fs/cgroup
   4. Unmount v1 controllers
      1. A mounted cgroup fs can be unmounted using the umount command
         1. Ex. umount /sys/fs/cgroup/pids
         2. It is unmounted only if it is not busy, that is, it has no child cgroups.
   5. Cgroups v1 controllers
      1. Each of the controllers is governed by a kernel configuration option and the availability of the cgroups feature is governed by the CONFIG_CGROUPS kernel configuration option.
      2. cpu (since Linux 2.6.24; CONFIG_CGROUP_SCHED)
         1. guaranteed a minimum number of "CPU shares" when a system is busy
      3. cpuacct (since Linux 2.6.24; CONFIG_CGROUP_CPUACCT)
         1. provides accounting for CPU usage by groups of processes
      4. cpuset (since Linux 2.6.24; CONFIG_CPUSETS)
         1. used to bind the processes in a cgroup to a specified set of CPUs and NUMA nodes
      5. memory (since Linux 2.6.25; CONFIG_MEMCG)
         1. supports reporting and limiting of process memory, kernel memory, and swap used by cgroups
      6. devices (since Linux 2.6.26; CONFIG_CGROUP_DEVICE)
         1. supports controlling which processes may create (mknod) devices as well as open them for reading or writing
      7. freezer (since Linux 2.6.28; CONFIG_CGROUP_FREEZER)
         1. can suspend and restore (resume) all processes in a cgroup.
      8. net_cls (since Linux 2.6.29; CONFIG_CGROUP_NET_CLASSID)
         1. places a classid, specified for the cgroup, on network packets created by a cgroup. These classids can then be used in firewall rules, as well as used to shape traffic using tc(8). This applies only to packets leaving the cgroup, not to traffic arriving at the cgroup.
      9. blkio (since Linux 2.6.33; CONFIG_BLK_CGROUP)
         1. controls and limits access to specified block devices by applying IO control in the form of throttling and upper limits against leaf nodes and intermediate nodes in the storage hierarchy.
      10. perf_event (since Linux 2.6.39; CONFIG_CGROUP_PERF)
          1. allows perf monitoring of the set of processes grouped in a cgroup.
      11. net_prio (since Linux 3.3; CONFIG_CGROUP_NET_PRIO)
          1. allows priorities to be specified, per network interface, for cgroups.
      12. hugetlb (since Linux 3.5; CONFIG_CGROUP_HUGETLB)
          1. supports limiting the use of huge pages by cgroups.
      13. pids (since Linux 4.3; CONFIG_CGROUP_PIDS)
          1. permits limiting the number of process that may be created in a cgroup (and its descendants).
      14. rdma (since Linux 4.11; CONFIG_CGROUP_RDMA)
          1. permits limiting the use of RDMA/IB-specific resources per cgroup.
   6. Creating cgroups and moving processes
      1. The cgroup fs initially contains a single root cgroup '/', which all processes belong to. A new cgroup is created by creating a directory in the cgroup filesystem
         1. Ex. mkdir /sys/fs/cgroup/cpu/cg1
         2. This creates a new empty cgroup
      2. The process may be moved to this cgroup by writing its PID into the cgroup's cgroup.procs file:
         1. Ex. echo $$ > /sys/fs/cgroup/cpu/cg1/cgroup.procs
         2. Only one PID at a time should be written to this file. Writing zero to this file causes the writing process to be moved to the corresponding cgroup. All threads in the process are moved into the new cgroup at once.
         3. A process can only be a member of exactly one cgroup and writing a PID to a cgroup.procs file automatically removes it from the cgroup of which it was previously a member.
   7. Removing cgroups
      1. To remove a cgroup, it must first have no child cgroups and contain no (nonzombie) processes. If it's the case, one can remove the corresponding cgroup directory path.
   8. cgroup named hierarchies
      1. It's possible to mount a cgroup hierarchy that has no attached controllers
      2. Ex. mount -t cgroup -o none,name=somename none /some/mount/point
         1. Multiple instances of such hierarchies can be mounted; each hierarchy must have a unique name. The only purpose of such hierarchies is to track processes.
5. cgroups v2
   1. Intro
      1. **All mounted controllers reside in a single unified hierarchy**. While controllers may be simultaneously mounted under v1 and v2 hierarchies, it is **not possible to mount the same controller simultaneously under both the v1 and v2 hierarchies**.
      2. Summary cgroups v2
         1. provides a unified hierarchy which all controllers are mounted
         2. "Internal" processes are not permitted. With the exception of the root cgroup, processes may reside only in leaf nodes.
         3. Active cgroups must be specified via the file cgroup.controllers and cgroup.subtree_control
         4. The tasks file has been removed. In addition, the cgroup.clone_children file that is employed by the cpuset controller has been removed.
         5. An improved mechanism for notification of empty cgroups is provided by the cgroup.events file.
   2. cgroups v2 unified hierarchy
      1. All available controllers are mounted against a single hierarchy. The available controllers are automatically mounted, meaning it is not necessary to specify the controllers when mounting the cgroup v2 filesystem using a command such as:
         1. mount -t cgroup2 none /mnt/cgroup2
   3. cgroups v2 controllers
      1. io (since Linux 4.5)
         1. This is the successor of the version 1 blkio controller.
      2. memory (since Linux 4.5)
         1. This is the successor of the version 1 memory controller.
      3. pids (since Linux 4.5)
         1. This is the same as the version 1 pids controller.
      4. perf_event (since Linux 4.11)
         1. This is the same as the version 1 perf_event controller.
      5. rdma (since Linux 4.11)
          1. This is the same as the version 1 rdma controller.
       1. cpu (since Linux 4.15)
          1. This is the successor to the version 1 cpu and cpuacct controllers.
   4. cgroups subtree control
      1. Each cgroup in v2 hierarchy contains following two files
         1. cgroup.controllers
            1. The read only file exposes a list of the controllers that re available in this cgroup. The contents of this file match the contents of the parent cgroup's cgroup.subtree_control file.
         2. cgroup.subtree_control
            1. This is a list of controllers that are active (enabled) in the cgroup. The set of controllers in this file is a subset of the set in the cgroup.controllers of this cgroup. The set of active controlelrs is modified by writing strings to this file containing space-delimited controller names, each preceded by '+' or '-' either to enable or disable a controller.
            2. Ex. echo '+pids -memory' > x/y/cgroup.subtree_control
   5. cgroups "no internal process" rule
      1. The rule means that, with the exception of the root cgroup, processes may reside only in leaf nodes ( groups that do not themselves contain child cgroups). This avoids the need to decide how to partition resources between processes which are members of a cgroup A and processes in child cgroups of A.
      2. Ex. If cgroup /cg1/cg2 exists, then a process may reside in /cg1/cg2, but not in /cg1. This avoids an ambiguity in cgroups v1 with respect to the delegation of resources between processes in /cg1 and its child cgroups.
   6. cgroups v2 cgorup.events file
      1. A new mechanism to provide notification about when a cgroup becomes empty.
      2. The cgroup v1 release_agent and notify_on_release files are removed, and replaced by a new, more general-purpose file, cgroup.events. The read-only file contains key-value pairs that identifies events or state for a cgroup.
         1. Currently, only one key appears in this file, populated, which has either the value 0, meaning that the cgroup contains no processes, or 1, meaning otherwise.
   7. cgroups v2 cgroup.stat file
      1. each cgroup in the v2 hierarchy contains a read-only cgroup.stat file that consists of lines containing key-value pairs.
         1. nr_descendents
            1. the total number of visible descendant cgroups underneath this cgroup
         2. nr_dying_descendants
            1. A cgroup enters a dying state after being deleted. It remains in that state for an undefined period depending on system load while resources are freed before the cgroup is destroyed.
   8. Limiting the number of descendant cgroups
      1. each cgroup contains following files which can be used to view and set limits on the number of descendant cgroups under that group
         1. cgroup.max.depth (since Linux 4.14)
            1. defines a limit on the depth of nesting of descendant cgroups.
         2. cgroup.max.descendants (since Linux 4.14)
            1. defines a limit on the number of live descendant cgroups that this cgroup may have.
   9. Other topics to look into
      1. Cgroups v2 delegation: delegation to a less privileged user
      2. Cgroups v2 delegation: nsdelegate and cgroup namespaces
      3. Cgroup v2 delegation containment rules
   10. Groups v2 thread mode
       1. Among the restrictions imposed by cgroup v2 that were not present in cgroup v1 are:
          1. No thread-granularity control: all of the threads of a process must be in the same cgroup
          2. No internal processes: a cgroup can't both have member processes and exercise controllers on a child cgroup.
       2. Thread mode allows following:
          1. The creation of threaded subtrees in which the threads of a process may be spread across cgroups inside the tree (A threaded subtree may contain multiple multi-threaded processes)
          2. The concept of threaded controllers, which can distribute resources across the cgroups in a threaded subtree.
          3. A relaxation of the "no internal processes rule", so that, within a threaded subtree, a cgroup can both contain member threads and exercise resource control over child cgroups.
       3. With the addition of thread mode, each nonroot cgroup now contains new file, cgroup.type, that exposes and change the "type" of cgroup. This file contains one of the following type values
          1. domain
             1. provides process-granularity control. If a process is a member of this cgroup, then all threads of the process are (by definition) in the same cgroup.
          2. threaded
             1. a member of a threaded subtree. Threads can be added to this cgroup, and controllers can be enabled for the cgroup.
          3. domain threaded
             1. a domain cgroup that serves as the root of a threaded subtree.  This cgroup type is also known as "threaded root"
          4. domain invalid
             1. a cgroup inside a threaded subtree that is in an "invalid" state.  Processes can't be added to the cgroup, and controllers can't be enabled for the cgroup.
6. /proc files
   1. /proc/cgroups (since Linux 2.6.24)
      1. This file contains information about the controllers that are compiled into the kernel.
   2. /proc/[pid]/cgroup (since Linux 2.6.24)
      1. This file describes control groups to which the process with the corresponding PID belongs. The displayed information differs for cgroups version 1 and version 2 hierarchies.
      2. For each cgroup hierarchy of which the process is a member, there is one entry containing three colon-separated files
         1. Syntax => hierarchy-ID:controller-list:cgroup-path
         2. Ex. 5:cpuacct,cput:/daemons
            1. The hierarchy ID for cgroups v1 can be matched in /proc/cgroups. For cgroups v2 it has value of 0
            2. For cgroups v1, controller-list contains a comma-separated list of the controllers bound to the hierarchy. For cgroups v2, this field is empty
            3. The cgroup-path contains the path of the control group in the hierarchy to which the process belongs and is relative to the mount point of the hierarchy.
7. /sys/kernel/cgroup files
   1. /sys/kernel/cgroup/delegate (since Linux 4.15)
      1. The file exports a list of the cgroup v2 files that are delegatable. 
   2. /sys/kernel/cgroup/features (since Linux 4.15)
      1. Over time, the set of cgroup v2 features that are provided by the kernel may change or grow, or some features may not be enabled by default. This file provides a way for user-space application to discover what feature the running kernel supports and has enabled.