/*
  Operator Precedence
*/

#include <iostream>

int main(){

  /*
    Eg. 1: We have three operators: the assignment operator, the addition operator and the multiplication operator.
    The precedence chart tells us that the multiplication operator has the highest precedence, followed by addition, followed by assignment. The statement is re-written on following line showing order of evaluation by including Paranthesis.
    Note that the evaluation takes place in order of multiplication, addition and finally, assignment.
  */
  //result = num1 + num2 * num3;
  //result = (num1 + (num2 * num3));

  /*
    Eg. 2: We again have three operators: the assignment operator, the addition operator and the subtraction operator. In this case, addition and subtraction are of higher precedence than assignment, but they both have the same precedence.
    So in this case, we need to use their associativity to determine the order of evaluation.
    We see that plus and minus associate left to right. So, this example using parentheses to show the order of evaluation is re-written below.
  */
  //result1 = num1 + num2 - num3;
  //result1 = ( (num1 + num2) - num3);

  // Eg.
  int x {5};
  int y {-2};
  int z {2};

  std::cout << (x + y * z <= x + z * z - x) << std::endl; // 1 - This evaluates to (1 <= 4) which is true, so 1 is displayed since 1 is true.

  return 0;
}
