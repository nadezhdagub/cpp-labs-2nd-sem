#include <iostream>
#include <algorithm>

#include "tasks.hpp"
#include "factorialContainer.hpp"

void detail::secondItem()
{
  detail::FactorialContainer container;

  std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

