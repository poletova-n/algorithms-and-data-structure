#include <iostream>
#include "queue.hpp"
#include "queue_array.hpp"
#include "queue_list.hpp"
#include "BinarySearchTree.hpp"

int main() {
  std::cout << "\n------------------------------------------------\n";
  std::cout << "Creating QueueArray with size = 10 ....\n";
  QueueArray<int> temp(10);
  temp.enQueue(5);
  temp.enQueue(6);
  temp.enQueue(7);
  temp.enQueue(8);
  temp.enQueue(9);
  temp.enQueue(77);
  temp.enQueue(88);
  temp.enQueue(99);
  temp.enQueue(11);
  temp.enQueue(12);
  std::cout << "Creating QueueArray with size = 10 completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Check function isEmpty() ....\n";
  if(temp.isEmpty()){std::cout<<"temp is empty!\n";}else{std::cout<<"temp is not empty!\n";}
  std::cout << "Check function isEmpty() completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Testing function deQueue 10 times ....\n";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << temp.deQueue() << " ";
  std::cout << "\nTesting function deQueue 10 times completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Check function isEmpty() ....\n";
  if(temp.isEmpty()){std::cout<<"temp is empty!\n";}else{std::cout<<"temp is not empty!\n";}
  std::cout << "Check function isEmpty() completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Testing copy constructor ....\n";
  std::cout << "Creating first queue ....\n";
  QueueArray<int> first(10);
  first.enQueue(5);
  first.enQueue(6);
  first.enQueue(7);
  first.enQueue(8);
  first.enQueue(9);
  first.enQueue(77);
  first.enQueue(88);
  first.enQueue(99);
  first.enQueue(11);
  first.enQueue(12);
  std::cout << "Creating first queue completed!\n";
  std::cout << "Copy first to 'copy' ....\n";
  QueueArray<int> copy(first);
  std::cout << "Copy first to 'copy' completed!\n";
  std::cout << "Check all queue's ....\n";
  std::cout << "First: ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout << first.deQueue() << " ";
  std::cout<< "\nCopy: ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << copy.deQueue() << " ";
  std::cout << "Check all queue's completed!\n";
  std::cout << "Testing copy constructor completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Test errors throw ...\n";
  QueueArray<int> err(3);
  err.enQueue(1);
  err.enQueue(2);
  err.enQueue(3);
  std::cout << "Try to put one element over size ...\n";
  try{
    err.enQueue(4);
  }catch (QueueOverflow error){
    std::cout<<error.reason()<<"\n";
  }
  std::cout << "Try to get one element in empty queue ...\n";
  err.deQueue();
  err.deQueue();
  err.deQueue();
  try{
    err.deQueue();
  }catch (QueueUnderflow error){
    std::cout<<error.reason()<<"\n";
  }
  std::cout << "Try to construct queue with invalid size ...\n";
  try{
    QueueArray<int> ival(-1);
  }catch (WrongQueueSize error){
    std::cout<<error.reason()<<"\n";
  }
  std::cout << "Test errors throw completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "START TESTING LISTQUEUE!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Creating QueueList ....\n";
  QueueList<int> liss;
  liss.enQueue(5);
  liss.enQueue(6);
  liss.enQueue(7);
  liss.enQueue(8);
  liss.enQueue(9);
  std::cout << "Creating QueueList completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Check function isEmpty() ....\n";
  if(liss.isEmpty()){std::cout<<"liss is empty!\n";}else{std::cout<<"liss is not empty!\n";}
  std::cout << "Check function isEmpty() completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Testing function deQueue 5 times ....\n";
  std::cout << liss.deQueue() << " ";
  std::cout << liss.deQueue() << " ";
  std::cout << liss.deQueue() << " ";
  std::cout << liss.deQueue() << " ";
  std::cout << liss.deQueue() << " ";
  std::cout << "\nTesting function deQueue 5 times completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Check function isEmpty() ....\n";
  if(liss.isEmpty()){std::cout<<"liss is empty!\n";}else{std::cout<<"liss is not empty!\n";}
  std::cout << "Check function isEmpty() completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Testing copy constructor ....\n";
  std::cout << "Creating first queue ....\n";
  QueueList<int> frst;
  frst.enQueue(5);
  frst.enQueue(6);
  frst.enQueue(7);
  frst.enQueue(8);
  frst.enQueue(9);
  std::cout << "Creating first queue completed!\n";
  std::cout << "Copy first to 'copy' ....\n";
  QueueList<int> cop(frst);
  std::cout << "Copy first to 'copy' completed!\n";
  std::cout << "Check all queue's ....\n";
  std::cout << "First: ";
  std::cout << frst.deQueue() << " ";
  std::cout << frst.deQueue() << " ";
  std::cout << frst.deQueue() << " ";
  std::cout << frst.deQueue() << " ";
  std::cout << frst.deQueue() << " ";
  std::cout<< "\nCopy: ";
  std::cout << cop.deQueue() << " ";
  std::cout << cop.deQueue() << " ";
  std::cout << cop.deQueue() << " ";
  std::cout << cop.deQueue() << " ";
  std::cout << cop.deQueue() << " ";
  std::cout << "Check all queue's completed!\n";
  std::cout << "Testing copy constructor completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Test errors throw ...\n";
  QueueList<int> erro;
  erro.enQueue(1);
  erro.enQueue(2);
  erro.enQueue(3);
  std::cout << "Try to get one element in empty queue ...\n";
  erro.deQueue();
  erro.deQueue();
  erro.deQueue();
  try{
    erro.deQueue();
  }catch (QueueUnderflow error){
    std::cout<<error.reason()<<"\n";
  }
  std::cout << "Test errors throw completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "START TESTING TREE FUNCTIONS!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Creating tree with numbers: 7 2 6 11 4\n";
  BinarySearchTree<int> tree;
  tree.add_iter(7);
  tree.add_iter(2);
  tree.add_iter(6);
  tree.add_iter(11);
  tree.add_iter(4);
  std::cout << "Creating tree completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Testing function iter_width() ...\n";
  tree.iter_width();
  std::cout << "Testing function completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Testing function iter_left_right() ...\n";
  tree.iter_left_right();
  std::cout << "Testing function completed!\n";
  std::cout << "\n------------------------------------------------\n";

  std::cout << "\n------------------------------------------------\n";
  std::cout << "Testing function is_same() ...\n";
  std::cout << "Creating copy of tree ...\n";
  BinarySearchTree<int> coppy(tree);
  std::cout << "Creating copy of tree completed\n";
  if(tree.is_same(coppy)){std::cout<<"trees is same \n";}else{std::cout<<"trees not same :( \n";}
  std::cout << "Creating another tree..\n";
  BinarySearchTree<int> not_copy;
  not_copy.add_iter(7);
  not_copy.add_iter(2);
  not_copy.add_iter(6);
  not_copy.add_iter(11);
  std::cout << "Creating another tree completed\n";
  if(tree.is_same(not_copy)){std::cout<<"trees is same \n";}else{std::cout<<"trees not same :( \n";}
  std::cout << "Testing function completed!\n";
  std::cout << "\n------------------------------------------------\n";

  return 0;
}
