/*
  Vectors
  Vector declaration and initialization
  Syntax for accessing individual vector elements. (array syntax and vector syntax)
  Chaning/Modifying vector elements - cin, assignment statement
  Method - at
  Method - size()
  Method - pushback (chaing size of a vector) - adding a new element at the end of vector - dynamic nature of vector
  Out of bounds - Exception
  2D Vector
*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main(){

  // Declaring Vectors
  std::vector <char> vowels; // create emply vector with no elements.

  // another way of vector declaration
  std::vector <char> vowels1 (5); // 5 elements, all initialized to 0

  // vector initilization
  std::vector <char> vowels2 {'a', 'e', 'i', 'o', 'u'}; // declare and initilize
  std::vector <int> test_scores {100, 98, 89, 85, 93};
  std::vector <double> hi_tempratures (365, 80.0); // 365 elements, all initialized to 80.0

  // Method 1 - Array Syntax
  // When we use the subscript operator in a vector, no bounds checking will be done. We have to do it ourself as with arrays.
  cout << "\nAccessing vector elements - array syntax" << endl;
  cout << "Test score at index 0: " << test_scores[0] << endl;
  cout << "Test score at index 1: " << test_scores[1] << endl;
  cout << "Test score at index 2: " << test_scores[2] << endl;
  cout << "Test score at index 3: " << test_scores[3] << endl;
  cout << "Test score at index 4: " << test_scores[4] << endl;

  // Method 2 -  Vector Syntax
  // object name  - name of vector - test_scores - at is the name of operation (method name)
  // 'at' method - we are asking the vector to give an element at a specific position - the value inside paranthesis.
  cout << "\nAccessing vector elements - vector syntax" << endl;
  cout << "Test score at index 0: " << test_scores.at(0) << endl;
  cout << "Test score at index 1: " << test_scores.at(1) << endl;
  cout << "Test score at index 2: " << test_scores.at(2) << endl;
  cout << "Test score at index 3: " << test_scores.at(3) << endl;
  cout << "Test score at index 4: " << test_scores.at(4) << endl;

  // Chaning/Modifying vector elements
  // using cin
  cout << "\nEnter score of 5 students" << endl;
  cin >> test_scores.at(0);
  cin >> test_scores.at(1);
  cin >> test_scores.at(2);
  cin >> test_scores.at(3);
  cin >> test_scores.at(4);

  cout << "\nModified test scores are (cin)" << endl;
  cout << "Test score at index 0: " << test_scores.at(0) << endl;
  cout << "Test score at index 1: " << test_scores.at(1) << endl;
  cout << "Test score at index 2: " << test_scores.at(2) << endl;
  cout << "Test score at index 3: " << test_scores.at(3) << endl;
  cout << "Test score at index 4: " << test_scores.at(4) << endl;

  // using assignment statement
  test_scores.at(0) = 90;
  test_scores.at(4) = 100;
  cout << "\nUpdated value after assignment statement at index 0: " << test_scores.at(0) << endl;
  cout << "\nUpdated value after assignment statement at index 4: " << test_scores.at(4) << endl;

  // Method - pushback, size (chaing size of a vector) - adding a new element at the end of vector
  // checking size
  cout << "\nThere are " << test_scores.size() << " scores in the vector before push_back" << endl;
  test_scores.push_back (80); // 80 added in the end of vector
  test_scores.push_back (90); // 90 added in the end of vector
  cout << "\nThere are " << test_scores.size() << " scores in the vector after push_back" << endl;

  // Alternative way for push_back
  cout << "\nEnter a test score to add to the vector: ";
  int score_to_add {0};
  cin >> score_to_add;
  test_scores.push_back (score_to_add);
  cout << "\nEnter one more test score to add to the vector: ";
  cin >> score_to_add;
  test_scores.push_back (score_to_add);
  cout << "\nThere are " << test_scores.size() << " scores in the vector after push_back (alternative method)" <<endl;

  // Exception1
  // What happens if we are using 'at' and we go out of bounds
  // test_scores = [ 90, 87, 67, 98, 78, 80, 90] - size = 7
  //test_scores.at(10) = 88; // we got error that terminates the program.

  // Exception2 - trying to access a value at 11
  // cout << "This should cause an exception!!" << test_scores.at(11);

  // 2D Vector - Vector of vectors
  // reviewer-rows ; movie reviews -cols
  std::vector <std::vector<int>> movie_ratings{
    {1, 2, 3, 4},
    {1, 2, 4, 4},
    {1, 3, 4, 5}
  };
  // array Syntax
  cout << "\nHere are the movie rating for reviewer #1 using array syntax :" << endl;
  cout << movie_ratings[0][0] << endl;
  cout << movie_ratings[0][1] << endl;
  cout << movie_ratings[0][2] << endl;
  cout << movie_ratings[0][3] << endl;
  // Vector Syntax
  cout << "\nHere are the movie rating for reviewer #1 using vector syntax :" << endl;
  cout << movie_ratings.at(0).at(0) << endl;
  cout << movie_ratings.at(0).at(1) << endl;
  cout << movie_ratings.at(0).at(2) << endl;
  cout << movie_ratings.at(0).at(3) << endl;

  return 0;
}
