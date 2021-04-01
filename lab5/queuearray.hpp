#ifndef LAB5_QUEUEARRAY_HPP
#define LAB5_QUEUEARRAY_HPP

#include <iostream>
#include "exceptions.hpp"
#include "queue.hpp"

template <class T>
class QueueArray: public Queue<T>
{
public:
  explicit QueueArray(size_t size = 100);
  QueueArray(const QueueArray<T>& queueArray);
  ~QueueArray() override;

  T& head() const override;
  void enQueue(const T& elem) override;
  void deQueue() override;
  bool empty() const override;
private:
  T* array_;
  size_t size_;
  size_t tail_;
};

template <class T>
QueueArray<T>::QueueArray(size_t size):
  size_(size),
  tail_(0)
{
  try
  {
    array_ = new T[size_];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
}

template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& queueArray):
  size_(queueArray.size_),
  tail_(queueArray.tail_)
{
  if (size_ != 0)
  {
    delete[]array_;
  }
  try
  {
    array_ = new T[size_];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
  for (size_t i = 0; i < size_; ++i)
  {
    array_[i] = queueArray[i];
  }
}

template <class T>
QueueArray<T>::~QueueArray<T>()
{
  delete array_;
}

template <class T>
T& QueueArray<T>::head() const
{
  if (size_ == 0)
  {
    throw std::out_of_range("Queue is empty.");
  }
  return array_[0];
}

template <class T>
void QueueArray<T>::enQueue(const T& elem)
{
  if (tail_ + 1 == size_)
  {
    throw QueueOverflow();
  }
  array_[tail_++] = elem;
}

template <class T>
void QueueArray<T>::deQueue()
{
  if (empty())
  {
    throw QueueUnderflow();
  }
  for (size_t i = 0; i < tail_; ++i)
  {
    array_[i] = std::move(array_[i + 1]);
  }
  --tail_;
}

template <class T>
bool QueueArray<T>::empty() const
{
  return tail_ == 0;
}


#endif //LAB5_QUEUEARRAY_HPP
