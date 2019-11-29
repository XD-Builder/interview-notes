# Abstract

- This document explores storage scalability

## About

1. Background
   1. A sound understanding of storage scalability is really important if you intend to interview for a senior backend engineer or senior infrastructure engineer role.
2. Pre-requisite
   1. Experience with relational DB, and basic understanding of NoSQL DBs.
   2. Concurrency - threads, deadlock, and starvation, data race and read/write locks.
   3. Networking - basic networking protocols like TCP and UDP, role of switches and routers.
   4. File System - OS, file system database, caching and how they work.
3. Terms
   1. Replication : Replication refers to **frequently copying the data across multiple machines**. Post replication, multiple copies of the data exists across machines. This might help in case one or more of the machines die due to some failure.
   2. Consistency: Assuming you have a storage system which has more than one machine, **consistency implies that the data is same across the cluster, so you can read or write to/from any node and get the same data**.
   3. Eventual consistency : Exactly what the name suggests. In a cluster, if multiple machines store the same data, an eventual consistent model implies that **all machines will have the same data eventually**. Its possible that at a given instance, those machines have different versions of the same data ( temporarily inconsistent ) but they will eventually reach a state where they have the same data.
   4. Availability: In the context of a database cluster, Availability refers to **the ability to always respond to queries ( read or write ) irrespective of nodes going down**.
   5. Partition Tolerance: In the context of a database cluster, **cluster continues to function even if there is a “partition” (communications break) between two nodes (both nodes are up, but can’t communicate)**.
   6. Vertical scaling and Horizontal scaling : In simple terms, to **scale horizontally is adding more servers**. To **scale vertically is to increase the resources of the server ( RAM, CPU, storage, etc. )**.
      1. Example: Lets say you own a restaurant which is now exceeding its seating capacity. One way of accommodating more people ( scaling ) would be to add more and more chairs (scaling vertically). However since the space is limited, you won’t be able to add more chairs once the space is full. Another way of scaling would be to open new branches of the restaurant ( horizontal scaling ).
   7. Sharding : With most huge systems, data does not fit on a single machine. In such cases, **sharding refers to splitting the very large database into smaller, faster and more manageable parts called data shards**.
4. CAP Theorem
   1. CAP Theorem states that in a distributed system, it is impossible to simultaneously guarantee all of the following:
      1. Consistency
      2. Availability
      3. Partition Tolerance
5. Steps to Approach a Problem
   1. Feature expectation (First 2 min)
      1. It's extremely important to get a very clear understanding of whats the requirement for the question.
   2. Estimation (2-5 min)
      1. Estimate the scale required for the system. The goal is to understand the level of sharding required (if any) and to zero down on the design goals for the system.
   3. Design Goals (1 min)
      1. Figure out what are the most important goals for the system.
   4. Skeleton of design (4-5 mins)
      1. 30-40 mins is not enough to discuss every single component in detail. Therefore, a good strategy is to discuss a very high level with the interviewer and go into a deep dive of components as enquired by the interviewer.
   5. Deep dive (20-30 mins)
      1. An extension to step 4
