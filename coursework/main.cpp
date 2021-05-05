#include "tests.hpp"

int main()
{
  //If you are user of Windows please uncomment the code below for correct work with Russian language
  //SetConsoleOutputCP(CP_UTF8);
  //SetConsoleCP(866);
  testDictionaryWithCorrectArguments();
  testDictionaryWithInvalidArguments();
  testSearch();
  testDelete();
  return 0;
}
