/*
  Challenge 4

  Copy Romeo and Juliet with line numbers (romeoandjuliet.txt)

  Read the file
  add line numbers
    (formatted) line numbers at begining of each line
    (formatted) line numbers only for the lines that actually have text
  Make copy and save it to another file.
*/
#include<iostream>
#include<fstream>
#include<string>
//#include<iomanip>

int main (){

  std::ifstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet.txt"};
  std::ofstream out_file1 {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet_out01.txt"};
  std::ofstream out_file2 {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet_out02.txt"};

  if(!in_file){
    std::cerr << "File not opened." << std::endl;
    return 1;
  }

  if(!out_file1){
    std::cerr << "File not opened." << std::endl;
    return 1;
  }

  if(!out_file2){
    std::cerr << "File not opened." << std::endl;
    return 1;
  }

  std::string line {};
  int line_number {};

  while (std::getline (in_file, line))
    out_file1 << std::setw(10) << std::left << ++line_number << line << std::endl;

  std::cout << "Copy Complete" << std::endl;

  // close files
  in_file.close();
  out_file1.close();
  out_file2.close(); 

  return 0;
}
