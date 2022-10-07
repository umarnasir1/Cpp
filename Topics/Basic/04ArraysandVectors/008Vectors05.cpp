/*
  Codility

  Distance as large as possible
  Distance between blocks numbered J and K  where J <= K = K - J +1
  Frogs can only jump up

  What is the longest distance that they can possibly create between each other, if they chose to sit on the optimal starting block initially?

  TODO - incomplete.. finish the problem 
*/

#include <iostream>
#include <vector>

int solution(std::vector<int> &blocks);

int main (){

  std::vector<int> A {2, 6, 8, 5}; // {1. 5, 5, 2, 6}, {1, 1}
  int ans = solution (A);
//  std::cout << ans << std::endl;

  return 0;
}

int solution(std::vector<int> &blocks) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> distances;

    // std::cout << j << std::endl << k << std::endl;
    // make nested loops in next step
    for (int i{}, j{}, k{}; i < blocks.size() - 1; i++)// finding optimal
      if (blocks.at(i+1) > blocks.at(i)){
        k = i+1;
        distances.push_back((k-j)+1);
      }

    // printing distances vector
    for (size_t i{}; i < distances.size(); i++)
      std::cout << "distances[" << i << "] = " << distances.at(i) << std::endl;

    return 0; //max(distances); // This is psudo code; taking out max of distances vector
}
