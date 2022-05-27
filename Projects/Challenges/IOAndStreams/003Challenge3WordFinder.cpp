/*
  Challenge 3
  Word finder

  Ask the user to enter a word
  Process the Romeo and Juliet file and determine how many total words there are and how many times the word the user entered appears as a substring of a word in the play.

  For example.
  If the user enters: love
  Then the words love, lovely, and beloved will all be considered matches.
  You decide whether you want to be case sensitive or not. Solution is case sensitive

  Sample are some sample runs:

  Enter the substring to search for: love
  25919 words were searched...
  The substring love was found 171 times

  Enter the substring to search for: Romeo
  25919 words were searched...
  The substring Romeo was found 132 times

  Enter the substring to search for: Juliet
  25919 words were searched...
  The substring Juliet was found 49 times

  Enter the substring to search for: Frank
  25919 words were searched...
  The substring Frank was found 0 times
*/
#include<iostream>
#include<fstream>
#include<string>

// function prototype
bool find_substring(const std::string &word_to_find, const std::string &target);

int main(){

  std::string word_to_find {}, word_read {};
  int word_read_count {}, match_count {}; // counters

  std::ifstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet.txt"};

  if(!in_file){
    std::cerr << "Error Opening File" << std::endl;
    return 1; // Exit from main()
  }

  std::cout << "Enter the substring to search for: ";
  std::cin >> word_to_find;

  while (in_file >> word_read) { // read a word from in_file; stop at white space
      ++word_read_count;
      if (find_substring(word_to_find, word_read)) { // checking if the word that we want to search is a substring of the word read from in_file
         ++match_count; // incrementing match count
         std::cout << word_read << " "; // displaying all the strings that contain the word we are searching for.
      }
  }

  std::cout << std::endl;
  std::cout << word_read_count << " words were searched... " << std::endl;
  std::cout << "The substring " << word_to_find << " was found " << match_count << " times"<< std::endl;

  in_file.close(); // Close file

  return 0;
}

// function definition
// return true if the string word_to_find is in the target string
// pass by reference
//  alies for actual variable, i.e., no cpy is made
//  passing location of actual parameter: refereing to the acutual parameter in the function body.
// passed by reference so that code is efficient (by not making copies)
// const - so code is safe and value of variables is not changed.
bool find_substring(const std::string &word_to_find, const std::string &target) {
    std::size_t found = target.find(word_to_find); //find() will return the index; we want to know if substring exists in the target or not.
    if (found == std::string::npos) // npos - no position; so if it returns npos that means that it was not in the word.
        return false;
    else
        return true;
}
