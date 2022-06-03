/*
  How we could use some of STLs functionality.
  STL Algorithm:
    sort() - sorting in ascending order.
    reverse() - sorting in descending order.
    accumulate () - sum of the elements in the vector
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main (){

  std::vector<int> v {1,5,3};

  // sort a vector
  std::sort(v.begin(), v.end()); //The sort algorithm needs a sequence of objects to sort. That's where the iterator comes in. We provide the sequence using v.begin() and v.end(). v.begin() and v.end() are iterators. This provides the sort algorithm with the integers in the vector v from the beginning element to the ending element, in other words, the entire vector.

  for (auto elem: v) // displaying a vector using range based for loop - behind the scenes, range based loop is an iterator.
    std::cout << elem << std::endl;

  // descending order
  std::cout << "\nDescendign Order" << std::endl;
  std::reverse(v.begin(), v.end());
  for (auto elem_r: v)
    std::cout << elem_r << std::endl;

  // Accumulate
  std::cout << "\nAccumulate" << std::endl;
  int sum {};
  sum = std::accumulate(v.begin(), v.end(), 0); // 0 - running sum will start at; if double then 0.0
  std::cout << sum << std::endl;

  return 0;
}
