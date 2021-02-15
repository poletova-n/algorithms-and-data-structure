
#include <iostream>
#include "list.h"

List::List()
{
    head_ = nullptr;
    size_ = 0;
}

List::~List()
{
    Node* temp = head_;
    while (temp->pNext_ != nullptr)
    {
        temp = temp->pNext_;
        delete head_;
        head_ = temp;
    }
}

List::List(const List& other)
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

void List::operator +=(int data)
{
    if (head_ == nullptr)
    {
        head_ = new Node(data);
    }
    else
    {
        Node* temp = this->head_;
        while (temp->pNext_ != nullptr)
        {
            if (temp->data_ == data)
            {
                throw "Элемент с таким значением уже сть в списке";
            }
            temp = temp->pNext_;
        }
        Node* current = this->head_;
        Node* prev = nullptr;
        while ((current->data_ < data)&&(current->pNext_ != nullptr))
        {
            prev = current;
            current = current->pNext_;
        }
        if (data < current->data_)
        {
            if (prev == nullptr)
            {
                prev = head_;
                head_ = new Node(data, current);
            }
            else if (prev != nullptr)
            {
                prev->pNext_ = new Node(data, current);
            }
        }
        else
        {
            current->pNext_ = new Node(data);
        }
        size_++;
    }
}

int List::operator[](int index)
{
    int cntr = 0;
    Node* temp = this->head_;
    while (temp->pNext_ != nullptr)
    {
        temp = temp->pNext_;
        cntr++;
    }
    if (index > cntr)
    {
        throw "Неверно задан индекс элемента списка";
    }
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

bool List::operator==(List& list)
{
    Node* current = this->head_;
    for (int i = 0; i <= list.size_; i++)
    {
        if (current->data_ != list[i])
        {
            std::cout << "Списки не являются идентичными" << std::endl;
            return false;
        }
        current = current->pNext_;
    }
    std::cout << "Списки являются идентичными" << std::endl;
    return true;
}

void List::operator=(List& other)
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

List List::merge(List& list)
{
    if (list.head_ == nullptr)
    {
        throw "Невозможно добавить к исходному списку пустой список";
        return *this;
    }
    for (int i = 0; i <= list.size_; i++)
    {
        int counter = 0;
        for (int j = 0; j <= this->size_; j++)
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

std::ostream& operator<<(std::ostream& stream, List& list)
{
    for (int i = 0; i <= list.size_; i++)
    {
        stream << list[i] << " ";
    }
    return stream;
}

List operator&(List& list, List& list1)
{
    List newlist;
    for (int i = 0; i <= list.size_; i++)
    {
        for (int j = 0; j <= list1.size_; j++)
        {
            if (list[i] == list1[j])
            {
                newlist += list[i];
            }
        }
    }
    std::cout << "Список, сформированный из элементов, имеющихся в обоих списках: " << newlist << std::endl;
    return newlist;
}

List operator|(List& list, List& list1)
{
    List newlist;
    newlist = list;
    for (int i = 0; i <= list1.size_; i++)
    {
        int counter = 0;
        for (int j = 0; j <= newlist.size_; j++)
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
    std::cout << "Список, сформированный из элементов двух списков: " << newlist << std::endl;
    return newlist;
}

