/*
  Recursive Functions 
   A function that call itself
  Eg. Factorial, Fibonacci

  OBS! An implimentation of factorial without recursion is in Projects/Challenges/03Functions/002NonRecursiveFactorial.cpp
*/
#include<iostream>

// Function Prototype
unsigned long long factorial (unsigned long long n);  // as the factorial function can generate massively huge numbers so unsigned long long is used as return type and parameter type as it can hold very very large positive numbers.
unsigned long long fibonacci (unsigned long long n);

int main (){
    std::cout << "factorial (3): " << factorial (3) << std::endl; // 6
    std::cout << "factorial (8): " << factorial (8) << std::endl;  // 40320
    std::cout << "factorial (12): " << factorial (12) << std::endl; // 479001600
    std::cout << "factorial (20): " << factorial (20) << std::endl;  // 2432902008176640000

    std::cout << "fibonacci (5): " << fibonacci (5) << std::endl; // 5
    std::cout << "fibonacci (30): " << fibonacci (30) << std::endl; // 832040
    std::cout << "fibonacci (40): " << fibonacci (40) << std::endl;// 102334155

  return 0;
}

//Function Definitions - factorial stack below
/*
Ex. factorial - factorial is defined in terms of itself.
0! = 1
n! = n * (n-1)!

Base case:
  factorial(0)= 1
Recursive case:
  factorial(n) = n * factorial(n-1) // recursion
*/
unsigned long long factorial (unsigned long long n){
  if (n==0) // checking base case
    return 1; // base case
  return n * factorial (n-1);  // recursive case
}

/*
Ex. Fibonacci
Fib (0) = 0
Fib (1) = 1
Fib (2) = Fib (n-1) + Fib (n-2)

Base case:
  Fib(0) = 0
  Fib(1) = 1
Recursive case:
  Fib(n) = Fib(n-1) + Fib(n-2)
*/
unsigned long long fibonacci (unsigned long long n){
  if (n <= 1)
    return n; // base case
  return fibonacci(n-1) + fibonacci(n-2); // recursive case
}

/*       Memory for a program for factorial (3)
            -------------------------
            |                       |
            |         HEAP          |
            |      Free Storage     |
            |                       |
            |                       |
            |                       |
            -------------------------
            |  Stack                |
            | (function call stack) |
            | ---------------       |
fact(0)     | n=0                   |
            | ------------          |
fact(1)     | 1*fact(0)             |
            | n=1                   |
            | -----------           |
fact(2)     | 2*fact(1)             |
            | n=2                   |
            | -------------         |
fact(3)     | 3*fact(2)             |
            | n=3                   |
            -------------------------
            |                       |
            |  Static Variables/    |
            |  Global variables     |
            -------------------------
            |  Code Area            |
main()      | factorial(3)          |
            ------------------------



4 x activation records on the stack for the same function so this is following the definition of recursion.
That's the definition of recursion.

figure before unwinding

1 is returned when fact(0) is called and unwiding process starts from the recursive call. and fact(0) is popped off the stack ie., activation record get clearned up
passing 1 to fact(0) in fact(1) and popping fact(1)  ie., activation record get clearned up
passing 1*1=1 to fact(1) in fact(2) and popping fact(1)  ie., activation record get clearned up
passing 2*1=2 to fact(2) in fact(3) and popping fact(2)  ie., activation record get clearned up
passing 3*2=6 to fact(3) in main() and popping fact(3)  ie., activation record get clearned up

and we output value of 6 (the final result)
*/
