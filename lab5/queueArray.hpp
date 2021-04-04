#ifndef LAB5_QUEUEARRAY_HPP
#define LAB5_QUEUEARRAY_HPP

#include "iostream"
#include "queue.hpp"
#include "exception.hpp"

template <class T>
class QueueArray : public Queue<T>
{
public:
  QueueArray(int size = 100);
  QueueArray(const QueueArray<T>& src);
  virtual ~QueueArray() { delete[] array_; }
  void enQueue (const T& value);
  const T& deQueue ();
  const T& print (std::ostream &out);
  bool isEmpty() { return head_ == tail_; }

private:
  T* array_;
  int head_ = 1;
  int tail_ = 1;
  int size_;
};

template <class T>
QueueArray<T>::QueueArray(int size)
{
  try
  {
    array_ = new T[size_ = size];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
  head_ = 1;
  tail_ = 1;
}

template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src)
{
  try
  {
    array_ = new T[size_ = src.size_];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
  head_ = src.head_;
  tail_ = src.tail_;
  for (int i = 0; i < size_; i++)
  {
    array_[i] = src.array_[i];
  }
}

template <class T>
void QueueArray<T>::enQueue (const T& value)
{
  if (head_ == tail_ + 1)
  {
    throw QueueOverflow();
  }
  tail_ += 1;
  array_[tail_] = value;
}

template <class T>
const T& QueueArray<T>::deQueue()
{
  if (head_ == tail_)
  {
    throw QueueUnderflow();
  }
  for (int i = 0; i <= tail_; i++)
  {
    array_[i] = array_[i+1];
  }
  --tail_;
}

template <class T>
const T& QueueArray<T>::print(std::ostream &out)
{
  for (int i = 2; i <= tail_; i++)
  {
    out << array_[i] << " ";
  }
}

#endif
