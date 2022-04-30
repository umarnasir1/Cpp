/*
  Read a file - using function.
  Continuing from 005Vectors03.cpp in 04ArraysandVectors & 002ReadFiles02.cpp in 10C++Files
  Read the board from another file, i.e., board.csv
    Write a function void ReadBoardFile which reads lines from a file. Write each line to cout, followed by a newline character "\n". The function should accept a string argument, which represents the path to the file.
*/
#include<iostream>
#include<string>
#include<fstream> // allows us to work with files.

// Function Prototype
void ReadBoardFile (std::string p); // reads in the file and prints each line to cout.

int main(){

  std::string path = "/Volumes/Umar/Kurser/C++/Cpp/Topics/Basic/10C++Files/board.csv";

  ReadBoardFile(path);

  return 0;
}


void ReadBoardFile (std::string p) {

  std::ifstream file (p); // Read from the csv file

  if (file) {
    std::string output; // Create a string in which data will be streamed.
    while(getline(file,output)) // Use a while loop together with the getline() function.
    // getline() read data from an I/O stream into a string
      std::cout << output << "\n"; // Output the text from the file
  }
  else {
    std::cout << "Stream was not created Sucessfully" << "\n";
  }

}
