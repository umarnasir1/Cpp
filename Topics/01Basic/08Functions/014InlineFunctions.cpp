/*
  Inline Functions
*/
#include<iostream>

// Function Declaration
inline int add_numbers(int a, int b);

int main (){
  int result {};
  result = add_numbers(100, 200);
  return 0;
}

// Function Definition
inline int add_numbers(int a, int b){
  return a + b;
}
