#include <iostream>
#include <exception>
#include <limits>
#include "queuearray.hpp"
#include "queuelist.hpp"

int main()
{
  QueueArray<int> queueArray;
  std::cout << "It's first part of the program. Here's checking class QueueArray.\n"
            << "Queue array is queue of int.\n"
            << "Please, input the numbers, which you want to enter into the queue.\n"
            << "If you want to stop the input, write something else.\n";
  while (true)
  {
    int input;
    std::cin >> input;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
    try
    {
      queueArray.enQueue(input);
    }
    catch (QueueOverflow& exception)
    {
      std::cerr << '\n' << exception.what();
      return 1;
    }
  }

  std::cout << "Please input the count of deQueue your queue:\n";
  int count1;
  std::cin >> count1;
  count1 = abs(count1);

  try
  {
    for (size_t i = 0; i < count1; ++i)
    {
      std::cout << queueArray.head() << ' ';
      queueArray.deQueue();
    }
  }
  catch (QueueUnderflow& exception)
  {
    std::cerr << '\n' << exception.what();
    return 1;
  }
  std::cout << " - numbers which was deQueued\n";

  std::cout << (queueArray.empty() ? "Queue is empty.\n" : "Queue is not empty.\n") << '\n';

  QueueList<int> queueList;
  std::cout << "It's second part of the program. Here's checking class QueueList.\n"
            << "Queue list is queue of int.\n"
            << "Please, input the numbers, which you want to enter into the queue.\n"
            << "If you want to stop the input, write something else.\n";
  while (true)
  {
    int input;
    std::cin >> input;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
    queueList.enQueue(input);
  }

  std::cout << "Please input the count of deQueue your queue:\n";
  int count2;
  std::cin >> count2;
  count2 = abs(count2);

  try
  {
    for (size_t i = 0; i < count2; ++i)
    {
      std::cout << queueList.head() << ' ';
      queueList.deQueue();
    }
  }
  catch (QueueUnderflow& exception)
  {
    std::cerr << '\n' << exception.what();
    return 1;
  }
  catch (std::out_of_range& exception)
  {
    std::cerr << '\n' << exception.what();
    return 1;
  }
  std::cout << " - numbers which was deQueued\n";

  std::cout << '\n' << (queueList.empty() ? "Queue is empty.\n" : "Queue is not empty.\n");

  return 0;
}