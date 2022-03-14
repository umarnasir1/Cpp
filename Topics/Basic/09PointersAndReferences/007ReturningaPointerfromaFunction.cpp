/*
  Returning a Pointer from a Function

  type *funciton ();

  What not to do when returning pointer from a function - Never return a pointer to a local variable!!

  int *dont_do_this(){
    int size {};
    ...
    return &size;
  }
  // size is a local variable to the function. This will compile just fine since the address of size is the address of an integer and that's what the function returns.
  PROBLEM1!! The address of a local variable in the function is returned. The variable's on the stack and the function just terminated, so this variable is now past its lifetime. The next time the function is called or any function is called, the stack area will be reused and the pointer will now be pointing into that new functions activation record. If you overwrite the data it's pointing to, you could trash the stack pointers, static links, all kinds of important information on the activation record.

  // function or_this has the same problem except that it's assigned a pointer to size variable and returns it. In both cases, the address that's being returned is a stack variable or a function local variable, very bad idea.
  int *or_this () {
      int size {};
      int *int_ptr {&size};
      ....
      return int_ptr;
  }

*/
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Function Declaration
int *largest_int (int *int_ptr1, int *int_ptr2);
int *create_array (size_t size, int init_value = 0);
void display (const int *const array, size_t size);

int main(){

  cout << "Eg. 01 ------------------------------------------" << endl;
  int a {100}, b {200};

  int *largest_ptr {nullptr};
  largest_ptr = largest_int (&a, &b); // The function expects pointers to integers. he function returns a pointer, which is assigned to largest_ptr (a pointer to integer)
  cout << "Out of " << a << " and " << b << ", the largest numebr is: " << *largest_ptr << endl; // 200 - deferencing pointer to print the value

  cout << "\nEg. 02 ------------------------------------------" << endl;
  int *my_array {nullptr}; // will be allocated by the function;
  size_t size;
  int init_value {};

  cout << "\nHow many integers would you like to allocate? ";
  cin >> size;
  cout << "What value would you like them initialized to? ";
  cin >> init_value;

  my_array = create_array(size, init_value); // create the array - size integers allocated dynamically on the heap and all initialized to init_value and returns the address of that first integer in the array.
  cout << "\n-----------------------------------------------------" << endl;

  display(my_array, size);
  delete [] my_array;  // free the storage as it is on heap

  return 0;
}

// Function Definition
// returns the value of the parameter that poitns to the largest integer. It's okay to return a pointer to data that's being passed into a function since we know that data exists. So in this case, we compare the two integers that the two pointers are pointing to and return the pointer that points to the largest integer. Notice that we're not comparing the pointers themselves. We're comparing what they're pointing to by de-referencing them.

int *largest_int (int *int_ptr1, int *int_ptr2) {
  if (*int_ptr1 > *int_ptr2)
    return int_ptr1;
  else
    return int_ptr2; // returning a pointer to integer
}

// return tynamically allocated memory
// allocate memory dynamically inside a function and return the address of that memory
int *create_array (size_t size, int init_value) { // init_value - initialize all the elements of array to to 0
  int *new_storage {nullptr};

  new_storage = new int[size]; // allocate array on the heap and stores the address of first one in array_ptr. We have to be careful not to loose this pointer, else we will have memory leak
  for (size_t i{0}; i < size; ++i) // initialize all the elements of array to to 0 (init_value)
    *(new_storage + i) = init_value; // pointer offset notation
  return new_storage; // returns pointer to integer - address of the first integer that we dynamically craated.
}

void display (const int *const array, size_t size){ // as we have got a constant pointer and we are poinitng to a constant arry, we cant mess with array either by accident or intentionally
  for (size_t i{0}; i < size; ++i)
    cout << array[i] << " ";
  cout << endl;
}


/*
Memory for Eg. 02
                            Memory for a program: (before stack is cleaned - stack gets cleaned after function execution so it will clean when create_arry() will be executed and then cleaned again when display() will be executed)

                            10 ingegers are allocated dynamically on the HEAP. The address of first element is 5000
                            -------------------------
                            |                       |
                            |         HEAP          |
                            |      Free Storage     |
                            |                       |
                            |                       |
                            |                       |(5036) new_storage[9]
                            |                       |(5032) new_storage[8]
                            |                       |(5028) new_storage[7]
                            |                       |(5024) new_storage[6]
                            |                       |(5020) new_storage[5]
                            |                       |(5016) new_storage[4]
                            |                       |(5012) new_storage[3]
                            |                       |(5008) new_storage[2]
                            |                       |(5004) new_storage[1]
                            |                       |(5000) new_storage[0]
                            -------------------------
                            |       Stack           |
                            | (function ccall stack)|
                            |                       |showing local variables (2)in main()
                            |size 10                |
          display(5000,10)  |array 5000             | pointing to first element of pointer(new_storage) in the heap
                            | ----------------      |
                            |                       |showing local variables (2)in main()
                            |new_storage 5000       | the new statement will return address of first element
                            |init_value 2           |
      create_array(10,2)    |size 10                |
                            -------------------------
                            |                       |
                            |  Static Variables/    |
                            |  Global variables     |
                            -------------------------
                            |                       | showing local variables (3)in main()
                main()      |init_value 2           | (3000)
                            |size 10                | (2000)
                            |my_array 5000          | (1000) create_array returns address which is assigned. so
                            ------------------------- my_array is pointing to first element of new_storage. As we dont want to loose the pointer, so we assigned it to my_array so now we have a copy which we can use as the stack will be clearned after function execution

*/
