/*
  Reading from a Text File

    Opening a file for reading with fstream (input and output both)
    Opening a file for reading with ifstream (only for input)
    Opening a file for reading with open

    --------------------------------------------------
    we have to be sure that the file is opened successfully -   May be it was not found or there was some sort of permission issue. Few ways to check that
        is_open()
        test the stream object

    -------------------------------------------------
    Reading from file
      using >>
        We can use extraction operator for formatted read (from text file)
        >> operator stops when they see any white space
      using getline
        We can use getline to read the file one line at a time.
        to read all the lines in a file - reading text file one line at a time
      one character at a time (get)
        reading file in a unformatted manner (i.e., one character at a time).

    ------------------------------------------------
    Closing file
      Always close any open files to flush out any unwritten data.

    -------------------------------------
    Example of Reading a file with open()
    
*/
#include<iostream>
#include<string>
#include<fsteam>

int main(){

  // Opening a file for reading with (fstream) (input and output both)

  std::fstream in_file { "../myfile.txt", std::ios::in}; // creating stream object in_file of type fstream; initializing object; using fstream class

  // Open for reading in binary model
  std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary}; // | sets both input and the binary modes to true.

  // -----------------------------------------------
  // Opening a file for reading with ifstream (only for input)
  std::ifstream in_file {"../myfile.txt", std::ios::in}; // creating ifstream object
  std::ifstream in_file {"../myfile.txt"}; // std::ios::in is optional when using ifstream as its already the default. Same effect as the previous statement.

  // Opening for reading in binary mode
  std::ifstream in_file {"../myfile.txt", std::ios::binary};  // open file in binary mode

  // -------------------------------------------------
  // Opening a file for reading with open - example below
  // Example of Reading a file with open() below
  std::ifstream in_file; // creating in_file as an ifstream; no file name to associate with it yet.
  std::string filename;
  std::cin >> filename; // get the file name (full path)

  in_file.open(filename); // or in_file.open(filename, std::ios::binary); - using open method on the stream object to open the file.

  // -------
  // 1. to be sure if the file is opened succesfully - is open
  // -------
  if (in_file.is_open()){
    // read from it
  }
  else {
    // file could not be opened
    // does it exist ?
    // should the program terminate ?
  }

  // -----
  // 2. check if file opened successfully - test the stream object
  if (in_file) { // just check the object
    // read from it
  }
  else {
    // file could not be opened
    // does not exist
    // should the program terminate ?
  }

  // ------------------------------------
  // Reading from files using (>>)
  // -------------------------------------
  // we want to read int, double and string  and a text file into our program.
  // Text file contents:
  // 100
  // 255.67
  // Larry
  std::fstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/name.txt", std::ios::in};
  int num {};
  double total {};
  std::string name {};

  // Reading from in_file using extraction operator
  in_file >> num; // read 100 and store in num
  in_file >> total >> name; // read 255.67 and store in total; then read Larry and store it in name.
  // We can have these three separate read statements on a single line OR  chain them together

  // ---------------------------------------
  // Reading from files using getline
  // ----------------------------------------
  // Text file contents:
  // This is a line
  std::fstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/name.txt", std::ios::in};
  std::string line {};
  std::getline(in_file, line); // An entire line of text up to the new line will be read from the file and stored in the string name line.


  //-------------------------------------------------
  // Reading text file one line at a time
  //-------------------------------------------------
  //  1. This program will read a text file from some file on disk and will display its contents to the console.
  std::fstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/name.txt", std::ios::in};// open file - declare in_file as fstream & connect it to name.txt
  std::string line {}; // declare line as an string object - That's where we'll store each line that we read from the text file.

  if (!in_file){//check if file is open successfully; !in_file will be true if the file was not opened successfully.
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main)/ program terminates - if we return something other than 0, our program terminates.
  }

  // otherwise we have open file and we start processing
  while (!in_file.eof()){ //eof() is a method that returns true when we reach the end of file
    std::getline(in_file, line); // read from infile and store an entire line of text into a line
    cout << line << std::endl; // display the line
  }

  in_file.close(); // close the file

  //----------------------------
  // 2. Variation of above program that does the while loop condition a bit differently
  std::fstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/name.txt", std::ios::in};// open file - declare in_file as fstream & connect it to name.txt
  std::string line {};

  if (!in_file){ // check if file is open
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main) - we return something other than zero to indicate that the program had an issue.
  }

  while (std::getline (in_file, line)) // read a line - embeding many of the string input statements right into the while condition. We can also embed statements that have the extraction operator in there. Since these statements return a reference to the stream object, they'll only return a true value when the read was successful. So when we reach the end of file or some other error condition is encountered, they will not return true, and the loop will terminate.
    cout << line << std::endl; // display the line

  in_file.close(); // close the file

  // --------------------------------
  // Reading text file one character at a time (get)
  std::fstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/name.txt", std::ios::in};// open file - declare in_file as a fsteam object but this time reading file in a unformatted manner (i.e., one character at a time).
  char c;

  if (!in_file){ // check if file is open
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main)
  }

  while (in_file.get(c)) // read a character - we are reading a single character into the variable c with the get method.
    std::cout << c; // display the character

  in_file.close(); // close the file

  // ----------------------------------------------
  // closing a file
  in_file.close();

  // ------------------------------------------------------
  // Example of open ()
  std::ifstream in_file;
  std::string filename;
  std::cin >> filename; //  /Volumes/Umar/Kurser/C++/Cpp/Topics/IntermediateAdvance/IOAndStreams/name.txt

  in_file.open(filename);

  // readline with getline
  if(!in_file){ // check if file is open
    std::cerr << "File Opening Error." << std::endl;
    return 1; // exit the program
  }

  std::string line{};
  while(getline(in_file,line))
    std::cout << line << std::endl;

  // closing the file
  in_file.close();

  return 0;
}
