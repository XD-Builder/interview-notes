# Abstract

- This document explains commands related to kernel & tuning

## sysctl

1. def
   1. Configure kernel parameters at runtime
   2. Used to modify kernel parameters at runtime.
   3. The available parameters are those listed under /proc/sys/.
      1. **Procfs is required for sysctl support in Linux**.
2. Syntax
   1. sysctl [options]variable[=value]] [...]
   2. sysctl - p [file or regexp][...]
3. Use Cases
   1. List all kernel parameters
      1. sysctl -a
   2. Set kernel parameters
      1. sysctl -w variable=value
   3. Load in sysctl settings from the specified or /etc/sysctl.conf if none given
      1. sysctl -pFILE
   4. Load settings from all system configuration files
      1. sysctl --system
   5. List kernel settings with matching regex
      1. sysctl -a --pattern forward
      2. sysctl -a --pattern 'net.ipv4.conf.(eth|wlan)0.arp'
   6. Applies kernel settings from all system configuration matches pattern
      1. sysctl --system --pattern '^net.ipv6'

## prlimit

1. Background
   1. get/set process resource limits
   2. Given a process ID and one or more resources, prlimit tries to retrieve and/or modify the limits.
   3. Its parameter is composd of a soft and a hard value separated by a colon (:), in order to modify the existing values
      1. soft:hard // specify both limits.
      2. :hard // sepecify only hard limit
      3. value // both limits to the same value
2. Syntax
   1. prlimit [options]--resource[=limits][--pid pid]
   2. prlimit [options]--resource[=limits] command [argument...]
3. Resource options
   1. -c => maximum size of a core file or core dump that records the memory image of a running process.
   2. -d => maximum data size
   3. -e => maximum nice priority allowed to raise
   4. -f => maximum file size
   5. -i => maximum number of pending signals
   6. -l => maximum locked-in-memory address space
   7. -m => maximum resident set size (RSS)
   8. -r => maximum real-time priority
   9. -s => maximum size of the stack
   10. -t => CPU time, in seconds
   11. -u => maximum number of processes
   12. -v => address space limit
   13. -x => maximum number of file locks held
   14. -y => timeout for real-time tasks
4. Use cases
   1. display limit values for all current resources of a process
      1. prlimit -p pid
         1. display limit values for all current resources.
   2. display the limit of the RSS, and set the soft and hard limits for the number of open files a limit
      1. prlimit -p pid --m --nofile=1024:4095
   3. modify only the soft limit for the number of processes
      1. prlimit --pid 13134 --nproc=512:
   4. set the current proces both the soft and ceiling values for the number of processes to unlimited.
      1. prlimit --pid \$\$ --nproc=unlimited
   5. set both the soft and hard CPU time limit to ten seconds and run 'sort'
      1. prlimit --cpu=10 sort -u hugefile

## ulimit (bash)

1. Def
   1. Modify shell resource limits
      1. provides control over the resources available to the shell and processes it creates, on systems that allow such control.
2. Syntax
   1. ulimit [-SHabcdefiklmnpqrstuvxPT][limit]
3. Options
   1. -S|-H => includes soft and hard resource limits
   2. HabcdefiklmnpqrstuvxPT => limits for resources managed by the shell.

## cgroup commands

1. Set up
   1. define /etc/cgconfig.conf
   2. mount cgroup hierarchy
2. Use cases
   1. Create cgroup
      1. Syntax: cgcreate -t uid:gid -a uid:gid -g subsystems:path
         1. -t specifies a user and group to own the tasks pseudofile for this cgroup and the user can add tasks to this cgroup
         2. -a specifies user and group to own all pseudofiles other than tasks for this cgroup
         3. -g specifies the hierarchy in which the cgroup should be created, as a comma-separated list of subsystems associated with hierarchies. The list of dhierarchies is **followed by a colon** and the **path to the child group relative to the hierarchy**. Do not include the hierarchy mount point in the path.
      2. Ex. cgcreate -g cpu,net_cls:/test-subgroup
      3. Alternative
         1. create a child of the cgroup directly like mkdir /cgroup/hierarchy/name/child_name
            2. Ex. mkdir /cgroup/cpu_and_mem/group1
   2. Delete cgroup
      1. Syntax: cgdelete subsystems:path
         1. subsystems is a comma‑separated list of subsystems.
         2. path is the path to the cgroup relative to the root of the hierarchy.
         3. Ex. cgdelete cpu,net_cls:/test-subgroup
         4. recursively remove all subgroups with the option -r.
   3. Set cgroup params
      1. Syntax: cgset -r param=val path_to_cgroup
         1. parameter is the param to be set, which corresponds to the ile in the directory of the given cgroup.
         2. Ex. cgset -r cpuset.cpus=0-1 group1
      2. Alternative
         1. echo 0-1 > /cgroup/cpu_and_mem/group1/cpuset.cpus
   4. Moving process to a control group
      1. Syntax: cgclassify -g subsystems:path_to_cgroup pidlist
         1. subsystem is a comma-separated list of subsystems, or \* to launch the process in the hierarchies associated with all available subsystems.
         2. pidlist is a space separated list of process identifier
         3. Ex. cgclassify -g cpu,memory:group1 1701 1702
      2. Alternative
         1. send process id to task file
            1. echo 1701 > /cgroup/cpu_and_mem/group1/tasks
   5. Obtain control groups information
      1. There are several ways to find and monitor control groups, subsystems, and hierarchies configured on your system
      2. To find the cgroup to which a process belongs:
         1. ps -O cgroup
      3. If you know the PID of the process, run
         1. cat /proc/PID/cgroup
