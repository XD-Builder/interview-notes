# Abstract

- This document explores time protocols provided by linux

## Network Time Protocol (NTP)

1. Definition
   1. A networking protocol for **clock synchronization between computer systems over packet-switched, variable-latency data networks**.
   2. In operation since before 1985, NTP is one of the oldest Internet protocols in current use.
      1. Intended to synchronize all participating computers to within a few milliseconds of UTC. It uses the **intersection algorithm**, a modified version of Marzullo's algorithm, to select accurate time servers and is **designed to mitigate the effects of variable network latency**. NTP can usually **maintain time to within tens of milliseconds over the public Internet**, and **can achieve better than one millisecond accuracy in local area networks under ideal conditions**. **Asymmetric routes and network congestion can cause errors of 100 ms or more**.
   3. It's described in terms of client-server model bu can easily be used in P2P relationships where both peers consider the other to be a potential time source.
      1. Implementation **sends and receives timestamps using the UDP on port 123**. They can use **broadcast or multicasting**, where **clients passively listen to time updates after an initial round-trip calibrating exchange**.
2. Clock Strata
   1. NTP uses a h**ierarchical, semi-layered system of time sources**. **Each level of this hierarchy is termed a stratum and is assigned a number starting with zero for the reference clock at the top**.
      1. A **server synchronized to a stratum n server runs at stratum n + 1**. **The number represents the distance from the reference clock** and is used to prevent cyclical dependencies in the hierarchy. Stratum is **not always an indication of quality or reliability**; it is common to find stratum 3 time sources that are higher quality than other stratum 2 time sources.
   2. A brief description of strata 0, 1, 2 and 3 is provided below.
      1. Stratum 0
         1. These are **high-precision timekeeping devices such as atomic clocks, GPS or other radio clocks**. They generate a very accurate pulse per second signal that triggers an interrupt and timestamp on a connected computer. Stratum 0 devices are also known as reference clocks.
      2. Stratum 1
         1. These are computers whose system time is **synchronized to within a few microseconds of their attached stratum 0 devices**. **Stratum 1 servers may peer with other stratum 1 servers for sanity check and backup**. They are also referred to as **primary time servers**.
      3. Stratum 2
         1. These are computers that are synchronized over a network to stratum 1 servers. Often a stratum 2 computer will query several stratum 1 servers. Stratum 2 computers may also peer with other stratum 2 computers to provide more stable and robust time for all devices in the peer group.
      4. Stratum 3
         1. These are computers that are synchronized to stratum 2 servers. They employ the same algorithms for peering and data sampling as stratum 2, and can themselves act as servers for stratum 4 computers, and so on.
   3. The NTP algorithms on each computer interact to construct a Bellman-Ford shortest-path spanning tree, to minimize the accumulated round-trip delay to the stratum 1 servers for all the clients.
3. Clock synchronization algorithm
   1. A typical NTP client will regularly poll one or more NTP servers. To synchronize its clock, the client must compute its time offset and round-trip delay. Time offset is defined by ((t1 - t0 ) + (t2 - t3)) / 2. Round-trip delay is (t3-t0) - (t2-t1).
      1. Where t0, is client's timestamp of the request packet transmission, t1 is the server's timestamp of the request packet reception, t2 is the server's timestamp of the response packet transmission and t3 is the client timestamp of the response packet reception.
   2. **Time offset and round trip delay are passed through filters and subjected to statistical analysis. Outliers are discarded and an estimate off time offset is derived from the best three remaining candidates**. The clock frequency is then adjusted to reduce the offset gradually, creating a feedback loop.
4. Implementations
   1. Simple Network Time Protocol (SNTP)
      1. A less complex implementation of NTP, using the same protocol but **without requiring the storage of state over extended periods of time**. It is **used in some embedded systems and in applications where full NTP capability is not required**.
   2. Windows Time Service
   3. OpenNTPD
   4. NTPSec
   5. Chrony
5. Security concerns
   1. Several security concerns arose in late 2014. Previously, researchers became aware that **NTP servers can be susceptible to man-in-the-middle attacks unless packets are cryptographically signed for authentication**. The **computational overhead involved can make this impractical on busy servers**, particularly during denial of service attacks. **NTP message spoofing** can be used to **move clocks on client computers and allow a number of attacks based on bypassing of cryptographic key expiration**. Some of the **services affected by fake NTP messages identified are TLS, DNSSEC, various caching schemes (such as DNS cache), BGP, Bitcoin and a number of persistent login schemes**.
   2.

## Precision Time Protocol (PTP)

1. Definition
   1. A protocol used to synchronize clocks throughout a computer network. **On a local area network, it achieves clock accuracy in the sub-microsecond range**, making it **suitable for measurement and control systems**.
   2. It's currently employed to synchronize financial transactions, mobile phone tower transmissions, sub-sea acoustic arrays, and networks that require precise timing but lack access to satellite navigation signals.
   3. Defined in the IEEE 1588 standardization effort. It's used to fill a niche not well served by either of the two dominant protocols, NTP and GPS.
      1. It's designed for local systems requiring accuracies beyond those attainable using NTP. Designed for applications that cannot bear the cost of a GPS receiver at each mode, or for which GPS signals are inaccessible.
2. Architecture
   1. Master-slave architecture. A time distribution system **consists of one or more communication media, and one or more clocks**.
      1. **An ordinary clock is a device with a single network connection** and is either the **source of (master) or destination for (slave) a synchronization reference**.
      2. **A boundary clock has multiple network connections** and can **accurately synchronize one network segment to another**. A **synchronization master is selected for each of the network segments in the system**. The root timing reference is called the grandmaster.
3. Synchronization
   1. Through use of the BMC algorithm, **PTP selects a master source of time for an IEEE 1588 domain and for each network segment in the domain**.
   2. Clocks determine the offset between themselves and their master

# Comparing NTP with PTP

1. Comparison
   1. NTP is cheaper, because the clients are free, and no special switches are required. Most system integrators buy dedicated servers, since that saves them the trouble of integrating a GPS receiver (to get standard time) with an NTP server. But each server can keep thousands of clients happy and on time
   2. In the case of **PTP, a slave synchronizes to a master clock, which other masters listen in, so that they can take over if the active master goes away for any reason**. That’s good, but **NTP does one better**. The client gets time from all of the servers and **ignore one which seems to be too far off in time compared to the other servers**.
