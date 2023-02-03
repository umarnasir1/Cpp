/*
  Deep Copy
    both source and the newly created object each have an exact unique copy of the original heap storage.
    create new storage and copy values
    delegating constructor -Delegate to Deep (int) and pass in the int (*source.data) source is pointing to
    Difference: We are not copying the pointer, we are copying the data pointed to by the pointer.
*/
#include<iostream>

class Deep{
private:
  int *data; //raw pointer
public:
  void set_data_value(int d) {*data = d;} // setter
  int get_data_value() {return *data;} // getter
  Deep(int d); //Constructor
  Deep(const Deep &source); //Copy Constructor
  ~Deep(); //Destructor
};

Deep::Deep(int d){
  data = new int; // allocate storage on the HEAP (dynamically)
  *data = d; // stores the passed in integer d into where there data pointer is pointing.
}

// create new storage and copy values
// Deep::Deep(const Deep &source){
//   data = new int; // allocate storage
//   *data = *source.data; // copying what the source data pointer is pointing to, which is an integer into our newly created area on the heap. Now we have an exact unique copy of the original heap storage in each object.
//   std::cout << "Copy constructor - deep" << std::endl;
// }

// Deep Copy constructor - delegating constructor
// Delegate to Deep (int) and pass in the int (*source.data) source is pointing to
Deep::Deep(const Deep &source)
  : Deep{*source.data}{ // delegating to the constructor that expects an integer and the integer we are passing in is the one pointed ot by data.
    std::cout << "Copy costructor - deep" << std::endl;
}

Deep::~Deep(){
  delete data; // free storage that was allocated by the constructor
  std::cout << "Destrcutor freeing data" << std::endl;
}

// function (regular function not member function)
void display_deep(Deep s){
  std::cout << s.get_data_value() << std::endl;
  // s is a object pointing to an integer. (its using data ptr to do that). It will contain 100 as value of object passed in the function but will have a different address due to deep copy. So we've got two different areas in the heap. So each one of these is pointing to a unique area.
  // when s goes out of scope, the destructor is called and releases data from the HEAP.
  // No Problem: since the storage being release is unique to s and obj1 is still pointing to valid data.
}

int main(){
  Deep obj1 {100}; // regular constructor call - obj1 has a pointer called data, and it's pointing to an integer on the heap, that's 100 (can be seen while debugging) and it's pointing to an integer on the heap, that's 100.
  display_deep(obj1); // copy constructor will be called

  Deep obj2 {obj1}; // making obj2 a copy of obj1. Both objects contains value of 100 but their memory addresses are different.

  obj2.set_data_value(1000); // setting integer value for obj2 to 1000

  return 0;
}
