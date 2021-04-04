#include <iostream>
#include "BinarySearchTree.h"
int main()
{
    BinarySearchTree<int> tre;

    tre.add_iter(5);
    tre.add_iter(4);
    tre.add_iter(6);
    tre.add_iter(7);
    tre.add_iter(8);
    tre.add_iter(15);
    tre.add_iter(10);
    tre.add_iter(27);
    tre.add_iter(20);
    tre.add_iter(16);
    tre.add_iter(17);
    tre.add_iter(11);

    tre.print_element(std::cout, 5);
    tre.print_element(std::cout, 15);

    std::cout << "element with key: " << 10 << " search status: " << tre.search(10) << "\n";

    std::cout << "------------------------------" << "\n"
              << "TRE: " << "\n"
              << "knots count: " << tre.get_count_knots() << "\n"
              << "height: " << tre.get_height() << "\n"
              << "------------------------------" << "\n";

    std::cout << "element with key: " << 8 << " search status: " << tre.search(8) << "\n";
    tre.remove(8);
    std::cout << "element with key: " << 8 << " search status: " << tre.search(8) << "\n";
    tre.print_element(std::cout, tre.search_next(6));
    tre.erase_tree();

}
