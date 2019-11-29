# Abstract

- This document explores consensus algorithm, protocol and why consensus algorithms matter to cryptocurrencies

## Consensus Algorithm

1. Background
   1. In the context of cryptocurrencies, the consensus algorithms are a crucial element of every blockchain network as they are responsible for maintaining the integrity and security of these distributed systems. **The first cryptocurrency consensus algorithm to be created was the Proof of Work (PoW), which was designed by Satoshi Nakamoto and implemented on Bitcoin as a way to overcome the Byzantine faults**.
2. Definition
   1. A consensus algorithm may be defined as **the mechanism through which a blockchain network reach consensus**. Public (decentralized) blockchains are built as distributed systems and, since they do not rely on a central authority, the distributed nodes need to agree on the validity of transactions. This is where consensus algorithms come into play. They assure that **the protocol rules are being followed and guarantee that all transactions occur in a trustless way, so the coins are only able to be spent once**.

## Consensus Algorithm vs Protocol

1. Background
   1. The term algorithm and protocol are often used interchangeably, but they are not the same thing. In simple terms, **we may define a protocol as the primary rules of a blockchain and the algorithm as the mechanism through which these rules will be followed**.
2. Differences
   1. Besides being extensively used on financial systems, the blockchain technology can be applied to a wide variety of businesses and may be suitable for different use cases. But regardless of the context, **a blockchain network will be built on top of a protocol that will define how the system is supposed to work, so all the different parts of the system and all participants of the network will need to follow the rules of the underlying protocol**.
   2. While the protocol determines what the rules are, the **algorithm tells the system what steps to take in order to comply with these rules and produce the desired results**. For instance, **the consensus algorithm of a blockchain is what determines the validity of transactions and blocks**. So, **Bitcoin and Ethereum are protocols** while **the Proof of Work and Proof of Stake are their consensus algorithms**.
   3. **To further illustrate, consider that the Bitcoin protocol defines how the nodes should interact, how the data should be transmitted between them, and what are the requirements for a successful block validation. On the other hand, the consensus algorithm is responsible for verifying the balances and signatures, confirming transactions, and for actually executing the validation of blocks - and all this is dependent on network consensus**.

## Different types of consensus algorithms

1. Background
   1. There are several types of consensus algorithms. The most common implementations are PoW and PoS. Each one has its own advantages and disadvantages when trying to balance security with functionality and scalability.
2. Proof of Work (PoW)
   1. **PoW was the first consensus algorithm to be created**. It is employed by Bitcoin and many other cryptocurrencies. The Proof of Work algorithm is **an essential part of the mining process**.
   2. **The PoW mining involves numerous hashing attempts, so more computational power means more trials per second**. In other words, miners with a high hash rate have better chances to find a valid solution for the next block (aka. block hash). **The PoW consensus algorithm makes sure that miners are only able to validate a new block of transactions and add it to the blockchain if the distributed nodes of the network reach consensus and agree that the block hash provided by the miner is a valid proof of work**.
3. Proof of Stake (PoS)
   1. The PoS consensus algorithm was developed in 2011 as an alternative to PoW. Although PoS and PoW share similar goals, **they present some fundamental differences and particularities. Especially during the validation of new blocks**.
   2. In a few words, **the Proof of Stake consensus algorithm replaces the PoW mining with a mechanism where blocks are validated according to the stake of the participants**. The validator of each block (also called forger or minter) is determined by an investment of the cryptocurrency itself and not by the amount of computational power allocated. Each PoS system may implement the algorithm in different ways, but in general, **the blockchain is secured by a pseudo-random election process that considers the node’s wealth and the coins age (how long the coins are being locked or staked) - along with a randomization factor**.
   3. The Ethereum blockchain is currently based on a PoW algorithm, **but the Casper protocol will eventually be released to switch the network from PoW to PoS in an attempt to increase the network’s scalability**.

## Why Consensus Algorithms Matter to Cryptocurrencies

1. The consensus algorithms are crucial for maintaining the integrity and security of a cryptocurrency network. **They provide a means of distributed nodes reaching consensus on which version of the blockchain is the real one. Agreeing upon the current blockchain state is essential for a digital economic system to work properly**.
2. **The Proof of Work consensus algorithm is considered one of the best solutions to the Byzantine Generals’ Problem, which allowed the creation of Bitcoin as a Byzantine Fault Tolerant system**. This means that the Bitcoin blockchain is highly resistant to attacks, such as the 51% attack (or majority attack). Not only because the network is decentralized but also because of the PoW algorithm. **The high costs involved in the process of mining makes it very difficult and unlikely that miners will invest their resources to disrupt the network**.
