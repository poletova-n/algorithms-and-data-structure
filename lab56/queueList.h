#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "queue.h"
#include "exception.h"

template <class T>
struct Node
{
public:
  Node(T data) : data(data), next(nullptr) {};
  T data;
  Node* next;
};

template <class T>
class QueueList : public Queue<T>
{
public:
  QueueList();
  QueueList(const QueueList<T>& src);
  ~QueueList() override
  {
    while (!isEmpty())
    {
      deQueue();
    }
  };
  void enQueue(const T& element);
  const T& deQueue();
  void printQueue();
  const T& getFront();
  bool isEmpty()
  {
    return (size == 0 );
  };
  int nElements()
  {
    return size;
  }
  T* front(QueueList* queue)
  {
    return queue->head_;
  }

private:
  Node<T>* head_;
  Node<T>* tail_;
  int size;
};

template <class T>
QueueList<T>::QueueList()
{
  size = 0;
  head_ = nullptr;
  tail_ = nullptr;
}

template <class T>
QueueList<T>::QueueList(const QueueList<T>& src)
{
  this->size = src.size;
  this->head_ = src.head_;
  this->tail_ = src.tail_;
}

template <class T>
void QueueList<T>::enQueue(const T& element)
{
  if (isEmpty())
  {
    head_ = new Node<T>(element);
    tail_ = new Node<T>(element);
    head_ = tail_;
  }
  else
  {
    Node<T>* cur = new Node<T>(element);
    tail_->next = cur;
    tail_ = cur;
  }
  size++;
}

template <class T>
const T& QueueList<T>::deQueue()
{
  if (!isEmpty())
  {
    if (head_ == tail_)
    {
      T temp = head_->data;
      head_ = nullptr;
      tail_ = nullptr;
      size--;
      return temp;
    }
    else
    {
      T temp = head_->data;
      head_ = head_->next;
      size--;
      return temp;
    }
  }
  throw QueueUnderflow();
}

template<class T>
void QueueList<T>::printQueue()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty.";
  }
  else
  {
    Node<T>* temp = head_;
    while ( temp != nullptr )
    {
      std::cout << " " << temp->data << " ";
      temp = temp->next;
    }
  }
  std::cout << std::endl;
}

template <class T>
const T& QueueList<T>::getFront()
{
  if (head_ == nullptr)
  {
   throw QueueUnderflow();
  }
  return head_->data;
}

#endif
