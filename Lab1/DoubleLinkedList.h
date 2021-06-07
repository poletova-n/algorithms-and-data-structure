#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <string>

class DoubleLinkedList
{
private:
  // Type 'NODE' is used to write the elements of the list, entangled with the next and the previous with the help of 'next' and the previous field 'prev'
  struct Node
  {
    int item;
    Node* next;
    Node* prev;

    Node(int item, Node* next = nullptr, Node* prev = nullptr) : item(item), next(next), prev(prev) { }
  };

  int count_;
  Node* head_;
  Node* tail_;

  Node* head() const { return head_; }
  Node* tail() const { return tail_; }

  void insertTail(Node* x);
  void insertHead(Node* x);
  void deleteNode(Node* x);
  Node* searchNode(int item);
  Node* replaceNode(Node* x, int item);

public:
  void outAll();
  bool searchItem(int item);
  DoubleLinkedList copy();

  DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {  }
  DoubleLinkedList(const DoubleLinkedList& other);

  DoubleLinkedList& operator= (const DoubleLinkedList& other);
  void swap(DoubleLinkedList& other) throw();

  DoubleLinkedList(DoubleLinkedList&& list) noexcept;
  DoubleLinkedList& operator= (DoubleLinkedList&& other);

  void insertHead(int item);
  void insertTail(int item);
  bool deleteHead();
  bool deleteTail();
  bool deleteItem(const int item);
  bool replaceItem(int itemOld, int itemNew);

  friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list);
  bool operator== (const DoubleLinkedList& list) const;
  void unite(DoubleLinkedList& other);
};
#endif
