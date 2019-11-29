# Abstract

- This document explores components of VLAN.

## VLANs and Trunking

1. Why VLAN?
   1. **Control over collisions, increased throughput**, and the additional features offered by switches all provide ample incentive to upgrade infrastructure
   2. But Layer 2 switched topologies are not without their difficulties. **Extensive flat topologies can create congested broadcast domains and can involve compromises with security, redundancy, and load balancing**. **These issues can be mitigated through the use of virtual local area networks, or VLANs**. This chapter provides the structure and operation of VLANs as standardized in IEEE 802.1Q
   3. **As the number of network nodes increases, the amount of overhead also increases. Each switch might be connected to dozens of nodes, with each node generating the several broadcast frames.** If enough traffic is created, even a switched network can have poor performance. Deploying **VLANs can help solve this problem by breaking up the broadcast domain and separating the traffic.**
2. What is VLAN?
   1. A virtual local area network (VLAN) is **a logical grouping of ports which is independent of location**. **A single VLAN (and the nodes connected in a single VLAN) will behave in the same way as if it was a separate Layer 3 network**.
      1. VLAN membership need not be limited to sequential ports or even ports on the same switch
   2. On a switch after a router, all of nodes connected are actually part of the same VLAN. So, another way to think about this topology is based on the VLAN. **For example, with Cisco devices the default VLAN is VLAN 1.** This is also called the **management VLAN**. Its **initial configuration includes all ports as members and this reflected in the source address table or SAT**. This table is **often described as being used to forward frames to the proper Layer 2 port based on the destination MAC**. With the introduction of VLANs, **the source address table reflects the port to MAC address mapping on a per-VLAN basis resulting in more advanced forwarding decisions**.
   3. show mac-address-table and show vlan commands.
      1. show mac-address-table
         1. Shows all of the ports (Fa0/1 – Fa0/24) are in VLAN 1.
      2. show vlan
         1. show active vlan with vlan number and ports.
   4. A common topology is that two switches are separated by a router. In this case, a group of nodes are connected to each switch. **The nodes on a particular switch share a common IP addressing scheme**. There are **two networks, 192.168.1.0 and 192.168.2.0**.
      1. Note that **both of the switches have the same VLAN since, in the absence of any configuration changes, switches from the same vendor will have the same numbering convention**. **Nonlocal network traffic must be sent to the router for forwarding. Routers will not forward Layer 2 unicast, multicast and broadcast frames**. VLANs provide a very similar logical topology in that **nodes within a VLAN share a common addressing scheme and that nonlocal traffic (traffic destined for nodes on a different VLAN) must be sent to the router for forwarding**.
         1. Thus VLAN1 in in Switch 1 connected to a router which connects to VLAN1 in Switch 2 will be able to forward traffics even though two switches don't physically connect.
      2. **A VLAN operates in the same way as a Layer 3 IP-based network. Thus, nodes on the 192.168.1.0 network must go to the router when trying to communicate with nodes on the 192.168.2.0 network even though all of the computers are connected to the same switch.** In order to communicate between VLANs, **routing functionality must be part of the topology**. **Layer 2 unicast, multicast and broadcast traffic will not cross VLAN boundaries**, therefore **traffic generated on VLAN 1 will not be seen by nodes on VLAN 2**. **Only the switch is aware of the VLANs**. **The nodes and the router have no idea that VLANs are in use—they are “non VLAN-aware.”** With the addition of the routing decision, **Layer 3 functionality can now be leveraged for additional security settings, problem/traffic containment and load balancing**.
   5. VLAN nodes location
      1. Since VLANs are **logical groupings of nodes** that are **independent of location**, it does not matter where the nodes connect. Figure 4-8 demonstrates this concept.
      2. It is often the case that network technicians do not wish to rewire the topology every time that a new node is connected. So, **a host may simply be connected to any available port and the port is then assigned to a particular VLAN**.
   6. Dynamic VLANs
      1. **The most common method of assigning dynamic VLAN membership is via the MAC address**. As soon as the node generates a single frame, the switch completes the MAC address query and then assigns the port. The nodes still do not have any knowledge that VLANs are used. VLAN membership **can also be based on other criteria or tied to authentication schemes such as 802.1X**.
