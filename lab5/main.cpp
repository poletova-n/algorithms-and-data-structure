#include <iostream>

#include "binarySearchTree.hpp"
#include "stackArray.hpp"
#include "queueArray.hpp"

void testQueue();
void testIterativeWalksByStackAndQueue();
void testSimilarity();

int main()
{
  testQueue();
  std::cout << std::endl;
  testIterativeWalksByStackAndQueue();
  std::cout << std::endl;
  testSimilarity();
  return 0;
}

void testQueue()
{
  std::cout << "\ttestQueue\n";
  try {
    std::cout << "Create intQueue\n";
    QueueArray<int> queue(5);

    try {
      std::cout << "Push 12\n"; queue.enQueue(12);
      std::cout << "Push 1\n"; queue.enQueue(1);
      std::cout << "Push 5\n"; queue.enQueue(5);
      std::cout << "Push -65\n"; queue.enQueue(-65);
      std::cout << "Push 9\n"; queue.enQueue(9);
    }
    catch (QueueOverflow& exceptionOver)
    {
      std::cerr << exceptionOver.getError() << std::endl;
    }

    try {
      std::cout << "Get current front " << queue.deQueue() << std::endl;
      std::cout << "Get current front " << queue.deQueue() << std::endl;
      std::cout << "Get current front " << queue.deQueue() << std::endl;
      std::cout << "Get current front " << queue.deQueue() << std::endl;
      std::cout << "Get current front " << queue.deQueue() << std::endl;
    }
    catch (QueueUnderflow& exceptionUnder) {
      std::cerr << exceptionUnder.getError() << std::endl;
    }

    try {
      std::cout << "Push 234\n"; queue.enQueue(234);
      std::cout << "Push 169\n"; queue.enQueue(169);
    }
    catch (QueueOverflow& exceptionOver)
    {
      std::cerr << exceptionOver.getError() << std::endl;
    }

    try {
      std::cout << "Get current front " << queue.deQueue() << std::endl;
    }
    catch (QueueUnderflow& exceptionUnder) {
      std::cerr << exceptionUnder.getError() << std::endl;
    }
  }
  catch (WrongQueueSize& exceptionWrong) {
    std::cerr << "Error: " << exceptionWrong.getError() << std::endl;
  }
}

void testIterativeWalksByStackAndQueue()
{
  std::cout << "\ttestIterativeWalksByStackAndQueue\n";
  BinarySearchTree<int> tree1;

  std::cout << (tree1.insert(8) ? "correct insert 8\n" : "oops... we can't insert 8\n");
  std::cout << (tree1.insert(12) ? "correct insert 12\n" : "oops... we can't insert 12\n");
  std::cout << (tree1.insert(6) ? "correct insert 6\n" : "oops... we can't insert 6\n");
  std::cout << (tree1.insert(8) ? "correct insert 8\n" : "oops... we can't insert 8 again\n");
  std::cout << (tree1.insert(7) ? "correct insert 7\n" : "oops... we can't insert 7\n");
  std::cout << (tree1.insert(5) ? "correct insert 5\n" : "oops... we can't insert 5\n");
  std::cout << (tree1.insert(-3) ? "correct insert -3\n" : "oops... we can't insert -3\n");
  std::cout << (tree1.insert(10) ? "correct insert 10\n" : "oops... we can't insert 10\n");
  std::cout << (tree1.insert(17) ? "correct insert 17\n" : "oops... we can't insert 17\n");
  std::cout << (tree1.insert(15) ? "correct insert 15\n" : "oops... we can't insert 15\n");
  std::cout << (tree1.insert(11) ? "correct insert 11\n" : "oops... we can't insert 11\n");

  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "At int tree now we have " << tree1.getCount() << " nodes\n";
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << (tree1.deleteKey(-3) ? "correct delete -3\n" : "oops... we can't delete -3\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(90) ? "correct delete 90\n" : "oops... we can't delete 90\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(7) ? "correct delete 7\n" : "oops... we can't delete 7\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(6) ? "correct delete 6\n" : "oops... we can't delete 6\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(10) ? "correct delete 10\n" : "oops... we can't delete 10\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(12) ? "correct delete 12\n" : "oops... we can't delete 12\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << "At int tree now we have " << tree1.getCount() << " nodes\n";
  std::cout << "Iterative infix walk by Stack: "; tree1.iterativeInfixWalkByStack();
  std::cout << "Iterative width walk by Queue: "; tree1.iterativeWidthWalkByQueue();
}

void testSimilarity()
{
  std::cout << "\ttestSimilarity\n";
  BinarySearchTree<int> first;
  first.insert(1);
  first.insert(10);
  first.insert(5);
  first.insert(12);
  first.insert(73);
  first.insert(-3);
  std::cout << "First tree now: "; first.iterativeInfixWalkByStack();
  BinarySearchTree<int> second;
  second.insert(12);
  second.insert(50);
  second.insert(1);
  second.insert(73);
  second.insert(-3);
  std::cout << "Second tree now: "; second.iterativeInfixWalkByStack();

  std::cout << (first.isSimilar(second) ? "Trees are similar" : "Trees are not similar") << std::endl;
  std::cout << "------------------------------------------------------------------------------------\n";

  first.deleteKey(5);
  std::cout << std::endl;
  first.deleteKey(10);
  std::cout << std::endl;
  second.deleteKey(50);
  std::cout << std::endl;
  std::cout << "First tree now: "; first.iterativeInfixWalkByStack();
  std::cout << "Second tree now: "; second.iterativeInfixWalkByStack();
  std::cout << (first.isSimilar(second) ? "Trees are similar" : "Trees are not similar") << std::endl;
  std::cout << "------------------------------------------------------------------------------------\n";
}
