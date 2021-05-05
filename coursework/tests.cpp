#include "tests.hpp"
#include "SinglyLinkedOrderedList.h"
#include "RBTree.hpp"

void testRightWorkList()
{
  SinglyLinkedOrderedList list;
  std::string str = "Nastia";
  std::string str2 = "Sergey";
  std::string str3 = "Ann";
  std::cout << "Print empty list:" << list << std::endl;
  list.insert(str);
  list.insert(str2);
  list.insert(str3);
  std::cout << "Print list after inserting elements:" << list << '\n';
  list.deleteWord(str);
  std::cout << "Print list after removing word Nastia:" << list << '\n';
  if(list.search(str2))
  {
    std::cout << "List contains word Sergey";
  }
}

void testInsertRepeatingElementList()
{
  SinglyLinkedOrderedList list;
  std::string str = "beautiful";
  list.insert(str);
  list.insert(str);
}

void testRightWorkRBTree()
{
  std::cout << "Print empty RBTree:" << '\n';
  RBTree dir;
  dir.print(std::cout);
  SinglyLinkedOrderedList list;
  std::string str1 = "end";
  std::string str2 = "stop";
  std::string str3 = "finish";
  std::string str4 = "terminate";
  std::string str5 = "close";
  list.insert(str2);
  list.insert(str3);
  list.insert(str4);
  list.insert(str5);
  dir.insert(str1, list);
  std::string string1 = "fast";
  std::string string2 = "quick";
  std::string string3 = "speedy";
  std::string string4 = "rapid";
  SinglyLinkedOrderedList list1;
  list1.insert(string3);
  list1.insert(string2);
  list1.insert(string4);
  dir.insert(string1, list1);
  std::string s1 = "false";
  std::string s2 = "fake";
  SinglyLinkedOrderedList list2;
  list2.insert(s2);
  dir.insert(s1, list2);
  std::string tmp1 = "good";
  std::string tmp2 = "excellent";
  std::string tmp3 = "fine";
  std::string tmp4 = "wonderful";
  std::string tmp5 = "marvelous";
  SinglyLinkedOrderedList list3;
  list3.insert(tmp2);
  list3.insert(tmp3);
  list3.insert(tmp4);
  list3.insert(tmp5);
  dir.insert(tmp1, list3);
  std::string temp1 = "little";
  std::string temp2 = "small";
  SinglyLinkedOrderedList list4;
  list4.insert(temp2);
  dir.insert(temp1, list4);
  std::cout << "Print RBTree after inserting words";
  dir.print(std::cout);
  std::cout << "Print hierarchy RBTree:" << '\n';
  dir.printHierarchy(std::cout);
  std::cout << '\n' <<"Is the word GOOD in the RBTree?";
  if (dir.search(tmp1))
  {
    std::cout << " Yes" << std::endl;
  }
  else
  {
    std::cout << " No" << std::endl;
  }
  std::cout << "Is the word BAD in the tree? ";
  std::string s3 = "bad";
  if (dir.search(s3))
  {
    std::cout << " Yes" << std::endl;
  }
  else
  {
    std::cout << " No" << std::endl;
  }
  std::cout << "Remove the word LITTLE and FAST from the RBTree"<< "\n";
  dir.remove(temp1);
  dir.remove(string1);
  std::cout << "Print RBTree after removing words";
  dir.print(std::cout);
}

void testDeleteInEmptyTreeExceptionRBTree()
{
  RBTree dir;
  std::string str2 = "pretty";
  dir.remove(str2);
}

void testDeleteNonExistentElementRBTree()
{
  SinglyLinkedOrderedList list;
  std::string str = "beautiful";
  list.insert(str);
  RBTree dir;
  std::string str2 = "pretty";
  dir.insert(str2, list);
  dir.remove(str);
}

void testInsertRepeatingElementRBTree()
{
  SinglyLinkedOrderedList list;
  std::string str = "beautiful";
  list.insert(str);
  RBTree dir;
  std::string str2 = "pretty";
  dir.insert(str2, list);
  dir.insert(str2, list);
}

void testInsertIncorrectWordInList()
{
  SinglyLinkedOrderedList list;
  std::string str = "Nastia%";
  list.insert(str);
}

void testInsertIncorrectWordInRBTree()
{
  SinglyLinkedOrderedList list;
  std::string str = "beautiful";
  list.insert(str);
  RBTree dir;
  std::string str2 = "pretty%";
  dir.insert(str2, list);
}





