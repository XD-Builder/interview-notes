# Abstract

- This document explores features of Tor browser and its inner workings to achieve anonymity

## Tor Browser

1. Definition of Tor Browser
   1. A browser that uses the Tor network to protect your privacy and anonymity.
   2. Tor browser has two main properties
      1. Your ISP and anyone watching your connection locally, w**ill not be able to track your internet activity**, including the names and addresses of the websites you visit
      2. The operators of the websites and services that you use, and anyone watching them, **will see a connection coming from the Tor network instead of your real Internet (IP) address**, and will not know who you are unless you explicitly identify yourself.
   3. Additional feature
      1. Designed to prevent websites from "fingerprinting" or identifying you based on your browser configuration. It does not keep any browsing history by default. Coolies are only valid for a single session.
2. How to circumvent blocking access to Tor?
   1. Direct access to the Tor network may sometimes be blocked by your ISP or by a government. Tor Browser includes some circumvention tools, called "pluggable transport" for getting around these blocks.
   2. Pluggable Transports
      1. Tools that Tor Browser can use to disguise the traffic it sends out.
   3. Bridges
      1. Most Pluggable Transports rely on the use of "bridge" relays.
      2. Like ordinary Tor relays, bridges are run by volunteers but they are not listed publicly so an adversary cannot identify them easily.
   4. Types of pluggable transport
      1. obfs3 => makes Tor traffic look random so that it does not look like Tor or any other protocol.
      2. obfs4 => similar to bfs3 but also prevents censors from finding bridges by Internet scanning. It's less likely to be blocked.
      3. Scramblesuit => Similar to obfs4 but has a different set of bridges
      4. FTE => Format-transforming encryption, disguises Tor traffic as ordinary web trafic
      5. meek => meek-amazon makes it look like you are using Amazon Web Services. meek-azure, meek-google,...
      6. Snowflake => An improvement upon Flashproxy and it sends your traffic through WebRTC, a P2P protocol with built-in NAT punching.
3. How to manage identities?
   1. Background
      1. When you connect to website, it is not only the website admin can record information about your visit, there can be third-party services, including social network "Like" buttons, analytics, trackers, and advertising beacons, all of which can link your activity across different sites.
   2. What Tor does?
      1. Tor network stops observers from being able to discover your exact location but it doesn't prevent your activities to be linked together to identify you.
   3. What Tor Browser does?
      1. Tor establishes a unique Tor circuit for each URL you connect. It forces different Tor circuit for different URLs so that tracker will not know that both connections orignate from your browser.
   4. Why Logging in over Tor?
      1. There may be situations in which it makes sense to use Tor with websites that require username, passwords, or other identifying information. Logging into a website using a regular browser means you reveal your IP address and geographical location in the process. The same for sending an email.
         1. Logging into your social networking or email accounts using Tor Browser allows you to choose exactly which information you reveal to the websites you browse.
   5. What is Tor Browser New Identity and New Tor Circuit?
      1. New Identity is used to prevent your subsequent browser activity from being linkable to what you were doing before. Selecting this option in browser will close all your open tabs and windows, clear all private info such as cookies and browsing history, and use new Tor circuits for all connections.
      2. New Tor Circuit for this Site is used for in case your exit relay is unable to connect to the website you require or is not loading it properly. Selecting this option will cause the currently-active tab or window to be reloaded over a new Tor circuit. Other tabs and windows from the same URL will use the new circuit as well once they are loaded. This does not clear any private information or unlink your activity, or affect your concurrent connection to other websites.
4. Introduction to Onion Services
   1. Definition
      1. Onion services (formerly known as "hidden services") are services, like websites, that are only accessible through the Tor network.
   2. Advantages over ordinary services on the non-private web
      1. An **onion services' location and IP address are hidden**, making it difficult for adversaries to censor it or identify its operators.
      2. All traffic between Tor users and onion services are **end-to-end encrypted**, so you do not need to worry about connecting over HTTPS.
      3. The address of an onion service is **automatically generated**, so the operators **do not need to purchase a domain name**; the .onion URL also helps Tor **ensure that it is connecting to the right location** and that **the connection is not being tampered with**.
   3. How to access an onion service?
      1. You need to know the address of an onion service in order to connect to it.
         1. An onion address is a string of 16 mostly random letters and numbers, followed by ".onion".
   4. How do you know your connection to an onion service is secure?
      1. Tor Browser shows at the URL bar an icon of a little green onion displaying the state of your connection: secure and using an onion service.
      2. If you are accessing a website with https and onion service, it will show an icon of a green onion and a padlock.
5. Secure Connections
   1. Background
      1. If personal or login information travels unencrypted over the Internet, it can easily be intercepted by an eavesdropper.
   2. Encryption
      1. If your connection is encrypted, the address will begin with "https://" rather than "http://".
   3. What Tor and HTTPS means to **hackers, local ISP operators, NSA, target ISP and target site operators**?
      1. Without Tor and HTTPS
         1. Everyone can see the site your are going, username/password and other request data you entered, and your location data.
      2. With HTTPS
         1. Everyone can see the site you are going and your location.
         2. Only target site operators can see your request data and body.
      3. With TOR
         1. Everyone can see location of TOR only.
         2. Tor Exit Relay can see target site, username/password and request data.
         3. NSA, target ISP and target site can see username/password and request data.
      4. With TOR and HTTPS
         1. Everyone can only see the site you're visiting and the location of TOR.
         2. Target site operators can see TOR location and all request data.
6. What does plugins, add-ons and JavaScript mean to your online anonymity?
   1. Flash Player
      1. Flash Player plugin used to display video content operates independently of Tor Browser and cannot easily be made to obey Tor Browser's proxy settings. In order to avoid identity exposure, Flash is disabled by default. Some sites such as YouTube offer alternative video delivery methods that do not use Flash and thus compatible with Tor Browser.
   2. JavaScript
      1. A programming language that websites use to offer interactive elements such as video, animation, audio, and status timelines.
      2. It enable attacks on the security of the browser which might lead to de-anonymization.
      3. Add-on NoScript allows you to control the JS that runs on individual web pages or block it entirely.
7. Why you should use up-to-date software?
   1. If you continue to use an outdated version of the software, you may be vulnerable to serious security flaws that compromise your privacy and anonymity and therefore you must keep it up to date.
8. How to troubleshoot Tor Browser connectivity issues?
   1. What to do when Tor Browser doesn't connect?
      1. Set computer's system clock correctly.
      2. Make sure Tor Browser is not already running and no antivirus program is preventing Tor from running.
      3. Temporarily disable firewall or delete and reinstall Tor Browser again.
   2. If still unable to connect?
      1. The ISP might be censoring connection to the Tor network. Try Circumvention section above.

## Tor Network

1. Definition
   1. A network of virtual tunnels that allows you to improve privacy and security on the Internet.
2. How it works?
   1. Tor Network sends your traffic through three random servers known as relays in the Tor network. The last relay in the circuit, the exit relay, then sends the traffic out onto the public Internet.

### Onion routing

1. Definition
   1. A technique for anonymous communication over a computer network.
   2. In an onion network, messages are encapsulated in layers of encryption, analogous to layers of an onion. The encrypted data is transmitted through a series of network nodes called onion routers, each of which "peels" away (decrypts) a single layer, uncovering the data's next destination. When the final layer is decrypted, the message arrives at its destination.
      1. The sender remains anonymous because each intermediary knows only the location of the immediately preceding and following node.
      2. There are methods to break the anonymity of this technique like timing analysis.
2. Data Structure
   1. An onion is a data structure formed by "wrapping" a message with successive layers of encryption to be decrypted by as many intermediary computers as there are layers before arriving at its destination.
      1. The original message remains hidden as it is transferred from one node to next and no intermediary knows both the origin and final destination of the data, allowing the sender to remain anonymous.
3. Onion creation and transmission
   1. To create and transmit an onion, the originator selects a set of nodes from a list provided by a "directory node". The chosen nodes are arranged into a path, called a "chain" or "circuit", through which the message will be transmitted.
   2. To preserve the anonymity of the sender, no node in the circuit is able to tell whether the node before it is the originator or another intermediary like itself and no nodes is able to tell how many other nodes are in the circuit and only the final node, the "exit node", is able to determine its own location in the chain.
   3. Originator obtains a public key from the directory node to send an encrypted message to the first ("entry") node, establishing a connection and a shared secret ("session key"). Using established encrypted link to the entry node, the originator can then relay a message through the first node to a second node in the chain using encryption that only the second node, and not the first, can decrypt.
4. Vulnerability
   1. Timing Analysis
      1. The ability of ISP to trace and log connections between computers means anonymity of TORs can be broken.
      2. Traffic analysis searches records of connections made by a potential originator and tries to match timing and data transfers to connections made to a potential recipient.
   2. Exit node vulnerability
      1. Although the message being sent is transmitted inside several layers of encryption, the job of the exit node, as the final node in the chain, is to decrypt the final layer and deliver the message to the recipient.
      2. A compromised exit node is thus able to acquire the raw data being transmitted.
         1. A Swedish researcher, used such an attack to collect passwords of over 100 email accounts related to foreign embassies.
      3. Exit node vulnerabilities are similar to those on unsecured wireless networks, where the data being transmitted by a user on the network may be intercepted by another user or by the router operator. Both issues are solved by using a secure end-to-end connection like SSL and secure HTTP.
   3. Software Vulnerability
      1. Achieved by exploiting vulnerable software on the user's computer.
      2. NSA targets a Tor users for close monitoring under its XKeyscore program.
      3. Attacks against Tor are an active area of academic research which is welcomed by the Tor Project itself. The bulk of the funding for Tor's development has come from the federal government of the US, initially through the Office of Naval Research and DARPA.

## XKeyscore

1. Definition
   1. A complicated system that enables almost unlimited surveillance of anyone anywhere in the world.
   2. A data retrieval system which consists of a series of user interfaces, backend databases, servers and software that selects certain types of data and metadata that the NSA has already collected using other methods.
   3. A passive program meaning it listens, but does not transmit anything on the networks that it targets. However it can trigger other systems, which perform "active" attacks.
2. Uses
   1. Read emails, website's traffic to and from.
   2. Watch any computer that an individual sits at, follow laptops as it moves from place to place.
   3. Build a fingerprint of one's unique online activity.
