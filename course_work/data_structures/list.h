#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <stdexcept>

template<class T>
class List
{
public:
  List();
  List(const List &object);
  ~List();
  void operator+=(T data);
  void operator=(const List &object);
  T operator[](int size);
  void print(std::ostream &stream);
private:
  class Node
  {
  public:
    Node(T data, Node *next = nullptr)
    {
      data_ = data;
      next_ = next;
    }
    T data_;
    Node *next_;
  };
  Node *head_;
  int count_;
};

template<class T>
List<T>::List()
{
  head_ = nullptr;
  count_ = 0;
}

template<class T>
List<T>::List(const List &object)
{
  if (object.head_ == nullptr)
  {
    head_ = nullptr;
    count_ = 0;
  }
  else
  {
    this->count_ = object.count_;
    Node *tempObject = object.head_;
    this->head_ = new Node(tempObject->data_);
    Node *tempThis = this->head_;
    while (tempObject->next_ != nullptr)
    {
      tempObject = tempObject->next_;
      tempThis->next_ = new Node(tempObject->data_);
      tempThis = tempThis->next_;
    }
  }
}

template<class T>
List<T>::~List()
{
  if (head_ != nullptr)
  {
    Node *temp1 = head_;
    Node *temp2 = temp1->next_;
    while (temp1->next_ != nullptr)
    {
      delete temp1;
      temp1 = temp2;
      temp2 = temp2->next_;
    }
    delete temp1;
    count_ = 0;
    head_ = nullptr;
  }
}

template<class T>
void List<T>::operator+=(T data)
{
  if (head_ == nullptr)
  {
    head_ = new Node(data);
    count_ += 1;
  }
  else
  {
    for (int i = 1; i <= count_; i++)
    {
      if (data == (*this)[i])
      {
        throw std::runtime_error("Adding a repeating element");
      }
    }
    Node *tempCurrent = head_;
    Node *tempPrev = nullptr;
    while ((data > tempCurrent->data_) && (tempCurrent->next_ != nullptr))
    {
      tempPrev = tempCurrent;
      tempCurrent = tempCurrent->next_;
    }
    if (data < tempCurrent->data_)
    {
      if (tempPrev != nullptr)
      {
        tempPrev->next_ = new Node(data, tempCurrent);
      }
      else
      {
        tempPrev = head_;
        tempPrev = new Node(data, tempCurrent);
        head_ = tempPrev;
      }
    }
    else
    {
      tempCurrent->next_ = new Node(data);
    }
    count_ += 1;
  }
}

template<class T>
void List<T>::operator=(const List &object)
{
  if (object.head_ == nullptr)
  {
    head_ = nullptr;
    count_ = 0;
  }
  else
  {
    this->count_ = object.count_;
    Node *tempObject = object.head_;
    this->head_ = new Node(tempObject->data_);
    Node *tempThis = this->head_;
    while (tempObject->next_ != nullptr)
    {
      tempObject = tempObject->next_;
      tempThis->next_ = new Node(tempObject->data_);
      tempThis = tempThis->next_;
    }
  }
}

template<class T>
T List<T>::operator[](int size)
{
  if ((this->count_ < size) || (size <= 0))
  {
    throw std::runtime_error("Going outside the list");
  }
  else
  {
    Node *temp = this->head_;
    for (int i = 1; i < size; i++)
    {
      temp = temp->next_;
    }
    return temp->data_;
  }
}

template<class T>
void List<T>::print(std::ostream &stream)
{
  if (head_ != nullptr)
  {
    Node *temp = head_;
    while (temp->next_ != nullptr)
    {
      stream << temp->data_ << "\n";
      temp = temp->next_;
    }
    stream << temp->data_ << "\n";
  }
}

#endif