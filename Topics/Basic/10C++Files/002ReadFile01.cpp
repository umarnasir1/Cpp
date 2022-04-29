/*
  Read a file
  Continuing from 005Vectors03.cpp in 04ArraysandVectors
  Read the board from another file, i.e., board.csv
   Write each line to cout, followed by a newline.
*/
#include<iostream>
#include<string>
#include<fstream>

int main(){

  std::string output; // string in which data will be streamed.

  // Read from a file
  std::ifstream file("/Volumes/Umar/Kurser/C++/Cpp/Topics/Basic/10C++Files/board.csv"); // Read from the csv file

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (file, output))
  // Use a while loop together with the getline() function.
  // getline() read data from an I/O stream - file into a string output
    std::cout << output << std::endl;

  return 0;
}
