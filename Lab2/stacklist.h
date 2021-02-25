#ifndef STACKLIST_H
#define STACKLIST_H

#include "exceptions.h"
#include "Stack.h"

template <class T>
class StackList : public Stack<T>
{
private:
  struct Node
  {
    Node(T item, Node* prev) :
      item_(item),
      prev_(prev)
    {}

    T item_;
    Node* prev_;
  };

  Node* top_;
  size_t size_;

public:
  StackList();
  ~StackList();

  T pop() override;
  const T& top() override;
  void push(const T& element) override;
  bool isEmpty() override;

};

template <class T>
StackList<T>::StackList()
{
  size_ = 0;
  top_ = nullptr;
}

template <class T>
StackList<T>::~StackList()
{
  Node* prev = this->top_;
  while (prev != nullptr)
  {
    prev = top_->prev_;
    delete top_;
    top_ = prev;
  }
}

template <class T> 
void StackList<T>::push(const T& element)
{
  if (size_ == 0)
  {
    Node* temp = new Node(element, nullptr);
    top_ = temp;
    size_++;
    return;
  }
  Node* temp = new Node(element, top_);
  this->top_ = temp;
  size_++;
}

template <class T>
T StackList<T>::pop()
{
  if (size_ == 0)
  {
    throw StackUnderFlow();
  }
  if (size_ == 1) 
  {
    T tempelem = top_->item_;
    delete this->top_;
    top_ = nullptr;
    size_--;
    return tempelem;
  }
  Node* prev = this->top_->prev_;
  T tempelem = this->top_->item_;
  delete this->top_;
  top_ = prev;
  size_--;
  return tempelem;
}

template <class T>
const T& StackList<T>::top()
{
  if (size_ == 0)
  {
    throw StackUnderFlow();
  }
  return this->top_->item_;
}

template <class T>
bool StackList<T>::isEmpty()
{
  return (size_ == 0);
}

#endif
