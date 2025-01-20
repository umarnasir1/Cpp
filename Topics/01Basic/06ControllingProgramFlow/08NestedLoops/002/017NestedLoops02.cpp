/*
  Nested Loops - Sum of the Product of all Pairs of Vector Elements

  Find the sum of the product of all pairs of vector elements.
  E.g 1, given the vector to be {1,2,3}, the possible pairs are (1,2), (1,3) and (2,3),
  so the result would be (1*2) + (1*3) + (2*3) which is 11
  E.g 2, {2, 4, 6, 8}, the possible pairs are (2,4), (2,6), (2,8), (4,6), (4,8), (6,8),
  so the result would be (2*4) + (2*6) + (2*8) + (4*6) + (4*8) + (6*8) wich is 140

  if the vector is empty or has 1 element then the result should be 0.
*/

#include <iostream>
#include <vector>

int main (){

  int result {};
  //std::vector<int> v {1, 2, 3}; // 11
  std::vector<int> v {2, 4, 6, 8}; // 140
  // std::vector<int> v {}; // 0
  // std::vector<int> v {2}; // 0

  for(size_t i{}; i < v.size(); ++i)
    for(size_t j {i+1}; j < v.size(); ++j)
      result += v.at(i) * v.at(j);

  std::cout << "Result : "<< result << std::endl;

  return 0;
}
