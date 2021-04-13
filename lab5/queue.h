#ifndef LAB5_QUEUE_H
#define LAB5_QUEUE_H

#include <exception>

class QueueOverflow: public std::exception
{
public:
  QueueOverflow() : reason_("Queue Overflow") { }
  const char* what() const override { return reason_; }
private:
  const char* reason_;
};

class QueueUnderflow: public std::exception
{
public:
  QueueUnderflow() : reason_("Queue Underflow") { }
  const char* what() const override { return reason_; }
private:
  const char* reason_;
};

template <class T>
class Queue
{
public:
  virtual ~Queue() {}

  virtual void enQueue(const T& e) = 0;

  virtual T deQueue() = 0;

  virtual bool isEmpty() const = 0;
};

class WrongQueueSize : public std::exception
{
public:
  WrongQueueSize() : reason_("Wrong Queue size") { }
  const char* what() const override { return reason_; }
private:
  const char* reason_;
};

template <typename T>
class QueueArray final : public Queue<T>
{
public:
  QueueArray(size_t size);
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src);

  QueueArray<T>& operator= (const QueueArray<T>& src) = delete;
  QueueArray<T>& operator= (QueueArray<T>&& src);

  virtual ~QueueArray() override { delete[] array_; }

  void enQueue(const T& e) override;
  T deQueue() override;
  bool isEmpty() const override { return head_ == tail_; }

private:
  T* array_;
  size_t head_ = 1;
  size_t tail_ = 1;
  size_t size_;
  void swap(QueueArray<T> &right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size):
        size_(size), head_ (1), tail_ (1)
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

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
  std::swap(array_, right.array_);
  std::swap(head_,  right.head_);
  std::swap(tail_,  right.tail_);
  std::swap(size_,  right.size_);

}
template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src)
{
  swap(src);
  src.array_ = nullptr;
  src.head_ = 1;
  src.tail_ = 1;
  src.size_ = 0;
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
  swap(src);
  src.array_ = nullptr;
  src.head_ = 1;
  src.tail_ = 1;
  src.size_ = 0;
  return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
  if (head_ == tail_ + 1 || (size_ == tail_ + 1 && head_ == 1))
  {
    throw QueueOverflow();
  }
  array_[tail_++] = e;
  if (tail_ == size_)
  {
    tail_ = 1;
  }
}

template <typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
  {
    throw QueueUnderflow();
  }
  head_++;
  if (head_ == size_)
  {
    head_ = 1;
    return array_[size_ - 1];
  }
  return array_[head_ - 1];
}

#endif
