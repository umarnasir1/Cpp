/*
  Functions - Built in functions

  Calling a function;
  function_name (argument);
  function_name (argument1, argument2, ...);

*/

#include <iostream>
#include <cmath>
#include <cstdlib> // rand()
#include <ctime> // time()

using std::cout;
using std::cin;
using std::endl;

int main (){

  // Calling a function
  cout << sqrt(400.0) << endl; // 20.0
  double result;
  result = pow(2.0, 3.0); // 2.0^3.0 = 8
  cout << result << endl;

  // E.g 1 - Math library
  double num {};

  cout << "Enter a number (double): ";
  cin >> num;

  cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
  cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;

  cout << "The sine of " << num << " is: " << sin(num) << endl;
  cout << "The cosine of " << num << " is: " << cos(num) << endl;

  cout << "The ceil of " << num << " is: " << ceil(num) << endl;
  cout << "The floor of " << num << " is: " << floor(num) << endl;
  cout << "The round of " << num << " is: " << round(num) << endl;

  double power {};
  cout << "\nEnter a power to raise " << num << " to: ";
  cin >> power;
  cout << num << " raised to the " << power << " power is: " << pow(num, power) << endl;

  // E.g 2 - Random numbers
  int random_number{};
  size_t count {10}; // number of random numbers to generate
  int min {1}; // lower bound (inclusive) 1-6 as we are modelling dice
  int max {6}; // uppwer bound (inclusive)

  // seed the random number generator
  // If you dont seed the generator you will get the same sequence random numbers every run

  cout << "RAND_MAX on my system is: " << RAND_MAX << endl; // rand() generates number between 0 and RAND_MAX (inclusive) so this will return the RAND_MAX of my system
  srand(time(nullptr)); // seeding the random number generator - with the system time (calling the time function and passing the null pointer which is 0)
  // rand() and srand() generates pseudorandom numbers (numbers themselves are random but the sequence that they're generated in is not.). In order to create more real random numbers, we want to seed that random number generator with a different value each time that way it creates different sequences of values.
  // if we dont seed the random number generator and comment srand(time(nullptr)); then we will get same numbers each time we run the program so we get random numbers but with same sequence as with previous run so seeding is very important .

  for (size_t i {1}; i <= count; ++i){
    random_number = rand() % max + min; // generate a random number [min, max] -
    // rand () will generate random numbers between 0 - RAND_MAX
    // rand() % max will scale the result down and return 0,1,2,3,4,5 and adding min (i.e, 1) will make range 1 -6
    cout << random_number << endl;
  }

  return 0;
}
