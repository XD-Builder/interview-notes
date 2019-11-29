# Abstract

- This document will try to explain efficient algorithms to sort top K elements in a big list.

# Problem statement

- Given an array and a number k where k is smaller than size of array and we need to find the k'th largest element in the given array. It is given that array elements are distinct

# O(n\*log(n)) Solutions

1. Merge Sort
   1. A divide and conquer algorithm to divide the problem into subproblems and merge the results into one single sorted array
   2. Steps
      1. Split array into sub-array until it can't be split anymore
      2. compare smallest left array with right array to come up with smallest sorted array. Say [1] compared to [10] returns [1, 10]
      3. Return the sorted array on the left side and compare it with the right side [1, 10] to [2, 5], ops include 1-2,10-2, 10-5 and 10
      4. Recursively compare and merge the result
2. Heap Sort
   1. A comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.
   2. What is a Binary Heap?
      1. A Complete Binary Tree where items are stored in a special order such that value in a parent node is greater(or smaller) than the values in its two children nodes. The former is called **max heap** and the latter is called **min heap** and this heap can be represented by binary tree or array.
      2. Why array representation?
         1. Array representation is space efficient
   3. Steps
      1. Build a max heap
         1. Adding root to the array from highest index to low and check children recursively to see swap root if necessary.
      2. Extract max element from heap one at a time
         1. Swap out the root element with elements at highest array index. Effectively, it removes the root node and set the highest index element of the array to the root node
3. Conclusion
   1. As n scales to say 1000, the complexity would be 1000 \* 10 = 10,000 where log(n) = 10 because 2^10 ~= 1000
   2. It will scale well but will be more become increasingly expensive as n gets very large

# O(n + k \* log(n))

1. Max Heap - HeapSelect
   1. Find k'th smallest element in time complexity better than O(n \* log(n)) by creating a Max Heap of the given n element and call extractMax() k times

# QuickSort

1. Steps
   1. Build a max heap
   2. Extract max element from heap k times

2. Conclusion
   1. As n scales to say 1000, the complexity would be 1000 + 10 \* 10 = 1,100 where log(n) = 10 because 2^10 ~= 1000 and k = 10 because we want top 10
   2. It will scale very well with very large number of n because cost is mostly fixated at O(n) if k doesn't increase
