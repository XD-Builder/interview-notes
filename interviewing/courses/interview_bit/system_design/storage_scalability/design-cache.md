# Abstract

- This document explores topics on how to design a distributed key value caching system, like Memcached or Redis.

## About

1. Question
   1. App checks if entry is in Cache
   2. If entry not in Cache, get entry from Database, save to Cache and read.
   3. If entry in Cache, read it.
2. Steps
   1. Feature expectation
      1. **What is the amount of data that we need to cache?**
         1. Let's assume we are looking to cache on the scale of Google or Twitter. The total size of the cache would be a few TBs.
      2. **What should be the eviction strategy?**
         1. It is possible that we might get entries when we would not have space to accommodate new entries. In such cases, we would need to remove one or more entries to make space for the new entry.
      3. **What should be the access pattern for the given cache?**
         1. Write through cache
            1. This is a caching system where **writes go through the cache and write is confirmed as success only if writes to DB and the cache BOTH succeed**. This is really useful for applications which write and re-read the information quickly. However, write latency will be higher in this case as there are writes to 2 separate systems.
         2. Write around cache
            1. This is a caching system where **write directly goes to the DB**. The cache system reads the information from DB incase of a miss. While this ensures **lower write load to the cache and faster writes**, this can **lead to higher read latency incase of applications which write and re-read the information quickly**.
         3. Write back cache
            1. This is a caching system where the **write is directly done to the caching layer and the write is confirmed as soon as the write to the cache completes**. The cache then **asynchronously syncs this write to the DB**. This would lead to a **really quick write latency and high write throughput**. But, as is the case with any non-persistent / in-memory write, **we stand the risk of losing the data incase the caching layer dies. We can improve our odds by introducing having more than one replica acknowledging the write ( so that we don’t lose data if just one of the replica dies )**.
   2. Estimation
      1. What is the kind of QPS we expect for the system?
         1. This estimation is **important to understand the number of machines we will need to answer the queries**.
            1. For example, if our estimations state that a single machine is going to handle 1M QPS, we run into a high risk of high latency / the machine dying because of queries not being answered fast enough and hence ending up in the backlog queue.
      2. What is the number of machines required to cache?
         1. **A cache has to be inherently of low latency. Which means all cache data has to reside in main memory**. 
   3. Design Goals
      1. Think about
         1. Latency - **Is this problem very latency sensitive (Or in other words, Are requests with high latency and a failing request, equally bad?).**
            1. For example, search type-ahead suggestions are useless if they take more than a second.
         2. Consistency - Does this problem require tight consistency? **Or is it okay if things are eventually consistent**?
         3. Availability - **Does this problem require 100% availability**?
      2. Is Latency a very important metric?
         1. If yes, then caching should be used.
      3. Consistency vs Availability?
         1. Unavailability in a caching system means that the caching machine goes down, which in turn means that we have a cache miss which leads to a high latency.
   4. Deep Dive
      1. How would a LRU cache work on a single machine which is single threaded?
         1. **What if we never had to remove entries from the LRU cache because we had enough space**, what would you use to **support and get and set**?
            1. A simple map/hashmap.
      2. How should we modify our approach if we also have to evict keys at some stage?
         1. We need a data structure which at any given instance can give me the least recently used objects in order.
      3. How would a LRU cache work on a single machine which is multi threaded ?
         1. How would you break down cache write and read into multiple instructions?
            1. Read path : Read a value corresponding to a key.
            2. Write path : Insert a new key-value entry to the LRU cache.
         2. How would you prioritize above operations to keep latency to a minimum for our system?
         3. How would you implement HashMap?
      4. Now that we have sorted how things look on a single server, how do we shard?
         1. What QPS would a machine have to handle if we shard in blocks of 72GB?
         2. Will our machines be able to handle qps of 23000?
         3. What if we shard among machines with 16GB of RAM?
      5. What happens when a machine handling a shard goes down?