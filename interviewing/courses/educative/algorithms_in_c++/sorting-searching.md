# Abstract

- This document explores sorting and searching.

## Selection Sort, Bubble Sort, & Insertion Sort - O(n^2)

1. Def
   1. Sorting is any process of arranging items systematically.
   2. In CS, sorting algorithms put elements of a list in a certain order.
2. Selection Sort Algorithm
   1. Sorting Steps
      1. **The algorithm divides the input array into two parts**: **the sublist of already-sorted elements**, which is built up from left to right, and **the sublist of the remaining elements** that occupy the rest of the list and need to be sorted.
      2. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by **finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right**.
         1. In other words, this algorithm works by iterating over the array and swapping each element with the minimum element found in the rest of the array.
3. Bubble Sort Algorithm
   1. About
      1. Another famous sorting algorithm also known as "sinking sort". It works by comparing adjacent pairs of elements and swapping them if they are in the wrong order. This is repeated until the array is sorted.
      2. Think of it as a bubble passes over the array and 'catches' the max/min element and brings it over to the right side.
4. Insertion Sort
   1. About
      1. Another very famous sorting algorithm, and works the way you would naturally sort in real life.
      2. It iterates over the given array, and figures out what the correct position of every element is and inserts it there.

## Merge Sort

1. Def
   1. A recursive Divide & Conquer algorithm that essentially divides a given array into two halves, sort those halves, and merges them together in order. The base case is to merge two arrays of size 1 so, eventually, single elements are merged in order; the merge part is where the heavy lifting happens.
2. Pseudocode
   <pre><code>
       mergeSort(arr)
       if arr.length == 1
           return arr
       else:
           s1 = mergeSort(arr[0,n/2])
           s2 = mergeSort(arr[n/2+1,n])
       return merge(s1,s2)
   </code></pre>

## Quicksort

1. Background
   1. Invented in 1959/60 by the Turing award-winning British computer scientist, Sir Charles Antony Richard Hoare, Quicksort is one of the top 10 most influential algorithms of 20th century.
   2. It's another recursive divide and conquer algorithm and it's the fastest known comparison-based sorting algorithm for arrays in the average case.
      1. Merge sort works better on linked lists, and there are other non-comparison based algorithms that outperform Quicksort.
2. Pseudocode
   1. Start with an array of n elements
   2. **Choose a pivot element from the array to be sorted**
   3. Partition the array into 2 unsorted subarrays, such that all elements in **one subarray are less than the pivot** and all the elements in the **other subarray are greater than the pivot**.
   4. Elements that are equal to the pivot can go in either subarray.
   5. **Sort each subarray recursively to yield two sorted subarrays**
   6. **Concatenate the two sorted subarrays and the pivot to yield one sorted array.**
3. Performance
   1. Worst-case time complexity is in O(n^2), although this only happens when the wrong pivot is picked for every recursive call.
      1. If the median value in the array is chosen to be the pivot, then quicksort would be in O(n x log(n)) even in the worst case.
4. How to pick the pivot to avoid worst case
   1. Choose randomly
      1. The chances of the first element being picked at every recursive call is asymptotically equivalent to 1 /(n^(n-1)). So the larger the input size, the lower the chances the worst-case scenario occurring.
   2. Median-of-Three Strategy
      1. Pick three random elements from the array and chose their median. This ensures that the first element is not picked
5. Analysis
   1. The worst-case time complexity of Quicksort is in O(n^2) although the occurrence is rare, the average case complexity of Quicksort is in O(n\*log(n)) because for each log(n) recursive call, the given array is iterated over.

## Searching Algorithms

1. Linear Search
   1. The most simple searching algorithm and it is in O(n) time. It goes through each element one by one. When the element that you are searching for is found, return its index.
2. Binary Search
   1. Assuming that the input array is sorted, compare the element that is being searched for with the element at the middle of the array. If the element being searched for is greater than the element at the middle of the array, recursively check for it in the second half of the given array. Otherwise, search for it in the first half of the given array.
   2. Performance is O(log(n))