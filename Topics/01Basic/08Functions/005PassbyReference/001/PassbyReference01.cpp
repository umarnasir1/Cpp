/*
  Pass by Reference
*/

#include<iostream>
#include<vector>
#include<string>

// Function Prototype
void scale_number (int &num); // passing by reference
void swap (int &a, int &b);
void print (std::vector <int> v); // pass by value
void print1 (const std::vector <int> &v); // pass by reference version of above print function
void pass_by_ref1 (int &num);
void pass_by_ref2 (std::string &s);
void pass_by_ref3 (std::vector <std::string> &v);
void print_vector (const std::vector <std::string> &v); // const - pass by reference version of above print function

int main(){

  std::cout << "------------ Eg. 01 ------------------------------" << std::endl;
  int number {1000};
  scale_number (number);
  std::cout << number << std::endl; // 100

  std::cout << "\n------------ Eg. 02 ------------------------------" << std::endl;
  int x{10}, y{20};
  std::cout << x << " " << y << std::endl; // 10 20
  swap (x, y); // when this function is called with x and y, a and b become aliases to x and y.
  std::cout << x << " " << y << std::endl; // 20 10

  std::cout << "\n------------ Eg. 03 ------------------------------" << std::endl;
  std::vector <int> data {1,2,3,4,5};
  print(data); // 1,2,3,4,5  - pass by value
  print1(data); // 1, 2, 3, 4, 5 - pass by reference - The output of this program is exactly the same as before, but we avoid the storage (as in pass by value a copy is made and in order to make a copy we need to allocate storage and copy values over) and copy overhead of pass by value.

  std::cout << "\n------------ Eg . 04 ------------------------------" << std::endl;
  int num {10}, another_num {20};
  std::cout << "num before calling pass_by_ref1: " << num << std::endl;
  pass_by_ref1(num);
  std::cout << "num after calling pass_by_ref1: " << num << std::endl;

  std::cout << "another_num before calling pass_by_ref1: " << another_num << std::endl;
  pass_by_ref1(another_num);
  std::cout << "another_num after calling pass_by_ref1: " << another_num << std::endl;

  std::string name {"Bjarne"};
  std::cout << "name before calling pass_by_ref2: " << name << std::endl;
  pass_by_ref2(name);
  std::cout << "name after calling pass_by_ref2: " << name << std::endl;

  std::vector <std::string> stooges {"Larry", "Moe", "Curly"};
  std::cout << "stooges before calling pass_by_ref3: ";
  print_vector(stooges);
  pass_by_ref3(stooges);
  std::cout << "stooges before calling pass_by_ref3: ";
  print_vector(stooges);

  return 0;
}

// Function Definition
void scale_number (int &num) {
  if (num > 100)
    num = 100;
    return;
}

// swap two numbers by passing by reference
void swap (int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
  return;
}

// passing a vector object - pass by value
void print(std::vector <int> v){
  for (auto num: v) // formal parameter v will be copy of actual parameter data
    std::cout << num << std::endl;
    return;
}

// passing a vector object - pass by reference
// the code of pass by reference would be same other than & sign.
// In order to avoid modification of vector, we can add constant.
void print1(const std::vector <int> &v){
//  v.at(0) = 200; // Error as this will change the value of vector
  for (auto num: v) // formal parameter v will be copy of actual parameter data
    std::cout << num << std::endl;
    return;
}

void pass_by_ref1 (int &num){
  num = 1000;
  return;
}

void pass_by_ref2 (std::string &s){
  s = "Changed";
  return;
}

void pass_by_ref3 (std::vector <std::string> &v){  // if we dont want to change v, when we can void pass_by_ref3 (const vector <string> &v){
  v.clear(); // delete all vector elements
  return;
}

void print_vector (const std::vector <std::string> &v){ // displays vector element by element
//  v.at(0) = 500; // don't want to be able to change the vector from print function.
  for (auto s: v)
    std::cout << s << " ";
  std::cout << std::endl;
  return;
}
