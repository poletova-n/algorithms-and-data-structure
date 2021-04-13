#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <iostream>

class StackOverFlow : public std::exception
{
public:
  StackOverFlow() :
    reason_("Stack OverFlow")
  {}
  const std::string &what()
  {
    return reason_;
  }
private:
  const std::string reason_;
};

class StackUnderFlow : public std::exception
{
public:
  StackUnderFlow() :
    reason_("Stack UnderFlow")
  {}
  const std::string &what()
  {
    return reason_;
  }
private:
  const std::string reason_;
};

class StackWrongSize : public std::exception
{
public:
  StackWrongSize() :
    reason_("Stack WrongSize")
  {}
  const std::string &what()
  {
    return reason_;
  }
private:
  const std::string reason_;
};

#endif