# Abstract

- This document explorse graphs and how we represent them.

## About Graph

1. What are graphs
   1. A graph is an abstract notation used to represent the connection between pairs of objects. It can be used to represent networks: systems of roads, airline flights from city to city, how the Internet is connected, or social connectivity on Facebook, Twitter etc. Some standard graph algorithms are used to solve these difficult problems.
2. Representing Graphs
   1. **Graphs represent pairwise relationships between objects**.
   2. Graphs are mathematical structures and therefore can be visualized by using two basic components, **nodes and edges**.
      1. **A node, also known as a vertex, is a fundamental part of a graph**. It is the entity that has **a name known as the key, and other information related to that entity**.
      2. **A relationship between nodes is expressed using edges**. An edge between two nodes expresses a one-way or two-way relationship between nodes.
   3. A graph can be represented as Adjacency Matrix and Adjacency List.
      1. Adjacency List is preferred because algorithms can be performed more efficiently using this form of representation.
   4. Adjacency Matrix vs Adjacency List
      1. Adjacency Matrix is 2D array where columns and rows denote connection between nodes.
         1. Adjacency List is a list of nodes each containing information about its neighbors in a list.
3. Mathematical Notation
   1. Vertices
      1. The set of vertices of Graph G is denoted by **V(G), or just V** if there is no ambiguity.
   2. Edge
      1. **An edge between vertices u and v is written as u,v.** The set of edges of G is denoted **E(G), or just E** if there is no ambiguity.
   3. Graph
      1. A graph's vertices can be represented as **V = {1,2,3,4}**
   4. Edge set
      1. An edge set can be represented as **E = {{1,2}, {2,3}, {3,4}}**
   5. Path
      1. A path in graph G = (V,E) is **a sequence of vertices v1, v2,..., vk, with the property that there are edges between vi and vi + 1. We say that the path goes from v1 to vk**.
      2. A path is simple if its vertices are all different.
   6. Cycle
      1. A cycle is a path v1,v2,..., vk for which
         1. k > 2
         2. the first k - 1 vertices are all different, and,
         3. v1 = vk
   7. Connected
      1. A graph is connected if **for every pair of vertices u and v, there is a path from u to v**.