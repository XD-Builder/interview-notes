#include <iostream>
using namespace std;

// takes an array of integers and an integer to find
// returns index of element if exists otherwise -1
int find_index(int array[], int to_find, int array_size) {
  // loop thru each element in the array
  for(int i = 0; i < array_size; i++){
    // check if this is the element you want to find
    if (array[i] == to_find){
      // if found return its index
      return i;
    }
  }
  return -1; // element not found, return -1
}

// takes an array and returns the index of maximum
// number in that array
int maximum_index(int array[], int array_size) {
  // initialize index to 0
  int max_index = -1;
  // set max value to least number
  int max_val = INT_MIN;
  // loop thru each element in array
  for(int i=0; i<array_size; i++){
    if (max_val < array[i]) {
      max_val = array[i];
      max_index = i;
    }
  }
  return max_index;
}

// takes an array and returns the index of minimum
// number in that array
int minimum_index(int array[], int array_size) {
  // initialize index to 0
  int min_index = -1;
  // set min value to the largest number
  int min_val = INT_MAX;
  // loop thru each element in array
  for(int i=0; i<array_size; i++){
    if (min_val > array[i]) {
      min_val = array[i];
      min_index = i;
    }
  }
  return min_index;
}

int main(int argc, char const *argv[])
{
    int * array = new int[5];
    for (int i = 0 ; i< 5; i++){
      array[i] = i + 5;
    }

    cout << array[find_index(array, 6, 5)] << ", At Index: " << find_index(array, 6, 5) << endl;
    cout << array[maximum_index(array, 5)] << ", At Index: " << maximum_index(array, 5) << endl;
    cout << array[minimum_index(array, 5)] << ", At Index: " << minimum_index(array, 5) << endl;

    return 0;
}
