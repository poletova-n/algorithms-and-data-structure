#include <iostream>
#include "Queue.hpp"
#include "QueueArray.hpp"
#include "QueueList.hpp"

int main()
{
  QueueArray<int> queue;
  queue.insertQueue(13);
  queue.insertQueue(1);
  queue.insertQueue(-22);
  queue.insertQueue(8);
  queue.insertQueue(99);

  QueueArray<int>queueCopy(queue);

  std::cout << "1st queue (Array):\n"
            << queue.deQueue() << ' ' << queue.deQueue() << ' ' << queue.deQueue() << ' '
            << queue.deQueue() << ' ' << queue.deQueue() << '\n';

  std::cout << "2nd queue (Array) [copy first]:\n"
            << queueCopy.deQueue() << ' ' << queueCopy.deQueue() << ' ' << queueCopy.deQueue() << ' '
            << queueCopy.deQueue() << ' ' << queueCopy.deQueue() << '\n';

  QueueList<int> queue2;
  queue2.insertQueue(54);
  queue2.insertQueue(8);
  queue2.insertQueue(-111);
  queue2.insertQueue(65);

  QueueList<int> queueTwoCopy(queue2);

  std::cout << "1st queue (List):\n"
            << queue2.deQueue() << ' ' << queue2.deQueue() << ' ' << queue2.deQueue() << ' '
            << ' ' << queue2.deQueue() << '\n';

  std::cout << "2nd queue (List) [copy first]:\n"
            << queueTwoCopy.deQueue() << ' ' << queueTwoCopy.deQueue() << ' ' << queueTwoCopy.deQueue() << ' '
            << ' ' << queueTwoCopy.deQueue() << '\n';

  return 0;
}
