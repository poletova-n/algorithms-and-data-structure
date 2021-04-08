#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "list.hpp"
#include "exceptionArray.hpp"

template<class T>
class Array
{
  public:
  Array();
  Array(const Array<T>&src) =delete;
  Array(Array<T>&&src)=delete;
  Array &operator=(const Array<T> &src) = delete;

  Array &operator=(Array<T> &&src) = delete;
  ~Array();
  T &operator[](int index);

  void pushBack(const T &element);

  void deleteItem(const int &index);
  void print();
  bool isEmpty();

  private:
  int size_;
  T *head_;
};

template<class T>
Array<T>::Array()
{
  size_ = 0;
  head_ = nullptr;
}


template<class T>
T &Array<T>::operator[](int index)
{
  return head_[index];
}




template<class T>
void Array<T>::pushBack(const T &element)
{
  T *temp = new T[size_];
  for (int i = 0; i < size_; i++)
  {
    temp[i] = head_[i];
  }
  if (size_ != 0)
  {
    delete[] head_;
  }
  size_++;
  head_ = new T[size_];
  for (int i = 0; i < size_ - 1; i++)
  {
    head_[i] = temp[i];
  }
  head_[size_ - 1] = element;

  delete[]temp;
}

template<class T>
void Array<T>::deleteItem(const int &index)
{
  if(isEmpty())
  {
    throw ArrayUnderflow();
  }
  T *temp1 = new T[size_ - 1];
  int j = 0;
  for (int i = 0; i < size_ - 1; i++)
  {
    if (i != index)
    {
      temp1[j] = head_[i];
      j++;
    }
  }
  if (size_ - 1 != index)
  {
    temp1[size_ - 2] = head_[size_ - 1];
  }

  delete[]head_;
  size_--;
  head_ = new T[size_];
  for (int i = 0; i < size_; i++)
  {
    head_[i] = temp1[i];
  }

  delete[]temp1;
}

template<class T>
void Array<T>::print()
{
  for (int i = 0; i < size_; i++)
  {
    std::cout << i << ": ";
    head_[i].print();
    std::cout << "\n";
  }
}

template<class T>
Array<T>::~Array()
{
  if (size_ != 0)
  {
    delete[]head_;
    head_ = nullptr;
    size_ = 0;
  }
}
template<class T>
bool Array<T>::isEmpty()
{
  return (size_==0);
}

#endif
