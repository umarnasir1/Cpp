/*
  Default Arguments - Single and Multiple default arguments

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

using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;
using std::string;

// Function Prototype
double calc_cost(double base_cost, double tax_rate = 0.06);

double calc_cost1 (double base_cost1 = 100, double tax_rate1 = 0.06, double shipping1 = 3.50);

void greeting(string name, string prefix = "Mr.", string suffix = "");

void print_grocery_list (int apples = 3, int oranges = 7, int mangos = 13);

int main (){

  // Eg. 01 single default argument
  cout << "--- Eg. 01 ------------------------------" << endl;
  double cost {};
  cost = calc_cost(200.0); // will use the default tax

  cout << fixed << setprecision(2);
  cout << "Cost is: " << cost << endl; // 212,00

  cost = calc_cost(100.0, 0.08); // will use 0.08 not the default
  cout << "Cost is: " << cost << endl; // 108,00

  // Eg. 02 Multiple default arguments.
  cout << "\n--- Eg. 02 ------------------------------" << endl;
  double cost1 {};
  cost1 = calc_cost1 (100.0, 0.08, 4.25); // will use no defaults -
  cout << "Cost is: " << cost1 << endl; // 112,25

  cost1 = calc_cost1 (100.0, 0.08); // will use default shipping
  cout << "Cost is: " << cost1 << endl; // 111,50

  cost1 = calc_cost1 (200.0); // will use default tax and shipping
  cout << "Cost is: " << cost1 << endl; // 215,50

  cost1 = calc_cost1();
  cout << "Cost is: " << cost1 << endl; // 109,50

  // Eg. 03 Multiple default arguments - Strings
  cout << "\n--- Eg. 03 ------------------------------" << endl;
  greeting("Glenn Jones", "Dr.", "M.D.");
  greeting("James Rogers", "Professor", "Ph.D");
  greeting("Frank Miller", "Dr."); // default suffix
  greeting("William Smith"); // default prefix and suffix
  greeting("Mary Howard", "Mrs.", "Ph.D");

  // Eg. 04 Multiple default arguments - Grocery List
  cout << "\n--- Eg. 04 ------------------------------" << endl;
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

void greeting(string name, string prefix, string suffix){
  cout << "Hello " << prefix + " " + name + " " + suffix << endl;
}

void print_grocery_list (int apples, int oranges, int mangos){
  cout << "Apples: " << apples << endl
       << "Oranges: " << oranges << endl
       << "Mangoes: " << mangos << endl;
}
