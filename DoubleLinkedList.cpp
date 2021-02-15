#include "DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList()
{
	head_ = nullptr;
	count_ = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& object)
{
	if (object.head_ == nullptr)
	{
		this->head_ = nullptr;
		this->count_ = 0;
	}
	else
	{
		this->count_ = object.count_;
		Node* tempObject = object.head_;
		this->head_ = new Node(tempObject->data_);
		Node* tempThis = this->head_;
		while (tempObject->next_ != nullptr)
		{
			Node* tempPrev = tempThis;
			tempObject = tempObject->next_;
			tempThis->next_ = new Node(tempObject->data_, nullptr, tempPrev);
			tempThis = tempThis->next_;
		}
	}
}

DoubleLinkedList::~DoubleLinkedList()
{
	if (head_ != nullptr)
	{
		Node* temp1 = head_;
		Node* temp2 = temp1->next_;
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

void DoubleLinkedList::merge(DoubleLinkedList& object)
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
		Node* temp1 = object.head_;
		Node* temp2 = temp1->next_;
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

void DoubleLinkedList::operator = (const DoubleLinkedList& object)
{
	if (object.head_ == nullptr)
	{
		this->head_ = nullptr;
		this->count_ = 0;
	}
	else
	{
		this->count_ = object.count_;
		Node* tempObject = object.head_;
		this->head_ = new Node(tempObject->data_);
		Node* tempThis = this->head_;
		while (tempObject->next_ != nullptr)
		{
			Node* tempPrev = tempThis;
			tempObject = tempObject->next_;
			tempThis->next_ = new Node(tempObject->data_, nullptr, tempPrev);
			tempThis = tempThis->next_;
		}
	}
}

void DoubleLinkedList::operator += (int data)
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
		Node* tempCurrent = head_;
		Node* tempPrev = nullptr;
		while ((data > tempCurrent->data_) && (tempCurrent->next_ != nullptr))
		{
			tempPrev = tempCurrent;
			tempCurrent = tempCurrent->next_;
		}
		if (data < tempCurrent->data_)
		{
			if (tempPrev != nullptr)
			{
				tempPrev->next_ = new Node(data, tempCurrent, tempPrev);
				tempCurrent->prev_ = tempPrev->next_;
			}
			else
			{
				tempPrev = head_;
				tempPrev = new Node(data, tempCurrent);
				head_ = tempPrev;
				tempCurrent->prev_ = head_;
			}
		}
		else
		{
			tempCurrent->next_ = new Node(data, nullptr, tempCurrent);
		}
		count_ += 1;
	}
}

int DoubleLinkedList::operator [] (int size)
{
	if ((this->count_ < size) || (size <= 0))
	{
		throw "Going outside the list";
	}
	else
	{
		Node* temp = this->head_;
		for (int i = 1; i < size; i++)
		{
			temp = temp->next_;
		}
		return temp->data_;
	}
}

std::ostream& operator<<(std::ostream& output, DoubleLinkedList& object)
{
	if (object.head_ == nullptr)
	{
		output << "The list is empty";
	}
	else
	{
		DoubleLinkedList::Node* temp = object.head_;
		while (temp->next_ != nullptr)
		{
			output << temp->data_ << " ";
			temp = temp->next_;
		}
		output << temp->data_;
	}
	return output;
}

bool DoubleLinkedList::operator == (DoubleLinkedList& object)
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

DoubleLinkedList operator & (DoubleLinkedList& object1, DoubleLinkedList& object2)
{
	DoubleLinkedList temp;
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

DoubleLinkedList operator | (DoubleLinkedList& object1, DoubleLinkedList& object2)
{
	DoubleLinkedList temp;
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