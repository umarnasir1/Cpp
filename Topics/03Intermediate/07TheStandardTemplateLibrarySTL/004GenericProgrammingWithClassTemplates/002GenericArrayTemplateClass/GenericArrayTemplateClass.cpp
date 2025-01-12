/*
    Generic Programming with Class Templates
        Creating a Generic Array Template class - not a raw array or dynamic array (Class Template for Array class)
            Generic: array of any size and type
                Array<type, size> arr; // passing size of array as in template parameter
                    Its possible to have non-typed template parameters e.g., Array<5> nums; 
            replacement for using a raw array
            C++11 already have this in standard template library (STL)
    
    In the following exgample, the compiler is providing three template classes 
        Array<int, 5> nums;
        Array<int, 100> nums2 {1};
        Array<std::string, 12> months {std::string{"Jan"}};

    OBS!! We will not use this (Array<int, 5> nums;) in code. 
        Since C++11 th STL has std::array which is a template-based array class.
        We are just doing it to learn. If we need to use array we will use std::array.
*/
#include<iostream>
#include<string>

// template <int N> //not generic;
template <typename T, int N> // typename T, will be replaced by what ever type the user wants; N - size of array - user will provide N at compile time and compiler will create the array.
class Array{ // Array class 
    int size{N};
    T values[N]; // the N needs to be known at compile-time!; Values in array that is of N size of T type

    // overloading << operator
    // size N is part of the type. So the compiler needs to know both T and N in order to bind the function correctly.
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr){ // display the array; it needs to know what N is so it needs the template parameter.
        os << "["; 
        for (const auto &val: arr.values)
            os << val << " "; 
        os << "]" << std::endl; 
        return os; 
    }
public: 
    Array() = default; // default constructor - https://en.cppreference.com/w/cpp/language/default_constructor
    // If we provide a non-no-args constructor, then the default no-args constructor is not generated. If we still want one, we can tell the compiler to generate one using the "= default".
    Array(T init_val){ // constructor - single arg - setting all the values of array to that value; T in case of generic
        for (auto &item: values)
            item = init_val; 
    }
    void fill(T val){ // change all those array elements to whatever value is passed in here; fill the array with whatever Ts are provided. (T is pluggable type)
        for (auto &item: values)
            item = val; 
    }
    int get_size() const{ //getter
        return size; 
    }
    // overloaded subscript[] operator for easy use - so we can use it as array indexing. 
    T &operator[](int index){ // returning a reference to T as array can be of any type (generic)
        return values[index];
    }
};

int main(){

    Array<int, 5> nums; // creating an array of 5 integers
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

    Array<int, 100> nums2 {1}; // initializer to initialize 100 integers to 1 - fixed size array; we are not doing any memory allocation. its happening on the stack. the compiler is handing the sizeing. - single arg constructor will be used as single argument in initializer list.
    std::cout << "The size of num2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl; 

    // template class to hold std::string
    Array<std::string, 12> months {std::string{"Jan"}}; // initializing all values of array month to Jan.
    // Array<std::string, 12> months {"Jan"};
    std::cout << "The size of months is: " << months.get_size() << std::endl;
    std::cout << months << std::endl; // [Jan Jan Jan Jan Jan Jan Jan Jan Jan Jan Jan Jan ]

    months[1] = std::string{"Feb"}; // months[1] = "Feb"; months.operator[1] = "Feb"
    months[2] = std::string{"Mar"}; 
    months[3] = std::string{"Apr"}; 
    months[4] = std::string{"Maj"}; 
    months[5] = std::string{"Jun"}; 
    std::cout << months << std::endl; //[Jan Feb Mar Apr Maj Jun Jan Jan Jan Jan Jan Jan ]

    months.fill(std::string{"X"}); // months.fill("X");
    std::cout << months << std::endl; // [X X X X X X X X X X X X ]

    return 0; 
}