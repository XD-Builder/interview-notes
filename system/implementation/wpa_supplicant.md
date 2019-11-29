# Abstract
1. This document explains what WPA supplicant is, its cli tools configuration and troubleshooting.

## About WPA Supplicant
1. Definition
    1. A cross platform supplicant with support for WEP, WPA and WPA suitable for all systems.
        1. WPA stands for Wi-Fi Protected Access Client and IEEE 802.1X Supplicant
    2. It implements WPA key negotation with a WPA Authenticator and EAP authentication with Authentication Server. It controls the roaming and IEEE 802.11 authentication/association of the wireless LAN driver.
    3. Designed to be a daemon program that runs in the background and acts at the backend component controlling the wireless connection. it supports separate frontend programs and an example text-based frontend, *wpa_cli*, which  is included with wpa_supplicant.
2. Prerequisites for running wpa_supplicant
    1. The network interface must be available, the physical device must be present and enabled, and the driver for the device must be loaded.
    2. After network being configured, higher level configuration such as DHCP may proceed.
3. Steps wpa_supplicant uses to associate an AP using WPA
    1. It requests the kernel driver to scan neighboring BSSes
    2. It selects a BSS based on its configuration
    3. It requests the kernel driver to associate with the chosen BSS
        1. If WPA-EAP, integrated IEEE 802.1X Supplicant completes EAP authentication with the authentication server (proxied by the Authenticator in the AP). Master key is received from the IEEE 802.1X Supplicant
        3. If WPA-PSK, it uses PSK as the master session key
    4. It completes a WPA 4-Way Handshake and Group Key Handshake with the Authenticator (AP)
    5. It configures encryption keys for unicast and broadcast normal data packets can be transmitted and received.

## Drivers
1. Support for each of the driver backends is chosen at wpa_supplicant compile time
    - hostap
        - Default host AP driver
    - madwifi
        - MADWIFI 802.11 support (Atheros, etc.).
    - wext
        - Linux wireless extension (generic).
    - wired
        - wpa_supplicant wired Ethernet driver
    - bsd
        - BSD 802.11 support
