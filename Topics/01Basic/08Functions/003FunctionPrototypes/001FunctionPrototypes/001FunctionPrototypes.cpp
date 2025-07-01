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

// Function Prototype
void say_hello ();

void say_hello1 (std::string name);

double calc_area_circle (double radius);
double calc_volume_cylinder (double radius, double height);
void area_circle();
void volume_cylinder();
void func (const char *s); // C-style string

const double pi {3.14159};

int main (){

  // function call
  say_hello(); // Ok - since it matches the prototype
  //  say_hello(100); // Compiler Error - as we have entered paramenter but in prototype there is no parameter  
  //  cout << say_hello(); // Error - no return value - as function call is within output statement and the function prototype says that the function doesnt return anything

  say_hello1("Bjarne");  // passing C-style String 

  std::string my_dog {"Buster"}; // C++ Style string
  say_hello1(my_dog); // passing a variable as argument

  area_circle();
  volume_cylinder();

  func("Bjarne");

  return 0;
}

// Function Definition
void say_hello (){
  std::cout << "Hello" << std::endl;
}

void say_hello1 (std::string name){
  std::cout << "Hello " << name << std::endl;
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

void func(const char *s){
  std::cout << "The value is: " << s << std::endl; 
}
