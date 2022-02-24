/*
  continue & break

  This example we could set of flag to done and handle the done Boolean in the loop condition.
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main (){

  vector <int> values {1,2,-1,3,-1,-99,7,8,10}; // This data is comming from a device/sensor and occasionally we get noise in the data.
  // -1 represents noise & we dont want to process the noise and we want to ignore it.
  // -99 stop signal, we need to stop processing when we get to stop signal.

  for (auto val: values)
    if (val == -99)
      break; // break out of the loop as stop signal
    else if (val == -1) // noise case
      continue; //This stops the iteration and control goes back to the beginning of the loop for the next iteration.
    else
      cout << val << endl; // process data

  return 0;
}
