/*
  Using String Streams
    Reading from stringstream - extracting information from string as string, int, double
    Writing to a stringstream
    Validating input with sringstream

  We can use any stream manipulators to format that data that we are putting on the stream.
*/

#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<limits>

int main (){

  // Rreading from a stringstream
  int num {};
  double total {};
  std::string name {};

  std::string info {"Moe 100  1234.5"}; // string stream
  std::istringstream iss {info}; // (1) Declare a stringstream object; (2) Connect it to a string;

  iss >> name >> num >> total; // Extracting information - reading from string stream.
  std::cout << std::setw(10) << std::left << name
            << std::setw(5) << num
            << std::setw(10) << total << std::endl;

  std::cout << "\n-----------------------------------------------------------" << std::endl;

  // Writing to a stringstream

  std::ostringstream oss {}; // Declaring a stringstream object

  // oss << name << " " << num << " " << total; // Write to the stream object
  oss << std::setw(10) << std::left << name
      << std::setw(5) << num
      << std::setw(10) << total << std::endl;

  std::cout << oss.str() << std::endl; // The stringstream has a string buffer that it uses internally, So if we want to display that string, all we have to do is call the stringstreams.str() method.

  std::cout << "\n---- Data Validation ----------------------------------------" << std::endl;
  // Validating input with string stream.

  // --- Ex. 1
  // //   We want to be sure that they do enter an integer, not some invalid data like a name.
  // int value {};
  // std::string input {};
  //
  // std::cout << "Enter an integer: ";
  // std::cin >> input; // we read input of user into string (not int)
  //
  // std::stringstream ss {input}; // (1) Declare a stringstream object; (2) Connect it to a string;
  // if (ss >> value) // Trying to convert the string to an integer. Extract an integer from ss and store it in value
  //   std::cout << "An integer was entered"; // sucessfull extraction - we have a valid integer stored in value
  // else
  //   std::cout << "An integer was NOT entered";

  // --- Ex. 2
  // User will enter an integer - We want to be sure that they do enter an integer, not some invalid data like a name.
  // validate the type the user is entering as user can enter anyting (numbers, letters, special characters, etc.).
  int value {};
  std::string entry {};
  bool done = false; // boolean flag; setting done to false as we are not done.
  do {
    std::cout << "Please enter an ingeter: ";
    std::cin >> entry; // read the input in the string; user can enter anything they want
    std::istringstream validator {entry}; // validation; hooking string stream (validator) to entry (string)
    if (validator >> value) // extracting value(int) from the stream  - Trying to convert the string to an integer.
      done = true;
    else
      std::cout << "Sorry, that's not an integer" << std::endl;

    // discard the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // if a user will enter 12.38, it will extract 12 and print it as integer and discard .38 (ignore everyting in the stream upto new line so next time if stream is read, its clean and there is nothing left over); also, if user enter '12 Hello there', it will keep 10 and display 12 as int and discard the rest.
    // Also, if user enters non-integer value it ignores all and in the next iteration of while loop the string stream is cleared. 
  }while(!done); // keep reading it the user enter something that is valid, i.e., till done = true.

  std::cout << "You entered the ingeter: " << value << std::endl;

  std::cout << std::endl;

  return 0;
}
