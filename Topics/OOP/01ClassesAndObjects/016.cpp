/*
  Deep Copy
    create new storage and copy values
*/
#include<iostream>

class Deep{
private:
  int *data; //raw pointer
public:
  Deep(int d); //Constructor
  Deep(const Deep &source); //Copy Constructor
  ~Deep(); //Destructor
};

Deep::Deep(int d){
  data = new int; // allocate storage on the HEAP (dynamically)
  *data = d; // stores the passed in integer d
}

Deep::Deep(const &scourse){
  data = new int; // allocate storage
  *data = *source.data;
  cout << "Copy constructor - deep" << endl;
}

Deep::~Deep(){
  delete data; // free storage that was allocated by the constructor
  cout << "Destrcutor freeing data" << endl;
}

int main(){
  return 0;
}
