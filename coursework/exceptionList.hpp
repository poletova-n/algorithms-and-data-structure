#ifndef EXCEPTIONLIST_HPP
#define EXCEPTIONLIST_HPP

#include <exception>
#include <iostream>

class ListUnderflow
  : public std::exception
{
  public:
  ListUnderflow() : reason_("List Underflow")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};

class ListWrongNode
  : public std::exception
{
  public:
  ListWrongNode() : reason_("Invalid address of the node being deleted")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};
#endif
