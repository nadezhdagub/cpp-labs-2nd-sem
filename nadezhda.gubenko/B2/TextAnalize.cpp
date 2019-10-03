#include <iostream>
#include <locale>

#include "TextAnalize.hpp"

TextAnalize::TextAnalize(std::istream &input) :
  input_(input)
{}

void TextAnalize::analize()
{
  while (input_)
  {
    inpText();
  }
}

void TextAnalize::inpText()
{
  char inp = input_.get();

  while (isspace(inp, std::locale()))
  {
    inp = input_.get();
  }

  if (isalpha(inp, std::locale()))
  {
    input_.unget();
    readWord();
  }
  else if (inp == '-')
  {
    if (input_.peek() == '-')
    {
      input_.unget();
      readDash();
    }
    else
    {
      input_.unget();
      readNumber();
    }
  }
  else if ((isdigit(inp, std::locale())) || (inp == '+'))
  {
    input_.unget();
    readNumber();
  }
  else if (ispunct(inp, std::locale()))
  {
    token_t phrase{token_t::Punct,  "" };
    phrase.str_.push_back(inp);
    text_.push_back(phrase);
  }
}

void TextAnalize::readWord()
{
  token_t phrase{ token_t::Word , "" };

  do
  {
    char inp = input_.get();
    phrase.str_.push_back(inp);
    if (inp == '-' && input_.peek() == '-')
    {
      phrase.str_.pop_back();
      input_.unget();
      break;
    }
  }

  while ((std::isalpha<char>(input_.peek(), std::locale())) || (input_.peek() == '-'));

  if (phrase.str_.size() > 20)
  {
    throw std::logic_error("Must be <= 20 symbols");
  }
  text_.push_back(phrase);
}

void TextAnalize::readDash()
{
  token_t phrase{token_t::Dash,  "" };
  while (input_.peek() == '-')
  {
    char inp = input_.get();
    phrase.str_.push_back(inp);
  }
  text_.push_back(phrase);
}

void TextAnalize::readNumber()
{
  token_t phrase{ token_t::Num,"" };

  char digit = std::use_facet<std::numpunct<char>>(std::locale()).decimal_point();
  bool was_digit = false;
  do
  {
    char inp = input_.get();
    if (inp == digit)
    {
      if (was_digit)
      {
        input_.unget();
        break;
      }
      was_digit = true;
    }
    phrase.str_.push_back(inp);
  }
  while ((std::isdigit<char>(input_.peek(), std::locale())) || ((input_.peek() == digit)));
  if (phrase.str_.size() > 20)
  {
    throw std::logic_error("Length of number must be <= 20 symbols");
  }
  text_.push_back(phrase);
}

std::list<token_t>::iterator TextAnalize::begin()
{
  return text_.begin();
}

std::list<token_t>::iterator TextAnalize::end()
{
  return text_.end();
}

