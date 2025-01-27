/*
  Function Overloading

  Eg. 1: add_numbers
  In this example, We have two functions that are both called add_numbers. The first function expects two integers and the second function expects two doubles.

  Notice that when we want to add two numbers, we dont have to think about different names. We will just use the function. The compiler will check the type of the arguments in the fucntion and match it to one of the available overloaded fucntion. (If it can't match it or if it can't convert the argument to one that matches, then we get a compiler error.)
    If I call add numbers with two integers, then the int int version of the function is called.
    If I call add numbers with two doubles, then the double double version of the function is called.

  Eg. 2 display
  Things to keep in mind when using overloaded functions with default arguments.

  void display(int num = 100); // individually ok
  void display(double num = 125.5);  //individually ok
  display(); // main

  There is will be problem if we gave default arguments to both display(int) and display(double) as now compiler cant figure out which one to use and will give compiler error

  Eg. 3 Calculating Area
  a program that computes the area of two shapes, a square and a rectangle.
*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

// prototype
int add_numbers (int, int); // add ints
double add_numbers (double, double); // add doubles

void display (int num);
void display (double num);
void display (std::string s); // expects C++ string object
void display (std::string s, std::string t);
void display (std::vector <int> v);
void display (std::vector <std::string> v); // expects vector of string object

int find_area(int side_length);
double find_area(double length, double width);

int main(){

  std::cout << "------------ Eg. 01 ------------------------------" << std::endl;
  std::cout << add_numbers (10, 20) << std::endl; // integer
  std::cout << add_numbers (10.0, 20.0) << std::endl; // double

  std::cout << "\n------------ Eg. 02 ------------------------------" << std::endl;
  display(100); // 100
  display('A'); // character is always promoted to int (As there is no overloaded fucntion that expects a character), so it will display (int num) fucntion and it should print 65 which is ASCII code for 'A'.
  display(123.5); //  double
  display(123.3F); // F in the end makes it a float. As there is no overloaded fucntion that expects a foat, so float is always is promoted to double

  display("C-Style string"); // C-Style string is converted to C++ String as there is no overloaded fucntion that expects a c style string.

  std::string s {"C++ String"}; // C++ string object
  display(s); // C++ String

  display("C-Style sting", s); // First argument is converted to a C++ String; the second is already string object

  std::vector <int> test_scores {78, 87, 97, 100, 89};
  display(test_scores);

  std::vector <std::string> three_stooges {"Larry", "Moe", "Curly"};
  display(three_stooges);

  std::cout << "\n------------ Eg. 03 ------------------------------" << std::endl;
  int square_area {find_area(2)};
  double rectangle_area {find_area(4.5, 2.3)};

  std::cout << "Area of square: " << square_area << std::endl;
  std::cout << "Area of rectangle : " << rectangle_area << std::endl;

  return 0;
}

// Function Definitions
int add_numbers (int a, int b){
  return a + b;
}

double add_numbers (double a, double b){
  return a + b;
}

void display (int num){
  std::cout << "Displaying int: " << num << std::endl;
}

void display (double num){
  std::cout << "Displaying double: "<< num << std::endl;
}

void display (std::string s){
  std::cout << "Displaying string: " << s << std::endl;
}

void display (std::string s, std::string t){
  std::cout << "Displaying 2 strings: " << s << " and " << t << std::endl;
}

void display (vector <int> v){
  std::cout << "Displaying vector of Integers: ";
  for (auto i: v)
    std::cout << i << " ";
  std::cout << std::endl;
}

void display (std::vector <std::string> v){
  std::cout << "Displaying vector of strings: ";
  for (auto s: v)
    std::cout << s + " ";
  std::cout << std::endl;
}

int find_area (int side_length) {
  return pow(side_length, 2); // return side_length * side_length;
}

double find_area (double length, double width){
  return length*width;
}
