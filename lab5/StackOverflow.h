#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H

#include <exception>

class StackOverflow :public std::exception
{
public:
  StackOverflow():reason("Stack Overflow") {}
  const char* what() { return reason; }
private:
  const char* reason;
};
#endif
