#ifndef LAB6_QUEUELIST_HPP
#define LAB6_QUEUELIST_HPP

#include "stdexcept"
#include "queue.hpp"
#include "exceptions.hpp"

template <class T>
class QueueList: public Queue<T>
{
public:
  QueueList();
  QueueList(QueueList<T>& queueList);
  ~QueueList() override;
  T& head() const override;
  void enQueue(const T& elem) override;
  void deQueue() override;
  bool empty() const override;

private:
  struct Node
  {
    T item_;
    Node* next_;

    explicit Node(const T& elem):
      item_(elem),
      next_(nullptr)
    {}
  };

  Node* head_;
};

template<class T>
QueueList<T>::QueueList():
  head_(nullptr)
{}

template <class T>
QueueList<T>::QueueList(QueueList<T>& queueList)
{
  if (queueList.head_ != nullptr)
  {
    Node* temp = queueList.head_;
    while (temp->next_ != nullptr)
    {
      enQueue(temp->item_);
      temp = temp->next_;
    }
  }
}

template <class T>
QueueList<T>::~QueueList()
{
  while (head_ != nullptr)
  {
    deQueue();
  }
}

template <class T>
T& QueueList<T>::head() const
{
  if (head_ == nullptr)
  {
    throw std::out_of_range("Queue is empty.");
  }
  return head_->item_;
}

template <class T>
void QueueList<T>::enQueue(const T& elem)
{
  if (head_ != nullptr)
  {
    Node* temp = head_;
    while (temp->next_ != nullptr)
    {
      temp = temp->next_;
    }
    temp->next_ = new Node(elem);
  }
  else
  {
    head_ = new Node(elem);
  }
}

template <class T>
void QueueList<T>::deQueue()
{
  if (head_ == nullptr)
  {
    throw QueueUnderflow();
  }
  Node* temp = head_->next_;
  delete head_;
  head_ = temp;
}

template <class T>
bool QueueList<T>::empty() const
{
  return head_ == nullptr;
}

#endif
