/*
  Using String Streams
    Reading from stringstream
    Writing to a stringstream
*/

#include<iostream>
#include<sstream>

int main (){

  // Rreading from a stringstream
  // int num {};
  // double total {};
  // std::string name {};
  // std::string info {"Moe 100  1234.5"}; // string stream
  //
  // std::istringstream iss {info}; // (1) Declare a stringstream object; (2) Connect it to a string;
  // iss >> name >> num >> total; // reading from string stream.

  // Writing to a stringstream
  int num {100};
  double total {1234.5};
  std::string name {"Moe"};

  std::ostringstream oss {}; // Declaring a stringstream object
  oss << name << " " << num << " " << total; // Write to the stream object 
  std::cout << oss.str() << std::endl;

  return 0;
}
