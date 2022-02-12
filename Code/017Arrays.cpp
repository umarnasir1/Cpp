/*
  Arrays
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

  // Array declaration & initialization

  int test_scores [5] {100, 95, 99, 87, 88};

  int high_score_per_level [10] {3, 5}; // initialize first two elements to 3,5 and remaining to 0 (if we put less initilizers)

  const int days_in_year {365};
  double hi_tempratures [days_in_year] {0}; // initilize all to zero

  int test_scores1 [5] {}; // initilize all to zero

  int another_arry [] {1,2,3,4,5}; // size automatically calculated by compiler based on the # of elements in the initializer list.

  //test_scores[0]; also called array subscripting.

  /************************************************************
  Accessing arrays elements
  *************************************************************/

  // Example:1

  // Always initialize arrays - or they will contain unknown values
  // if not initilized there can be junk values. e.g output

  // First score at index 0: 0
  // Second score at index 0: 0
  // Third score at index 0: 0
  // Fourth score at index 0: 0
  // Fifth score at index 0: -402196424

  // after initialization
  cout << "First score at index 0: " << test_scores[0] << endl;
  cout << "Second score at index 1: " << test_scores[1] << endl;
  cout << "Third score at index 2: " << test_scores[2] << endl;
  cout << "Fourth score at index 3: " << test_scores[3] << endl;
  cout << "Fifth score at index 4: " << test_scores[4] << endl;

  cout << "\nEnter 5 test scores: ";
  cin >> test_scores[0];
  cin >> test_scores[1];
  cin >> test_scores[2];
  cin >> test_scores[3];
  cin >> test_scores[4];

  cout << "First score at index 1: " << test_scores[0] << endl;
  cout << "Second score at index 2: " << test_scores[1] << endl;
  cout << "Third score at index 3: " << test_scores[2] << endl;
  cout << "Fourth score at index 4: " << test_scores[3] << endl;
  cout << "Fifth score at index 5: " << test_scores[4] << endl;  // test_scores[-1] will give warning.


  /************************************************************
  Storing Values & Changing the contents of array elements
  **************************************************************/

  // Example:2
  double hi_temps [] {90.1, 89.8, 77.5, 81.6};

  cout << "The first high temprature is now : " << hi_temps[0] << endl;

  hi_temps[0] = 100.7; // set the first element in hi_temps to 100.7

  cout << "The first high temprature is now : " <<hi_temps[0] << endl;

  return 0;
}
