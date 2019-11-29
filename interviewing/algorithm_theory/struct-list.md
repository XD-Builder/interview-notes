# Abstract

- This document serves a placeholder for future list definitions and research

## LinkedList

## Queue

## DeQueue

## Priority Queue

1. Def
   1. An abstract data type which is like a regular queue or stack data structure, but where additionally each element has a "priority" associated with it.
   2. **An element with high priority is served before an element with low priority**.
   3. Often implemented with heaps but is conceptually distinct from them. It's an abstract concept like "a list" or "a map".
      1. Just as a list can be implemented with linked list or an array, a priority queue can be implemented with a heap or a variety of other methods such as an unordered array.
2. Operations
   1. is_empty
      1. whether the queue has no elements
   2. insert_with_priority
      1. add an element to the queue with an associated priority
   3. pull_highest_priority_element
      1. remove the element from the queue that has the highest priority, and return it.
   4. peek
      1. returns the highest priority element but does not modify the queue, is very frequently implemented, and nearly always executes in O(1) time.
3. Applications
   1. Bandwidth management
      2. It can be used to manage limited resources such as bandwidth on a transmission line from a network router. **In the event of outgoing traffic queuing due to insufficient bandwidth, all other queues can be halted to send the traffic from the highest priority queue upon arrival**. This ensures that the prioritized traffic is forwarded with the least delay and the least likelihood of being rejected due to a queue reaching its maximum capacity.
   2. Discrete event simulation
      1. Manage the events in a discrete event simulation. **Events are added to the queue with their simulation time used as the priority**. The execution of the simulation proceeds by repeatedly pulling the top of the queue and executing the event thereon.
   3. Dijkstra's algorithm
      1. **When the graph is stored in the form of adjacency list of matrix, priority queue can be used to extract minimum efficiently when implementing Dijkstra's algorithm**, although one also needs the ability to alter the priority of a particular vertex in the priority queue efficiently.
   4. Huffman coding
      1. Requires one to repeatedly obtain the two lowest-frequency trees.
   5. Best-first search algorithms
      1. Find the shortest path between two vertices of a weighted graph, trying out the most promising routes first.
   6. Prim's algorithm for minimum spanning tree
      1. Using min heap priority queue in Prim's algorithm to find the minimum spanning tree of a connected and undirected graph, one can achieve a good running time. 