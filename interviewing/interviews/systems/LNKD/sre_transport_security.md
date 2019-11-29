# SSH & HTTPS 
## SSH
### Steps to ssh into a server with asymmetric key exchange - a local simulation
With version, "OpenSSH_7.6p1, LibreSSL 2.6.2", config file "~/.ssh/config" as below and running `ssh home`

    Host home*
        HostName example.com
        Port 5000

    Host *
        AddKeysToAgent yes
        UseKeychain yes
        IdentityFile ~/.ssh/id_rsa

1.  Reads configuration from ~/.ssh/config which may contain name to configurations for hostname, port, identity file, keychain and more...
2.  Finds home* and * both name match rules and applies configuration to current connection request.
3.  Connects to example.com port 5000 establishing a TCP connection.
4.  Loads identity file specified in "~/.ssh/config" and its certificate.
5.  Verifies compatibility of remote OpenSSH version and OS version with local OpenSSH and OS.
6.  Sends a list of preferred host key algorithms.
7.  Sends and receives SSH2_MSG_KEXINIT messages for negotiating highest available proposals for
    1.  KEX algorithms
    2.  ciphers ctos
    3.  ciphers stoc
    4.  MACs ctos
    5.  MACs stoc
    6.  compression ctos
    7.  compression stoc
    8.  miscellaneous
8.  After SSH2_MSG_KEX_DH_GEX_INIT sent, server's response pubkey is SHA256 hashed to match digest in "~/.ssh/known_hosts" file
9.  Defines rekey after x number of blocks and receives new session key from remote host and defines server-sig-algs used for message integrity digest.
10. Completes authentication by offering local public key to the server and use its private key to authenticate itself to remote host.
11. Creates a channel for a new client session, enters interactive mode and sets environment variable for the remote shell.

### Analysis
* Authentication - Steps
    * Steps 6-9 authenticates remote server with the known_hosts remote server pubkey and generates a session key.
    * Steps 10-11 authenticates local host and starts a new channel
* RFC notes
    * A key exchange method uses explicit server authentication if the key exchange messages include a signature or other proof of the server's authenticity.  A key exchange method uses implicit server authentication if, in order to prove its authenticity, the server also has to prove that it knows the shared secret, K, by sending a message and a corresponding MAC that the client can verify.
        * Explicit authentication - server signature provided during KEX.
        * Implicit authentication - server signature on shared key after KEX and send it to client.
* Authentication-- Two sides
    * Server Authentication:
        * Local host checks its "know_hosts" file containing a line with pubkey matching that of remote server's /etc/ssh/ssh_host_{host_key_algorithm}_key.pub file
        * Remote server authenticates itself with its /etc/ssh/ssh_host_{host_key_algorithm}_key
    * Local host Authentication:
        * Local host provides its local pubkey from id_rsa.pub to remote server to verify in its ~/.ssh/authorized_keys file.
        * Local host then authenticates itself to remote server using private key inside ~/.ssh/id_rsa file
* Network Packet - Steps
    1. Client queries DNS for remote host ip address on port 53 via UDP and sets target IP from DNS query answer
    2. Client performs TCP three-way Handshake with target ip and port 5000. 
    3. Client sends SSH, OpenSSH version to target and target responds with the same and OS version
    4. Client ACKs with a default list of KEX algorithm, host key algorithm, stream cipher and server returns the similar and they ACK each other's packets.
    5. Client and server exchanges an init message and and server responds with its public key.
    6. Client and server both generate a same new MSG_KEY and server responds with signature algorithm for client to validate data integrity.
    7. Client offers its on public key using MSG_KEY symmetric encryption and signature algorithm provided.
    8. Once authenticated, client is able to login to the server
* ssh_config(5)
    * Provides details on ssh options an definitions.

## TLS/SSL
* What is
    * TLS/SSL authenticates and secures data transfers by using certificate-based authentication and symmetric encryption keys
    * It’s worth noting that SSL and TLS simply refer to the handshake that takes place between a client and a server. The handshake doesn’t actually do any encryption itself, it just agrees on a shared secret and type of encryption that is going to be used.
* TLS 1.2 Full Handshake
    * Client Hello(handshake protocol, unique random byte, TLS version, all available Cipher Suite)
    * Server Hello(handshake protocol, unique random byte, new session id, TLS version, chosen Cipher Suite), Certificate, Server Key Exchange(EC DH key params like curve type, pubkey(g^a mod p), signature algorithm and signature), Server Hello Done 
        * signature algorithm and signature - prevents MITM attack by authenticating itself as the server.
    * Client Key Exchange(EC DH Key params, pubkey(g^b mod p)), Change Cipher Spec(DES, DSA, KEA, ...) for hinting next packet be encrypted, encrypted handshake message, Finished 
        * master_secret
            * generated by PRF(pre_master_secret, "master secret", ClientHello.random + ServerHello.random)[0..47] - exactly 48 bytes in length
                * RSA only - pre_master_secret is generated by client encrypted under the server's public key.
                * DH only - the negotiated key, with leading bytes of zeros stripped off, is used as the pre_master_secret.
                    * Given known prime numbers g and p and secret numbers a and b.
                    * pre-master key is the value you directly obtain from the key exchange g^ab(mod p)
                        * (g^a mod p)^b mod p = g^ab mod p
                        * (g^b mod p)^a mod p = g^ba mod p
        * Above two steps each - generates a key_block of 128 bytes using master_secret generated, both sides' random value and key expansion.
        * Generated key_block - is partitioned into 2 x 32 bytes of read_write encryption key and 2 x 32 bytes of read_write MAC key.
    * Change Cipher Spec, encrypted handshake message, Finished
        * Change Cipher Spec - used to notify server that next packet will be encrypted with just negotiated cipher spec and keys
        * if exists a previous negotiated key, reuse it and and ignore previous two step by first sending Client Hello with existing session id
    * GET HTTP/1.1
    * HTTP Response
* Application Data Protocol
    * Application data messages are carried by the record layer and are fragmented, compressed, and encrypted based on the current connection state.  The messages are treated as transparent data to the record layer.
* TLS 1.3 Full Handshake
    * Client Hello, Key Share
    * Server Hello, Key Share, Certificate, Certificate Verify, Finished
    * Finished GET HTTP/1.1
    * HTTP Response
* TLS 1.3 New Feature
    * “zero round trip” mode (0-RTT) for sending data to those sites you visited recently.
* Steps to connect to a website using HTTPS
    1. Browser requests and retrieves remote host certificate chain and authenticate host certificate using trusted CA public key and sends a encrypted session key + data.
    2. Remote host retrieves decrypts the session key and then forwards html encrypted using the session key.  
* Layers a SSL/TLS encryption layer on top of HTTP protocol
    * Authenticates the server and ensures confidentiality.
    * Agrees on a "cipher suite" which includes which encryption algorithm should be used to exchange data

## HTTPS Handshake Steps - Simple Version
1. After building a TCP connection, the SSL handshake is started by the client. The client (which can be a browser as well as any other program such as Windows Update or PuTTY) sends a number of specifications:
    * which version of SSL/TLS it is running,
    * what ciphersuites it wants to use, and
    * what compression methods it wants to use.
2. The server checks what the highest SSL/TLS version is that is supported by them both, picks a ciphersuite from one of the client's options (if it supports one), and optionally picks a compression method. After this the basic setup is done, the server sends its certificate. This certificate must be trusted by either the client itself or a party that the client trusts. For example if the client trusts GeoTrust, then the client can trust the certificate from Google.com, because GeoTrust cryptographically signed Google's certificate.
3. Having verified the certificate and being certain this server really is who he claims to be (and not a man in the middle), a key is exchanged. This can be a public key, a "PreMasterSecret" or simply nothing, depending on the chosen ciphersuite. Both the server and the client can now compute the key for the symmetric encryption?. The client tells the server that from now on, all communication will be encrypted, and sends an encrypted and authenticated message to the server.
4. The server verifies that the MAC (used for authentication) is correct, and that the message can be correctly decrypted. It then returns a message, which the client verifies as well.
5. The handshake is now finished, and the two hosts can communicate securely. 
6. To close the connection, a close_notify 'alert' is used. If an attacker tries to terminate the connection by finishing the TCP connection (injecting a FIN packet), both sides will know the connection was improperly terminated. The connection cannot be compromised by this though, merely interrupted.

## HTTPS - Google case 
### 1. Validate the certificate of a website:
1. When you enter the URL www.Google.com, Google’s server gives its public key and certificate (which was signed by GeoTrust) to the Browser.
2. Now browser has to verify the authenticity of the certificate i.e. it’s actually signed from GeoTrust or not. As browsers come with a pre-installed list of public keys from all the major CA’s, it picks the public key of the GeoTrust and tries to decrypt the digital signature of the certificate which was encrypted by the private key of GeoTrust.
3. If it’s able to decrypt the signature (which means it’s a trustworthy website) then it proceeds to the next step else it stops and shows a red cross before the URL.

### 2. Create a secure connection (encrypts outgoing and incoming data) so that no one else can read it:
1. As I mentioned, Google sends its public key when you enter www.Google.com . Any data encrypted with this public key can only be decrypted by Google’s private key which Google doesn’t share with anyone.
2. After validating the certificate, browser creates a new key let’s call it Session Key and make 2 copies of it. These keys can encrypt as well as decrypt the data.
3. The browser then encrypts (1 copy of session key + other request data) with the Google's public key . Then it sends it back to the Google server.
4. Google’s server decrypts the encrypted data using its private key and gets the session key , and other request data.
5. When Google sends the data like requested HTML document and other HTTP data to the browser it first encrypts the data with this session key and browser decrypts the data with the other copy of the session key.
6. Similarly, when browser sends the data to the Google server it encrypts it with the session key which server decrypts on the other side.


## Important Concepts
* Diffie–Hellman key exchange (DH)
    * It allows two parties that have no prior knowledge of each other to jointly establish a shared secret key over an insecure channel.
    * It provides forward secrecy where stealing the private key doesn't let you decrypt old sessions.
    * Procedures:
        * Both parties agree on a large prime number, which will serve as a seed value.
        * Both parties agree on an encryption generator (typically AES), which will be used to manipulate the values in a predefined way.
        * Independently, each party comes up with another prime number which is kept secret from the other party. This number is used as the private key for this interaction (different than the private SSH key used for authentication).
        * The generated private key, the encryption generator, and the shared prime number are used to generate a public key that is derived from the private key, but which can be shared with the other party.
        * Both participants then exchange their generated public keys.
        * The receiving entity uses their own private key, the other party's public key, and the original shared prime number to compute a shared secret key. Although this is independently computed by each party, using opposite private and public keys, it will result in the same shared secret key.
        * The shared secret is then used to encrypt all communication that follows.
* SSH Server Auth
    * Procedure
        * The client begins by sending an ID for the key pair it would like to authenticate with to the server.
        * The server check's the file of the account that the client is attempting to log into for the key ID.
        * If a public key with matching ID is found in the file, the server generates a random number and uses the public key to encrypt the number.
        * The server sends the client this encrypted message.
        * If the client actually has the associated private key, it will be able to decrypt the message using that key, revealing the original number.
        * The client combines the decrypted number with the shared session key that is being used to encrypt the communication, and calculates the MD5 hash of this value.
        * The client then sends this MD5 hash back to the server as an answer to the encrypted number message.
        * The server uses the same shared session key and the original number that it sent to the client to calculate the MD5 value on its own. It compares its own calculation to the one that the client sent back. If these two values match, it proves that the client was in possession of the private key and the client is authenticated.
