#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include "rb-tree.h"
int main()
{
	std::ifstream file("D:\\games\\algorithms-and-data-structure\\coursework\\input2.txt");
  //std::ifstream file("D:\\games\\algorithms-and-data-structure\\coursework\\input1.txt");
  //std::ifstream file("D:\\games\\algorithms-and-data-structure\\coursework\\input.txt");
	if (!file)
	{
		std::cerr << "File isn't open\n\n";
		return -1;
	}
	std::vector<std::string> strings;
  std::vector<std::string> strings1;
	while (!file.eof()) {
    std::string s;
    std::getline(file, s);
        strings.push_back(s);
        for (int i = 0; i < s.size(); i++) {
        if ((s[i] == '.') || (s[i] == ',') || (s[i] == ';') || (s[i] >=48 && s[i] <=57 ))
        {
          s.erase(i, 1);
          i-=1;
        }
        if (std::isupper(s[i]))
          s[i] = std::tolower(s[i]);
      }
      strings1.push_back(s);
    }
  file.close();
	for (unsigned i = 0; i < strings.size(); i++)
	{
		std::cout << i + 1 << ' ' << strings[i] << '\n';
	}
	std::cout << "--------------------------------\n";
	RBtree tree;
	for (unsigned i = 0; i < strings1.size(); i++)
	{
		std::istringstream ss{ strings1[i] };
		while (!ss.eof())
		{
			std::string s;
			ss >> s;
			string temps;
			temps += std::to_string(i + 1);
			tree.Insert(s, temps);
		}
	}
	tree.Show();
	tree.ShowTree();
	tree.Delete("i");
  std::cout<<"Tree after deleting i: \n";
  tree.Show();
 // tree.ShowTree();
	tree.Clean();
	std::cout<<"Tree after clean: \n";
	tree.Show();
	std::cout<<"nodes count: "<<tree.GetNodesCount();
	RBtree tree1;
	tree1.Clean();
	tree1.ShowTree();
	tree1.Delete("h");
	strings.clear();
	strings1.clear();
	return 0;
}
