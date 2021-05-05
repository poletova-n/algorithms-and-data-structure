#include "SinglyLinkedOrderedList.h"
#include <iostream>

SinglyLinkedOrderedList::SinglyLinkedOrderedList() :
  head_(nullptr),
  tail_(nullptr),
  count_(0)
{}

SinglyLinkedOrderedList::SinglyLinkedOrderedList(const SinglyLinkedOrderedList& src):
  head_(nullptr),
  tail_(nullptr)
{
  head_ = src.head_;
  tail_ = src.tail_;
  count_ = src.count_;
}

SinglyLinkedOrderedList::SinglyLinkedOrderedList(SinglyLinkedOrderedList &&list) noexcept
{
  head_ = list.head_;
  tail_ = list.tail_;
  count_ = list.count_;
  list.head_ = nullptr;
  list.tail_ = nullptr;
  list.count_ = 0;
}

void SinglyLinkedOrderedList::insert(std::string& word)
{
  if(parse(word) == false)
  {
    throw std::invalid_argument("Word must be contain of English letter and -");
  }
  Node *time = head_;
  if (head_ == nullptr)
  {
    head_ = new Node(word, nullptr);
    tail_ = new Node(word, nullptr);
    count_++;
  }
  else
  {
    if (word < time->word_)
    {
      head_ = new Node(word, time);
      count_++;
    }
    else
    {
      int counter = 0;
      for (int i = 0; i < count_; i++)
      {
        if (word == time->word_)
        {
          throw std::invalid_argument("We already have such an element!");
        }
        else if (word > time->word_ && i != count_ - 1)
        {
          if ((time->next_->word_) > word)
          {
            counter = 1;
            break;
          }
          time = time->next_;
        }
      }
      if (counter == 0)
      {
        tail_ = new Node(word, nullptr);
        time->next_ = tail_;
        count_++;
      }
      else if (counter == 1)
      {
        Node *newNode = new Node(word, time->next_);
        time->next_ = newNode;
        count_++;
      }
    }
  }
}

SinglyLinkedOrderedList::Node *SinglyLinkedOrderedList::searchNode(std::string& word)
{
  Node *x = head_;
  while (x != nullptr && x->word_ != word)
  {
    x = x->next_;
  }
  return x;
}

bool SinglyLinkedOrderedList::search(std::string& word)
{
  return (searchNode(word) != nullptr);
}

void SinglyLinkedOrderedList::deleteNode(Node *x)
{
  if (x == nullptr)
  {
    throw std::invalid_argument("The address of the deleted node is set incorrectly");
  }
  Node *tmp = head_;
  for (int i = 0; i < count_; i++)
  {
    if (tmp->next_ == x)
    {
      tmp->next_ = x->next_;
      break;
    }
    tmp = tmp->next_;
  }
  if (x->word_ == head_->word_)
  {
    head_ = head_->next_;
  }
  else if (x->word_ == tail_->word_)
  {
    tail_ = tmp;
  }
  delete x;
  count_--;
}

bool SinglyLinkedOrderedList::deleteWord(std::string& word)
{
  if (head_ != nullptr && head_->next_ != nullptr)
  {
    Node *newNode = head_;
    int counter = 0;
    for (int i = 0; i < count_; i++)
    {
      if (newNode->word_ != word)
      {
        newNode = newNode->next_;
      }
      else if (newNode->word_ == word)
      {
        counter = 1;
        break;
      }
    }
    if (counter == 1)
    {
      deleteNode(newNode);
    }
  }
  else if (head_->word_ == word)
  {
    deleteNode(head_);
  }
  return (searchNode(word) == nullptr);
}

SinglyLinkedOrderedList::~SinglyLinkedOrderedList()
{
  while (head_ != nullptr)
  {
    if (head_)
    {
      Node *newHead = head_->next_;
      delete head_;
      head_ = newHead;
    }
  }
}

SinglyLinkedOrderedList &SinglyLinkedOrderedList::operator = (const SinglyLinkedOrderedList &src)
{
  Node* sourceNode = src.head_;
  while (sourceNode != nullptr)
  {
    insert(sourceNode->word_);
    sourceNode = sourceNode->next_;
  }
  return *this;
}

bool SinglyLinkedOrderedList::parse(std::string &word)
{
  for (int i = 0; i < word.size(); i++)
  {
    if ((word[i] < 'A' || word[i] > 'z') && (word[i] != '-'))
    {
      return false;
    }
  }
  return true;
}
