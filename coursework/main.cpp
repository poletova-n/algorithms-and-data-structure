#include <iostream>
#include "tests.hpp"
int main()
{
  std::cout << "Test SinglyOrderList:" << '\n';
  testRightWorkList();
  std::cout << '\n' << '\n' << "Test RBTree:" << '\n';
  testRightWorkRBTree();
}
