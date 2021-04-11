#include <iostream>
#include <windows.h>
#include "test.hpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(866);

    std::cout << "TESTS:" << std::endl;
    testAddWithInvalidKey();
    std::cout << std::endl;

    testAddWithInvalidTranslation();
    std::cout << std::endl;

    testForEmptyDictionary();
    std::cout << std::endl;

    testSearchWithNotAddedArgument();
    std::cout << std::endl;

    testAddWithValidArguments();
    std::cout << std::endl;

    testRemoveFromEmptyTree();
    std::cout << std::endl;

    testRemoveToNotAddedArguments();
    std::cout << std::endl;

    testRemoveToValidArguments();
    return 0;
}