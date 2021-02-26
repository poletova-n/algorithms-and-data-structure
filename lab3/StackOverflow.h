#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H

#include <exception> 

class StackOverflow : public std::exception
{
public:
  StackOverflow() : error_("Stack Overflow") {};
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};
#endif