#include <iostream>
#include "queueArray.hpp"
#include "queueList.hpp"

int main()
{
  std::cout << "\n Test queue by array \n";

  QueueArray<int> queue1;
  queue1.enQueue(10);
  queue1.enQueue(5);
  queue1.enQueue(3);
  queue1.enQueue(2);
  queue1.enQueue(8);
  queue1.enQueue(6);

  std::cout << "1 queue: ";
  queue1.print(std::cout);
  std::cout << "\n";

  QueueArray<int> queue2(queue1);

  std::cout << "copy of queue: ";
  queue2.print(std::cout);
  std::cout << "\n";

  queue1.deQueue();
  queue1.deQueue();
  queue1.deQueue();

  std::cout << "queue 1 after remove 3 elements: ";
  queue1.print(std::cout);
  std::cout << "\n";

  std::cout << "\n Test queue by list \n";

  QueueList<int> queue3;
  queue3.enQueue(10);
  queue3.enQueue(5);
  queue3.enQueue(3);
  queue3.enQueue(2);
  queue3.enQueue(8);
  queue3.enQueue(6);

  std::cout << "3 queue: ";
  queue3.print(std::cout);
  std::cout << "\n";

  QueueList<int> queue4(queue3);

  std::cout << "copy of queue: ";
  queue4.print(std::cout);
  std::cout << "\n";

  queue3.deQueue();
  queue3.deQueue();
  queue3.deQueue();

  std::cout << "queue 3 after remove 3 elements: ";
  queue3.print(std::cout);
  std::cout << "\n";

  return 0;
}
