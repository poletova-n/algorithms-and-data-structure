#include<iostream>
using namespace std;
//hehe
						//=================================NODE==================================================//
class Node
{
private:
	int data_;
	Node* next_;
	Node* pre_;
public:
	Node() : data_(0), next_(nullptr), pre_(nullptr) {}
	Node(int data) : data_(data), next_(nullptr), pre_(nullptr) {}
	Node(const Node& node)
	{
		data_ = node.data_;
		next_ = node.next_;
		pre_ = node.pre_;
	}
	Node(Node&& node) noexcept
	{
		data_ = node.data_;
		next_ = node.next_;
		pre_ = node.pre_;
		data_ = 0;
		node.next_ = nullptr;
		node.pre_ = nullptr;
	}
	~Node()
	{
		/*data_ = 0;
		delete next_;
		delete pre_;*/
	}
	void setData(int);
	void setNext(Node*);
	void setPreious(Node*);
	int getData() const;
	Node* getNext();
	Node* getPrevious();
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
void Node::setPreious(Node* pre)
{
	pre_ = pre;
}
int Node::getData() const
{
	return data_;
}
Node* Node::getNext()
{
	return next_;
}
Node* Node::getPrevious()
{
	return pre_;
}

Node& Node::operator= (const Node& node)
{
	if (this == &node)
	{
		return *this;
	}
	data_ = node.data_;
	next_ = node.next_;
	pre_ = node.pre_;
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
	pre_ = node.pre_;
	node.next_ = nullptr;
	node.pre_ = nullptr;
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

//====================================Double Linked List==================================================//

class DoubleLinkedList
{
private:
	Node* pHead_;
	Node* pTail_;
public:
	DoubleLinkedList()
	{
		pHead_ = nullptr;
		pTail_ = nullptr;
	}
	DoubleLinkedList(const DoubleLinkedList& list)
	{
		pHead_ = nullptr;
		pTail_ = nullptr;
		pHead_ = list.pHead_;
		pTail_ = list.pTail_;
	}
	DoubleLinkedList(DoubleLinkedList&& list) noexcept
	{
		pHead_ = list.pHead_;
		pTail_ = list.pTail_;
		list.pHead_ = nullptr;
		list.pTail_ = nullptr;
	}
	~DoubleLinkedList() {}
	Node* getHead() const;
	Node* getTail() const;


	DoubleLinkedList& insertHead(Node*);
	DoubleLinkedList& insertTail(Node*);
	DoubleLinkedList& insert_advance(Node*, Node*);
	DoubleLinkedList& insert_later(Node*, Node*);
	size_t lenght() const;
	DoubleLinkedList& deleteElement(Node*);

	DoubleLinkedList& operator= (const DoubleLinkedList&);
	DoubleLinkedList& operator= (DoubleLinkedList&& doubleLinkedList) noexcept;

	DoubleLinkedList& operator+= (Node*);
	friend void operator<< (ostream&, const DoubleLinkedList&);
	friend bool operator==(const DoubleLinkedList&, const DoubleLinkedList&);
	friend DoubleLinkedList operator& (const DoubleLinkedList&, const DoubleLinkedList&);
	friend DoubleLinkedList operator| (const DoubleLinkedList&, const DoubleLinkedList&);
	DoubleLinkedList& merge(DoubleLinkedList&);
};

Node* DoubleLinkedList::getHead() const
{
	return this->pHead_;
}
Node* DoubleLinkedList::getTail() const
{
	return this->pTail_;
}
DoubleLinkedList& DoubleLinkedList::insertHead(Node* node)
{
	if (pHead_ == nullptr)
	{
		pHead_ = pTail_ = node;
	}
	else
	{
		node->setNext(pHead_);
		pHead_->setPreious(node);
		pHead_ = node;
	}
	return *this;
}
DoubleLinkedList& DoubleLinkedList::insertTail(Node* node)
{
	if (pHead_ == nullptr)
	{
		pHead_ = pTail_ = node;
	}
	else
	{
		pTail_->setNext(node);
		node->setPreious(pTail_);
		pTail_ = node;
	}
	return *this;
}
DoubleLinkedList& DoubleLinkedList::insert_advance(Node* p, Node* node)
{
	if (p == this->pHead_)
	{
		this->insertHead(node);
	}
	else
	{
		node->setNext(p->getPrevious()->getNext());
		p->getPrevious()->setNext(node);
		node->setPreious(p->getPrevious());
		p->setPreious(node);
	}
	return *this;
}
DoubleLinkedList& DoubleLinkedList::insert_later(Node* p, Node* node)
{
	if (p == pTail_)
	{
		this->insertTail(node);
	}
	else
	{
		node->setNext(p->getNext());
		p->setNext(node);
		node->setPreious(node->getNext()->getPrevious());
		node->getNext()->setPreious(node);
	}
	return *this;
}

size_t DoubleLinkedList::lenght() const
{
	size_t count = 0;
	for (Node* i = this->getHead(); i != nullptr; i = i->getNext())
	{
		++count;
	}
	return count;
}
DoubleLinkedList& DoubleLinkedList::deleteElement(Node* node)
{
	if (this->lenght() > 1)
	{
		if (node == pHead_)
		{
			pHead_ = node->getNext();
			node->setNext(nullptr);
			pHead_->setPreious(nullptr);
		}
		else
		{
			if (node == pTail_)
			{
				pTail_->setPreious(nullptr);
				pTail_ = pTail_->getPrevious();
				pTail_->setNext(nullptr);
			}
			else
			{
				node->getNext()->setPreious(node->getPrevious());
				node->getPrevious()->setNext(node->getNext());
				node->setPreious(nullptr);
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
DoubleLinkedList& DoubleLinkedList::operator= (const DoubleLinkedList& doubleLinkedList)
{
	this->pHead_ = doubleLinkedList.pHead_;
	this->pTail_ = doubleLinkedList.pTail_;
	return *this;
}

DoubleLinkedList& DoubleLinkedList::operator= (DoubleLinkedList&& doubleLinkedList) noexcept
{
	this->pHead_ = doubleLinkedList.pHead_;
	this->pTail_ = doubleLinkedList.pTail_;
	doubleLinkedList.pHead_ = nullptr;
	doubleLinkedList.pTail_ = nullptr;
	return *this;
}

DoubleLinkedList& DoubleLinkedList::operator+= (Node* node)
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
void operator<< (ostream& out, const DoubleLinkedList& list)
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

bool operator==(const DoubleLinkedList& doubleLinkedList1, const DoubleLinkedList& doubleLinkedList2)
{
	size_t count1 = doubleLinkedList1.lenght();
	size_t count2 = doubleLinkedList2.lenght();
	if (count1 == count2)
	{
		Node* tempList1 = doubleLinkedList1.pHead_;
		Node* tempList2 = doubleLinkedList2.pHead_;
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

DoubleLinkedList operator& (const DoubleLinkedList& list1, const DoubleLinkedList& list2)
{
	DoubleLinkedList list3;
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

DoubleLinkedList operator| (const DoubleLinkedList& list1, const DoubleLinkedList& list2)
{
	DoubleLinkedList list3;
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

DoubleLinkedList& DoubleLinkedList::merge(DoubleLinkedList& list)
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
	DoubleLinkedList list1;
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



	DoubleLinkedList list2;
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