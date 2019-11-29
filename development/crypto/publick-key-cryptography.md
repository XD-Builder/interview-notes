# Abstract

- This document explores public key cryptography

## What is

1. Def
   1. Known as asymmetric cryptography is a framework that uses both a private and public key, as opposed to the single key used in symmetric cryptography.
   2. The use of key pairs give PKC a unique set of characteristics and capabilities that can be utilized to solve challenges inherent in other cryptographic techniques.
      1. An important element of modern computer security, as well as a critical component of the growing cryptocurrency ecosystem.

## How does PKC work?

1. Keys Use
   1. In a PKC scheme, the public key is used by a sender to encrypt information, while the private key is used by a recipient to decrypt it.
   2. Because the two keys are different from one another, the public key can be safely shared without compromising the security of the private one.
   3. Each asymmetric key pair is unique, ensuring that a message encrypted using a public key can only be read by the person who possesses the corresponding private key.
2. Key Length
   1. Because asymmetric encryption algorithms generate key pairs that are mathematically linked, their key lengths are much longer than those used in symmetric cryptography. This longer length - typically between 1,024 and 2,048 bits - makes it extremely difficult to compute a private key from its public counterpart.
3. RSA
   1. One of the most commons algorithm for asymmetric encryption in use today is known as RSA. In the RSA scheme, keys are generated using a modulus that is arrived at by multiplying two numbers (often two large prime numbers).
      1. In basic terms, the modulus generates two keys (one public that can be shared, and one private that should be kept in secret). The RSA algorithm was first described in 1977 by Rivest, Shamir, and Adleman (hence, RSA) and remains a major component of public key cryptography systems.

## PKC as an Encryption Tool

1. It solves one of the long-standing problems of symmetric algorithms, which is **the communication of the key that is used for both encryption and decryption**. Sending this key over an insecure connection risks exposing it to third parties, who can then read any messages encrypted with the shared key. Although cryptographic techniques (such as the **Diffie-Hellman-Merkle key exchange protocol**) exist to solve this problem, they are still **vulnerable to attacks**. In public key cryptography, by contrast, **the key used for encryption can be shared securely over any connection**. As a result, asymmetric algorithms offer a higher level of protection when compared to the symmetric ones.

## Use in Generating Digital Signatures

1. Authenticating data through the use of digital signatures

   1. **A hash created using the data in a message.**
   2. When that message is sent, the signature can be checked by the recipient using the sender's public key as a way to authenticate the source of the message and to ensure that it has not been tampered with.
   3. **In some cases, digital signatures and encryption are applied together, as the hash itself may be encrypted as part of the message.**
   4. **Not all digital signature schemes use encryption techniques**

## Limitations

1. Although it can be used to enhance computer security and provide verification of message integrity, PKC does have some limitations
   1. Owing to the **complex mathematical operations involved in encryption and decryption, asymmetric algorithms can be quite slow** when forced to deal with large amounts of data
2. This type of cryptography also depends heavily on the assumption that the private key will remain secret.
   1. If a private key is accidentally shared or exposed, the security of all messages that have been encrypted with its corresponding public key will be compromised.
   2. It is also possible for users to accidentally lose their private keys, in which case it becomes impossible for them to access the encrypted data.

## Applications of Public Key Cryptography

1. Secure Transactions
   1. This type of cryptography is used by many modern computer systems to provide security for sensitive information. Emails, for example, can be encrypted using public key cryptography techniques to keep their contents confidential. The secure sockets layer (SSL) protocol that makes secure connections to websites possible also employs asymmetric cryptography.
   2. PKC systems have even been explored as **a means of providing a secure electronic voting environment that would potentially allow voters to participate in elections from their home computers**.
2. Cryptocurrency
   1. PKC also features prominently in blockchain and cryptocurrency technology. **When a new cryptocurrency wallet is set up, a pair of keys is generated (public and private keys).**
   2. **The public address is generated using the public key and can be securely shared with others**.
   3. **The private key, on the other hand, is used for creating digital signatures and verifying transactions, and therefore, must be kept in secret**.
   4. **Once a transaction has been verified by confirming the hash contained in the digital signature, that transaction can be added to the blockchain ledger**.
      1. **This system of digital signature verification ensures that only the person who has the private key associated with the corresponding cryptocurrency wallet can release funds from it**.
   5. **It should be noted that the asymmetric ciphers used in cryptocurrency applications** are different from those used for computer security purposes.
      1. Bitcoin and Ethereum, for instance, use a specialized cipher known as the **Elliptic Curve Digital Signature Algorithm (ECDSA) to verify transactions**.
   6. From computer security to verifying cryptocurrency transactions, **public key cryptography plays an important role in securing modern digital systems**.
      1. By using paired public and private keys, asymmetric cryptography algorithms resolve fundamental security concerns presented by symmetric ciphers.
      2. **Although PKC has been in use for many years, new uses and applications are regularly being developed for it, particularly in the blockchain and cryptocurrency space**.
