#include <ostream>

#include "Tree.h"

int main()
{
  Tree<int> tree;

  tree.insert(10);
  tree.insert(5);
  tree.insert(11);
  tree.insert(12);
  tree.insert(2);
  tree.insert(25);

  std::cout << "Tree: ";
  tree.print(std::cout);

  std::cout << "Node count: " << tree.getCount() << "\n\n";
  std::cout << "Tree height: " << tree.getHeight() << "\n\n";

  std::cout << "Iterative Search\n";

  if (tree.iterativeSearch(10))
  {
    std::cout << "Tree contains 10 - true\n";
  }
  else
  {
    std::cout << "Tree contains 10 - false\n";
  }

  if (tree.iterativeSearch(4))
  {
    std::cout << "Tree contains 4 - true\n";
  }
  else
  {
    std::cout << "Tree contains 4 - false\n";
  }


  std::cout << tree.nextNode(11) << '\n';

  tree.deleteKey(5);

  if (tree.iterativeSearch(5))
  {
    std::cout << "Tree contains 5 - true\n";
  }
  else
  {
    std::cout << "Tree contains 5 - false\n";
  }

  return 0;
}
