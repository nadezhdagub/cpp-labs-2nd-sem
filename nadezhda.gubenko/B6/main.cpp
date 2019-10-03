#include <iostream>
#include <string>

#include "task.hpp"
#include "shape.hpp"

int main(int argc, char *argv[])
{
  try
  {
    if (argc < 2)
    {
      std::cerr << "Invalid number of arguments" << std::endl;
      return 1;
    }
      switch (std::atoi(argv[1]))
      {
        case 1:
          {
            return detail::firstItem(std::cin, std::cout);
          }
        case 2:
          {
            return detail::secondItem(std::cin, std::cout);
          }
          default:
            std::cerr << "Invalid argument" << std::endl;
            return 1;
      }
  }
  catch (const std::ios_base::failure & e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
