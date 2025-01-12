// Linker Errors
// Linker errors occours when linker tries to put all the pieces of program together to create an executable
// A lot of times they occur as due to one or more pieces (of files) are missing (typically, this can happen when an object file or libraries cant be found by the linker).
// Linker errors are tricky to fix.
// We usually deal with these errors if we are using libraries from third parties (more at Intermediate and Advance level C++)
// In below example, no compiler error but linker error.
// In below code, the error is x is defined externally, in main(), we want to print the value of x. x is not initialized or there is no value of x due to which the linker is giving error (where do I (Linker) get that value to print because that what you (programmer) have asked me (Linker) to do right now)
// so there is linker error as linker cannot find the value of x

// #include <iostream>

// extern int x;

// int main(){
//   std::cout << "Hello World!!" << std::endl;
//   std::cout << x;
//   return 0;
// }