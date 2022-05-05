/*
  struct structureName{
    member1;
    member2;
    member3;
    ..
    memberN;
  };

  structureName instance; 
*/

#include<iostream>
#include<string>
#include<vector>

struct Students{
  std::string name {"Bjarne"};
  double gpa {2.0};
};

int main(){
   Students course1; // instance of struct- Students;  variable course1 have 2 data points

  // Assigning individually
  // course1.name = "Tom";
  // course1.gpa = 4.0;
  // std::cout << course1.name << std::endl;
  // std::cout << course1.gpa << std::endl;

  // Creating a vector
  std::vector <Students> first_period;

  first_period.push_back(course1); // pushback with default values

  // Vector now has 1 element @ index 0, so modify it.
  first_period.at(0).name = "Tom";
  first_period.at(0).gpa = 4.0;

  std::cout << first_period.at(0).name << std::endl;
  std::cout << first_period.at(0).gpa << std::endl;

  return 0;
}
