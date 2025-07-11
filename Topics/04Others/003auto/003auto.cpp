/*
    typeid - gives internal representation of what the type is 
        This value will be different depending on the compiler, the library, the version
            The value will be different on Linux & Windows  
*/
#include <iostream>
#include <typeinfo>
#include <vector>

int main (){

    // used case #1
    /*std::string s {"This is a string"};
    auto x {s}; 
    std::cout << "x is " << x << std::endl; 
    std::cout << "The type os x is " << typeid(x).name() << std::endl; */

    // used case #2
    std::vector<int> v1 {1,2,3,4,5};
    for (auto it = v1.begin(); it != v1.end(); ++it){
        // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){// loop that relies on an iterator for a vector
        // type of iterator: std::vector<int>::iterator we can replace it with auto bec it knows that v1.begin() returns type of the iterator
        //  and so the auto type will be that type of variable  
        std::cout << "int is :" << *it << std::endl; 
        std::cout << "type of it is " << typeid(it).name() << std::endl;
    }

    return 0; 
}