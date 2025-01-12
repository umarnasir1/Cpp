// Chain the exptraction operator & insertion operator

#include <iostream>

int main(){
  int d, m, y;
  std::cout << "Enter your date of birth in format (dd month year) : ";
  std::cin >> d >> m >> y;
  std::cout << "Date of Birth : " << d << " / " << m << " / "<< y << std::endl;
  return 0;
}
