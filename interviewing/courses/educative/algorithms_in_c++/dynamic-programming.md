# Abstract

1. This document introduces dynamic programming

## What is Dynamic Programming

1. What is
   1. Dynamic programming algorithms solve problems by combining results of subproblems, just like in the divide and conquer algorithms
2. Characteristics
   1. **Most problems that can be solved with dynamic programming can also be solved with a divide and conquer approach. The difference between the two is that the dynamic programming approach is applicable when a problem has overlapping subproblems; i.e. the subproblems of a given problem are not independent such as when two subproblems share a subsubproblem**. An example would be the Fibonacci code we saw in the last lesson where fib(3) had to be calculated in order to calculate both fib(4) and fib(5).
   2. Furthermore, **dynamic programming problems have the optimal substructure property which means that the overall optimal solution of the problem can be constructed from the optimal solutions of its subproblems**.
   3. Hence, a problem of size ‘n’ **can be reduced to subproblems of size ‘n-1’ and ‘n-2’**. Therefore, Fibonacci numbers have the optimal substructure property.
   4. Dynamic programming algorithms s**olve every subproblem just once and save the answer in a lookup table, thereby avoiding recalculating the answer every time the subproblem is encountered**.
   5. There are two dynamic programming patterns: **memoization and tabulation**
3. Memoization (Top Down)
   1. The memoized version (yes, that is not a typo - its memoization not memorization) of a problem is similar to the regular recursive version; the difference is that it looks for the answer of a subproblem in a lookup table before computing its solution. **If the precomputed value exists, then it is returned. Otherwise, the value is computed and put in the lookup table so that it can be reused later**.
4. Tabulation (Bottom Up)
   1. Tabulation is **the opposite of the top-down approach and avoids recursion**. In this approach, we solve the problem “bottom-up” (i.e. by solving all the related sub-problems first). **This is typically done by filling up a lookup table and based on the results in the table, the solution to the top/original problem is then computed**.
   2. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on.