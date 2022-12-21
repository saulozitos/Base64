#include "base64.h"
#include <iostream>

int main() {

  Base64 base64;
  const std::string message{"This is a menssage to be encoded!"};
  const std::string codedMessage = base64.encode(message);

  std::cout << "Coded message: " << codedMessage << '\n';

  const std::string decodedMessage = base64.decode(codedMessage);

  std::cout << "Decoded message: " << decodedMessage << '\n';
  return 0;
}
