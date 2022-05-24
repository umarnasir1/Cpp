/*
  Challenge 2
  Automated Grader

  Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz as well as student responses for the quiz.

  The answer key is the first item in the file.
  Student1 name
  Student1 responses
  Student2 name
  Student2 responses
  . . .

  Here is a sample file.

  ABCDE
  Frank
  ABCDE
  Larry
  ABCAC
  Moe
  BBCDE
  Curly
  BBAAE
  Michael
  BBCDE

  You should read the file and display:
  Each student's name and score (#correct out of 5)
  At the end, the class average should be displayed
  You may assume that the data in the file is properly formatted

  Program should output to the console the following:
  Student                     Score
  ---------------------------------
  Frank                           5
  Larry                           3
  Moe                             4
  Curly                           2
  Michael                         4
  ---------------------------------
  Average score                 3.6


  Markus
  BDADA
  Mark
  BADEC
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
//#include<numeric>

int check_score(std::string key, std::string student_response); // function prototype

int main (){

  std::ifstream in_file {"/Volumes/Umar/Kurser/C++/Cpp/Projects/Challenges/IOAndStreams/responses.txt"};

  if(!in_file){
    std::cerr << "Error Opening File" << std::endl;
    return 1; // Exit from main()
  }

  std::cout << std::setw(15) << std::left << "Student"
            << std::setw(15) << std::right<< "Score"
            << std::endl;

  std::cout << std::setw(30)
            << std::setfill('-')
            << "" // setw() and setfill() will apply to empty string
            << std::endl; // display total_width dashes

  std::cout << std::setfill(' '); // reset setfill to blank space

  //KEY
  std::string key {}, name {}, student_response {};
  int individual_score {}, num_of_students {};
  // std::vector<double> total_score;
  double total_score {};
  std::getline(in_file, key); // curser aage chala gya hai
  // std::cout << key << std::endl;

  // if you're expecting that every input is two lines of text, just read two lines at a time
  while(std::getline(in_file, name) && std::getline(in_file, student_response)){
    individual_score = check_score(key, student_response);
    std::cout << std::setw(15) << std::left << name
              << std::setw(15) << std::right << individual_score
              << std::endl;
    num_of_students ++;
    total_score += individual_score;
    // total_score.push_back(individual_score);
  }

  std::cout << std::setw(30)
            << std::setfill('-')
            << "" // setw() and setfill() will apply to empty string
            << std::endl; // display total_width dashes

  std::cout << std::setfill(' '); // reset setfill to blank space
  std::cout << std::setprecision(1) << std::fixed; // for displaying the cost with 2 decimal digits.

  std::cout << std::setw(15) << std::left << "Average Score"
            << std::setw(15) << std::right << total_score/num_of_students// accumulate(total_score.begin(), total_score.end(),0)/total_score.size()
            << std::endl;

  std::cout << std::endl;
  in_file.close(); // closing the file

  return 0;
}

int check_score(std::string key, std::string student_response){

  int individual_score {};

  for (int i {}; i < key.length(); ++i)
    if ((key.at(i) == student_response.at(i)) == true)
      individual_score += 1;

  return individual_score;
}
