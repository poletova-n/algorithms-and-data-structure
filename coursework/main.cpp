#include "ttTree.h"
#include <iostream>

int main()
{
  std::string path = "D:\\KURSACH_ALGOSI\\tale.txt";
  std::ifstream input(path);
  if (!input)
  {
    std::cout << "Invalid File Name. Restart Program.\n";
    return 2;
  }
  else
  {
    ttTree myTree;
    myTree.buildTree(input);
    input.close();
    myTree.printTree(std::cout);
  }
  return 0;
}
