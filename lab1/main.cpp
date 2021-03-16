#include "List.hpp"
#include "DoubleLinkedList.hpp"

int main()
{
  std::cout << "Test -= operator for SingleLinkedList" << "\n";
  List singleList;
  DoubleLinkedList doubleList;
  singleList += 1;
  singleList += 2;
  singleList += 4;
  singleList += 5;
  singleList += 66;
  singleList += 15;
  singleList += 33;
  singleList.print();
  singleList -= 33;
  singleList.print();
  singleList -= 1;
  singleList.print();
  singleList -= 66;
  singleList.print();
  singleList -= 5;
  singleList.print();
  std::cout << "\nTest -= operator for DoubleLinkedList\n";
  doubleList += 3;
  doubleList += 4;
  doubleList += 5;
  doubleList += 33;
  doubleList += 2;
  doubleList += 70;
  doubleList.print();
  doubleList -= 2;
  doubleList.print();
  doubleList -= 70;
  doubleList.print();
  doubleList -= 5;
  doubleList.print();
  try        //single linked list
  {
    List firstSingleList;
    List secondSingleList;
    List thirdSingleList;
    List fourthSingleList;
    firstSingleList += 1;
    firstSingleList += 2;
    firstSingleList += 4;
    firstSingleList += 5;
    firstSingleList += 66;
    firstSingleList += 15;
    firstSingleList += 33;
    secondSingleList += 3;
    secondSingleList += 4;
    secondSingleList += 5;
    secondSingleList += 33;
    secondSingleList += 2;
    secondSingleList += 70;
    thirdSingleList = firstSingleList | secondSingleList;
    fourthSingleList = firstSingleList & secondSingleList;
    std::cout << "\nSingle Linked List" << std::endl
              << "List 1" << std::endl
              << firstSingleList << std::endl << std::endl
              << "List 2" << std::endl
              << secondSingleList << std::endl << std::endl;
    if (firstSingleList == secondSingleList)
    {
      std::cout << "Lists are equal (List 1 and List 2)" << std::endl;
    }
    else
    {
      std::cout << "Lists aren't equal (List 1 and List 2)" << std::endl << std::endl;
    }
    std::cout << "List 3. Merge |" << std::endl
              << thirdSingleList << std::endl << std::endl
              << "List 4. Merge &" << std::endl
              << fourthSingleList << std::endl << std::endl
              << "Merge method" << std::endl;
    firstSingleList.merge(secondSingleList);
    std::cout << "List 1" << std::endl
              << firstSingleList << std::endl << std::endl
              << "List 2" << std::endl
              << secondSingleList << std::endl << std::endl;
  }
  catch (const char *exception)
  {
    std::cout << "Caught an exception" << std::endl
              << exception << std::endl;
  }
  try        //double linked list
  {
    DoubleLinkedList firstDoubleList;
    DoubleLinkedList secondDoubleList;
    DoubleLinkedList thirdDoubleList;
    DoubleLinkedList fourthDoubleList;
    firstDoubleList += 1;
    firstDoubleList += 2;
    firstDoubleList += 4;
    firstDoubleList += 5;
    firstDoubleList += 66;
    firstDoubleList += 15;
    firstDoubleList += 33;
    secondDoubleList += 3;
    secondDoubleList += 4;
    secondDoubleList += 5;
    secondDoubleList += 33;
    secondDoubleList += 2;
    secondDoubleList += 70;
    thirdDoubleList = firstDoubleList | secondDoubleList;
    fourthDoubleList = firstDoubleList & secondDoubleList;
    std::cout << "Double Linked List" << std::endl
              << "List 1" << std::endl
              << firstDoubleList << std::endl << std::endl
              << "List 2" << std::endl
              << secondDoubleList << std::endl << std::endl;
    if (firstDoubleList == secondDoubleList)
    {
      std::cout << "Lists are equal (List 1 and List 2)" << std::endl;
    }
    else
    {
      std::cout << "Lists aren't equal (List 1 and List 2)" << std::endl << std::endl;
    }
    std::cout << "List 3. Merge |" << std::endl
              << thirdDoubleList << std::endl << std::endl
              << "List 4. Merge &" << std::endl
              << fourthDoubleList << std::endl << std::endl
              << "Merge method" << std::endl;
    firstDoubleList.merge(secondDoubleList);
    std::cout << "List 1" << std::endl
              << firstDoubleList << std::endl << std::endl
              << "List 2" << std::endl
              << secondDoubleList << std::endl;
  }
  catch (const char *exception)
  {
    std::cout << "Caught an exception"
              << exception << std::endl;
  }
  return 0;
}
