/*
  Friends of a Class
    non-member function
      declaring a friend looks like in C++
        non- member function: declaring a stand alone non-member function
        member function/method of another class 
        Another (separate) class as a friend.
*/
#include<iostream>
#include<string>

class Player{
  friend void display_player(Player &p); // declaring a stand alone non-member function as friend of the player class. Player class grants the friendship by declaring the function prototype preceded by the friend keyword. Now display_player function has access to everything in the player class.
  friend void Other_class::display_player1(Player &p); // declaring display_player method of Other_class as a friend. display_player method will have acess to everything in the Player class.
  friend class Other_class; // Declaring Other_class as friend of Player so all the methods in the Other_class will have access to the Player class's private attributes.
  std::string name;
  int health;
  int xp;
public:
  // we don't have to go through public getters or setters to display the player information or set player information as we can directly access the Player attributes via display_player function. In fact, we can change them as well if we wanted to since the object is passed by reference and in this case non-const.
};

void display_player(Player &p){
  std::cout << p.name << std::endl;
  std::cout << p.health << std::endl;
  std::cout << p.xp << std::endl;
}

class Other_class{
  //...
public:
  void display_player1(Player &p){ // we can use the player classes private attributes directly within it.
    std::cout << p.name << std::endl;
    std::cout << p.health << std::endl;
    std::cout << p.xp << std::endl ;
  }
};
