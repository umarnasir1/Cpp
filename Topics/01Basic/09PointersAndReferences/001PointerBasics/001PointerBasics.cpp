/*
  Declaring Pointers
  Accessing the pointer Address and Storing Address in a Pointer

  variable_type *pointer_name; // Declaration
  Read from right to left

  int *ptr; // ptr stores addresses of pointers to integers.

  variable_type *pointer_name {nullptr};  // {} {nullptr} same, we are initializing pointer to 0 i.e., to point nowhere i.e., address zero
  variable_type *pointer_name {}; // Initializing - important to initilize at the time of declaration otherwise it will contain garbage data (dummy address in this case).
  un-initialize pointer can point anywhere - So if we use it we could be accessing memory that we have no business messing around with.

  Eg.02 size of pointer
    difference between pointer and what it is pointing to.

  * - dereferencing operator

*/
#include <iostream>
#include <string>
#include <vector>

int main (){

  int *int_ptr {};  // int_ptr is a pointer to integer
  double *double_ptr {nullptr}; // double_ptr is a pointer to a double
  char *char_ptr {nullptr};
  std::string *string_ptr {nullptr}; // string_ptr is a pointer to a C++ string object.

  // Eg. 01
  int num {10}; // actual variable declaration.
  // declaring a pointer
  int *p; // p is a pointer to int - a pointer can hold address (to integer in this case)

  // p is not initialized
  //cout << "Value of p is: " << p << endl;  // 0x61ff60 - garbage - the value of p is the value that is stored in p (addresses to integers)- and this address is pointing somewhere (we dont know where )
  //p = nullptr; // set p to point nowhere - sets p to 0
  //cout << "Value of p is: " << p << endl; // 0

  std::cout << "Value of num is: " << num << std::endl; // 10 - displaying contents of num
  std::cout << "Address of num is: " << &num << std::endl; //0x7ff7bf730724 - location in memory of variable num  - displaying address of num.
  std::cout << "sizeof of num is: " << sizeof num << std::endl; // 4 (bytes) - how much storage is allocated by num / how much storage we need to store int

  p = &num;   // store address of num in pointer variable

  std::cout << "Address stored in p variable: " << p << std::endl; // 0x7ff7bf730724 - print the address stored in p pointer variable
  std::cout << "Value of *ip variable: " << *p << std::endl; // 10 - access the value at the address available in pointer
  std::cout << "Address of p is: " << &p << std::endl; // 0x7ff7bf730718 - address of variable p
  std::cout << "sizeof of p is: " << sizeof p << std::endl; // 8 bytes - addresses can be stored in 8 bytes

  // Eg. 02- size of
  // Each pointer is pointing to a different type. Each can hold addresses of variables of the type they point to.
  // All below pointers will hold values that can be represented in 8 bytes. An address of an integer and an address of a vector and the address of a string all have size of 8 on my machine.
  int *p1 {nullptr};
  double *p2 {nullptr};
  unsigned long long *p3 {nullptr};
  std::vector<std::string> *p4 {nullptr};
  std::string *p5 {nullptr};

  /*
  There's a big difference between the size of the pointer variable itself and the size of what it points to i.e.,
  difference between a pointer and what it points to.
  A pointer is just a simple variable.
  What it points to could be simple or a very complex structure
  in below egs. p1 is point to int, p2 to double .. etc.

  p1 is going to point to an integer, right.
  p2 will point to a double, so we'll have much more storage here.
  P4 will point to a vector of string objects so it could be pointing to a vector of string objects where this could
    be Larry Moe and Curly, where these guys are all string objects.
  */

  // size of pointer
  // how much store is required to store address (address that the pointer is pointing to)
  std::cout << "sizeof of p1 is: " << sizeof p1 << std::endl; // 8 bytes - addresses can be stored in 8 bytes
  std::cout << "sizeof of p2 is: " << sizeof p2 << std::endl; //8
  std::cout << "sizeof of p3 is: " << sizeof p3 << std::endl; //8
  std::cout << "sizeof of p4 is: " << sizeof p4 << std::endl; //8
  std::cout << "sizeof of p5 is: " << sizeof p5 << std::endl; //8

  //value of *p1-*p5 --- values char, double
  // how much storage is rquired to store value pointer is pointing to (value at address that the pointer is pointing to)
  std::cout << "sizeof of *p1 is: " << sizeof *p1 << std::endl; //4
  std::cout << "sizeof of *p2 is: " << sizeof *p2 << std::endl; //8
  std::cout << "sizeof of *p3 is: " << sizeof *p3 << std::endl; //8
  std::cout << "sizeof of *p4 is: " << sizeof *p4 << std::endl; //24
  std::cout << "sizeof of *p5 is: " << sizeof *p5 << std::endl; //24

  // size of address  of p1-p5
  std::cout << "sizeof of &p1 is: " << sizeof &p1 << std::endl; //8
  std::cout << "sizeof of &p2 is: " << sizeof &p2 << std::endl; //8
  std::cout << "sizeof of &p3 is: " << sizeof &p3 << std::endl; //8
  std::cout << "sizeof of &p4 is: " << sizeof &p4 << std::endl; //8
  std::cout << "sizeof of &p5 is: " << sizeof &p5 << std::endl; //8
  //-------

  // Eg. 03
  // -- Typed pointer -The compiler will make sure that the address stored in a pointer variable is of the correct type
  int score {10};
  double high_temp {100.7};
  double low_temp {37.2};

  int *score_ptr {nullptr}; // score_ptr is pointer to integer   0x000000

  score_ptr = &score; // Ok - assigning address of score to score_ptr - Ok since score_ptr holds addresses of integers and scores an integer.
  // score_ptr is pointing to integer.

  //score_ptr = &high_temp; // assigning address of high_temp to score_ptr - compiler error as score_ptr hold address of int but we are asking it to store the address of a double. Both addresses are 8 bytes long, so the issue isn't the size won't fit, the issue is that there's a type conflict.
  double *temp_ptr; // not initialized .. pointing anywhere

  // pointer is a variable so its value can be changed.
  temp_ptr = nullptr;
  temp_ptr = &high_temp; // points to high_temp
  temp_ptr = &low_temp;  // now points to low_temp

  std::cout << "Value of score is: " << score << std::endl; // 10
  std::cout << "Address of score is: " << &score << std::endl; // 0x7ff7bf7306ec
  std::cout << "Value of score_ptr is: " << score_ptr << std::endl; // 0x7ff7bf7306ec
  std::cout << "Value of *temp_ptr is: " << *temp_ptr << std::endl; // 37.2 - Access the data we are pointing to

  // Eg. 4 - Dereferencing a Pointer - Access the data we are pointing to
  int score1 {100};
  int *score_ptr1 {&score1}; // Declaring a score pointer to be a pointer to an integer and initialize it to the address of score. Now score_ptr1 points to score1

  std::cout << *score_ptr1 << std::endl; //100 - As score_ptr1 points to score1 (we are using dereference operator)

  // When we dereference a pointer on the left hand side of an assignment statement, this results in an l value
  // left hand side of an assignment statement is address or location
  *score_ptr1 = 200; // Dereferencing the pointer again. The left-hand side of an assignment statement is an address or a location that's where we want to store things. Assigning 200 to score_ptr1. We just change the value of score indirectly via the pointer.

  std::cout << *score_ptr1 << std::endl; // 200
  std::cout << score1 << std::endl; // 200

  // string - modified what that pointer is pointing to.
  std::string name {"Bjarne"};
  std::string *string_ptr1 {&name};

  std::cout << *string_ptr1 << std::endl; // Bjarne

  name = "Straustrup"; // changing name  - not through pointer.. through variable - not modifying the pointer, but modifiing the area the pointer is pointing to.

  std::cout << *string_ptr1 << std::endl; // Straustrup - dereferencing the pointer again


  // another eg. of pointer and what it is poitning to
  std::cout << "---------------------------" << std::endl;
  std::vector <std::string> stooges {"Larry", "Moe", "Curly"};
  std::vector <std::string> *vector_ptr {nullptr};

  vector_ptr = &stooges;

  std::cout << "First stooge: " << (*vector_ptr).at(0) << std::endl; // Larry - dereferencing prointer and then at(). further we use () as . have higher presidence then ()
  std::cout << "Second stooge: " << (*vector_ptr).at(1) << std::endl; // Moe
  std::cout << "Third stooge: " << (*vector_ptr).at(2) << std::endl; // Curly

  // Printing all the stooges through vector pointer
  std::cout << "Stooges: ";
  for (auto stooge: *vector_ptr) // Range based for loop ; *vector_ptr -we are getting stooges
    std::cout << stooge << " "; // Larry Moe Curly
  std::cout << std::endl;

  // Eg 5
  int intarray[3] {1,2,3};
  std::cout << intarray << std::endl; // 0x7ff7bfefe854- address of first element
  // array elements can also be accessed as if the array were a pointer. 
  std::cout << *intarray << std::endl; // 1 - pointing to the first element of array

  // if we want to assign the value to first element of the array
  int *ip {intarray}; 
  *ip = 2; // [2, 2, 3]
  ++ip; // incrementing the pointer so it points to the second element. 
  *ip = 3; // assigns the value 3 to the second element of the array. [2,3,3]
  *(++ip) = 4; // increment a pointer and using it in same expression [2,3,4]
  std::cout << &intarray << std::endl; // 0x7ff7bfefe854 - address of first element

  return 0;
}
