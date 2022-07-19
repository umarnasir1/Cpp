/*
  Implementing a Recursive Function - Save a Penny
    Create a program that calculates the total_amount of money that wil be accumulated if you start with a penny and double it everyday for n number of days.

    Eg.
    Day1: $0.01
    Day2: $0.02
    Day3: $0.04
    ...
    ...
    ...
    Day16: $327.68
    Day17: $655.36
    Day18: $1310.72
*/

#include<iostream>
#include<iomanip>

// int function_activation_count {0};// Global variable

// Function Prototype
double a_penny_doubled_everyday(int days, double amount = 0.01); // check default amount

int main (){

  double total_amount{0.01};

  total_amount = a_penny_doubled_everyday(25, total_amount);

  std::cout << "If I start with a penny and doubled it every day for 25 days, I will have $ " << std::setprecision(10) << total_amount << std::endl;

  return 0;
}

// Function Definition
double a_penny_doubled_everyday(int days, double amount){
  // function_activation_count++; // global variable
  if (days==1)
    return amount; // base case
  return 2 * a_penny_doubled_everyday(--days, amount); // recursive case - return 2 * a_penny_doubled_everyday(days-1, amount);
}
