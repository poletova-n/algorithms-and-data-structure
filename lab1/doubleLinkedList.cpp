
#include <iostream>
#include"doubleLinkedList.h"

DLList::DLList()
{
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

DLList::~DLList()
{
    Node* temp = head_;
    while (temp->pNext_ != nullptr)
    {
        temp = temp->pNext_;
        delete head_;
        head_ = temp;
    }
}

DLList::DLList(const DLList& other)
{
    if (other.head_ == nullptr)
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
    else
    {
        this->size_ = other.size_;
        Node* current = other.head_;
        this->head_ = new Node(current->data_);
        Node* temp = this->head_;
        while (current->pNext_ != nullptr)
        {
            current = current->pNext_;
            temp->pNext_ = new Node(current->data_);
            temp = temp->pNext_;
        }
    }
}

void DLList::operator +=(int data)
{
    if (head_ == nullptr)
    {
        head_ = new Node(data);
        size_++;
    }
    else
    {
        Node* temp = this->head_;
        while (temp->pNext_ != nullptr)
        {
            if (temp->data_ == data)
            {
                throw "Element with this value is already here";
            }
            temp = temp->pNext_;
        }
        Node* current = head_;
        Node* prev = nullptr;
        while ((current->data_ < data) && (current->pNext_ != nullptr))
        {
            prev = current;
            current = current->pNext_;
        }
        if (data < current->data_)
        {
            if (prev == nullptr)
            {
                prev = head_;
                prev = new Node(data, current);
                head_ = prev;
                current->pPrev_ = head_;
            }
            else if (prev != nullptr)
            {
                prev->pNext_ = new Node(data, current, prev);
                current->pPrev_ = prev->pNext_;
            }
        }
        else
        {
            current->pNext_ = new Node(data);
        }
        size_++;
    }
}

int DLList::operator[](int index)
{
    int counter = 0;
    Node* current = this->head_;
    while (current != nullptr)
    {
        if (counter == index)
            return current->data_;
        else
        {
            current = current->pNext_;
            counter++;
        }
    }
}

bool DLList::operator==(DLList& list)
{
    Node* current = this->head_;
    for (int i = 0; i <= list.size_; i++)
    {
        if (current->data_ != list[i])
        {
            std::cout << "These lists are not the equal" << std::endl;
            return false;
        }
        current = current->pNext_;
    }
    std::cout << "These lists are equal" << std::endl;
    return true;
}

void DLList::operator=(DLList& other)
{
    if (other.head_ == nullptr)
    {
        head_ = nullptr;
        size_ = 0;
    }
    else
    {
        this->size_ = other.size_;
        Node* temp = other.head_;
        this->head_ = new Node(temp->data_);
        Node* temp1 = this->head_;
        while (temp->pNext_ != nullptr)
        {
            temp = temp->pNext_;
            temp1->pNext_ = new Node(temp->data_);
            temp1 = temp1->pNext_;
        }
    }
}

DLList operator&(DLList& list, DLList& list1)
{
    DLList newlist;
    for (int i = 0; i < list.size_; i++)
    {
        for (int j = 0; j < list1.size_; j++)
        {
            if (list[i] == list1[j])
            {
                newlist += list[i];
            }
        }
    }
    std::cout << "List formed from elements of both current lists: " << newlist << std::endl;
    return newlist;
}

DLList operator|(DLList& list, DLList& list1)
{
    DLList newlist;
    newlist = list;
    for (int i = 0; i < list1.size_; i++)
    {
        int counter = 0;
        for (int j = 0; j < newlist.size_; j++)
        {
            if (list1[i] == newlist[j])
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            newlist += list1[i];
        }
    }
    std::cout << "List formed from both current lists: " << newlist << std::endl;
    return newlist;
}

std::ostream& operator<<(std::ostream& stream, DLList& list)
{
    for (int i = 0; i < list.size_; i++)
    {
        stream << list[i] << " ";
    }
    return stream;
}

DLList operator||(DLList& list, DLList& list1)
{
    DLList newlist;
    for (int i = 0; i < list1.size_; i++)
    {
        int counter = 0;
        for (int j = 0; j < list.size_; j++)
        {
            if (list1[i] == list[j])
            {
                counter++;
            }
            
        }
        if (counter == 0)
        {
            newlist += list1[i];
        }
    }
    for (int i = 0; i < list.size_; i++)
    {
        int counter = 0;
        for (int j = 0; j < list1.size_; j++)
        {
            if (list[i] == list1[j])
            {
                counter++;
            }

        }
        if (counter == 0)
        {
            newlist += list[i];
        }
    }
    std::cout << "List formed from both current lists: " << newlist << std::endl;
    return newlist;
}

DLList DLList::merge(DLList& list)
{

    if (list.head_ == nullptr)
    {
        throw "Adding an empty list is impossible";
        return *this;
    }
    for (int i = 0; i < list.size_; i++)
    {
        int counter = 0;
        for (int j = 0; j < this->size_; j++)
        {
            if ((*this)[j] == list[i])
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            *this += list[i];
        }
    }
    return *this;
    Node* temp = head_;
    while (temp->pNext_ != nullptr)
    {
        temp = temp->pNext_;
        delete head_;
        head_ = temp;
    }
}