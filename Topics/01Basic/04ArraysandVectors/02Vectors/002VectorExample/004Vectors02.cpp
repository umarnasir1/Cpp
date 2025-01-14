/*
    Vector - Challenge

    Write a C++ program as follows:

    Declare 2 empty vectors of integers named vector1 and vector 2, respectively.
    Add 10 and 20 to vector1 dynamically using push_back
    Display the elements in vector1 using the at() method as well as its size using the size() method

    Add 100 and 200 to vector2 dynamically using push_back
    Display the elements in vector2 using the at() method as well as its size using the size() method

    Declare an empty 2D vector called vector_2d
    Remember, that a 2D vector is a vector of vector<int>

    Add vector1 to vector_2d dynamically using push_back
    Add vector2 to vector_2d dynamically using push_back

    Display the elements in vector_2d using the at() method

    Change vector1.at(0) to 1000

    Display the elements in vector_2d again using the at() method

    Display the elements in vector1

    What did you expect? Did you get what you expected? What do you think happended?
*/

#include <iostream>
#include <vector>

int main (){

  // Declare 2 empty vectors of integers named vector1 and vector 2
  std::vector <int> vector1, vector2;

  // Add 10 and 20 to vector1 dynamically using push_back
  vector1.push_back(10);
  vector1.push_back(20);

  // Display the elements in vector1 using the at() method as well as its size using the size() method
  std::cout << "Vector1" << std::endl;
  std::cout << "Element at position 0: " << vector1.at(0) << std::endl;
  std::cout << "Element at position 1: " << vector1.at(1) << std::endl;

  std::cout << "The size of the vector 1 is: " << vector1.size() << std::endl;

  // Add 100 and 200 to vector2 dynamically using push_back
  vector2.push_back(100);
  vector2.push_back(200);

  // Display the elements in vector2 using the at() method as well as its size using the size() method
  std::cout << "\nVector2" << std::endl;
  std::cout << "Element at position 0: " << vector2.at(0) << std::endl;
  std::cout << "Element at position 1: " << vector2.at(1) << std::endl;

  std::cout << "The size of the vector 2 is: " << vector2.size() << std::endl;

  // Declare an empty 2D vector called vector_2d
  std::vector <std::vector<int>> vector_2d;

  // Add vector1 to vector_2d dynamically using push_back
  vector_2d.push_back(vector1);

  // Add vector2 to vector_2d dynamically using push_back
  vector_2d.push_back(vector2);

  // vector_2d: a 2D vector that contains two vectors
  // [10  20]
  // [100 200]

  // Display the elements in vector_2d using the at() method
  std::cout << "\nVector_2D" << std::endl;
  std::cout << "Element at row 0: " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << std::endl;
  std::cout << "Element at row 1: " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << std::endl;

  // Change vector1.at(0) to 1000
  vector1.at(0) = 1000;

  // vector 2D didnt changed after this assignment- The reason for that is when elements are added/updated to vectors, a copy is actually made of what is added/insearted. In vectors of references or vectors of pointers, we can actually change what it's pointing to and it'll be reflected in the vector.
  // But when we're using integers and floats and doubles, remember, we're making copies of what we're putting into the vector.
  // Display the elements in vector_2d again using the at() method
  std::cout << "\nVector_2D" << std::endl;
  std::cout << "Element at row 0: " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << std::endl;
  std::cout << "Element at row 1: " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << std::endl;

  // Display the elements in vector1
  std::cout << "\nVector1" << std::endl;
  std::cout << "Element at position 0: " << vector1.at(0) << std::endl;
  std::cout << "Element at position 1: " << vector1.at(1) << std::endl;

  return 0;
}
