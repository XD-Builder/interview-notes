# Abstract

- This document serves a placeholder for future tree definitions and research

## Tree structures

### Tries

### Binary Search Trees

### Red Black Tree

1. What is?
   1. R-B Tree is a self-balancing Binary Search Tree (BST) where every node follows following rules
      1. Every node has a color either red or black.
      2. Root of the tree is always black
      3. There are no two adjacent red nodes (A red node cannot have a red parent or red child)
      4. Every path from a node (including root) to any of its descendant NULL node has the same number of black nodes.
      5. All leaves (NIL) are black.
2. Why R-B Tree?
   1. AVL trees are more balanced compared to R-B Trees, but they may cause more rotations during insertion and deletion.
      1. If your app involves many frequent insertions and deletions, R-B tree should be preferred.
      2. If insertions and deletions are less frequent and search is ore frequent, then AVL tree should be preferred.
3. Properties
   1. A node of height h has black-height >= h/2
   2. Every R-B Tree with n nodes has height <= 2 Log(n+1)
4. Operations
   1. Insertion
      1. Time => O(Log(n+1)) + O (1) for rotations
   2. Deletion
      1. Time =>
   3. Search/Update
      1. Time => O(Log(n+1))

### AVL Tree

1. What is?
   1. A self-balancing Binary Search Tree (BST) where the difference between heights of left and right sub-trees cannot be more than one for all nodes.
2. Properties
   1. Each node keeps track of its height and all rotate operations update node heights.
3. Operations
   1. Insertion
      1. Operation ensures that the given tree remains AVL after every insertion
      2. Operations include left rotate, right rotate
      3. Time => O(Log(n+1))
