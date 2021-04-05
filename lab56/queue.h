#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
  virtual ~Queue() {};
  virtual void enQueue(const T& e) = 0; 
  virtual const T& deQueue() = 0;
  virtual bool isEmpty() = 0;
};
#endif
