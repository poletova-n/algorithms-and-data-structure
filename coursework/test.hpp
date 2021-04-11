#ifndef COURSEWORK_TEST_HPP
#define COURSEWORK_TEST_HPP
#include <stdexcept>
#include <string>
#include "AVLTree.hpp"

void testAddWithValidArguments()
{
    std::cout << "Test for method Add with valid arguments" << std::endl;
    AVLTree dictionary;
    dictionary.add("acceptable - приемлемый");
    std::cout << "Add:\n(acceptable - приемлемый)" << std::endl;
    dictionary.add("allowance - позволение, разрешение, паек");
    std::cout << "(allowance - позволение, разрешение, паек)" << std::endl;
    dictionary.add("aback - захваченный врасплох");
    std::cout << "(aback - захваченный врасплох)" << std::endl;
    dictionary.add("vortex - вихрь, водоворот");
    std::cout << "(vortex - вихрь, водоворот)" << std::endl;
    dictionary.add("crescent - полумесяц, серповидный, нарастающий");
    std::cout << "(crescent - полумесяц, серповидный, нарастающий)" << std::endl;
    dictionary.add("chancellor - канцлер, ректор университета");
    std::cout << "(chancellor - канцлер, ректор университета)" << std::endl;
    dictionary.add("camera - фотоаппарат, кинокамера");
    std::cout << "(camera - фотоаппарат, кинокамера)" <<std::endl;
    dictionary.add("azure - голубой, лазурь, небо");
    std::cout << "(azure - голубой, лазурь, небо)" << std::endl;
    dictionary.add("educator - педагог");
    std::cout << "(educator - педагог)" << std::endl;
    std::cout << "This dictionary:" << std::endl;
    dictionary.print(std::cout);
}

void testAddWithInvalidKey()
{
    try {
        std::cout << "Test for method Add with invalid key:" << std::endl;
        AVLTree dictionary;
        std::cout << "Add:(champ*on - чемпион, первоклассный)" << std::endl;
        dictionary.add("champ*on - чемпион, первоклассный");
    } catch(const SyntaxError& err)
    {
        std::cout << err.what();
    }
}

void testAddWithInvalidTranslation()
{
    try {
        std::cout << "Test for method Add with invalid translation" << std::endl;
        AVLTree dictionary;
        std::cout << "Add: (chaplet - венок, б&&усы)" << std::endl;
        dictionary.add("chaplet - венок, б&&усы");
    } catch(const SyntaxError& err)
    {
        std::cout << err.what();
    }
}

void testForEmptyDictionary()
{
    try {
        std::cout << "Test for empty dictionary" << std::endl;
        AVLTree dictionary;
        dictionary.search("");
    } catch(const EmptyDictionary& err)
    {
        std::cout << err.what();
    }
}

void testSearchWithNotAddedArgument()
{
    try {
        std::cout << "Test for method search with not added argument" << std::endl;
        AVLTree dictionary;
        dictionary.add("cloak - плащ, покров, скрывать");
        std::cout << "Add:(cloak - плащ, покров, скрывать)" << std::endl;
        std::cout << "Search word: (chiefly)" << std::endl;
        if (!dictionary.search("chiefly")) {
            throw WordIsNotFound("chiefly");
        }
    } catch(const WordIsNotFound& err)
    {
        std::cout << err.what();
    }

}

void testRemoveFromEmptyTree()
{
    try {
        std::cout << "Test method remove from empty tree" << std::endl;
        AVLTree dictionary;
        dictionary.remove("");
    } catch (const EmptyDictionary& err)
    {
        std::cout << err.what();
    }
}

void testRemoveToNotAddedArguments()
{
    try {
        std::cout << "Test method remove to not added arguments" << std::endl;
        AVLTree dictionary;
        dictionary.add("circumspect - осторожный, осмотрительный");
        std::cout << "Add:(circumspect - осторожный, осмотрительный)" << std::endl;
        std::cout << "Remove word: (element)" << std::endl;
        dictionary.remove("element");
    } catch (const WordIsNotFound& err)
    {
        std::cout << err.what();
    }
}

void testRemoveToValidArguments()
{
    try {
        std::cout << "Test method remove to valid arguments" << std::endl;
        AVLTree dictionary;
        dictionary.add("clemency - милосердие, мягкость");
        std::cout << "Add: (clemency - милосердие, мягкость)" << std::endl;
        dictionary.add("clinical - клинический");
        std::cout << "(clinical - клинический)" << std::endl;
        dictionary.remove("clemency");
        std::cout << "Remove word: clemency" << std::endl;
        std::cout << "Try to search word: clemency" << std::endl;
        if (!dictionary.search("clemency")) {
            throw WordIsNotFound("clemency");
        }
    } catch (const WordIsNotFound& err)
    {
        std::cout << err.what();
    }
}
#endif