/*
  Compound Assignment Operators
  LHS += RHS -> LHS = LHS + (RHS);

  a *= b + c; // a = a * (b + c);
  cost += items * tax; // cost = cost + (items * tax); - incrementing cost by product of items and tax
*/

#include <iostream>

using std::cout;
using std::endl;

int main(){

  int a {5};

  a += 1; // a = a + 1;
  cout << "a += 1: " << a << endl;
  a -= 2; // a = a - 2;
  cout << "a -= 2: " << a << endl;
  a *= 3; // a = a * 5;
  cout << "a *= 3: " << a << endl;
  a /= 5; // a = a / 5;
  cout << "a /= 5: " << a << endl; // a is not a float so it will be integer division
  a %= 3; // a = a % 3;
  cout << "a %= 3: " << a << endl;

  int amount {100};
  amount += amount * 2;
  cout << amount << endl;

  return 0;
}
