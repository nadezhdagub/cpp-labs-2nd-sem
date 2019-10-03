#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <iterator>

#include "TextAnalize.hpp"
#include "token.hpp"


int main(int argc, char *argv[])
{
  unsigned int lnWidth = 40;

  try
  {
    if (argc != 1 && argc != 3)
    {
      throw std::invalid_argument("program have zero or 2 parametrs{empty|--line-width <size>}");
    }

    if (argc == 3)
    {
      if (strcmp(argv[1], "--line-width") != 0)
      {
        throw std::invalid_argument("first parametr must be --line-width");
      }

      lnWidth = atoi(argv[2]);
    }

    constexpr int maxWordSize = 20;
    constexpr int dashSize = 3;

    if (lnWidth <= (maxWordSize + dashSize + 1))
    {
      throw std::invalid_argument("size must be more than 24");
    }

    TextAnalize analyzer(std::cin);
    analyzer.analize();

    std::list<token_t> vec(analyzer.begin(), analyzer.end());

    if (!isCorrect(vec))
    {
      throw std::invalid_argument("Invalid input");
    }

    lineReform(std::cout, lnWidth, vec);
  }
  catch (const std::exception& err)
  {
    std::cerr << err.what() << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "Unknown exception\n";
    return 1;
  }

  return 0;
}
