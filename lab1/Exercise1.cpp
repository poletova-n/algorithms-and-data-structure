#include<iostream>
using namespace std;

//=================================NODE==================================================//

class Node
{
private:
	int data_;
	Node* next_;
public:
	Node() : data_(0), next_(nullptr) {}
	Node(int data) : data_(data), next_(nullptr) {}
	Node(const Node& node)
	{
		data_ = node.data_;
		next_ = node.next_;
	}
	Node(Node&& node) noexcept
	{
		data_ = node.data_;
		next_ = node.next_;
		data_ = 0;
		node.next_ = nullptr;
	}
	~Node()
	{
		/*data_ = 0;
		delete next_;*/
	}
	void setData(int);
	void setNext(Node*);
	int getData() const;
	Node* getNext();
	Node& operator= (const Node& node);
	Node& operator= (Node&& node) noexcept;
	friend bool operator== (const Node&, const Node&);
	friend bool operator > (const Node&, const Node&);

};

void Node::setData(int data)
{
	data_ = data;
}
void Node::setNext(Node* next)
{
	next_ = next;
}
int Node::getData() const
{
	return data_;
}
Node* Node::getNext()
{
	return next_;
}

Node& Node::operator= (const Node& node)
{
	if (this == &node)
	{
		return *this;
	}
	data_ = node.data_;
	next_ = node.next_;
	return *this;
}

Node& Node::operator= (Node&& node) noexcept
{
	if (this == &node)
	{
		return *this;
	}
	data_ = node.data_;
	node.data_ = 0;
	next_ = node.next_;
	node.next_ = nullptr;
	return *this;
}

bool operator== (const Node& node1, const Node& node2)
{
	return (node1.data_ == node2.data_);
}

bool operator > (const Node& node1, const Node& node2)
{
	return (node1.data_ > node2.data_);
}

//====================================Double Linked List===========================================//

class List
{
private:
	Node* pHead_;
	Node* pTail_;
public:
	List()
	{
		pHead_ = nullptr;
		pTail_ = nullptr;
	}
	List(const List& list)
	{
		pHead_ = nullptr;
		pTail_ = nullptr;
		pHead_ = list.pHead_;
		pTail_ = list.pTail_;
	}
	List(List&& list) noexcept
	{
		pHead_ = list.pHead_;
		pTail_ = list.pTail_;
		list.pHead_ = nullptr;
		list.pTail_ = nullptr;
	}
	~List() {}
	Node* getHead() const;
	Node* getTail() const;


	List& insertHead(Node*);
	List& insertTail(Node*);
	List& insert_advance(Node*, Node*);
	List& insert_later(Node*, Node*);
	size_t lenght() const;
	List& deleteElement(Node*);

	List& operator= (const List& list);
	List& operator= (List&& list) noexcept;

	List& operator+= (Node*);
	friend void operator<< (ostream& out, const List& list);
	friend bool operator==(const List&, const List&);
	friend List operator& (const List&, const List&);
	friend List operator| (const List&, const List&);
	List& merge(List&);
};

Node* List::getHead() const
{
	return this->pHead_;
}
Node* List::getTail() const
{
	return this->pTail_;
}


List& List::insertHead(Node* node)
{
	if (pHead_ == nullptr)
	{
		pHead_ = pTail_ = node;
	}
	else
	{
		node->setNext(pHead_);
		pHead_ = node;
	}
	return *this;
}
List& List::insertTail(Node* node)
{
	if (pHead_ == nullptr)
	{
		pHead_ = pTail_ = node;
	}
	else
	{
		pTail_->setNext(node);
		pTail_ = node;
	}
	return *this;
}

List& List::insert_advance(Node* p, Node* node)
{
	if (p == this->pHead_)
	{
		this->insertHead(node);
	}
	else
	{
		for (Node* i = pHead_; i != nullptr; i = i->getNext())
		{
			if (i->getNext() == p)
			{
				node->setNext(i->getNext());
				i->setNext(node);
				return *this;
			}
		}
	}
	return *this;
}

List& List::insert_later(Node* p, Node* node)
{
	if (p == pTail_)
	{
		this->insertTail(node);
	}
	else
	{
		node->setNext(p->getNext());
		p->setNext(node);
	}
	return *this;
}

size_t List::lenght() const
{
	size_t count = 0;
	for (Node* i = this->getHead(); i != nullptr; i = i->getNext())
	{
		++count;
	}
	return count;
}

List& List::deleteElement(Node* node)
{
	if (this->lenght() > 1)
	{
		if (node == pHead_)
		{
			pHead_ = node->getNext();
			node->setNext(nullptr);
		}
		else
		{
			if (node == pTail_)
			{
				Node* temp = pHead_;
				while (temp->getNext() != pTail_)
				{
					temp = temp->getNext();
				}
				pTail_ = temp;
				temp->setNext(nullptr);
			}
			else
			{
				Node* temp = pHead_;
				while (temp->getNext() != node)
				{
					temp = temp->getNext();
				}
				temp->setNext(node->getNext());
				node->setNext(nullptr);
			}
		}
	}
	else
	{
		pHead_ = pTail_ = nullptr;
	}
	return *this;
}

List& List::operator= (const List& list)
{
	this->pHead_ = list.pHead_;
	this->pTail_ = list.pTail_;
	return *this;
}

List& List::operator= (List&& list) noexcept
{
	this->pHead_ = list.pHead_;
	this->pTail_ = list.pTail_;
	list.pHead_ = nullptr;
	list.pTail_ = nullptr;
	return *this;
}

List& List::operator+= (Node* node)
{
	if (pHead_ == nullptr)
	{
		this->insertHead(node);
		return *this;
	}
	else
	{
		for (Node* i = pHead_; i != nullptr; i = i->getNext())
		{
			if (node->getData() == i->getData())
			{
				return *this;
			}
			if (node->getData() < i->getData())
			{
				this->insert_advance(i, node);
				return *this;
			}
		}
		this->insertTail(node);
		return *this;
	}
}


void operator<< (ostream& out, const List& list)
{
	if (list.getHead() != nullptr)
	{
		for (Node* i = list.getHead(); i != nullptr; i = i->getNext())
		{
			cout << i->getData() << "  ";
		}
		cout << endl;
	}
	else
	{
		cout << "The list is empty." << endl;
	}
}
bool operator==(const List& list1, const List& list2)
{
	size_t count1 = list1.lenght();
	size_t count2 = list2.lenght();
	if (count1 == count2)
	{
		Node* tempList1 = list1.pHead_;
		Node* tempList2 = list2.pHead_;
		for (size_t i = 0; i < count1; i++)
		{
			if (tempList1->getData() != tempList2->getData())
			{
				return 0;
			}
			tempList1 = tempList1->getNext();
			tempList2 = tempList2->getNext();
		}
		return 1;
	}
	else
	{
		return 0;
	}

}
List operator& (const List& list1, const List& list2)
{
	List list3;
	int index = 0;				//biến này để lưu chỉ số của phần từ của danh sách thứ 2 trùng để vòng lặp sau chỉ cần lặp từ phần tử đó thôi
	for (Node* i = list1.getHead(); i != nullptr; i = i->getNext())		//xét danh sách đầu tiên
	{
		int count = index;
		if (count == 0)
		{
			int condition = 1;
			for (Node* j = list2.getHead(); (j != nullptr && condition == 1); j = j->getNext())
			{
				++count;
				if (i->getData() == j->getData())
				{
					Node* ptr = new Node(i->getData());
					list3 += ptr;
					index = count;
					condition = 0;
				}
				if (i->getData() < j->getData())
				{
					condition = 0;
				}
			}
		}
		else
		{
			Node* temp = list2.getHead();
			for (int j = 0; j < index; ++j)
			{
				temp = temp->getNext();
			}
			int condition = 1;
			for (Node* j = temp; (j != nullptr && condition == 1); j = j->getNext())
			{
				++count;
				if (i->getData() == j->getData())
				{
					Node* ptr = new Node(i->getData());
					list3 += ptr;
					index = count;
					condition = 0;
				}
				if (i->getData() < j->getData())
				{
					condition = 0;
				}
			}
		}

	}
	return list3;
}

List operator| (const List& list1, const List& list2)
{
	List list3;
	for (Node* i = list1.getHead(); i != nullptr; i = i->getNext())
	{
		if (list3.getTail() == nullptr || (list3.getTail()->getData() != i->getData()))
		{
			Node* temp = new Node(i->getData());
			list3 += temp;
		}
	}
	for (Node* i = list2.pHead_; i != nullptr; i = i->getNext())
	{
		int condition = 1;
		int check = 0;
		for (Node* j = list3.pHead_; (j != nullptr && condition == 1); j = j->getNext())
		{
			if (j->getData() > i->getData())
			{
				condition = 0;
			}
			else
			{
				if (i->getData() == j->getData())
				{
					check = 1;
				}
			}
		}
		if (check == 0)
		{
			Node* ptr = new Node(i->getData());
			list3 += ptr;
		}
	}
	return list3;
}

List& List::merge(List& list)
{
	if (this == &list)
	{
		return *this;
	}
	else
	{
		if (list.pHead_ != nullptr)
		{
			if (this->pHead_ == nullptr)
			{
				this->pHead_ = list.pHead_;
				this->pTail_ = list.pTail_;
				list.pHead_ = nullptr;
				list.pTail_ = nullptr;
			}
			else
			{
				size_t lengh = list.lenght();
				for (size_t i = 0; i < lengh; ++i)
				{
					Node* temp = list.pHead_;
					list.deleteElement(temp);
					*this += temp;
				}
			}
		}
		return *this;
	}
}

int main()
{

	List list1;
	int a;
	cout << "Number of elements: "; cin >> a;
	for (int i = 0; i < a; ++i)
	{
		int k;
		cout << "Enter element " << (i + 1) << " : ";
		cin >> k;
		Node* temp = new Node(k);
		list1 += temp;
	}
	cout << "List 1: " << list1;
	cout << "\n\n";



	List list2;
	int b;
	cout << "Number of elements: "; cin >> b;
	for (int i = 0; i < b; ++i)
	{
		int k;
		cout << "Enter element " << (i + 1) << " : ";
		cin >> k;
		Node* temp = new Node(k);
		list2 += temp;
	}
	cout << "List 2: " << list2;
	cout << "\n\n";
	list2.merge(list1);

	cout << "List 2: " << list2;
	cout << "\n\n";

	return 0;
}