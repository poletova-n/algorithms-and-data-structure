#include <iostream>
#include <exception>

#include "queue.hpp"
#include "queueArray.hpp"
#include "QueueList.hpp"

int main() {

  QueueArray<int> queue;
  queue.enQueue(5);
  queue.enQueue(10);
  queue.enQueue(4);
  queue.enQueue(3);
  queue.print(std::cout);
  queue.deQueue();
  queue.print(std::cout);

  QueueList<int> kyeye;
  kyeye.enQueue(11);
  kyeye.enQueue(12);
  kyeye.enQueue(13);
  kyeye.enQueue(14);
  kyeye.enQueue(15);
  kyeye.print(std::cout);
  kyeye.deQueue();
  kyeye.deQueue();
  kyeye.print(std::cout);

  return 0;
}
