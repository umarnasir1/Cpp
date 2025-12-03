#include <iostream>
#include <fstream>

int main() {
    static int lineno {}; //line number; static - storage on stack
    static const char * filename {"/Users/umar/Library/CloudStorage/GoogleDrive-umar021@gmail.com/My Drive/Kurser/C++/Cpp/Topics/03Intermediate/06IOAndStreams/005ReadingFromATextFile/001/test.txt"};
    static const char * textstring {"This is the test file"};
    
    // write a file
    std::cout << "write the file:\n";
    std::ofstream ofile(filename); // std::ofstream - output file stream object for writing to a file; ofile - name 
    ofile << ++lineno << " " << textstring << '\n'; // ofile is used to write to a file (just like cout is used)
    ofile << ++lineno << " " << textstring << '\n'; // 2 This is the test file
    ofile << ++lineno << " " << textstring << '\n'; // 3 This is the test file
    ofile.close(); //closing the file 
    
    // read a file
    static char buf[128]; // for getline
    std::cout << "read the file:\n";
    std::ifstream infile(filename); // std::ifstream works like std::cin; infile - name
    while (infile.good()) { // The good() function returns true if none of the stream's error flags are set. 
        infile.getline(buf, sizeof(buf)); // reading from a file
        std::cout << buf << '\n'; // printing out 
    }
    infile.close(); //closing the file 
    
    // delete file
    std::cout << "delete file.\n";
    remove(filename); // delete the file
}


