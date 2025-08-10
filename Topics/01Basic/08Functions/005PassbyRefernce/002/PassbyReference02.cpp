/*
  Using Pass by Reference - Print a Guest List
    Print a Guest List to an event
    Clear the Guest List when the event is over
*/

#include <iostream>
#include <string>

// Function Prototype
void print_guest_list(const std::string &s1, const std::string &s2, const std::string &s3);
void clear_guest_list(std::string &s1, std::string &s2, std::string &s3);

int main (){

  std::string guest_1 {"Larry"};
  std::string guest_2 {"Moe"};
  std::string guest_3 {"Curly"};

  print_guest_list(guest_1, guest_2, guest_3);
  clear_guest_list(guest_1, guest_2, guest_3);
  std::cout<< "\nPrinting gueslist after clear_guest_list()" << std::endl;
  print_guest_list(guest_1, guest_2, guest_3);
  std::cout<< "end of program" << std::endl;

  return 0;
}

// Function Definition
void print_guest_list(const std::string &s1, const std::string &s2, const std::string &s3){
  std::cout << s1 << std::endl << s2 << std::endl << s3 << std::endl;
  return;
}

void clear_guest_list(std::string &s1, std::string &s2, std::string &s3){
  s1 = s2 = s3 = " ";
  return;
}
