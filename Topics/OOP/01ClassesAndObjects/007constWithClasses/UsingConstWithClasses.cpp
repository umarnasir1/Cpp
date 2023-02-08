/*
  Using const with classes
  const correctness

  What happens when we call member methods on a const object.
    We will get compiler error when we will pass areference to a const object.
    The compiler is being very caeful not to allow a constant objet to loose its constness.
    Solution: We need to tell the compiler that specific methods will not modify the object.
      by putting the const modifiere befor the semicolon and the method prototype
      std::string get_name() const; 
      Now the compiler will not only allow this method to be called on const objects, it will 
      also produce a compiler error if you try to modify any of the object attributes in the 
      method.
      OBS! since you're telling the compiler that get_name() is a const member function.
      Then if you write code in the body of get_name() that modifies the object, you'll get 
      a compiler error.
*/
#include<iostream>
#include<string>

class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  std::string get_name() const {return name;} // getter - const correctness - We need to tell the compiler that specific methods will not modify the object. Now, the compiler will not only allow this method to be called on const objects, it will also produce a compiler error if you try to modify any of the object attributes in the method.
  // we will get compiler error if we write code in the body of get_name that modifies the object as get_name is a const member function.
  void set_name(std::string name_val){name=name_val;} // setter
  // Overloaded Constructors
  Player(); // no-args constructor
  Player(std::string name_val);
  Player(std::string name_val, int health_val, int xp_val);
  // default destructor will be used. 
};

Player::Player()
  :Player {"None", 0, 0}{ // delegating to Player (three ags constructor)
}

Player::Player(std::string name_val) // delegating to Player (three ags constructor)
  :Player {name_val, 0, 0}{
}

Player::Player(std::string name_val, int health_val, int xp_val)
  :name{name_val}, health{health_val}, xp{xp_val}{ // initializer list
}

// not a member function, its a regular function thats y not declared in class
void display_player_name (const Player &p){ // expects a reference to a const object.
  std::cout << p.get_name() << std::endl;
}

int main(){

  const Player villian {"Villain", 100, 55}; // villain is const object so its attributes cannot be change/modified.
  
  // //  1.
  // villian.xp = 1000; // checking the aove statement by making xp public. It should  because xp is public (made private again after checking this), but it won't because villain is constant.

  // //  2. What happens when we call member methods on a const object?
  // villian.set_name("Super guy"); // Error - villian is const; this will never work even when const correct as we don't want to set anything in villain.
  // // This will not work even with const correctness 

  // std::cout << villian.get_name() << std::endl; // Error
  // // REASON: The compiler assumes that the get name function could potentially change the object (if there is some code in body). The compiler cant guarantee so its going to throw an error.

  // 3. Regular function
  // display_player_name(villian); // ERROR (if std::string get_name())- p.get_name could potentially change the object. The compiler is being very careful not to allow a const object to lose its constness.

  // const correctness
  std::cout << villian.get_name() << std::endl;
  display_player_name(villian);

  // Hero Object
  Player hero {"Hero", 100, 15};
  
  // 1.
  std::cout << hero.get_name() << std::endl; //Hero -OK   
  
  // 2.
  // display_player_name(hero); // ERROR - hero is not a const; we are passing hero into display_player_name() as a const (const Player &p) that means this function can't change it. Thats the problem. p.get_name() could potentially change the object. The compiler is being very careful not to allow a const object to lose its constness.
  // Solution: const correctness
  
  display_player_name(hero); //Hero OK after const correctness

  return 0;
}
