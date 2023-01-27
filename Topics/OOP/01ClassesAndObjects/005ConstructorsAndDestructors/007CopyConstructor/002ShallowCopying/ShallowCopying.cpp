/*
  Shallow Copy
    Only the pointer is copied - not what is pointing to!
*/

#include<iostream>

class Shallow{
private:
    int *data; 
public: 
    void set_data_value(int d) {*data = d;}
    int get_data_value() {return *data;}
    Shallow(int d); // constructor
    Shallow(const Shallow &source); // copy constructor
    ~Shallow(); // Destructor
};

Shallow::Shallow(int d){
    data = new int; // allocate storage on HEAP
    *data = d; 
}

Shallow::Shallow(const Shallow &source)
    :data{source.data}{
    std::cout << "Copy constructor - shallow" << std::endl; 
}

Shallow::~Shallow(){
    delete data; 
    std::cout << "Destructor freeing data" << std::endl; 
}

void display_shallow(Shallow s){
    std::cout << s.get_data_value() << std::endl; 
}


int main (){
    Shallow obj1 {100};
    display_shallow(obj1); // obj1's data has been released.

    Shallow obj2 {obj1};
    obj1.set_data_value (1000);

    return 0; 
}