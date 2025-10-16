/*
  Best Practice to seperate interface & implimentation
*/

#include <iostream>

class c1{ // Class definition
  private: 
    int value {}; 
  public: 
    void setvalue (int number) {value = number; }
    int getvalue () {return value; }
};

int main (){
  c1 o1; 
  o1.setvalue(92);
  std::cout<< "The value is : " << o1.getvalue() << std::endl; 
}