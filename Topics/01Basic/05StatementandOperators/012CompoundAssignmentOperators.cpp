/*
  Compound Assignment Operators
  LHS += RHS -> LHS = LHS + (RHS);

  a *= b + c; // a = a * (b + c);
  cost += items * tax; // cost = cost + (items * tax); - incrementing cost by product of items and tax
*/

#include <iostream>

int main(){

  int a {5};

  a += 1; // a = a + 1;
  std::cout << "a += 1: " << a << std::endl;
  a -= 2; // a = a - 2;
  std::cout << "a -= 2: " << a << std::endl;
  a *= 3; // a = a * 5;
  std::cout << "a *= 3: " << a << std::endl;
  a /= 5; // a = a / 5;
  std::cout << "a /= 5: " << a << std::endl; // a is not a float so it will be integer division
  a %= 3; // a = a % 3;
  std::cout << "a %= 3: " << a << std::endl;

  int amount {100};
  amount += amount * 2;
  std::cout << amount << std::endl;

  return 0;
}
