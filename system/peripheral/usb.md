# Abstract

- This document explores USB, how it actually works, and its dark sides

## Universal Serial Bus

1. Definition
   1. USB is an industry standard that establishes specifications for cables, connectors and protocols for connection, communication and power supply between personal computers and their peripheral devices.
2. Purpose
   1. USB was designed to standardize the connection of peripherals like keyboards, pointing devices, digital still and video cameras, printers, portable media players, disk drivers and network adapters to personal computers, both to communicate and to supply electric power.
      1. It's increasingly replacing other types of battery chargers of portable devices.
      2. USB 1.0 => 1996 => 1.5MB/s full speed
      3. USB 2.0 (Revised) => 2001 => 60MB/s
      4. USB 3.0 => 2011 => 625 MB/s (SuperSpeed)
      5. USB 3.1 & 3.2 => 2014 & 2017 => 1.2GB/s, 2.5GB/s (SuperSpeed+)
3. Benefits
   1. The USB interface is self-configuring, so the user need not adjust settings on the device and interface for speed or data format, or configure interrupts, input/output addresses, or direct memory access channels.
   2. USB connectors are standardized at the host, so any peripheral can use any available receptacle. It takes full advantage of the additional processing power that can be economically put into peripheral devices so that they can manage themselves.
   3. The USB interface is "hot pluggable", meaning devices can be exchanged without rebooting the host computer.
   4. When a device is plugged into a port on a running personal computer system, it is either entirely automatically configured using existing device drivers, or the system prompts the user to locate a driver which is then installed and configured automatically.
   5. For hardware manufacturers and software developers, the USB standard eliminates the requirement to develop proprietary interfaces to new peripherals.
   6. The wide range of transfer speeds available from a USB interface suits devices ranging from keyboards and mice up to streaming video interfaces
   7. A USB interface can be designed to provide the best available latency for time-critical functions, or can be set up to do background transfers of bulk data with little impact on system resources.
4. Limitations
   1. cables are limited in length, as the standard was meant to connect to peripherals on the same table-top, not between rooms or between buildings
   2. USB has a strict "tree" topology and "master-slave" protocol for addressing peripheral devices; peripheral devices cannot interact with one another except via the host, and two hosts cannot communicate over their USB ports directly.
   3. A host cannot "broadcast" signals to all peripherals at once, each must be addressed individually. Some very high speed peripheral devices require sustained speeds not available in the USB standard.
   4. For a product developer, use of USB requires implementation of a complex protocol and implies an "intelligent" controller in the peripheral device.
   5. Developers of USB devices intended for public sale generally must obtain a USB ID which requires a fee paid to the Implementers' Forum.
   6. Developers of products that use the USB specification must sign an agreement with Implementer's Forum. Use of the USB logos on the product require annual fees and membership in the organization.
5. History
   1. A group of seven companies began the development of USB in 1994, Compaq, DEC, IBM, Intel, Microsoft, NEC, and Nortel with a goal to make it fundamentally easier to connect external devices to PCs by replacing the multitude of connectors at the back of PCs, addressing the usability issues of existing interfaces, and simplifying software configuration of all devices connected to USB, as well as permitting greater data rates for external devices.
   2. USB 1.0 specification is released in 1996, and defined data transfer rates of 1.5 Mbit/s Low Speed and 12 Mbit/s Full Speed.
   3. USB 2.0 specification was released in April 2000 was ratified by the USB Implementers Forum at the ned of 2001.
   4. USB 3.0 specification was published on 11/12/2008. Its main goals were to increase the data transfer rate (up to 5Gbit/s), decrease power consumption, increase power output, and be backward compatible with USB 2.0.
   5. USB 3.1 specification was published in July 2013
   6. In December 2014, USB-IF submitted USB3.1, USB Power Delivery 2.0 and USB Type-C specifications to the IEC for inclusion in the international standard IEC Universal Serial Bus interfaces for data nad power.
6. System Design
   1. High Level
      1. A USB system consists of a host with one or more downstream ports, and multiple peripherals, forming a tiered-star topology.
      2. A USB host may have multiple controllers, either with one or more ports. Up to 127 devices may be connected to a single host controller.
   2. Communication
      1. Communication is based on pipes (logical channels). A pipe is a connection from the host controller to a logical entity, found on a device, named an endpoint.
      2. A USB could have up to 32 endpoints 16 in and 16 out.
      3. Endpoints are defined and numbered by the device during initialization, which is relatively permanent, whereas a pipe may be open or closed.
   3. Message pipe
      1. Short, simple commands to the device, and a status response, used, for example, by the bus control pipe number 0.
   4. Stream pipe
      1. A uni-directional pipe connected to a unidirectional endpoint that transfers data using an isochronous, interrupt, or bulk transfer.
         1. Isochronous transfers (meaning occurring at the same time)
            1. At some guaranteed data rate but with possible data loss
            2. Fixed bandwidth streaming data, realtime audio or video
         2. Interrupt transfers
            1. Device that need guaranteed quick responses (bounded latency) such as pointing devices, mice, and keyboards.
         3. Bulk transfers
            1. Large sporadic transfers using all remaining available bandwidth, but with no guarantees on bandwidth or latency (e.g., files transfers)
   5. Transfer
      1. When a host starts a data transfer, it sends a TOKEN packet containing an endpoint specified with a tuple of (device_address, endpoint_number).
      2. If the transfer is from the host to the endpoint, the host sends an OUT packet with the desired device address and endpoint number.
      3. If the data transfer is from the device to the host, the host sends an IN packet instead.
   6. Flow
      1. When a USB device is first connected to a USB host, the USB device enumeration process is started. It starts by sending a reset signal to the USB device. The data rate of the USB device is determined during the reset signaling.
      2. After reset, the USB device's information is read by the host and the device is assigned a unique 7-bit address.
      3. If the device is supported by the host, the device drivers needed for communicating with the device are loaded and the device is set to a configured state.
      4. If the USB host is restarted, the enumeration process is repeated for all connected devices.
   7. Security
      1. The Host controller directs traffic flow to devices, so no USB device can transfer any data on the bus without an explicit request from the host controller.
      2. In USB 2.0, the host controller polls the bus for traffic, usually in a round-robin fashion.
7. Device classes
   1. The functionality of a USB device is defined by a class code sent to a USB host. This allows the host to load software modules for the device and to support new devices from different manufacturers.
   2. Device classes include:
      1. 00h => Device => unspecified => interface descriptors are used to determine needed drivers
      2. 01h => Interface => audio => speaker, microphone, sound card, MIDI.
      3. 02h => Device & interface => Communications and CDC control => Modem, Ethernet adapter, Wi-Fi adapter, ...
      4. 03h => Interface => Human Interface Device (HID) => Keyboard, mouse, joystick
      5. 06h => Interface => Image (PTP/MTP) => Webcam, scanner
      6. .... to class FFh
8. Device Firmware Upgrade (DFU)
   1. What is?
      1. DFU is a vendor- and device-independent mechanism for upgrading the firmware of USB devices with improved versions provided by their manufacturers, offering a way to deploy firmware bug fixes.
