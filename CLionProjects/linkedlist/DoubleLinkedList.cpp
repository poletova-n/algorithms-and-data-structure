#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - Дважды связный список целых чисел - реализация методов класса  
//
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// Конструктор "копирования" – создание копии имеющегося списка
DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList & src)
{
    head_ = nullptr;
    tail_ = nullptr;
    count_ = 0;
    Node* temp = src.head_;
    while(temp != nullptr)
    {
        insertTail(temp->item_);
        temp = temp->next_;
    }
}

// Вставить сформированный узел в хвост списка
void DoubleLinkedList::insertTail(Node* x)
{
    x->prev_ = tail_;
    if(head_ == nullptr)
    {
        insertHead(x);
        count_ = count_-1;
    }
    tail_->next_ = x;
    x->next_ = nullptr;
    tail_ = x;
    count_++;
}

// Вставить сформированный узел в начало списка
void DoubleLinkedList::insertHead(Node* x)
{   // x->prev_ == nullptr,  x->next_ == nullptr  
    x->next_ = head_;
    if (head_ != nullptr) {
        // список был НЕ пуст – новый элемент будет и первым, и последним
        head_->prev_ = x;
    }
    else {
        // список был пуст – новый элемент будет и первым, и последним
        tail_ = x;
    }
    head_ = x;
    count_++;  // число элементов списка увеличилось
}

// Удаление заданного узла 
void DoubleLinkedList::deleteNode(Node* x)
{
    if (x == nullptr) {
        throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
    }
    if (x->prev_ != nullptr) {
        // удаляется НЕ голова списка
        (x->prev_)->next_ = x->next_;
    }
    else {
        // удаляется голова списка,  второй элемент становится первым
        head_ = x->next_;
    }
    if (x->next_ != nullptr) {
        // удаляется НЕ хвост
        (x->next_)->prev_ = x->prev_    ;
    }
    else {
        // удаляется хвост
        tail_ = x->prev_;
    }
    delete x;      //
    count_--;     // число элементов списка уменьшилось
}

// Поиск узла (адрес) с заданным значением  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
    Node* x = head_;
    while (x != nullptr && x->item_ != item) {
        x = x->next_;
    }
    return x;
}

// Замена информации узла на новое 
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
    x->item_ = item;
    return x;
}

// количество элементов списка
int DoubleLinkedList::count()const{ return count_; }

// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const
{
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

int& DoubleLinkedList::headItem()
{
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const
{
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
}
int& DoubleLinkedList::tailItem()
{
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
}

// Вставить элемент в голову списка
void DoubleLinkedList::insertHead(int item)
{   // создаем новый элемент списка и добавляем в голову 
    insertHead(new Node(item));
}


// Вставить элемент в хвост списка
void DoubleLinkedList::insertTail(int item)
{   // создаем новый элемент списка и добавляем в хвост 
    insertTail(new Node(item));
}

// Удалить элемент с головы списка
bool DoubleLinkedList::deleteHead()
{
    if (head_ == nullptr) {
        return 0;  // список пуст, удалений нет
    }
    deleteNode(head_);
    return 1;      // список был НЕ пуст, удаление головы
}

// Удалить элемент из хвоста списка
bool DoubleLinkedList::deleteTail()
{
    deleteNode(tail_);
    return 1;
}

// Удаление узла с заданным значением  
bool DoubleLinkedList::deleteItem(const int item)
{
    Node* x = head_;
    while (x != nullptr && x->item_ != item) {
        x = x->next_;
    }
    if(x->item_ == item)
    {
        deleteNode(x);
    }
    return 1;
}

// Поиск записи с заданным значением  
bool DoubleLinkedList::searchItem(int item)
{   // возвращаем TRUE, если узел найден 
    return (searchNode(item) != nullptr);
}


// Замена информации узла на новое 
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew)
{
    Node* x = head_;
    while (x != nullptr && x->item_ != itemOld) {
        x = x->next_;
    }
    if(x->item_ != itemOld)
    {
        return 0;
    }
    if(x->item_ == itemOld)
    {
        replaceNode(x,itemNew);
    }
    return 1;
}

// Вывод элементов списка в текстовом виде в стандартный выходной поток 
void DoubleLinkedList::outAll()
{
    Node* current = head_;       // Указатель на элемент
    while (current != nullptr)
    {
        std::cout << current->item_ << ' ';
        current = current->next_;  // Переход к следующему элементу
    }
    std::cout << std::endl;
}

// Деструктор списка	
DoubleLinkedList::~DoubleLinkedList()
{
    Node* current = nullptr;   // указатель на элемент, подлежащий удалению
    Node* next = head_;        // указатель на следующий элемент
    while (next != nullptr)
    {  // пока есть еще элементы в списке
        current = next;
        if(current->item_ < 0)
        {
            break;
        }
        next = next->next_; // переход к следующему элементу
        if(current->item_ >= 0)
        delete current;
    }
}

bool DoubleLinkedList::operator==(DoubleLinkedList &src)
{
    if(count_ != src.count_)
    {
        return 0;
    }
    else
    {
        Node* rightSideNode = src.head_;
        Node* leftSideNode = head_;
        for(int i = 0;i<count_;i++)
        {
            if(leftSideNode->item_ != rightSideNode->item_)
            {
                return 0;
            }
        }
        return 1;
    }

}

void DoubleLinkedList::appendInTheEnd(DoubleLinkedList &src)
{
    Node* h = src.head_;
    while(h != nullptr)
    {
        insertTail(h->item_);
        h = h->next_;
    }
    return;
}




DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &src)
{
    DoubleLinkedList temp(src);
    this->swap(temp);
    return *this;
}


void DoubleLinkedList::swap(DoubleLinkedList &src)
{
    DoubleLinkedList temp(src);
    src.head_ = this->head_;
    src.tail_ = this->tail_;
    src.count_ = this->count_;
    this->head_ = temp.head_;
    this->tail_ = temp.tail_;
    this->count_ = temp.count_;
    temp.head_ = nullptr;
    temp.tail_ = nullptr;
    temp.count_ = NULL;
    return;
}

DoubleLinkedList &DoubleLinkedList::operator=(DoubleLinkedList &&src) noexcept
{
    if (this != &src)
    {
        delete[] head_;
        delete[] tail_;
        count_ = -1;
        DoubleLinkedList temp(src);
        head_ = temp.head_;
        tail_ = temp.tail_;
        count_ = temp.count_;
        src.~DoubleLinkedList();
        temp.head_ = nullptr;
        temp.tail_ = nullptr;
        temp.count_ = NULL;

    }
    return *this;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &&src) noexcept
{
    if (this != &src)
    {
        delete[] head_;
        delete[] tail_;
        count_ = -1;
        DoubleLinkedList temp(src);
        head_ = temp.head_;
        tail_ = temp.tail_;
        count_ = temp.count_;
        src.~DoubleLinkedList();
        temp.head_ = nullptr;
        temp.tail_ = nullptr;
        temp.count_ = NULL;

    }
}
