/*
  Stream Manipulators - align and fill
    std::setw - field width - only applied to next data item on the stream; right justtification by default
    justification
      std::left
      std::right
    std::setfill -only applies when we have fieldwidth associated with it;

*/
#include<iostream>
#include<iomanip>
#include<string>

void ruler (); // ruler function

int main (){

  int num1 {1234};
  double num2 {1234.5678};
  std::string hello{"Hello"};

  // default - no stream manipulators or methods
  std::cout << "\n--Defaults -------------------------------------------------" << std::endl;
  ruler();
  std::cout <<  num2 << hello << std::endl; // 1234.57Hello - display 6 digits of presion and then round and hellow is displayed

  // default - one per line
  std::cout << "\n--Defaults - one per line ----------------------------------" << std::endl;
  ruler();
  std::cout << num1 << std::endl
            << num2 << std::endl // rounding to 6th precision of digit
            << hello << std::endl;

  // setw - This will create a field width of 10 for the next data item only. num1 will be displayed right justified by default in the field width of 10. Notice that the last digit in number, the 4 in this case, is displayed in position 10. That's the rightmost side of the field width we set earlier. num2 is displayed right after. justification will persist until changed. However, the justification will only be used if associated with a set width manipulator.(no field width associated with num2 and hello)
  std::cout << "\n--width 10 for num1 -------------------------------------------------" << std::endl;
  ruler();
  std::cout <<  std::setw(10) << num1
            << num2
            << hello
            << std::endl;
// 12345678901234567890123456789012345678901234567890
//       12341234.57Hello

  std::cout << "\n--width 10 for num1 and num2-----------------------------------------" << std::endl;
  ruler();
  std::cout << std::setw(10) << num1 // displayed right justified with the width of 10
            << std::setw(10) << num2 // displayed right justified with the width of 10
            << hello // no formatting
            << std::endl;

  // 12345678901234567890123456789012345678901234567890
  //       1234   1234.57Hello

  // justification
  std::cout << std::setw(64) << std::right << num1 << std::endl; // ------------------------------------------------------------1234                                         
  std::cout << std::setw(64) << std::right << num2 << std::endl; // ---------------------------------------------------------1234.57                                    
  std::cout << std::setw(64) << std::right << hello << std::endl; // -----------------------------------------------------------Hello

  ruler();
  std::cout << std::setw(10)
            << std::left // left justification
            << num2 // only affects num2 and next item in stream have no filed width associated to it.
            << hello << std::endl;

  // 123456789012345678901234567890
  // 1234.57   Hello

  // field width for all 3 item
  std::cout << "\n--width 10 for num1 and hello and width 15 for hello-------------" << std::endl;
  ruler();
  std::cout << std::setw(10) << num2
            << std::setw(10) << std::right << hello // default is right .. but we are doing it to be explicit.. dont have to do it
            << std::setw(15) << std::right << hello
            << std::endl;

  // 1234567890123456789012345678901234567890
  // 1234.57        Hello          Hello

  // field width for all 3 item
  std::cout << "\n--width 10 for num1 and num2 and 15 for hello left for all ------" << std::endl;
  ruler();
  std::cout << std::setw(10) << std::left << num1
            << std::setw(10) << std::left << num2
            << std::setw(15) << std::left << hello
            << std::endl;
  // 12345678901234567890123456789012345678901234567890
  // 1234      1234.57   Hello

  // setfill
  // setfill to dash
  // This is presistent (till changed)
  std::cout << std::setfill('-');
  std::cout << std::setw(10) << num2 // feild width will only apply to apply
            << hello << std::endl; // setfill doesnt apply as there is no fieldwidth associated with it;

  // 12345678901234567890
  // ---1234.57Hello

  std::cout << "\n--width 10 for num1 and num2 and 15 for hello left for all setfill to dash ------" << std::endl; // setfill presistant as set at line 88
  ruler();
  std::cout << std::setw(10) << std::left << num1
            << std::setw(10) << std::left << num2
            << std::setw(15) << std::left << hello
            << std::endl;
  // 12345678901234567890123456789012345678901234567890
  // 1234------1234.57---Hello----------


  std::cout << std::setfill('*');
  std::cout << std::setw(10) << num2
            << std::setfill('-') << std::setw(10) << hello // setfill('-') will impliment on next hello as it have setw(15) associated with it
            << std::setw(15)<< hello
            << std::endl;

  // 1234567890123456789012345678901234567890
  // ***1234.57-----hello----------hello

  std::cout << "\n--width 10 for num1 and num2 and hello left for all setfill varied------" << std::endl;
  ruler();
  std::cout << std::setw(10) << std::left << std::setfill('*') << num1
            << std::setw(10) << std::left << std::setfill('#') << num2
            << std::setw(10) << std::left << std::setfill('-') << hello
            << std::endl;
  // 12345678901234567890123456789012345678901234567890
  // 1234******1234.57###Hello-----
  
  return 0;
}

void ruler() {
  std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
}
