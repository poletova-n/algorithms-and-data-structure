#ifndef RB_TREE
#define	RB_TREE
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <string>

using std::string;
//true = red, false = black
class RBtree {
  struct node { node* l, * r; string value; string ss; bool color; };
  node* tree_root;
  int nodes_count;
public:
  RBtree();
  ~RBtree();
  void Insert(string, string);
  void Delete(string);
  int GetNodesCount() const;
  void Show();
  void ShowTree();
  void Clean();
  bool Search(const string &);
private:
  node* NewNode(string value, string ss);
  void DelNode(node*);
  void Clean(node*);
  node* RotateL(node*);
  node* RotateR(node*);
  void BalanceInsert(node**);
  bool BalanceDeleteL(node**);
  bool BalanceDeleteR(node**);
  bool Insert(string, string, node**);
  void Show(node*);
  void ShowTree(node*, int, char);
  bool Delete(node**,string &);
  bool GetMin(node**, node**); //find and remove the maximum node of the subtree
};
#endif
