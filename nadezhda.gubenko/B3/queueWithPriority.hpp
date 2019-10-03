#ifndef B3_QUEUEWITHPRIORITY_HPP
#define B3_QUEUEWITHPRIORITY_HPP

#include <iostream>
#include <stdexcept>
#include <list>
#include <memory>

namespace detail
{
  typedef enum
  {
    LOW,
    NORMAL,
    HIGH
  } ElementPriority;

  template<typename QueueElement>
  class QueueWithPriority
  {
  public:
    QueueWithPriority() = default;
    ~QueueWithPriority() = default;

    void putElementToQueue(const QueueElement &element, ElementPriority priority);
    std::unique_ptr<QueueElement>  getElementFromQueue();
    void accelerate();
    bool isEmpty() const;

  private:
    std::list<QueueElement> queue_[3];
  };
}

template <typename QueueElement>
void detail::QueueWithPriority<QueueElement>::putElementToQueue(const QueueElement & element, ElementPriority priority)
{
  queue_[priority].push_back(element);
}


template <typename QueueElement>
std::unique_ptr<QueueElement> detail::QueueWithPriority<QueueElement>::getElementFromQueue()
{
  if (isEmpty())
  {
    throw std::invalid_argument("Queue is empty");
  }

  std::unique_ptr<QueueElement> ptr;
  for (int i = 2; i >= 0; i--)
  {
    if (!queue_[i].empty())
    {
      ptr = std::unique_ptr<QueueElement>(new QueueElement(queue_[i].front()));
      queue_[i].pop_front();
      break;
    }
  }

  return ptr;
}


template <typename QueueElement>
void detail::QueueWithPriority<QueueElement>::accelerate()
{
  queue_[2].splice(queue_[2].end(), queue_[0], queue_[0].begin(), queue_[0].end());}

template <typename QueueElement>
bool detail::QueueWithPriority<QueueElement>::isEmpty() const
{
  return (queue_[0].empty() && queue_[1].empty() && queue_[2].empty());
}

#endif //B3_QUEUEWITHPRIORITY_HPP
