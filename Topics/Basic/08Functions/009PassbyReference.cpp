/*
  Pass by Reference
*/

#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

// Function Prototype
void scale_number (int &num); // passing by reference
void swap (int &a, int &b);
void print (vector <int> v); // pass by value
void print1 (const vector <int> &v); // pass by reference version of above print function
void pass_by_ref1 (int &num);
void pass_by_ref2 (string &s);
void pass_by_ref3 (vector <string> &v);
void print_vector (const vector <string> &v); // const - pass by reference version of above print function

int main(){

  cout << "------------ Eg. 01 ------------------------------" << endl;
  int number {1000};
  scale_number (number);
  cout << number << endl;

  cout << "\n------------ Eg. 02 ------------------------------" << endl;
  int x{10}, y{20};
  cout << x << " " << y << endl; // 10 20
  swap (x, y); // when this function is called with x and y, a and b become aliases to x and y.
  cout << x << " " << y << endl; // 20 10

  cout << "\n------------ Eg. 03 ------------------------------" << endl;
  vector <int> data {1,2,3,4,5};
  print(data); // 1,2,3,4,5  - pass by value
  print1(data); // 1, 2, 3, 4, 5 - pass by reference - The output of this program is exactly the same as before, but we avoid the storage and copy overhead of pass by value.

  cout << "\n------------ Eg . 04 ------------------------------" << endl;
  int num {10}, another_num {20};
  cout << "num before calling pass_by_ref1: " << num << endl;
  pass_by_ref1(num);
  cout << "num after calling pass_by_ref1: " << num << endl;

  cout << "another_num before calling pass_by_ref1: " << another_num << endl;
  pass_by_ref1(another_num);
  cout << "another_num after calling pass_by_ref1: " << another_num << endl;

  string name {"Bjarne"};
  cout << "name before calling pass_by_ref2: " << name << endl;
  pass_by_ref2(name);
  cout << "name after calling pass_by_ref2: " << name << endl;

  vector <string> stooges {"Larry", "Moe", "Curly"};
  cout << "stooges before calling pass_by_ref3: ";
  print_vector(stooges);
  pass_by_ref3(stooges);
  cout << "stooges before calling pass_by_ref3: ";
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
void print(vector <int> v){
  for (auto num: v) // formal parameter v will be copy of actual parameter data
    cout << num << endl;
    return;
}

// passing a vector object - pass by reference
// the code of pass by reference would be same other than & sign.
// In order to avoid modification of vector, we can add constant.
void print1(const vector <int> &v){
//  v.at(0) = 200; // Error
  for (auto num: v) // formal parameter v will be copy of actual parameter data
    cout << num << endl;
    return;
}

void pass_by_ref1 (int &num){
  num = 1000;
  return;
}

void pass_by_ref2 (string &s){
  s = "Changed";
  return;
}

void pass_by_ref3 (vector <string> &v){  // if we dont want to change v, when we can void pass_by_ref3 (const vector <string> &v){
  v.clear(); // delete all vector elements
  return;
}

void print_vector (const vector <string> &v){ // displays vector element by element
//  v.at(0) = 500; // don't want to be able to change the vector from print function.
  for (auto s: v)
    cout << s << " ";
  cout << endl;
  return; 
}
