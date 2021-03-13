#ifndef TEST_QUEUE_HPP
#define TEST_QUEUE_HPP

#include <iostream>

#include "queueArray.hpp"
#include "exception.hpp"

void testQueue()
{
  try
  {
    std::cout << "\tTEST1. OVERFLOW\n";
    QueueArray<int> Queue(5);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.enQueue(1);
    Queue.enQueue(-3);
    Queue.enQueue(8);
    Queue.enQueue(9);
  }
  catch (const QueueOverflow &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const QueueUnderflow &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  try
  {
    std::cout << "\n\tTEST2. UNDERFLOW\n";
    QueueArray<int> Queue(5);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.enQueue(1);
    Queue.deQueue();
    Queue.deQueue();
    Queue.deQueue();
    Queue.deQueue();
  }
  catch (const QueueOverflow &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const QueueUnderflow &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  try
  {
    std::cout << "\n\tTEST 3\n";
    QueueArray<int> Queue(6);
    Queue.enQueue(2);
    Queue.enQueue(3);
    std::cout << "\nQueue: ";
    Queue.print(std::cout);
    std::cout << "\nDelete 1 times\n";
    Queue.deQueue();
    Queue.print(std::cout);
    std::cout << "\nInsert 9, 2, 3, 6\n";
    Queue.enQueue(9);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.enQueue(6);
    Queue.print(std::cout);
  }
  catch (const QueueUnderflow &e)
  {
    std::cout << "\n" << e.what() << "\n";
  } catch (const QueueOverflow &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  try
  {
    QueueArray<int> Queue(6);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.enQueue(1);
    Queue.enQueue(8);
    QueueArray<int> Queue2(Queue.rValue());
    Queue.print(std::cout);
    Queue2.print(std::cout);
  }
    catch (const WrongQueueSize &e)
  {
    std::cerr << "\n" << e.what() << "\n";
  }
  catch (const QueueUnderflow &e)
  {
    std::cerr << "\n" << e.what() << "\n";
  }
  catch (const QueueOverflow &e)
  {
    std::cerr << "\n" << e.what() << "\n";
  }
  try
  {
    std::cout << "\n\n\tTEST4. TESTING THE TRANSITION THROUGH THE END OF THE ARRAY\n";
    QueueArray<int> Queue(6);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.enQueue(1);
    Queue.enQueue(8);
    std::cout << "\nQueue: ";
    Queue.print(std::cout);
    std::cout << "\nDelete 3 times\n";
    Queue.deQueue();
    Queue.deQueue();
    Queue.deQueue();
    Queue.print(std::cout);
    std::cout << "\nInsert 9, 2, 3, 6\n";
    Queue.enQueue(9);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.enQueue(6);
    Queue.enQueue(8);
    Queue.print(std::cout);
  }
  catch (const QueueUnderflow &e)
  {
    std::cerr << "\n" << e.what() << "\n";
  }
  catch (const QueueOverflow &e)
  {
    std::cerr << "\n" << e.what() << "\n";
  }

}
#endif
