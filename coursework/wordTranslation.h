#ifndef COURSEWORK_WORDTRANSLATION_H
#define COURSEWORK_WORDTRANSLATION_H

#include <stdexcept>
#include <string>
#include <fstream>

template<class T>
class List
{
public:
  List();
  ~List();
  void insert(const T& data);
  void print();
  void printFile(std::ofstream &stream);

private:
  class Node
  {
  public:
    Node* pNext_;
    T data_;
    Node(T data, Node* pNext = nullptr)
    {
      this->data_ = data;
      this->pNext_ = pNext;
    }
  };
  Node* head_;
};

template<class T>
List<T>::List() :
  head_(nullptr)
{ }

template<class T>
List<T>::~List() {

}

template<class T>
void List<T>::insert(const T &data) {
  if (head_ == nullptr)
  {
    head_ = new Node(data);
  }
  else
  {
    Node* temp = this->head_;
    if (temp->data_ == data)
    {
      std::cout << "THIS TRANSLATION HAS ALREADY BEEN ADDED, PLEASE TRY AGAIN\n";
      return;
    }
    while (temp->pNext_ != nullptr)
    {
      if (temp->data_ == data)
      {
        std::cout << "THIS TRANSLATION HAS ALREADY BEEN ADDED, PLEASE TRY AGAIN\n";
        return;
      }
      temp = temp->pNext_;
    }
    Node* current = this->head_;
    Node* prev = nullptr;
    while ((current->data_ < data)&&(current->pNext_ != nullptr))
    {
      prev = current;
      current = current->pNext_;
    }
    if (data < current->data_)
    {
      if (prev == nullptr)
      {
        prev = head_;
        head_ = new Node(data, current);
      }
      else if (prev != nullptr)
      {
        prev->pNext_ = new Node(data, current);
      }
    }
    else
    {
      current->pNext_ = new Node(data);
    }
  }
}

template<class T>
void List<T>::print() {
  Node *temp = head_;
  if (head_ == nullptr) {
    std::cout << "translations of this word still haven't been added\n";
    return;
  }
  while (temp != nullptr) {
    std::cout << temp->data_ << "\n";
    temp = temp->pNext_;
  }
}

template<class T>
void List<T>::printFile(std::ofstream &stream) {
  if (head_== nullptr) {
    stream << "no translations\n";
    return;
  }
  Node *temp = head_;
  while (temp != nullptr) {
    stream << temp->data_ << "\n";
    temp = temp->pNext_;
  }
}

#endif //COURSEWORK_WORDTRANSLATION_H
