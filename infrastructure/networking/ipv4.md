# IPv4

## IPv4 Introduction

1. Motivation
   1. IP is designed for use in interconnected systems of packet-switched computer computer communication networks. It provides for transmitting blocks of data called datagrams from sources to destinations, where sources and destinations are hosts identified by fixed length addresses. It also provides fragmentation and reassembly of long datagrams, if necessary, for transmission through "small packet" networks
2. Scope
   1. IP is limited in scope to provide the functions necessary to deliver a package of bits from a source to a destination over an interconnected system of networks. There are no mechanisms to augment end-to-end data reliability, flow control, sequencing, or other services commonly found in host-to-host protocols. It capitalizes on the services of its supporting networks to provide various types and qualities of service
3. Interfaces
   1. This protocol is called on by host-to-host protocols in an internet environment. It calls on local network protocols to carry the internet datagram to the next gateway or destination host.
      1. Ex. TCP module would call on the internet module to take a TCP segment (including the TCP header and user data) as the data portion of an internet datagram. The TCP module would provide the addresses and other parameters in the internet header to the internet module as arguments of the call. The internet module would then create an internet datagram and call on the local network interface to transmit the internet datagram.
4. Operation
   1. The IP implements two basic functions: **addressing and fragmentation**
      1. The internet modules use the address carried in the internet header to transit internet datagrams toward their destinations. **The selection of a path for transmission is called routing**
      2. The internet modules use fields in the internet header to fragment and reassemble internet datagrams when necessary for transmission through "small packet" networks.
      3. The mode of operation is that an internet module resides in each host engaged in internet communication and in each gateway that interconnects networks. These modules share common rules for interpreting address fields and for fragmenting and assembling internet datagrams. In addition, these modules have procedures for making routing decisions and other functions.
      4. The internet protocol treats each internet datagram as **an independent entity unrelated to any other internet datagram**.
      5. Four key mechanisms in providing its service are **Type of Service, Time to Live, Options, and Header Checksum.**
         1. TOS - used to indicate the quality of the service desired. This is used by gateways to select the actual transmission parameters for a particular network, the network to be used for the next hop, or the next gateway when routing an internet datagram.
         2. TTL - indicates an upper bound on the lifetime of an internet datagram. It's set by the sender of the datagram and reduced at the points along the route when it is processed.
         3. Options - provides for control functions needed or useful in some situations but unecessary for the most common communications. The options include provisions for timestamps, security, and special routing.
         4. Header Checksum - provides a verification that the information used in processing internet datagram has been transmitted correctly. The data may contain errors. If the header checksum fails, the internet datagram is discarded at once by the entity which detects the error.
   2. What IP doesn't provide
      1. There are no reliable communication facility.
      2. There are no acknowledgments either end-to-end or hop-by-hop.
      3. There is no error control for data, only a header checksum.
      4. There are no retransmissions.
      5. There is no flow control.

## IP Overview

1. Relation to Other Protocols
   1. IP ICMP interfaces on one side to the higher level host-to-host protocols and on the other side to the local network protocol.
      1. In this context a "local network" may be small network in a building or a large network such as ARPANET.
2. Model of Operation
   1. Sample Scenario for transmitting a datagram from one app to another.
      1. Assumption
         1. This transmission will involve one intermediate gateway.
      2. The sending app prepares its data and calls on its local internet module to send that data as a datagram and passes the destination address and other parameters as arguments of its call.
      3. The internet module prepares a datagram header and attaches the data to it. The internet module determines a local network address for this internet address, in this case it is the address of a gateway.
      4. It sends this datagram and the local network address to the local network interfaces.
      5. The local network interface creates a local network header, and attaches the datagram to it, then sends the result via the local network.
      6. The datagram arrives at a gateway host wrapped in the local network header, the local network interface strips off this header, and turns the datagram over to the internet module. **The internet module determines from the internet address that the datagram is to be forwarded to another host in a second network.** The internet module **determines a local net address for the destination host**. It calls on the local network interface for that network to send the datagram.
      7. The local network interface **creates a local network header and attaches the datagram** sending the result to the destination host.
      8. At this destination host the datagram is **stripped of the local net header by the local network interface** and handed to the internet module.
      9. The **internet module determines that the datagram is for an application** in this host. It passes the **data to the app in response to a system call, passing the source address and other parameters** as result of the call.
3. Function Description
   1. The function or IP is to **move datagram through an interconnected set of networks** and it's done by **passing the datagrams from one internet module to another until the destination is reached**. The internet module **reside in hosts and gateways in the internet system**. The datagram are **routed from one internet module to another through individual networks based on the interpretation of an internet address.** Thus on **important mechanism of the IP is the internet address**.
   2. The routing of messages from one internet module to another means datagrams may need to traverse a network whose maximum packet size is smaller than the size of the datagram. To overcome this difficulty, a fragmentation mechanism is provided in the IP.
   3. Addressing
      1. It's the task of higher level protocols to make the mapping from name to addresses. The internet module maps internet address to local net address. It is the task of lower level procedures to make the mapping from local net addresses to routes.
      2. Addresses are fixed length of four octets.
         1. Class A internet addresses have high order bit zero, the next 7 bits for network and last 24 for local address.
         2. Class B internet addresses have high order two bits one-zero, the next 14 bits class network and the last 16 bits local address.
         3. Class C internet addresses have high order three bits one-zero-one, the next 21 bits are the network and the last 8 bits local addresses.
   4. Fragmentation
      1. Fragmentation is necessary when it originates in a local net that allows a large packet size and must traverse a local net that limits packets to a smaller size to reach its destination
      2. An internet datagram can be marked "don't fragment". Any internet datagram so marked is not to be internet fragmented under any circumstances. If internet datagram marked don't fragment cannot be delivered to its destination without fragmenting it, it is to be discarded instead.
      3. To Fragment a long internet datagram, an internet protocol module creates two new internet datagrams and copies the contents of the internet header fields from the long datagram into two portions on a octet boundary.
      4. To assemble the fragments of an internet datagram, an internet protocol module combines internet datagrams that all have the same value for the four fields: identification, source, destination, and protocol. The combination is done by placing the data portion of each fragment in the relative position indicated by the fragment offset in that fragment's internet header. The first fragment will have the fragment offset zero, and the last fragment will have the more-fragments flag reset to zero.
4. Gateways
   1. Implements internet protocol to forward datagrams between networks. It also implements the Gateway to Gateway Protocol(GGP) to coordinate routing and other internet control information.
   2. In a gateway the higher level protocols need not be implemented and the GGP functions are added to the IP module
5. IP Header Format
   1. Version - 4 bits
   2. IHL - 4 bits (Internet Header Length)
   3. TOS - 8 bits
   4. Total Length - 16 bits
   5. Identification - 16 bits
   6. Flags - 3 bits (For fragmenting the datagram)
   7. Fragment Offset - 13 bits (the current offset of the datagram fragment)
   8. TTL - 8 bits (A node decrements one or the time when processed by a node, not a good measure, considered as an upper bound)
   9. Protocol - 8 bits (indication of the next protocol used in the data portion of the internet datagram)
   10. Header Checksum - 16 bits (is on header only)
   11. Source Address - 32 bits
   12. Destination Address -32 bits
   13. Options - 24 bits (defined options include security, loose/strict source routing, record route, stream id, oor timestamp )
   14. Padding - 8 bits (Ensure header padding is used to ensure that the internet header ends on a 32 bit boundary)
