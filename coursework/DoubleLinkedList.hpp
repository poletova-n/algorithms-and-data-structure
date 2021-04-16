#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include <iostream>
#include <string>

class DoubleLinkedList
{
public:
  DoubleLinkedList():
    head_(nullptr),
    tail_(nullptr)
  {}

  DoubleLinkedList(const DoubleLinkedList&);
  ~DoubleLinkedList();
  void pushBack(std::string);
  std::string getValueAsString();
private:
  struct Node
  {
    Node* next_;
    Node* prev_;
    std::string value_;

    Node(std::string value, Node* next = nullptr, Node* prev = nullptr):
      next_(next),
      prev_(prev),
      value_(value)
    {}
  };

  Node* head_;
  Node* tail_;
};

#endif
