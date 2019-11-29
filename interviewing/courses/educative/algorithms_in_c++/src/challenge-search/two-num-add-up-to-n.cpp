// Problem Statement
// Implement a function that takes an array arr, a number value, and the size of the array as an input, and returns two numbers which add up to value.

// Input
// An array, value, and size of the array

// Output
// An array with two integers that add up to value

// Sample Input

// arr = {1,21,3,14,5,60,7,6};
// value = 81;
// Sample Output

// arr = {21,60};
// For example, in this illustration we are given 81 as the number value. When we traverse the whole array, we find that 21 and 60 are the integers that add up to 81.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void quickSort(int arr[], int left, int right);
int choosePivot(int left, int right);
int partition(int arr[], int left, int right);
int binarySearch(int s, int arr[], int arrSize);
vector<int> findSumNSquared(int arr[], int arrSize, int s);
vector<int> findSumNLogNPlusN(int arr[], int arrSize, int s);
vector<int> findSumNLogNPlusLogN(int arr[], int arrSize, int s);
vector<int> findSumN(int arr[], int arrSize, int s);

int main()
{
    int arr[] = {1, -1, 2, -2};
    // vector<int> sums = findSumNSquared(arr, 4, 0);
    vector<int> sums = findSumN(arr, 4, 0);
    // vector<int> sums = findSumNLogNPlusLogN(arr, 4, 0);

    for (vector<int>::iterator it = sums.begin(); it != sums.end(); it++)
    {
        cout << *it << endl;
    }
    // for (auto const& value: sums){
    //     cout << value << endl;
    // }
}

// n^2 because linear search (n) * n outer loop
vector<int> findSumNSquared(int arr[], int arrSize, int s)
{
    unordered_set<int> US;
    vector<int> elements;
    for (int i = 0; i < arrSize; i++)
    {
        int temp = s - arr[i];
        if (US.find(temp) != US.end())
        {
            elements.push_back(arr[i]);
            elements.push_back(temp);
        }
        US.insert(arr[i]);
    }
    return elements;
}

vector<int> findSumNLogNPlusN(int arr[], int arrSize, int s)
{
    quickSort(arr, 0, arrSize - 1); // Sort the array in Ascending Order
    vector<int> elements;
    int ind1 = 0;           // index of the start of the array
    int ind2 = arrSize - 1; // index of the end of the array
    int sum = 0;

    while (ind1 <= ind2)
    {
        sum = arr[ind1] + arr[ind2]; // Calculate Sum of Pointer 1 and 2
        if (sum < s)
            ind1++; // If sum is less than given value => Move Pointer 1 to Right
        else if (sum > s)
            ind2--;
        else
        {
            elements.push_back(arr[ind1]);
            elements.push_back(arr[ind2]);
            break;
        }
    }
    return elements;
}

vector<int> findSumNLogNPlusLogN(int arr[], int arrSize, int s)
{
    quickSort(arr, 0, arrSize - 1); //Sort the array in Ascending Order
    vector<int> elements;
    int foundInd;
    for (int i = 0; i < arrSize; i++)
    {
        foundInd = binarySearch(s - arr[i], arr, arrSize);
        if (foundInd != -1)
        {
            elements.push_back(arr[i]);
            elements.push_back(arr[foundInd]);
        }
    }
    return elements;
}

vector<int> findSumN(int arr[], int arrSize, int s)
{
    // Implemented using hashtable, O(1) op time
    unordered_set<int> US;
    vector<int> elements;
    // O(n) iteration time
    for (int i = 0; i < arrSize; i++)
    {
        int temp = s - arr[i];
        // O(1) find and compare
        if (US.find(temp) != US.end())
        {
            elements.push_back(arr[i]);
            elements.push_back(temp);
        }
        // O(1) insert underlying hashtable
        US.insert(arr[i]);
    }
    return elements;
}

int binarySearch(int s, int arr[], int arrSize)
{
    if (arrSize <= 0)
        return -1;

    int start = 0;
    int end = arrSize - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (s > arr[mid])
        {
            start = mid + 1;
        }
        else if (s < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // pi is where the pivot is at
        int pi = partition(arr, left, right);

        // Separately sort elements before and after partition
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

// ------- Space Efficient In-place Quicksort
int choosePivot(int left, int right)
{
    // Pick 3 random numbers within the range of the array
    int i1 = left + (rand() % (right - left + 1));
    int i2 = left + (rand() % (right - left + 1));
    int i3 = left + (rand() % (right - left + 1));

    // Return their median
    return max(min(i1, i2), min(max(i1, i2), i3));
}

int partition(int arr[], int left, int right)
{
    int pivotInd = choosePivot(left, right); // Index of pivot
    swap(arr[right], arr[pivotInd]);         // put the pivot at the end
    int pivot = arr[right];                  // Pivot
    int i = (left - 1);                      // All the elements less than or equal to the
    // pivot go before or at i

    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; // increment the index
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); // Putting the pivot back in place
    return (i + 1);
}