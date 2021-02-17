#include <iostream>
#include "List.h"
#include "doublelinkedlist.h"


int main() {
    std::cout << "Simply linked list : " << '\n' << std::endl;
    List firstList;
    firstList += 1;//test operator
    firstList += 3;//+=
    std::cout << "First List: " << firstList << std::endl;

    List secondList;
    secondList += 1;
    secondList += 2;//+=
    secondList += 4;//
    std::cout << "Second List: " << secondList << '\n' << std::endl;

    secondList += 1;

    std::cout << "Test ' == ' : " << (firstList == secondList) << std::endl;

    List Thirdlist(firstList & secondList);
    std::cout << "Test ' & ' : " << Thirdlist << std::endl;

    List Fourthlist(firstList | secondList);
    std::cout << "Test ' | ' : " << Fourthlist << std::endl;

    List lmt;
    lmt += 2;        //List
    lmt += 67;       //to
    lmt += 76;       //check
    lmt += 43;       //merge
    lmt.merge(firstList);
    std::cout << "Test ' merge ' : " << lmt << std::endl;

    //<------------------------------||------------------------------>

    std::cout << '\n' << "Doubly linked list : " << '\n' << std::endl;

    DoubleList firstlist;
    firstlist += 1;
    firstlist += 3;
    firstlist += 5;
    std::cout << "Firstlist: " << firstlist <<std::endl;

    DoubleList secondlist;
    secondlist +=2;
    secondlist +=4;
    secondlist +=6;
    std::cout << "Secondlist: " << secondlist << '\n' << std::endl;

    secondlist += 1;//add to the list to check &
    DoubleList thirdlist = firstlist & secondlist;
    std::cout << "Test ' & ' : " << thirdlist << std::endl;

    DoubleList sexthlist = firstlist | secondlist;
    std::cout << "Test ' | ' : " << sexthlist << std::endl;

    std::cout << "Test ' == ' : " << (firstlist==secondlist) << std::endl;

    DoubleList standartOil;     //list
    standartOil += 11;          //to
    standartOil += 33;          //check
    standartOil += 22;          //merge

    firstlist.merge(standartOil);
    std::cout << "Test ' merge ' : " << firstlist ;




    return 0;
}