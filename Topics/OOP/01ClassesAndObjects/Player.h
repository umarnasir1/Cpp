/*
  Static Class Members

  Player.h - class specification
  Player.cpp - class definition
  020StaticClassMembers.cpp
*/
#ifndef _PLAYER_H_   // include guard
#define _PLAYER_H_
#include<string>

class Player
{
private:
  static int num_players; // static variable - we cannot initialize it here, we will get compiler error - c++ forbids inclass initialization of non-constant members, so we will initialize it in player.cpp file.
  std::string name;
  int health;
  int xp;
public:
  // getters
  std::string get_name(){ return name;}
  int get_health(){return health;}
  int get_xp(){return xp;}
  Player(std::string name_val = "None", int health_val = 0, int xp_val = 0); //  Constructor with default parameters
  Player(const Player &source);// Copy Constructor
  ~Player(); // Destructor
  static int get_num_players(); // static class function. This function will return static integer we just declared. Static only belongs to class. static functions have only access to static variables and not object variables (name, health, xp).
};

#endif // _PLAYER_H_
