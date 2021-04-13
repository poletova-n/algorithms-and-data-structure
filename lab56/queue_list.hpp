#ifndef LAB56_QUEUE_LIST_HPP
#define LAB56_QUEUE_LIST_HPP

#include <iostream>
#include "queue.hpp"
#include "exceptions_queue.hpp"

template<class T>
class QueueList : public Queue<T> {

public:
  QueueList();

  QueueList(const QueueList &src);

  virtual ~QueueList();

  void enQueue(const T &e);

  const T deQueue();

  bool isEmpty();

private:

  struct Node {
    T value_;
    Node *next_;
    Node *prev_;

    Node(T value, Node *next = nullptr, Node *prev = nullptr) : value_(value), next_(next), prev_(prev) {}
  };

  int size_;
  Node *head_;
  Node *tail_;

  T deleteHead();

  void insertTail(Node *x);

  void insertHead(Node *x);
};

template<class T>
QueueList<T>::QueueList():
        size_(0), head_(nullptr), tail_(nullptr) {}

template<class T>
QueueList<T>::QueueList(const QueueList &src) {
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
  Node *iter = src.head_;
  for (int i = 0; i < src.size_; i++) {
    enQueue(iter->value_);
    iter = iter->next_;
  }
}

template<class T>
void QueueList<T>::enQueue(const T &e) {
  insertTail(new Node(e));
}

template<class T>
void QueueList<T>::insertTail(Node *x) {
  x->prev_ = tail_;
  if (head_ == nullptr) {
    insertHead(x);
    size_ = size_ - 1;
  }
  tail_->next_ = x;
  x->next_ = nullptr;
  tail_ = x;
  size_++;
}

template<class T>
const T QueueList<T>::deQueue() {
  if (head_ == nullptr) {
    throw QueueUnderflow();
  }
  deleteHead();
}

template<class T>
T QueueList<T>::deleteHead() {
  T val = head_->value_;
  Node *x = head_;
  head_ = x->next_;
  if (x->next_ != nullptr) {
    (x->next_)->prev_ = x->prev_;
  } else {
    tail_ = x->prev_;
  }
  delete x;
  size_--;
  return val;
}

template<class T>
QueueList<T>::~QueueList() {
  Node *next = head_;
  while (next != nullptr) {
    next = head_->next_;
    delete head_;
    head_ = next;
  }
}

template<class T>
bool QueueList<T>::isEmpty() {
  return head_ == nullptr && tail_ == nullptr ? 1 : 0;
}

template<class T>
void QueueList<T>::insertHead(QueueList::Node *x) {
  x->next_ = head_;
  if (head_ != nullptr) {
    head_->prev_ = x;
  } else {
    tail_ = x;
  }
  head_ = x;
  size_++;
}

#endif //LAB56_QUEUE_LIST_HPP
