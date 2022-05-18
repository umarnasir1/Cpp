/*
  Reading from a Text File
    Opening a file for reading with fstream
    Opening a file for reading with ifstream
    Opening a file for reading with open
      havent provided any file name to associate with it.
      Very common use case since many times we dont know the file name, and we have to get it from the user or from some other source at run time. Once we have the file name, we can use it and use open method on the stream object to open the file.

  Create the stream and connect it to a file.
  Read from the file - we have to be sure that the file is opened successfully -   May be it was not found or there was some sort of permission issue. Few ways to check that
      is_open()
        We can call the is open method of the file stream object that we created. This will return a boolean indicating whether the file is open for processing or not.
          true - then its OK and we can read fromt he file.
          false - something happened and we cant read from the file.
            We might then display an error message and terminate the program.
            We might see if we can somehow recreate that file from a backup.
      test the stream object
        true - we can proceed reading from the file
        false - if we couldnt open file

    Reading from file
      using >>
        We can use extraction operator for formatted read (from text file)
        same way we used it within cin
      using getline
        We can use getline to read the file one line at a time. (>> operator stops when they see any white space)
        to read all the lines in a file - reading text file one line at a time
      one character at a time (get)





    Closing file
      Always close any open files to flush out any unwritten data.


*/
#include<iostream>
#include<string>
#include<fsteam>

int main(){

  // Opening a file for reading with (fstream)

  std::fstream in_file { "../myfile.txt", std::ios::in}; // creating stream object in_file of type fstream; initializing object; using fstream class

  // Open for reading in binary model
  std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary}; // | sets both input and the binary modes to true.

  // ------
  // Opening a file for reading with ifstream
  std::ifstream in_file {"../myfile.txt", std::ios::in}; // creating ifstream object
  std::ifstream in_file {"../myfile.txt"};

  // Opening for reading in binary mode
  std::ifstream in_file {"../myfile.txt", std::ios::binary};  // open file in binary mode

  // ----
  // Opening a file for reading with open
  std::ifstream in_file; // creating in_file as an ifstream.
  std::string filename;
  std::cin >> filename; // get the file name

  in_file.open(filename); // or in_file.open(filename, std::ios::binary); - using open method on the stream object to open the file.

  // -------
  // to be sure if the file is opened succesfully - is open
  if (in_file.is_open()){
    // read from it
  }
  else {
    // file could not be opened
    // does it exist ?
    // should the program terminate ?
  }

  // -----
  // check if file opened successfully - test the stream object
  if (in_file) { // just check the object
    // read from it
  }
  else {
    // file could not be opened
    // does not exist
    // should the program terminate ?
  }

  // ------
  // Reading from files using (>>)
  // we want to read int, double and string  and a text file into our program.
  // Text file contents:
  // 100
  // 255.67
  // Larry
  int num {};
  double total {};
  std::string name {};

  // Reading from in_file using extraction operator
  in_file >> num; // read 100 and store in num
  in_file >> total >> name; // read 255.67 and store in total; then read Larry and store it in name.
  // We can have these three separate read statements on a single line OR  chain them together


  // -------
  // Reading from files using getline
  // Text file contents:
  // This is a line
  std::string line {};
  std:: getline(in_file, line); // An entire line of text up to the new line will be read from the file and stored in the string name line.

  //--------
  // Reading text file one line at a time
  //  this program will read a text file from some file on disk and will display its contents to the console.
  std::ifstream in_file{"../myfile.txt"}; // open file - declare in_file as ifstream & connect it to myfile.txt
  std::string line {}; // declare line as an string object

  if (!in_file){//check if file is open successfully; !in_file will be true if the file was not opened opened successfully.
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main)/ program terminates
  }
  while (!in_file.eof()){ // while not at the end; eof returns true when we reach the end of file
    std::getline(in_file, line); // read from infile and store an entire line of text into a line
    cout << line << std::endl; // display the line
  }
  in_file.close(); // close the file


  //-----
  // Variation of above program that does the while loop condition a bit differently
  std::ifsteam in_file{"../myfile.txt"}; // open file
  std::string line {};

  if (!in_file){ // check if file is open
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main)
  }
  while (std::getline (in_file, line)) // read a line - embeding many of the string input statements right into the while condition. We can also embed statements that have the extraction operator in there. Since these statements return a reference to the stream object, they'll only return a true value when the read was successful. So when we reach the end of file or some other error condition is encountered, they will not return true, and the loop will terminate.
    cout << line << std::endl; // display the line

  in_file.close(); // close the file

  // -------
  // Reading text file one character at a time (get)
  std::ifsteam in_file{"../myfile.txt"};  // open file -infile as a ifsteam object but this time reading file in a unformatted manner (i.e., one character at a time). Sometimes this is very useful since the extraction operator getline and other methods depend on white space or new lines to be able to work correctly. Unformatted input reads one character at a time regardless of what that character is.
  char c;

  if (!in_file){ // check if file is open
    std::cerr << "File open error" << std::endl;
    return 1; // exit the program (main)
  }
  while (in_file.get(c)) // read a character - we are reading a single character into the variable c with the get method.
    std.:cout << c; // display the character

  in_file.close(); // close the file

  // ------
  // closing a file
  in_file.close();

  return 0;
}
