/*
  Generic Programming with Function Templates
    Generic Programming - use max with any data types
    Aim: How we can use C++ Templates to accomplish writing generic functions.

 max function as a template function 
  function to determine the max of 2 integers. for floats, double, char, long there will be little modifiction in max fucntion. The function is same, just the type (of parameters) is changed so many versions of max depending on type.
 
  int max(int a, int b){
    return (a > b) ? a : b; // conditional operator
  }

  We can replace type (int) with an identifier/name that represents any type,
  say T (but we can use any valid identifier we wish)

  T max (T a, T b) {
    return (a>b) ? a : b;
  }

  But the computer won't know what to do with this, and it's going to give us
  a compiler error. We need to explicitly tell the compiler that this is a 
  template function.

  template <typename T> // OR template <class T> 
    typneme T is template parameter type. 
    This tells a computer the T is the type name that will be replaced with 
    whatever the user needs.
    We may also use class instead of typeneme. typename and class are equivalent
  
  We can use ALMOST any type we need.
   Notice that the code in the template function is using the > operator to 
   compare a and b. This means that whatever type we use for T must support 
   > operator. For primitive types, like int, chars and doubles, it's not a 
   problem. But for our own class types, we have to be sure that our class 
   overloads the greater than operator or this won't compile.

  We can have multiple template parameters (no limit) and their types can be 
  different.
 */

#include <iostream>

template <typename T> // OR template <class T> 
T max (T a, T b) {
  return (a>b) ? a : b;
}

template <typename T1, typename T2> // function declaration - We have specified two template parameters in this case.
void func(T1 a, T2 b){ // It expects 2 parameters. The first is a type T1 and the second is of type T2.
  std::cout << a << " " << b << std::endl;
}

int main (){

  int a {10};
  int b {20};

  std::cout << max<int>(a,b) << std::endl; // usage of template parameter int- This gives the
  // compiler all the information it needs to actually generate a specialized 
  // function from the template we created using int in place of T. 
  // this happens at compile-time.
  // similar syntax as vectors and smart pointers, unique pointer, shared pointers.
  // as these are implimented as template classes. 

  double c {20.1};
  double d {21.2};
  std::cout << max<double>(c,d) << std::endl; // max function for doubles.
  // The compiler now knows that it needs to generate the double version of 
  // the max function.

  // Often, the compiler can deduce the type and the template prarameter is not 
  // needed. (and we don't even need to provide it as in the second statement.)
  // Depending on the type of c and d, the compiler will figure it out.
  std::cout << max(c,d) << std::endl; // for doubles 

  // max function - char
  char e {'A'};
  char f {'Z'};

  std::cout << max(e,f) << std::endl; // the compiler will generate the character version of max fucntion.

  // func - func with multiple types 
  func<int, double> (10, 20.2); // explicitly provide an integer in the double
  func('A', 12.4); // call of func with no template parameters, the compiler 
  // will deduce the types from the function arguments.

  // // Assuming player class
  // Player p1{"Hero", 100, 20};
  // Player p2{"Enemy", 99, 3};

  // // using max with player objects 
  // // The compiler will generate the max function that expects and compares
  // // player objects.
  // std::cout << max<Player> (p1,p2); 
  // // This will not compile unless Player class overloads > operator

  return 0; 
}