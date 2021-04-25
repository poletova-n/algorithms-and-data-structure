#include "list.hpp"

#include <vector>
#include <string>

List::List(const List& list) :
  head_(nullptr),
  tail_(nullptr)
{
  Node *temp(list.head_);
  while (temp != nullptr)
  {
    add(temp->value_);
    temp = temp->next_;
  }
}

List::~List()
{
  Node *temp(head_);
  while (temp != nullptr)
  {
    head_ = temp;
    temp = head_->next_;
    delete head_;
  }
}

void List::add(std::string value)
{
  if (head_ == nullptr)
  {
    head_ = new Node(value);
    tail_ = head_;
  }
  else
  {
    tail_->next_ = new Node(value);
    Node *temp = tail_;
    tail_ = tail_->next_;
    tail_->prev_ = temp;
  }
}

std::string List::getValueAsString()
{
  std::string result;
  Node *temp(head_);
  while (temp != nullptr)
  {
    result += temp->value_;
    if (temp->next_ != nullptr)
    {
      result += ", ";
    }
    temp = temp->next_;
  }
  return result;
}

void List::Swap(const int index1, const int index2)
{
  Node* element1 = head_;
  for (int index = 0; index < index1; index++)
    element1 = element1->next_;
  Node* element2 = head_;
  for (int index = 0; index < index2; index++)
    element2 = element2->next_;
  std::string tmp = element1->value_;
  element1->value_ = element2->value_;
  element2->value_ = tmp;
}
