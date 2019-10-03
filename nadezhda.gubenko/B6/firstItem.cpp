#include <iostream>
#include <string>
#include <iterator>
#include <set>
#include <algorithm>

#include "task.hpp"

int detail::firstItem(std::istream & in, std::ostream & out)
{
  std::set<std::string> words;

  std::copy(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>(),
            std::inserter(words, words.begin()));
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(out, "\n"));

  return 0;
}
