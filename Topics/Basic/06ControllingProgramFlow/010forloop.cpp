/*
  for loop

  for (initilization; condition/test; increment) //
    statement; // if statements then block {}

  order - initilization (one time); condition; execute body; increment;  condition;  execute body and so on
  ; are required but the expressions are optional and all variations can be used, e.g., for (;;), for (i=1;;)
  conditional expression evaluates to a Boolean
  initialization expression is executed exactly once before any iteraton occurs; condition is checked; if its true the body of loop is executed and then increment and loop repeats till the condition evaluates to false.
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {

  // prints from 1 to 5
  cout << "Example 1\n";
  for (int i {1} ; i <= 5; i++)   // very common and have some advantages; scope of i just in for loop ; compiler error if try to use i outside loop
    cout << i << endl;

  // increment by 2
  cout << "\nExample 2\n";
  for (int i {1} ; i <= 10; i+=2)
    cout << i << endl;

  // count down 10 -> 1
  cout << "\nExample 3\n";
  for (int i {10} ; i >= 1; i--)
    cout << i << endl;

  cout << "\nExample 4\n";
  // display even numbers from 1-10
  for (int i {1}; i <= 10; i++)
    if (i % 2 == 0) // condition to check for even number.
      cout << i << endl;

  // count from 10 to 100 with increment of 10 & and the numbers that are only divisible by 15
  cout << "\nExample 5\n";
  for (int i {10} ; i <= 100; i+=10)
    if (i % 15 == 0)
      cout << i << endl;

  cout << "\nExample 6\n";
  // product of two numbers, both incrementing, i = 1-5,  j= 5-9
  for (int i {1}, j {5} ; i <=5 ; i++, j++)
    cout << i << " * " << j << " : " << (i * j) << endl;

  // print 1 - 100 in a table format such that each line contains 10 characters, i.e,
  // line 1 from 1 to 10, line 2 from 11 to 20 and so on.
  cout << "\nExample 7\n";
  for (int i{1}; i<=100; i++){
    cout << i;
    if ( i%10 == 0)
      cout << endl;
    else
      cout << " ";
  }

  // Same as Example 7 but using conditional operator
  cout << "\nExample 8\n";
  for (int i{1}; i<=100; i++)
    cout << i << ((i%10 == 0) ? "\n" : " " );

  // for loop with an array - display elements of an array
  cout << "\nExample 9\n";
  int scores [] {100, 90, 87};

  for (int i {0}; i <= 2; i++)
    cout << scores[i] << endl;

  // for loop with a vector - display elements of a vector.
  cout << "\nExample 10\n";
  vector<int> nums {10, 20, 30, 40, 50};

  for (unsigned int i {0}; i < nums.size() ; i++) // .size method inside vector class, tells how many items are in vector. Additionally, .size() returns unsigned int as size of vector cannot be -ve, and int i that we are declaring is signed (as int is by default signed) so we can get a warning when comparing signed and unsigned integers due to it. In order to deal with that warning we can declare our int i as unsigned int.
  //nums.size() = 5
    cout << nums.at(i) << endl;

  // sum of odd integers
  cout << "\nExample 11\n";
  int sum {};

  for (int i {1}; i <= 15; i++)
    if (i%2 != 0)
      sum += i;

  cout << "Sum is: " << sum << endl;

  return 0;
}
