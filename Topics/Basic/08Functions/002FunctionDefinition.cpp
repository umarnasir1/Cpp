/*
  User Defined Functions

  int function_name (int a, std::string b, ... , parameterx){     // std::string - standard string
    statement(s);
    return 0;
  }

  Function with no return type and no parameters
  void function_name () {
    statements(s);
    return; // optional
  }
*/

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

////////// Functions /////////////

const double pi {3.14159};

void say_hello () {
  cout << "Hello" << endl;
  return;
}

void say_world () {
    cout << " World" << endl;
    cout << "Bye from say_world" << endl;
    return;
}

void say_hello1 () {
  cout << "Hello";
  say_world(); // funcitons can call other functions
  cout << "Bye from say_hello" <<endl;
  return;
}

// add two numbers, if any of the number is -ve then we should return zero
int add_numbers (int a, int b){
  if ( a < 0 || b < 0)
    return 0;
  else
    return a + b;
}

double calc_area_circle (double radius){
  return pi * radius * radius;
}

double calc_volume_cylinder (double radius, double height){
//    return pi * radius * radius * height;
  return calc_area_circle(radius) * height; // reusing the calc_area_circle function - the function should be defined before it is used or it should be prototyped.
}

void area_circle(){
  double radius {};
  cout << "Enter the radius of circle: ";
  cin >> radius;

  cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
  return;
}

void volume_cylinder(){
  double radius {};
  double height {};

  cout << "Enter the radius of cylinder: ";
  cin >> radius;

  cout << "Enter the height of cylinder: ";
  cin >> height;

  cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;

  return;
}

////////// Main /////////////
int main(){

  // Eg. 01 - Calling function  1 time
  say_hello();

  // Eg. 02
  cout << "\n\nCalling the funciton 10 times in a looop\n";
  for (int i{1}; i <= 10; ++i)
    say_hello();

  // Eg. 03 Hello world
  cout << "\nEg. 03- Testing program Flow \n";
  say_hello1();
  cout << "Bye from main" << endl;

  // Eg. 04 -// add two numbers, if any of the number is -ve then we should return zero
  cout << "Apping add_numbers on 20 and 5 : " << add_numbers(20,5) << endl; // 25
  cout << "Apping add_numbers on -2 and 500 : " << add_numbers(-2,500) << endl; //0

  // Eg. 05 - Area of Circle and Volume of Cylinder
  cout << "\nEg. 04 Area of a Circle\n";
  area_circle();
  volume_cylinder();

  return 0;
}
