#include "List.h"

List::List()
{
    this->head_ = nullptr;

    this->count_ = 0;
}

List::List(List&& copy) noexcept
{
    this->head_ = copy.head_;

    this->count_ = copy.count_;

    copy.head_ = nullptr;

    copy.count_ = 0;
}

List::~List()
{
    Node* next = head_;
    while (next != nullptr) {
        next = head_->next_;
        delete head_;
        head_ = next;
    }
}

void List::operator += (int data)
{
    Node* temp = new Node(data);
    this->insert(temp);
}

std::ostream& operator << (std::ostream& pst, const List& list)
{
    List::Node* current = list.head_;

    while (current != nullptr) {
        pst << current->data_ << " ";
        current = current->next_;
    }

    return pst;
}

bool List::operator == (const List& copy)
{
    if (this->count_ != copy.count_) return false;

        Node* FirstTemp = this->head_;
        Node* SecondTemp = copy.head_;

    while (FirstTemp->next_ != nullptr && SecondTemp->next_ != nullptr)
    {
        if (FirstTemp->data_ != SecondTemp->data_) return false;

            FirstTemp = FirstTemp->next_;
            SecondTemp = SecondTemp->next_;
    }
    return true;
}

List operator & (const List& first, const List& second)
{
    List temp;
    List::Node* current = first.head_;
    while (current != nullptr)
    {
        List::Node* current2 = second.head_;

        while (current2 != nullptr)
        {
            if (current->data_ == current2->data_)
            {
                temp.insert(new List::Node(current->data_));
                break;
            }
            current2 = current2->next_;
        }
        current = current->next_;
    }
    return temp;
}

List operator | (const List& first, const List& second)
{
    List temp;
    List::Node* current = first.head_;
    while (current != nullptr) {
        temp.insert(new List::Node(current->data_));
        current = current->next_;
    }
    current = second.head_;
    while (current != nullptr) {
        temp.insert(new List::Node(current->data_));
        current = current->next_;
    }
    return temp;
}

void List::merge(List& parameter)
{
    Node* current = parameter.head_;
    while (current != nullptr) {
        this->insert(new List::Node(current->data_));

        current = parameter.head_->next_;

        delete parameter.head_;

        parameter.head_ = current;
    }
}

void List::insert(Node* node)
{
    if (head_ == nullptr)
    {
        head_ = node;
        count_++;
        return;
    }

    Node* current = head_;

    while (current->next_ != nullptr && current->next_->data_ <= node->data_)
    {
        current = current->next_;
    }

    if (current == head_)
    {
        if (current->data_ > node->data_) {
            node->next_ = head_;
            head_ = node;
            count_++;
        }

        else if (current->data_ < node->data_) {
            node->next_ = head_->next_;
            head_->next_ = node;
            count_++;
        }

        return;
    }

    if (current->next_ != nullptr)
    {

        if (current->next_->data_ != node->data_ && current->data_ != node->data_) {
            node->next_ = current->next_;
            current->next_ = node;
            count_++;
        }
        return;
    }

    else if (current->next_ == nullptr && current->data_ == node->data_)
    {
        return;
    }

    count_++;

    current->next_ = node;
}
