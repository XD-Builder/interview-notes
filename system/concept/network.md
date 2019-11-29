# Abstract
1. This document explores different network interfaces, their histories and implementations

## Wi-Fi Protected Access
1. WPA History
    1. An intermediate measure to take the place of WEP by Wi-Fi Alliance. It could be implemented through firmware upgrades on wireless network interface cards designed for WEP that began shipping as back as 1999.
    2. The WPA protocol implements much of IEEE 802.11i standard. Specifically the Temporal Key Integrity Protocol was adopted for WPA.
        1. WEP used a 64-bit or 128-bit encryption key that must be manually entered on wireless access points and devices and does not change. Whereas TKIP employs a per-packet key, meaning it dynamically generates a new 128-bit key for each packet and thus prevents the types of attacks that compromised WEP.
    3. WPA also includes Message Integrity Check designed to prevent an attacker from altering and resending data packets.
        1. It replaces CRC that was used by the WEP standard as CRC's main flaw was that it didn't provide a sufficiently strong  data integrity guarantee for packet it handled. TKIP is much stronger than a CRC, but not as strong as the algorithm used in WPA2.
2. WPA2 History
    1. WPA2 replaced WPA. It includes mandatory support for CCMP (Counter Mode Cipher Block Chaining Message Authentication Code Protocol), an AES-based encryption mode. Certification began in September 2004; from March 13, 2006, WPA2 certification is mandatory for all new devices to bear the Wi-Fi trademark.
3. WPA3 History
    1. In January 2018, the Wi-Fi Alliance announced WPA3 as a replacement to WPA2. The new standard uses 128-bit encryption in WPA3-Personal mode (192-bit in WPA3 and forward secrecy.
    2. The WPA3 standard also replaces the Pre-Shared Key exchange with Simultaneous Authentication of Equals resulting in a more secure initial key exchange in personal mode.
4. WPA-EPA
    1. It's not an authentication system but a protocol for transporting authentication information. It's used to protect wireless networks in enterprises. It's used to protect wireless networks in enterprises and thus scarcely used in private networks, thus WPA Enterprise and WPA-EAP are synonymous.
    2. EAP needs a Radius server and offers three different methods for connecting and authenticating to the server.
        1. TLS authentication relies on the mutual exchange of certificates for both server and client. First the server presents its certificate to the client where it is evaluated. If the server certificate is valid, the client then presents its certificate to the server. While TLS is secure, it requires a working certificate management infrastructure in your network and it's rarely found in private network.
        2. TTLS (Tunneled Transport Layer Security (TTLS) - An EAP protocol that extends TLS.
        3. EAP-PEAP (Protected Extensible Authentication Protocol) - TTLS and PEAP are two-stage protocols. The first stage is to establish a secure connection and second stage is for the client authentication data to be exchanged. Both require far less certification management overhead than TLS.
    3. Major EAP-TLS include EAP-PEAP/*, EAP-TTLS, EAP-PSK.
5. Terminologies
    1. see [glossary](../glossary.md)

