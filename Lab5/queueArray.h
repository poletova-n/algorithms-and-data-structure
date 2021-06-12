#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include "queue.h"
#include "queueException.h"

template <typename T>
class QueueArray : public Queue<T>
{
public:
  explicit QueueArray(size_t size);
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src) noexcept;
  QueueArray<T>& operator= (const QueueArray<T>& src) = delete;
  QueueArray<T>& operator= (QueueArray<T>&& src) noexcept;
  ~QueueArray() override { delete[] array_; }
  void enQueue(const T& e) override;
  T deQueue() override;
  bool isEmpty() const override;
  void printQueue() const;

private:
private:
  T* array_;         // массив элементов очереди
  size_t head_ = 1;  // Очередь пуста, если  head[Q] = tail[Q].
  size_t tail_ = 1;  // Первоначально: head[Q] = tail[Q] = 1;
  size_t size_;      // размер очереди
};

template<typename T>
QueueArray<T>::QueueArray(size_t size) :
  size_(size), head_(1), tail_(1)
{
  try
  {
    array_ = new T[size + 1];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
}

template<typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src) noexcept
{
  head_ = src.head_;
  tail_ = src.tail_;
  array_ = src.array_;
  size_ = src.size_;

  src.array_ = nullptr;
  src.size_ = 0;
}

template<typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src) noexcept
{
  head_ = src.head_;
  tail_ = src.tail_;
  array_ = src.array_;
  size_ = src.size_;

  src.array_ = nullptr;
  src.size_ = 0;

  return *this;
}

template<typename T>
void QueueArray<T>::enQueue(const T& e)
{
  if (size_ + 1 == tail_)
  {
    throw QueueOverflow();
  }

  array_[tail_] = e;
  tail_++;
}

template<typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
  {
    throw QueueUnderflow();
  }

  T deleteTemp = array_[1];

  for (size_t i = 0; i < tail_ - 1; i++)
  {
    array_[i] = array_[i + 1];
  }

  tail_--;
  return deleteTemp;
}

template<typename T>
void QueueArray<T>::printQueue() const
{
  if (isEmpty())
  {
    std::cout << "Queue is empty\n";
  }
  else
  {
    std::cout << "Queue ";
    for (size_t i = head_; i < tail_; i++)
    {
      std::cout << array_[i] << " ";
    }
  }
}

template<typename T>
bool QueueArray<T>::isEmpty() const
{
  return head_ == tail_;
}

#endif
