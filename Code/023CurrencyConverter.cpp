/*
  Convert € to $
  conversion factor 1.135
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (){

  const double conversion_factor {1.135};

  cout << "Welcome to € to $ Converter " << endl;
  cout << "Enter the value in €: ";

  double euros {0.0};
  double usd {0.0};

  cin >> euros;
  usd = euros * conversion_factor;

  cout << euros << "€ is equivalalent to " << usd << "$." << endl;

  return 0;
}
