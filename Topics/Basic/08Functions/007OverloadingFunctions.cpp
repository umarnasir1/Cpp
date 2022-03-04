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

*/
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// prototype
int add_numbers (int, int); // add ints
double add_numbers (double, double); // add doubles

void display (int num);
void display (double num);
void display (string s); // expects C++ string object
void display (string s, string t);
void display (vector <int> v);
void display (vector <string> v); // expects vector of string object

int main(){

  cout << "------------ Eg. 01 ------------------------------" << endl;
  cout << add_numbers (10, 20) << endl; // integer
  cout << add_numbers (10.0, 20.0) << endl; // double

  cout << "------------ Eg. 02 ------------------------------" << endl;
  display(100); // 100
  display('A'); // character is always promoted to int (As there is no overloaded fucntion that expects a character), so it will display (int num) fucntion and it should print 65 which is ASCII code for 'A'.
  display(123.5); //  double
  display(123.3F); // F in the end makes it a float. As there is no overloaded fucntion that expects a foat, so float is always is promoted to double

  display("C-Style string"); // C-Style string is converted to C++ String as there is no overloaded fucntion that expects a c style string.

  string s {"C++ String"}; // C++ string object
  display(s); // C++ String

  display("C-Style sting", s); // First argument is converted to a C++ String; the second is already string object

  vector <int> test_scores {78, 87, 97, 100, 89};
  display(test_scores);

  vector <string> three_stooges {"Larry", "Moe", "Curly"};
  display(three_stooges);

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
  cout << "Displaying int: " << num << endl;
}

void display (double num){
  cout << "Displaying double: "<< num << endl;
}

void display (string s){
  cout << "Displaying string: " << s << endl;
}

void display (string s, string t){
  cout << "Displaying 2 strings: " << s << " and " << t << endl;
}

void display (vector <int> v){
  cout << "Displaying vector of Integers: ";
  for (auto i: v)
    cout << i << " ";
  cout << endl;
}

void display (vector <string> v){
  cout << "Displaying vector of strings: ";
  for (auto s: v)
    cout << s + " ";
  cout << endl;
}
