/*
  Convert € to $
  conversion factor 1.135
*/

#include <iostream>

int main (){

  const double conversion_factor {1.135};

  std::cout << "Welcome to € to $ Converter " << std::endl;
  std::cout << "Enter the value in €: ";

  double euros {0.0};
  double usd {0.0};

  std::cin >> euros;
  usd = euros * conversion_factor;

  std::cout << euros << "€ is equivalalent to " << usd << "$." << std::endl;

  return 0;
}
