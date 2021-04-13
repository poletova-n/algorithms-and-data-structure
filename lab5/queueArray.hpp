#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

#include <iostream>
#include "queue.hpp"
#include "exceptions.hpp"

template <typename T>
class QueueArray final : public Queue<T>
{
public:
  explicit QueueArray(size_t size);
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src) noexcept;
  QueueArray<T>& operator= (QueueArray<T>&& src) noexcept;
  virtual ~QueueArray()
  {
    if(size_!=0) {
      delete[] array_;
    }
  }
  void enQueue(const T& e) override;
  T deQueue() override;
  void printQueue(std::ostream &out) const;
  bool isEmpty() const override
  {
    return (head_==-1 && tail_ == -1 || head_==tail_+1);
  }
private:
  T* array_;
  size_t head_ = -1;
  size_t tail_ = -1;
  size_t size_;
  void swap(QueueArray<T>& right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size) :
        size_(size), head_(-1), tail_(-1)
{
  try {
    array_ = new T[size + 1];
  }
  catch (...) {
    throw WrongQueueSize();
  }

}

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
  std::swap(array_, right.array_);
  std::swap(head_, right.head_);
  std::swap(tail_, right.tail_);
  std::swap(size_, right.size_);
}
template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src) noexcept
{
  try
  {
    head_ = src.head_;
    tail_ = src.tail_;
    array_ =src.array_;
    size_ = src.size_;
    src.size_ = 0;
    src.head_ = -1;
    src.tail_ = -1;
    src.array_ == nullptr;
  }
  catch (...)
  {
    throw WrongStackSize();
  }
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src) noexcept
{
  head_ = src.head_;
  tail_ = src.tail_;
  array_ = src.array_;
  size_ = src.size_;
  src.size_ = 0;
  src.head_ = -1;
  src.tail_ = -1;
  src.array_ == nullptr;
  return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
  if (head_ == tail_ + 1)
  {
    throw QueueOverflow();
  }
  if (tail_ == size_-1 && head_==0)
  {
    throw QueueOverflow();
  }
  if (head_ == -1)
  {
    head_ = 0;
  }
  if (tail_ == size_ - 1 && head_ != 0)
  {
    tail_ = 0;
    array_[tail_] = e;
  }
  else
  {
    tail_++;
    array_[tail_] = e;
  }
}

template <typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == -1)
  {
    throw QueueUnderflow();
  }

  T elem = array_[head_];
  if (head_ == tail_)
  {
    head_ = -1;
    tail_ = -1;
  }
  else if (tail_ == size_ - 1)
  {
    head_ = 0;
  }
  else
  {
    head_++;
  }
  return elem;
}
template<typename T>
void QueueArray<T>::printQueue(std::ostream& out) const
{
  if (head_ == tail_ && head_ ==-1)
  {
    out << "Queue is empty!\n";
    return;
  }
  if(tail_==head_ && head_!=-1)
  {
    out<<array_[head_];
  }
  if(tail_>head_)
  {
    for(int i=head_;i<=tail_;i++)
    {
      out<<array_[i]<<" ";
    }
  }
  if(tail_<head_)
  {
    for(int i=head_;i<size_;i++)
    {
      out<<array_[i]<<" ";
    }
    for(int i=0;i<=tail_;i++)
    {
      out<<array_[i]<<" ";
    }
  }
}
#endif
