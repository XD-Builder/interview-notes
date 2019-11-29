# Abstract

- This document serves a placeholder for future graph definitions and research

## Graph Definition

## Graph Structures

## Graph Algorithm

### DFS

1. Characteristics
   1. Searches children first
   2. Uses stack
   3. Searching for a path from one vertex to another may produce sub-optimal solution before you find the real shortest path.
   4. Space Complexity is O(|V|) meaning the most memory it can take up is the longest possible path.
   5. More efficient if nodes are evenly distributed and the graph has shorter depth.

### BFS

1. Characteristics
   1. Searches siblings first
   2. Usually implemented with queues
   3. A complete algorithm and will give you the optimal solution
   4. Space Complexity O(b^d) a lot of memory
      1. based on the branching factor and the depth searched.
   5. More efficient if graph has smaller branching factor and higher depth.
