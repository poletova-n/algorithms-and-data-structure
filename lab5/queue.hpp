#ifndef LAB5_QUEUE_HPP
#define LAB5_QUEUE_HPP

template <class T>
class Queue
{
public:
  virtual ~Queue() = default;
  virtual T& head() const = 0;
  virtual void enQueue(const T& elem) = 0;
  virtual void deQueue() = 0;
  virtual bool empty() const = 0;
};


#endif //LAB5_QUEUE_HPP
