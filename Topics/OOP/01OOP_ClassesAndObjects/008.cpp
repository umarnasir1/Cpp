/*
  Default Constructor
*/

class Account{
private:
  std::string name;
  double balance;
public:
  bool withdraw(double amount);
  bool deposit(double amount);
};

// In this class, no constructors are defined, So c++ will automatically generate a default constructor that allows us to create objects with no initialization information.

int main(){
  Account frank_account; // frank_account and jim_account, two local objectts are created. Since no constructor is provided, the compiler provided default constructor will be used.
  Account jim_account;

  // in case of pointer to an object, the object is created on heap. We still havent provided any constructor so default constructor will be used.
  Account *mary_account = new Account;
  delete mary_account;

  return 0;
}

class Account{
private:
  std::string name;
  double balance;
public:
  Account(){ // no args constructor will be called when no initialization information is provided during object creation and initialization will be performed. If a constructor that expects arguments is created and no argument constructor is not created, then c++ will not generate the no args default contructor automatically, we have to explicitly define it. In this case, if we have code that creates objects with initialization information, then that code will no longer compile since no default constructor implicitly define (c++ will automatically no args constructor only when no constructor is defined.).
    name = "None";
    balance = 0.0;
  }
  Account(std::string name_val, double bal){ // constructor that expects arguments and initilization done on basis of arguments passed
    name = name_val;
    balance = bal;
  }
  bool withdraw(double amount);
  bool deposit(double amount);
};
