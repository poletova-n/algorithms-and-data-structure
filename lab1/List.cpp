#include "List.h"
#include <ostream>

List::List()
{
    this->head_ = nullptr;
    this->size = 0;
}

void List::insert(Node* x)
{
    if (this->size == 0)
    {
        this->head_ = x;
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
            x->next_ = head_;
            head_ = x;
            size++;
        }
        else if (current->item_ < x->item_) {
            x->next_ = head_->next_;
            head_->next_ = x;
            size++;
        }
        return;
    }
    if (current->next_ != nullptr)
    {
        if (current->next_->item_ != x->item_ && current->item_ != x->item_) {
            x->next_ = current->next_;
            current->next_ = x;
            size++;
        }
        return;
    }
    else if (current->next_ == nullptr && current->item_ == x->item_) {
        return;
    }
    current->next_ = x;
    size ++;
}

List::List(List&& copy) noexcept
{
    this->head_ = copy.head_;
    this->size = copy.size;
    copy.head_ = nullptr;
    copy.size = 0;
}

List::List(const List& copy) {
    Node* temp = copy.head_;
    while (temp != nullptr) {
        this->insert(new Node(temp->item_));
        temp = temp->next_;
    }
}

List::~List()
{
    Node* next = this->head_;
    while (next != nullptr) {
        next = head_->next_;
        delete head_;
        head_ = next;
    }
}

void List::operator+=(int item){
    this->insert(new Node(item));
}

std::ostream& operator<<(std::ostream& item, const List& list)
{
    List::Node* current = list.head_;
    while (current != nullptr) {
        item << current-> item_ << " ";
        current = current->next_;
    }
    return item;
}

bool List::operator==(const List& copy)
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

List operator&(const List& left, const List& right)
{
    List newList;
    List::Node* currentLeft = left.head_;
    while (currentLeft != nullptr) {
        List::Node* currentRight = right.head_;
        while (currentRight != nullptr) {
            if (currentLeft->item_ == currentRight->item_) {
                newList.insert(new List::Node(currentLeft->item_));
                break;
            }
            currentRight = currentRight->next_;
        }
        currentLeft = currentLeft->next_;
    }
    return newList;
}

List operator|(const List& left, const List& right)
{
    List newList;
    List::Node* currentLeft = left.head_;
    List::Node* currentRight = right.head_;
    while (currentLeft != nullptr) {
        newList.insert(new List::Node(currentLeft->item_));
        currentLeft = currentLeft->next_;
    }
    List::Node* currentNew = newList.head_;
    while (currentNew != nullptr) {
        while (currentRight != nullptr){
            if (currentRight->item_ != currentNew->item_) {
                newList.insert(new List::Node(currentRight->item_));
            }
            currentRight = currentRight->next_;
        }
            currentNew = currentNew->next_;
    }
    return newList;
}

void List::merge(List& list)
{
    Node* current = list.head_;
    while (current != nullptr) {
        this->insert(new List::Node(current->item_));
        current = list.head_->next_;
        list.head_ = nullptr;
        list.head_ = current;
    }
}


