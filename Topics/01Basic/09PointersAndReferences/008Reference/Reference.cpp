/*
  References
*/
#include<iostream>
#include<vector>
#include<string>

int main(){

  // References are often used in range-based for loops to access collection elements inside each iteration.
  // str -copies
  // &str - alias
  std::cout << "Ex. 01 ------------------------------------------" << std::endl;
  std::vector<std::string> stooges {"Larry", "Moe", "Curly"};

  for (auto str: stooges)
    str = "Funny"; // changes the copy as str is a copy for each of the vector elements as we loop through them so copy is beign set to funny.  making a copy could be pretty expensive (in some user defined data type - couple of hundred 1000bytes for eg).

  for (auto str: stooges)
    std::cout << str << std::endl; // Larry, Moe, Curly

/*
  // -----------------------
  for (auto const &str: stooges)
    str = "Funny"; // compiler error -  we're preventing any change to the data in the vector because the compiler marks it as read-only - but this is not what we want here as we want to modify the vector. but const can be used when we dont want to change vector elements.

  //It makes sense to use the const qualifier for the reference str in the loop when we're displaying the vector elements. So any attempt to change them would probably be a mistake so we can have the compiler help us out by making the reference const. CONST is best to use if we aren't going to modify the collection elements,
  for (auto const &str: stooges)
    std::cout << str << std::endl;
*/

  // -----------------------
  // Using references in to change the vector elements.
  std::cout << "\n------------------------------------------" << std::endl;
  for (auto &str: stooges) // str is a reference to each vector element  i.e., it is an alias for each of these vector elements
    str = "Funny"; // changes the actual

  for (auto const &str: stooges) // using const - to change of elements
    std::cout << str << std::endl; // Funny, Funny, Funny


  // -----------------------
  std::cout << "\nEg. 02------------------------------------------" << std::endl;
  int num {100};
  int &ref {num}; // ref is an alias to num

  std::cout << num << std::endl; // 100
  std::cout << ref << std::endl; // 100

  num = 200;
  std::cout << "\n------------------------------------------" << std::endl;
  std::cout << num << std::endl; // 200
  std::cout << ref << std::endl; // 200

  ref = 300; // changing num through reference
  std::cout << "\n-------------------------------------------" << std::endl;
  std::cout << num << std::endl; // 300
  std::cout << ref << std::endl; // 300

  return 0;
}
