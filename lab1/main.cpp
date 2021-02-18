
#include <iostream>
#include <fstream>

#include"list.h"
#include"doubleLinkedList.h"

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        List list1;
        list1 += 1;
        list1 += 4;
        list1 += 2;
        list1 += 33;
        list1 += 15;
        list1 += 5;
        list1 += 66;
        std::cout << "First list: " << list1 << std::endl;
        List list2;
        list2 += 5;
        list2 += 3;
        list2 += 4;
        list2 += 1;
        list2 += 2;
        list2 += 77;
        list2 += 66;
        list2 += 17;
        list2 += 15;
        list2 += 19;
        std::cout << "Second list: " << list2 << std::endl;
        list1 == list2;
        list1& list2;
        list1 | list2;
        List list3;
        list3 += 8;
        list3 += 26;
        list3 += 54;
        std::cout << "Third list: " << list3 << std::endl;
        list1.merge(list3);
        std::cout << "Changed first list: " << list1 << std::endl;

        DLList lst1;
        lst1 += 1;
        lst1 += 4;
        lst1 += 2;
        lst1 += 33;
        lst1 += 15;
        lst1 += 5;
        lst1 += 66;
        std::cout << "First double linked list: " << lst1 << std::endl;
        DLList lst2;
        lst2 += 5;
        lst2 += 3;
        lst2 += 4;
        lst2 += 1;
        lst2 += 2;
        lst2 += 77;
        lst2 += 66;
        lst2 += 17;
        lst2 += 15;
        lst2 += 19;
        std::cout << "second double linked list: " << lst2 << std::endl;
        lst1 == lst2;
        lst1& lst2;
        lst1 | lst2;
        lst1 || lst2;
        DLList lst3;
        lst3 += 8;
        lst3 += 26;
        lst3 += 54;
        std::cout << "Third double linked list: " << lst3 << std::endl;
        lst1.merge(lst3);
        std::cout << "Changed first double linked list: " << lst1 << std::endl;

    }
    catch (const char* errorString)
    {
        std::cerr << std::endl << errorString << std::endl;
        return -1;
    }
}



