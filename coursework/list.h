#ifndef LIST_H
#define LIST_H

#include <string>

class List
{
public:
  List() : pHead_(nullptr), pTail_(nullptr) {}
  List(const List&);
  List(List&&) noexcept;
  ~List();

  List& operator= (const List&);
  List& operator= (List&& List) noexcept = delete;

  size_t getSize();
  
  List& insert(std::string);

  void print(std::ostream&);
private:
  struct Node
  {
    std::string word_;
    Node* next_;
    Node* pre_;
    Node(std::string word, Node* next = nullptr, Node* pre = nullptr) : word_(word), next_(next), pre_(pre) {}
  };
  Node* pHead_;
  Node* pTail_;
  List& insertHead(Node*);
  List& insertTail(Node*);
};

#endif
