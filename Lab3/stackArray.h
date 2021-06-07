#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "stack.h"
#include "wrongStackSize.h"
#include "stackOverflow.h"
#include "stackUnderflow.h"

template <class T>
class StackArray : public Stack<T>
{
public:
  StackArray(int size = 100);
  StackArray(const StackArray<T>& src);
  ~StackArray() override;

  void push(const T& e) override;
  T pop() override;
  T top();
  [[nodiscard]] bool isEmpty() const override;

private:
  T* array_;
  int top_ = 0;
  int size_;
};

template <class T>
StackArray<T>::StackArray(int size)
{
  if (size <= 0)
  {
    throw WrongStackSize();
  }

  array_ = new T[size_ = size];
  top_ = 0;
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& src)
{
  array_ = new T[size_ = src.size_];

  for (int i = 0; i < src.top_; i++)
  {
    array_[i] = src.array_[i];
  }

  top_ = src.top_;
}

template<class T>
StackArray<T>::~StackArray()
{
  delete[] array_;
}

template <class T>
void StackArray<T>::push(const T& e)
{
  if (top_ == size_)
  {
    throw StackOverflow();
  }

  top_++;
  array_[top_] = e;
}

template <class T>
T StackArray<T>::pop()
{
  if (top_ == 0)
  {
    throw StackUnderflow();
  }

  return array_[top_--];
}

template <class T>
bool StackArray<T>::isEmpty() const
{
  return top_ == 0;
}

template<class T>
T StackArray<T>::top()
{
  return array_[top_];
}

#endif
