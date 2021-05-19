#include <iostream>

#ifndef _SinglyLinkedOrderedList
#define _SinglyLinkedOrderedList

template <typename T>
class SinglyLinkedOrderedList
{
public:

  SinglyLinkedOrderedList() : head_(nullptr) {} SinglyLinkedOrderedList(SinglyLinkedOrderedList&&);
  ~SinglyLinkedOrderedList();
  bool insert(T);
  bool search(T) const;
  bool deleteItem(T);

  SinglyLinkedOrderedList subtract(const SinglyLinkedOrderedList&) const; 
  SinglyLinkedOrderedList unite(SinglyLinkedOrderedList&) const; 
  SinglyLinkedOrderedList intersect(const SinglyLinkedOrderedList&) const;
  template <typename T>
friend std::ostream& operator << (std::ostream&, const SinglyLinkedOrderedList<T>&);
private:
  struct Node
  {
    T item_;
	Node* next_;
	Node(T item, Node* next = nullptr) : item_(item), next_(next) {}
  };

  Node* head_;

  Node* searchNode(T) const;

  bool insert(Node*);
};

template <typename T> SinglyLinkedOrderedList<T>::SinglyLinkedOrderedList(SinglyLinkedOrderedList&& list)
{
  head_ = list.head_;
  list.head_ = nullptr;
}

template <typename T> SinglyLinkedOrderedList<T>::~SinglyLinkedOrderedList()
{
  Node* temp = head_;
  while (head_ != nullptr) {
	  temp = head_->next_;
	  delete head_;
	  head_ = temp;
	}
}

template<typename T>
bool SinglyLinkedOrderedList<T>::insert(T item)
{
  return insert(new Node(item));
}

template <typename T>
bool SinglyLinkedOrderedList<T>::search(T item) const
{
  return (searchNode(item) != nullptr);
}

template <typename T>
bool SinglyLinkedOrderedList<T>::deleteItem(T item)
{
	Node* temp = head_;
	Node* previous = nullptr;
	while (temp != nullptr && temp->item_ != item) {
		previous = temp;
		temp = temp->next_;
	}
	if (temp == nullptr) {
		return false;
	}
	if (previous == nullptr) {
		head_ = temp->next_;
	}
	else {
		previous->next_ = temp->next_;
	}
	delete temp;
	return true;
}

  template <typename T>
  SinglyLinkedOrderedList<T> SinglyLinkedOrderedList<T>::subtract(const SinglyLinkedOrderedList & list) const
  {
	  SinglyLinkedOrderedList result;
	  Node* temp = head_;
	  Node* previous = nullptr;
	  while (temp != nullptr) {
		  if (!list.searchNode(temp->item_)) {
			  result.insert(new Node(temp->item_));
		  }
		  temp = temp->next_;
	  }
	  return result;
  }

  template <typename T>
  SinglyLinkedOrderedList<T> SinglyLinkedOrderedList<T>::unite(SinglyLinkedOrderedList<T>& list) const
  {
	  SinglyLinkedOrderedList result; Node* temp = head_;
	  while (temp != nullptr) {
		  result.insert(new Node(temp->item_));
		  temp = temp->next_;
	  }
	  temp = list.head_; Node* next = nullptr;
	  while (temp != nullptr) {
		  next = temp->next_;
		  result.insert(temp);
		  temp = next;
	  }
	  list.head_ = nullptr;
	  return result;
  }
  
  template <typename T>
  SinglyLinkedOrderedList<T> SinglyLinkedOrderedList<T>::intersect(const 
  SinglyLinkedOrderedList & list) const
  {
	  SinglyLinkedOrderedList result;
	  Node* temp = head_;
	  while (temp != nullptr) {
		  if (list.searchNode(temp->item_)) {
			  result.insert(new Node(temp->item_));
		  }
		  temp = temp->next_;
	  }
	  return result;
  }
  
  template <typename T>
  std::ostream& operator << (std::ostream & out, const SinglyLinkedOrderedList<T>&list)
  {
	  SinglyLinkedOrderedList<T>::template Node* temp = list.head_;
	  while (temp != nullptr) {
		  out << temp->item_ << ' ';
		  temp = temp->next_;
	  }
	  out << '\n'; return out;
  }
  
  template<typename T>
  SinglyLinkedOrderedList<T>::template Node* SinglyLinkedOrderedList<T>::searchNode(T item) const
  {
	  Node* temp = head_;
	  while (temp != nullptr && temp->item_ != item) {
		  temp = temp->next_;
	  }
	  return temp;
  }
  
  template <typename T>
  bool SinglyLinkedOrderedList<T>::insert(Node * node)
  {
	  if (head_ == nullptr) {
		  head_ = node;
		  return true;
	  }
	  Node* temp = head_;
	  while (temp->next_ != nullptr && temp->next_->item_ < node->item_) {
		  temp = temp->next_;
	  }
	  if (temp == head_) {
		  if (temp->item_ < node->item_) {
			  if (temp->next_ != nullptr && temp->next_->item_ == node->item_) {
				  return false;
			  }
			  node->next_ = temp->next_;
			  temp->next_ = node;
			  return true;
		  }
		  else if (temp->item_ > node->item_) {
			  head_ = node;
			  node->next_ = temp;
			  return true;
		  }
		  return false;
	  }
	  else if (temp->next_ == nullptr) {
		  temp->next_ = node;
		  node->next_ = nullptr;
		  return true;
	  }
	  else if (temp->next_->item_ != node->item_) {
		  node->next_ = temp->next_;
		  temp->next_ = node; return true;
	  }
	  return false;
  }
#endif
