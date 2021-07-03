#pragma once

#include <string>

class Base64 {
public:
    Base64() = default;
    ~Base64() = default;

    static std::string encode(const std::string& msg);
    static std::string decode(const std::string& msg);
};
