#include <iostream>
#include "Queue.h"
#include "BinarySearchTree.h"

int main()
{
  try
  {
    QueueArray<int> q(4);
    //QueueArray<int> q1(-3); // Wrong size
    //q.push(1); q.push(2); q.push(3); q.push(4); q.push(5); // Owerflow
    //q.pop(); // Underflow

    q.push(1); q.push(2);
    std::cout << q.pop() << " "; std::cout << q.pop() << "\n";
    q.push(1); q.push(2); q.push(3); q.push(4);
    std::cout << q.pop() << " "; std::cout << q.pop() << " "; std::cout << q.pop() << " "; std::cout << q.pop() << "\n";
    std::cout << "empty : " << q.isEmpty() << "\n\n";

    BinarySearchTree<int> tree1;
    tree1.insert(3); tree1.insert(-8); tree1.insert(15); tree1.insert(-10); tree1.insert(1);
    tree1.insert(10); tree1.insert(100); tree1.insert(2); tree1.insert(11); tree1.insert(115);

    std::cout << "iterativeWidthWalk, tree1 : ";
    int* arr1 = tree1.iterativeWidthWalk();
    for (size_t i = 0; i < tree1.getCount(); i++)
    {
      std::cout << arr1[i] << " ";
    }
    delete[] arr1;
    std::cout << "\n";

    std::cout << "iterativeInorderWalk, tree1 : ";
    int* arr2 = tree1.iterativeInorderWalk();
    for (size_t i = 0; i < tree1.getCount(); i++)
    {
      std::cout << arr2[i] << " ";
    }
    delete[] arr2;
    std::cout << "\n";

    BinarySearchTree<int> tree2;
    tree2.insert(10); tree2.insert(-8); tree2.insert(2); tree2.insert(3); tree2.insert(-10);
    tree2.insert(1);tree2.insert(100); tree2.insert(15); tree2.insert(115); tree2.insert(11);

    std::cout << "tree1 similar tree2 : " << tree1.isSimilar(tree2) << "\n";
    BinarySearchTree<int> treeEmpty;
    std::cout << "tree1 similar treeEmpty : " << tree1.isSimilar(treeEmpty) << "\n";
  }
  catch (const WrongQueueSize& e)
  {
    std::cerr << e.what();
  }
  catch (const QueueOverflow& e)
  {
    std::cerr << e.what();
  }
  catch (const QueueUnderflow& e)
  {
    std::cerr << e.what();
  }
}