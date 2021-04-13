#ifndef QUEUE_HPP
#define QUEUE_HPP

template <class T>
class Queue
{
public:
  virtual ~Queue() {};
  virtual void enQueue(const T& elem) = 0;
  virtual T deQueue() = 0;
  virtual bool isEmpty() = 0;
};

#endif
