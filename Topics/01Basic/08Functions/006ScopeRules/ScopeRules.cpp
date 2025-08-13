/*
  Scope Rules
    Global Variable - declared outside any class or function
    The compiler will look for variable in scope of function and if it doesnt find it will look for ouside the main() function. if the variable
      is in the block it will use that variable. 
    static - retains it value between calls so if reinitilizes, it will keep the value. 
*/

#include<iostream>

// Function Prototype
void local_example (int x);
void global_example ();
void static_local_example();
void func(int x, int y, int z);
void func1(int &x, int &y, int &z);

int num {300}; // Global Variable - declared outside any class or function

int main (){

  int num {100}, num1{500}; // local to main

  std::cout << "Local num is: " << num << " is main" << std::endl;

  { // creates a new level of sope.
    int num {200}; //local to inner block {}
    std::cout << "Local num is: " << num << " in inner block in main" << std::endl;
    std::cout << "Inner block in main can see out - num1 is: " << num1 << std::endl;
  }

  std::cout << "Local num is: " << num << " is main" << std::endl;

  local_example(10);
  local_example(20);

  global_example();
  global_example();

  static_local_example();
  static_local_example();
  static_local_example();

  // Eg. 02
  std::cout <<"\nExample 02 .........." << std::endl;
  int a {10}, b {20}, c {30};
  func(a, b, c);  
  std::cout << a << " " << b << " " << c << std::endl; // 10 20 30 as the func(a,b,c) is not returning any thing
  
  // Eg. 03
  std::cout <<"\nExample 03 .........." << std::endl;
  func1(a, b, c); 
  std::cout << a << " " << b << " " << c <<std::endl; // 20 10 30 as address was passed in func1() thats why values are updated 
  return 0;
}

// Function Definition
void local_example(int x){
  int num {1000}; // local to local Example
  std::cout << "\nLocal num is: " << num << " in local_example - start" << std::endl;
  num = x; // scope -num of local block so that is changed.
  std::cout << "Local num is: " << num << " in local_example - end" << std::endl;
  // num1 in main is not within scope - so it cant be used here.
  return;
}

void global_example (){ // the compiler will look for num in scope of function and if it doesnt find it will look for ouside the main() function
  std::cout << "\nGlobal num is: " << num << " in global_example - start" << std::endl;
  num *= 2; // will update the global
  std::cout << "Global num is: " << num << " in global_example - end" << std::endl;
  return;
}

void static_local_example(){
  static int num {5000}; // local to static_local_example static - retains it value between calls
  std::cout << "\nLocal static num is: " << num << " in static_local_example - start"<< std::endl;
  num += 1000;
  std::cout << "Local static num is: " << num << " in static_local_example - end" << std::endl;
}

void func(int x, int y, int z){
  x = y + z;
  y = 10;
  x = 20;
}

void func1(int &x, int &y, int &z){
  x = y + z;
  y = 10;
  x = 20;
}
