#ifndef B2_FORMAT_HPP
#define B2_FORMAT_HPP

#include <iostream>
#include <list>

#include "token.hpp"

void lineReform(std::ostream &output_, unsigned int line_width_, const std::list<token_t> &line); // разные файлы и поменять названия
bool isCorrect(const std::list<token_t> &line);

#endif //B2_FORMAT_HPP
