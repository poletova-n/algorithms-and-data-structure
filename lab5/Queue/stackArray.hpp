#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

#include "stack.hpp"
#include <iostream>
#include "exception.hpp"

template<class T>
class StackArray
  : public Stack<T>
{
public:
  explicit StackArray(int size) : size_(size)
  {
    if (size <= 0)
      throw StackWrongSize();
    top_ = 0;
    array_ = new T[size];
  };

  StackArray(const StackArray<T> &src) = delete;

  StackArray(StackArray<T> &&src) noexcept;

  StackArray &operator=(const StackArray<T> &src) = delete;

  StackArray &operator=(StackArray<T> &&src) noexcept;

  ~StackArray();
  //Добавление элемент в стэк
  void push(const T &src) override;

//Проверка на пустоту
  bool isEmpty() override;
  // Удаление и возвращение верхнего элемента.
  T pop() override;
// возвращение верхнего элемента без его удаления
  const T &top() override;
//возвращение top_
  int getTop();
//Вывод стэка
  void outAll();
  size_t getSize();
  StackArray rValue();

private:
// size задает размер стека "по умолчанию"
  T *array_;
  std::size_t top_{};
  std::size_t size_{};

};

#endif

template<class T>
void StackArray<T>::push(const T &src)
{
  if (top_ == size_)
    throw StackOverFlow();
  top_++;
  array_[top_] = src;
}

template<class T>
T StackArray<T>::pop()
{
  if (top_ == 0)
    throw StackUnderFlow();
  return array_[top_--];
}

template<class T>
bool StackArray<T>::isEmpty()
{
  if (this->top_ == 0)
    return true;
  return false;
}

template<class T>
void StackArray<T>::outAll()
{
  for (int i = 1; i <= top_; i++)

    std::cout << array_[i] << " ";

}

template<class T>
const T &StackArray<T>::top()
{
  if (top_ == 0)
    throw StackUnderFlow();
  return array_[top_];
}

template<class T>
StackArray<T>::~StackArray()
{
  delete[] array_;
}

template<class T>
int StackArray<T>::getTop()
{
  return top_;
}

template<class T>
StackArray<T>::StackArray(StackArray<T> &&src) noexcept
{
  this->top_ = src.top_;
  this->size_ = src.size_;
  this->array_ = src.array_;
  src.array_ = nullptr;
  src.top_ = 0;
  src.size_ = 0;
}

template<class T>
StackArray<T> &StackArray<T>::operator=(StackArray<T> &&src) noexcept
{
  this->top_ = src.top_;
  this->size_ = src.size_;
  this->array_ = src.array_;
  src.array_ = nullptr;
  src.top_ = 0;
  src.size_ = 0;
  return *this;
}

template<class T>
StackArray<T> StackArray<T>::rValue()
{
  return (std::move(*this));
}
template<class T>
size_t StackArray<T>::getSize()
{
  return size_;
}


