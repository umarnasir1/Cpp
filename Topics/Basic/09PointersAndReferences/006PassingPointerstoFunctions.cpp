/*
  Passing pointers to a function
  Pass-by-reference with pointers
*/
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// Function Definition
void double_data (int *int_ptr); // expects a pointer to an integer as a parameter
void swap (int *a, int *b);
void display (const vector <string> *const v);
void display (int* array, int sentinel); // function overloading

int main(){

  // pass by reference with pointers
  // Eg1
  cout << "\nEg. 01-----------------------------------" << endl;
  int value {10};
  int *int_ptr {nullptr}; // int_ptr also parameter to the function. There are two different variables and two different scopes. int_ptr is just created to pass pointer to the function.

  // Two ways to pass same information in a function-
  cout << "Value before double_data: " << value << endl; // 10
  double_data(&value); // passing address
  cout << "Value after double_data: " << value << endl; // 20

  cout << "----------------------------------------" << endl; // another way; passing pointer
  int_ptr = &value;
  double_data(int_ptr); // passing pointer
  cout << "Value: " << value << endl;

  /*
                              Memory for a program: (before stack is cleaned - stack gets cleaned after function execution)
                              -------------------------
                              |                       |
                              |         HEAP          |
                              |      Free Storage     |
                              |                       |
                              |                       |
                              |                       |
                              -------------------------
                              |                       |
                              |                       |
                              |        Stack          |
                              | (function call stack) |
                              |                       |
                              |                       |
        double_data(1000)     |int_ptr:  1000 (memory)|local variable int_ptr
                              -------------------------
                              |                       |
                              |  Static Variables/    |
                              |  Global variables     |
                              -------------------------
                              |                       |
                  main()      |                       |
                              |int_ptr                | (2000)
                              |value 10,20 (new)      | (1000)
                              -------------------------
*/

  // Eg. 2
  cout << "\nEg. 02-----------------------------------" << endl;
  int x {100}, y {200};
  cout << "\nx: " << x << endl;
  cout << "y: " << y << endl;
  swap(&x, &y); // the values will change as references are being passed
  cout << "\nx: " << x << endl;
  cout << "y: " << y << endl;

  /*
                              Memory for a program: (before stack is cleaned - stack gets cleaned after function execution)
                              -------------------------
                              |                       |
                              |         HEAP          |
                              |      Free Storage     |
                              |                       |
                              |                       |
                              |                       |
                              -------------------------
                              |                       |
                              |                       |
                              |        Stack          |
                              | (function call stack) |
                              |temp 100               |
                              |b 2000                 | memory 2000 pointing to y
        swap(1000, 2000)      |a 1000                 | memory 1000 pointing to x
                              -------------------------
                              |                       |
                              |  Static Variables/    |
                              |  Global variables     |
                              -------------------------
                              |                       |
                  main()      |                       |
                              |y 200 ,100             | (2000)
                              |x 100, 200             | (1000)
                              -------------------------
*/
  cout << "\nEg. 03-----------------------------------" << endl;
  vector<string> stooges {"Larry", "Moe", "Curly"};
  display(&stooges); // address of first element of vector.

  cout << "---------------------------------------" << endl;
  int scores [] {100, 98, 97, 79, 85, -1};
  display(scores, -1);

  return 0;
}

// Function Definition
void double_data (int *int_ptr){
  *int_ptr *= 2; // double the contents of the data the pointer points to.
  return;
}

void swap (int *a, int *b){ // swap has three local variables a,b and temp- a,b pointers to integers, temp is int
  int temp = *a;
  *a = *b; // values swaped in main() as we are using * operator
  *b = temp; // values swaped in main() as we are using * operator
  return;
}

// As this is a display function, we dont want the funciton to modify the contents of vector, therefore, declaring v pointing to constant vector of strings (line 129). In order to avoid pointer to modify (line 133), declaring pointer as const
void display (const vector<string> *const v){ // passing pointer to vector - expects the address of vector of strings - displays string
  //(*v).at(0) = "Bjarne"; // Modifying vector's first element - const vector<string> - const will prevent this change
  //v = nullptr; // Modifying vector's first element - *const v will prevent this change
  for (auto str: *v) // *v dereferencing a vector - in order to get to what the pointer is pointing to
    cout << str << " ";
  cout << endl;
  return;
}

void display (int *array, int sentinel){
  while (*array != sentinel) // *array - dereferenccing what i am pointing to - stop when sentinel value occurs 
    cout << *array++ << " "; // dereference array, display array, increment array to the next element
  cout << endl;
}
