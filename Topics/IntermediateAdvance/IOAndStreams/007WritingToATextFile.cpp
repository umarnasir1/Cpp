/*
  Writing to a Text File

  Opening the file for output & connecting to a file
    fstream
    ofstream
    Opening a file for writing with ofstream
      truncate (discard contents) when openeing
      append on each write
      seek to end of stream when openeing
    Opening a file for writing with open
  checking to make sure if it was oppened correctly
    is_open
    test the stream object
  Writting to the file in different ways
    Writing to files using <<
      We can use the insertion operator for formatted write
      Same way we used it with cout
    Copying a text file one line at a time
    Copying a text file one character at a time (get/put) - unformatted
      get() - read character using get
      put() - write character using put

  Closing a file
*/
#include<iostream>
#include<fstream>

int main (){

  // Opening a file for writing with (fstream)
  std::fstream out_file {"../path/myfile.txt", std::ios::out}
  //Open for writing in binary mode
  std::fstream out_file {"../path/myfile.txt", std::ios::out | std::ios::binary};

  // Opening a file for writing with ofstream
  std::ofstream out_file {"../path/myfile.txt", std::ios::out};
  std::ofstream out_file {"../path/myfile.txt"}; // std::ios::out is optional as it is default.
  std::ofstream out_file {"../path/myfile.txt", std::ios::out | std::ios::binary};

  // Opening a  file for writing with ofstream
  // truncate (discard contents) when opening
  std::ofstream out_file {"../path/myfile.txt", std::ios::trunc};

  // append on each write
  std::ofstream out_file {"../path/myfile.txt", std::ios::app};

  // seek to end of stream when oopening
  std::ofstream out_file {"../path/myfile.txt", std::ios::ate}; // we want to set the initial position of the next right to the end of the existing file.

  // Opening a file for writing with open
  // one uesed case: if file name is not known and we have to get it from the user or from some other rescourse at runtime.
  std::ofstream out_file;
  std::string filename;
  std::cin >> filename; // get the file name

  out_file.open(filename); // or out_file.open(filename, std::ios::binary);

  // -----------------
  // check if file openend sucessfully - is open
  // -----------------
  if (out_file.is_open()){
    // write to the file
  }
  else {
    // file could not be created or opened
    // does it exist ?
    // should the program terminate?
  }

  // -----------------
  // check if file openend sucessfully - test the stream object
  // -----------------
  if (out_file){ // just check the object
    // write to the file
  }
  else {
    // file could not be created or opened
    // does it exist ?
    // should the program terminate?
  }

  // -------------------------------------
  // Writing to files
  // -------------------------------------

  // Writing to files using <<
  std::ofstream out_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/samplewrite.txt"};

  int num {100};
  double total {255.67};
  std::string name {"Larry"};

  out_file << num << "\n"
           << total << "\n"
           << name << std::endl; // endl flushes out any unwritten buffers

  // ----------------------------------------
  // Copying a text file one line at a time
  // existing file is myfile.txt, and we want to copy it to another file named copy.txt.
  std::ifstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/samplewrite.txt"}; // open file
  std::ofstream out_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/copy.txt"}; // if the output file does not exist, it will be created. If it does exist, it will be truncated.

  if (!in_file){ // check if file is open
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main)
  }

  if (!out_file){ // check if file is open
    std::cerr << "File create error" << std::endl;
    return 1; // exit the program (main)
  }

  std::string line {};

  while (std::getline (in_file, line)) // read input file one line at a time into string variable line
    out_file << line << std::endl; // write a line

  // closing files
  in_file.close();
  out_file.close();
  // ----------------------------------------

  // Copying a text file one character at a time (get/put) - UnFormatted
  std::ifstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/samplewrite.txt"}; // open file
  std::ofstream out_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/copy.txt"};

  if (!in_file){ // check if file is open
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main)
  }

  if (!out_file){ // check if file is open
    std::cerr << "File create error" << std::endl;
    return 1; // exit the program (main)
  }

  char c;

  while (in_file.get(c)) // read a character - get ()
    out_file.put(c); // write the character - put()

  // close the files
  in_file.close();
  out_file.close();

  // Closing a file
  out_file.close();

  return 0;
}
