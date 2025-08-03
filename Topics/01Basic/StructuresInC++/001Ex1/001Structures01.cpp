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
  std::cout << "s1: "<< s1.i << ", " << s1.d << ", " << s1.s << std::endl;

  return 0;
}
