# Abstract

- This document explores Pretty Good Privacy (PGP), how it works, use cases, advantages and disadvantages and closing thoughts

## What is

1. Def
   1. An encryption software designed to provide privacy, security, and authentication for online communications systems. [Phil Zimmerman](https://www.philzimmermann.com/EN/essays/WhyIWrotePGP.html) create the first GPG program and was made freely available due to the growing social demand for privacy.
2. History
   1. Since its creation in 1991, many versions of PGP software were created. In 1997, Phil Zimmerman made a proposal to the IETF for the creation of an open-source PGP standard. **The proposal was accepted and led to the creation of the OpenPGP protocol, which defines standards formats for encryption keys and messages**.
   2. Although initially used only for securing email messages and attachments, PGP is now applied to a wide range of use cases, including digital signatures, full disk encryption, and network protection.
   3. PGP was initially owned by the company PGP Inc, which was later acquired by Network Associates Inc. **In 2010, Symantec Corp. acquired PGP for \$300 million, and the term is now a trademark used for their OpenPGP-compliant products**.

## How does it work

1. Background
   1. PGP is among the first widely available software to implement PKC. It is **a hybrid cryptosystem that uses both symmetric and asymmetric encryption to achieve a high level of security**.
2. Work flow
   1. During a basic process of text encryption, a plaintext is converted into ciphertext.
   2. Compression
      1. But before the process of encryption takes place, most PGP systems perform data compression. By compressing plaintext files prior to transmitting them, PGP saves both disk space and transmission time - while also improving security.
   3. Encryption
      1. Following the file compression, the actual process of encryption begins. At this stage, the compressed plaintext file is encrypted with a single-use key, which is known as the session key which is randomly generated through the use of symmetric cryptography, and each PGP communication session ahs a unique session key.
   4. Session Key
      1. Session key itself is encrypted using asymmetric encryption: **the intended receiver (Bob) provides his public key to the sender of the message (Alice) so that she can encrypt the session key. This step allows Alice to safely share the session key with Bob through the Internet, regardless of security condition**.
   5. Asymmetric encryption of the session key
      1. Usually done through the use of the RSA algorithm. Many other encryption systems use RSA, including the TLS protocol that secures a great portion of the Internet.
      2. Once the message's ciphertext and the encrypted session key are transmitted, Bob can use his private key to decrypt the session key, which is then used to decrypt the ciphertext back into the original plaintext.
3. Digital signatures
   1. PGP supports digital signatures aside from the basic process of encryption and decryption which serve at least three functions
      1. Authentication - Bob can verify that the sender of the message was Alice
      2. Integrity - Bob can be sure that the message wasn't altered
      3. Non-repudiation - After the message is digitally signed, Alice cannot claim she didn't send it.

## Use Cases

1. One of the most common uses for PGP is to secure emails.
2. Although PGP is mostly used to secure Internet communications, it can also be applied to encrypt individual devices.
   1. PGP can be applied to disk partitions.

## Advantages and disadvantages

1. Advantages
   1. Allows secure exchange of information and cryptographic keys through the Internet.
   2. It benefits from both the security of asymmetric cryptography and the speed of symmetric encryption. In addition to security and speed, digital signatures ensure the integrity of the data and authenticity of the sender.
   3. **The OpenPGP protocol allowed for the emergence of a standardized competitive environment and PGP solutions are now provided by multiple companies and organizations**. Still, all PGP programs that comply with the OpenPGP standards are compatible with each other. This means that files and keys generated in one program may be used in another without problem.
2. Disadvantages
   1. **PGP systems are not that simple to use and understand, especially for users with little technical knowledge.**
   2. **The long length of the public keys is deemed by many as quite inconvenient**
   3. In 2018, a major vullnerability called EFAIL was published by the Electronic Frontier Foundation (EFF).
      1. EFAIL made it possible for attackers to exploit active HTML content in encrypted emails to gain access to the plaintext versions of messages.
      2. However, some of the concerns described by EFAIL were already known by the PGP community since the late 1990s and, in fact, **the vulnerabilities are related to the different implementations on the part of email clients, and not with PGP itself**. So PGP is not broken and continues to be highly secure.

## Closing thoughts

1. Since its development in 1991, PGP has been an essential tool for data protection and is now used in a wide range of applications, providing privacy, security, and authentication for several communication systems and digital service providers.
2. The core technology of PGP is regarded as robust and typographically sound.
   1. It's worth noting that different PGP implementations may present varying levels of security.