#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
    this->head_ = nullptr;
    this->tail_ = nullptr;
    this->size = 0;
}

void DoubleLinkedList::insert(Node* x)
{
    if (this->size == 0)
    {
        this->head_ = x;
        this->tail_ = x;
        size ++;
        return;
    }
    Node* current = head_;
    while(current->next_ != nullptr && current->next_->item_ <= x->item_)
    {
        current = current->next_;
    }
    if (current == head_)
    {
        if (current->item_ > x->item_) {
            x->prev_ = tail_;
            x->next_ = head_;
            head_ = x;
            size++;
        }
        else if (current->item_ < x->item_) {
            x->next_ = head_->next_;
            head_->next_ = x;
            x->prev_ = head_->next_;
            size++;
        }
        return;
    }
    if (current->next_ != nullptr)
    {
        if (current->next_->item_ != x->item_ && current->item_ != x->item_) {
            x->next_ = current->next_;
            current->next_->prev_ = x;
            current->next_ = x;
            x->prev_ = current;
            size++;
        }
        return;
    }
    else if (current->next_ == nullptr && current->item_ == x->item_) {
        return;
    }
    current->next_ = x;
    x->prev_ = current;
    this->tail_ = x;
    size ++;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& copy) noexcept
{
    this->head_ = copy.head_;
    this->tail_ = copy.tail_;
    this->size = copy.size;
    copy.head_ = nullptr;
    copy.tail_ = nullptr;
    copy.size = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& copy) {
    Node* temp = copy.head_;
    while (temp != nullptr) {
        this->insert(new Node(temp->item_));
        temp = temp->next_;
    }
}

DoubleLinkedList::~DoubleLinkedList()
{
    Node* next = this->head_;
    while (next != nullptr) {
        next = head_->next_;
        delete head_;
        head_ = next;
    }
}

void DoubleLinkedList::operator+=(int item){
    this->insert(new Node(item));
}

std::ostream& operator<<(std::ostream& item, const DoubleLinkedList& list)
{
    DoubleLinkedList::Node* current = list.head_;
    while (current != nullptr) {
        item << current-> item_ << " ";
        current = current->next_;
    }
    return item;
}

bool DoubleLinkedList::operator==(const DoubleLinkedList& copy)
{
    Node *temp1 = this->head_;
    Node *temp2 = copy.head_;
    while (temp1->next_ != nullptr && temp2->next_ != nullptr) {
        if (temp1->item_ != temp2->item_)
            return false;
        temp1 = temp1->next_;
        temp2 = temp2->next_;
    }
    return true;
}

DoubleLinkedList operator&(const DoubleLinkedList& left, const DoubleLinkedList& right)
{
    DoubleLinkedList newList;
    DoubleLinkedList::Node* currentLeft = left.head_;
    while (currentLeft != nullptr) {
        DoubleLinkedList::Node* currentRight = right.head_;
        while (currentRight != nullptr) {
            if (currentLeft->item_ == currentRight->item_) {
                newList.insert(new DoubleLinkedList::Node(currentLeft->item_));
                break;
            }
            currentRight = currentRight->next_;
        }
        currentLeft = currentLeft->next_;
    }
    return newList;
}

DoubleLinkedList operator|(const DoubleLinkedList& left, const DoubleLinkedList& right)
{
    DoubleLinkedList newList;
    DoubleLinkedList::Node* currentLeft = left.head_;
    DoubleLinkedList::Node* currentRight = right.head_;
    while (currentLeft != nullptr) {
        newList.insert(new DoubleLinkedList::Node(currentLeft->item_));
        currentLeft = currentLeft->next_;
    }
    DoubleLinkedList::Node* currentNew = newList.head_;
    while (currentNew != nullptr) {
        while (currentRight != nullptr){
            if (currentRight->item_ != currentNew->item_) {
                newList.insert(new DoubleLinkedList::Node(currentRight->item_));
            }
            currentRight = currentRight->next_;
        }
        currentNew = currentNew->next_;
    }
    return newList;
}

void DoubleLinkedList::merge(DoubleLinkedList& list)
{
    Node* current = list.head_;
    while (current != nullptr) {
        this->insert(new DoubleLinkedList::Node(current->item_));
        current = list.head_->next_;
        list.head_ = nullptr;
        list.head_ = current;
    }
}