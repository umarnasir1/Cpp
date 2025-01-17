/*
  Excercie - Create a program that determines the eligibility of an individual applying for a job as a delivery driver.

  In order for the individual to be eligible, they must be 18 years of age or older,
  OR be aove the age of 15 and have their parents consent to work.
  Additionally, they must possess a valid social security number and have no driving accidents.

*/

#include <iostream>

int main(){

  int age {20};
  bool parental_consent {true}, ssn {true}, accidents {};

  if ( (age >=18 || (age > 15 && parental_consent)) && ssn && !accidents)
    std::cout << "Yes, you can work." << std::endl;

  return 0;
}
