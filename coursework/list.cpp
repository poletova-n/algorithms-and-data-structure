#include "list.h"
#include "details.h"
#include <iostream>

List::List(const List& list):
  pHead_(nullptr),
  pTail_(nullptr)
{
  for (Node* i = list.pHead_; i != nullptr; i = i->next_)
  {
    Node* tempNode = new Node(i->word_);
    if (pHead_ == nullptr)
    {
      pHead_ = pTail_ = tempNode;
    }
    else
    {
      pTail_->next_ = tempNode;
      tempNode->pre_ = pTail_;
      pTail_ = tempNode;
    }
  }
}

List::List(List&& list) noexcept
{
  pHead_ = list.pHead_;
  pTail_ = list.pTail_;
  list.pHead_ = nullptr;
  list.pTail_ = nullptr;
}

List::~List()
{
  while (pHead_ != nullptr)
  {
    if (pHead_ == pTail_)
    {
      pHead_ = nullptr;
    }
    else
    {
      Node* tempNode = pHead_;
      pHead_ = pHead_->next_;
      pHead_->pre_ = nullptr;
      delete tempNode;
    }
  }
  delete pHead_;
  delete pTail_;
}

List& List::operator=(const List& list)
{
  while (pHead_ != nullptr)
  {
    if (pHead_ == pTail_)
    {
      pHead_ = nullptr;
      delete pTail_;
      pTail_ = nullptr;
    }
    else
    {
      Node* tempNode = pHead_;
      pHead_ = pHead_->next_;
      pHead_->pre_ = nullptr;
      delete tempNode;
    }
  }
  for (Node* i = list.pHead_; i != nullptr; i = i->next_)
  {
    Node* tempNode = new Node(i->word_);
    if (pHead_ == nullptr)
    {
      pHead_ = pTail_ = tempNode;
    }
    else
    {
      pTail_->next_ = tempNode;
      tempNode->pre_ = pTail_;
      pTail_ = tempNode;
    }
  }
  return *this;
}

size_t List::getSize()
{
  size_t count = 0;
  for (Node* i = pHead_; i != nullptr; i = i->next_)
  {
    count++;
  }
  return count;
}

List& List::insertHead(Node* newNode)
{
  if (pHead_ == nullptr)
  {
    pHead_ = pTail_ = newNode;
  }
  else
  {
    newNode->next_ = pHead_;
    pHead_->pre_ = newNode;
    pHead_ = newNode;
  }
  return *this;
}

List& List::insertTail(Node* newNode)
{
  if (pHead_ == nullptr)
  {
    pHead_ = pTail_ = newNode;
  }
  else
  {
    pTail_->next_ = newNode;
    newNode->pre_ = pTail_;
    pTail_ = newNode;
  }
  return *this;
}

List& List::insert(std::string word)
{
  if (!isWord(word))
  {
    throw myExceptions::ErrorSyntax("Invalid word added.");
  }
  Node* newNode = new Node(word);
  if (pHead_ == nullptr)
  {
    pHead_ = pTail_ = newNode;
  }
  else
  {
    for (Node* i = pHead_; i != nullptr; i = i->next_)
    {
      if (newNode->word_.compare(i->word_) == 0)
      {
        return *this;
      }
      if (i->word_.length() > newNode->word_.length())
      {
        if (i == pHead_)
        {
          insertHead(newNode);
        }
        else
        {
          i->pre_->next_ = newNode;
          newNode->pre_ = i->pre_;
          i->pre_ = newNode;
          newNode->next_ = i;
        }
        return *this;
      }
    }
    insertTail(newNode);
  }
  return *this;
}

void List::print(std::ostream& out)
{
  for (Node* i = pHead_; i != nullptr; i = i->next_)
  {
    out << i->word_ << " ";
  }
}
