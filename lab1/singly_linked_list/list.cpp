#include <iostream>
#include "list.h"
    
    List::List() {
    value_ = NULL;
    next_ = nullptr;
    head_ = this;
    }

    List::List(int value) {
    next_ = nullptr;
    head_ = this;
    value_ = value;        
    }

    void List::insert(int value)
    {
        List* current;

        if (next_ == nullptr)
        {
            List temp = List(value);
            next_ = &temp;
        }
        else
        {
            current = next_;
            while (current->next_ != nullptr)
            {
                current = current->next_;
            }
            List p = List(value);
            current->next_ = &p;
        }
    }

    List::List(List* src) {
        bool last = false;
        List lst(src->value_);
        List* next = src->next_;
        while (!last) {
            if (next->next_ == nullptr) {
                last = true;
                lst.insert(next->value_);
            }
            else {
                lst.insert(next->value_);
                next = next->next_;
            }
        }
    }

    List::List(List&& src) {
    }