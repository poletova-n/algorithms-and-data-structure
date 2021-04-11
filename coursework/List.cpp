#include "List.hpp"
#include "Exceptions.hpp"
#include <stdexcept>

 List::~List()
{
    Node * temp = nullptr;
    while (head_ != nullptr)
    {
        temp = head_->next_;
        head_ = temp;
    }
}

std::string List::print() const
{
    Node *temp = head_;
    std::string out;
    while (temp)
    {
        out+= temp->item_;
        if (temp == tail_)
        {
            out += "\n";
        }
        else{
            out += ", ";
        }
        temp = temp->next_;
    }
    return out;
}

size_t List::getSize()
{
    size_t size = 0;
    Node* temp = head_;
    while (temp)
    {
        temp = temp->next_;
        size++;
    }
    return size;
}

void List::insert (std::string word)
{
    while (word.find(',') != -1)
    {
        char pos = word.find(',');
        if (pos == word.length() - 1)
        {
            word.erase(pos - 1, pos);
            break;
        }
        std::string temp = word.substr(0,pos);
        insert(temp);
        word.erase(0,pos+2);
    }
    if (head_ == nullptr)
    {
        insertHead(word);
    }
    else
    {
        size_t size = this->getSize();
        if (size == 1)
        {
            if (word < head_->item_)
            {
                insertHead(word);
            }
            else
            {
                insertTail(word);
            }
        }
        else
        {
            if (head_->item_ > word)
            {
                insertHead(word);
                return;
            }
            if (tail_->item_ < word)
            {
                insertTail(word);
                return;
            }
        }
    }
}

void List::insertHead(std::string word)
{
    Node* temp = new Node(std::move(word),head_);
    insertHead(temp);
}

void List::insertHead(Node* elem)
{
    if (!head_)
    {
        head_ = tail_ = elem;
    }
    else
    {
        head_ = elem;
    }
}

void List::insertTail(std::string word)
{
    Node* temp = new Node(std::move(word),nullptr);
    insertTail(temp);
}

void List::insertTail(Node* elem)
{
    if (tail_)
    {
        tail_->next_ = elem;
    }
    else
    {
        head_ = elem;
    }
    tail_ = elem;
}


