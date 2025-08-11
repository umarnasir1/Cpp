/*
  User Defined Functions

  int function_name (int a, std::string b, const char *s, ... , parameterx){     // std::string - standard string
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

// Function Prototype - next program
void say_hello ();
void say_world ();
void say_hello1 ();
int add_numbers (int a, int b);
double calc_area_circle (double radius);
double calc_volume_cylinder (double radius, double height);
void area_circle();
void volume_cylinder();

const double pi {3.14159};

////////// Main /////////////
int main(){

  // Eg. 01 - Calling function  1 time
  say_hello();

  // Eg. 02
  std::cout << "\n\nCalling the funciton 10 times in a looop\n";
  for (int i{1}; i <= 10; ++i)
    say_hello();

  // Eg. 03 Hello world
  std::cout << "\nEg. 03- Testing program Flow \n";
  say_hello1();
  std::cout << "Bye from main" << std::endl;

  // Eg. 04 -// add two numbers, if any of the number is -ve then we should return zero
  std::cout << "Apping add_numbers on 20 and 5 : " << add_numbers(20,5) << std::endl; // 25
  std::cout << "Apping add_numbers on -2 and 500 : " << add_numbers(-2,500) << std::endl; //0

  // Eg. 05 - Area of Circle and Volume of Cylinder
  std::cout << "\nEg. 04 Area of a Circle\n";
  area_circle();
  volume_cylinder();

  return 0;
}

////////// Functions Definition/////////////
void say_hello () {
  std::cout << "Hello" << std::endl;
  return;
}

void say_world () {
    std::cout << " World" << std::endl;
    std::cout << "Bye from say_world" << std::endl;
    return;
}

void say_hello1 () {
  std::cout << "Hello";
  say_world(); // funcitons can call other functions
  std::cout << "Bye from say_hello" << std::endl;
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
  std::cout << "Enter the radius of circle: ";
  std::cin >> radius;

  std::cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << std::endl;
  return;
}

void volume_cylinder(){
  double radius {};
  double height {};

  std::cout << "Enter the radius of cylinder: ";
  std::cin >> radius;

  std::cout << "Enter the height of cylinder: ";
  std::cin >> height;

  std::cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << std::endl;

  return;
}