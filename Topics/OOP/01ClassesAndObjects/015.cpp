/*
  How can we create a copy of object?
  Copy Constructor
    when an object of a class is created and is initialized by object of same class.
  Default Assignment Operator / Implicit Copy Assignment Operator
    Class_name object1;
    Class_name object2;
    object2= object1;

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
  //Copy Constructor
  Dummy(const Dummy &source); //prototype
};

// Copy Constructor
Dummy::Dummy(const Dummy &source)
  : a{source.a}, b{source.b} { // Initializer list ot initialize source object
    // cout << "Copy Constructor - made copy of: " << source.name << endl;
}

int main(){
  Dummy d1;
  d1.set_data_value(3,4);
  d1.show_data();
  Dummy d2{d1}; // initializing d2 to d1 - copying values of d1 to d2
  d2.show_data();
  return 0;
}
