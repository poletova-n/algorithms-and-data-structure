#include <iostream>
#include "list.h"

list::list()
{
    this->head_ = nullptr;

    this->count_ = nullptr;
}

list::list(list&& copy) noexcept
{
    this->head_ = copy.head_;

    this->count_ = copy.count_;

    copy.head_ = nullptr;

    copy.count_ = nullptr;
}

list::~list()
{
    Node* next = head_;
    while (next != nullptr) {
        next = head_->next_;
        delete head_;
        head_ = next;
    }
}

void list::operator += (int info)
{
    Node* temp = new Node(info);
    this->insert(temp);
}

std::ostream& operator << (std::ostream& stream, const list& list)
{
    list::Node* current = list.head_;

    while (current != nullptr) {
        stream << current->info_ << " ";
        current = current->next_;
    }
    return stream;
}

bool list::operator == (const list& copy)
{
    if (this->count_ != copy.count_) return false;

    Node* FirstTemp = this->head_;
    Node* SecondTemp = copy.head_;

    while (FirstTemp->next_ != nullptr && SecondTemp->next_ != nullptr)
    {
        if (FirstTemp->info_ != SecondTemp->info_) return false;

        FirstTemp = FirstTemp->next_;
        SecondTemp = SecondTemp->next_;
    }
    return true;
}

list operator & (const list& first, const list& second)
{
    list temp;
    list::Node* current = first.head_;
    while (current != nullptr)
    {
        list::Node* current2 = second.head_;

        while (current2 != nullptr)
        {
            if (current->info_ == current2->info_)
            {
                temp.insert(new list::Node(current->info_));
                break;
            }
            current2 = current2->next_;
        }
        current = current->next_;
    }
    return temp;
}

list operator | (const list& first, const list& second)
{
    list temp;
    list::Node* current = first.head_;
    while (current != nullptr) {
        temp.insert(new list::Node(current->info_));
        current = current->next_;
    }
    current = second.head_;
    while (current != nullptr) {
        temp.insert(new list::Node(current->info_));
        current = current->next_;
    }
    return temp;
}

void list::merge(list& parameter)
{
    Node* current = parameter.head_;
    while (current != nullptr) {
        this->insert(new list::Node(current->info_));
        current = parameter.head_->next_;
        delete parameter.head_;
        parameter.head_ = current;
    }
}

void list::insert(Node* node)
{
    if (head_ == nullptr)
    {
        head_ = node;
        count_++;
        return;
    }

    Node* current = head_;

    while (current->next_ != nullptr && current->next_->info_ <= node->info_)
    {
        current = current->next_;
    }

    if (current == head_)
    {
        if (current->info_ > node->info_) {
            node->next_ = head_;
            head_ = node;
            count_++;
        }

        else if (current->info_ < node->info_) {
            node->next_ = head_->next_;
            head_->next_ = node;
            count_++;
        }

        return;
    }

    if (current->next_ != nullptr)
    {

        if (current->next_->info_ != node->info_ && current->info_ != node->info_) {
            node->next_ = current->next_;
            current->next_ = node;
            count_++;
        }
        return;
    }

    else if (current->next_ == nullptr && current->info_ == node->info_)
    {
        return;
    }

    count_++;

    current->next_ = node;
}
