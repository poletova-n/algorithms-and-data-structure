#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H


#include <ostream>

class DoublyLinkedList {
public:
  DoublyLinkedList();

  DoublyLinkedList(const DoublyLinkedList& src);

  DoublyLinkedList(DoublyLinkedList&& src) noexcept;

  void swap(DoublyLinkedList& rhs) noexcept;

  [[nodiscard]] int size() const;

  void push_front(int item);

  void push_back(int item);

  void pop_front();

  void pop_back();

  void remove(int item);

  void clear();

  bool has(int item);

  void merge(DoublyLinkedList& other);

  DoublyLinkedList& operator=(const DoublyLinkedList& other);

  DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

  bool operator==(const DoublyLinkedList& rhs) const;

  bool operator!=(const DoublyLinkedList& rhs) const;

  friend DoublyLinkedList operator&(const DoublyLinkedList& lhs, const DoublyLinkedList& rhs);

  friend DoublyLinkedList operator|(const DoublyLinkedList& lhs, const DoublyLinkedList& rhs);

  DoublyLinkedList& operator+=(int item);

  friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& singlyLinkedList);

  virtual ~DoublyLinkedList();

private:
  struct Node {
    int item_;
    Node* next_;
    Node* prev_;
    Node(int item, Node* next, Node* prev);
  };

  int size_;
  Node* head_;
  Node* tail_;

  [[nodiscard]] Node* head() const;

  [[nodiscard]] Node* tail() const;

  void insertTail(Node* x);

  void insertHead(Node* elem);

  void deleteNode(Node* x);

  Node* searchNode(int item);

  void replace(int itemOld, int itemNew);

  void sort();
};


#endif
