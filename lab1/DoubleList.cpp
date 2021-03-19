#include "DoubleList.h"

DoubleList::DoubleList()
{
    count_ = 0;
    root_ = nullptr;
    tail_ = nullptr;
}

DoubleList::DoubleList(DoubleList &&copyVal) noexcept
{
    root_ = copyVal.root_;
    tail_ = copyVal.tail_;
    count_ = copyVal.count_;
    copyVal.root_ = nullptr;
    copyVal.tail_ = nullptr;
    copyVal.count_ = 0;
}

DoubleList::~DoubleList()
{
    while(count_ > 0)
    {
        Node *temp = this->root_;
        root_ = root_->next_;
        delete temp;
        count_ -= 1;
    }
}

bool DoubleList::checkForRepeatedElements(Node* value)
{
    if (this->root_ == nullptr)
    {
        return false;
    }
    Node *current = root_;
    while (current != nullptr )
    {
        if (current->data_ == value->data_)
        {
            return true;
        }
        current = current->next_;
    }
    return false;
}


void DoubleList::sort()
{
    for (int i = 0; i < this->count_; i++)
    {
        Node* temp = this->root_;
        Node* next = temp->next_;
        while (next != nullptr)
        {
            if (temp->data_ > next->data_)
            {
                std::swap(temp->data_, next->data_);
            }
            temp = temp->next_;
            next = next->next_;
        }
    }
}

bool DoubleList::operator==(DoubleList &anotherList)
{
    Node *temp1 = root_;
    Node *temp2 = anotherList.root_;

    if(count_ != anotherList.count_)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < count_; i++)
        {
            if (temp1->data_ != temp2->data_)
            {
                return false;
            }
        }
        return true;
    }
}

DoubleList::DoubleList(const DoubleList &copyVal):
        count_(0), root_(nullptr), tail_(nullptr)
{
    Node* temp = copyVal.root_;
    while (temp != nullptr)
    {
        insert(new Node(temp->data_));
        temp = temp->next_;
    }
}

void DoubleList::operator+= (int x)
{
    Node* temp = new Node(x);
    this->insert(temp);
}

std::ostream &operator<< (std::ostream &output, const DoubleList &list)
{
    DoubleList::Node* current = list.root_;
    while( current != nullptr)
    {
        output << current->data_ << " ";
        current = current->next_;
    }
    output << "\n";
    return output;
}

DoubleList operator& (const DoubleList &list1, const DoubleList &list2)
{
    DoubleList list3;
    DoubleList::Node* firstVal = list1.root_;
    for (int i = 0; i < list1.getCount(); ++i)
    {
        DoubleList::Node* secondVal = list2.root_;
        for (int j = 0; j < list2.getCount(); ++j)
        {
            if (firstVal->data_ == secondVal->data_)
            {
                list3.insert(new DoubleList::Node(firstVal->data_));
                break;
            }
            secondVal = secondVal->next_;
        }
        firstVal = firstVal->next_;
    }
    return list3;
}

DoubleList operator| (const DoubleList &list1, const DoubleList &list2)
{
    DoubleList list3;
    DoubleList::Node* temp = list1.root_;
    for (int i = 0; i < list1.getCount(); ++i)
    {
        list3.insert(new DoubleList::Node(temp->data_));
        temp = temp->next_;
    }
    temp = list2.root_;
    for (int i = 0; i < list2.getCount(); ++i)
    {
        list3.insert(new DoubleList::Node(temp->data_));
        temp = temp->next_;
    }
    return list3;
}

void DoubleList::merge(DoubleList &newList)
{
    Node* temp = newList.root_;
    while (temp != nullptr)
    {
        insert(new Node(temp->data_));
        temp = newList.root_->next_;
        delete newList.root_;
        newList.count_--;
        newList.root_ = temp;
    }
}

int DoubleList::getCount() const
{
    return count_;
}

void DoubleList::insert(Node *value)
{
    if (!checkForRepeatedElements(value))
    {
        value->next_ = nullptr;
        if (this->root_ == nullptr)
        {
            value->prev_ = nullptr;
            root_ = value;
            tail_ = root_;
        }
        else if (root_->next_ == nullptr)
        {
            value->prev_ = root_;
            root_->next_ = value;
            tail_ = root_->next_;
        }
        else
        {
            Node* temp = root_;
            while (temp->next_ != nullptr)
            {
                temp = temp->next_;
            }
            value->prev_ = temp;
            temp->next_ = value;
            tail_ = temp->next_;
        }
        count_++;
        sort();
    }
}