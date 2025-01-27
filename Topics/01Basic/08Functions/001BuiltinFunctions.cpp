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

int main (){

  // Calling a function
  std::cout << sqrt(400.0) << std::endl; // 20.0
  double result;
  result = pow(2.0, 3.0); // 2.0^3.0 = 8
  std::cout << result << std::endl;

  // E.g 1 - Math library
  double num {};

  std::cout << "Enter a number (double): ";
  std::cin >> num;

  std::cout << "The sqrt of " << num << " is: " << sqrt(num) << std::endl;
  std::cout << "The cubed root of " << num << " is: " << cbrt(num) << std::endl;

  std::cout << "The sine of " << num << " is: " << sin(num) << std::endl;
  std::cout << "The cosine of " << num << " is: " << cos(num) << std::endl;

  std::cout << "The ceil of " << num << " is: " << ceil(num) << std::endl;
  std::cout << "The floor of " << num << " is: " << floor(num) << std::endl;
  std::cout << "The round of " << num << " is: " << round(num) << std::endl;

  double power {};
  std::cout << "\nEnter a power to raise " << num << " to: ";
  std::cin >> power;
  std::cout << num << " raised to the " << power << " power is: " << pow(num, power) << std::endl;


  // E.g 2
  // In this excercise, a program is created that will be used as a POS (point of sales) system in a restaurant. The 5 guests will be splitting the bill evenly. The POS will used in three different locatioins, each with different guidelines for pricing bills.
  // At location 1, individual_bill_1 always rounds down to the nearest dollar.
  // At location 2, individual_bill_2 always rounds to the nearest dollar.
  // At location 3, individual_bill_3 always rounds up to the nearest cent.

  double bill_total {102.78};
  int number_of_guests {5};

  double individual_bill {bill_total/number_of_guests};  // 20,556

  double individual_bill_1 {floor(individual_bill)};
  double individual_bill_2 {round(individual_bill)};
  double individual_bill_3 {ceil(individual_bill*100)/100}; // rouding to nearest cent thats why * 100 and later divide the result by 100. (explanition below)

  /*
  individual: 20.556
  individual * 100: 2055.6 // cents
  ceil(individual * 100): 2056 // cents
  ceil(individual * 100)/100: 20.56 //$
  */

  cout << "The individual bill at location 1 will be $" << individual_bill_1 << "\n" << "The individual bill at location 2 will be $" << individual_bill_2 << "\n" << "The individual bill at location 3 will be $" << individual_bill_3 << endl;


  // E.g 3 - Random numbers
  int random_number{};
  size_t count {10}; // number of random numbers to generate
  int min {1}; // lower bound (inclusive) 1-6 as we are modelling dice
  int max {6}; // uppwer bound (inclusive)

  // seed the random number generator
  // If you dont seed the generator you will get the same sequence random numbers every run

  std::cout << "RAND_MAX on my system is: " << RAND_MAX << std::endl; // rand() generates number between 0 and RAND_MAX (inclusive) so this will return the RAND_MAX of my system
  srand(time(nullptr)); // seeding the random number generator - with the system time (calling the time function and passing the null pointer which is 0)
  // rand() and srand() generates pseudorandom numbers (numbers themselves are random but the sequence that they're generated in is not.). In order to create more real random numbers, we want to seed that random number generator with a different value each time that way it creates different sequences of values.
  // if we dont seed the random number generator and comment srand(time(nullptr)); then we will get same numbers each time we run the program so we get random numbers but with same sequence as with previous run so seeding is very important .

  for (size_t i {1}; i <= count; ++i){
    random_number = rand() % (max - min + 1) + min; // generate a random number [min, max]
    // rand () will generate random numbers between 0 - RAND_MAX
    // rand() % (max - min + 1) will scale the result down and return [0 - (max-min)] i.e, 0,1,2,3,4,5 and adding min (i.e, 1) will make range [1 -6]; the (max-min+1), the +1 is to couter for 0 as range will be [0 - max-1]
    std::cout << random_number << std::endl;
  }

  return 0;
}
