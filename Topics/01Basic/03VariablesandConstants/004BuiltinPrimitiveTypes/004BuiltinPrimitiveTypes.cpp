/*
  C++ Bilt in Primitve Types
*/

#include <iostream>

int main (){

  /**************************************
  * Character type
  ***************************************/
  char middle_name {'N'};
  std::cout << "My Middle Initial is : " << middle_name << std::endl;

  /**************************************
  * Integer type
  ***************************************/
  unsigned short int exam_score {55}; // same as unsigned short exam_score {55};
  std::cout << "My exam score was " << exam_score << std::endl;

  int countries_represented {65};
  std::cout << "There were " << countries_represented << " countries represented in my meeting " << std::endl;

  long people_in_florida {20610000};
  std::cout << "There are about " << people_in_florida << " people in Florida" << std::endl;

  long long peple_on_earth {7600000000};
  std::cout << "There are about " << peple_on_earth << " people on earth " << std::endl;

  long long distance_to_alpha_centauri {9461000000000};
  std::cout << "The distance to alpha centauri is " << distance_to_alpha_centauri << " kilometers" << std::endl;

  /**************************************
  * Float type
  ***************************************/
  float car_payment {401.23};
  std::cout << "My car payment is " << car_payment << std::endl;

  double pi {3.14159};
  std::cout << "Pi is " << pi << std::endl;

  long double large_amount {2.7e120};
  std::cout << large_amount << " is a very big number" << std::endl;

  /**************************************
  * Bool type
  ***************************************/
   bool game_over {false};
   std::cout << "The value of gameOver is " << game_over << std::endl;

  return 0;
}
