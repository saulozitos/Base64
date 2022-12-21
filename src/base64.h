#pragma once

#include <array>
#include <string>

class Base64 {
public:
  Base64();
  ~Base64() = default;

  std::string encode(const std::string &message);
  std::string decode(const std::string &message);

private:
  const std::string m_base64Chars;
  const std::array<int, 256> m_aux;
};
