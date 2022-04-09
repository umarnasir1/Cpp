/*
Shallow Copy - what is happeneing with HEAP memory when using RAW pointers.
  a simple example that demonstrate the problem
  Shallow copy - only the pointer is copied - not what is pointing to (data)!
  problem occurs when dealing with raw pointers - source (in copy constructor) and the newly created object BOTH pointing to the same data area! any class that has a raw pointer as a data member will have the same issues.
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
  Shallow (int d); // constructor
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
//  the source object and the newly created object both point to the same area and heap that was allocated for the data. (didnt understand fully )

// Destructor
Shallow::~Shallow(){
  delete data; // free storage as we dynamically alloate storage in constructor
  cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s){ // pass object by value - making copy of it.
  cout << s.get_data_value() << endl;
}

int main (){
  // will likely crash at line Shallow obj2 {obj1};
  Shallow obj1 {100}; // integer 100 allocated on the HEAP and stored in it.- regular constructor call

  // OBS!! Better to use Deep copy here rather than shallow copy
  display_shallow(obj1); // passing by value so here we need to make copy.
  // A copy of obj1 (i.e., s) will be created inside this function. And when this function is done, the copy of the obj1 (i.e., s) will be destroyed/release memory. Since obj1 and the copy (s) that was just destroyed pointed to the same memory area, obj1 now points to invalid storage. If we try to access that storage from obj, our program could crash.

  // Summary
  //obj1 pointing to data
  // s pointing to data
  // after disöay_shallow(), s goes out of scope? (Destructor call for s which will free the storage on the HEAP)
  // so freed up the memory and no longer a valid memory (as HEAP is cleaned)
  // and obj1 is pointing to invalid memory

  Shallow obj2 {obj1}; //program gets crash as pointing to invalid memory - as when destructor is called, it have feed up the heap and obj is pointing to invalid memory. So now if we try to make a copy of obj1 and call it obj2 again, this calls the copy constructor again. Well, we just copied it again. So now we've got two objects pointing to invalid data. (obj1 and obj2)
  obj2.set_data_value(1000); // changing obj1 data to 1000 indirectly as obj1 and obj2 are pointig to same data in memory
  // CRASH - now we have to unwind and free up obj1 and obj2 calling destructors for both as they are both pointing to invalid data so whehn we attempt to delet it/release memory that is no longer valid, the program crashes.

  return 0;
}
