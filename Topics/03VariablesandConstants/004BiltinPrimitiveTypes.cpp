/*
  C++ Bilt in Primitve Types
*/

#include <iostream>

using std::cout;
using std::endl;

int main (){

  /**************************************
  * Character type
  ***************************************/
  char middle_name {'N'};
  cout << "My Middle Initial is : " << middle_name << endl;

  /**************************************
  * Integer type
  ***************************************/
  unsigned short int exam_score {55}; // same as unsigned short exam_score {55};
  cout << "My exam score was " << exam_score << endl;

  int countries_represented {65};
  cout << "There were " << countries_represented << " countries represented in my meeting " <<endl;

  long people_in_florida {20610000};
  cout << "There are about " << people_in_florida << " people in Florida" << endl;

  long long peple_on_earth {7600000000};
  cout << "There are about " << peple_on_earth << " people on earth " << endl;

  long long distance_to_alpha_centauri {9461000000000};
  cout << "The distance to alpha centauri is " << distance_to_alpha_centauri << " kilometers" <<endl;

  /**************************************
  * Float type
  ***************************************/
  float car_payment {401.23};
  cout << "My car payment is " << car_payment << endl;

  double pi {3.14159};
  cout << "Pi is " << pi << endl;

  long double large_amount {2.7e120};
  cout << large_amount << " is a very big number" << endl;

  /**************************************
  * Bool type
  ***************************************/
   bool game_over {false};
   cout << "The value of gameOver is " << game_over << endl;

  return 0;
}
