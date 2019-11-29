# Abstract

- This document explores [basic programming](https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/tutorial/)

## Time and Space Complexity

1. Background
   1. Sometimes, there are more than one way to solve a problem. **We need to learn how to compare the performance different algorithms and choose the best one to solve a particular problem**. While analyzing an algorithm, we mostly consider time complexity and space complexity.
2. Time and Space Complexity
   1. Time complexity of an algorithm quantifies the amount of time taken by an algorithm to run as a function of the length of the input.
   2. Space Complexity of an algorithm quantifies the amount of space or memory taken by an algorithm to run as a function of the length of the input.
   3. Time and space complexity depends on lots of things like hardware, operating system, processors, etc. However, we don't consider any of these factors while analyzing the algorithm. We only consider the execution time of an algorithm
3. Analysis of an algorithm
   1. Each of the operation in computer take approximately constant time. Let each operation takes c time. During analyses of algorithm, mostly we will consider worst case scenario.
   2. Order of growth is how the time of execution depends on the length of the input
   3. O-notation is used to denote asymptotic upper bound.
   4. Ω-notation is used to denote asymptotic lower bound
   5. Θ-notation is used to denote asymptotic tight bound.

## Basics of Bit Manipulation

1. Background
   1. Working on bytes, or data types comprising of bytes like ints, floats, doubles or even data structures which stores large amount of bytes is normal for a programmer. If a programmer needs to go beyond those basic data types, they will need use manipulate bits
2. Operation
   1. Operations with bits are used in **Data compression** (data is compressed by converting it from one representation to another, to reduce the space)
   2. **Exclusive-Or Encryption** (an algorithm to encrypt the data for safety issues).
   3. In order to encode, decode or compress files we have to extract the data at bit level. Bitwise operations are faster and closer to the system and sometimes optimize the program to a good level.
3. Bitwise Operators
   1. Not (~): Bitwise not is an unary operator that flips the bits of the number
   2. AND (&): Bitwise AND is a binary operator that operates on two equal-length bit patterns.
   3. OR (|): Bitwise OR is also a binary operator that operates on two equal-length bit patterns, similar to bitwise AND
   4. XOR (^): Bitwise XOR also takes two equal-length bit patterns.
   5. Left Shift (<<): Left shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the left and append 0 at the end
   6. Right Shift (>>): Right shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the right and append 1 at the end.
4. Applications
   1. They are widely used in areas of graphics, especially XOR(Exclusive OR) operations
   2. They are widely used in the embedded systems, in situations, where we need to set/clear/toggle just one single bit of a specific register without modifying the other contents. We can do OR/AND/XOR operations with the appropriate mask for the bit position.
   3. Data structure like n-bit map can be used to allocate n-size resource pool to represent the current status.
   4. Bits are used in networking, framing the packets of numerous bits which is sent to another system generally through any type of serial interface.

## Recursion and Backtracking

1. Background
   1. When a function calls itself, it's called recursion.
   2. It's useful for solving problems which can be broken down into smaller problems of the same kind.
      1. Any recursive method must have a terminating condition. One that the answer is already known and we just need to return that.
      2. There is an upper limit to the number of recursive calls that can be made. To prevent this make sure that your base case is reached before stack size limit exceeds.
2. Requirements to solving a problem using recursion
   1. The problem can be broken down into smaller problems of same type
   2. Problem has some base case(s)
   3. Base case is reached before the stack size limit exceeds
3. Backtracking
   1. While solving a problem using recursion, we break the given problem into smaller ones. However let's say we have a problem A and we divided into three smaller problems B, C and D. Now it may be the case that the solution to A does not depend on all the three subproblems, in fact we don't even know on which one it depends.
   2. Basically in backtracking we attempt solving a subproblem, and if we don't reach the desired solution, then undo whatever we did for solving that subproblem and try solving another subproblem.
4. N-Queens Problem
   1. Given a chess board having N x N cells, we need to place N queens in such a way that no queen is attacked by any other queen. A queen can attack horizontally, vertically and diagonally.
   2. Initially we are having N x N unattacked cells where we need to place N queens. First let's place the first queen at a cell (i,j), so now the number of unattacked cell is reduced, and number of queens to be placed is N - 1. Place the next queen at some unattacked cell. This again reduces the number of unattacked cells and number of queens to be placed becomes N-2. Continue doing this, as long as following holds true
      1. The number of unattacked cells is not 0.
      2. The number of queens to be placed is not 0
   3. If the number of queens to be placed becomes 0, then it's over and we found a solution
   4. If the number of unattacked cells become 0, then we need to backtrack, i.e. remove the last placed queen from its current cell, and place it at some other cell. We do so recursively.