// Challenge - Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>
#include <string>

int main() {

  std::string secret_message, encrypted_message, decrypted_message; // automatic initialization of C++ Strings.

  std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  std::string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  std::cout << "Enter your secret message: ";
  std::getline(std::cin,secret_message); // get a line from cin and strore in secret_message.

  std::cout << "\nEncrypting message..." << std::endl;

  // Encryption
  for (auto letter: secret_message)
    // std::cout << alphabet << " " << letter << " " << alphabet.find(letter) << std::endl;
    if (isalpha(letter))
      encrypted_message += key.at(alphabet.find(letter)); //key[alphabet.find(letter)]; // finding the position of character in secret message in the key
    else
      encrypted_message += letter;

  // Alternate solution 
  // for (auto letter: secret_message){
  //   size_t position = alphabet.find(letter); 
  //   if (position != std::string::npos)  //std::string::npos - if character not in string
  //     encrypted_message += {key.at(position)};
  //   else
  //     encrypted_message += letter; 
  // }

  std::cout << "\nEncrypted message: " << encrypted_message << std::endl;

  std::cout << "\nDecrypting message..." << std::endl;

  // Decryption
  for (auto letter: encrypted_message)
    if (isalpha(letter))
      decrypted_message += alphabet.at(key.find(letter)); // alphabet[key.find(letter)];
    else
      decrypted_message += letter;

  std::cout << "\nDecrypted message: " << decrypted_message << std::endl;

  std::cout << std::endl;
  return 0;
}
