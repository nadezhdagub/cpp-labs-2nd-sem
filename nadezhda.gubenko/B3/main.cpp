#include<iostream>

#include"queueWithPriority.hpp"
#include"task.hpp"

int main(int argc, char *argv[])
{
  try {
    if (argc != 2) {
      std::cerr << "Invalid number of parameters";
      return 1;
    }
    if (std::stoi(argv[1]) == 1)
    {
      firstItem();
    } else if (std::stoi(argv[1]) == 2)
    {
      secondItem();
    } else {
      std::cerr << "Invalid number of task";
      return 1;
    }
  }
  catch (const std::exception &err)
  {
    std::cerr << err.what();
    return 1;
  }
  return 0;
}
