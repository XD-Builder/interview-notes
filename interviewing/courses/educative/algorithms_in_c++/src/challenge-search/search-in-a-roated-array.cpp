// Problem Statement
// Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in ascending order.

// Input
// A sorted array that has been rotated a number of times

// Output
// The index of the element

// Sample Input

// int arr[] = {7, 8, 9, 0, 3, 5, 6}
// int left = 0; // Index of the start of the array
// int right = 6; // Index of the end of the array
// int s = 3; // Element that is being searched for
// Sample Output

// 4 // Index of the element that was searched for

#include <iostream>
using namespace std;
int searchRotatedArrayLogN(int arr[], int left, int right, int s);
int searchRotatedArrayBruteForce(int arr[], int left, int right, int s);

int main()
{
    int arr[] = {1, 2, 55, 100, -100, -50, -10};
    // int index = searchRotatedArrayBruteForce(arr, 0, 6, -100);
    int index = searchRotatedArrayLogN(arr, 0, 6, -100);
    cout << "Index: " << index << endl;
}

int searchRotatedArrayBruteForce(int arr[], int left, int right, int s) {
  if (right <= 0) // Sanity check
    return -1;
  
  for(int i = 0; i < right; i++)
    if(arr[i] == s)
      return i; // If found return index
  
  return -1; // Return -1 otherwise
}


int searchRotatedArrayLogN(int arr[], int left, int right, int s)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == s)
        {
            return mid;
        }
        // scenario when s is greater than mid
        else if (s > arr[mid])
        {
            // negate right half if mid is greater than right
            // and s is greater than right too
            if (arr[mid] > arr[right] && s > arr[right]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        else if ( s < arr[mid])
        {   
            // negate left half if mid is greater than left and left is greater s so we know we should look right half
            if (arr[mid] > arr[left] && arr[left] > s){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}