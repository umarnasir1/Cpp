/*
  Best Practice to seperate interface & implimentation
  setvalue() & getvalue() also called function accesors 
*/

#include <iostream>

class c1{ // Class definition
  private: // even if we dont write private, it will be private by default
    int value {}; // cannot initialize here; initialize with constructor or constructor initializer list.  
  public: 
    c1 // Constructor used to initialize private data memebr 
    void setvalue (int number) {value = number; }
    int getvalue () {return value; }
};

int main (){
  c1 o1; 
  o1.setvalue(92);
  std::cout<< "The value is : " << o1.getvalue() << std::endl; 
}