#include <iostream>
#include <iomanip>

#include "Functor.hpp"

Functor::Functor() :
  max_(0),
  min_(0),
  mean_(0),
  positive_(0),
  negative_(0),
  oddSum_(0),
  evenSum_(0),
  firstEqualLast_(true),
  first_(0),
  last_(0),
  listCount_(0)
{}

void Functor::operator()(long long int num)
{
  if (listCount_ == 0)
  {
    first_ = num;
    max_ = num;
    min_ = num;
  }
  listCount_++;
  last_ = num;
  if (num > max_)
  {
    max_ = num;
  }
  if (num < min_)
  {
    min_ = num;
  }
  if (num > 0)
  {
    positive_++;
  }
  else if (num < 0)
  {
    negative_++;
  }
  if (num % 2 == 0)
  {
    evenSum_ += num;
  }
  else
  {
    oddSum_ += num;
  }
  if (first_ == last_)
  {
    firstEqualLast_ = true;
  }
  else
  {
    firstEqualLast_ = false;
  }
  mean_ = static_cast<double>(oddSum_ + evenSum_) / static_cast<double>(listCount_);
}

void Functor::getAll() const
{
  if (!listCount_)
  {
    std::cout << "No Data" << std::endl;
    return;
  }
  else
  {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Max: " << max_ << std::endl;
    std::cout << "Min: " << min_ << std::endl;
    std::cout << "Mean: " << mean_ << std::endl;
    std::cout << "Positive: " << positive_ << std::endl;
    std::cout << "Negative: " << negative_ << std::endl;
    std::cout << "Odd Sum: " << oddSum_ << std::endl;
    std::cout << "Even Sum: " << evenSum_ << std::endl;
    std::cout << "First/Last Equal: ";
    if (firstEqualLast_)
    {
      std::cout << "yes" << std::endl;
    }
    else
    {
      std::cout << "no" << std::endl;
    }
  }
}


long long int Functor::getMax() const
{
  return max_;
}

long long int Functor::getMin() const
{
  return min_;
}

double Functor::getMean() const
{
  return mean_;
}

unsigned int Functor::getPositive() const
{
  return positive_;
}

unsigned int Functor::getNegative() const
{
  return negative_;
}

long long int Functor::getOddSum() const
{
  return oddSum_;
}

long long int Functor::getEvenSum() const
{
  return evenSum_;
}

bool Functor::getFirstEqualLast() const
{
  return firstEqualLast_;
}

