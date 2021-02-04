#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
    : size_(0), head_(nullptr), tail_(nullptr) {}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& src)
    : size_(0), head_(nullptr), tail_(nullptr) {
  Node* temp = src.head_;
  while (temp != nullptr) {
    push_back(temp->item_);
    temp = temp->next_;
  }
}

SinglyLinkedList::SinglyLinkedList(SinglyLinkedList&& src) noexcept {
  head_ = src.head_;
  tail_ = src.tail_;
  size_ = src.size_;
  src.head_ = nullptr;
  src.tail_ = nullptr;
  src.size_ = 0;
}

SinglyLinkedList::Node::Node(int item, SinglyLinkedList::Node* next = nullptr) {
  this->item_ = item;
  this->next_ = next;
}

void SinglyLinkedList::swap(SinglyLinkedList& rhs) noexcept {
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

int SinglyLinkedList::size() const { return size_; }

SinglyLinkedList::Node* SinglyLinkedList::head() const { return head_; }

SinglyLinkedList::Node* SinglyLinkedList::tail() const { return tail_; }

void SinglyLinkedList::insertTail(Node* x) {
  x->next_ = nullptr;
  tail_ = x;
  if (this->head_ == nullptr) {
    head_ = tail_;
  } else if (head_->next_ == nullptr) {
    head_->next_ = tail_;
  } else {
    Node* temp = head_;
    while (temp->next_ != nullptr) {
      temp = temp->next_;
    }
    temp->next_ = tail_;
  }
  size_++;
}

void SinglyLinkedList::insertHead(Node* elem) {
  if (head_ == nullptr) {
    elem->next_ = nullptr;
  } else {
    elem->next_ = head_;
  }
  head_ = elem;
  size_++;
}

void SinglyLinkedList::deleteNode(Node* x) {
  if (head_ == x) {
    head_ = head_->next_;
    delete x;
    size_--;
    return;
  }
  Node* temp = head_;
  while (temp->next_ != x) {
    temp = temp->next_;
  }
  delete x;
  temp->next_ = nullptr;
  size_--;
}

SinglyLinkedList::Node* SinglyLinkedList::searchNode(int item) {
  Node* x = head_;
  while (x != nullptr && x->item_ != item) {
    x = x->next_;
  }
  return x;
}

void SinglyLinkedList::push_front(int item) {
  if (!has(item)) {
    insertHead(new Node(item));
  }
  this->sort();
}

void SinglyLinkedList::push_back(int item) {
  if (!has(item)) {
    insertTail(new Node(item));
  }
  this->sort();
}

void SinglyLinkedList::pop_front() {
  if (head_ == nullptr) {
    return;
  }
  deleteNode(head_);
}

void SinglyLinkedList::pop_back() {
  if (head_ == nullptr) {
    return;
  }
  Node* temp = head_;
  while (temp->next_ != nullptr) {
    temp = temp->next_;
  }
  deleteNode(temp);
}

void SinglyLinkedList::remove(const int item) {
  deleteNode(searchNode(item));
  this->sort();
}

void SinglyLinkedList::clear() {
  while (this->head_ != nullptr) {
    pop_front();
  }
  this->size_ = 0;
}

bool SinglyLinkedList::has(int item) {
  return (searchNode(item) != nullptr);
}

void SinglyLinkedList::replace(int itemOld, int itemNew) {
  Node* newNode = searchNode(itemNew);
  Node* oldNode = searchNode(itemOld);
  if (newNode == nullptr || oldNode == nullptr) {
    return;
  }
  int temp = oldNode->item_;
  oldNode->item_ = newNode->item_;
  newNode->item_ = temp;
}

void SinglyLinkedList::sort() {
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

void SinglyLinkedList::merge(SinglyLinkedList& other) {
  if (this == &other) {
    return;
  }
  while (other.head_ != nullptr) {
    this->push_back(other.head_->item_);
    other.deleteNode(other.head_);
  }
  this->sort();
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other) {
  if (this == &other) {
    return *this;
  }
  SinglyLinkedList temp(other);
  this->swap(temp);
  return *this;
}

SinglyLinkedList& SinglyLinkedList::operator=(SinglyLinkedList&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  this->swap(other);
  return *this;
}

bool SinglyLinkedList::operator==(const SinglyLinkedList& rhs) const {
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

bool SinglyLinkedList::operator!=(const SinglyLinkedList& rhs) const {
  return !(rhs == *this);
}

SinglyLinkedList operator&(const SinglyLinkedList& lhs, const SinglyLinkedList& rhs) {
  SinglyLinkedList singlyLinkedList;
  SinglyLinkedList::Node* left = lhs.head_;
  for (int i = 0; i < lhs.size_; ++i) {
    SinglyLinkedList::Node* right = rhs.head_;
    for (int j = 0; j < rhs.size_; ++j) {
      if (left->item_ == right->item_) {
        singlyLinkedList.push_back(left->item_);
        break;
      }
      right = right->next_;
    }
    left = left->next_;
  }
  return singlyLinkedList;
}

SinglyLinkedList operator|(const SinglyLinkedList& lhs, const SinglyLinkedList& rhs) {
  SinglyLinkedList singlyLinkedList;
  SinglyLinkedList::Node* temp = lhs.head_;
  for (int i = 0; i < lhs.size_; ++i) {
    singlyLinkedList.push_back(temp->item_);
    temp = temp->next_;
  }
  temp = rhs.head_;
  for (int i = 0; i < rhs.size_; ++i) {
    singlyLinkedList.push_back(temp->item_);
    temp = temp->next_;
  }
  return singlyLinkedList;
}

SinglyLinkedList& SinglyLinkedList::operator+=(int item) {
  this->push_back(item);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& singlyLinkedList) {
  SinglyLinkedList::Node* current = singlyLinkedList.head_;
  while (current != nullptr) {
    os << current->item_ << ' ';
    current = current->next_;
  }
  os << '\n';
  return os;
}

SinglyLinkedList::~SinglyLinkedList() {
  Node* next = head_;
  while (next != nullptr) {
    next = head_->next_;
    delete head_;
    head_ = next;
  }
}
