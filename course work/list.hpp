#ifndef COURSACH_LIST_HPP
#define COURSACH_LIST_HPP

#include <string>
#include <iostream>

class List {
public:
  List();
  ~List();
  List(List&& list) noexcept;
  int getSize();
  std::string print();
  void addElem(std::string& str);
  List& operator = (const List &elem);

private:
  struct node
  {
    std::string item_;
    node* next_;
    node(std::string& item, node* next = nullptr) :
    item_(item),
    next_(next)
    {}
  };
  node* head_;
  bool isRussianWord(std::string str);
};

#endif
