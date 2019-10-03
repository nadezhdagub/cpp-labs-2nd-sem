#include <iostream>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>

#include "Functor.hpp"

int main()
{
  Functor functor = std::for_each(std::istream_iterator<int>(std::cin),
                                        std::istream_iterator<int>(), Functor());

  if (!std::cin.eof())
  {
    std::cerr << "Invalid input!" << std::endl;
    return 1;
  }

  functor << std::cout;
  return 0;
}

