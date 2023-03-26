/*
  STL Algorithm:
    sort() - sorting in ascending order.
    reverse() - sorting in descending order.
    accumulate () - sum of the elements in the vector
    copy ()
      back_inserter
    min (), max () - check later

    TODO:
      Test with providing subset of vector.
        sort the first half of a vector, we could modify the iterator to produce just the first half of the elements.
      min, max föstår inte (https://www.geeksforgeeks.org/c-magicians-stl-algorithms/)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main (){

  std::vector<int> v {10, 20, 5, 23, 42, 15};
  std::cout << "Vector is: "; 
  for (auto elem: v)
    std::cout << elem << " "; 

  // sort a vector
  std::cout << "\nVector after sorting is: "; 
  std::sort(v.begin(), v.end()); // the entire vector

  for (auto elem: v) // displaying a vector using range based for loop - behind the scenes, range based loop is an iterator.
    std::cout << elem << " ";

  // descending order
  std::cout << "\nVector after sorting in Descendign Order: ";
  std::reverse(v.begin(), v.end());
  for (auto elem_r: v)
    std::cout << elem_r << " ";

  // // max
  // std::cout << "\nMaximum element of vector is:  " << *max_element(v.begin(), v.end()); 

  // // min
  // std::cout << "\nMinimum element of vector is:  " << *min_element(v.begin(), v.end());
  
  // Accumulate
  std::cout << "\nThe accumulation of vector elements is: " << std::accumulate(v.begin(), v.end(), 0) << std::endl; // 0 - running sum will start at; if double then 0.0; typically 0, but we can use any number. If we use 3 then the accumulation will start from 3 onwards.

  // Copy
  std::vector<int> v2 { 4, 5, 2, 8, 0, 9, 2}; 
  std::copy(v.begin(), v.end(), std::back_inserter (v2));
  std::cout<< "\nAfter Copy: "; 
  for (auto elem: v2)
    std::cout << elem << " "; // After Copy: 4 5 2 8 0 9 2 42 23 20 15 10 5 

  std::cout << std::endl; 
  return 0;
}
