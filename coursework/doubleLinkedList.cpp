#include "doubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other)
{
  head_ = nullptr;
  tail_ = nullptr;
  count_ = 0;
  Node *n = other.head_;
  while (n)
  {
    insertTail(n->item_);
    n = n->next_;
  }
}

DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList& other)
{
  if (this != &other)
  {
    DoubleLinkedList(other).DoubleLinkedList::swap(*this);
  }
  return *this;
}

void DoubleLinkedList::swap(DoubleLinkedList& list) noexcept
{
  std::swap(count_, list.count_);
  std::swap(head_, list.head_);
  std::swap(tail_, list.tail_);
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept
{
  count_ = other.count_;
  head_ = other.head_;
  tail_ = other.tail_;

  other.count_ = 0;
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& other) noexcept
{
  count_ = other.count_;
  head_ = other.head_;
  tail_ = other.tail_;

  other.count_ = 0;
  other.head_ = nullptr;
  other.tail_ = nullptr;

  return *this;
}

void DoubleLinkedList::insertTail(Node *x)
{
  x->prev_ = tail_;
  if (tail_ != nullptr)
  {
    tail_->next_ = x;
  }
  else
  {
    head_ = x;
  }
  tail_ = x;
  count_++;
}

void DoubleLinkedList::insertHead(Node *x)
{
  x->next_ = head_;
  if (head_ != nullptr)
  {
    head_->prev_ = x;
  }
  else
  {
    tail_ = x;
  }
  head_ = x;
  count_++;
}

void DoubleLinkedList::deleteNode(Node *x)
{
  if (!x)
  {
    throw ("deleteNode - node is nullptr");
  }
  if (x->prev_)
  {
    (x->prev_)->next_ = x->next_;
  }
  else
  {
    head_ = x->next_;
  }
  if (x->next_ != nullptr)
  {
    (x->next_)->prev_ = x->prev_;
  }
  else
  {
    tail_ = x->prev_;
  }
  delete x;
  count_--;
}

DoubleLinkedList::Node *DoubleLinkedList::searchNode(int item)
{
  Node* x = head_;
  while (x != nullptr && x->item_ != item)
  {
    x = x->next_;
  }
  return x;
}

DoubleLinkedList::Node *DoubleLinkedList::replaceNode(DoubleLinkedList::Node *x, int item)
{
  x->item_ = item;
  return x;
}

int DoubleLinkedList::headItem() const
{
  if (head_ != nullptr)
  {
    return head_->item_;
  }
  throw ("headItem - list is empty");
}

int &DoubleLinkedList::headItem()
{
  if (head_ != nullptr)
  {
    return head_->item_;
  }
  throw ("headItem - list is empty");
}

int DoubleLinkedList::tailItem() const
{
  if (tail_ != nullptr)
  {
    return tail_->item_;
  }
  throw ("tailItem - list is empty");
}

int &DoubleLinkedList::tailItem()
{
  if (tail_ != nullptr)
  {
    return tail_->item_;
  }
  throw ("tailItem - list is empty");
}

void DoubleLinkedList::insertHead(int item)
{
  insertHead(new Node(item));
}

void DoubleLinkedList::insertTail(int item)
{
  insertTail(new Node(item));
}

bool DoubleLinkedList::deleteHead()
{
  if (head_ == nullptr)
  {
    return false;
  }
  deleteNode(head_);
  return true;
}

bool DoubleLinkedList::deleteTail()
{
  if (tail_ == nullptr)
  {
    return false;
  }
  deleteNode(tail_);
  return true;
}

bool DoubleLinkedList::deleteItem(const int item, bool all)
{
  Node *x = searchNode(item);
  if (x == nullptr)
  {
    return false;
  }
  if (x->prev_ != nullptr)
  {
    (x->prev_)->next_ = x->next_;
  }
  else
  {
    head_ = x->next_;
  }
  if (x->next_ != nullptr)
  {
    (x->next_)->prev_ = x->prev_;
  }
  else
  {
    tail_ = x->prev_;
  }
  delete x;
  count_--;
  if (all)
  {
    deleteItem(item, true);
  }
  return true;
}

bool DoubleLinkedList::searchItem(int item)
{
  return (searchNode(item) != nullptr);
}

bool DoubleLinkedList::replaceItem(int itemOld, int itemNew, bool all)
{
  Node *x = searchNode(itemOld);
  if (x == nullptr)
  {
    return false;
  }
  replaceNode(x, itemNew);
  if (all)
  {
    replaceItem(itemOld, itemNew, true);
  }
  return true;
}

void DoubleLinkedList::print()
{
  Node *current = head_;
  while (current != nullptr)
  {
    std::cout << current->item_ << ' ';
    current = current->next_;
  }
  std::cout << std::endl;
}

DoubleLinkedList::~DoubleLinkedList()
{
  Node *current = nullptr;
  Node *next = head_;
  while (next != nullptr)
  {
    current = next;
    next = next->next_;
    delete current;
  }
}

std::ostream& operator<<(std::ostream& outStream, const DoubleLinkedList& list)
{
  DoubleLinkedList::Node* current = list.head_;
  while (current != nullptr)
  {
    outStream << current->item_ << ' ';
    current = current->next_;
  }
  outStream << '\n';
  return outStream;
}

bool DoubleLinkedList::operator == (const DoubleLinkedList& other)
{
  Node* current1 = this->head_;
  Node* current2 = other.head_;
  while ((current1->item_) == (current2->item_))
  {
    current1 = current1->next_;
    current2 = current2->next_;
    if (current1 == nullptr) return true;
  }
  return false;
}

void DoubleLinkedList::addList(DoubleLinkedList& list)
{
  if (list.head_ != nullptr)
  {
    if (tail_ != nullptr)
    {
      Node *temp = tail_;
      tail_->next_ = list.head_;
      list.head_->prev_ = temp;
    }
    else
    {
      head_ = list.head_;
    }
  }
  tail_ = list.tail_;
  count_ += list.count_;
  list.head_ = nullptr;
  list.tail_ = nullptr;
  list.count_ = 0;
}

int DoubleLinkedList::getNode(int index)
{
  if (index < 0 || index >= count_)
  {
    throw ("getNode - index is out of range");
  }
  Node *current;
  if (index <= count_ / 2)
  {
    current = head_;
    for (int i = 0; i < index; i++)
    {
      current = current->next_;
    }
  }
  else
  {
    current = tail_;
    for (int i = count_ - 1; i > index; i--)
    {
      current = current->prev_;
    }
  }
  return current->item_;
}

DoubleLinkedList DoubleLinkedList::copy()
{
  DoubleLinkedList result = *this;
  return result;
}

bool DoubleLinkedList::isEmpty()
{
  return count_ == 0;
}

int DoubleLinkedList::getItem(int index)
{
  Node *node = head_;
  for (int i = 0; i < count(); i++)
  {
    if (i == index)
    {
      return node->item_;
    }
    if (node->next_)
    {
      node = node->next_;
    }
  }
  return 0;
}
