/*
  Increment & Decrement Operator

  Increment Operator ++
  Decrement Operator --

  Increments or decrements its operand by 1
  Can be used with integers, flating point types and pointers.

  Prefix ++num
  Postfix num++

  Don't overuse this operator!
  ALERT!!! Nver use it twice for the same variable in the same statement!!
*/

#include <iostream>

using std::cout;
using std::endl;

int main(){

  int counter {10};
  int result {0};

  // Example 1: Simple
  cout << "Example 1" << endl;
  cout << "Counter: " << counter << endl;

  counter = counter + 1;
  cout << "Counter: " << counter << endl;

  counter++;
  cout << "Counter: " << counter << endl;

  ++counter;
  cout << "Counter: " << counter << endl;

  // Example 2: preincrement
  cout << "\nExample 2" << endl;

  counter  = 10;

  cout << "Counter :" << counter << endl;

  result = ++counter;
  cout << "Counter: " << counter << endl;
  cout << "Result: " << result << endl;

  // Example 3: post-increment
  cout << "\nExample 3" << endl;

  counter  = 10;
  result = 0;

  cout << "Counter :" << counter << endl;

  result = counter++; // post increment - increment counter after we use it so here result will be 10 as counter is 10, but counter will get incremented after counter is assigned to result.
  // result = counter
  // counter ++

  cout << "Counter: " << counter << endl;
  cout << "Result: " << result << endl;

  // Example 4:
  cout << "\nExample 4" << endl;

  counter  = 10;
  result = 0;

  cout << "Counter :" << counter << endl;

  result = ++counter + 10; // preincrement
  // counter ++
  // result = counter + 10

  cout << "Counter: " << counter << endl;
  cout << "Result: " << result << endl;

  // Example 5:
  cout << "\nExample 5" << endl;

  counter  = 10;
  result = 0;

  cout << "Counter :" << counter << endl;

  result = counter++ + 10; // post increment
  // result = counter + 10
  // counter ++

  cout << "Counter: " << counter << endl;
  cout << "Result: " << result << endl;

  return 0;
}
