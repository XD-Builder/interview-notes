## Master Web Attacks with Full-Stack Exploitation

1. Background
   1. Until 2017 HackerOne bug hunters have earned $20 million in bug bounties and they are expected to earn $100 million by the end of 2020. Some of the HackerOne customers include the US State Department of Defense, GM, Uber, Twitter, and Yahoo.
   2. Modern web apps are complex and it's all about full-stack nowadays.
2. Learn
   1. REST API, AngularJS-based exploits
   2. DOM-based exploits
   3. Bypass Content Security Policy
   4. Server-side request forgery
   5. Browser-dependent exploits
   6. DB truncation attack
   7. NoSQL injection
   8. Type confusion vulnerability
   9. Race conditions exploits
   10. Path-relative stylesheet import vulnerability
   11. Reflected file download vulnerability
   12. Subdomain takeover

## Mapping and Tracking WiFi Networks/Devices without Being Connected

1. Background
   1. WiFi hacking has been around for a while, and everyone knows about tools like airmon-ng, kismet, et al. But what if you just want to view a list of all networks in your area along with all the devices connected to them? Or maybe you want to know who's hogging all the bandwidth? Or you want to know when someone's cellphone is nearby? Or perhaps you'd like to know if your Airbnb host's IP Camera is uploading your video to the cloud?
2. Goal
   1. Research tool "trackerjacker" on how it explores some of the suprisingly informative data floating around in radio space.

## Mobile App exploits

1. Background
   1. Mobile Apps are the most preferred way of delivering attacks today. Understanding the finer details of Mobile App attacks is soon becoming an essential skill for penetration testers as well as for app developers and testers.
2. Learn
   1. Android Exploitation
      1. ARM CPU, Architecture, Registers and Modes of Operations, ARM Assembly, Debugging, Stack Overflow in ARM, writing shellcode exploits
   2. iOS Exploitation
      1. iOS Security Basics
      2. Reverse Engineering iOS Apps
      3. Static analysis and Dynamic Analysis
      4. Jailbreak Detection and Bypass
      5. Identifying and Exploiting Flaws in Apps
      6. Finding Security flaws in real world.

## Malware Analysis Intro

1. Background
   1. With Malware featuring crypto-trojans(ransomware), banking-trojans, information- and credential-stealers, bot-nets of various specifications, and last but not least, industry- or even state-driven cyber espionage, the analysis of this kind of software is becoming more and more important these days.
2. Goal
   1. How easy it is to get infected by malicious software
   2. Access what's possible and what isn't
   3. Gain a comprehensive overview of the various malware categories and their according specifics.
   4. Find out what malware analysts do
   5. Develop and hence understand typical strategic concepts and tactics in reverse engineering
   6. Build a basic understanding of typical activities when dealing with cyber security incidents
   7. Develop a realistic perspective regarding possibly upcoming malware incidents regarding their company.
3. Learn
   1. Prologue - Who? How? What? Malware categories, adversaries, motives
   2. The lab - Setup, concepts, strategies, pitfalls and common mistakes
   3. Initial incident handling
   4. Sample Extract - find a needle in the haystack
   5. Behavior Analysis - eavesdropping the OS
   6. Code Analysis - Machine code, portable executables, disassemblers, debuggers, strategies

## Attacking IoT with Software Defined Radio

1. Learning
   1. Learn to reverse engineer the wireless communication between IoT devices with Software Defined Radio using the Universal Radio Hacker(URH)
   2. Learn HF basics such as digital modulations and encodings, how to reveal the protocol logics and develop attacks.
   3. Investigate and attack a wireless socket and smart home door lock
2. Steps
   1. Pick up raw signals with SDR
   2. Modulation of raw signals to get Bits
   3. Decoding of Bits
   4. Reverse engineering of the protocol format (where are addresses, sequence numbers etc.)
   5. Developing of attacks with fuzzing and simulation.

## Security Risks in Cellular Networks: Phone, RAN, and Core

1. Goal
   1. Have a general overview of cellular technology, the structure and function of mobile networks, and types of security flaws common to all mobile networks, some of which are unavoidable.
2. Learn
   1. Describe shortcomings in mobile networks, both in the core network and in radio network, for GSM, UMTS, and LTE.
   2. Understand the risks associated with using mobile devices.

## Advanced Penetration Testing in Real World

1. Learn
   1. Buffer overflow - find and exploit buffer overflows and bypass OS protections
   2. Web exploitation - manually find and exploit web app vulnerabilities using Burpsuite
   3. Network exploitation - manually exploit network related vulnerabilities using Scapy, ethercap and Responder
   4. Passwords - optimize the way you attack offline and online passwords (0day is fun, but the way attackers again access most of the time is simply using login/passwords)
   5. Mobile app hacking - find and exploit Android/iOS app vulnerabilities using Needle, Frida, Cycript and Hopper
