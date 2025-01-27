/*
  Default Arguments - Single and Multiple default arguments

  In case of default arguments, in case, we don't pass any values during function calling, the default value would be taken.

  Eg. No default arguments

  // prototype
  double calc_cost(double base_cost, double tax_rate);

  int main () {
    double cost {0};
    cost = calc_cost(100.0, 0.06);
    return 0;
  }

  // The function calculates the tax amount and adds that to the base costs and returns that value to the caller.
  double calc_cost (double base_cost, double tax_rate){
    return base_cost += (base_cost * tax_rate);
  }

   Eg 1 Single Default argument
  // if 96% of our customers will have 6% tax rate so we can make that as default value and only supply argument when tax rate is not 6%

  Eg.2 - Multiple default arguments
  Eg.3 - Multiple default arguments - Eg with strings
  Eg.4 - Multiple default arguments - Grocery List
    Automatically print Grocery list. Most weeks the grocery list is the same.
*/

#include<iostream>
#include<iomanip>
#include<string>

// Function Prototype
double calc_cost(double base_cost, double tax_rate = 0.06);

double calc_cost1 (double base_cost1 = 100, double tax_rate1 = 0.06, double shipping1 = 3.50);

void greeting(std::string name, std::string prefix = "Mr.", std::string suffix = "");

void print_grocery_list (int apples = 3, int oranges = 7, int mangos = 13);

int main (){

  // Eg. 01 single default argument
  std::cout << "--- Eg. 01 ------------------------------" << std::endl;
  double cost {};
  cost = calc_cost(200.0); // will use the default tax

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Cost is: " << cost << std::endl; // 212,00

  cost = calc_cost(100.0, 0.08); // will use 0.08 not the default
  std::cout << "Cost is: " << cost << std::endl; // 108,00

  // Eg. 02 Multiple default arguments.
  std::cout << "\n--- Eg. 02 ------------------------------" << std::endl;
  double cost1 {};
  cost1 = calc_cost1 (100.0, 0.08, 4.25); // will use no defaults -
  std::cout << "Cost is: " << cost1 << std::endl; // 112,25

  cost1 = calc_cost1 (100.0, 0.08); // will use default shipping
  std::cout << "Cost is: " << cost1 <<std::endl; // 111,50

  cost1 = calc_cost1 (200.0); // will use default tax and shipping
  std::cout << "Cost is: " << cost1 << std::endl; // 215,50

  cost1 = calc_cost1();
  std::cout << "Cost is: " << cost1 << std::endl; // 109,50

  // Eg. 03 Multiple default arguments - Strings
  std::cout << "\n--- Eg. 03 ------------------------------" << std::endl;
  greeting("Glenn Jones", "Dr.", "M.D.");
  greeting("James Rogers", "Professor", "Ph.D");
  greeting("Frank Miller", "Dr."); // default suffix
  greeting("William Smith"); // default prefix and suffix
  greeting("Mary Howard", "Mrs.", "Ph.D");

  // Eg. 04 Multiple default arguments - Grocery List
  std::cout << "\n--- Eg. 04 ------------------------------" << std::endl;
  print_grocery_list(); // Week 1
  print_grocery_list(5); // Week 2 - 5 apples instead of 3 and others as usual . 
  print_grocery_list(7, 11); // Week 3 - having a party and would like to serve fruit punch so 7 apples are nned and 11 oranges along with default mangos.

  return 0;
}

// Function Definitions
// The function calculates the tax amount and adds that to the base costs and returns that value to the caller.
double calc_cost (double base_cost, double tax_rate){
  return base_cost += (base_cost * tax_rate);
}

double calc_cost1 (double base_cost1, double tax_rate1, double shipping1){
  return base_cost1 += (base_cost1 * tax_rate1) + shipping1;
}

void greeting(std::string name, std::string prefix, std::string suffix){
  std::cout << "Hello " << prefix + " " + name + " " + suffix << std::endl;
}

void print_grocery_list (int apples, int oranges, int mangos){
  std::cout << "Apples: " << apples << std::endl
       << "Oranges: " << oranges << std::endl
       << "Mangoes: " << mangos << std::endl;
}
