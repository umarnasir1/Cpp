/*
  This program will calculate the area of a room in square feet
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  
  cout << "Enter the width of the room: ";
  int room_width {0};
  cin >> room_width;

  cout << "Enter the length of the room: ";
  int room_length {0};
  cin >> room_length;

  cout << "The are of the room is " << room_width * room_length << " square feet" << endl;

  return 0;
}
