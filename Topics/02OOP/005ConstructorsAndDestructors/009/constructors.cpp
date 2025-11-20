/*
    Checking Constructor Calls
*/
#include <iostream>
#include <string>

// In static memory space bec they are outside of any function
const std::string unk {"unknown"}; 
const std::string clone_prefix {"clone-"}; // simple prefix string 

// -- Class Interface --
class Animal {
    std::string a_type {};
    std::string a_name {};
    std::string a_sound {};
public:
    Animal(); // default constructor - initialize the object to default state 
    Animal(const std::string &type, const std::string &name, const std::string &sound); // Constructor with args 
    Animal(const Animal&);  // copy constructor - takes data from another animal object
    ~Animal();  // destructor
    Animal& operator = (const Animal&);   // copy/assignment operator - acts like a constructor - overloading = operator
    void print() const; // to print objects ; const qualified function to work with const objects 
};

// -- implementation --
Animal::Animal() : a_type(unk), a_name(unk), a_sound(unk) { //initializer list, unk - unknown defined as constant
    std::cout << "default constructor" << std::endl;
}

Animal::Animal(const std::string &type, const std::string &name, const std::string &sound) // const string references 
: a_type(type), a_name(name), a_sound(sound) { // initializer list
    std::cout << "constructor with arguments" << std::endl;
}

Animal::Animal(const Animal &a) { // const reference to another object 
    std::cout << "copy constructor" << std::endl;
    a_name = clone_prefix + a.a_name; // clone prefix being added to the beginning of the name using addition operator from the string class
    a_type = a.a_type;
    a_sound = a.a_sound;
}

Animal::~Animal() {
    std::cout << "destructor: " << a_name << " the " << a_type << std::endl;
}

Animal& Animal::operator = (const Animal &o) { // Overloading assignment operator
    std::cout << "assignment operator" << std::endl;
    if(this != &o) { // checking on safe side; condition to check if we are not copying myself into myself. 
        a_name = clone_prefix + o.a_name;
        a_type = o.a_type;
        a_sound = o.a_sound;
    }
    return *this; // copy assignment operator always returns a reference to this, and so we dereference the pointer and use reference operator (Animmal&) to return reference to our current object. 
}

void Animal::print () const {
    std::cout << a_name << " the " << a_type << " says " << a_sound << std::endl;
}

int main() {
    Animal a {}; // default construtor has set the class to a default state, object = a;
    a.print();
    
    const Animal b("goat", "bob", "baah"); // constructor with argruments; constant object b;
    b.print();
    
    const Animal c {b}; // copy constructor; - no need of operator overloading =
    //const Animal c = b; // can use assignment operator also for copy constructor; - no need of operator overloading = 
    c.print();
    
    a = c; // assignment operator will be overloaded
    a.print();
    
    std::cout << "end of main\n";
    return 0;
}
