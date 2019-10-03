#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

#include "algoritm.hpp"

int main()
{
  try
  {
    task();
  }
  catch (std::exception & e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}



