#include <iostream>

#include "task.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of arguments";
    return 1;
  }

  try
  {
    int task = std::atoi(argv[1]);
    switch (task)
    {
      case 1:
        firstItem(std::cin, std::cout);
        break;
      case 2:
        secondItem(std::cin, std::cout);
        break;
      default:
        std::cerr << "Invalid argument";
        return 1;
        break;
    }
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what();
    return 1;
  }

  return 0;
}
