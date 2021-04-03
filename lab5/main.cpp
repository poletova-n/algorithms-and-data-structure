#include <iostream>
#include <random>
#include "queuearray.hpp"
#include "queuelist.hpp"

void testQueueArray(size_t n);
void testQueueList(size_t n);

int main()
{
  std::ios::sync_with_stdio(false);
  size_t n;
  std::cout << "Enter size of queue:\n";
  std::cin >> n;
  if (std::cin.fail()) {
    std::cerr << "Fail with reading of integer number!";
    return 2;
  }
  try {
    testQueueArray(n);
  } catch (const WrongQueueSize& e) {
    std::cerr << e.what();
    return 1;
  } catch (const QueueUnderflow& e) {
    std::cerr << e.what();
    return 1;
  } catch (const QueueOverflow& e) {
    std::cerr << e.what();
    return 1;
  } catch (const std::runtime_error& e) {
    std::cerr << e.what();
    return 2;
  }

  try {
    testQueueList(n);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what();
    return 1;
  }

  return 0;
}

void testQueueArray(size_t n)
{
  QueueArray<int> queueArray(n);

  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_real_distribution<> dis(0, 666);

  for (size_t i = 0; i < n; ++i) {
    queueArray.push(dis(gen));
  }

  queueArray.print(std::cout);

  std::cout << "Enter the number of elements to be deleted:\n";
  size_t del;
  std::cin >> del;

  if (std::cin.fail()) {
    throw std::runtime_error("Fail with reading of integer number!");
  }

  for (size_t i = 0; i < del; ++i) {
    queueArray.pop();
  }

  queueArray.print(std::cout);
}

void testQueueList(size_t n)
{
  QueueList<int> queueList;

  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_real_distribution<> dis(0, 666);

  for (size_t i = 0; i < n; ++i) {
    queueList.push(dis(gen));
  }

  queueList.print(std::cout);

  std::cout << "Enter the number of elements to be deleted:\n";
  size_t del;
  std::cin >> del;

  if (std::cin.fail()) {
    throw std::runtime_error("Fail with reading of integer number!");
  }

  for (size_t i = 0; i < del; ++i) {
    queueList.pop();
  }

  queueList.print(std::cout);
}
