/*
    // 
    1. There are only three ways one can pass arguments to a function:
        Pass By Value.
        Pass By Reference.
        Pass By Address.

    //
    2. char array[255];  
        The array can store 255 elements. 
        They arary may be initialized at the time of declaration. 
*/

#include<iostream>
#include<string>

// int main(){

//     // // ---------
//     // enum answer { yes, no, whoknows }; 
//     // enum answer a[3]; 
//     // a[0] = no; 
//     // a[2] = yes; 
//     // a[1] = whoknows; 
//     // for (int i{0}; i < 3; i++)
//     //     std::cout << a[i]; // 120
    
//     // // ---------
//     // int i = 2;
//     // if (i--==1) // after executing this line i=1;
//     //     std::cout<< i; 
//     // else 
//     //     std::cout<< i+1; // 2

//     // // ---------
//     // char i = '1';
//     // switch(i){
//     //     case '1':
//     //         std::cout<<"Hello ";
//     //     case '2':
//     //         std::cout<<"world "; // Hello world 
//     //         break; 
//     //     case '3':
//     //         std::cout<<"!";
//     // } 

//     // ---------
//     std::string s1[]= {"A","Z"};
//     std::string s="";
    
//     for (int i{0}; i<2; i++)
//         std::cout << s.append(s1[i]).insert(1,"_"); // A_A__Z  
//         // Inserts s1[i] in s starting from 1st index of s
  

// // ---------
// // ---------
// // ---------
// // ---------
// // ---------
// // ---------
// // ---------


//     return 0;
// }


//// ----------------------------
// char fun (char *p){
//     char c = *p; 
//     (*p)++; 
//     return c; 
// }

// int main(){
//     char array[3]={'a','b','c'}; 
//     fun(array+1); 
//     std::cout<< fun(array+1); // c
//     return 0;  
// }


////------------------------------ 
// class SupClass {
// public:
//     void show(int par){ std::cout << par + 1;}
// };

// class SubClass : public SupClass {
// public:
//     void show(float par){ std::cout << par + 2;}
// };

// int main(){
//     SubClass o;
//     o.show(2.0); //4
// }

////----------------------------------------------
class Class {
public:
    static char value;
    Class() { value++; };
    ~Class () { value++; };
    //insert code here
    void set(char c = 'd') { value = c; } // abcd
    
    void print() { std::cout << value;}
};

char Class::value = 'a';

int main () {
    Class a,*b;
    b = new Class();
    b->set('a');
    b->print();
    delete b;
    a.print();
    a.set('c');
    a.print();
    a.set();
    a.print();

    return 0;
}