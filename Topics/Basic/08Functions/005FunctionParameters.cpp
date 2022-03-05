/*
  Function Parameters - pass in parameters by value
*/

#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// Funtion Prototyp
void param_test (int formal);

void pass_by_value1(int num);
void pass_by_value2(string s); // expects a C++ string object
void pass_by_value3(vector <string> v); // expects vector of strings object
void print_vector(vector <string> v);

int main(){
  // Eg. 01
  int actual {50};
  cout << "Actual Parameter before function call : " << actual << endl; // 50;
  param_test(actual); // pass in 50 to param_test
  cout << "Actual Parameter after function call : " << actual << endl; // 50 -did not change

  // Eg. 02
  int num {10};
  int another_num {20};

  cout << "num before calling pass_by_value1: " << num << endl;
  pass_by_value1(num);
  cout << "num after calling pass_by_value1: " << num << endl;

  cout << "\nanother_num before calling pass_by_value1: " << another_num << endl;
  pass_by_value1(another_num);
  cout << "another_num after calling pass_by_value1: " << another_num << endl;

  string name {"Bjarne"};   // C++ String object
  cout << "\nname before calling pass_by_value2: " << name << endl;
  pass_by_value2(name);
  cout << "name after calling pass_by_value2: " << name << endl;

  vector <string> stooges {"Larry", "Moe", "Curly"};  // vector of strings object
  cout << "\nstooges before calling pass_by_value3: ";
  print_vector(stooges);
  pass_by_value3(stooges);
  cout << "stooges after calling pass_by_value3: ";
  print_vector(stooges);

  return 0;
}

// Function Definition
void param_test (int formal){ // formal is a copy of actual
  cout << "Value of passed parameter before assignment operator : " << formal << endl; // 50
  formal = 100;  // only changes the local copy
  cout << "Value of passed parameter after assignment operator : " << formal << endl; // 100
  return;
}

void pass_by_value1 (int num){
  num = 1000; // local copy
  return;
}

void pass_by_value2 (string s){
  s = "Changed";
  return;
}

void pass_by_value3(vector <string> v){
  v.clear(); // delete all vector elements
}

void print_vector(vector <string> v){ // for integer vector, it would be same void print(vector <int> v)
  for (auto s: v)
    cout << s << " ";
  cout << endl;
  return;
}
