#ifndef WORKING_STACKARRAY_HPP
#define WORKING_STACKARRAY_HPP

#include <iostream>
#include <stdexcept>
#include "wrongstacksize.hpp"
#include "stackoverflow.hpp"
#include "stackunderflow.hpp"
#include "stack.hpp"

template<typename T>
class StackArray: public Stack<T>
{
public:
  explicit StackArray(size_t size = 50);
  ~StackArray() override;
  void push(const T& element) override;
  T& pop() override;
  bool isEmpty() const;

private:
  T* array_;
  size_t size_;
  size_t counter_;
};

template<typename T>
StackArray<T>::StackArray(size_t size):
  size_(size)
{
  if (size <= 0)
  {
    throw WrongStackSize();
  }
  array_ = new T[size_];
  counter_ = 0;
}

template<typename T>
StackArray<T>::~StackArray()
{
  delete[] array_;
};

template<typename T>
void StackArray<T>::push(const T& element)
{
  if (counter_ == size_)
  {
    throw StackOverflow();
  }
  array_[++counter_] = element;
}

template<typename T>
T& StackArray<T>::pop()
{
  if (counter_ == 0)
  {
    throw StackUnderflow();
  }
  return array_[counter_--];
}

template <typename T>
bool StackArray<T>::isEmpty() const
{
  return counter_ == 0;
}

#endif
