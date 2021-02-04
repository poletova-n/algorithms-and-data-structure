#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
    : size_(0), head_(nullptr), tail_(nullptr) {}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& src)
    : size_(0), head_(nullptr), tail_(nullptr) {
  Node* temp = src.head_;
  while (temp != nullptr) {
    push_back(temp->item_);
    temp = temp->next_;
  }
}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& src) noexcept {
  head_ = src.head_;
  tail_ = src.tail_;
  size_ = src.size_;
  src.head_ = nullptr;
  src.tail_ = nullptr;
  src.size_ = 0;
}

DoublyLinkedList::Node::Node(int item, DoublyLinkedList::Node* next = nullptr, DoublyLinkedList::Node* prev = nullptr) {
  this->next_ = next;
  this->item_ = item;
  this->prev_ = prev;
}

void DoublyLinkedList::swap(DoublyLinkedList& rhs) noexcept {
  Node* tempHead = rhs.head_;
  Node* tempTail = rhs.tail_;
  int tempSize = rhs.size_;
  rhs.head_ = this->head_;
  rhs.tail_ = this->tail_;
  rhs.size_ = this->size_;
  this->head_ = tempHead;
  this->tail_ = tempTail;
  this->size_ = tempSize;
}

int DoublyLinkedList::size() const { return size_; }

DoublyLinkedList::Node* DoublyLinkedList::head() const { return head_; }

DoublyLinkedList::Node* DoublyLinkedList::tail() const { return tail_; }

void DoublyLinkedList::insertTail(DoublyLinkedList::Node* x) {
  x->next_ = nullptr;
  if (this->head_ == nullptr) {
    x->prev_ = nullptr;
    head_ = x;
  } else if (head_->next_ == nullptr) {
    x->prev_ = head_;
    head_->next_ = x;
  } else {
    Node* temp = head_;
    while (temp->next_ != nullptr) {
      temp = temp->next_;
    }
    x->prev_ = temp;
    temp->next_ = x;
  }
  size_++;
}

void DoublyLinkedList::insertHead(DoublyLinkedList::Node* elem) {
  elem->next_ = head_;
  if (head_ != nullptr) {
    head_->prev_ = elem;
  } else {
    tail_ = elem;
  }
  head_ = elem;
  size_++;
}

void DoublyLinkedList::deleteNode(DoublyLinkedList::Node* x) {
  if (x->prev_ != nullptr) {
    // удаляется НЕ голова списка
    (x->prev_)->next_ = x->next_;
  } else {
    // удаляется голова списка,  второй элемент становится первым
    head_ = x->next_;
  }
  if (x->next_ != nullptr) {
    // удаляется НЕ хвост
    (x->next_)->prev_ = x->prev_;
  } else {
    // удаляется хвост
    tail_ = x->prev_;
  }
  delete x;
  size_--;
}

DoublyLinkedList::Node* DoublyLinkedList::searchNode(int item) {
  Node* x = head_;
  while (x != nullptr && x->item_ != item) {
    x = x->next_;
  }
  return x;
}

void DoublyLinkedList::push_front(int item) {
  if (!has(item)) {
    insertHead(new Node(item));
  }
  this->sort();
}

void DoublyLinkedList::push_back(int item) {
  if (!has(item)) {
    insertTail(new Node(item));
  }
  this->sort();
}
void DoublyLinkedList::pop_front() {
  if (head_ == nullptr) {
    return;
  }
  deleteNode(head_);
}

void DoublyLinkedList::pop_back() {
  if (head_ == nullptr) {
    return;
  }
  Node* temp = head_;
  while (temp->next_ != nullptr) {
    temp = temp->next_;
  }
  deleteNode(temp);
}

void DoublyLinkedList::remove(int item) {
  deleteNode(searchNode(item));
  this->sort();
}

void DoublyLinkedList::clear() {
  while (this->head_ != nullptr) {
    pop_front();
  }
  this->size_ = 0;
}

bool DoublyLinkedList::has(int item) {
  return (searchNode(item) != nullptr);
}

void DoublyLinkedList::replace(int itemOld, int itemNew) {
  Node* newNode = searchNode(itemNew);
  Node* oldNode = searchNode(itemOld);
  if (newNode == nullptr || oldNode == nullptr) {
    return;
  }
  int temp = oldNode->item_;
  oldNode->item_ = newNode->item_;
  newNode->item_ = temp;
}

void DoublyLinkedList::sort() {
  for (int i = 0; i < this->size_; i++) {
    Node* temp = this->head_;
    Node* next = temp->next_;
    while (next != nullptr) {
      if (temp->item_ > next->item_) {
        replace(temp->item_, next->item_);
      }
      temp = temp->next_;
      next = next->next_;
    }
  }
}

void DoublyLinkedList::merge(DoublyLinkedList& other) {
  if (this == &other) {
    return;
  }
  while (other.head_ != nullptr) {
    this->push_back(other.head_->item_);
    other.deleteNode(other.head_);
  }
  this->sort();
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other) {
  if (this == &other) {
    return *this;
  }
  DoublyLinkedList temp(other);
  this->swap(temp);
  return *this;
}

DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  this->swap(other);
  return *this;
}

bool DoublyLinkedList::operator==(const DoublyLinkedList& rhs) const {
  if (this->size_ != rhs.size_) {
    return false;
  }
  Node* x1 = this->head_;
  Node* x2 = rhs.head_;
  while (x1 != nullptr && x2 != nullptr) {
    if (x1 != x2) {
      return false;
    }
    x1 = x1->next_;
    x2 = x2->next_;
  }
  return true;
}

bool DoublyLinkedList::operator!=(const DoublyLinkedList& rhs) const {
  return !(rhs == *this);
}
DoublyLinkedList operator&(const DoublyLinkedList& lhs, const DoublyLinkedList& rhs) {
  DoublyLinkedList doublyLinkedList;
  DoublyLinkedList::Node* left = lhs.head_;
  for (int i = 0; i < lhs.size_; ++i) {
    DoublyLinkedList::Node* right = rhs.head_;
    for (int j = 0; j < rhs.size_; ++j) {
      if (left->item_ == right->item_) {
        doublyLinkedList.push_back(left->item_);
        break;
      }
      right = right->next_;
    }
    left = left->next_;
  }
  return doublyLinkedList;
}

DoublyLinkedList operator|(const DoublyLinkedList& lhs, const DoublyLinkedList& rhs) {
  DoublyLinkedList doublyLinkedList;
  DoublyLinkedList::Node* temp = lhs.head_;
  for (int i = 0; i < lhs.size_; ++i) {
    doublyLinkedList.push_back(temp->item_);
    temp = temp->next_;
  }
  temp = rhs.head_;
  for (int i = 0; i < rhs.size_; ++i) {
    doublyLinkedList.push_back(temp->item_);
    temp = temp->next_;
  }
  return doublyLinkedList;
}

DoublyLinkedList& DoublyLinkedList::operator+=(int item) {
  this->push_back(item);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& singlyLinkedList) {
  DoublyLinkedList::Node* current = singlyLinkedList.head_;// Указатель на элемент
  while (current != nullptr) {
    os << current->item_ << ' ';
    current = current->next_;// Переход к следующему элементу
  }
  os << '\n';
  return os;
}

DoublyLinkedList::~DoublyLinkedList() {
  Node* next = head_;
  while (next != nullptr) {
    next = head_->next_;
    delete head_;
    head_ = next;
  }
}

// Доступ к информации головного узла списка
//int DoubleLinkedList::headItem() const
//{
//  if (head_ != nullptr) {
//    return head_->item_;
//  }
//  throw ("headItem - список пуст!");
//}
//
//int& DoubleLinkedList::headItem()
//{
//  if (head_ != nullptr) {
//    return head_->item_;
//  }
//  throw ("headItem - список пуст!");
//}

// Доступ к информации хвостового узла списка
//int DoubleLinkedList::tailItem() const
//{
//  if (tail_ != nullptr) {
//    return tail_->item_;
//  }
//  throw ("tailItem - список пуст!");
//}
//int& DoubleLinkedList::tailItem()
//{
//  if (tail_ != nullptr) {
//    return tail_->item_;
//  }
//  throw ("tailItem - список пуст!");
//}