/*
  Generic Programming with Function Templates
    Primitive Types
      Function templates with single parameter 
      Function templates with two parameters
    Own Types (Structure, Classes) (operator overloading)
      Function templates with single parameter 
      Function templates with two parameters
    Swap Template Function 
    

    Generic Programming - use max with any data types
    Aim: How we can use C++ Templates to accomplish writing generic functions.



//----------------
 max function as a template function 
  function to determine the max of 2 integers. for floats, double, char, long there will be little modifiction in max fucntion. The function is same, just the type (of parameters) is changed so many versions of max depending on type.
 
  int max(int a, int b){
    return (a > b) ? a : b; // conditional operator
  }

  double max(double a, double b){
    return (a > b) ? a : b; // conditional operator
  }

  char max(char a, char b){
    return (a > b) ? a : b; // conditional operator
  }

//----------------

  We can replace type (int) with an identifier/name that represents any type,
  say T (but we can use any valid identifier we wish)

  T max (T a, T b) {
    return (a>b) ? a : b;
  }

  But the computer won't know what to do with this, and it's going to give us
  a compiler error. We need to explicitly tell the compiler that this is a 
  template function.

  template <typename T> // OR template <class T> 
    typname T is template parameter type. e.g., min <int> (2,3)
    This tells a computer the T is the type name that will be replaced with 
    whatever the user needs.
    We may also use class instead of typeneme. typename and class are equivalent
  
  We can use ALMOST any type we need.
   Notice that the code in the template function (max) is using the > operator to 
   compare a and b. This means that whatever type we use for T must support 
   > operator. For primitive types, like int, chars and doubles, it's not a 
   problem. But for our own class types, we have to be sure that our class 
   overloads the greater than operator or this won't compile. E.g., The following 
   will not compile unless Player overloads operator >

   Player p1{"Hero", 100, 20};
   Player p2{"Enemy", 99, 3}; 

   std::cout << max<Player>(p1,p2);

  We can have multiple template parameters (no limit) and their types can be 
  different.
 */

#include <iostream>
#include <string> 

// Template Function #1 (blue print)
template <typename T> // OR template <class T> 
T max (T a, T b) { // a of type T; b of type T; return Type T
  return (a > b) ? a : b;
}

// OBS! At this point, the compiler have done nothing. All it have done is to make sure that for
// template function is valid but it have not created an integer version or double verion of this. 
// Nothing is created. This is just a blueprint right now. 

// Template Function #2
template <typename T> // OR template <class T> 
T min (T a, T b) {
  return (a < b) ? a : b;
}

// Template Function #3
template <typename T1, typename T2> // function declaration - We have specified two template parameters in this case.
void func(T1 a, T2 b){ // It expects 2 parameters. The first is a type T1 and the second is of type T2.
  std::cout << a << " " << b << std::endl; // displaying a and b
}

// Structure - Own data type 
struct Person{
  std::string name; 
  int age; 
  // overloaded operator < as member methods
  bool operator< (const Person &rhs) const { // first const- dont want to modify the argument; last const as we dont want to modify anything
    return this -> age < rhs.age; // return age < rhs.age; 
  }
};

// overloaded operator << as non-member function
std::ostream &operator<<(std::ostream &os, const Person &p){ // std::ostream &os not const as we want to change it
  os << p.name; // putting data on the stream
  return os; 
}

// Template function my_swap - swap two integers or any data type
template <typename T>
void my_swap (T &a, T &b){
  T temp {a};
  a = b; 
  b = temp;
}

int main (){
  // ---------------------------------------
  // primitive types (int, double, char)
  // ---------------------------------------

  // int
  int a {10};
  int b {20};

  std::cout << max<int>(a,b) << std::endl; // usage of template parameter int- This 
  // gives the compiler all the information it needs to actually generate a 
  // specialized function (int, char,...) from the template we created using int 
  // in place of T. 
  // This happens at compile-time.
  // similar syntax as vectors and smart pointers, unique pointer, shared pointers.
  // as these are implimented as template classes. 
  std::cout << min<int>(2,3) << std::endl; // 2
  
  // Often, the compiler can deduce the type and the template prarameter is not 
  // needed. The compiler is smart enough and create the integer version of
  // teplate function. Alot of times, the compiler will figure it out. Sometime 
  // the compiler cant figure it out, depending on how complex the template 
  // function is. 
  std::cout << min(2,3) << std::endl; // 2 - not providing template prarameter <int>
  std::cout << min(5+2*2, 7+40) << std::endl; // 9
  
  // double 
  double c {20.1};
  double d {21.2};
  std::cout << max<double>(c,d) << std::endl; // max function for doubles.
  // The compiler now knows that it needs to generate the double version of 
  // the max function.
  std::cout << min(12.5,9.2) << std::endl; // 9.2

  // char
  char e {'A'};
  char f {'Z'};

  std::cout << max(e,f) << std::endl; // the compiler will generate the character version of max fucntion.
  std:: cout << min('A','B') << std::endl; // A

  // ---------------------------------------
  // func - func with multiple types 
  func<int, int> (10,20); // 10 20
  func(10,20); // 10 20 -// will deduce the types from the function arguments.
  func<int, double> (10, 20.2); // 10 20.2 -explicitly provide an integer in the double
  func('A', 12.4); // A 12.4 -call of func with no template parameters, the compiler 
  // will deduce the types from the function arguments.
  func(1000, "Testing"); // 1000 Testing
  func(2000, std::string{"Frank"}); // 2000 Frank
  

  // ---------------------------------------
  // struct - own data type - Operator overloading
  Person p1 {"Bjarne", 30}; 
  Person p2 {"Straustrup", 50};

  // min() will compare any type that will make scence. so comparing p1 and p2 
  // will not make scence. It will make scence if we just compare the ages. 
  // Person p3 = min(p1, p2); 
  // The compiler has generated that specialized function for the persons, but now It can't be 
  // compiled it because it doesn't know how to compare 2 persons using <. 
  // In this case, we will tell the compiler how to do that (operator overloading)
  Person p3 = min(p1, p2); // - p1.operator< (p2); // will deduce the types from the function arguments or min<Person,Person>(p1, p2).
  std::cout << p3.name << " is younger." << std::endl; 

  // -----------
  // operator overloading with function template with two arguments
  // if we run func(p1,p2); without operator overloading << we will get errorError - no overloaded << operator for type: Person. 
  func(p1,p2); // will deduce the types from the function arguments; or func<Person,Person>;

  // Testcases for my_swap function

  // -----------
  // int
  // -----------
  int x{100}, y{200};
  std::cout << "Before Swap:\n" << x << " , " << y << std::endl; // we can modify func() and use it to display too 
  my_swap(x,y);
  std::cout << "After Swap\n" << x << " , " << y << std::endl; 

  // -----------
  // char
  // -----------
  char char1 {'A'}, char2 {'B'};
  std::cout << "Before Swap:\n" << char1 << " , " << char2 << std::endl; 
  my_swap(char1,char2);
  std::cout << "After Swap\n" << char1 << " , " << char2 << std::endl; 

  // -----------
  // string
  // -----------
  std::string str1 {"Bjarne"}, str2 {"C++ is fun"};
  std::cout << "Before Swap:\n" << str1 << " , " << str2 << std::endl; 
  my_swap(str1,str2);
  func(str1,str2);
  std::cout << "After Swap\n" << str1 << " , " << str2 << std::endl; 

  // -----------
  // object - in this case, will swap p1 and p2 but will only display name as this is how we have overloaded <<
  // -----------
  std::cout << "Before Swap:\n" << p1 << " , " << p2 << std::endl; // << already overloaded for func()
  my_swap(p1,p2);
  std::cout << "After Swap\n" << p1 << " , " << p2 << std::endl; 

  return 0; 
}