/*
Codility

Write a function:
int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

int solution(std::vector<int> &A);

int main (){

  std::vector<int> A {1, 3, 6, 4, 1, 2};
  solution (A);

  // std::cout << "end of program" << std::endl;

  return 0;
}

int solution(std::vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    for (int i{}; i<A.size(); i++)
        if (A.at(i) >= 0)
            return 1;
        else
          return 1;
}

// TODO - NOT Complete
// int solution(vector<int> &A) {
//     vector<int> B(A.size()+1, 0); // vector len 7, init to 0
//
//     for(size_t i = 0; i < A.size(); i++)
//         B[A[i]-1] = 1;
//
//     for(size_t i=0; i < B.size(); i++)
//         if(B[i] == 0)
//             return i+1;
//
//     return 0;
// }
