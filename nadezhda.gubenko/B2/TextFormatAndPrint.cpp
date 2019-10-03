#include <list>
#include <iostream>

#include "token.hpp"
#include "format.hpp"

const size_t lengthWordOrNum = 20;
const size_t lengthDash = 3;
const size_t HyphenAndSpace = 4;

void linePrint(std::ostream &output_, const std::list<token_t>& line)
{
  for (auto it = line.begin(); it != line.end(); it++)
  {
    output_ << (*it).str_;
  }
  output_ << "\n";
}

int getCurrentWidth(std::ostream &output_, std::list<token_t> &line)
{
  std::size_t currentWidth = 0;
  std::list<token_t> temp_line;
  while (!line.empty())
  {
    temp_line.push_front(line.back());
    currentWidth += line.back().str_.size();
    line.pop_back();
    if (temp_line.front().str_type_ == token_t::Word || temp_line.front().str_type_ == token_t::Num)
    {
      break;
    }
  }
  linePrint(output_, line);
  line = temp_line;
  return currentWidth;
}

void lineReform(std::ostream &output_, unsigned int line_width_, const std::list<token_t> &line)
{
  std::size_t curr_length = 0;
  std::list<token_t> ln;
  for (auto it = line.begin(); it != line.end(); it++)
  {
    switch ((*it).str_type_)
    {
      case token_t::Dash:
      {
        if (curr_length + HyphenAndSpace > line_width_)
        {
          curr_length = getCurrentWidth(output_, ln);
        }
        ln.push_back(token_t{ token_t::Space," " });
        ln.push_back(*it);
        curr_length += (*it).str_.length() + 1;
        break;
      }
      case token_t::Num:
      case token_t::Word:
      {
        if (curr_length + (*it).str_.length() + 1 > line_width_)
        {
          linePrint(output_, ln);
          ln.clear();
          curr_length = 0;
        }
        else if (!ln.empty())
        {
          ln.push_back(token_t{ token_t::Space," " });
          curr_length++;
        }
        ln.push_back(*it);
        curr_length += (*it).str_.length();
        break;
      }
      case token_t::Punct:
      {
        if (curr_length + 1 > line_width_)
        {
          curr_length = getCurrentWidth(output_, ln);
        }
        ln.push_back(*it);
        curr_length += (*it).str_.length();
        break;
      }
      case token_t::Space:
      {
        break;
      }
    }
  }
  if (!ln.empty())
  {
    linePrint(output_, ln);
  }
}

bool isCorrect(const std::list<token_t> &line)
{
  if (!line.empty() && (line.front().str_type_ != token_t::Word) && (line.front().str_type_ != token_t::Num))
  {
    return false;
  }
  for (auto it = line.begin(); it != line.end(); it++)
  {
    switch ((*it).str_type_)
    {
      case token_t::Word:
      case token_t::Num:
        if ((*it).str_.size() > lengthWordOrNum)
        {
          return false;
        }
        break;
      case token_t::Dash:
        if ((*it).str_.size() != lengthDash)
        {
          return false;
        }
        if (it != line.begin())
        {
          const token_t &prev = *std::prev(it);
          if ((prev.str_type_ == token_t::Dash) || ((prev.str_type_ == token_t::Punct) && (prev.str_ != ",")))
          {
            return false;
          }
        }
        break;
      case token_t::Punct:
        if (it != line.begin())
        {
          const token_t &prev = *std::prev(it);
          if ((prev.str_type_ == token_t::Dash) || (prev.str_type_ == token_t::Punct))
          {
            return false;
          }
        }
        break;
      case token_t::Space:
        break;
    }
  }
  return true;
}


