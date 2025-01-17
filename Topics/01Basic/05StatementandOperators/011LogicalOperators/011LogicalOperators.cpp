/*
  Logical Operators !, &&, || 

  num1 >= 10 && num1 < 20 (both expressions must be true for entire expression to be true)
  num1 <= 10 || num1 >= 20 (either expression or both can be true for the entire expression to be true)

  !is_raining && temperature > 32.0 (Checking if its not raining and the temperature is greater than 32 degrees Fahrenheit.)

  is_raining || is_snowing (This expression will be true if its raining or if its snowing or both)

  temperature > 100 && is_humid || is_raining (Checking to see if temperature is greater than 100 and it is humid or its raining. Here and has precedence over the or.)
*/

#include <iostream>

int main(){

  int num {};
  const int lower {10};
  const int upper {20};

  std::cout << std::boolalpha; // to display true and false instead of 1 and 0.

  // Eg. 1
  // Determine if an entered integer is between two other integers (not inclusive of bounds)
  // assume lower < upper
  // test values: 15;  out of bound - 22; 5; bound -10; 20
  std::cout << "Enter an integer - the bounds are " << lower << " and " << upper << " : ";
  std::cin >> num;

  bool within_bounds {false};

  within_bounds = (num > lower && num < upper);
  std::cout << num << " is between " << lower << " and " << upper << " : " << within_bounds << std::endl;

  // Eg. 2
  // Determine if an entered integer is outside the bounds
  // assume lower < upper
  // Test values: 25, 5; out of bound - 15; bound - 10, 20
  std::cout << "Enter an integer - the bounds are " << lower << " and " << upper << " : ";
  std::cin >> num;

  bool outside_bounds {false};

  outside_bounds = (num < lower || num > upper);
  std::cout << num << " is outside " << lower << " and " << upper << " : " << outside_bounds << std::endl;

  // Eg. 3
  // Determine if an entered integer is exactly on the boundry (10 or 20)
  // assume lower < upper
  // Test cases: on bound -10, 20; inside bound- 15; outside bound - 25, 8
  std::cout << "Enter an integer - the bounds are " << lower << " and " << upper << " : ";
  std::cin >> num;

  bool on_bounds {false};

  on_bounds = (num == lower || num == upper);
  std::cout << num << " is on one of the bounds which are " << lower << " and " << upper << " : " << on_bounds << std::endl;

  // Eg. 4
  // Determine if you need to wear a coat based on temperature and wind speed.
  bool wear_coat {false};
  double temperature {};
  int wind_speed {};

  const int wind_speed_for_coat {25}; // wind over this value requires a coat
  const double temperature_for_coat {45}; // temperature below this value require a coat

  // Require a coat if either wind is too high or temperature is too low
  std::cout << "\nEnter the current temperature in F: ";
  std::cin >> temperature;
  std::cout << "\nEnter windspeed in mph: ";
  std::cin >> wind_speed;

  wear_coat = (temperature < temperature_for_coat || wind_speed > wind_speed_for_coat);
  std::cout << "Do you need to wear a coat using OR : " << wear_coat << std::endl;

  // Require a coat if BOTH the windspeed is too high AND temperature is too low
  wear_coat = (temperature < temperature_for_coat && wind_speed > wind_speed_for_coat);
  std::cout << "Do you need to wear a coat using AND: " << wear_coat << std::endl;

  /*
    Just a really simple switch of a condition can totally change the logic really depending on what we want.
    Enter the current temperature in F: 30
    Enter windspeed in mph: 5
    Do you need to wear a coat using OR :true - because its cold (temp < 45)
    Do you need to wear a coat using AND: false - because wind speed is not that high although temperature is low - in && both conditions need to be true.
  */

  return 0;
}
