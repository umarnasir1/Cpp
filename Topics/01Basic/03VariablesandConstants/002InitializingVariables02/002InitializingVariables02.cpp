/*
  This program will calculate the area of a room in square feet
*/
#include <iostream>

int main(){

  std::cout << "Enter the width of the room: ";
  int room_width {}; 
  std::cin >> room_width;

  std::cout << "Enter the length of the room: ";
  int room_length {}; 
  std::cin >> room_length;

  std::cout << "The are of the room is " << room_width * room_length << " square feet" << std::endl;

  return 0;
}
