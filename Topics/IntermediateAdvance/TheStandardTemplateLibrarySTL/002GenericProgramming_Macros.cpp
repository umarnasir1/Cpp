/*
  Generic Programming with Macros
    The preprocessor will first remove the pound defined statements the code, then it goes through the program and replaces/substituting any defined names with what we defined them to be and then the processed file is sent to the compiler.

    Idea of Generic Programming: A function (for e.g.,) with any data type.

    Generic functions using preprocessor Macros.

    NOT recommended
      Be very careful when you use macros in practice, especially macros that use arguments.
      Example1
      Example2
      Best practice to avoid wrong output
*/

// -------------------
// NOT Recommended
// --------------------

// defines the name MAX_SIZE to be 100 and no type is associated with 100.
#define MAX_SIZE 100

// defines PI to be 3.14159
#define PI 3.14159

if (num > MAX_SIZE) // MAX_SIZE being used in the expression in the file statement.
  std::cout << "Too big";

double area = PI * r * r; // PI is being used in the calclulation

// Better practice:
// use constants, as they are typed and are known to the compiler.

// max function
// function to determine the max of 2 integers. for floats, double, char, long there will be little modifiction in max fucntion. The function is same, just the type (of parameters) is changed so many versions of max depending on type.
// Generic Programming - use max with any data types
//  Using MACROS with parameters

int max (int a, int b){
  return (a > b) ? a : b; // conditional operator
}

int max (double a, double b){
  return (a > b) ? a : b; // conditional operator
}

int max (char a, char b){
  return (a > b) ? a : b; // conditional operator
}

int x {100};
int y {200};
std::cout << max(x,y); // displays 200


// Generic programming
// ----Exameples 1
// Macros with parameters
//  defining macro that expects two arguments, and we can define it to be conditional expression. So when the preprocessor sees max with two arguments, it will replace it with what we defined it in the macro, and it will also replace the arguments a and b. So now we have no functions defined, just a single macro called max. We can now use max in our code with arguments

#define MAX (a,b) ((a > b) ? a : b)

std::cout << MAX(10,20) << std::endl; // 20
std::cout << MAX(2.4, 3.5) << std::endl; // 3.5
std::cout << MAX('A', 'C') << std::endl; // C

// ----Exameples 2 -
// macros with arguments s(#define)

#define SQUARE(a) a*a

result = SQUARE(5); // 25 - Square(5) will be replaced with 5*5. -OK

result = 100/SQUARE(5); // 100 but we expect 4 - Square(5) will be replaced with 5*5, hence, 100/5*5 and we will get 100 ((100/5)*5) - blind substitution - WRONG

// how can we make this better
// BEST PRACTICE: when we use macros, we can wrap all the arguments in parantheses - better chance that result will be correct.

#define SQUARE(a) ((a)*(a))

result = SQUARE(5); // 25 - Square(5) will be replaced with ((5)*(5)). - OK

result = 100/SQUARE(5); // 4- result = 100/((5)*(5)) - OK
