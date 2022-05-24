/*
  Read File
    Exemple with a function. 
*/

#include<iostream>
#include<fstream>
#include<string>

void read_file(std::string file_name); // Function Prototype

int main(){

  read_file("/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/name.txt");

  return 0;
}

void read_file(std::string file_name) {

    std::ifstream in_file {file_name, std::ios::in};

    if(!in_file){
        std::cerr << "Error opening file" << std::endl;
    }
    else{
        std::string word;
        while(in_file >> word){
            std::cout << word << std::endl;
        }
        in_file.close(); // closing the file
    }
}
