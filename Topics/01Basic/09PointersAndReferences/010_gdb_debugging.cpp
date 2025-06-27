/*
  Debugger

  Breakpoint - code runs till breakpoint, from there, we can go line by line, go into functions etc.
*/
#include<iostream>

// Function Prototype
void swap (int *a, int *b);

int main (){

  int i {5};
  while (i>0){
    std::cout << i << std::endl;
    i--;
  }

  int x{100}, y{200};
  std::cout << "\nx: " << x << std::endl;
  std::cout << "y: " << y << std::endl;

  swap(&x, &y);

  std::cout << "\nx: " << x << std::endl;
  std::cout << "y: " << y << std::endl;
  std::cout << std::endl;

  // cout <<"Hello World!" << endl;
  //
  // vector<int> v {1,2,3,4,5};
  //
  // for (auto i: v){
  // cout << i << endl;
  // }

  return 0;
}

// Function Definition
void swap (int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
