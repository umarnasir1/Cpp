/*
    auto keyword 
*/

#include <vector>


int main (){

    vector<int> vec; // declared a vector 
    vec<int>::iterator iter = vec.begin(); // declaring a vector iterator of int type.
    // begin() returns an iterator which points to the first element in the vector
    // or 
    auto iter = vec.begin(); // the compiler knows that vec.begin() returns a vector of int iterator.  so the compiler knows 
    // what type it is going to be

    return 0;
}