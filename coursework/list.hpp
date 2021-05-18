#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template<class T>
class DoubleLinkedList
{
private:
  struct Node
  {
    T item_;
    int weight_;
    Node* next_;
    Node* prev_;
    Node(T item, int weight = 0, Node* next = nullptr, Node* prev = nullptr) : item_(item), weight_(weight), next_(next), prev_(prev) { }
  };

  int count_;
  Node* head_;
  Node* tail_;

public:
  DoubleLinkedList();
  DoubleLinkedList(const DoubleLinkedList& src);
  virtual ~DoubleLinkedList();
  DoubleLinkedList& operator=(const DoubleLinkedList& a);
  DoubleLinkedList& operator=(DoubleLinkedList&& a);

  int count() const;
  bool isEmpty();
  void insertHead(T item, int weight);
  void insertTail(T item, int weight);
  void insertItem(T item);
  bool deleteHead();
  bool deleteTail();
  bool deleteItem(const T item);

  bool searchItem(T item);
  bool replaceItem(T itemOld, T itemNew);
  void outAll();

  Node* head() const;
  Node* tail() const;
  void insertNode(Node* x);
  void deleteNode(Node* x = nullptr);
  Node* searchNode(T item);
  Node* replaceNode(Node* x, T item);

  template <typename G>
  friend bool operator==(const DoubleLinkedList& list1, const DoubleLinkedList& list2);
  friend std::ostream& operator<<(std::ostream& out, DoubleLinkedList& list)
  {
    list.outAll();
    return out;
  }
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {  }

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& src) : count_(0), head_(nullptr), tail_(nullptr)
{
  Node* temp = src.head_;
  while (temp != nullptr)
  {
    insertTail(temp->item_, temp->weight_);
    temp = temp->next_;
  }
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
  Node* current = nullptr;
  Node* next = head_;
  while (next != nullptr)
  {
    current = next;
    next = next->next_;
    delete current;
  }
}

template<class T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& a)
{
  if (*this == a)
  {
    return *this;
  }
  Node* temp = a.head_;
  while (temp != nullptr)
  {
    insertTail(temp->item_, temp->weight_);
    temp = temp->next_;
  }
  return *this;
}

template<class T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(DoubleLinkedList&& src)
{
  if (this != &src)
  {
    count_ = -1;
    DoubleLinkedList temp(src);
    head_ = temp.head_;
    tail_ = temp.tail_;
    count_ = temp.count_;
    src.~DoubleLinkedList();
    temp.head_ = nullptr;
    temp.tail_ = nullptr;
    temp.count_ = 0;
  }
  return *this;
}

template<class T>
int DoubleLinkedList<T>::count()const
{
  return count_;
}
template<class T>
bool DoubleLinkedList<T>::isEmpty()
{
  return count_ == 0;
}

template<class T>
void DoubleLinkedList<T>::insertHead(T item, int weight)
{
  if (count_ == 0)
  {
    head_ = new Node(item, weight, head_);
    tail_ = head_;
  }
  else
  {
    head_ = new Node(item, weight, head_);
    (head_->next_)->prev_ = head_;
  }
  count_++;
}

template<class T>
void DoubleLinkedList<T>::insertTail(T item, int weight)
{
  if (count_ == 0)
  {
    head_ = new Node(item, weight, head_);
    tail_ = head_;
  }
  else
  {
    tail_ = new Node(item, weight, nullptr, tail_);
    (tail_->prev_)->next_ = tail_;
  }
  count_++;
}

template<class T>
void DoubleLinkedList<T>::insertItem(T item)
{
  insertNode(new Node(item));
}

template<class T>
bool DoubleLinkedList<T>::deleteHead()
{
  if (head_ == nullptr)
  {
    return 0;
  }
  deleteNode(head_);
  return 1;
}

template<class T>
bool DoubleLinkedList<T>::deleteTail()
{
  if (head_ == nullptr)
  {
    return 0;
  }
  deleteNode(tail_);
  return 1;
}

template<class T>
bool DoubleLinkedList<T>::deleteItem(const T item)
{
  if (searchItem(item) == 0)
  {
    std::cout << "Incorrect value for delete\n ";
    return 0;
  }
  else
  {
    deleteNode(searchNode(item));
    return 1;
  }
}

template<class T>
bool DoubleLinkedList<T>::searchItem(T item)
{
  return (searchNode(item) != nullptr);
}

template<class T>
bool DoubleLinkedList<T>::replaceItem(T itemOld, T itemNew)
{
  if (searchItem(itemOld) == 0)
  {
    std::cout << "Incorrect value for replacing ";
    return 0;
  }
  else
  {
    return (replaceNode(searchNode(itemOld), itemNew) != nullptr);
  }
}

template<class T>
void DoubleLinkedList<T>::outAll()
{
  Node* current = head_;
  while (current != nullptr)
  {
    //    if (current != tail_)
    //    {
    //      std::cout << current->item_ << ' ';
    //    }
    //    else
    //    {
    //      std::cout << current->item_;
    //    }
    std::cout << current->item_ << ' ';
    current = current->next_;
  }
  std::cout << std::endl;
}

template<class T>
bool operator==(const DoubleLinkedList<T>& list1, const DoubleLinkedList<T>& list2)
{
  if (list1.count() == list2.count())
  {
    int counter = list1.count();
    int check = 0;
    while (counter != 0)
    {
      if ((list1.head() == list2.head()) && ((list1.head()->next_)->prev_ == list1.head()) && ((list2.head()->next_)->prev_ == list2.head()))
      {
        check++;
      }
      counter--;
    }
    if (check == list1.count())
    {
      return 1;
    }
  }
  return 0;
}

template<class T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::head() const
{
  return head_;
}

template<class T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::tail() const
{
  return tail_;
}

template<class T>
void DoubleLinkedList<T>::insertNode(Node* x)
{
  if (head_ == nullptr)
  {
    x->next_ = nullptr;
    head_ = x;
    tail_ = x;
    head_->next_ = nullptr;
    head_->prev_ = nullptr;
  }
  else
  {
    Node* temp = head_;
    while (temp->next_ != nullptr)
    {
      temp = temp->next_;
    }
    temp->next_ = x;
    x->next_ = nullptr;
    x->prev_ = temp;
  }
}

template<class T>
void DoubleLinkedList<T>::deleteNode(Node* x)
{
  if (count_ > 0) {
    if (count_ == 1) {
      head_ = nullptr;
      tail_ = nullptr;
      x->next_ = nullptr;
      x->prev_ = nullptr;
      delete x;
      count_--;
    }
    else {
      if (x == nullptr) {
        throw ("DoubleLinkedList::deleteNode  - incorrect address of deleting node");
      }
      if ((x->prev_ != nullptr) && (x->next_ != nullptr)) {
        (x->prev_)->next_ = x->next_;
        (x->next_)->prev_ = x->prev_;
        x->next_ = nullptr;
        x->prev_ = nullptr;
      }
      if ((x->prev_ == nullptr) && (x->next_ != nullptr)) {
        head_ = x->next_;
        head_->prev_ = nullptr;
        (head_->next_) = (x->next_)->next_;
        x->next_ = nullptr;
      }
      if ((x->prev_ != nullptr) && (x->next_ == nullptr)) {
        tail_ = x->prev_;
        tail_->next_ = nullptr;
        (tail_->prev_) = (x->prev_)->prev_;
        x->prev_ = nullptr;
      }
      delete x;
      count_--;
    }
  }
}

template<class T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::searchNode(T item)
{
  Node* x = head_;
  while (x != nullptr && x->item_ != item)
  {
    x = x->next_;
  }
  return x;
}

template<class T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::replaceNode(DoubleLinkedList<T>::Node* x, T item)
{
  x->item_ = item;
  return x;
}

#endif
