#ifndef STACK_ARRAY_
#define STACK_ARRAY_

#include "stack.h"
#include "wrongStackSize.h"
#include "stackOverflow.h"
#include "stackUnderflow.h"

template <class T>
class StackArray : public Stack<T>
{
public:
  StackArray(size_t size = 100); // size задает размер стека "по умолчанию"
  StackArray(const StackArray<T>& src); // = delete;
  StackArray(StackArray<T>&& src); 
  StackArray <T>& operator=(const StackArray<T>& src); // = delete;
  StackArray <T>& operator=(StackArray<T>&& src);
  ~StackArray(); //{ delete[] array_; }
  void push(const T& e);
  T pop();
  const T& top();
  bool isEmpty(); // { return top_ == 0; }
private:
  T* array_; // массив элементов стека: !!! array_[0] – не используется, top_ от 1 до size_
  size_t top_; // вершина стека, элемент занесенный в стек последним
  size_t size_; // размер стека
  void swap(StackArray<T>& src);
};

template <class T>
StackArray<T>::StackArray(size_t size) :
  size_(size),
  top_(0)
{ // !!! array_[0] – не используется, top_ от 1 до size_
  try {
    array_ = new T[size + 1]; // пытаемся заказать память под элементы стека...
  }
  catch (...) { // если что-то случилось (например, размер слишком большой
    throw WrongStackSize(); // или отрицательный) - возникает исключительная ситуация
  }
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) :
  size_(src.size_),
  top_(src.top_)
{
  try {// !!! array_[0] – не используется, top_ от 1 до size_
    array_ = new T[src.size_ + 1];
  }
  catch (...) {
    throw WrongStackSize();
  }
  // копирование массива
  for (size_t i = 1; i < src.top_; i++) {
    array_[i] = src.array_[i];
  }
}

template<class T>
StackArray<T>::StackArray(StackArray<T>&& src)
{
  size_ = src.size_;
  top_ = src.top_;
  try 
  {// !!! array_[0] – не используется, top_ от 1 до size_
    array_ = new T[src.size_ + 1];
  }
  catch (...) {
    throw WrongStackSize();
  }
  // копирование массива
  for (size_t i = 1; i < src.top_; i++) {
    array_[i] = src.array_[i];
  }
}

template<class T>
StackArray <T>& StackArray<T>::operator=(const StackArray<T>& src)
{
  size_ = src.size_;
  top_ = src.top_;
  for (size_t i = 0; i < src.top_; i++)
  {
    array_[i] = src.array_[i];
  }
  return *this;
}

template<class T>
StackArray <T>& StackArray<T>::operator=(StackArray<T>&& src)
{
  size_ = src.size_;
  top = src.top_;
  for (size_t i = 0; i < src.top_; i++)
  {
    array_[i] = src.array_[i];
  }

  return *this;
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
    throw StackOverflow(); // нет места для нового элемента
  }
  array_[++top_] = e; // занесение элемента в стек
}

template<class T>
T StackArray<T>::pop()
{
  if (top_ == 0) 
  {
    throw StackUnderflow(); // стек пуст
  }
  return array_[top_--]; // Элемент физически остается в стеке, но больше "не доступен"
}

template<class T>const T& StackArray<T>::top()
{
  return array_[top_];
}

template<class T>
bool StackArray<T>::isEmpty()
{
  return (top_ == 0);
}

template <class T>
void StackArray<T> ::swap(StackArray<T>& src)
{
  std::swap(array_, src.array_); // (this->array_, src.array_)
  std::swap(top_, src.top_);
  std::swap(size_, src.size_);
}
#endif 
