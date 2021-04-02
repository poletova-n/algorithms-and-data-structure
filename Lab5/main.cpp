#include "exceptions.h"
#include "queuearray.h"
#include "queuelist.h"

#include <iostream>

int main()
{
  std::cout << "Created Queue on Array: \n";
  QueueArray<int> arr;
  arr.enQueue(3);
  arr.enQueue(8);
  arr.enQueue(-1);
  arr.enQueue(4);
  std::cout << "Used copy constructor. \n";
  QueueArray<int> arr2(arr);
  std::cout << "First queue: \n";
  std::cout << arr.deQueue() << ' ';
  std::cout << arr.deQueue() << ' ';
  std::cout << arr.deQueue() << ' ';
  std::cout << arr.deQueue() << '\n';

  std::cout << "Second queue: \n";
  std::cout << arr2.deQueue() << ' ';
  std::cout << arr2.deQueue() << ' ';
  std::cout << arr2.deQueue() << ' ';
  std::cout << arr2.deQueue() << '\n';

  std::cout << "Created Queue on List: \n";
  QueueList<int> arr3;
  arr3.enQueue(3);
  arr3.enQueue(8);
  arr3.enQueue(-1);
  arr3.enQueue(4);
  std::cout << "Used copy constructor. \n";
  QueueList<int> arr4(arr3);
  std::cout << "First queue: \n";
  std::cout << arr3.deQueue() << ' ';
  std::cout << arr3.deQueue() << ' ';
  std::cout << arr3.deQueue() << ' ';
  std::cout << arr3.deQueue() << '\n';

  std::cout << "Second queue: \n";
  std::cout << arr4.deQueue() << ' ';
  std::cout << arr4.deQueue() << ' ';
  std::cout << arr4.deQueue() << ' ';
  std::cout << arr4.deQueue() << ' ';

  return 0;
}