#include <iostream>
#include "list.h"
int main()
{
    List firstList(5);
    firstList.insert(10);  
    while (&firstList != nullptr)
    {
        std::cout << firstList.value_ << ' ';
        firstList = firstList.next_;
    }
    return 0;
}

