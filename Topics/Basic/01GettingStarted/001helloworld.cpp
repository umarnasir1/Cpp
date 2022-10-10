#include <iostream> // input, output libraries for e.g., cout

int main() {
  std::cout << "Hellow World!!" << std::endl; //endl will flush the buffers and will move the cursor to the next line. If stream is buffered, it may not get written to the console until it is flushed
  return 0;
}