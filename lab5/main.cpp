#include <iostream>
#include "exception.hpp"
#include "QueueArray.hpp"
#include "Queuelist.hpp"

int main()
{
  std::cout << "<------created array queue------> \n";

  QueueArray<int> arrQueue;
  
  arrQueue.enQueue(37);
  arrQueue.enQueue(15);
  arrQueue.enQueue(23);
  
  QueueArray<int> arrQueueCopy(arrQueue);
  
  std::cout << "array queue is: \n";
  std::cout << arrQueue.deQueue() << ' ';
  std::cout << arrQueue.deQueue() << ' ';
  std::cout << arrQueue.deQueue() << '\n';

  std::cout << "coped array queue is: \n";
  std::cout << arrQueueCopy.deQueue() << ' ';
  std::cout << arrQueueCopy.deQueue() << ' ';
  std::cout << arrQueueCopy.deQueue() << '\n';

  std::cout << "<------created list queue------>\n";
  QueueList<int> listQueue;
  listQueue.enQueue(15);
  listQueue.enQueue(52);
  listQueue.enQueue(37);
  listQueue.enQueue(23);
  listQueue.enQueue(23);
  listQueue.enQueue(47);

  QueueList<int> listQueueCopy(listQueue);
  std::cout << "list queue: \n";
  std::cout << listQueue.deQueue() << ' ';
  std::cout << listQueue.deQueue() << ' ';
  std::cout << listQueue.deQueue() << ' ';
  std::cout << listQueue.deQueue() << ' ';
  std::cout << listQueue.deQueue() << ' ';
  std::cout << listQueue.deQueue() << '\n';

  std::cout << "coped list queue: \n";
  std::cout << listQueueCopy.deQueue() << ' ';
  std::cout << listQueueCopy.deQueue() << ' ';
  std::cout << listQueueCopy.deQueue() << ' ';
  std::cout << listQueueCopy.deQueue() << ' ';
  std::cout << listQueueCopy.deQueue() << ' ';
  std::cout << listQueueCopy.deQueue() << ' ';


  return 0;
}