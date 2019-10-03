#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

#include "task.hpp"
#include "queueWithPriority.hpp"

void firstItem()
{
  detail::QueueWithPriority<std::string> queue;
  std::string line(" ");

  while (std::getline(std::cin, line))
  {
    try
    {
      std::istringstream iss(line);

      std::string command;
      iss >> command;

      if (command == "add")
      {
        addCommand(iss, queue);
      }
      else if (command == "get")
      {
        getCommand(queue);
      }
      else if (command == "accelerate")
      {
        accelerateCommand(queue);
      }
      else
      {
        throw std::invalid_argument("<INVALID COMMAND>");
      }
    }
    catch (const std::exception& e)
    {
      std::cout << e.what() << "\n";
    }
  }
}

void addCommand(std::istringstream & iss, detail::QueueWithPriority<std::string> & queueWithPriority)
{
  std::string word;
  iss >> word;

  detail:: ElementPriority priority;

  if (word == "low")
  {
    priority = detail::LOW;
  }
  else if (word == "normal")
  {
    priority = detail::NORMAL;
  }
  else if (word == "high")
  {
    priority = detail::HIGH;
  }
  else
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }

  std::string element = "";
  iss.get();
  std::getline(iss, element);

  if (element.empty())
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }

  queueWithPriority.putElementToQueue(element, priority);
}

void getCommand(detail::QueueWithPriority<std::string> & queueWithPriority)
{
 // std::string element = "";

  queueWithPriority.getElementFromQueue() ;
}

void accelerateCommand(detail::QueueWithPriority<std::string> & queueWithPriority)
{
  queueWithPriority.accelerate();
}
