#include "base64.h"

Base64::Base64()
    : m_base64Chars("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012345"
                    "6789+/"),
      m_aux([this]() {
        std::array<int, 256> T{-1};
        for (int i = 0; i < m_base64Chars.size(); ++i) {
          T.at(m_base64Chars[i]) = i;
        }
        return T;
      }()) {}

std::string Base64::encode(const std::string &message) {

  std::string msg;
  int auxA = 0;
  int auxB = -6;

  for (const auto &c : message) {

    auxA = (auxA << 8) + c;
    auxB += 8;

    while (auxB >= 0) {
      const auto index = (auxA >> auxB) & 0x3F;
      const auto encodedChar = m_base64Chars[index];
      msg.push_back(encodedChar);
      auxB -= 6;
    }
  }

  if (auxB > -6) {
    const auto index = ((auxA << 8) >> (auxB + 8)) & 0x3F;
    const auto encodedChar = m_base64Chars[index];
    msg.push_back(encodedChar);
  }

  while (msg.size() % 4) {
    msg.push_back('=');
  }

  return msg;
}

std::string Base64::decode(const std::string &message) {

  std::string msg;
  int auxA = 0;
  int auxB = -8;

  for (const auto &c : message) {

    if (m_aux.at(c) == -1)
      break;

    auxA = (auxA << 6) + m_aux.at(c);
    auxB += 6;

    if (auxB >= 0) {
      const char decodedChar = static_cast<char>((auxA >> auxB) & 0xFF);
      msg.push_back(decodedChar);
      auxB -= 8;
    }
  }

  return msg;
}
