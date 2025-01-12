/*
  Debugger

  Breakpoint - code runs till breakpoint, from there, we can go line by line, go into functions etc.
*/
#include<iostream>

using std::cout;
using std::endl;
//using std::vector;

// Function Prototype
void swap (int *a, int *b);

int main (){

  int i {5};
  while (i>0){
    cout << i << endl;
    i--;
  }

  int x{100}, y{200};
  cout << "\nx: " << x << endl;
  cout << "y: " << y << endl;

  swap(&x, &y);

  cout << "\nx: " << x << endl;
  cout << "y: " << y << endl;
  cout << endl;

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
