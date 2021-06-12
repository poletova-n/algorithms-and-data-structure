#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>

std::string NeedlemanWunsch(const std::string& firstString, const std::string& secondString);
std::string Hirschberg(const std::string& firstString, const std::string& secondString);

int* getMatrixLastRow(const std::string& firstString, const std::string& secondString);
std::string reverseString(const std::string& src);

#endif
