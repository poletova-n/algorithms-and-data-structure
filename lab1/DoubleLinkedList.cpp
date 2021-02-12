#include "DoubleLinkedList.h"

DoubleLinkedList::Node::Node(int item)
    :item_(item), next_(nullptr), prev_(nullptr) {}

DoubleLinkedList::DoubleLinkedList()
    :head_(nullptr), tail_(nullptr) {}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& source)
    :head_(nullptr), tail_(nullptr)
{
  Node* temp = source.head_;
  while (temp != nullptr)
  {
    *this += temp->item_;
    temp = temp->next_;
  }
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& source) noexcept
{
  head_ = source.head_;
  tail_ = source.tail_;
  source.head_ = nullptr;
  source.tail_ = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
{
  while (head_ != nullptr)
  {
    Node* temp = head_->next_;
    head_ = nullptr;
    head_ = temp;
    if (tail_ != head_)
    {
      temp = tail_->prev_;
      tail_ = nullptr;
      tail_ = temp;
    }
  }
}

void DoubleLinkedList::insert(Node* node)
{
  if (this->searchNode(node->item_) != nullptr)
  {
    delete node;
    return;
  }
  if (head_ == nullptr)
  {
    head_ = node;
    tail_ = node;
    return;
  }
  if (head_->item_ > node->item_)
  {
    head_->prev_ = node;
    node->next_ = head_;
    head_ = node;
    return;
  }
  if (tail_->item_ < node->item_)
  {
    Node* temp = tail_;
    tail_ = node;
    tail_->prev_ = temp;
    tail_->prev_->next_ = tail_;
    return;
  }
  Node* tempFromHead = head_->next_;
  Node* tempFromTail = tail_->prev_;
  while (tempFromHead->next_ != nullptr)
  {
    if ((tempFromHead->item_ < node->item_) && (tempFromHead->next_->item_ > node->item_))
    {
      Node* temp = tempFromHead->next_;
      tempFromHead->next_ = node;
      tempFromHead->next_->next_ = temp;
      tempFromHead->next_->prev_ = tempFromHead;
      tempFromHead->next_->next_->prev_ = tempFromHead->next_;
      return;
    }
    if ((tempFromTail->item_ > node->item_) && (tempFromTail->prev_->item_ < node->item_))
    {
      Node* temp = tempFromTail->prev_;
      tempFromTail->prev_ = node;
      tempFromTail->prev_->prev_ = temp;
      tempFromTail->prev_->next_ = tempFromTail;
      tempFromTail->prev_->prev_->next_ = tempFromTail->prev_;
      return;
    }
    tempFromHead = tempFromHead->next_;
    tempFromTail = tempFromTail->prev_;
  }
}

DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item) const
{
  Node* tempFH = head_;
  Node* tempFT = tail_;
  while ((tempFH != nullptr) && (tempFT != nullptr))
  {
    if (tempFH->item_ == item)
    {
      return tempFH;
    }
    tempFH = tempFH->next_;
    if (tempFT->item_ == item)
    {
      return tempFT;
    }
    tempFT = tempFT->prev_;
  }
  return nullptr;
}

void DoubleLinkedList::merge (DoubleLinkedList& source)
{
  while(source.head_ != nullptr)
  {
    if (this->searchNode(source.head_->item_) == nullptr)
    {
      *this += source.head_->item_;
    }
    Node* temp = source.head_->next_;
    source.head_ = nullptr;
    source.head_ = temp;
  }
}

DoubleLinkedList& DoubleLinkedList::operator += (int item)
{
  this->insert(new Node(item));
  return *this;
}

std::ostream& operator << (std::ostream& os, const DoubleLinkedList& list)
{
  DoubleLinkedList::Node* temp = list.head_;
  while (temp != nullptr)
  {
    os << temp->item_ << ' ';
    temp = temp->next_;
  }
  return os;
}

bool DoubleLinkedList::operator == (const DoubleLinkedList& source) const
{
  Node* thisTemp = head_;
  Node* sourceTemp = source.head_;
  while (thisTemp != nullptr || sourceTemp != nullptr)
  {
    if (thisTemp->item_ != sourceTemp->item_)
    {
      return false;
    }
    thisTemp = thisTemp->next_;
    sourceTemp = sourceTemp->next_;
    if (thisTemp != nullptr && sourceTemp == nullptr
      || thisTemp == nullptr && sourceTemp != nullptr)
    {
      return false;
    }
  }
  return true;
}

DoubleLinkedList operator & (const DoubleLinkedList& list, const DoubleLinkedList& source)
{
  DoubleLinkedList summary;
  DoubleLinkedList::Node* tempList = list.head_;
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

DoubleLinkedList operator | (const DoubleLinkedList& list, const DoubleLinkedList& source)
{
  DoubleLinkedList summary(source);
  DoubleLinkedList::Node* tempList = list.head_;
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
