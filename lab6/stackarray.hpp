#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

#include <iostream>
#include "exception.hpp"
#include "stack.hpp"

template <class T>
class StackArray : public Stack<T>
{
private:
  size_t size_;
  T* array_;
  unsigned int pos_;
public:
  StackArray(const size_t size);
  ~StackArray();

  T pop() override;
  const T& top() override;
  void push(const T& element) override;
  bool isEmpty() override;
  int getPos();

  template <class T2>
  friend std::ostream& operator<<(std::ostream& stream, const StackArray<T2>& arr);
};

template <class T>
StackArray<T>::StackArray(const size_t size)
{
  if (size <= 0)
  {
    throw WrongStackSize();
  }
  this->size_ = size;
  this->array_ = new T[size + 1];
  this->pos_ = 0;
}

template <class T>
StackArray<T>::~StackArray()
{
  delete[] array_;
}

template <class T>
T StackArray<T>::pop()
{
  if (pos_ <= 0)
  {
    throw StackUnderFlow();
  }
  return array_[pos_--];
}

template <class T>
void StackArray<T>::push(const T& element)
{
  if (pos_ >= size_)
  {
    throw StackOverFlow();
  }
  array_[++pos_] = element;
}

template <class T>
const T& StackArray<T>::top()
{
  return array_[pos_];
}

template <class T>
int StackArray<T>::getPos()
{
  return pos_;
}

template <class T>
std::ostream& operator<<(std::ostream& stream, const StackArray<T>& arr)
{
  for (size_t i = 1; i <= arr.size_; i++)
  {
    stream << arr.array_[i] << " ";
  }
  stream << "\n";
  return stream;
}

template <class T>
bool StackArray<T>::isEmpty()
{
  return (pos_ == 0);
}

#endif