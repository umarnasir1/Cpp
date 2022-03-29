/*
  Copy Constructor

  Used Case
    Pass object to function/method by - value
    Return object by value
    Construct one object based on another

  Declaring Copy constructor
  Same name as the class as its a constructor.
  And in the parameter list, we have a single object passed in of the same type. We pass that object in as a reference and a constant.
  Y by reference and constant?
    if we pas by value, then we have to make a copy of it. That's the whole point of the copy constructor. We would defeat the purpose and end up with never ending recursive calls.
    And as a constant because the semantics of copying means that we're copying the source, we're not modifying it. So the const prevents any modification to the source object.

  Type::Type (const Type &source);

  Implementing the Copy constructor
  Type::Type (const Type &source){
  // code or initialization list to copy the object
  }
*/

// Pass object to function/method by - value
Player hero {"Hero", 100, 20};

void display_player(Player p){ // expects player object by value
  // p is a COPY of hero in this example (using the copy constructor)
  // use p
  // Destructor for p will be called (as p is going out of scope)
}

display_player(hero);

// Return Object by value
Player enemy;

Player create_super_enemy(){ // creates and returns a player object
  Player an_enemy{"Super Enemy", 1000, 1000};
  return an_enemy; // A COPY of an_enemy is returned
}

enemy = create_super_enemy();

// Construct one object based on another (existing)
Player hero {"Hero", 100, 100};

Player another_hero {hero}; // A copy of hero is made using copy constructor

//----  Declaring Copy constructor
Player::Player(const Player &source);
Account::Account(const Account &source);
