#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "iostream"
template <class T>
class Queue
{
public:
  virtual ~Queue() = default;
  virtual void enQueue(const T& e) = 0;
  virtual T deQueue() = 0;
  virtual bool isEmpty() const = 0;
};
#endif
