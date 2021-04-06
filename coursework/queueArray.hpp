#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

#include <iostream>
#include "queue.hpp"
#include "exceptionQueue.hpp"

template<class T>
class QueueArray final : public Queue<T>
{
  public:
  explicit QueueArray(int size);

  QueueArray(const QueueArray<T> &src) = delete;

  QueueArray(QueueArray<T> &&src) noexcept;
  QueueArray<T> &operator=(const QueueArray<T> &src) = delete;
  QueueArray<T> &operator=(QueueArray<T> &&src) noexcept;

  ~QueueArray() override;

  void enQueue(const T &e) override;

  T deQueue() override;

  bool isEmpty() const override
  { return (head_ == -1 && tail_ == -1 || head_ == tail_ + 1); }

  void print(std::ostream &out) const;


  private:
  T *array_;
  int head_ = -1;
  int tail_ = -1;
  int size_;


};

template<typename T>
QueueArray<T>::QueueArray(int size):
  size_(size),
  head_(-1),
  tail_(-1)
{
    if(size_<=0)
    {
      throw WrongQueueSize();
    }
  array_ = new T[size + 1];
}

template<typename T>
QueueArray<T>::QueueArray(QueueArray<T> &&src) noexcept
{
  head_ = src.head_;
  tail_ = src.tail_;
  array_ = src.array_;
  size_ = src.size_;
  src.size_ = 0;
  src.head_ = -1;
  src.tail_ = -1;
  src.array_ == nullptr;

}

template<typename T>
QueueArray<T> &QueueArray<T>::operator=(QueueArray<T> &&src) noexcept
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

template<typename T>
void QueueArray<T>::enQueue(const T &e)
{
  if (head_ == tail_ + 1)
  {
    throw QueueOverflow();
  }
  if (tail_ == size_ - 1 && head_ == 0)
  {
    throw QueueOverflow();
  }
  if (head_ == -1)
  {
    head_ = 0;
  }
  tail_ = (tail_ + 1) % size_;
  array_[tail_] = e;
}

template<typename T>
T QueueArray<T>::deQueue()
{
  if (this->isEmpty())
  {
    throw QueueUnderflow();
  }
  T element;
  element = array_[head_];
  if (head_ == tail_)
  {
    head_ = -1;
    tail_ = -1;
  } else
  {
    head_ = (head_ + 1) % size_;
  }
  return (element);
}

template<class T>
void QueueArray<T>::print(std::ostream &out) const
{
  if (head_ == tail_ && head_ != -1)
  {
    out << array_[head_];
  }
  if (head_ < tail_)
  {
    for (int i = head_; i <= tail_; i++)
    {
      out << array_[i] << " ";
    }
  }
  if (head_ > tail_)
  {
    int temp = head_;
    for (int i = temp; i < size_; i++)
    {
      out << array_[i] << " ";
    }
    temp = 0;
    for (int i = temp; i <= tail_; i++)
    {
      out << array_[i] << " ";
    }
  }
}

template<class T>
QueueArray<T>::~QueueArray()
{
  if (size_ != 0)
  {
    delete[] array_;
  }
}


#endif
