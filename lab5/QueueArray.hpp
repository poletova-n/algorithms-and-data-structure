#ifndef QUEUEARRAY
#define QUEUEARRAY
#include "Queue.hpp"
#include "WrongQueueSize.hpp"
#include "QueueOverflow.hpp"
#include "QueueUnderflow.hpp"

template <typename T>
class QueueArray final : public Queue<T>
{
public:
  explicit QueueArray(size_t size = 100);
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src) noexcept ;

  QueueArray<T>& operator= (QueueArray<T>& src) = delete;
  QueueArray<T>& operator= (QueueArray<T>&& src) noexcept ;

  virtual ~QueueArray()
  { delete[] array_; }

  void enQueue(const T& e) override;
  T deQueue() override;
  bool isEmpty() const override { return head_ == tail_; }


private:
  T* array_;
  size_t head_ = 1;
  size_t tail_ = 1;
  size_t size_{};
  void swap(QueueArray<T> &right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size) :
size_(size),
head_ (1),
tail_ (1)
{
    array_ = new T[size + 1];
}

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
  std::swap(*this->array_, right.array_);
  std::swap(*this->array_,  right.head_);
  std::swap(*this->array_,  right.tail_);
  std::swap(*this->array_,  right.size_);

}
template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src) noexcept
{
  this->swap(src);
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src) noexcept
{
  this->swap(src);
  return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
  if (head_ == tail_ + 1)
    throw QueueOverflow();
  if(isEmpty())
  {
    array_[1] = e;
    tail_++;
  }
  else
  {
    array_[tail_] = e;
    tail_++;
  }
}

template <typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
    throw QueueUnderflow();
  T tmp = array_[1];
  for(int i = 1; i < tail_ - 1; i++)
  {
    array_[i] = array_ [i+1];
  }
  tail_--;
  return tmp;
}
#endif
