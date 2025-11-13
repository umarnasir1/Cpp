/*
  Best Practice to seperate interface & implimentation
  setvalue() & getvalue() also called function accesors 
  Const Qualify Object 
  o1 is not const qualified, i.e., mutable 
  o2 is const - not mutable 
    for const object we need a const qualified getter in order to access the value
      const qualified getter will not allow any modification of data in the object
      int getvalue () const {return value; } 
      const after the function sigure and before the block 
    
    The const qualified getter will work for both mutable and the immutable const qualified object. but we can have two separate getters
      for mutable and immutable object. 
  
  Const qualified functions can always be called 
  Non-const qualified functions may only be called by non-const or mutable objects. 
*/

#include <iostream>

class c1{ // Class definition
  private: // even if we dont write private, it will be private by default
    int value {}; // cannot initialize here; initialize with constructor or constructor initializer list.  
  public: 
    void setvalue (int number) {value = number; }
    int getvalue () {return value; }
    int getvalue () const {return value; } // const qualified getter - const after the function sigure and before the block 
    // works for both mutable and non-mutable object 
};

int main (){
  c1 o1; 
  o1.setvalue(92);
  const c1 o2 = o1;
  std::cout<< "o1 value is : " << o1.getvalue() << std::endl; 
  std::cout<< "o2 value is : " << o2.getvalue() << std::endl; // will get error as for const object, const qualified getter is needed.
}