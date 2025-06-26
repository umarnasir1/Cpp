/*  
    C++23
    print function uses the same formatter as format. 
    This will mitigate the need of cout and iostream in many cases. 
*/
#include <print> // C++23

int main(){
    const char* str {"Hellow, World!"}; 
    std::print("The str is {}\n", str);
}