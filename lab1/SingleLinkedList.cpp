#include "SingleLinkedList.h"

SingleLinkedList::Node::Node(int item)
{
  item_ = item;
  next_ = nullptr;
}

SingleLinkedList::SingleLinkedList()
    : head_(nullptr) {}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& source)
    : head_(nullptr)
{
  Node* temp = source.head_;
  while (temp != nullptr)
  {
    *this += temp->item_;
    temp = temp->next_;
  }
}

SingleLinkedList::SingleLinkedList(SingleLinkedList&& source) noexcept
{
  this->head_ = source.head_;
  source.head_ = nullptr;
}

SingleLinkedList::~SingleLinkedList()
{
  Node* temp = head_;
  while (temp != nullptr)
  {
    temp = head_->next_;
    delete head_;
    head_ = temp;
  }
}

void SingleLinkedList::insert (Node* x)
{
  if (head_ == nullptr)
  {
    head_ = x;
    return;
  }
  if (searchNode(x->item_) != nullptr)
  {
    delete x;
    return;
  }

  if (head_->item_ > x->item_)
  {
    x->next_  = head_;
    head_ = x;
    return;
  }
  if ((head_->next_ == nullptr) && (x->item_ > head_->item_))
  {
    head_->next_ = x;
    return;
  }
  Node* counter = this->head_;
  while (counter->next_ != nullptr)
  {
    if ((x->item_ > counter->item_) && (x->item_ < counter->next_->item_))
    {
      x->next_ = counter->next_;
      counter->next_ = x;
      return;
    }
    counter = counter->next_;
    if (counter->next_ == nullptr)
    {
      x->next_ = nullptr;
      counter->next_ = x;
      return;
    }
  }
}

SingleLinkedList::Node* SingleLinkedList::searchNode(int item) const
{
  Node* temp = head_;
  while((temp != nullptr) && (temp->item_ != item))
  {
    temp = temp->next_;
  }
  return temp;
}

void SingleLinkedList::merge(SingleLinkedList& source)
{
  while(source.head_ != nullptr)
  {
    if(this->searchNode(source.head_->item_) == nullptr)
    {
      *this += source.head_->item_;
    }
    Node* temp = source.head_->next_;
    source.head_ = nullptr;
    source.head_ = temp;
  }
}

SingleLinkedList& SingleLinkedList::operator += (int item)
{
  insert(new Node(item));
  return *this;
}

SingleLinkedList& SingleLinkedList::operator = (const SingleLinkedList & source)
{
  if (this != &source)
  {
    while (this->head_ != nullptr)
    {
      Node* temp = this->head_->next_;
      this->head_ = nullptr;
      this->head_ = temp;
    }
    Node* temp = source.head_;
    while (temp != nullptr)
    {
      *this += temp->item_;
      temp = temp->next_;
    }
  }
  return *this;
}

bool SingleLinkedList::operator == (const SingleLinkedList& source) const
{
  Node* tempThis = this->head_;
  Node* tempSource = source.head_;
  while ((tempThis != nullptr) || (tempSource != nullptr))
  {
    if(tempThis->item_ != tempSource->item_)
    {
      return false;
    }
    tempSource = tempSource->next_;
    tempThis = tempThis->next_;
    if ((tempThis == nullptr) && (tempSource != nullptr) ||
        (tempThis != nullptr) && (tempSource == nullptr))
    {
      return false;
    }
  }
  return true;
}

SingleLinkedList operator & (const SingleLinkedList& list, const SingleLinkedList& source)
{
  SingleLinkedList summary;
  SingleLinkedList::Node* tempList = list.head_;
  while (tempList != nullptr)
  {
    if (source.searchNode(tempList->item_) != nullptr)
    {
      summary += tempList->item_;
    }
    tempList = tempList->next_;
  }
  return summary;
}

SingleLinkedList operator | (const SingleLinkedList& list, const SingleLinkedList& source)
{
  SingleLinkedList summary(source);
  SingleLinkedList::Node* tempList = list.head_;
  while(tempList != nullptr)
  {
    if (summary.searchNode(tempList->item_) == nullptr)
    {
      summary += tempList->item_;
    }
    tempList = tempList->next_;
  }
  return summary;
}

std::ostream& operator<<(std::ostream& os, const SingleLinkedList& list)
{
  SingleLinkedList::Node* temp = list.head_;
  while (temp != nullptr)
  {
    os << temp->item_ << ' ';
    temp = temp->next_;
  }
  return os;
}