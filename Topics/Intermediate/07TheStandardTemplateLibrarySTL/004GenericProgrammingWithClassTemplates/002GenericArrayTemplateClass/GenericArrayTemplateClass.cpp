/*
    Generic Programming with Class Templates
        Creating a Generic Array Template class (Class Template for Array class)
            Generic: array of any size and type
                Array<size> arr; // size of array as in template parameter
            replacement for using a raw array
            C++11 already have this in standard template library
*/
#include<iostream>
#include<string>

template <int N> // size of array - user will provide N at compile time and compiler will create the array.
class Array{ // Array class 
    int size{N}; // how do we get the N??
    int values{N}; // the N needs to be known at compile-time!

    // overloading << operator
    friend std::ostream &operator <<(std::ostream &os, const Array<N> &arr){ // display the array; it needs to know what N is so it needs the template parameter.
        os << "["; 
        for (const auto &val: arr.values)
            os << val << " "; 
        os << "]" << std::endl; 
        return os; 
    }
public: 
    Array() = default; // constructor
    Array(int init_val){ // constructor - single arg - setting all the values of array to that value
        for (auto &item: values)
            item = init_val; 
    }
    void fill(int val){ // change all those array elements to whatever value is passed in here
        for (auto &item: values)
            item = val; 
    }
    int get_size() const{
        return size; 
    }
    // overloaded subscript[] operator for easy use - so we can use it as array indexing. 
    int &operator[](int index){ // returning reference
        return values[index];
    }
};

int main(){

    Array<5> nums; // creating an array of 5 integers
    std::cout << "The size of num is: " << nums.get_size() << std::endl; 
    std::cout << nums << std::endl; // display the integers as << operator is overloaded

    nums.fill(0); // fill the array to 0s 
    std::cout<< "The size of num is: " << nums.get_size() << std::endl; // 5
    std::cout<< nums << std::endl; // [0 0 0 0 0]

    nums.fill(10); // fill the array to 10s 
    std::cout<< nums << std::endl; //[10 10 10 10 10]

    nums[0] = 1000; // subscript operator [] overloaded; nums.operator[](0); setting values;
    nums[3] = 2000; // nums.operator[](3); setting values
    std::cout << nums << std::endl; // [1000 10 10 2000 10]

    Array<100> nums2 {1}; // initializer to initialize 100 integers to 1 - fixed size array; we are not doing any memory allocation. its happening on the stack. the compiler is handing the sizeing. 
    std::cout << "The size of num2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl; 
 
    return 0; 
}