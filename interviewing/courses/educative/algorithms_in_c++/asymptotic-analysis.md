# Abstract

- This document explores complexity measures, asymptotic analysis and big O

## Complexity Measures

1. Def
   1. 'Complexity' is an approximate measure of the efficiency of an algorithm. Two kinds of complexities are time and space. They are approximations of how much time and how much space an algorithm will take to process certain inputs respectively.
      1. Variables that affect an algorithm includes number of cores, read/write speed of memory, CPU architecture, disk usage and inputs.
      2. Since only input can be controlled, we measure the rate of growth of time/space with respect to the growth in the input.
2. Time complexity
   1. **An algorithm's rate of growth, with time taken in relation to the input**.
3. How to calculate time complexity
   1. The running time complexity is calculated by considering two things: the problem and the size of the data.
      1. List down **all the basic operations in the code**
      2. Count the **number of times each gets executed**
      3. **Sum all the counts to get an equation**

## Asymptotic Analysis and Big O

1. Asymptotic Analysis
   1. Algorithms can be put into broad categories based on their running time complexities using a technique called ‘asymptotic analysis.’ Mathematically, the asymptotic behavior of a function f(n) refers to the growth of f(n) as n gets large. Essentially, **asymptotic analysis is a way to frame an algorithm’s run-time complexity with a mathematical function for very large input sizes**.
2. Big O - O(n)
   1. The Big O complexity of an algorithm finds **the worst case behavior** of an algorithm **as its input size grows**. In other words, your **algorithm’s performance can’t be worse than its Big O complexity for large input sizes**. To find the Big O complexity of an algorithm from the running time complexity, you simply
      1. Drop the leading constants
      2. Ignore the lower order terms
   2. ∈ O(n ​3 ​​ ) (read: is in Big-Oh of n-cube). The Big O complexity gives an upper bound on the running time complexity of an algorithm. Formally, if f(n) ∈ O(g(n)) exist where c>0 and no0​​ ≥ 0 such that f(n)≤cg(n) and c and n0 are positive real numbers—such that n >= n0. So g(n) represents a set of all functions that satisfies **f(n) ≤ cg(n)**.
      1. n0 is the starting point, the input size n where n > n0 such that c\*g(n) is always the upper bound of the f(n) as n increases
      2. c is some constant to scale g(n) so it becomes the upper bound of f(n)

## Other Common Asymptotic Notations and Why Big O Trumps Them

1. Big 'Omega' - Ω(n)
   1. It finds **the best case behavior of an algorithm as its input size grows**. In other words, your algorithm’s **performance can not be better than its Big Omega complexity for large input sizes**.
      1. For example, If f(n)=n^2 ​​then it is in Ω(n) and in Ω(n^2).
      2. Formally, if there exists a real constant c > 0 and there exists n0 > 1 and **f(n) ≥ cg(n)** for n ≥ n0 ​​ then f(n) is in Ω(g(n)).
2. Big 'Theta' - Θ(n)
   1. if f(n) is in O(g(n)) and f(n) is also in Ω(g(n)) then it is in Θ(n). Formally, f(n) is in Θ(n) if there exist constants c1 > 0, c2 > 0 and an n0 ≥ 0 such that **c2g(n) ≤ f(n) ≤ c1g(n)** and n ≥ n0.
   2. So Big Theta is an ‘asymptotically tight bound.’ When a particular running time is Θ(n), the running time is at least c1g(n) and at most c2g(n); i.e., it is sandwiched between two functions.
3. Little 'o' - o(n)
   1. f(n) is in o(g(n)) if for any constant c > 0 there is an n0 >= 1 such that f(n) < cg(n) (strictly less) for all possible values of c and n >n0
      1. **It shows that there is a minimum n after which the inequality holds no matter how small you make c, as long as it's not negative or zero**.
   2. Ex
      1. n+10 ∈ o(n^2) ∈ o(10^n) ∈ o(nlogn) ∉ o(n) ∉ o(n−10)
4. Little 'omega' - ω(n)
   1. A function f(n) is in w(g(n)) if for any c > 0 there exists an n0 > 1 such that f(n) > cg(n) for n >= n0.
   2. Ex
      1. 5n^2 ∈ ω(n) ∈ ω() ∉ ω(n^2)
5. Summary
   1. Algorithm => Performance
      1. o(n) => < n
      2. O(n) => <= n
      3. Θ(n) => = n
      4. Ω(n) => >= n
      5. ω(n) => >n
         1. Out of these, **Big O is the one that is almost always preferred to analyze an algorithm, as average and best cases do not give insight to the efficiency of an algorithm for most use-cases**.
