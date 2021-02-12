#ifndef ALGORITHMS_AND_DATA_STRUCTURE_DOUBLELINKEDLIST_H
#define ALGORITHMS_AND_DATA_STRUCTURE_DOUBLELINKEDLIST_H


#include <ostream>

class DoubleLinkedList
{
private:

  struct Node
  {
    int item_;
    Node* next_;
    Node* prev_;

    explicit Node (int item);
  };

  Node* head_;

  Node* tail_;

  void insert(Node* node);

  Node* searchNode(int item) const;

public:

  DoubleLinkedList();

  DoubleLinkedList(const DoubleLinkedList& source);

  DoubleLinkedList(DoubleLinkedList&& source) noexcept;

  ~DoubleLinkedList();

  DoubleLinkedList& operator += (int item);

  friend std::ostream& operator << (std::ostream& os, const DoubleLinkedList& list);

  bool operator == (const DoubleLinkedList& rhs) const;

  friend DoubleLinkedList operator & (const DoubleLinkedList& list, const DoubleLinkedList& source);

  friend DoubleLinkedList operator | (const DoubleLinkedList& list, const DoubleLinkedList& source);

  void merge (DoubleLinkedList& source);

};


#endif//ALGORITHMS_AND_DATA_STRUCTURE_DOUBLELINKEDLIST_H
