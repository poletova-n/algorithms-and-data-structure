#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class T>
class List
{
public:
  List();
  List(const List& copy);
  List(List&& copy) noexcept;
  ~List();

  void operator+=(T data);
private:
	struct Node
	{
		T data_;
		Node* next_;
		Node(T data, Node* next = nullptr) : data_(data), next_(next) { }
	};
	Node* head_;
	int count_;
	void insert(Node* list);
};

template <class T>
void List<T>::insert(Node* node)
{
  if (this->head_ == nullptr)
  {
    this->head_ = node;
    count_++;
    return;
  }
  Node* current = head_;
  while (current->next_ != nullptr && current->next_->data_ <= node->data_)
  {
    current = current->next_;
  }
  if (current == head_)
  {
    if (current->data_ > node->data_)
    {
      node->next_ = head_;
      head_ = node;
      count_++;
    }
    else if (current->data_ < node->data_)
    {
      node->next_ = head_->next_;
      head_->next_ = node;
      count_++;
    }
    return;
  }
  if (current->next_ != nullptr)
  {
    if (current->next_->data_ != node->data_ && current->data_ != node->data_)
    {
      node->next_ = current->next_;
      current->next_ = node;
      count_++;
    }
    return;
  }
  else if (current->next_ == nullptr && current->data_ == node->data_)
  {
    return;
  }
  count_++;
  current->next_ = node;
}

template <class T>
List<T>::List()
{
  this->head_ = nullptr;
  this->count_ = 0;
}

template <class T>
List<T>::List(List<T>&& copy) noexcept
{
  this->head_ = copy.head_;
  this->count_ = copy.count_;
  copy.head_ = nullptr;
  copy.count_ = 0;
}

template <class T>
List<T>::List(const List<T>& copy)
{
  Node* temp = copy.head_;
  while (temp != nullptr)
  {
    this->insert(new Node(temp->data_));
    temp = temp->next_;
  }
}

template <class T>
List<T>::~List()
{
  Node* next = this->head_;
  while (next != nullptr)
  {
    next = head_->next_;
    delete head_;
    head_ = next;
  }
}

template <class T>
void List<T>::operator+=(T data)
{
  Node* temp = new Node(data);
  this->insert(temp);
}

#endif // !LIST_H
