#include "DoubleLinkedList.h"
#include <iostream>


std::ostream& operator<< (std::ostream &out, DoubleLinkedList &src)
{
    src.outAll();
    return out;
}

int main() {
    DoubleLinkedList list;   // Создание пустого списка
    list.insertHead(1);      // Добавление элементов
    list.insertHead(2);
    list.insertHead(3);
    std::cout << "First list:" << std::endl;
    list.outAll();           // Печать элементов

    std::cout << ((list.searchItem(1))?  "1 find" : "1 not find") << std::endl;
    std::cout << ((list.searchItem(8)) ? "8 find" : "8 not find") << std::endl;

    DoubleLinkedList  list1(list); // (list);  // Копирование списка
    list1.insertHead(4);         // Добавление элемента
    list1.insertHead(5);         // Добавление элемента
    list1.deleteHead();          // Удаление головного
    std::cout << "Second list, copied from first:" << std::endl;
    list1.outAll();
    list1.insertTail(6);
    list1.deleteTail(); // удаление хвостового элемента 
    list1.deleteItem(3);
    std::cout << "Second list, after deleting:" << std::endl;
    list1.outAll();  // Печать результата
    std::cout << "Checking overloaded operator <<:" << std::endl;
    std::cout << list; // проверка перегруженного оператора вывода
    std::cout << "Checking list comparing:" << std::endl;
    bool temp = list == list1; // проверка перегруженного оператора сравнения
    std::cout << temp << std::endl;
    list1.insertHead(5);
    list = list1; // оператор присвоения-копирования через copy-and-swap идиому
    std::cout << "Checking copy-and-swap idiom:" << std::endl;
    list.outAll();
    list1.outAll();
    list.appendInTheEnd(list1); // добавление одного списка в конец другому
    std::cout << "Merged lists:" << std::endl;
    list.outAll();

    return 0;
}

