/*
  Shallow Copy
    Only the pointer is copied - not what is pointing to!
*/
#include<iostream>

using std::cout;
using std::endl;

class Dummy{
private:
  int a,b;
public:
  void set_data_value(int val1, int val2){ a = val1; b = val2;}
  void show_data(){cout << a << " , " << b << endl;}
  Dummy(int v1=0, int v2=0); //Constructor
  Dummy(const Dummy &source); //Copy Constructor prototype
};

// Constructor
Dummy::Dummy(int v1, int v2)
  : a{v1}, b{v2}{
}

// Copy Constructor
Dummy::Dummy(const Dummy &source)
  : a{source.a}, b{source.b} { // Initializer list ot initialize source object
    // cout << "Copy Constructor - made copy of: " << source.name << endl;
}

int main(){
  Dummy d1;
  d1.show_data();
  d1.set_data_value(3,4);
  d1.show_data();
  Dummy d2{d1}; // initializing d2 to d1 - copying values of d1 to d2
  d2.show_data();
  return 0;
}
