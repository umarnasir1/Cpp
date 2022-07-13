/*
  Passing Arrays to Functions - Print a Guest list
    Print a Guest List to an even
    Clear the Guest List when the event is over
*/

#include <iostream>
#include <string>

// Function Prototype
void print_guest_list(const std::string guest_list[], size_t guest_list_size);
void clear_guest_list(std::string guest_list[], size_t guest_list_size);

int main (){

  std::string guest_list[] {"Larry", "Moe", "Curly"};
  size_t guest_list_size {3};

  print_guest_list(guest_list, guest_list_size);
  clear_guest_list(guest_list, guest_list_size);
  std::cout<< "\nPrinting gueslist after clear_guest_list()" << std::endl;
  print_guest_list(guest_list, guest_list_size);
  std::cout<< "end of program" << std::endl;

  return 0;
}

// Function Definition
void print_guest_list(const std::string guest_list[], size_t guest_list_size){
    for (size_t i{0}; i < guest_list_size; ++i)
      std::cout << guest_list[i] << std::endl;
    return;
}

void clear_guest_list(std::string guest_list[], size_t guest_list_size){
    for (size_t i{0}; i < guest_list_size; ++i)
        guest_list[i] = " ";
    return;
}
