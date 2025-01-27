/*
  Functions and Prototypes - Converting Temperatures
*/

#include<iostream>
#include<cmath>

using std::cout;

// Function prototype
double fahrenheit_to_celsius(double fahrenheit_temperature);
double fahrenheit_to_kelvin(double fahrenheit_temperature);

int main (){

  double fahrenheit_temperature {}, celsius_temperature {}, kelvin_temperature {};

  celsius_temperature = fahrenheit_to_celsius(fahrenheit_temperature);
  kelvin_temperature = fahrenheit_to_kelvin(fahrenheit_temperature);

  std::cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";

  return 0;
}

// Function Definition
double fahrenheit_to_celsius(double fahrenheit_temperature){
  return round((5.0/9.0)*(fahrenheit_temperature - 32));
}

double fahrenheit_to_kelvin(double fahrenheit_temperature){
  return round((5.0/9.0)* (fahrenheit_temperature - 32) + 273);
}
