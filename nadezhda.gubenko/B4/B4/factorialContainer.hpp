#ifndef B4_FACTORIALCONTAINER_HPP
#define B4_FACTORIALCONTAINER_HPP

#include <iterator>

namespace detail
{
  class FactorialContainer
  {
  public:
    class Iterator;

    FactorialContainer() = default;

    Iterator begin();

    Iterator end();
  };

  class FactorialContainer::Iterator : public std::iterator<std::bidirectional_iterator_tag, size_t>
  {
  public:
    Iterator(size_t id, size_t value);

    Iterator(const Iterator &other) = default;

    const size_t *operator->() const;

    const size_t &operator*() const;

    Iterator &operator++();

    Iterator operator++(int);

    Iterator &operator--();

    Iterator operator--(int);

    Iterator &operator=(const Iterator &object) = default;

    bool operator==(const Iterator &other) const;

    bool operator!=(const Iterator &other) const;

  private:
    size_t index_;
    size_t value_;
  };
}

#endif //B4_FACTORIALCONTAINER_HPP
