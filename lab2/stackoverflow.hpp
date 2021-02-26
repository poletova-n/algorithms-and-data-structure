#ifndef WORKING_STACKOVERFLOW_HPP
#define WORKING_STACKOVERFLOW_HPP

#include <exception>

class StackOverflow : public std::exception
{
public:
  StackOverflow():
    exceptionName("Stack Overflow!") {}
  const char* what() const noexcept override { return exceptionName; }

private:
  const char* exceptionName;
};

#endif
