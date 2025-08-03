/*
struct structureName{
  member1;
  member2;
  member3;
  ..
  memberN;
};

structureName instance;
*/
#include<iostream>

struct S{
  int i {};
  double d {};
  const char *s {};
};

int main(){

  S s1 {23, 34.2, "Test"}; // initializer list to initilize variable or object based on that structure.
  // S - structure name; s1 - object name 
  std::cout << "s1: "<< s1.i << ", " << s1.d << ", " << s1.s << std::endl; // s1: 23, 34.2, Test
  s1.d = 73.0; // writing value 
  std::cout << "s1: "<< s1.i << ", " << s1.d << ", " << s1.s << std::endl; // s1: 23, 73, Test 
  // accessing memebers of structure via pointer with ->
  auto *sp {&s1};
  sp->d = 75.9; // writing value via pointer member defrence operator which accesses a member through a pointer
  std::cout << "s1: "<< s1.i << ", " << s1.d << ", " << s1.s << std::endl; // s1: 23, 75.9, Test
  std::cout << "s1: "<< sp->i << ", " << sp->d << ", " << sp->s << std::endl; // s1: 23, 75.9, Test
  
  return 0;
}
