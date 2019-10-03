#ifndef B2_TOKEN_HPP
#define B2_TOKEN_HPP

#include <string>

struct token_t
{
  enum token_type
  {
    Word,
    Num,
    Space,
    Punct,
    Dash,
  };
  token_type str_type_;
  std::string str_;
};

#endif //B2_UNIT_HPP
