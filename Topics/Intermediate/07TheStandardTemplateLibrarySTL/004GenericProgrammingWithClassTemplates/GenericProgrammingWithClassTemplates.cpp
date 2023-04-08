/*
  Generic Programming with Class Templates

  How to make a class generic
    Class to hold two(2) items: std::string (name) and a value (an integer, double, or string)
    Multiple template parameters

  Implementation of template-based array class.

*/
#include<iostream>
#include<string>
#include<vector>

// // class Item{
// // private:
// //   std::string name; 
// //   int value; 
// // public: 
// //   Item(std::string name, int value) // 2 args constructor
// //     :name{name}, value{value}{
// //   }
// //   // getters
// //   std::string get_name() const {return name;}
// //   int get_value() const {return value;}
// // };
template <typename T> 
class Item{
private:
  std::string name; 
  T value; // value that will be replaced (int, double, std::string)
public: 
  Item(std::string name, T value) // 2 args constructor
    :name{name}, value{value}{
  }
  // getters
  std::string get_name() const {return name;}
  T get_value() const {return value;}
};

// multiple template parameters (can be same or different)
// associating 2 data types and calling it my pair.
template <typename T1, typename T2>
struct My_Pair{
  T1 first; 
  T2 second; 
}; 

int main (){

  // creating objects - instances of Items
  // if we want to create instances of items, we can simply provide the type of the value in the 
  // template parameter and the compiler will take care of generating the correct class from the 
  // template.
  Item<int> item1 {"Frank", 100}; // value of type int; name of type stirng 
  std::cout << item1.get_name() << " " << item1.get_value() << std::endl; 

  Item<double> item2 {"House",100.0}; // value of type double; name of type stirng
  std::cout << item2.get_name() << " " << item2.get_value() << std::endl; 

  Item<std::string> item3 {"Frank", "Professor"}; // value of type string; name of type stirng
  std::cout << item3.get_name() << " " << item3.get_value() << std::endl; 

  Item <Item<std::string>> item4 {"Frank", {"C++", "Professor"}}; // Name: "Frank"; value: Item<std::string> (Name: C++; value: Professor)
  std::cout << item4.get_name() << " "
            << item4.get_value().get_name() << " "
            << item4.get_value().get_value() << std::endl; 

  std::cout << "\n================================================================" << std::endl; 
  std::vector<Item<double>> vec {}; // vector that holds items and those items will have value as an double
  vec.push_back(Item<double>("Larry",100.0)); 
  vec.push_back(Item<double>("Moe",200.0));
  vec.push_back(Item<double>("Curley",300.0));

  for (const auto &item: vec){ // uses const ref; for (auto item: vec){ - will work (copies the value)
    std::cout << item.get_name() << " " << item.get_value() << std::endl; 
  }

  std::cout << "\n================================================================" << std::endl; 
  My_Pair <std::string, int> p1 {"Frank", 100}; 
  My_Pair <int, double> p2 {124, 13.6}; 

  std::cout << p1.first << "," << p1.second << std::endl; 
  std::cout << p2.first << "," << p2.second << std::endl; 

  return 0;
}
