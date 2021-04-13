#ifndef QUEUE_QUEUELIST_H
#define QUEUE_QUEUELIST_H

#include <iostream>

#include "exception.h"
#include "queue.h"

template<class T>
class QueueList : public Queue<T>
{
public:
  QueueList();
  ~QueueList();
  void enQueue(const T &element) override;
  T deQueue() override;
  bool isEmpty() const override;
  void print(std::ostream &output) const override;
private:
  struct Node
  {
    Node(T data, Node *next = nullptr)
    {
      data_ = data;
      next_ = next;
    }
    T data_;
    Node *next_;
  };
  Node *head_;
  int current_;
};

template<class T>
QueueList<T>::QueueList():
  head_(nullptr),
  current_(0)
{}

template<class T>
QueueList<T>::~QueueList()
{
  if (head_ != nullptr)
  {
    Node *temp = head_;
    while (temp->next_ != nullptr)
    {
      Node *current = temp;
      temp = temp->next_;
      delete current;
    }
    delete temp;
  }
}

template<class T>
void QueueList<T>::enQueue(const T &element)
{
  if (head_ == nullptr)
  {
    head_ = new Node(element);
  }
  else
  {
    Node *temp = head_;
    while (temp->next_ != nullptr)
    {
      temp = temp->next_;
    }
    temp->next_ = new Node(element);
  }
  current_++;
}

template<class T>
T QueueList<T>::deQueue()
{
  if (current_ == 0)
  {
    throw QueueUnderflow();
  }
  if (current_ == 1)
  {
    T tempData = head_->data_;
    delete head_;
    head_ = nullptr;
    current_--;
    return tempData;
  }
  else
  {
    T tempData = head_->data_;
    Node *tempCurrent = head_;
    Node *tempPrev = nullptr;
    while (tempCurrent->next_ != nullptr)
    {
      tempCurrent->data_ = tempCurrent->next_->data_;
      tempPrev = tempCurrent;
      tempCurrent = tempCurrent->next_;
    }
    tempPrev->next_ = nullptr;
    delete tempCurrent;
    current_--;
    return tempData;
  }
}

template<class T>
bool QueueList<T>::isEmpty() const
{
  if (current_ == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<class T>
void QueueList<T>::print(std::ostream &output) const
{
  if (current_ == 0)
  {
    throw QueueUnderflow();
  }
  output << "QueueList: ";
  Node *temp = head_;
  while (temp->next_ != nullptr)
  {
    output << temp->data_ << " ";
    temp = temp->next_;
  }
  output << temp->data_;
}

#endif
