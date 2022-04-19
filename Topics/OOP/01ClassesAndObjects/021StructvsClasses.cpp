/*
  Struct vs Classes
*/
#include<iostream>
#include<string>

// class Person{
//   std::string name;
//   std::string get_name(){ return name;}
// };
//
// int main(){
//   Person p;
//   p.name = "Frank"; // ERROR - class memebers are private by default and we cannot access private members.
//   std::cout << p.get_name(); // ERROR - class memebers are private by default and we cannot access private members.
//   return 0;
// }


struct Person{
  std::string name;
  std::string get_name(){ return name;} // best practice is not to declare methods in structure. Here, its to show that we can put methods in structs.
};

int main(){
  Person p;
  p.name = "Frank"; // OK - as struct memebrs are public by default
  std::cout << p.get_name(); // OK - as struct memebrs are public by default
  return 0; /
}
