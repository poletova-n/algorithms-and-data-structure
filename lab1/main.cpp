#include <iostream>
#include "list.h"

int main()
{
    list firstlist;
    firstlist +=1;
    firstlist += 2;
    firstlist +=7;
    std::cout << "First list: " << firstlist << "\n";

    list secondlist;
    secondlist +=3;
    secondlist += 4;
    std::cout << "Second list: " << secondlist << "\n";

    secondlist += 1;

    std::cout << (firstlist == secondlist);
    list thirdlist(firstlist & secondlist);
    std::cout << thirdlist << std::endl;

    list fourthlist;
    fourthlist +=5;
   // std::cout << fourthlist << std::endl; // до мерджа
    fourthlist.merge(firstlist);
    std::cout << "merge " <<fourthlist << std::endl;
    return 0;
}
