#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>

template<class T>
class Queue
{
public:
  virtual ~Queue() = default;
  virtual void enQueue(const T &element) = 0;
  virtual T deQueue() = 0;
  virtual bool isEmpty() const = 0;
  virtual void print(std::ostream &output) const = 0;
};

#endif
