#ifndef STACKS_STACKARRAY_H
#define STACKS_STACKARRAY_H

#include "stack.h"
#include "exception.h"

#include<iostream>

template <class T>
class StackArray : public Stack<T>
{
public:
  StackArray(int size = 20);
  StackArray(const StackArray<T>& src);
  ~StackArray() override;
  void push(const T& e) override;
  const T& pop() override;
  bool isEmpty() override;
  int getTop();
  const T& getElement(int n);

private:
  T* array_;
  int top_ = 0;
  int size_;
};

template <class T>
StackArray<T>::~StackArray() {
  delete[] array_;
}

template <class T>
StackArray<T>::StackArray(int size) {
  try {
    size_ = size;
    array_ = new T[size_];
  }
  catch (...) {
    throw WrongStackSize();
  }
  top_ = 0;
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) {
  try {
    size_ = src.size_;
    array_ = new T[size_];
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
void StackArray<T>::push(const T& element) {
  if (top_ == size_)
    throw StackOverflow();
  top_++;
  array_[top_] = element;
}

template <class T>
const T& StackArray<T>::pop() {
  if (top_ == 0)
    throw StackUnderflow();
  return array_[top_--];
}

template <class T>
bool StackArray<T>::isEmpty() {
  return top_ == 0;
}

template<class T>
int StackArray<T>::getTop() {
  return top_;
}

template<class T>
const T& StackArray<T>::getElement(int n) {
  return array_[n];
}

#endif //STACKS_STACKARRAY_H
