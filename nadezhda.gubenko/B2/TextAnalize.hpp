#ifndef B2_TEXTANALIZE_HPP
#define B2_TEXTANALIZE_HPP

#include <iostream>
#include <list>

#include "token.hpp"
#include "format.hpp"

class TextAnalize
{
  public:
  TextAnalize(std::istream &input);
  void analize();
  std::list<token_t>::iterator begin();
  std::list<token_t>::iterator end();

  private:
  std::istream &input_;
  std::list<token_t> text_;

  void inpText();
  void readWord();
  void readDash();
  void readNumber();
};

#endif //B2_TEXTANALIZE_HPP
