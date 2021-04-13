#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>

#include "exceptions.h"
#include "stack.h"

template<class T>
class StackList : public Stack<T>
{
public:
  StackList();
  ~StackList();
  void push(const T &element) override;
  T pop() override;
  bool isEmpty() override;
private:
  struct Node
  {
    Node(T data, Node *next = nullptr)
    {
      data_ = data;
      next_ = next;
    }
    Node *next_;
    T data_;
  };
  Node *head_;
  int top_;
};

template<class T>
StackList<T>::StackList()
{
  head_ = nullptr;
  top_ = 0;
}

template<class T>
StackList<T>::~StackList()
{
  if (head_ != nullptr)
  {
    Node *tempCurrent = head_;
    Node *tempPrev = nullptr;
    while (tempCurrent->next_ != nullptr)
    {
      tempPrev = tempCurrent;
      tempCurrent = tempCurrent->next_;
      delete tempPrev;
    }
    delete tempCurrent;
  }
}

template<class T>
void StackList<T>::push(const T &element)
{
  if (head_ == nullptr)
  {
    head_ = new Node(element);
    top_ += 1;
  }
  else
  {
    Node *temp = head_;
    while (temp->next_ != nullptr)
    {
      temp = temp->next_;
    }
    temp->next_ = new Node(element);
    top_ += 1;
  }
}

template<class T>
T StackList<T>::pop()
{
  if (isEmpty())
  {
    throw StackUnderFlow();
  }
  if (head_->next_ == nullptr)
  {
    T tempData;
    tempData = head_->data_;
    top_ -= 1;
    delete head_;
    head_ = nullptr;
    return tempData;
  }
  else
  {
    Node *tempCurrent = head_;
    Node *tempPrev = nullptr;
    T tempData;
    while (tempCurrent->next_ != nullptr)
    {
      tempPrev = tempCurrent;
      tempCurrent = tempCurrent->next_;
    }
    tempData = tempCurrent->data_;
    delete tempCurrent;
    top_ -= 1;
    tempPrev->next_ = nullptr;
    return tempData;
  }
}

template<class T>
bool StackList<T>::isEmpty()
{
  if (top_ == 0)
  {
    return true;
  }
  return false;
}

#endif