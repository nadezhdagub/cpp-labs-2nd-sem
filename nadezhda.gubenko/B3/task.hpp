#ifndef B3_TASK_HPP
#define B3_TASK_HPP

#include <list>
#include <iostream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "queueWithPriority.hpp"

void firstItem();
void addCommand(std::istringstream & iss, detail::QueueWithPriority<std::string> & queueWithPriority);
void getCommand(detail::QueueWithPriority<std::string> & queueWithPriority);
void accelerateCommand(detail::QueueWithPriority<std::string> & queueWithPriority);

void secondItem();
void print(std::list<int>::iterator leftPos, std::list<int>::iterator rightPos, std::list<int>::iterator begin);

#endif //B3_TASK_HPP
