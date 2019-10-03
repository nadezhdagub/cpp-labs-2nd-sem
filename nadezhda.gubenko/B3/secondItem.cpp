#include <iostream>
#include <stdexcept>
#include <list>

#include "task.hpp"

void print(const std::list<int> & list)
{
  for (auto it1 = list.begin(), it2 = list.end(); it1 != it2--; it1++) {
    if (it1 == it2)
    {
      std::cout << *it1 << "\n";
      return;
    }
    std::cout << *it1 << " " << *it2 << " ";
  }
  std::cout << "\n";
}

void secondItem()  // переменные конст
{
  const size_t firstValue = 1;
  const size_t lastValue = 20;

  std::list<int> list;
  size_t n = 0;

  while (std::cin >> n)
  {
    if ((n < firstValue) || (n > lastValue))
    {
      throw std::invalid_argument("Numbers must be from 1 to 20");
    }
    list.push_back(n);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect input data;");
  }

  if (list.size() > lastValue)
  {
    throw std::invalid_argument("Quantity of elements must be less than 20;");
  }

  print(list);
}

