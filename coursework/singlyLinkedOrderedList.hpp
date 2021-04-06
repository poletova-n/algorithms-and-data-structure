#ifndef SINGLYLINKEDORDEREDLIST_HPP
#define SINGLYLINKEDORDEREDLIST_HPP

#include <iostream>
#include "exceptionList.hpp"

template<class T>
class SinglyLinkedOrderedList
{
  private:
  struct Node
  {
    T item_;
    Node *next_;
    explicit Node(int item, Node *next_ = nullptr) :
      item_(item),
      next_(next_)
    {}
  };

  Node *head_;
  void insertNode(Node *x);

  void deleteNode(Node *x);

  public:
  SinglyLinkedOrderedList() : head_(nullptr)
  {}

  SinglyLinkedOrderedList(const SinglyLinkedOrderedList &src);

  SinglyLinkedOrderedList &operator=(const SinglyLinkedOrderedList<T> &src);

  SinglyLinkedOrderedList(SinglyLinkedOrderedList &&src) = delete;

  SinglyLinkedOrderedList &operator=(SinglyLinkedOrderedList<T> &&src) = delete;

  ~SinglyLinkedOrderedList();

  void insertItem(T item);

  Node *searchNode(T item);

  bool searchItem(T item);

  bool deleteItem(T item);

  void print();

  int getSize();

  bool isEmpty();
};

template<class T>
void SinglyLinkedOrderedList<T>::insertNode(SinglyLinkedOrderedList::Node *x)
{
  if (this->head_ == nullptr)
  {
    x->next_ = nullptr;
    this->head_ = x;
    this->head_->next_ = nullptr;

  } else
  {
    Node *temp = this->head_;
    while (temp != nullptr)
    {
      if (this->head_->item_ > x->item_)
      {
        x->next_ = head_;
        this->head_ = x;
        return;
      } else if (temp->next_ == nullptr)
        break;
      else if (temp->next_->item_ < x->item_)
        temp = temp->next_;

      else if (temp->next_->item_ == x->item_ || head_->item_ == x->item_)

        return;

      else if (temp->next_->item_ > x->item_)
      {
        x->next_ = temp->next_;
        temp->next_ = x;
        return;
      }
    }
    temp->next_ = x;
    x->next_ = nullptr;
  }

}

template<class T>
void SinglyLinkedOrderedList<T>::insertItem(T item)
{
  insertNode(new Node(item));
}

template<class T>
bool SinglyLinkedOrderedList<T>::searchItem(T item)
{
  return (searchNode(item) != nullptr);
}

template<class T>
typename SinglyLinkedOrderedList<T>::Node *SinglyLinkedOrderedList<T>::searchNode(T item)
{
  Node *temp = head_;
  while (temp != nullptr && temp->item_ != item)
  {
    temp = temp->next_;
  }
  return temp;

}

template<class T>
void SinglyLinkedOrderedList<T>::deleteNode(SinglyLinkedOrderedList::Node *x)
{
  if (x == nullptr)
  {
    throw ListWrongNode();
  } else
  {
    if (this->head_ == x)
      head_ = x->next_;
    else
    {

      Node *temp = this->head_;
      while (temp != nullptr && temp->next_ != x)
        temp = temp->next_;
      if (temp != nullptr)
        temp->next_ = x->next_;
      delete x;

    }
  }
}

template<class T>
bool SinglyLinkedOrderedList<T>::deleteItem(T item)
{
  if (isEmpty())
  {
    throw ListUnderflow();
  }
  if (!searchItem(item))
    return false;
  else
  {
    Node *temp = searchNode(item);
    deleteNode(temp);
    return true;
  }
}

template<class T>
SinglyLinkedOrderedList<T> &SinglyLinkedOrderedList<T>::operator=(const SinglyLinkedOrderedList<T> &src)
{
  head_ = nullptr;
  Node *temp = src.head_;
  while (temp != nullptr)
  {
    insertItem(temp->item_);
    temp = temp->next_;
  }
  return *this;
}

template<class T>
SinglyLinkedOrderedList<T>::SinglyLinkedOrderedList(const SinglyLinkedOrderedList &src)
{
  head_ = nullptr;
  Node *temp = src.head_;
  while (temp != nullptr)
  {
    insertItem(temp->item_);
    temp = temp->next_;
  }
}

template<class T>
void SinglyLinkedOrderedList<T>::print()
{
  Node *temp = head_;
  while (temp != nullptr)
  {
    std::cout << temp->item_ << " ";
    temp = temp->next_;
  }
}

template<class T>
int SinglyLinkedOrderedList<T>::getSize()
{
  Node *temp = head_;
  int size = 0;
  while (temp != nullptr)
  {
    size++;
    temp = temp->next_;
  }
  return size;
}

template<class T>
bool SinglyLinkedOrderedList<T>::isEmpty()
{
  return (getSize() == 0);
}

template<class T>
SinglyLinkedOrderedList<T>::~SinglyLinkedOrderedList()
{
  Node *next = head_;
  while (head_ != nullptr)
  {
    next = head_->next_;
    delete head_;
    head_ = next;
  }
}

#endif
