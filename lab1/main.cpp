#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main()
{
  int choose = 0;
  std::cout << "if you want to check Single Linked List input 1.\n"
            << "if you want to check Double Linked List input 2 :\n";
  std::cin >> choose;
  if (choose == 1) {
    SingleLinkedList a;
    SingleLinkedList b;
    std::cout << "now we'll check operator += (value 5).\n";
    system("PAUSE");
    b += 5;
    std::cout << "operator += is checked. b += 5. list b is " << b << '\n';
    a = b;
    system("PAUSE");
    b += 15;
    std::cout << "operator += is checked. b += 15. list b is " << b << '\n';
    a += 10;
    a += 10;
    SingleLinkedList c(a);
    c += 7;
    std::cout << "checking list c is " << c << '\n';
    std::cout << "check move constructor (c into d)\n";
    system("PAUSE");
    SingleLinkedList d = std::move(c);
    std::cout << "a move constructor is checked. list d is " << d
              << "list c can't be outputed. c is empty.\n";
    a += 15;
    c += 11;
    c += 10;
    c += -3;
    c += 7;
    system("PAUSE");
    std::cout << "list c is " << c << '\n'
              << "list a is " << a << '\n';
    SingleLinkedList f = c & a;
    std::cout << "operator & is checked. result list is " << f << '\n';
    system("PAUSE");
    SingleLinkedList e = c | a;
    std::cout << "operator | is checked. result list is " << e << '\n';
    system("PAUSE");
    SingleLinkedList first;
    first += 10;
    first += 20;
    SingleLinkedList second;
    second += 1;
    second += 2;
    std::cout << "list first is " << first << '\n'
              << "list second is " << second << '\n';
    system("PAUSE");
    first.merge(second);
    std::cout << "method merge is checked. list first now is " << first
              << "list second is empty, can't output.\n";
    {
      SingleLinkedList listOne;
      listOne += 10;
      listOne += 20;
      SingleLinkedList listTwo;
      listTwo += 1;
      listTwo += 2;
      std::cout << "list listOne is " << listOne << " list listTwo is " << listTwo << '\n';
      system("PAUSE");
      if (listOne == listTwo)
      {
        std::cout << "listOne equal listTwo. equality operator is checked.\n";
      }
      else
      {
        std::cout << "listOne doesn't equal listTwo. let's check equality operator again.\n";
      }
      system("PAUSE");
      listOne = listTwo;
      std::cout << "listOne = listTwo.\n";
      system("PAUSE");
      if (listOne == listTwo)
      {
        std::cout << "listOne equal listTwo. equality operator is checked.\n";
      }
      else
      {
        std::cout << "listOne doesn't equal listTwo. let's check equality operator again.\n";
      }
    }
  }
  else if (choose == 2)
  {
    DoubleLinkedList first;
    std::cout << "now we'll check operator += (value: 2).\n";
    system("PAUSE");
    first += 2;
    std::cout << "operator += is checked. list first now is " << first << '\n';
    system("PAUSE");
    DoubleLinkedList second(first);
    std::cout << "list second is equal first: " << second << '\n';
    std::cout << "let's check it by equal operator ==: \n";
    std::cout << ((first == second) ? "it's true\n" : "it's false\n");
    system("PAUSE");
    std::cout << "second += 5:\n";
    second += 5;
    std::cout << "is first equal second?\n";
    std::cout << ((first == second) ? "it's true\n" : "it's false\n");
    system("PAUSE");
    std::cout << "let's check move constructor. creating list third and move list second to it.\n"
              << "list second is " << second << '\n';
    system("PAUSE");
    DoubleLinkedList third = std::move(second);
    std::cout << "list third is " << third << "\nlist second is empty" << '\n';
    system("PAUSE");
    DoubleLinkedList firstList;
    firstList += 1;
    firstList += 5;
    firstList += 10;
    DoubleLinkedList secondList;
    secondList += 5;
    secondList += 7;
    secondList += 15;
    std::cout << "check operator & \n";
    system("PAUSE");
    DoubleLinkedList commonList = std::move(firstList & secondList);
    std::cout << "common list is " << commonList << '\n';
    std::cout << "check operator | \n";
    system("PAUSE");
    DoubleLinkedList summaryList = std::move(firstList | secondList);
    std::cout << "summary list is " << summaryList << '\n';
    system("PAUSE");
    DoubleLinkedList mergedList;
    DoubleLinkedList mergingList;
    std::cout << "check class function 'merge':\n";
    mergedList += 1;
    mergedList += 2;
    mergedList += 3;
    mergedList += 4;
    mergingList += 4;
    mergingList += 5;
    mergingList += 6;
    std::cout << "merged list is " << mergedList << '\n'
              << "merging list is " << mergingList << '\n';
    system("PAUSE");
    mergingList.merge(mergedList);
    std::cout << "after merge merging list is " << mergingList
              << "merged list is empty";
  }
  return 0;
}