/*
  Codility

  TODO: add problem statement 
*/

#include <iostream>
#include <vector>
#include <numeric>

int solution(std::vector<int> &A);

int main (){

  std::vector<int> A {-6, -91, 1011, -100, 84, -22, 0, 1, 473};
  int ans = solution (A);
  std::cout << ans << std::endl;

  return 0;
}

int solution(std::vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> B;

    for (size_t i{}; i < A.size(); i++)
      //std::cout<< A.at(i) << " " << A.at(i)%4 << std::endl;
      if (A.at(i) % 4 == 0)//{
        //std::cout << A.at(i) << std::endl;
        B.push_back(A.at(i));//}

    return accumulate(B.begin(), B.end(), 0);
}
