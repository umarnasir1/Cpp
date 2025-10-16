/*
  Declaration of the function inside the class 
  Definition of the function outside the class
  Best Practice to seperate interface & implimentation
*/

#include <iostream>

class c1{ // Class definition
  private: 
    int value {}; 
  public: 
    void setvalue (int number);
    int getvalue ();
};

void c1::setvalue (int number) { // Letting the compiler know which class the function belongs via the scope resolution operator. 
  value = number; 
}

int c1::getvalue () {
  return value; 
}

int main (){
  c1 o1; 
  o1.setvalue(92);
  std::cout<< "The value is : " << o1.getvalue() << std::endl; 
}