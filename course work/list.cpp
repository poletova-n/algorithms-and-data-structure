#include "list.hpp"

#include <string>

List::List()
{
  head_ = nullptr;
}

List::~List()
{
  node *temp;
  while (head_ != nullptr)
  {
    temp = head_;
    head_ = head_->next_;
    delete temp;
  }
}

List::List(List &&list) noexcept
{
  head_ = list.head_;
  list.head_ = nullptr;
}

int List::getSize()
{
  node *temp = head_;
  int count = 0;
  while (temp != nullptr)
  {
    count++;
    temp = temp->next_;
  }
  return count;
}

std::string List::print()
{
  node *temp = head_;
  std::string words;
  while (true)
  {
    words += temp->item_;
    temp = temp->next_;
    if (temp == nullptr)
    {
      words += ";";
      break;
    }
    words += ", ";
  }
  return words;
}

void List::addElem(std::string& str)
{
  isRussianWord(str);
  int y = getSize();
  node* x = new node(str);
  node* Time = head_;
  node* TimeNext = head_;
  int z = 1;
  if (head_ == nullptr)
  {
    head_ = x;
  }
  else
  {
    if (str < head_->item_)
    {
      x->next_ = head_;
      head_ = x;
      z = 0;
    }
    if (z == 1)
    {
      for (int i = 0; i < y; i++)
      {
        if (Time->item_ == str)
        {
          break;
        }
        if (Time->next_ == nullptr)
        {
          Time->next_ = x;
          break;
        }

        if ((str > Time->item_) && (str >= Time->next_->item_))
        {
          Time = Time->next_;
          continue;
        }
        TimeNext = Time->next_;
        Time->next_ = x;
        x->next_ = TimeNext;
      }
    }
  }
}

bool List::isRussianWord(std::string str)
{
  for (int i = 0; str[i] != '\0'; i++ )
  {
    if (str[i] > -30 || str[i] < -130)
    {
      throw std::invalid_argument("The translation was entered incorrectly, the entered word is not Russian");
    }
  }
  return true;
}

List &List::operator=(const List &elem)
{
  node* sourceNode = elem.head_;
  while (sourceNode != nullptr)
  {
    addElem(sourceNode->item_);
    sourceNode = sourceNode->next_;
  }
  return *this;
}
