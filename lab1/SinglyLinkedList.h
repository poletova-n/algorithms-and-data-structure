#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <ostream>

class SinglyLinkedList {
public:
  SinglyLinkedList();

  SinglyLinkedList(const SinglyLinkedList& src);

  SinglyLinkedList(SinglyLinkedList&& src) noexcept;

  void swap(SinglyLinkedList& rhs) noexcept;

  [[nodiscard]] int size() const;

  void push_front(int item);

  void push_back(int item);

  void pop_front();

  void pop_back();

  void remove(int item);

  void clear();

  bool has(int item);

  void merge(SinglyLinkedList& other);

  SinglyLinkedList& operator=(const SinglyLinkedList& other);

  SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept;

  bool operator==(const SinglyLinkedList& rhs) const;

  bool operator!=(const SinglyLinkedList& rhs) const;

  friend SinglyLinkedList operator&(const SinglyLinkedList& lhs, const SinglyLinkedList& rhs);

  friend SinglyLinkedList operator|(const SinglyLinkedList& lhs, const SinglyLinkedList& rhs);

  SinglyLinkedList& operator+=(int item);

  friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& singlyLinkedList);

  virtual ~SinglyLinkedList();

private:
  struct Node {
    int item_;
    Node* next_;
    Node(int item, Node* next);
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
