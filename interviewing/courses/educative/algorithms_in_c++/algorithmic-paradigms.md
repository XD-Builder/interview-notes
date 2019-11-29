# Abstract

- This document explores algorithmic paradigms

## Brute Force

1. Def
   1. **The most straightforward and exhaustive option for solving a problem**. It requires us to go through all the possibilities to find a solution to the problem we are meaning to solve.
   2. Ex. If we have an array of integers and we want to find the minimum, maximum, or certain element in that array, the Brute Force approach requires us to go through all the elements to find that specific element.
      1. There are no shortcuts, no performance improvement; not at this stage.
   3. Though this approach is the most inefficient, it might be the first one that we can think of and it is guaranteed to find the solution.
2. Examples - Linear Search
   1. A method for finding a target value within a given array. It sequentially checks each element of the array for the target value until a match is found or all the elements have been searched.
      1. It runs in linear time (at its worst) and makes n comparisons (at most), where n is the length of the list.
      2. O(n) in time complexity

## Greedy Algorithms

1. Def
   1. Greedy algorithm is an algorithmic paradigm that **builds up on a solution piece by piece**; this means it chooses the next piece that **offers the most obvious and immediate benefit**.
   2. A Greedy algorithm, as the name implies, always makes the choice that seems to be the best at the time.
      1. It makes a locally optimal choice in the hope that it will lead to a globally optimal solution
      2. The problems where the locally-optimal choice leads to a global solution are the best fit for the Greedy technique.
2. Required problem properties
   1. Greedy choice property - A global optimum can be arrived at by selecting a local optimum.
   2. Optimal substructure - An optimal solution to the problem contains an optimal solution to subproblems.
3. How it works
   1. It works by **recursively constructing a set of pieces from the smallest possible constituent parts**.
   2. Recursion is an approach to problem-solving in which the solution to a particular problem depends on solutions to smaller instances of the same problem.
   3. Disadvantage is that it is entirely possible that the most optimal short-term solutions may lead to the worst possible long-term outcome
   4. Advantage is that solutions to smaller instances of the problem can be straightforward and easy to understand.

## Divide and Conquer Method

1. Def
   1. An algorithmic paradigm in which the problem is **repeatedly divided into sub-problems until we reach a point where each problem is similar and atomic and can't be divided further**. At this point, we start **solving these atomic problems and combining (merging) the solutions together**.
2. 3 steps in Divide and Conquer
   1. Divide
      1. Break the problem at hand into smaller sub-problems. This step can be achieved in a recursive fashion to divide the problem until no further division is possible
   2. Conquer
      1. Solve the received atomic sub-problem from Step 1. Often the problems are considered solved and passed onto the next step.
   3. Merge
      1. Repeatedly combine the solved sub-problems to formulate a solution for the original problem

## Dynamic Programming
1. Def
   1. An algorithmic paradigm that solves problems by combining results of subproblems - just like Divide and Conquer algorithms.
2. Characteristics
   1. Overlapping subproblems
      1. **The subproblems of a given problem are not independent; in other words, two subproblems don't share a subsubproblem**.
   2. Optimal Substructure Property
      1. The overall optimal solution of the problem can be constructed from the optimal solutions of its subproblems.
3. DP Patterns
   1. Memoization (Top Down)
      1. The memoized version of a problem is similar to the regular recursive version, except that **it looks for the answer of a subproblem in a lookup table before computing its solution**.
   2. Tabulation (Bottom up)
      1. Tabulation is the opposite of the top-down approach and **avoids recursion**. In this approach, we solve the problem "bottom-up". This is typically done by **filling up a lookup table, and computing the solution to the top/original problem based on the results in the table**.
