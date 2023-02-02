/*
  Shallow Copy
    Only the pointer is copied - not what is pointing to!
*/

#include<iostream>

class Shallow{
private:
    int *data; 
public: 
    void set_data_value(int d) {*data = d;} // setter
    int get_data_value() {return *data;} // getter
    Shallow(int d); // constructor
    Shallow(const Shallow &source); // copy constructor
    ~Shallow(); // Destructor
};

Shallow::Shallow(int d){
    data = new int; // allocate storage on HEAP
    *data = d; 
}

Shallow::Shallow(const Shallow &source)
    :data{source.data}{ // copying the pointer; not what it is pointing to. So both objects will be pointing to the same area.
    std::cout << "Copy constructor - shallow" << std::endl; 
}

Shallow::~Shallow(){
    delete data; // frees the storage
    std::cout << "Destructor freeing data" << std::endl; 
}

// function (regular function not member function)
void display_shallow(Shallow s){
    std::cout << s.get_data_value() << std::endl; 
}

int main (){
    Shallow obj1 {100};
    display_shallow(obj1); // Problem: // obj1's data has been released.
    // A copy of obj1 is created inside function and when the function is done, that copy 
    // of obj1 will be destroyed. Since obj1 and the copy that was destroyed pointed to same 
    // memory area, obj1 will now point to invalid storage. the program can crash if we try 
    // to access that storage from obj1. Also, when the destructor for object1 eventually 
    // gets called it will try to release memory that's no longer valid and will probably 
    // crash.
    
    Shallow obj2 {obj1}; // obj1 and obj2 is pointing to invalid data
    obj1.set_data_value (1000);
    
    // the program will crash when sometimes when the destructors for obj1 and obj2 are called.

    return 0; 
}