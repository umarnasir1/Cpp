/*
Implementing the Copy constructor
Shallow copy
Deep Copy

Shallow Copy
  a simple example that demonstrate the problem
  Shallow copy - only the pointer is copied - not what is pointing to!
  problem - source and the newly created object BOTH pointing to the same data area! any class that has a raw pointer as a data member will have the same issues.

  what is happeneing with HEAP memory when using RAW pointers.
*/
#include<iostream>

using std::cout;
using std::endl;

class Shallow{
private:
  int *data; // (raw) pointer to int
public:
  void set_data_value(int d) {*data = d;} // setter
  int get_data_value() {return *data;} // getter
  void display_shallow(Shallow s);
  Shallow (int d); // constructor -
  Shallow (const Shallow &source); // copy constructor
  ~Shallow(); // Destructor
};

// Constructor
Shallow::Shallow(int d) { // expects an integer
  data = new int; // allocate storage (dynamically) for the integer and stores the passed integer d where the data pointer is pointing.
  * data = d; // de-referencing the pointer and storing that integer where data's pointing.
}

// Copy Constructor - shallow copy
Shallow::Shallow(const Shallow &source)
  : data {source.data} { // initializer list - copying the pointer not what it is pointing to -- copying the value in that data variable which is the pointer from source
    cout << "Copy constructor - shallow" << endl;
}

// Destructor
Shallow::~Shallow(){
  delete data; // free storage as we dynamically alloate storage in constructor
  cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s){ // pass object by value - making copy of it (and heres where the problem occurs)
  cout << s.get_data_value() << endl;
}
//  the source object and the newly created object both point to the same area and heap that was allocated for the data. (didnt understand fully )

// Well, the problem comes into play when we make a copy of a shallow object using the copy constructor that's doing a shallow copy. Suppose we have a function display shallow that expects a shallow object by copy. We make the copy with the copy constructor as usual, but when that local object s goes out of scope its destructor is called, and the destructor releases the storage in the heap that s is pointing to. You see the problem now. The object that was copied into this function still points to this now released storage, but it thinks that the storage is valid.

int main (){
  // will likely crash
  Shallow obj1 {100}; // integer 100  allocated on the heap and stored in it.
  // OBS!! Better to use Deep copy here rather than shallow copy
  display_shallow(obj1); // passing by value so here copy we need to make copy.
  // obj1's data has been released! - a copy of obj1 will be created inside this function. And when this function is done, the copy of the obj1 will be destroyed. Since obj1 and the copy that was just destroyed pointed to the same memory area, obj1 now points to invalid storage. If we try to access that storage from object1, our program could crash. Also when the destructor for obj1 eventually gets called it will try to release memory that's no longer valid and will probably crash.

  //obj1 pointing to data
  // s pointing to data
  // what happens when s goes out of scope? (Destructor call for s which will free the storage on the heap)
  // so freed up the memory and no longer a valid memory (as stack is cleaned)
  // and obj1 is pointing to invalid memory

  Shallow obj2 {obj1}; //program gets crash as pointing to invalid memory - as when destructor is called, it have feed up the heap and obj is pointing to invalid memory. So now if we try to make a copy of obj1 and call it obj2 again, this calls the copy constructor again. Well, we just copied it again. So now we've got two objects pointing to invalid data.
  obj2.set_data_value(1000); // changing obj1 data to 1000 as obj1 and obj2 are pointig to same data in memory
  // CRASH - now we have to unwind and free up obj1 and obj2 ccalling destructors for both

  return 0;
}
