# Abstract

- This document explores Greedy Approach algorithm

## Greedy Approach to problems

1. Problem
   1. Statement
      1. Say you are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
   2. Mathematically
      1. Let S = 1,2,..., n be the set of activities that compete for a resource.
      2. Each activity i has its starting time s(i) and finish time f(i) with s(i) <= f(i), namely, if selected, i takes place during time [s(i), f(i)).
      3. No two activities can share the resource at any time point. We say that activities i and j are compatible if their time period are disjoint.
   3. Conclusion
      1. The activity-selection problem is the problem of selecting the largest set of mutually compatible activities.
