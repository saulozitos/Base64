#include "base64.h"
#include <iostream>

int main()
{
    const std::string message = { "This is a menssage to be encoded!" };
    const std::string codedMessage = Base64::encode(message);

    std::cout << "Coded message: " << codedMessage << '\n';

    const std::string decodedMessage = Base64::decode(codedMessage);

    std::cout << "Decoded message: " << decodedMessage << '\n';
    return 0;
}
