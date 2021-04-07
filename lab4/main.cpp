#include "BinarySearchTree.h"
using namespace std;

int main()
{
  Tree t;

  t.print(cout);
  cout << endl << "Number of vertexes: " << t.getCount();
  cout << endl << "Height: " << t.getHeight();
  cout << endl;
  t.deleteKey(3); cout << "Deleting vertex 3...\n";
  t.deleteKey(25); cout << "Deleting a vertex 25...\n";
  t.deleteKey(1); cout << "Deleting vertex 1...\n";
  t.print(cout);
  cout << endl;
  Tree<int> s = t; cout << "Copying the tree...\n";
  s.print(cout);

}
