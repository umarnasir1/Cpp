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
#include<iomanip>

int main (){

  std::ifstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet.txt"};
  std::ofstream out_file1 {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet_out01.txt"}; // creating copy of the file
  std::ofstream out_file2 {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet_out02.txt"}; // creating copy of the file

  if(!in_file){ // if(!in_file.is_open())
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
  int line_number {}; // counter for line numbers at begining of each line
  int line_number_1 {};// counter for line numbers only for the lines that actually have text

  while (getline (in_file, line)){
    out_file1 << std::setw(7) << std::left << ++line_number << line << std::endl;
    // out_file2
    if (line.size() != 1) // if the line is not empty - containing the line termination thats why 1
      out_file2 << std::setw(7) << std::left << ++line_number_1 << line << std::endl;
    else
      out_file2 << std::endl; // empty line - as there is no text

    // alternate method - out_file2
    // if (line == "\r") // if the line is not empty - Unix line terminators for lines.
    //   out_file2 << std::endl; // empty line - as there is no text
    // else {
    //   out_file2 << std::setw(7) << std::left << ++line_number_1 << line << std::endl;
    // }

  } // end of while

  std::cout << "Copy Complete" << std::endl;

  // close files
  in_file.close();
  out_file1.close();
  out_file2.close();

  return 0;
}
