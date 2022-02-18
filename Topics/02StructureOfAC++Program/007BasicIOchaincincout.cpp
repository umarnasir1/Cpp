// Chain the exptraction operator & insertion operator

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int d, m, y;
  cout << "Enter your date of birth in format (dd month year) : ";
  cin >> d >> m >> y;
  cout << "Date of Birth : " << d << " / " << m << " / "<< y << endl;
  return 0;
}
