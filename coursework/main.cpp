#include <iostream>

#include "tree.hpp"

int main()
{
  Tree dictionary;
  try
  {
    //dictionary.insert("incorrect2938", "jjk, sgjdh");
    //dictionary.insert("incorrect", "378, -=00--02");
    //dictionary.insert("incorrect", "");
    //dictionary.remove("incorrect");

    dictionary.insert("beautiful", "pretty, elegant");
    dictionary.insert("help", "Promote, assist");
    dictionary.insert("Run", "sprint, jog");
    dictionary.insert("big", "giant, huge");
    dictionary.print(std::cout);

    if (dictionary.search("big"))
    {
      std::cout << "Dictionary contains word big\n";
    }
    else
    {
      std::cout << "Dictionary not contains word big\n";
    }
    if (dictionary.search("small"))
    {
      std::cout << "Dictionary contains word small\n";
    }
    else
    {
      std::cout << "Dictionary not contains word small\n";
    }

    dictionary.remove("run");
    std::cout << "Dictionary after delete element\n";
    dictionary.print(std::cout);
    if (dictionary.search("run"))
    {
      std::cout << "Dictionary contains word run\n";
    }
    else
    {
      std::cout << "Dictionary not contains word run\n";
    }
  }
  catch (const std::invalid_argument &error)
  {
    std::cerr << error.what();
    return 1;
  }
  catch (const std::runtime_error &error)
  {
    std::cerr << error.what();
    return 1;
  }

  return 0;
}
