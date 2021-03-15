#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <iostream>

class StackOverflow : public std::exception {
public:
  StackOverflow() : error_reason_("Stack Overflow"){}
  const char* reason() {
    return error_reason_.c_str();
  }
private:
  std::string error_reason_;
};

class StackUnderflow : public std::exception {
public:
  StackUnderflow() : error_reason_("Stack Underflow") {}
  const char* reason() {
    return error_reason_.c_str();
  }
private:
  std::string error_reason_;
};

class WrongStackSize : public std::exception {
public:
  WrongStackSize() : error_reason_("Wrong stack size") {}
  const char* reason() {
    return error_reason_.c_str();
  }
private:
  std::string error_reason_;
};








#endif