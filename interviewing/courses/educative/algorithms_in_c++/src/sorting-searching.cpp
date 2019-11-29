#include "auxiliary-function.cpp"

void selectionSort(int *arr, int arrSize)
{
  int maxInd;
  for (int i = 0; i < arrSize; i++)
  {
    maxInd = findMin(arr, i, arrSize - 1); // findMin expects a start and end index so arrSize won't work
    swap(arr[i], arr[maxInd]);
  }
}

void bubbleSort(int arr[], int arrSize)
{
  int i, j;
  for (i = 0; i < arrSize - 1; i++)
    // Last i elements are already in place
    for (j = 0; j < arrSize - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

void insertionSort(int arr[], int arrSize)
{
  int ele, j;
  for (int i = 1; i < arrSize; i++)
  {
    ele = arr[i]; // Element to be inserted
    j = i - 1;

    // shifts elements back to space for the element to be inserted
    while (j >= 0 && arr[j] > ele)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = ele;
  }
}

// ------- MERGE SORT
void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;

  // Initialzing the sizes of the temporary arrays
  int sizeLeft = mid - left + 1;
  int sizeRight = right - mid;

  // Initializing temporary arrays
  int leftArr[sizeLeft], rightArr[sizeRight];

  // Copying the given array into the temporary arrays
  for (i = 0; i < sizeLeft; i++)
    leftArr[i] = arr[left + i];
  for (j = 0; j < sizeRight; j++)
    rightArr[j] = arr[mid + 1 + j];

  // Merging the temporary arrays back into the given array
  i = 0;    // Initial index of first subarray
  j = 0;    // Initial index of second subarray
  k = left; // Initial index of the given array

  // This is the main part of the algorithm
  // Iterate over both arrays and copy the element that is smaller to the
  // given array.
  while (i < sizeLeft && j < sizeRight)
  {
    if (leftArr[i] <= rightArr[j])
    {
      arr[k] = leftArr[i];
      i++;
    }
    else
    {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // Copying the remaining elements of leftArr[], if there are any
  while (i < sizeLeft)
  {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of rightArr[], if there are any
  while (j < sizeRight)
  {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int leftIndex, int rightIndex)
{
  // Sanity checks
  if (leftIndex < 0 || rightIndex < 0)
    return;

  if (rightIndex > leftIndex)
  {
    // Equivalent to (leftIndex+rightIndex)/2, but avoids overflow
    int mid = leftIndex + (rightIndex - leftIndex) / 2;

    // Sorting the first and second halves of the array
    mergeSort(arr, leftIndex, mid);
    mergeSort(arr, mid + 1, rightIndex);

    // Merging the array
    merge(arr, leftIndex, mid, rightIndex);
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

// ----- Brute Force Linear Search
int linearSearch(int s, int *arr, int arrSize)
{
  if (arrSize <= 0)
    return -1;
  for (int i = 0; i < arrSize; i++)
    if (arr[i] == s)
      return i;
  return -1;
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
    mid = (start + end)/2;

    if (s > arr[mid])
    {
      start = mid + 1;
    }
    else if ( s < arr[mid])
    {
      end = mid - 1;
    } else {
       return mid;
    }
  }
  return -1;
}

void sorting();
void searching();

int main(int argc, char const *argv[])
{
  // sorting();
  searching();
}

void searching()
{
  // int arr[] = {5, 4, 1, 0, 5, 95, 4, -100, 200, 0};
  int arr[] = {-100, 0, 0, 1, 4, 4, 5, 5, 95, 200};
  int arrSize = 10;
  int toSearch = 0;

  int index = binarySearch(toSearch, arr, arrSize);
  // int index = linearSearch(toSearch, arr, arrSize);
  if (index != -1)
    cout << arr[index] << endl;
  else
    cout << toSearch << " not found in the array: ";
  printArray(arr, arrSize);
}

void sorting()
{

  int array[] = {1, 2, 4, 3, 5, 6};
  cout << "Before: ";
  printArray(array, sizeof(array) / sizeof(array[0]));

  // sorting algo O(n^2)
  // selectionSort(array, sizeof(array)/sizeof(array[0]));
  // bubbleSort(array, sizeof(array)/sizeof(array[0]));
  // insertionSort(array, sizeof(array)/sizeof(array[0]));

  // sorting algo O(n*log(n))
  // mergeSort(array, 0, sizeof(array)/sizeof(array[0])-1);
  quickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

  cout << "After: ";
  printArray(array, sizeof(array) / sizeof(array[0]));
}