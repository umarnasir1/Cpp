/*
  Nested if statement

  Shipping Cost Calculator

  Ask the user for package dimension in inches
  length, width, height - these should be integers

  All dimensions must be 10 inches or less or we cannot ship it

  Base cost $2,50
  If package volume is greater than 100 cubic inches there is a 10% surcharge.
  If package volume is greater than 500 cubic inches there is a 25% surcharge.

*/

#include <iostream>
#include <iomanip> // input out manipulators

int main(){
/*
  int length {}, width {}, height {};
  double base_cost {2.5};

  const int tier1_threshold {100};
  const int tier2_threshold {500};

  int max_dimension {10}; // inch - All dimensions must be 10 inch or less or we cant ship it

  double tier1_surcharge {0.10};
  double tier2_surcharge {0.25};

  std::cout << "Welcome to the package cost calculator" << std::endl;
  std::cout << "Enter the package dimensions (length x width, height) in inches: ";
  std::cin >> length >> width  >> height;

  if (length > max_dimension || width > max_dimension || height > max_dimension)
    std::cout << "Sorry, The package cannot be shipped as the package's dimension exceeded." << std::endl;
  else {
    double package_cost {base_cost};
    int package_volume {length * width * height};
    if (package_volume > tier2_threshold){
      package_cost += package_cost * tier2_surcharge;
      std::cout << "adding tier2 surcharge" << std::endl;
    }
    else if (package_volume > tier1_threshold){
      package_cost += package_cost * tier1_surcharge;
      std::cout << "adding tier1 surcharge" << std::endl;
    }
    else
      std::cout << "No Surcharge will be charged" << std::endl;

    std::cout << std::fixed << std::setprecision(2); // precison 2 decimal
    std::cout << "The volume of your package is: " << package_volume << std::endl;
    std::cout << "Your package will cost $" << package_cost << " to ship." << std::endl;
  }*/
  return 0;
}