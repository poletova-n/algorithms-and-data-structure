#include <cstdio>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "rb-tree.h"

// Rules for red-black tree:

// 1. Root is always black
// 2. Every node has one color - red or black and always has two children
// 3. All lists (node without childs) hasn't info and are black
// 4. All childs of red node is black
// 5. All ways from root or non-list node to lists contains equal amount of black nodes

RBtree::RBtree()
{
	tree_root=nullptr;
	nodes_count=0;
}

RBtree::~RBtree()
{
	Clean(tree_root);
}

RBtree::node *RBtree::NewNode(string value, string ss)
{
	nodes_count++;
	node *node=new struct node;
	node->value=value;
	node->ss = ss;
	node->l=node->r=nullptr;
	node->color=true;
	return node;
}

void RBtree::DelNode(node *node)
{
	nodes_count--;
	delete node;
}
void RBtree::Clean(node *node)
{
	if(!node) return;
	Clean(node->l);
	Clean(node->r);
	DelNode(node);
}

void RBtree::Clean()
{
  if (tree_root == nullptr)
  std::cout<<"\nTree already clean\n";
  Clean(tree_root);
  tree_root=0;
}

void RBtree::Show(node *node)
{
	if(!node) return;
	Show(node->l);
	std::cout << std::setw(6)<<node->ss << " " << node->value << "\n";
	Show(node->r);
}

void RBtree::ShowTree(node* node, int depth, char dir)
{
	int n;
	if (!node) return;
	for(n=0; n<depth; n++)
	  putchar(' ');
	std::cout << dir << " " << node->ss << " " << node->value << " ";
	if (node->color != 0) std::cout << "(red)\n";
	else std::cout << "(black)\n";
	ShowTree(node->l, depth + 2, '-');
	ShowTree(node->r, depth + 2, '+');
}
RBtree::node *RBtree::RotateL(node *node)
{
  RBtree::node *p2 =node->r;
  RBtree::node *p21=p2->l;
  p2->l=node;
  node->r=p21;
  return p2;
}

RBtree::node *RBtree::RotateR(node *node)
{
  RBtree::node *p1 =node->l;
  RBtree::node *p12=p1->r;
  p1->r=node;
  node->l=p12;
  return p1;
}

void RBtree::BalanceInsert(node **root)
{
  node *p1,*p2,*px1,*px2;
  node *node=*root;
  if(node->color)
    return;
  p1=node->l;
  p2=node->r;
  if (p1 && p1->color) {
    px2=p1->r;
    if(px2 && px2->color)
      p1=node->l=RotateL(p1);
    px1=p1->l;
    if(px1 && px1->color) {
      node->color=true;
      p1->color=false;
      if(p2 && p2->color) {
        px1->color=true;
        p2->color=false;
        return;
      }
      *root=RotateR(node);
      return;
    }
  }
  if(p2 && p2->color) {
    px1=p2->l;
    if(px1 && px1->color) p2=node->r=RotateR(p2);
    px2=p2->r;
    if(px2 && px2->color) {
      node->color=true;
      p2->color=false;
      if(p1 && p1->color) {
        px2->color=true;
        p1->color=false;
        return;
      }
      *root=RotateL(node);
      return;
    }
  }
}


bool RBtree::BalanceDeleteL(node **root)
{
  node *node=*root;
  RBtree::node *p1=node->l;
  RBtree::node *p2=node->r;
  if(p1 && p1->color) {
    p1->color=false;
    return false;
  }
  if(p2 && p2->color) {
    node->color=true;
    p2->color=false;
    node=*root=RotateL(node);
    if(BalanceDeleteL(&node->l))
      node->l->color=false;
    return false;
  }
  unsigned int mask=0;
  RBtree::node *p21=p2->l;
  RBtree::node *p22=p2->r;
  if(p21 && p21->color) mask|=1;
  if(p22 && p22->color) mask|=2;
  switch(mask)
  {
    case 0:
      p2->color=true;
      return true;
    case 3:
    case 1:
      p2->color=true;
      p21->color=false;
      p2=node->r=RotateR(p2);
      p22=p2->r;
    case 2:
      p2->color=node->color;
      p22->color=node->color=false;
      *root=RotateL(node);
  }
  return false;
}

bool RBtree::BalanceDeleteR(node **root)
{
  node *node=*root;
  RBtree::node *p1=node->l;
  RBtree::node *p2=node->r;
  if(p2 && p2->color)
  {
    p2->color=false;
    return false;
  }
  if(p1 && p1->color) {
    node->color=true;
    p1->color=false;
    node=*root=RotateR(node);
    if(BalanceDeleteR(&node->r)) node->r->color=false;
    return false;
  }
  unsigned int mask=0;
  RBtree::node *p11=p1->l;
  RBtree::node *p12=p1->r;
  if(p11 && p11->color) mask|=1;
  if(p12 && p12->color) mask|=2;
  switch(mask) {
      case 0:
      p1->color=true;
      return true;
      case 3:
      case 2:
      p1->color=true;
      p12->color=false;
      p1=node->l=RotateL(p1);
      p11=p1->l;
      case 1:
      p1->color=node->color;
      p11->color=node->color=false;
      *root=RotateR(node);
  }
  return false;
}
bool RBtree::Insert(string ss, string value, node **root)
{
	node *node=*root;
	if(!node) *root=NewNode(value, ss);
	else {
		if (ss == node->ss)
		{
			node->value += " ";
			node->value += value;
			return true;
		}
		if(Insert(ss, value, ss < node->ss ? &node->l: &node->r))
		  return true;
		BalanceInsert(root);
	}
	return false;
}
void RBtree::Show()
{
	if (tree_root == nullptr) {
   std::cout <<"Tree is empty to print\n";
  }
	Show(tree_root);
}

void RBtree::ShowTree()
{
  if (tree_root == nullptr) {
    std::cout <<"Tree is empty to show\n";
  }
	std::cout<<"[tree]\n";
	ShowTree(tree_root, 0, '*');
}

void RBtree::Insert(string ss, string value)
{
	if (value == "" && ss =="")
  {
    std::cout<<"You can't add an empty element!";
  }
	Insert(ss, value, &tree_root);
	if(tree_root)
	  tree_root->color = false;
}
int RBtree::GetNodesCount() const
{
  return nodes_count;
}

bool RBtree::GetMin(node **root,node **res)
{
  node *node = *root;
  if(node->l) {
    if (GetMin(&node->l,res))
      return BalanceDeleteL(root);
  } else {
    *root=node->r;
    *res=node;
    return !node->color;
  }
  return false;
}

void RBtree::Delete(string ss)
{
  if (!Search(ss))
  {
     std::cout <<"Such element doesn't exists\n";
  }
  if (!tree_root)
    std::cout<<"Tree is empty to delete something\n";
  Delete(&tree_root,ss);
}

bool RBtree::Delete(node **root, string & ss)
{
  node *t,*node = *root;
  if(!node) return false;
  if(node->ss < ss) {
    if(Delete(&node->r, ss))
      return BalanceDeleteR(root);
  } else if(node->ss > ss) {
    if (Delete(&node->l, ss))
      return BalanceDeleteL(root);
  } else {
    bool res;
    if(!node->r) {
      *root = node->l;
      res =! node->color;
    } else {
      res = GetMin(&node->r,root);
      t=*root;
      t->color=node->color;
      t->l=node->l;
      t->r=node->r;
      if (res)
        res = BalanceDeleteR(root);
    }
    DelNode(node);
    return res;
  }
  return false;
}
bool RBtree::Search(const  string &ss)
{
 if (tree_root == nullptr)
  {
    std::cout<<"Can’t search in empty tree";
  }
  node *node=tree_root;
  while(node) {
    if ((node->ss == ss))
      return true;
    node = node->ss > ss ? node->l : node->r;
  }
  return false;
}



