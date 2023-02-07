/*
  this pointer
*/

// 1. Here's an example of one way to write the set balance method for an account class.
// bal= name of the parameter; balance = class member balance
void Account::set_balance(double bal){
  balance = bal; // compiler is doing behind the scenes; this->balance is implied
}

// 2. To disambiguate identifier use
// suppose that the name of parameter is balance. Now in the method body, the assignment statement balance equals balance would use the parameter balance for both of those identifiers instead of the data member balance. That's because of scope rules. Now this statement would not accomplish what we wanted to do.
void Account::set_balance(double balance){
  balance = balance; // which balance? the parameter
}

// So in order to refer to the data member balance, we need to explicitly use this arrow balance.
void Account::set_balance(double balance){
  this->balance = balance; //Unabmiguous
}

// 3. To determine obeject identity
// Sometimes, its useful to know if tow objects are same object. If compare logic is involved or computationally expensive, then a quick check to see if the objects are the same, could help performance
// Suppose we have a compare balance method in the account class that compares the balance of one object with another.
// We could check to see if we're comparing the same objects by comparing this and the address of other. If they are the same, then we are dealing with the same object.
int Account::compare_balance(const Account &other){
  if (this == &other) // checking if the objects are one in the same. 'this' is the address of the current object, &other is address of the other object.
    std::cout << "The same objects" << std::endl;
}

frank_account.compare_balance(frank_account);

// We will use the 'this' pointer again when we overload the assignment operator.
