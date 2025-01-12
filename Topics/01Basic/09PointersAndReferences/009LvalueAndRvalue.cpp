/*
  L-values & R-values
*/
#include<iostream>
#include<string>

using std::string;

// Function Prototye
int square (int &n);

int main (){

  // l value
  int x {100}; // x is an l-value
  x = 1000;
  x = 1000 + 20;

  string name; // name is an l-value
  name = "Frank";

  // non l value i.e, R values
  int x1 {100}; // 100 is an r-value
  int y = x + 200; // (x+200) is an r-value since not addressable; (x+200) will produce a temporary variable


  //100 = x; // 100 is NOT a l-value; its a literal - compiler error as 100 is not an assignable l-value.
  //(1000 + 20) = x; // (1000 + 20) is NOT an l-value; this statement will produce temporary value which is not addressable

  //name = "Frank";  // "Frank" is an r-value
  //"Frank" = name;  // "Frank" is NOT an l-value; not addressable

  //int max_num = max(20,30); // max(20,30) is an r-value as it returns a result that is temporary and not addressable.

  // r-values can be assigned to l-values explicitly
  int x2 {100};
  int y2 {0};

  // y2 = 100; // r-value 100 assigned to l-value y

  //x2 = x2 + y2; // temporary  r-value (x2+y2) assigned to l-value x

  // l-value references
  int x3 {100};
  int &ref1 = x3;  // ref1 is reference to x3 (l-value) (This makes sense since ref1 are an alias for x3, and we can use ref1 on the left-hand side of an assignment statement since it refers to an l-value.)
  ref1 = 1000;

  //int &ref2 = 100; // Error 100 is an r-value - is not allowed so compiler will generate error

  // pass by reference
  int num {10};

  square(num); // OK - n is a reference to an l-value and num is an l-value
  //square(5); // Error - cant reference r-value 5 - we must reference l-value

  return 0;
}

// Function Definition
int square (int &n) { // The function expects an integer integer by reference
  return n*n;
}
