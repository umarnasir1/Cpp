/*
  How to Function Calls Work?
  The call stack
*/
#include <iostream>

using std::cout;
using std::endl;

// Function Prototype
int func1(int a, int b);
void func2(int &x, int y, int z);

int main() {
    int x {10};
    int y{20};
    int z{};
    z = func1(x,y);
    cout << z << endl;
    return 0;
}

// Function Definition
int func1(int a, int b) {
    int result {};
    result = a + b;
    func2(result, a , b);
    return result;
}

void func2(int &x, int y, int z) {
    x+= y + z;
}

/*             Memory for a program:
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
              | func2()               |
              | z= 20                 |
functions()   | y= 10                 |
              | x= 30                 |
              |    ----------         |
              | func1()               |
              | result = 30           |
              | b = 20                |
              | a = 10                |
              -------------------------
              |                       |
              |  Static Variables/    |
              |  Global variables     |
              -------------------------
              |  Code Area            |
              | z = 0                 |
main()         | y = 20                |
              | x = 10                |
              ------------------------

        code
        main() stops what it's doing and it allocates space for x, y, z. Also, an activation record is pushed for func1().

        stack
        funct1() is now on the stack, and we need space for a, b, and result.
        We're doing pass by value here. So what's going to happen is the x hooks up with the a and the y hooks up with the b. So these values coppies in the stack as x and y are passed to the function.
        Now we start executing the function and 30 is stored in result .. (orignally result was zero)

        func2() is activated and we need space for  x (reference parameter), y, z
        y and z get their values
        x is a reference parameter so x is an alias of result i,e any changes in x will be updated in result
        start executing the code (x= 60 and that updates result in func1())

        func2() is done and its get popped off the stack

        func1() returns to main and stack is being popped as func1() is done

        back to main ().. prints the value and now program is done.

        -----------------------
        What typically happens when main calls func1 (or any function calls another) ?
            There are other ways to acheive the same results :)

            main:
                push space on the stack for the return value (that func1 is going to return something to main)
                push space for the parameters (if parameters are passed in)
                push the return address (func1 needs to know where to come back to)
                transfer control to func1 (assembly language instruction - jmp; you just jump over there, and you are off and running. )
            func1:
                push the address of the previous activation record (moving a stack pointer to know where the top of the stack is)
                push any register values that will need to be restored before returning to the caller
                perform the code in func1
                restore the register values (main is on the top of stack)
                restore the previous activation record (move the stack pointer - pop all the stuff off the stack)
                store any function result
                transfer control to the return address (jmp) - back to main in his case
            main:
                pop the parameters off the stack to clear off the stack (main knows where the parameters are, where the return values are)
                pop the return value
*/
