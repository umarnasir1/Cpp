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

int main() {

  // prints from 1 to 5
  std::cout << "Example 1\n";
  for (int i {1} ; i <= 5; i++)   // very common and have some advantages; scope of i just in for loop ; compiler error if try to use i outside loop
    std::cout << i << std::endl;

  // increment by 2 - display odd numbers
  std::cout << "\nExample 2\n";
  for (int i {1} ; i <= 10; i+=2)
    std::cout << i << std::endl;

  // count down 10 -> 1
  std::cout << "\nExample 3\n";
  for (int i {10} ; i >= 1; i--)
    std::cout << i << std::endl;

  std::cout << "\nExample 4\n";
  // display even numbers from 1-10
  for (int i {1}; i <= 10; i++)
    if (i % 2 == 0) // condition to check for even number.
      std::cout << i << std::endl;

  // count from 10 to 100 with increment of 10 & and the numbers that are only divisible by 15
  std::cout << "\nExample 5\n";
  for (int i {10} ; i <= 100; i+=10)
    if (i % 15 == 0)
      std::cout << i << std::endl;

  std::cout << "\nExample 6\n";
  // product of two numbers, both incrementing, i = 1-5,  j= 5-9
  for (int i {1}, j {5} ; i <=5 ; i++, j++)
    std::cout << i << " * " << j << " : " << (i * j) << std::endl;

  // print 1 - 100 in a table format such that each line contains 10 characters, i.e,
  // line 1 from 1 to 10, line 2 from 11 to 20 and so on.
  std::cout << "\nExample 7\n";
  for (int i{1}; i<=100; i++){
    std::cout << i;
    if ( i%10 == 0)
      std::cout << std::endl;
    else
      std::cout << " ";
  }

  // Same as Example 7 but using conditional operator
  std::cout << "\nExample 8\n";
  for (int i{1}; i<=100; i++)
    std::cout << i << ((i%10 == 0) ? "\n" : " " );

  // for loop with an array - display elements of an array
  std::cout << "\nExample 9\n";
  int scores [] {100, 90, 87};

  for (int i {0}; i <= 2; i++)
    std::cout << scores[i] << std::endl;

  // for loop with a vector - display elements of a vector.
  std::cout << "\nExample 10\n";
  std::vector<int> nums {10, 20, 30, 40, 50};

  for (unsigned int i {0}; i < nums.size() ; i++) // .size method inside vector class, tells how many items are in vector. Additionally, .size() returns unsigned int as size of vector cannot be -ve, and int i that we are declaring is signed (as int is by default signed) so we can get a warning when comparing signed and unsigned integers due to it. In order to deal with that warning we can declare our int i as unsigned int.
  //nums.size() = 5
    std::cout << nums.at(i) << std::endl;

  // sum of odd integers
  std::cout << "\nExample 11\n";
  int sum {};

  for (int i {1}; i <= 15; i++)
    if (i%2 != 0)
      sum += i;

  std::cout << "Sum is: " << sum << std::endl;

  //  sum of first 10 natural numbers.
  std::cout << "\nExample 12" << std::endl;

  int sum1{};
  for (size_t i{1}; i<=10; ++i)
    sum1 += i;
  
  std::cout << "The sum of first 10 natural numbers is : " << sum1 << std::endl;

  return 0;
}
