/*
  Scope Rules
*/

#include<iostream>

using std::cout;
using std::endl;

// Function Prototype
void local_example (int x);
void global_example ();
void static_local_example();
void func(int x, int y, int z);
void func1(int &x, int &y, int &z);

int num {300}; // Global Variable - declared outside any class or function

int main (){

  int num {100}, num1{500}; // local to main

  cout << "Local num is: " << num << " is main" << endl;

  { // creates a new level of sope.
    int num {200}; //local to inner block {}
    cout << "Local num is: " << num << " in inner block in main" << endl;
    cout << "Inner block in main can see out - num1 is: " << num1 << endl;
  }

  cout << "Local num is: " << num << " is main" << endl;

  local_example(10);
  local_example(20);

  global_example();
  global_example();

  static_local_example();
  static_local_example();
  static_local_example();

  // Eg. 02
  cout <<"\nExample 02 .........." << endl;
  int a {10}, b {20}, c {30};
  func(a, b, c);  // 10 20 30 as the func(a,b,c) is not returning any thing
  cout << a << " " << b << " " << c << endl;
  // Eg. 03
  cout <<"\nExample 03 .........." << endl;
  func1(a, b, c); // 20 10 30 as address was passed in func1() thats why values are updated 
  cout << a << " " << b << " " << c << endl;
  return 0;
}

// Function Definition
void local_example(int x){
  int num {1000}; // local to local Example
  cout << "\nLocal num is: " << num << " in local_example - start" << endl;
  num = x;
  cout << "Local num is: " << num << " in local_example - end" << endl;
  // num1 in main is not within scope - so it cant be used here.
  return;
}

void global_example (){ // the compiler will look for num in scope of function and if it doesnt find it will look for ouside the main() function
  cout << "\nGlobal num is: " << num << " in global_example - start" << endl;
  num *= 2;
  cout << "Global num is: " << num << " in global_example - end" << endl;
  return;
}

void static_local_example(){
  static int num {5000}; // local to static_local_example static - retains it value between calls
  cout << "\nLocal static num is: " << num << " in static_local_example - start"<< endl;
  num += 1000;
  cout << "Local static num is: " << num << " in static_local_example - end" << endl;
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
