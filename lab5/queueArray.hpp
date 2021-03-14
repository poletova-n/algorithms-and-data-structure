#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

#include <iostream>

#include "queueOverflow.hpp"
#include "queueUnderflow.hpp"
#include "wrongQueueSize.hpp"
#include "queue.hpp"

template<class T>
class QueueArray final: public Queue<T>
{
public:
  QueueArray(size_t size = 5);
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src);
  QueueArray<T>& operator=(const QueueArray<T>& src) = delete;
  QueueArray<T>& operator=(QueueArray<T>&& src);
  ~QueueArray() override;
  void enQueue(const T& data) override;
  const T& deQueue() override;
  bool isEmpty() const override;

private:
  T* array_;
  size_t front_;
  size_t end_;
  size_t size_;
};

template<class T>
QueueArray<T>::QueueArray(size_t size) :
  front_(1),
  end_(1),
  size_(size)
{
  try {
    array_ = new T[size + 1];
  }
  catch (...) {
    throw WrongQueueSize();
  }
}

template<typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src) :
  array_(src.array_),
  front_(src.front_),
  end_(src.end_),
  size_(src.size_)
{
  src.size_ = 0;
  src.front_ = 0;
  src.end_ = 0;
  src.array_ = nullptr;

  std::cout << "Move constructor!\n";
}

template<typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
  if (src == *this)
    return *this;

  array_(src.array_);
  front_ = src.front_;
  end_ = src.end_;
  size_ = src.size_;

  src.size_ = 0;
  src.front_ = 0;
  src.end_ = 0;
  src.array_ = nullptr;

  std::cout << "Move assignment!\n";
}

template <typename T>
QueueArray<T>::~QueueArray()
{
  delete[] array_;
}

template<typename T>
void QueueArray<T>::enQueue(const T& data)
{
  if (front_ == end_ + 1) {
    throw QueueOverflow();
  }
  array_[end_++] = data;
  end_ %= size_;
}

template<typename T>
const T& QueueArray<T>::deQueue()
{
  if (front_ == end_) {
    throw QueueUnderflow();
  }
  size_t tempIndex = front_;
  front_++;
  front_ %= size_;
  return array_[tempIndex];
}

template<typename T>
bool QueueArray<T>::isEmpty() const
{
  return front_ == end_;
}

#endif
