# Abstract

- This document explores definitions, categories and applications of algorithm

## Overview

1. Def
   1. Algorithm is an unambiguous specification of how to solve a class of problems. It can perform calculation, data processing, automated reasoning, and other tasks.
   2. An algorithm can be expressed with a finite amount of space and time and in a well-defined formal languages for calculating a function.
      1. Starting from an initial state an initial input, the instructions describe a computation that, when executed, proceeds through a finite number of well-defined successive states, eventually producing "output" and terminating at a final ending state. The transition from one state to the next is **not necessarily deterministic**; some algorithms, known as randomized algorithms, incorporate random input.

## Design

1. Def
   1. A method or mathematical process for problem-solving and engineering algorithms. **The design of algorithms is part of many solution theories of operation research, such as dynamic programming and divide-and-conquer**.
   2. Techniques for designing and implementing algorithm design are also called algorithm design patterns, such as the template method pattern and decorator pattern.
   3. **Most important aspects of algorithm design is creating an algorithm that has an efficient runtime known as Big O.**
2. Design Steps
   1. Problem Definition
   2. Development of a model
   3. Specification of the algorithm
   4. Designing an algorithm
   5. Checking the correctness of the algorithm
   6. Analysis of algorithm
   7. Implementing of algorithm
   8. Program testing
   9. Documentation preparation

## Classification

### By Implementation

1. Recursion
   1. An algorithm that invokes itself repeatedly until a certain condition known as termination condition matches, which is a method common to functional programming.
   2. Iterative algorithms use repetitive constructs like loops and sometimes additional data struct like stacks to solve the given problems.
      1. Some problems are naturally suited for one implementation or the other.
      2. Ex. Towers of Hanoi is well understood using recursive implementation.
      3. **Every recursive version has an equivalent (but possibly more or less complex) iterative version and vice versa.**
2. Logical
   1. An algorithm may be viewed as controlled logical deduction, expressed as "Algorithm = logic + control"
      1. The **logic component expresses the axioms** that may be used in the **computation** and the **control component determines the way in which deduction is applied to the axioms**.
      2. In pure logic programming languages, the control component is fixed and **algorithms are specified by supplying only the logic component**. The appeal for **this approach is the elegant semantics**: a change in the axioms produces a well-defined change in the algorithm.
3. Serial, parallel or distributed
   1. An algorithm designed for one single instruction execution at a time is called serial algorithm.
   2. **Parallel algorithms take advantage of computer architectures where several processors can work on a problem at the same time, whereas distributed algorithms utilize multiple machines connected with a computer network**.
      1. Parallel or distributed algorithms **divide the problem into more symmetrical or asymmetrical subproblems and collect the results back together**. The resource consumption in such algorithms is not only processor cycles on each processor but also the communication overhead between the processors.
      2. Some sorting algorithms can be parallelized efficiently, but their communication overhead is expensive. **Iterative algorithms are generally parallelizable. Some problems have no parallel algorithms and are called inherently serial problems**.
4. Deterministic or non-deterministic
   1. **Deteterministic algorithm solve the problem with exact decision at every step of the algorithm** whereas **non-deterministic algorithms solve problems via guessing although typical guesses are made more accurate through the use of heuristics**.
5. Exact or approximate
   1. While many algorithms search an exact solution, **approximation algorithm seek an approximation that is closer to the true solution**.
   2. The approximation can be reached by either using a deterministic or a random strategy.
   3. **Approximate algorithms have practical values for many hard problems**, like Knapsack problem, where there is a set of given items.
6. Quantum Algorithm
   1. Run on a realistic model of quantum computation.
   2. The term is used for **algorithms which seem inherently quantum, or use some essential feature of Quantum computing such as quantum superposition or quantum entanglement**.

### By design paradigm

1. Brute-force or exhaustic search
   1. **The naive method of trying every possible solution to see which is the best.**
2. Divide and conquer
   1. Repeatedly reduces an instance of a problem to one or more smaller instances of the same problem, often recursively, until the instances are small enough to solver easily.
      1. Ex. merge sorting. **Sorting can be done on each segment of data after dividing data into segments and sorting of entire data can be obtained in the conquer phase by merging the segments**.
   2. A simpler variant of divide and conquer is called a _decrease and conquer algorithm_, that solves an identical subproblem and uses the solution of this solution to solve the bigger problem.
      1. Ex. binary search tree, which decreases the problem to a subset iteratively.
      2. Divide and conquer divides the problem into multiple subproblems and so the conquer stage is more complex than decrease and conquer algorithms.
3. Search and enumeration
   1. Many problems (such as playing chess) can be modeled as problems on graphs.
   2. A graph exploration algorithm specifies rules for moving around a graph and is useful for such problems.
   3. This category also includes search algorithms, branch and bound enumeration and backtracking.
4. Randomized algorithm
   1. Such algorithms make some choice **(pseudo)randomly**. They can be useful in finding approximate solutions for problems where finding exact solutions can be impractical. For some of these problems, it is known that the fastest approximations must involve some randomness. **Whether randomized algorithms with polynomial time complexity can be the fastest algorithms for some problems is an open question known as the P vs NP problem**.
   2. Two large classes of such algorithms are:
      1. Monte Carlo algorithms
         1. return a correct answer with high-probability. Ex. RP, randomized polynomial time
      2. Last Vegas algorithms
         1. always return the correct answer, but their running time is only probabilistically bound. Ex. ZPP, zero error probabilistic polynomial time
5. Reduction of Complexity
   1. Involves **solving a difficult problem by transforming it into a better-known problem for which we have asymptotically optimal algorithms**.
      1. Asymptotically optimal means for large inputs it performs at worst a constant factor worse than the best possible algorithm.
      2. Ex. One selection algorithm for finding the median in an unsorted list involves first sorting the list and then pulling out the middle element in the sorted list, a technique known as transform and conquer.
6. Back tracking
   1. **In this approach, multiple solutions are built incrementally and abandoned when it is determined that they cannot lead to a valid full solution.**

### Optimization Problems

1. **Linear programming**
   1. When searching for optimal solutions to a linear function bound to linear equality and inequality constraints, **the constraints of the problem can be used directly in producing the optimal solutions**.
   2. It can solve any problem in this category such as the popular **simplex algorithm** and **maximum flow problem for directed graphs**.
   3. If a problem additionally requires that one or more of the unknowns must be an integer then it is classified integer programming.
      1. A linear programming algorithm can solve such a problem if it can be proved that all restrictions for integer values are superficial, i.e., the solutions satisfy these restrictions anyway.
      2. In general case, a specialized algorithm or an algorithm that finds approximate solutions is used, depending on the difficulty of the problem.
2. Dynamic programming
   1. When a problem shows optimal substructures - **meaning the optimal solution to a problem can be constructed from optimal solutions to subproblems** - an overlapping subproblems, meaning the same subproblems are used to solve many different problem instances, **a quicker approach called dynamic programming avoids recomputing solutions that hve already computed**.
      1. Ex. Floyd–Warshall algorithm, the shortest path to a goal from a vertex in a weighted graph can be found by using the shortest path to the goal from all adjacent vertices.
   2. **Dynamic programming and memoization go together**. The main difference between dynamic programming and divide and conquer is that **subproblems are more or less independent in divide and conquer, whereas subproblems overlap in dynamic programming**. The difference between dynamic programming and straightforward recursion is in caching or memoization of recursive calls. **When subproblems are independent and there is no repetition, memoization does not help; hence dynamic programming is not a solution for all complex problems**. By using memoization or maintaining a table of subproblems already solved, **dynamic programming reduces the exponential nature of many problems to polynomial complexity**.
3. The greedy method
   1. A greedy algorithm is similar to a dynamic programming algorithm in that it works by examining substructures, **in this case not of the problem but of a given solution**.
   2. Such algorithms **start with some solution, which may be given or have been constructed in some way, and improve it by making small modifications**. For some problems they can find the optimal solution while for others they stop at local optima, that is, at solutions that cannot be improved by the algorithm but are not optimum. 
   3. **The most popular use of greedy algorithms is for finding the minimal spanning tree where finding the optimal solution is possible with this method**. 
      1. Huffman Tree, Kruskal, Prim, Sollin are greedy algorithms that can solve this optimization problem.
4. The heuristic method
   1. In optimization problems, heuristic algorithms can be used to **find a solution close to the optimal solution in cases where finding the optimal solution is impractical**. These algorithms work by getting closer and closer to the optimal solution as they progress. **In principle, if run for an infinite amount of time, they will find the optimal solution**.
   2. Their merit is that they can find a solution very close to the optimal solution in a relatively short time. **Such algorithms include local search, tabu search, simulated annealing, and genetic algorithms**. 
      1. **Some of them, like simulated annealing, are non-deterministic algorithms while others, like tabu search, are deterministic**. 
      2. When a bound on the error of the non-optimal solution is known, **the algorithm is further categorized as an approximation algorithm**.

### By field of study

1. Every field of science has its own problems and needs efficient algorithms. Related problems in one field are often studied together.
2. Some classes of algorithms are:
   1. search algorithms
   2. sorting algorithms
   3. merge algorithms
   4. numerical algorithms
   5. graph algorithms
   6. string algorithms
   7. computational geometric algorithms
   8. combinatorial algorithm
   9. medical algorithms
   10. machine learning,
   11. cryptography
   12. data compression
   13. parsing techniques
3. Algorithm advances in one field may improve those of other, sometimes completely unreleated, fields. Ex. dynamic programming was invented for optimization of resource consumption in industry but is now used in solving a broad range of problems in many fields.

### By Complexity

1. Constant time
   1. If the **time needed by the algorithm is the same, regardless of the input size**. Ex. an access to an array element.
2. Linear time
   1. If the time is **proportional to the input size**. Ex. traverse a list.
3. Logarithmic time
   1. If the time is a **logarithmic function of the input size**. Ex. binary search algorithm.
4. Polynomial time
   1. If the time is a **power of the input size**. Ex. bubble sort algorithm has quadratic time complexity.
5. Exponential time
   1. If the time is an **exponential function of the input size**. Ex. Brute-force search