#ifndef LAB5_QUEUELIST_HPP
#define LAB5_QUEUELIST_HPP

#include "iostream"
#include "queue.hpp"
#include "exceptionQ.hpp"

template <class T>
class QueueList : public Queue<T>
{
public:
  QueueList();
  QueueList(const QueueList<T>& src);
  virtual ~QueueList();
  void enQueue (const T& value);
  const T& deQueue ();
  const T& print (std::ostream &out);
  bool isEmpty() { return head_ == nullptr; };
  const T& getEl();

private:
  struct Node
  {
    T item_;
    Node *next_;
    Node (T item, Node *next = nullptr):
      item_(item),
      next_(next)
    {}
  };
  Node *head_;
};

template <class T>
QueueList<T>::~QueueList()
{
  while (head_ != nullptr)
  {
    deQueue();
  }
}

template <class T>
QueueList<T>::QueueList()
{
  head_ = nullptr;
}

template <class T>
QueueList<T>::QueueList(const QueueList<T>& src)
{
  head_ = nullptr;
  Node* node = src.head_;
  while (node->next_ != nullptr)
  {
    enQueue(node->item_);
    node = node->next_;
  }
  enQueue(node->item_);
}

template <class T>
void QueueList<T>::enQueue (const T& value)
{
  if (head_ != nullptr)
  {
    Node* node = head_;
    while (node->next_ != nullptr)
    {
      node = node->next_;
    }
    node->next_ = new Node(value);
  }
  else
  {
    head_ = new Node(value);
  }
}

template <class T>
const T& QueueList<T>::deQueue()
{
  if (head_ == nullptr)
  {
    throw QueueUnderflow();
  }

  if (head_->next_ == nullptr)
  {
    T value = head_->item_;
    delete head_;
    head_ = nullptr;
    return value;
  }
  T value = head_->item_;
  Node* node = head_->next_;
  delete head_;
  head_ = node;
  return value;
}

template <class T>
const T& QueueList<T>::print(std::ostream &out)
{
  Node* node = head_;
  while(node != nullptr)
  {
    out << node->item_ << " ";
    node = node->next_;
  }
}

template <class T>
const T& QueueList<T>::getEl()
{
  if (head_ == nullptr)
  {
    throw std::out_of_range("Queue is empty.");
  }
  return head_->item_;
}

#endif
