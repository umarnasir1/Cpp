/*
  Move Constructor & Move Semantics

  Move Constructor Syntax - R-value reference
  Type::Type(Type &&source);
  Move::Move(Move &&source);
*/
#include<iostream>
#include<vector>

using std::cout;
using std::endl;

class Move{
private:
  int *data; // raw Pointer to integer
public:
  void set_data_value(int d){*data=d;} // setter
  int get_data_value(){return *data;} // getter
  Move(int d); // Constructor
  Move(const Move &source); // Copy Constructor
  Move(Move &&source) noexcept; // Move Constructor
  ~Move(); // Destructor
};

// Constructor
Move::Move(int d){
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy Constructor - Deep Copy
Move::Move(const Move &source)
  :Move{*source.data}{ // delicating to the constructor
    cout << "Copy constructor - deep copy for: " << *data << endl;
}

// Move::Move(const Move &source){
//   data = new int; // allocate storage
//   *data = *source.data; // copy
// }

// Move Constructor
Move::Move(Move &&source) noexcept // 'Steal' the data and then null out the source pointer
  : data{source.data} { // copying the data - not copying what its pointing to
    source.data = nullptr; // nulling out the pointer
    cout << "Move constructor - moving resource: " << *data << endl;
}

// Destructor
Move::~Move(){
  if (data != nullptr)
    cout << "Destructor freeing data for: " << *data << endl; // destroying objects that we moved if data poinint to value.
  else
    cout << "Destructor freeing data for nullptr" << endl; // destroying nullptr - in case of Move constructor.
  delete data;
}

int main(){
  // // Move Semantics
  // // Difference between L-value reference and R-value reference
  // int x {100}; // x is a l-value as it is addressable and its got a name
  // int &l_ref = x; // l-value reference since x is an l-value ; l_ref is reference to x
  // l_ref = 10; // change x to 10
  //
  // // r-value
  // int &&r_ref = 200; // r-value reference since 200 is an R-value ; declared by using && operator
  // r_ref = 300; // change r_ref to 300; stores 300 into the R-value of where ref refers to so we can change that temporary variable.
  //
  // // int &&x_ref = x; // Compiler error: if we try to assign an L-value to an R-value reference
  //
  // // l-value reference parameters
  // // L-value references in the context of function parameters.
  // void func(int &num); // func expects an L-value reference as denoted by &; A
  //
  // func(x); // okay since x is an L-value and num will be the reference to an L-value.;  A - x is an l-value
  // // func(200); // Error as 200 is R-value (error: cannot bind non-cast l value reference of type 'int&' to an rvalue of type 'int')
  //
  // // R-value reference parameters
  // // R-value references in the context of function parameters.
  // void func(int &&num); // exects an R-value reference as its denoted by &&; B
  //
  // func(200); // ok since 200 is an r-value and as num is a reference to r-valueM B-200
  // // func(x); // Error since x is l-value
  //
  // // L-value and R-value reference parameters
  // // we can overload these functions and have both of them in our code at the same time since they have unique signatures.  Compiler will call the correct function depending on whether the parameter is an L-value or and R-value.
  // void func(int &num); // A
  // void func(int &&num); // B
  //
  // func(x); // calls A - x is an l -value
  // func(200); // calls B-200 is an r-value

  std::vector<Move> vec; // vector of Move objects

  // Copy Constructor
  // Inefficient Copying: Constructor will be called to copy the temps
  // pushing back move objects
  // vec.push_back(Move{10}); // Move{10} creating temporary unnamed Move objects as there is no varliable name (R-value)
  // vec.push_back(Move{20}); // Move{20} creating temporary unnamed Move objects as there is no varliable name (R-value)
  // vec.push_back(Move{30});
  // vec.push_back(Move{40});
  // vec.push_back(Move{50});
  // vec.push_back(Move{60});
  // vec.push_back(Move{70});
  // vec.push_back(Move{80});
  // All using temporary objects so they are copied using copy constructors (copy of temp) so the vector can push them back. Thats the cause of inefficiancy:

  // Constructor as we need to construct the object - temporary object - R-value
  // so copied  using copy constructor
  // 1. Constructor call; output
  // 2. copied - deligating
  // 3. Copy constructor - deep copy as we created it temporarily and needs to be copied into the vector. (as delicating constructor used so constructor will be called again)
  // 4. Destructor

  // 15 deep copies- much more than we expect. we have only 8 push_backs.
  // The vector is growing behind the scenes. As the vector grows, the objects need to be copied to a new storage. Vector is a contiguous storage, so it is making copies behind the scenes as well. A lot of times there is a log of copying going on behind the scenes that we are not aware of.


  // Move Constructor (the fact that its r-value, that comes to play when using move constructors)
  // Efficient - Move constructors will be clled for the temp r-values. more efficient as compared to deep copying.
  vec.push_back(Move{10}); // Move{10} creating temporary unnamed Move objects as there is no varliable name (R-value)

  // 1. Regular Constructor call to create temporary R-value.
  // 2. Move Constructor rather than copy constructor because this is an R-value temporary.
  // 3. Destructor

  vec.push_back(Move{20});
  vec.push_back(Move{30});
  vec.push_back(Move{40});
  vec.push_back(Move{50});
  vec.push_back(Move{60});
  vec.push_back(Move{70});
  vec.push_back(Move{80});

  // You can also see when the destructors are called for null pointer. That's destroying the object that we just moved and set its data pointer to null.

  return 0;
}


// Copy Constructor - Output: 61 lines
// Constructor for: 10
// Constructor for: 10
// Copy constructor - deep copy for: 10
// Destructor freeing data for: 10
// Constructor for: 20
// Constructor for: 20
// Copy constructor - deep copy for: 20
// Constructor for: 10
// Copy constructor - deep copy for: 10
// Destructor freeing data for: 10
// Destructor freeing data for: 20
// Constructor for: 30
// Constructor for: 30
// Copy constructor - deep copy for: 30
// Constructor for: 20
// Copy constructor - deep copy for: 20
// Constructor for: 10
// Copy constructor - deep copy for: 10
// Destructor freeing data for: 20
// Destructor freeing data for: 10
// Destructor freeing data for: 30
// Constructor for: 40
// Constructor for: 40
// Copy constructor - deep copy for: 40
// Destructor freeing data for: 40
// Constructor for: 50
// Constructor for: 50
// Copy constructor - deep copy for: 50
// Constructor for: 40
// Copy constructor - deep copy for: 40
// Constructor for: 30
// Copy constructor - deep copy for: 30
// Constructor for: 20
// Copy constructor - deep copy for: 20
// Constructor for: 10
// Copy constructor - deep copy for: 10
// Destructor freeing data for: 40
// Destructor freeing data for: 30
// Destructor freeing data for: 20
// Destructor freeing data for: 10
// Destructor freeing data for: 50
// Constructor for: 60
// Constructor for: 60
// Copy constructor - deep copy for: 60
// Destructor freeing data for: 60
// Constructor for: 70
// Constructor for: 70
// Copy constructor - deep copy for: 70
// Destructor freeing data for: 70
// Constructor for: 80
// Constructor for: 80
// Copy constructor - deep copy for: 80
// Destructor freeing data for: 80
// Destructor freeing data for: 80
// Destructor freeing data for: 70
// Destructor freeing data for: 60
// Destructor freeing data for: 50
// Destructor freeing data for: 40
// Destructor freeing data for: 30
// Destructor freeing data for: 20
// Destructor freeing data for: 10


// Move Constructor - Output: 46 lines
// Constructor for: 10
// Move constructor - moving resource: 10
// Destructor freeing data for nullptr
// Constructor for: 20
// Move constructor - moving resource: 20
// Move constructor - moving resource: 10
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Constructor for: 30
// Move constructor - moving resource: 30
// Move constructor - moving resource: 20
// Move constructor - moving resource: 10
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Constructor for: 40
// Move constructor - moving resource: 40
// Destructor freeing data for nullptr
// Constructor for: 50
// Move constructor - moving resource: 50
// Move constructor - moving resource: 40
// Move constructor - moving resource: 30
// Move constructor - moving resource: 20
// Move constructor - moving resource: 10
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Constructor for: 60
// Move constructor - moving resource: 60
// Destructor freeing data for nullptr
// Constructor for: 70
// Move constructor - moving resource: 70
// Destructor freeing data for nullptr
// Constructor for: 80
// Move constructor - moving resource: 80
// Destructor freeing data for nullptr
// Destructor freeing data for: 80
// Destructor freeing data for: 70
// Destructor freeing data for: 60
// Destructor freeing data for: 50
// Destructor freeing data for: 40
// Destructor freeing data for: 30
// Destructor freeing data for: 20
// Destructor freeing data for: 10
