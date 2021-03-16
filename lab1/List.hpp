#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
class List
{
public:
  List();
  List(const List &object);
  ~List();
  void operator+=(int data);
  void operator-=(int data);
  bool operator==(List &object);
  int operator[](int size);
  void operator=(const List &object);
  friend List operator&(List &object1, List &object2);
  friend List operator|(List &object1, List &object2);
  friend std::ostream &operator<<(std::ostream &output, List &object);
  void merge(List &object);
  void print();
private:
  class Node
  {
  public:
    Node(int data, Node *next = nullptr)
    {
      data_ = data;
      next_ = next;
    }
    int data_;
    Node *next_;
  };
  Node *head_;
  int count_;
};
#endif
