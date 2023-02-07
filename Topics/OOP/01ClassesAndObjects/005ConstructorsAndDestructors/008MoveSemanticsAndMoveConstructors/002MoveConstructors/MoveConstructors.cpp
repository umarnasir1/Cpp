/*
  Move Constructor & Move Semantics

  R-value references are used by move constructor and move assignment operator to efficiently move an object rather than copy it.

  Move Constructor Syntax - R-value reference
  Type::Type(Type &&source);
  Move::Move(Move &&source);
*/
#include<iostream>
#include<vector>

class Move{
private:
  int *data; // raw Pointer
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
    std::cout << "Constructor for: " << d << std::endl;
}

// Copy Constructor - Deep Copy - Allocate storage and copy
Move::Move(const Move &source)
  :Move{*source.data}{ // delicating to the constructor using initializer list
    std::cout << "Copy constructor - deep copy for: " << *data << std::endl;
}

// Move::Move(const Move &source){
//   data = new int; // allocate storage
//   *data = *source.data; // copy the data 
// }

// Move Constructor
Move::Move(Move &&source) noexcept // 'Steal' the data and then null out the source pointer
  :data{source.data} { // copies the address of the resource from source object to the current object.- Initializer list
    // simple copy of pointer data memeber; its not copying what it is poining to (we are not doing deep copy)
    source.data = nullptr; // nulling out the pointer
    std::cout << "Move constructor - moving resource: " << *data << std::endl;
}

// Destructor
Move::~Move(){
  if (data != nullptr)
    std::cout << "Destructor freeing data for: " << *data << std::endl; // destroying objects
  else
    std::cout << "Destructor freeing data for nullptr" << std::endl; // destroying nullptr; destroying the object that we just moved (and set its data pointer to null).
  delete data;
}

int main(){

  std::vector<Move> vec; // vector of Move objects

  // Pushing back Move objects
  // vec.push_back(Move{10}); // Move{10} creating temporary unnamed Move objects as there is no varliable name (R-value)
  // vec.push_back(Move{20});
  
  // When Move Constructor Code is commented
  // Compiler is going to use the COPY CONSTRUCTOR to make copies of temporary Move objects so the vector can push them back. 
  // Thats the cause of inefficiancy (as many constructors, destructors, copy constructors are being called). Copy constructor 
  // is doing several deep copies which is quite in efficient. 

  // Constructor as we need to construct the object - temporary object - R-value
  // so copied  using copy constructor
  // 1. Constructor call; construct an object 
  // 2. Copy constructor - deep copy as we created it temporarily and needs to be copied into the vector. (as delicating constructor used so constructor will be called again)
  // 3. Destructor - destoying the copy we made/ object

  // 15 deep copies- much more than we expect. we have only 8 push_backs.
  // The vector is growing behind the scenes. As the vector grows, the objects need to be copied to a new storage. Vector is a contiguous storage, so it is making copies behind the scenes as well. A lot of times there is a log of copying going on behind the scenes that we are not aware of.

  // -------
  // Move Constructors (will make the code efficient as we are not doing a copy at all - (the fact that its r-value (temporary values), that comes to play when using move constructors)
  // Instead of making a deep copy of the move constructor 
  //    'moves' the resources on the HEAP  
  //    Simply copies the address of the resource from source to the current object
  //    And, nulls out the pointer in the source pointer. 
  
  // Pushing back Move objects
  vec.push_back(Move{10}); // Move{10} creating temporary unnamed Move objects as there is no varliable name (R-value)
  // Move constructors will be called for the temp r-values instead of copy constructors. 
  // 1. Regular Constructor call to create temporary R-value.
  // 2. Move Constructor rather than copy constructor because this is an R-value temporary.
  // 3. Destructor (are also called for nullptr, destroying the object we just moved and setting its data ptr to null)

  vec.push_back(Move{20});
  vec.push_back(Move{30});
  vec.push_back(Move{40});
  vec.push_back(Move{50});
  vec.push_back(Move{60});
  vec.push_back(Move{70});
  vec.push_back(Move{80});

  return 0;
}

// 
//  vec.push_back(Move{10});
//  vec.push_back(Move{20});

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
// Destructor freeing data for: 20
// Destructor freeing data for: 10


// Constructor for: 10
// Move constructor - moving resource: 10
// Destructor freeing data for nullptr
// Constructor for: 20
// Move constructor - moving resource: 20
// Move constructor - moving resource: 10
// Destructor freeing data for nullptr
// Destructor freeing data for nullptr
// Destructor freeing data for: 20
// Destructor freeing data for: 10

// Reason for soo many deep copies/ Moves:
// The vector is actually growing behind the scenes.
// And when the vector grows, those objects need to be copied to the new storage (as the vector is using contiguous storage. So it's making copies of the objects behind the scenes as well.).
// // --------------

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
