/*
  Function Prototype

  int function_name(); // prototype

  int function_name1 (int);
  // or
  int function_name1 (int a); // The compiler doesnt see the parameter name but best practice is to provide the parameter name for documentation purposes

  void function_name2 (); // A function with no return type and no parameters

  void function_name3 (int a, std::string b);
  // or
  void function_name3 (int, std::string);

  int function_name(){
    statements;
    return 0;
  }

  int function_name1 (int a){
    statement(s);
    return 0;
  }

  void function_name2 (){
    statement(s);
    return;
  }

  void function_name3 (int a, std::string b){
    statement(s);
    return;
  }

*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Function Prototype
void say_hello ();

void say_hello1 (std::string name);

double calc_area_circle (double radius);
double calc_volume_cylinder (double radius, double height);
void area_circle();
void volume_cylinder();

const double pi {3.14159};

int main (){

  // function call
  say_hello(); // Ok - since it matches the prototype
//  say_hello(100); // Compiler Error - as we have entered paramenter but in prototype there is no parameter
//   cout << say_hello(); // Error - no return value - as function call is within output statement and the function prototype says that the function doesnt return anything

  say_hello1("Bjarne");

  std::string my_dog {"Buster"};
  say_hello1(my_dog); // passing a variable as argument

  area_circle();
  volume_cylinder();

  return 0;
}

// Function Definition
void say_hello (){
  cout << "Hello" << endl;
}

void say_hello1 (std::string name){
  cout << "Hello " << name << endl;
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
