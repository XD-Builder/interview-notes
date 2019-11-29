# Abstract

- This document explores lightning network, its network routing, advantages and limitations and when is it coming.

## How does lightning network(LN) work

1. History
   1. LN as a concept was created by Joseph Poon and Thaddeus Dryja in 2015. The main idea behind the project is to design a payment protocol that can be used as an off-chain solution for the scalability problem faced by the Bitcoin blockchain, but the concept may be appiled to other Cryptocurrencies as well.
   2. The introduction of the LN was triggered by the limitations that not only Bitcoin but by many other cryptocurrencies are facing. **Currently, the Bitcoin blockchain is only able to process from 2 to 7 transactions per second (TPS)**. As the cryptocurrency ecosystem grows and more people join the network, the number of transactions being broadcasted to the blockchain also increases.
      1. As the network gets more and more congested, the overall performance is compromised, which greatly reduces the practical usability of Bitcoin as global digital currency. In such a context, **the LN was created as an attempt to alleviate the network congestion of the Bitcoin blockchain**.
2. Definition
   1. **LN consists of an off-chain transfer network that is being built on top of the Bitcoin blockchain. The system works on a P2P level and its usability relies on the creation of the so-called bidirectional payment channels, through which users can make seamless cryptocurrency transactions**.
3. Execution
   1. After two parties decide to open a payment channel, they are able to transmit funds back and forth across their wallets. Although the process of setting up a new payment channel involves **an on-chain transaction**, all transactions that take place within the channel are **off-chain** and **do not require a global consensus**. Therefore, these transactions can be quickly executed through a smart contract, **incurring in much lower fees and a much higher TPS rate**.
4. Payment channel
   1. In order to open a payment channel, **the two parties involved need to set up a multi-signature wallet and add some funds to it**. Funds that are stored on multi-sig wallets can **only be accessed if the private keys of both parties are provided** (two or more, depending on the case). This means that one party cannot open the wallet without the consent of the other.
      1. As an example, let's imagine that Alice wants to use the LN to trade Bitcoin with Bob.
      2. First, they set up a payment channel, using a multi-signature wallet. While the payment channel acts like a smart contract, the multi-sig wallet acts like a vaults, where the funds to be traded are deposited.
      3. During the lifetime of the payment channel, **Alice and Bob can perform as many off-chain transactions as they want**.
   2. **Right after each transaction, both Alice and Bob sign and update their own copy of the balance sheet, which records the amount of coins each one has, when they are done with their transactions, they can close the payment channel and broadcast the final balance sheet to the Bitcoin blockchain**. The LN smart contract will make sure they receive their Bitcoins, according to the last version fo the balance sheet.
   3. Summing up, the parties involved only need to **interact twice with the Bitcoin blockchain**. One time to open the payment channel and another one to close it, which means that **all other transactions that take place within the channel are not directly interacting with the main chain**.

## Network Routing

1. How it works
   1. Even if two parties do not have a direct payment channel, they are still able to **send and receive Bitcoins through interconnected payment channels**. That means that Alice is able to send payments to Charlie without having to create a direct channel with him, as long as there is a network route between them that contains enough balance.
   2. If Alice has an open payment channel with Bob and Bob has a Channel with Charlie, she can send the payment through Bob. **The payment routing may involve many Lightning Network nodes, but the smart contract will automatically search for the shortest available path**.

## Advantages, limitations, and future of Lightning Network

1. Advantages
   1. The LN project is working towards an **off-chain solution for the traffic on the Bitcoin blockchain**
   2. Through the use of bidirectional payment channels, the Lightning Network **allows for nearly instant transactions**.
   3. The LN may be suitable for **micropayments**, as it allows the transfer of small values. Moreover, automatized micropayments may be implemented on the Machine-to-Machine economy, where transactions are made between electronic devices without the need for human interference.
2. Limitations
   1. Unlike on-chain transactions, **LN payments cannot be made if the receiver is offline**.
   2. **Participants of the network may need to monitor payment channels regularly in order to keep their funds safe** (such risk could be overcomed by outsourced monitoring services).
   3. The LN is **not suitable yet for large payments**. As the network counts with many multi-signature wallets(which are basically shared wallets) chances are high that these will not have sufficient balance to act as intermediaries of large payments.
   4. Opening and **closing a payment channel** involves on-chain transaction, which **usually requires manual work and higher transaction fees**.
3. When is lightning network coming?
   1. On March 15th of 2018, the Lightning Labs announced the 4th major release of the **Lightning Network Daemon (lnd)**, which gave rise to the **first Lightning mainnet beta release**. The lnd is a complete implementation of a Lightning Network node and is currently being **experimented on the Bitcoin Test Network**. Along with lnd, there are other implementations being developed such as c-lightning and eclair.
   2. There is no official release data for Lightning Network as each protocol implementation has a different approach, which is **based on regular updates and continuous development**.
   3. Since the lnd beta release, there was a huge increase in the number of LN nodes and payment channels. As of Jan 2019, Grafana dashboard reports more than 24,300 payment channels.
   4. The collective work of nodes and payment channel is what makes the Lightning Network an interesting solution for the scalability problem. The beta version has been going through a lot of experimentation and its efficiency is yet to be proved.
      1. Nevertheless, the Lightning Network does have a huge potential to improve the Bitcoin and the cryptocurrency ecosystem.