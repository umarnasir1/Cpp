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

struct Abc{
  int p;
  int q;
};

int main(){

  Abc x {23, 34}; // initializer list 
  std::cout << x.p << " " << x.q << std::endl;
  return 0;
}
