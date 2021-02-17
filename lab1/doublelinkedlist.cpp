#include "doublelinkedlist.h"

DoubleList::DoubleList() {
    head_ = nullptr;
    tail_ = nullptr;
    counter_ = 0;
}

DoubleList::DoubleList(DoubleList&& copy) noexcept {
    this->head_ = copy.head_;
    this->tail_ = copy.tail_;
    copy.head_ = nullptr;
    copy.tail_ = nullptr;
}

DoubleList::~DoubleList() {
    Node* current = nullptr;
    Node* next = head_;
    while (next != nullptr)
    {
        current = next;
        if(current->data_ < 0)
        {
            break;
        }
        next = next->next_;
        if(current->data_ >= 0)
            delete current;
    }
}

void DoubleList::operator+=(int data) {
    Node* temp = new Node(data);
    this->insert(temp);
    counter_ += 1;
}

std::ostream &operator<<(std::ostream &trans, const DoubleList& list) {
    DoubleList::Node* value = list.head_;

    while(value != nullptr){
        trans << value->data_ << " ";
        value = value->next_;
    }
    return trans;
}

bool DoubleList::operator==(const DoubleList &list  ) {
    Node* temp_one = head_;
    Node* temp_two = list.head_;

    if(counter_ != list.counter_){
        return false;
    }

    for (int i = 0; i < counter_; ++i) {
        if(temp_one->data_ != temp_two->data_)
        {
            return false;
        }
        return true;
    }


    return true;
}

DoubleList operator&(const DoubleList &firstlist, const DoubleList& secondlist)
{
    DoubleList thirdlist;
    DoubleList::Node* value = firstlist.head_;
    while(value != nullptr)
    {
        DoubleList::Node* second_value = secondlist.head_;
        while(second_value != nullptr)
        {
            if (value->data_ == second_value->data_)
            {
                thirdlist.insert(new DoubleList::Node(value->data_));
                break;
            }
            second_value = second_value->next_;
        }
        value = value->next_;
    }
    return thirdlist;
}

DoubleList operator|(const DoubleList &firstlist, const DoubleList &secondlist) {
    DoubleList thirdlist;
    DoubleList::Node* value = firstlist.head_;
    while(value != nullptr){
        thirdlist.insert(new DoubleList::Node(value -> data_));
        value = value ->next_;
    }

    value = secondlist.head_;

    while (value != nullptr){
        thirdlist.insert(new DoubleList::Node(value->data_));
        value = value->next_;
    }

    return thirdlist;
}

void DoubleList::merge(DoubleList& List) {
    Node* value = List.head_;
    while(value != nullptr){
        this -> insert(new DoubleList::Node(value -> data_));
        value = List.head_ -> next_;
        delete List.head_;
        List.head_ = value;
    }
}

void DoubleList::insert(DoubleList::Node *dlist) {

        if (!RepeatedElements(dlist))
        {
            dlist->next_ = nullptr;
            if (this->head_ == nullptr)
            {
                dlist->prev_ = nullptr;
                head_ = dlist;
                tail_ = head_;
            }
            else if (head_->next_ == nullptr)
            {
                dlist->prev_ = head_;
                head_->next_ = dlist;
                tail_ = head_->next_;
            }
            else
            {
                Node* temp = head_;
                while (temp->next_ != nullptr)
                {
                    temp = temp->next_;
                }
                dlist->prev_ = temp;
                temp->next_ = dlist;
                tail_ = temp->next_;
            }
            counter_++;
            sorting();
        }
}

bool DoubleList::RepeatedElements(Node* value)
{
    if (this->head_ == nullptr)
    {
        return false;
    }
    Node *current = head_;
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

void DoubleList::sorting()
{
    for (int i = 0; i < this->counter_; i++)
    {
        Node* temp = this->head_;
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



