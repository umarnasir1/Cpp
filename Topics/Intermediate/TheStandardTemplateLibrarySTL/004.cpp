/*
  Generic Programming with Function Templates
    Generic functions using Function Templates.

  (1) Create Two templates.
    How they work with integers, with doubles, with character and primitive times where there are no issues with overloading operators.
  (2) Then what we'll do is we'll create our own type, we'll call it person or something like that. Then you'll see some of the issues that we have to address to get that person class or structure in this case to work with these templates.
  (3) Then we will create a swap templates function at the end.
*/
#include<iostream>
#include<string>

template <typename T> // generic type T
T min(T a, T b){ // a and b of type T
  return (a < b) ? a : b; // comparing; Issue: no issue with premitive types, but issue with user defined types and classes.
} // at this point the compilers done nothing for us. It hasn't -- all it's done is make sure that this is valid, but it has not created an integer version of this or double version of this, nothing gets created. It's just a blueprint right now.

// template <typename T1, typename T2>
// void func(T1 a, T2 b){
//   std::cout << a << " " << b << std::endl;
// }

struct Person {
  std::string name; // C++ string
  int age;
  // TODO - going back to Operator Overolading 
  // bool operator<(const Person &rhs) const{ // Operator Overloading
  //   return this->age < rhs.age;
  //}
};

int main (){

  Person p1{"Curly", 50}; // Person object
  Person p2{"Moe", 30};

  Person p3 = min(p1,p2); // Comparing ages of object1 and object2 - doesnt quite make scence though
  // Error - as there is no overloading of < here (in case of user defined data types we have to overload operators. So here the compiler doesn't know how to compare two persons using <)
  // code for operator overloadin line 26
  // std::cout << p3.name << " is younger" << std::endl; // displaying result

  std::cout << min<int>(2,3) << std::endl; // 2; using template parameter <int>. The compiler now sees blueprint (line 18) and generates the integer version of it, so T will be int.
  std::cout << min(2,3) << std::endl; // 2; template parameter <int> not provided; The compilers smart enough to deduce that these are integers. So it's going to create the integer version of it. A lot of times the compiler will figure it out, a lot of times, the compiler wont figure it out depending on the complexity of the template function.
  std::cout << min('A','B') << std::endl; // A - it will deduce that this template parameter is character and it would generate the character version of template function.
  std::cout << min(12.5,9.2) << std::endl; // 9.2 - it will deduce that template parameter is double and will generate double version of template function.
  std::cout << min(5+2*2, 7+40) << std::endl; // 9 - We dont have to worry about precedence here.

  // func<int,int>(10,20);
  // func(10,20);
  // func<char,double>('A',12.4);
  // func('A',12.4);


  return 0;
}
