#include "DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& list):
  head_(nullptr),
  tail_(nullptr)
{
  Node* temp(list.head_);
  while (temp != nullptr) {
    pushBack(temp->value_);
    temp = temp->next_;
  }
}


DoubleLinkedList::~DoubleLinkedList()
{
  Node* temp(head_);
  while (temp != nullptr) {
    head_ = temp;
    temp = head_->next_;
    delete head_;
  }
}

void DoubleLinkedList::pushBack(std::string value)
{
  if (head_ == nullptr) {
    head_ = new Node(value);
    tail_ = head_;
  } else {
    tail_->next_ = new Node(value);
    Node* temp = tail_;
    tail_ = tail_->next_;
    tail_->prev_ = temp;
  }
}

std::string DoubleLinkedList::getValueAsString()
{
  std::string result;
  Node* temp(head_);
  while (temp != nullptr) {
    result += temp->value_;
    if (temp->next_ != nullptr) {
      result += ", ";
    }
    temp = temp->next_;
  }
  return result;
}
