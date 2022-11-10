/*
  STL Algorithm:
    sort() - sorting in ascending order.
    reverse() - sorting in descending order.
    accumulate () - sum of the elements in the vector

    TODO:
      Test with providing subset of vector.
        sort the first half of a vector, we could modify the iterator to produce just the first half of the elements.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main (){

  std::vector<int> v {1,5,3};

  // sort a vector
  std::sort(v.begin(), v.end()); // the entire vector

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
  sum = std::accumulate(v.begin(), v.end(), 0); // 0 - running sum will start at; if double then 0.0; typically 0, but we can use any number. If we use 3 then the accumulation will start from 3 onwards.
  std::cout << sum << std::endl;

  return 0;
}
