#include <iostream>
#include "queuearray.hpp"
#include "queuelist.hpp"

int main()
{
  std::cout << "Creating queue array with size = 10.\n";
  QueueArray<int> firstArrayQueue(10);
  std::cout << "Inserting numbers from 1 to 10.\n";
  firstArrayQueue.enQueue(1);
  firstArrayQueue.enQueue(2);
  firstArrayQueue.enQueue(3);
  firstArrayQueue.enQueue(4);
  firstArrayQueue.enQueue(5);
  firstArrayQueue.enQueue(6);
  firstArrayQueue.enQueue(7);
  firstArrayQueue.enQueue(8);
  firstArrayQueue.enQueue(9);
  firstArrayQueue.enQueue(10);
  try
  {
    std::cout << "Trying to insert one more number: \n";
   firstArrayQueue.enQueue(4);
  }
  catch (const QueueOverflow& error)
  {
    std::cout << error.what() << "\n";
  }
  std::cout << "Copying current queue to the new one.\n";
  QueueArray<int> secondArrayQueue(firstArrayQueue);
  std::cout << "Popping items from queue: \n";
  for(int i = 0;i<10;i++)
  {
    std::cout << secondArrayQueue.deQueue() << " ";
  }
  try
  {
    std::cout << "\nTrying to pop one more item: \n";
    secondArrayQueue.deQueue();
  }
  catch (const QueueUnderflow& error)
  {
    std::cout << error.what() << "\n";
  }

  std::cout << "\nCreating list queue and filling it with numbers from 1 to 3.\n";
  QueueList<int> firstQueueList;
  firstQueueList.enQueue(1);
  firstQueueList.enQueue(2);
  firstQueueList.enQueue(3);
  std::cout << "Copying current queue list to the new one.\n";
  QueueList<int> secondQueueList(firstQueueList);
  std::cout << "Popping items from queue: \n";
  for(int i = 0;i<3;i++)
  {
    std::cout << secondQueueList.deQueue() << " ";
  }
  return 0;
}

