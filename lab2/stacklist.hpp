#ifndef WORKING_STACKLIST_HPP
#define WORKING_STACKLIST_HPP

#include "stack.hpp"

template <typename T>
class StackList: public Stack<T>
{
public:
  StackList();
  ~StackList() override;
  void push(const T& element) override;
  T& pop() override;
  bool isEmpty() const;

private:
  struct Node
  {
    T item_;
    Node* prev_;

    explicit Node(const T element)
    {
      item_ = element;
    }
  };
  Node* top_;
};

template <typename T>
StackList<T>::StackList():
  top_(nullptr) {}

template <typename T>
StackList<T>::~StackList()
{
  while (top_ != nullptr)
  {
    StackList<T>::Node* temp = top_->prev_;
    delete top_;
    top_ = temp;
  }
}

template <typename T>
void StackList<T>::push(const T& element)
{
  StackList<T>::Node* temp = top_;
  top_ = new Node(element);
  top_->prev_ = temp;
}

template <typename T>
T& StackList<T>::pop()
{
  StackList<T>::Node* temp = top_;
  top_ = top_->prev_;
  return temp->item_;
}

template <typename T>
bool StackList<T>::isEmpty() const
{
  return (top_ == nullptr);
}

#endif // WORKING_STACKLIST_HPP
