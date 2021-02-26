#ifndef ALGORITHMS_AND_DATA_STRUCTURE_SINGLELINKEDLIST_H
#define ALGORITHMS_AND_DATA_STRUCTURE_SINGLELINKEDLIST_H
#include <iostream>

class SingleLinkedList
{
private:

  struct Node
  {
      int item_;
      Node* next_;
      explicit Node(int item);
  };

  Node* head_;

  void insert (Node* x);

  Node* searchNode(int item) const;

public:

  SingleLinkedList();

  SingleLinkedList(const SingleLinkedList& source);

  SingleLinkedList(SingleLinkedList&& source) noexcept;

  ~SingleLinkedList();

  void merge(SingleLinkedList& source);

  friend SingleLinkedList operator & (const SingleLinkedList& list, const SingleLinkedList& source);

  friend SingleLinkedList operator | (const SingleLinkedList& list, const SingleLinkedList& source);

  friend std::ostream& operator << (std::ostream& os, const SingleLinkedList& list);

  SingleLinkedList& operator += (int item);

  SingleLinkedList& operator = (const SingleLinkedList & source);

  bool operator == (const SingleLinkedList& source) const;
};
#endif //ALGORITHMS_AND_DATA_STRUCTURE_SINGLELINKEDLIST_H