/*
  Generic Programming with Class Templates

  How to make a class generic
    Class to hold items: string (name) and an integer (value).
    Instead of an int and a string, we want to model a double and a string.

*/
#include<iostream>

// class Item{
// private:
//   std::string name; 
//   int value; 
// public: 
//   Item(std::string name, int value) // 2 args constructor
//     :name{name}, value{value}{
//   }
//   // getters
//   std::string get_name() const {return name;}
//   int get_value() const {return value;}
// };

template <typename T> 
class Item{
private:
  std::string name; 
  T value; 
public: 
  Item(std::string name, T value) // 2 args constructor
    :name{name}, value{value}{
  }
  // getters
  std::string get_name() const {return name;}
  T get_value() const {return value;}
};

int main (){

  return 0;
}
