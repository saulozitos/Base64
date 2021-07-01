#pragma once

#include <string>

class Base64
{
public:
    Base64() = default;
    ~Base64() = default;

    std::string encode(const std::string &msg);
    std::string decode(const std::string &msg);

private:
    const std::string m_base64Chars{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
};
