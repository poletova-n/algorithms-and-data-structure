#ifndef LAB2_STACKARRAY_HPP
#define LAB2_STACKARRAY_HPP

#include "exception.hpp"
#include "stack.hpp"

template <class T>
class StackArray : public Stack<T>
{
public:
    StackArray(int size = 5);
    StackArray(const StackArray<T>& src);
    virtual ~StackArray() { delete[] array_; }
    void push(const T& e);
    const T& pop();
    T getTop();
    bool isEmpty() { return top_ == 0; }
private:
    T* array_;
    int top_ = 0;
    int size_;
};
template <class T>
StackArray<T>::StackArray(int size) {
  try {
    array_ = new T[size_ = size];
  }
  catch (...) {
    throw WrongStackSize();
  }
  top_ = 0;
}

template<class T>
T StackArray<T>::getTop()
{
  return array_[top_];
}
template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) {
  try {
    array_ = new T[size_ = src.size_];
  }
  catch (...) {
    throw WrongStackSize();
  }
  for (int i = 0; i < src.top_; i++) {
    array_[i] = src.array_[i];
  }
  top_ = src.top_;
}
template <class T>
void StackArray<T>::push(const T& e)
{
  if (top_ == size_)
    throw StackOverflow();
  top_++;
  array_[top_] = e;
}
template <class T>
const T& StackArray<T>::pop()
{
  if (top_ == 0)
    throw StackUnderflow();
  return array_[top_--];
}

#endif
