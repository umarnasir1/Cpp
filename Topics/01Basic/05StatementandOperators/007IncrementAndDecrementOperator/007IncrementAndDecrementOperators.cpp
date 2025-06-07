/*
  Increment & Decrement Operator

  Increment Operator ++
  Decrement Operator --

  Increments or decrements its operand by 1
  Can be used with integers, flating point types and pointers.

  Prefix ++num -increment counter before we use it
  Postfix num++ -increment counter after we use it

  Don't overuse this operator!
  ALERT!!! Never use it twice for the same variable in the same statement!!
*/

#include <iostream>

int main(){

  int counter {10};
  int result {0};

  // Example 1: Simple
  std::cout << "Example 1" << std::endl;
  std::cout << "Counter: " << counter << std::endl; //10

  counter = counter + 1;
  std::cout << "Counter: " << counter << std::endl; //11

  counter++;
  std::cout << "Counter: " << counter << std::endl; //12

  ++counter;
  std::cout << "Counter: " << counter << std::endl; //13

  // Example 2: pre-increment
  std::cout << "\nExample 2" << std::endl;

  counter = 10;

  std::cout << "Counter :" << counter << std::endl;//10

  result = ++counter;
  std::cout << "Counter: " << counter << std::endl;//11 
  std::cout << "Result: " << result << std::endl;//11

  // Example 3: post-increment
  std::cout << "\nExample 3" << std::endl;

  counter  = 10;
  result = 0;

  std::cout << "Counter :" << counter << std::endl;//10

  result = counter++; // post increment - increment counter after we use it so here result will be 10 as counter is 10, but counter will get incremented after counter is assigned to result.
  // result = counter
  // counter ++

  std::cout << "Counter: " << counter << std::endl;//11
  std::cout << "Result: " << result << std::endl;//10 

  // Example 4:
  std::cout << "\nExample 4" << std::endl;

  counter  = 10;
  result = 0;

  std::cout << "Counter :" << counter << std::endl;//10

  result = ++counter + 10; // pre-increment
  // counter ++
  // result = counter + 10

  std::cout << "Counter: " << counter << std::endl;//11
  std::cout << "Result: " << result << std::endl;//21

  // Example 5:
  std::cout << "\nExample 5" << std::endl;

  counter  = 10;
  result = 0;

  std::cout << "Counter :" << counter << std::endl;//10

  result = counter++ + 10; // post increment
  // result = counter + 10
  // counter ++

  std::cout << "Counter: " << counter << std::endl;//11
  std::cout << "Result: " << result << std::endl;//20

  return 0;
}
