#include <iostream>
#include <string>

const std::string unk {"unknown"};
const std::string clone_prefix {"clone-"};

// -- interface --
class Animal {
    std::string a_type {};
    std::string a_name {};
    std::string a_sound {};
public:
    Animal();   // default constructor
    Animal(const std::string& type, const std::string& name, const std::string& sound);
    Animal(const Animal&);  // copy constructor
    ~Animal();  // destructor
    Animal& operator = (const Animal&);   // copy/assignment operator
    void print() const;
};

// -- implementation --
Animal::Animal() : a_type(unk), a_name(unk), a_sound(unk) {
    std::cout << "default constructor" << std::endl;
}

Animal::Animal(const std::string& type, const std::string& name, const std::string& sound)
: a_type(type), a_name(name), a_sound(sound) {
    std::cout << "constructor with arguments" << std::endl;
}

Animal::Animal(const Animal& a) {
    std::cout << "copy constructor" << std::endl;
    a_name = clone_prefix + a.a_name;
    a_type = a.a_type;
    a_sound = a.a_sound;
}

Animal::~Animal() {
    std::cout << "destructor: " << a_name << " the " << a_type << std::endl;
}

Animal& Animal::operator = (const Animal& o) {
    std::cout << "assignment operator" << std::endl;
    if(this != &o) {
        a_name = clone_prefix + o.a_name;
        a_type = o.a_type;
        a_sound = o.a_sound;
    }
    return *this;
}

void Animal::print () const {
    std::cout << a_name << " the " << a_type << " says " << a_sound << std::endl;
}

int main() {
    Animal a {};
    a.print();
    
    const Animal b("goat", "bob", "baah");
    b.print();
    
    const Animal c = b;
    c.print();
    
    a = c;
    a.print();
    
    std::cout << "end of main\n";
    return 0;
}
