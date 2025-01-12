/*
  Create and Write Files
  Create a file
  Write a file
  Close a file
*/
#include<iostream>
#include<fstream>

int main(){
  // Create a text file
  std::ofstream outfile ("/Volumes/Umar/Kurser/C++/Cpp/Topics/Basic/10C++Files/textfile.txt"); // instance of ofstream class

  // Write a file
  outfile << "test test test test test" << std::endl
          << "line 2" << std::endl;

  // Close the file
  outfile.close();

  std::ofstream { "Hello.txt" };
  // Hello.txt has been created here
  // The stream is destroyed right after its creation, so the stream is closed inside the destructor and thus the file is created.

  return 0;
}
