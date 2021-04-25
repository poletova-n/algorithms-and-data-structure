#ifndef COURSEWORK_LIST_HPP
#define COURSEWORK_LIST_HPP

#include <iostream>
#include <string>
#include <vector>

class List
{
public:
  List():
    head_(nullptr),
    tail_(nullptr)
  {}

  List(const List& list);
  ~List();
  void add(std::string value);
  void Swap(const int index1, const int index2);
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
