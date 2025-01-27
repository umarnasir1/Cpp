/*
  Function Parameters - pass in parameters by value
*/

#include<iostream>
#include<string>
#include<vector>

// Funtion Prototyp
void param_test (int formal);

void pass_by_value1(int num);
void pass_by_value2(std::string s); // expects a C++ string object
void pass_by_value3(std::vector <sstd::tring> v); // expects vector of strings object
void print_vector(std::vector <std::string> v);

int main(){
  // Eg. 01
  int actual {50};
  std::cout << "Actual Parameter before function call : " << actual << std::endl; // 50;
  param_test(actual); // pass in 50 to param_test
  std::cout << "Actual Parameter after function call : " << actual << std::endl; // 50 -did not change

  // Eg. 02
  int num {10};
  int another_num {20};

  std::cout << "num before calling pass_by_value1: " << num << std::endl;
  pass_by_value1(num);
  std::cout << "num after calling pass_by_value1: " << num << std::endl;

  std::cout << "\nanother_num before calling pass_by_value1: " << another_num << std::endl;
  pass_by_value1(another_num);
  std::cout << "another_num after calling pass_by_value1: " << another_num << std::endl;

  string name {"Bjarne"};   // C++ String object
  std::cout << "\nname before calling pass_by_value2: " << name << std::endl;
  pass_by_value2(name);
  std::cout << "name after calling pass_by_value2: " << name << std::endl;

  vector <string> stooges {"Larry", "Moe", "Curly"};  // vector of strings object
  std::cout << "\nstooges before calling pass_by_value3: ";
  print_vector(stooges);
  pass_by_value3(stooges);
  std::cout << "stooges after calling pass_by_value3: ";
  print_vector(stooges);

  return 0;
}

// Function Definition
void param_test (int formal){ // formal is a copy of actual
  std::cout << "Value of passed parameter before assignment operator : " << formal << std::endl; // 50
  formal = 100;  // only changes the local copy
  std::cout << "Value of passed parameter after assignment operator : " << formal << std::endl; // 100
  return;
}

void pass_by_value1 (int num){
  num = 1000; // local copy - and here the formal parameter will be changed.
  return;
}

void pass_by_value2 (string s){
  s = "Changed"; // this will not change the name but will change the copy 
  return;
}

void pass_by_value3(vector <string> v){
  v.clear(); // delete all vector elements
}

void print_vector(vector <string> v){ // for integer vector, it would be same void print(vector <int> v)
  for (auto s: v)
    std::cout << s << " ";
  std::cout << endl;
  return;
}
