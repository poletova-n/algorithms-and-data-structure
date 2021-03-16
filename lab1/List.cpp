#include "List.hpp"

List::List()
{
  head_ = nullptr;
  count_ = 0;
}

List::List(const List &object)
{
  if (object.head_ == nullptr)
  {
    head_ = nullptr;
    count_ = 0;
  }
  else
  {
    this->count_ = object.count_;
    Node *tempObject = object.head_;
    this->head_ = new Node(tempObject->data_);
    Node *tempThis = this->head_;
    while (tempObject->next_ != nullptr)
    {
      tempObject = tempObject->next_;
      tempThis->next_ = new Node(tempObject->data_);
      tempThis = tempThis->next_;
    }
  }
}

void List::print()
{
  Node *temp = head_;
  while (temp->next_ != nullptr)
  {
    std::cout << temp->data_ << " ";
    temp = temp->next_;
  }
  std::cout << temp->data_ << "\n";
}

void List::operator-=(int data)
{
  Node *tempCurrent = head_;
  Node *tempPrev = nullptr;
  while (tempCurrent->next_ != nullptr)
  {
    if (tempCurrent->data_ == data)
    {
      if (tempCurrent == head_)  //if first item
      {
        tempCurrent = tempCurrent->next_;
        delete head_;
        head_ = tempCurrent;
      }
      else  //if not first and not last item
      {
        Node *temp = tempCurrent->next_;
        delete tempCurrent;
        tempPrev->next_ = temp;
        tempCurrent = tempPrev;
      }
      count_ -= 1;
    }
    tempPrev = tempCurrent;
    tempCurrent = tempCurrent->next_;
  }
  if (tempCurrent->data_ == data)  //if last item
  {
    count_ -= 1;
    delete tempPrev->next_;
    tempPrev->next_ = nullptr;
  }
}

void List::operator=(const List &object)
{
  if (object.head_ == nullptr)
  {
    head_ = nullptr;
    count_ = 0;
  }
  else
  {
    this->count_ = object.count_;
    Node *tempObject = object.head_;
    this->head_ = new Node(tempObject->data_);
    Node *tempThis = this->head_;
    while (tempObject->next_ != nullptr)
    {
      tempObject = tempObject->next_;
      tempThis->next_ = new Node(tempObject->data_);
      tempThis = tempThis->next_;
    }
  }
}

List::~List()
{
  if (head_ != nullptr)
  {
    Node *temp1 = head_;
    Node *temp2 = temp1->next_;
    while (temp1->next_ != nullptr)
    {
      delete temp1;
      temp1 = temp2;
      temp2 = temp2->next_;
    }
    delete temp1;
    count_ = 0;
    head_ = nullptr;
  }
}

void List::operator+=(int data)
{
  if (head_ == nullptr)
  {
    head_ = new Node(data);
    count_ += 1;
  }
  else
  {
    for (int i = 1; i <= count_; i++)
    {
      if (data == (*this)[i])
      {
        throw "Adding a repeating element";
      }
    }
    Node *tempCurrent = head_;
    Node *tempPrev = nullptr;
    while ((data > tempCurrent->data_) && (tempCurrent->next_ != nullptr))
    {
      tempPrev = tempCurrent;
      tempCurrent = tempCurrent->next_;
    }
    if (data < tempCurrent->data_)
    {
      if (tempPrev != nullptr)
      {
        tempPrev->next_ = new Node(data, tempCurrent);
      }
      else
      {
        tempPrev = head_;
        tempPrev = new Node(data, tempCurrent);
        head_ = tempPrev;
      }
    }
    else
    {
      tempCurrent->next_ = new Node(data);
    }
    count_ += 1;
  }
}

std::ostream &operator<<(std::ostream &output, List &object)
{
  if (object.head_ == nullptr)
  {
    output << "The list is empty";
  }
  else
  {
    List::Node *temp = object.head_;
    while (temp->next_ != nullptr)
    {
      output << temp->data_ << " ";
      temp = temp->next_;
    }
    output << temp->data_;
  }
  return output;
}

bool List::operator==(List &object)
{
  if (this->count_ != object.count_)
  {
    return false;
  }
  else
  {
    if (this->count_ == 0)
    {
      return true;
    }
    else
    {
      for (int i = 1; i <= this->count_; i++)
      {
        if (object[i] != (*this)[i])
        {
          return false;
        }
      }
      return true;
    }
  }
}

List operator&(List &object1, List &object2)
{
  List temp;
  for (int i = 1; i <= object2.count_; i++)
  {
    bool check = false;
    for (int j = 1; j <= object1.count_; j++)
    {
      if (object2[i] == object1[j])
      {
        check = true;
      }
    }
    if (check)
    {
      temp += object2[i];
    }
  }
  return temp;
}

int List::operator[](int size)
{
  if ((this->count_ < size) || (size <= 0))
  {
    throw "Going outside the list";
  }
  else
  {
    Node *temp = this->head_;
    for (int i = 1; i < size; i++)
    {
      temp = temp->next_;
    }
    return temp->data_;
  }
}

List operator|(List &object1, List &object2)
{
  List temp;
  for (int i = 1; i <= object2.count_; i++)
  {
    temp += object2[i];
  }
  for (int i = 1; i <= object1.count_; i++)
  {
    bool check = true;
    for (int j = 1; j <= temp.count_; j++)
    {
      if (object1[i] == temp[j])
      {
        check = false;
      }
    }
    if (check)
    {
      temp += object1[i];
    }
  }
  return temp;
}

void List::merge(List &object)
{
  for (int i = 1; i <= object.count_; i++)
  {
    bool check = true;
    for (int j = 1; j <= this->count_; j++)
    {
      if ((*this)[j] == object[i])
      {
        check = false;
      }
    }
    if (check)
    {
      *this += object[i];
    }
  }
  if (object.head_ != nullptr)
  {
    Node *temp1 = object.head_;
    Node *temp2 = temp1->next_;
    while (temp1->next_ != nullptr)
    {
      delete temp1;
      temp1 = temp2;
      temp2 = temp2->next_;
    }
    delete temp1;
    object.count_ = 0;
    object.head_ = nullptr;
  }
}
