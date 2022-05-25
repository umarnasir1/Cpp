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

// int word_count (std::ifstream file_name);

int main(){

  std::string word {}, total_words {};
  int total_words_count {};

  std::cout << "Enter the substring to search for: ";
  std::cin >> word;

  std::ifstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/romeoandjuliet.txt"};

  // TODO 1 - Try to make a word_count()
  while (in_file >> total_words)
    total_words_count ++;

  std::cout << total_words_count << " words were searched... " << std::endl;

  // TODO 2 - searching function


  in_file.close(); // Close file

  return 0;
}

// function definitions
// int word_count (std::ifstream file_name){
//
//   std::cout << "Test";
//   return 1;
//
// }
