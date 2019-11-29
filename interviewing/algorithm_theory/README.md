# Abstract

- This document covers basic data structures, their operations and common interview problems.

# Arrays

1. Def
   1. A linear data structure from which other data structures like stacks and queues derived.
   2. Basic ops include insert, get, delete, size
2. Types
   1. One-dimensional arrays
   2. Multi-dimensional arrays, arrays within arrays
3. Common Problems
   1. Find the second minimum element of an array
   2. First non-repeating integers in an array
   3. Merge two sorted arrays
   4. Rearrange positive and negative values in an array.

# Stacks

1. Def
   1. An abstract linear data structure such that the last element pushed will be the first element pop off the stack
   2. Basic ops include push, pop, isEmpty, top.
2. Common Problems
   1. Evaluate postfix expression using a stack
   2. Sort values in a stack
   3. Check balanced parentheses in an expression

# Queues

1. Def
   1. An abstract linear data structure such that the first element enqueued will be the first element to be dequeued.
   2. Basic ops include enqueue, dequeue, isEmpty, top
2. Common Problems
   1. Implement stack using a queue
   2. Reverse first k elements of a queue
   3. Generate binary numbers from 1 to n using a queue

# Linked List

1. Def
   1. An abstract linear data structure which might look similar to arrays but differs in memory allocation, internal structure and how basic ops are carried out.
   2. A chain of nodes where each node contains information like data and pointer to the succeeding node in the chain.
   3. Basic Ops include insertAtEnd, insertAtHead, deleteAtEnd, deleteAtHead, search, isEmpty
2. Types
   1. Singly Linked List (Uni-drectional)
   2. Doubly Likned List (Bi-directional)
3. Common Problems
   1. Reverse a linked list
   2. Detect loop in a linked list
   3. Return Nth node from the end in a linked list
   4. Remove duplicates from a linked list

# Graphs

1. Def
   1. A set of nodes that are connected to each other in the form of a network.
   2. Nodes are called vertices.
   3. A pair(x,y) is called an edge, which indicates that vertex x is connected to vertex y.
   4. An edge may contain weight/cost, showing how much cost is required to traverse from vertex x to y.
2. Types
   1. Undirected Graph
   2. Directed Graph
3. Representation
   1. Adjacency Matrix
   2. Adjacency List
4. Common Graph traversing algorithms
   1. Breadth First Search
   2. Depth First Search
5. Common Problems
   1. Implement Breadth and Depth First Search
   2. Check if a graph is a tree or not
   3. Count number of edges in a graph
   4. Find the shortest path between two vertices

# Trees

1. Def
   1. A hierarchical data structure consisting of vertices (nodes) and edges that connect them. Similar to graphs, but the key point that differentiates a tree from the graph is that a cycle cannot exist in a tree.
   2. Extensively used in AI and complex algorithms to provide an efficient storage mechanism for problem-solving
2. Types
   1. N-ary Tree
   2. Balanced Tree
   3. Binary Tree
   4. Binary Search Tree
   5. AVL Tree
   6. Red Black Tree
   7. 2-3 Tree
3. Common Problems
   1. Find the height of a binary tree
   2. Find kth maximum value in a binary search tree
   3. Find nodes at "k" distance from the root
   4. Find ancestors of a given node in a binary tree

# Trie

1. Def
   1. Known as "Prefix Trees", is a tree-like data structure which proves to be quite efficient for solving problems related to strings. It provides fast retrieval, and mostly used for searching words in a dictionary, providing auto suggestions in a search engine, and even for IP routing.
2. Common Problems
   1. Count total number of words in Trie
   2. Print all words stored in Trie
   3. Sort elements of an array using Trie
   4. Form words from a dictionary using Trie
   5. Build a T9 dictionary

# Hash Table

1. Def
   1. Hashing is a process used to uniquely identify objects and store each of them at some pre-calculated unique index called its "key" and the object stored in the form of a "key-value" pair, and the collection of such items is called a "dictionary".
2. Performance of hashing data structure depends on three factors
   1. Hash Function
   2. Size of Hash Table
   3. Collision Handling Method
3. Common Hashing Problem
   1. Find Symmetric pairs in an array
   2. Trace complete path of a journey
   3. Find if an array is a subset of another array
   4. Check if given arrays are disjoint.
