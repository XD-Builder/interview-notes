// Problem Statement
// Given an array of strings that contains anagrams, write a function to print pairs of those anagrams.

// Input
// An array of strings. Remember that spaces count as characters! So " abc" and “cab” are technically not anagrams since " abc" has spaces which “cab” does not.

// Output
// A string vector where all the anagrams are grouped together.

// Sample Input

// string arr[] = {
//     "tom marvolo riddle ",
//     "abc",
//     "def",
//     "cab",
//     "fed",
//     "brag",
//     "clint eastwood ",
//     "i am lord voldemort",
//     "elvis",
//     "grab",
//     "old west action",
//     "lives"
//   };
// Sample Output

// vector <string> vec = {
//     "clint eastwood",
//     "old west action",
//     "tom marvolo riddle",
//     "i am lord voldemort",
//     "elvis",
//     "lives",
//     "def",
//     "fed",
//     "abc",
//     "cab"
//   };

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int choosePivot(int left, int right) {
  // Pick 3 random numbers within the range of the array
  int i1 = left + (rand() % (right - left + 1));
  int i2 = left + (rand() % (right - left + 1));
  int i3 = left + (rand() % (right - left + 1));

  // Return their median
  return max(min(i1, i2), min(max(i1, i2), i3));
}

int partition(string & arr, int left, int right) {
  int pivotInd = choosePivot(left, right); // Index of pivot
  swap(arr[right], arr[pivotInd]); // put the pivot at the end
  int pivot = arr[right]; // Pivot 
  int i = (left - 1); // All the elements less than or equal to the
  // pivot go before or at i

  for (int j = left; j <= right - 1; j++) {
    if (arr[j] <= pivot) {
      i++; // increment the index 
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]); // Putting the pivot back in place
  return (i + 1);
}

void quickSort(string & arr, int left, int right) {
  if (left < right) {
    // pi is where the pivot is at
    int pi = partition(arr, left, right);

    // Separately sort elements before and after partition 
    quickSort(arr, left, pi - 1);
    quickSort(arr, pi + 1, right);
  }
}

// n * k * log(k)
vector<string> groupAnagrams(string strArray[], int arrSize)
{
  string dup[arrSize];
  vector<string> output;
  for (int i = 0; i < arrSize; i++) // Hard copying the given array
    dup[i] = strArray[i];

  for (int i = 0; i < arrSize; i++) // Sorting the words in the duplicate array
    quickSort(dup[i], 0, dup[i].length() - 1);

  // Constructing a map where key is each sorted word
  // and value is a vector of indices where it is present
  unordered_map < string, vector < int >> map;
  for (int i = 0; i < arrSize; i++)
    map[dup[i]].push_back(i);

  // Traversing the map and reading indices for each sorted key.
  // The anagrams are present in the actual list at those indices
  for (auto itr: map) {
    for (int index: itr.second) {
      output.push_back(strArray[index]);
    }
  }
  return output;
}

int main(int argc, char const *argv[])
{
  string strArr[] = {"hello", "ohell", "said", "dais", "back"};

  for (const string &s : groupAnagrams(strArr, 5))
  {
    cout << s << endl;
  }
  return 0;
}