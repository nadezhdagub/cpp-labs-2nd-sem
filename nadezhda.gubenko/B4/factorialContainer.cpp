#include "factorialContainer.hpp"

const size_t FactorialLastIndex = 11;
const size_t FactorialOf11 = 39916800;


detail::FactorialContainer::Iterator::Iterator(size_t index, size_t value)
{
  index_ = index;
  value_ = value;
}

const size_t * detail::FactorialContainer::Iterator::operator->() const
{
  return &value_;
}

const size_t & detail::FactorialContainer::Iterator::operator*() const
{
  return value_;
}

detail::FactorialContainer::Iterator detail::FactorialContainer::begin()
{
  return FactorialContainer::Iterator(1, 1);
}

detail::FactorialContainer::Iterator detail::FactorialContainer::end()
{
  return FactorialContainer::Iterator(FactorialLastIndex, FactorialOf11);
}

detail::FactorialContainer::Iterator & detail::FactorialContainer::Iterator::operator++()
{
  value_ *= ++index_;
  return *this;
}

detail::FactorialContainer::Iterator detail::FactorialContainer::Iterator::operator++(int)
{
  FactorialContainer::Iterator prev = *this;
  value_ *= ++index_;
  return prev;
}

detail::FactorialContainer::Iterator & detail::FactorialContainer::Iterator::operator--()
{
  value_ /= index_--;
  return *this;
}

detail::FactorialContainer::Iterator detail::FactorialContainer::Iterator::operator--(int)
{
  FactorialContainer::Iterator prev = *this;
  value_ /= index_--;
  return prev;
}

bool detail::FactorialContainer::Iterator::operator==(const detail::FactorialContainer::Iterator & other) const
{
  return (index_ == other.index_);
}

bool detail::FactorialContainer::Iterator::operator!=(const detail::FactorialContainer::Iterator & other) const
{
  return (!(other == *this));
}
