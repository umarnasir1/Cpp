/*
  What is Operator Overloading
*/
#include<iostream>

int main(){

  // --- Code if we are not overloading operators -------------------
  // (1) Using functions
  // (2) Using member methods

  // Using functions:
  // Suppose we've implemented our own class 'Number', which can model any kind of number: an integer, a double, a complex number, an irrational number, etc.
  // If we want to be able to manipulate 'Number' objects (e.g., result object of class Number) so that we can add them, subtract them, multiply them and so forth, we could implement non-member functions or member functions to achieve what we want. So if we wanted to add a and b, then multiply that result by the quotient of c divided by d.
  Number result = multiply (add(a,b), divide(c,d));

  // Using member methods: (we need objects and method names)
  Number result = (a.add(b)).multiply(c.divide(d));

  // Both the statements are very unreadale and difficult to write due to functions.
  // We're adding dividing and multiplying and we've been using these operators to do that since we were little kids in school why can't we use them now.
  // Ans: C++ doesnt know what to do with our user-defined types.
  // In most cases, it makes no sense to add or multiply or subtract your objects. For example, what does it mean to subtract two player objects in a game or multiply two account objects?

  // In many cases, it doesn't make sense to overload certain operators for your classes. In those cases don't do it. Only do it if it makes sense.

  // ---- Using overloaded operators ------------------
  // Let's see what our calculation would look like if we overloaded the addition, multiplication and division operators.

  // Suppose we have a Number class that models any number. Our user-defined number class now looks and feels and behaves like the built in c++ types.
  Number result = (a+b)*(c/d); // Behind the scenes, we're still calling methods or functions.

  return 0;
}
