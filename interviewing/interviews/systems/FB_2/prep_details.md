# Abstract

- This document serves as a template for what to focus as a Systems Engineer. It details aspects of Systems Engineer functions and low level details required to be successful for the job.

## System Questions

1. Onsite
   - Design, coding, networking, system.
2. System

   - Whiteboarding.. Problem solution. Knowledge of Linux, **practical troubleshooting is the key**.
   - **Theoretical core building block of Linux**. **System boot and load, Shell and how it interacts with OS**.
   - **UNIX file system linux vm, techniques for resource control, common troubleshooting tools**
   - Practical **troubleshooting, debugging with one server or multiple server in a distributed system**.
   - **Apply knowledge in the real world**.
   - How successful engineer prepare, **not a trivia**, needs **a solid base of knowledge**. If you don't understand the question. Then ask questions.
   - For practical problems, **use, resource utilization, performance, working scenarios and workflow**.

3. System problems

   - **System and Scripting**
     - how do the writer get the data to aggregator. What is the system time for different nodes. check "ntp" differences with SNTP (simple network time protocol). Are there queuing issues. How would you find those
       - **SNTP (Simple Network Time Protocol) and NTP (Network Time Protocol)** are describing exactly the same network package format, the differences can be found in the way how a system deals with the content of these packages in order to synchronize its time. They are basically two different ways of how to deal with time synchronization.
     - Looking at the writer as source, I would look at the **cpu with top, look for utilization, memory of a process**, 30% cpu,
       - troubleshoot writer for queuing ntp?
         - which process is queuing the ntp?
           - Read, https://www.eecis.udel.edu/~mills/ntp/html/warp.html
         - With the found process find io for that process
     - Programs runs in user space, why would user vs systems matter. If I have a bug in the process that is spinning threads. kernel system space. Context switching between spaces happens, can you describe a context switch.
       - What's the purpose of kernel space. Why can't we run programs in user space without needing OS.
         - Privilege escalation for accessing devices for networking, fs, memory ops, ipc, interrupt & signal, multi-threading etc..
         - Kernel space moderates between competing processes and threads for resources and enforce fairness across processes in the system.
           - It also handles exceptional scenarios, buffering, security for IPC, mutexes, timers, privileges and roles and more.
       - A process with a bug that's spinning new threads, how it relates to kernel system space and how context switch between spaces happen.
         - Creating a thread requires context switch to run the newly created thread if all cpu cores are busy running processes.
         - The more threads it spins, the more of the CPU time needs to be context switched, meaning saving the state of one process and loading the state of another in their corresponding Process Control Block (PCB) by kernel to support running all threads fairly in a time-span say 1 second.
         - Context switch can happen because of multitasking schedulers, interrupt Handling initiated by devices or software, or User and Kernel Mode Switching (when kernel needs to run its own code, or syscalls that requires kernel context to run).
       - What's specifically in a context switch
         - Described in the system_prep folder
     - There is a lifecycle of a process, execute, process waits for an io in a specific state. how would you know if you have a lot context switches and what may cause this.
       - Answer
         - pidstat -wt
           - This will show cswch/s nvcswch/s for all processes
       - Process lifecycle
         - What's the state of a process that's waiting for an io to complete.
           - Blocked state
         - How to determine a lot of context switches are happening and what may cause a lot of context switches.
           - pidstat -wt
             - Shows all processes and threads and their context switches
           - pidstat -wt -p <pid>
             - Shows all threads under pid and their context switches
     - There can be a CPU hog and that can be a high priority, the kernel can be trying to handle too many requests. Don't need to see io and writers would go to aggregator. Is there some sort of buffering to disk here. How would you know that.
       - Answer
         - If you want to find io issues and their wait time, run the following which tells you disk utilization and extended disk stats
           - iostat -xd
             - **rrqm stands for the number of read requests** merged per second that were queued to the device.
             - **await stands for the average time in milliseconds for I/O requests issued to the device to be served. This includes the time spent by the requests in queue and the time spent servicing them**.
             - **wareq-sz stands for average size (in kilobytes) of the write requests that were issued to the device.**
       - How do you know a process is using a lot of cpu and kernel is trying to handle too many of them?
         - top? identifying the most using pid
         - Then pidstat? finding the percentage of user and system it's waiting and percentage of waiting cpu time it's consuming
       - If io and writers are going to aggregator meaning going to disk is fine, how do you find out is there buffering to disk?
         - Answer
           - To find memory, buffer, swap, page in and out
             - cat /proc/meminfo
             - vmstat -S KB -s
             - free -m
           - Interactively see changes, run
             - top
           - To flush the buffer/cache
             - sysctl -w vm.drop_caches=3
           - Lastly download ftools and run
             - fincore
               - gives you some summary information on what files' pages are the content of the cache
             - sync
               - synchronize cached writes to persistent storage
           - clear Swap space, you may like to run the below command.
             - swapoff -a && swapon -a
         - Dirty memory, write through cache
           - write through cache
             - a storage method in which data is written into the cache and the corresponding main memory location **at the same time**. The **cached data allows for fast retrieval on demand**, while the same data in main memory ensures that nothing will get lost if a crash, power failure, or other system disruption occurs.
             - Although write through **minimizes the risk of data loss, every write operation must be done twice, and this redundancy takes time**. The active application program must wait until each block of data has been written into both the main memory and the cache before starting the next operation. The "data insurance" therefore comes at the expense of system speed.
             - Write through is the preferred method of **data storage in applications where data loss cannot be tolerated, such as banking and medical device control**. In less critical applications, and especially when data volume is large, an alternative method called **write back accelerates system performance because updates are normally written exclusively to the cache**, and are backed up in the main memory **only at specified intervals or under certain conditions**.
           - Dirty Memory
             - cat /proc/meminfo | grep Dirty
             - If data is written, **it is first written to the Page Cache and managed as one of its dirty pages. Dirty means that the data is stored in the Page Cache, but needs to be written to the underlying storage device first**. The content of these dirty pages is periodically transferred (as well as with the system calls sync or fsync) to the underlying storage device. The system may, in this last instance, be a RAID controller or the hard disk directly.
           - Find top 5 memory usage process
             - ps -eo pmem,pcpu,vsize,pid,cmd | sort -k 1 -nr | head -5
     - Print last second last column of file which has an unknown number of columns.
       - awk '{print \$(NF-1)}' fileName
         - defaults to space separated file.
       - awk -F ":" '{print \$(NF-1)}' /etc/passwd
         - sets delimiter to colon and prints second to the last colon.
     - Find the duplicate uid from the password file. - print all duplicate uids
       - awk "print \$2" /etc/passwd | uniq | grep -v "^1:"
         - Not sure why this is the answer but..
       - awk -F: '{print \$3}' pwd | sort |uniq -d
         - This will print password delimited by colon and the third field which is the uid
         - Given list of uid, sort will sort the list numerically
         - Given a sorted uid line by line, unique will stream through and print only if the stream has a dup from the previous item streamed.
     - Ctrl-Z works in shell
       - Simple Answer
         - A **"background job" is just one that is not interacting with the user** -- it **doesn't control the tty** and it just does its thing (generally silently). **A foreground job is the reverse, it holds control of the tty to interact with the user**.
         - **Control-Z suspends the most recent foreground process** (the last process to interact with the tty) (unless that process takes steps to ignore suspension, like shells normally do). This will generally bring you back to your shell, from which you can generally enter the command bg to move the just-suspended process to the background (letting it continue to run) or fg to bring it back to the foreground.
       - Deeper Answer
         - Pressing Ctrl+Z s**ends the TSTP signal to your proces**s. This **halts execution (the kernel won't schedule any more CPU time to the process) and the process is awaiting a CONT to continue processing**.
         - You can **emulate/replicate this via kill -TSTP and kill -CONT** (since kill will send a nominated signal to your process, despite the name!)
         - **The shell has the functionality to 'background' the process, but this is a relationship between the shell and the process**. The process itself doesn't really have the concept of 'background' or 'foreground'.
     - Break down the question first, do not reference last interview

4. Coding - 3/16

   - Return whether the given string ignoring punctuation, special characters and capitalization, is it a palindrome.

```python
def isPalindrome(inputStr):
  if inputStr = None or len(inputStr) == 0:
    return True
  cleansedInputStr = cleanseStr(inputStr)
  for i in range(0, len(cleansedInputStr)/2):
    if cleansedInputStr[i] != cleansedInputStr[len(cleansedInputStr)-i-1]:
      return False
  return True

def isPalindrome(inputStr):
  if inputStr = None or len(inputStr) == 0:
    return True
  cleansedInputStr = cleanseStr(inputStr)
  if cleansedInputStr == cleansedInputStr[::-1]:
  # ''.join(reversed(cleansedInputStr))
    return True
  return False

def cleanseStr(inputStr):
  inputStr = inputStr.lower()
  inputStr = re.sub('[^a-z0-9]+', '', inputStr)
  return inputStr
```

- Print last 10 lines of a file, how to do array sum. Why use enumerate? Would a multipass solution make more sense.
  - tail -10 file
  - Array sum python

```python
a = [1,2,3,4]
print(sum(a))
```

- Diagnose arrays. Memory is expensive can we use less. Reading one lines at a time. goat latin.
  - Goat Latin
    - Examples
      - Input: "I speak Goat Latin"
      - Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa
    - Rules
      - If a word begins with a vowel (a,e,i,o or u) append "ma" to the end of the word
      - If a word begins with a consonant (not a vowel), remove the first letter and append it to the end, then add "am"
      - Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
        - For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.

```python
class Solution(object):
    def toGoatLatin(self, S):

        def convert(word):
            if word[0] not in 'aeiouAEIOU':
                word = word[1:] + word[:1]
            return word + 'ma'

        return " ".join(convert(word) + 'a' * i
                        for i, word in enumerate(S.split(), 1))
```

- Concordance, migration monitoring, large procs
  - An alphabetical list of words present in a text, usually with citations of the passages concerned.
  - Sketch out solution, prepare me with question about the .. text file will be fit into a file. Use dictionary and quicker answer
  - Top 3 most occuring
- migration monitoring
  - shell scripting to sh scripting. How to parse the output. Expect some use of awk. solution, host, ps -ef, useful tool like netstat

1. System Design - pirate

   - reboot the world - focus on candidate's ability to build scalable systems and adapt to changing requirement.
     - patch the kernel, and restart all of the servers
     - patch 100 servers and reboot them.
     - Running systems like a single file. Are there load balancer.
       - how to drain traffic to systems and rolling upgrade the system kernels with reboot. How to efficiently distribute kernels across all servers and how to load balance servers so the upgrading server doesn't get routed with traffics.
   - scale file distribution
     - how to use bittorrent? Dividing large files to smaller pieces with cryptographic hashes for authenticity.
       - How to distribute the initial torrent files? Via Config management system like SaltStack.
       - How bittorent can help? The distribution time wil go down from t + t _ number nodes to distribute file, to t + t *log2(N) / pieces that you break down it to.
       - Network load will be less and avoids flashing crowd. The file distribute faster as bitTorrent uses rarest piece first transmission scheme.

2. Networking

   - Freshly booted up devices want to SCP a file to a server on another VLAN. Explain high level packet flow. Troubleshoot SCP speed to the server. What tools would you use? Follow up about questions about mismatched MTU. Different link speed and etc. How ping, traceroute, mtr works. How pmtud, retransmission and dup packets congestion window.
     - Answer
       - VLAN high level traffic flow
         - VLAN operates on switches. Switches has headers to identify if it's part of the VLAN.
           - the computers, servers, and other network devices are logically connected regardless of their physical location
         - Nodes forwards data frame to switch, which looks up VLAN membership of the target mac. If it's for another VLAN, then it forwards the frame to router which forwards to correct switch that it knows of.
           - Before that the switch should be set up with vlan and knows either by port or mac address which VLAN does it belong to.
       - Problem without VLAN
         - broadcast are seem by all computers in the LAN network. VLAN helps separate network traffic. Reduces traffic conflict
       - SCP slow speed to the server troubleshooting
         - Common causes of slow IntraVLAN and InterVLAN connectivity. Can be caused by multiple factors on different network layers.
         - Categories of Causes
           - Slow Collision Domain Connectivity
             - Collision domain is **defined as connected devices configured in a half-duplex port configuration, connected to each other or a hub**. If a device is connected to a switch port and full-duplex mode is configured, **such a point-to-point connection is collisionless. Slowness on such a segment still can occur for different reasons**.
           - Slow Broadcast Domain Connectivity (Slow VLAN)
             - Slow broadcast domain connectivity occurs when the whole VLAN (that is, all devices on the same VLAN) experiences slowness.
           - Slow InterVLAN Connectivity (Slow Forwarding Between VLANs)
             - Slow interVLAN connectivity (slow forwarding between VLANs) occurs when there is no slowness on the local VLAN, **but traffic needs to be forwarded to an alternate VLAN, and it is not forwarded at the expected rate**.
         - Causes for Network Slowness
           - Packet Loss
             - In most cases, a network is considered slow when **higher-layer protocols (applications) require extended time to complete an operation** that typically runs faster. **That slowness is caused by the loss of some packets on the network, which causes higher-level protocols like TCP or applications to time out and initiate retransmission**.
           - Hardware Forwarding Issues
             - With another type of slowness, caused by **network equipment**, forwarding (whether Layer 2 [L2] or L3) is performed slowly. This is due to a deviation from normal (designed) operation and switching to slow path forwarding. An example of this is **when Multilayer Switching (MLS) on the switch forwards L3 packets between VLANs in the hardwar**e, **but due to misconfiguration, MLS is not functioning properly and forwarding is done by the router in the software (which drops the interVLAN forwarding rate significantly)**.
         - Troubleshooting
           - If your VLAN appears to be slow, first isolate the collision domain problems.
             - You need to establish if only users on the same collision domain are experiencing connectivity problems, or if it is happening on multiple domains. To do this, **make a data transfer between user PCs on the same collision domain, and compare this performance with the performance of another collision domain**, or with its expected performance.
               - If problems only occur on that collision domain, and the performance of other collision domains in the same VLAN is normal, then look at the port counters on the switch to determine what troubles this segment may be experiencing. Most likely, **the cause is simple, such as a duplex mismatch**. Another, less frequent cause is an overloaded or oversubscribed segment. For more information on troubleshooting a **single segment problem, refer to the document Configuring and Troubleshooting Ethernet 10/100/1000Mb Half/Full Duplex Auto-Negotiation**.
       - Mismatched MTU
         - Ping
           - Ping can be used to find an acceptable MTU size. Make sure to take into account the 28 bytes for the IP and ICMP headers by subtracting from the packet size. 
           - CLI on mac
             -  ping www.meraki.com -s 1472 -D
             -  ping host with 1472 bytes and do not fragment. This assumes you are testing 1500 byte IP datagram which has a 28 bytes overhead.
       - Different Link speed
       - Other causes
         - Traffic loop, overloaded or oversubscribed VLAN
         - Congestion on the switch inband path
         - switch management processor high CPU utilization
         - ingress errors on a cut-through switch
       - VLan Commands
         - switchport mode, trunk, access, dynamic desirable, dynamic auto.
         - show vlan or show vlan id
         - show interfaces fastEthernet 0/1 switchport
       - Ping, Traceroute
       - MTR
         - A powerful tool which enables administrators to **diagnose and isolate networking errors and provide reports of network status to upstream providers**. MTR represents an evolution of the traceroute command by providing a greater data sample, as if augmenting traceroute with ping output.
         - Background
           - Networking diagnostic tools including ping, traceroute, and mtr use Internet Control Message Protocol (ICMP) packets to test contention and traffic between two points on the Internet. When a user pings a host on the Internet, a series of ICMP packets are sent to the host, which responds by sending packets in return. The user’s client is then able to compute the round trip time between two points on the Internet.
           - As mtr starts, it investigates the network connection between the host mtr runs on and a user-specified destination host. After it determines the address of each network hop between the machines, it sends a sequence ICMP ECHO requests to each one to determine the quality of the link to each machine. As it does this, it prints running statistics about each machine.
       - PMTUD
         - Path MTU Discovery is a standardized technique in computer networking for determining the maximum transmission unit (MTU) size on then network path between two IP hosts with the goal of avoiding IP fragmentation.
         - Ex ping www.meraki.com -s 1472 -D, which sets "don't fragment flag"
           - Then, any device along the path whose MTU is smaller than the packet will drop it, and send back an Internet Control Message Protocol (ICMP) Fragmentation Needed (Type 3, Code 4) message containing its MTU, allowing the source host to reduce its Path MTU appropriately.
         - Problems
           - **Many network security devices block all ICMP messages for perceived security benefits**, including the errors that are necessary for the proper operation of PMTUD. This can result in connections that complete the TCP three-way handshake correctly, but **then hang when data is transferred**. **This state is referred to as a black hole connection**.
           - Some implementations of PMTUD **attempt to prevent this problem by inferring that large payload packets have been dropped due to MTU rather than because of link congestion**. However, in order for the Transmission Control Protocol (TCP) to operate most efficiently, ICMP Unreachable messages (type 3) should be permitted. **A robust method for PMTUD that relies on TCP or another protocol to probe the path with progressively larger packets has been standardized in RFC 4821**.
           - A workaround used by some routers is to **change the maximum segment size (MSS) of all TCP connections passing through links with MTU lower than the Ethernet default of 1500. This is known as MSS clamping**.
       - Retran and DUP packets congestion window
         - Cwnd or Congestion Window is **a TCP state variable that limits the amount of data the TCP can send into the network before receiving an ACK**.
         - TCP congestion control was introduced into the Internet in the late 1980s by Van Jacobson, roughly eight years after the TCP/IP protocol stack had become operational. Immediately preceding this time, the Internet was suffering from congestion collapse—hosts would send their packets into the Internet as fast as the advertised window would allow, **congestion would occur at some router (causing packets to be dropped), and the hosts would time out and retransmit their packets, resulting in even more congestion**.
   - Explanation of ARP broadcast and unknown unicast flooding. TCP exchanges. Flooding network research
     - Answer
       - What's ARP broadcast and unknown unicast flooding
         - ARP broadcasts a request packet in a special format to all the machines on the LAN to see if one machine knows that it has that IP address associated with it.
           - A machine that recognizes the IP address as its own returns a reply so indicating. ARP updates the ARP cache for future reference and then sends the packet to the MAC address that replied.
         - Unicast Flood
           - **when a switch receives a unicast frame and treats it as a broadcast frame, flooding the frame to all other ports on the switch**.
             - When a switch receives a unicast frame with **a destination address not in the switch’s forwarding table**, **the frame is treated like a broadcast frame and sent to all hosts on a network**
           - switchport block unicast 
           - switchport protected
             - both will block unicast flood.
       - Flooding Network Research
       - TCP Exchanges
         - TCP SYN, SYN-ACK, ACK. 
         - FIN, FIN-ACK, FIN, FIN-ACK
   - Curl to FB.com and what happens.
     - DNS resolution
     - GET request
     - 301 redirect response
     - TLS establishment
     - GET request with new URL
   - User with a workstation that is not able to connect to a network how do you troubleshoot that.
     - Traceroute to see if local network is able to go out of the local network.
       - If may fail with unknown host which means it's not able to resolve DNS.
         - Check ifconfig with your interface if it has ip assignmend, maybe related DHCP?
         - Check /etc/nsswitch.conf
         - Check /etc/hosts
         - Check /etc/networks
       - IF it fails with traceroute to a certain router, then there is some networking issue.
       - Else it may be related to the user program itself with proxy or some other environment settings.
   - If the system has an IP address of 169.254.0.18
     - 169.254.*.* IP addresses are flagged as "limited connectivity"
       - Almost as good as no IP at all
       - This difficulty arises when your computer asks for an IP address, and no one responds to the request. Whether due to a network problem, maybe not being on a network at all, or perhaps there’s no DHCP server to hand out IP addresses, the result is the same: the request for an IP address assignment goes unanswered. Your machine waits for a while, and then gives up. But when it gives up, it invokes what’s called Automatic Private IP Addressing, or APIPA, and makes up its own IP address. And those “made up” IP addresses all begin with 169.254.
     - I tells you that the machine cannot reach the DHCP server over the network.
       - If you're connected via a NAT router, then either your computer is not actually connected on the network to the router, or the router itself isn't responding to DHCP request.
       - If you're connected to the Internet directly, then there is a problem with that you connection. Check the cabling to your broadband modem, and check the cabling from your broadband modem to your telephone line. It may actually be ISP's DHCP server or some other item they control that's at fault
     - Something about your network setup is not working, and probably you want to investigate what and why.
   - How would you troubleshoot DHCP issues on a network. If you ping the DHCP server but not getting any replies. What would be problem
     - Answer
       - /etc/init.d/dhcp stop | start in the server in debug mode
       - man dhclient to get more info about the client's capabilities
         - The client normally prints no output during its startup sequence. It can be made to emit verbose messages displaying the startup sequence events until it has acquired an address by supplying the -v command line argument. In either case, the client logs messages using the syslog(3) facility.
         - on Systemd, run journalctl, or run cat /var/log/syslog to find logs about the connectivity
           - cat /var/log/syslog | grep -Ei 'dhcp'
           - journalctl | grep -Ei 'dhcp'
         - Troubleshoot from there if the server is having issues
     - How DHCP really work on a router.
       - UDP packet for DHCP requests.
       - DHCP follows DORA
         - Discovery
           - The client sends a broadcasts messages on the network subnet using the destination address 255.255.255.255 or the specific subnet broadcast address.
         - Offer
           - When a DHCP server receives a DHCPDISCOVER message from a client, which is an IP address lease request, the server reserves an IP address for the client and makes a lease offer by sending a DHCPOFFER message to the client. This message contains the client's MAC address, the IP address that the server is offering, the subnet mask, the lease duration, and the IP address of the DHCP server making the offer.
             - Which contains subnetmask, router, ip address lease time, dhcp server, dns servers
         - Request
           - In response to the DHCP offer, the client replies with a DHCP request, broadcast to the server, requesting the offered **address**. A client can receive DHCP offers from multiple servers, but it will accept only one DHCP offer. Based on required server identification option in the request and broadcast messaging, servers are informed whose offer the client has accepted. When other DHCP servers receive this message, they withdraw any offers that they might have made to the client and return the offered address to the pool of available addresses.
         - Acknowledgement
           - When the DHCP server receives the DHCPREQUEST message from the client, the configuration process enters its final stage. The acknowledgement stage involves sending a DHCPACK packet to the client. This packet includes the lease duration and any other configuration information that the client might have requested. At this point, the IP configuration process is completed.

3. Behavioral Questions
   - What interests you.
     - Challenge oneself intellectually and making an impact if possible
   - Why leave your current company
   - How you work as a team as an individual
   - Your strongest team.
   - Tell me about a project or career that you are proud of. What do you consider to be successful. How do others view it.
     - Projects
   - Describe a situation when you and your team are given little direction but able to come to a successful completion, how do you go about it and what are the challenges and mistakes that you make and what do you learn from it.
     - Research, googling, RFC if necessary.
     - What's learned. Focus and there will always a solution to your problem.
   - Have you dealt with conflicts and describe it with a successful resolution. What do you learn from it.
     - Respect and listen
   - Tell me about a time, you receive a negative feedbacks and how do you handle it.
     - Accept, internalize and change
   - Have ever change your behavior? How are you able to change it and how do you keep it in check. What is the impact on the organization.
     - Yes, better working environment, sharing and collaboration
   - What is the strongest team environment. How do you handle poor team environment.
     - Coach teammates in poor team environment.
     - The strongest team environment focuses on excellence, best practice and fast innovation and iteration.
