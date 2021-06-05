#ifndef COURSEWORK_EXCEPTIONS_HPP
#define COURSEWORK_EXCEPTIONS_HPP

#include <exception>
#include <iostream>

class GraphEmpty : public std::exception
{
public:
  GraphEmpty() : reason_("Graph is empty") { }
  const char *what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  const std::string reason_;
};

class GraphDFCError : public std::exception
{
public:
  GraphDFCError() : reason_("Error in DFC function") { }
  const char *what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  const std::string reason_;
};

class StackOverFlow : public std::exception
{
public:
  StackOverFlow() : reason_("Stack Overflow") { }
  const char *what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  const std::string reason_;
};

class StackUnderFlow : public std::exception
{
public:
  StackUnderFlow() : reason_("Stack Underflow") { }
  const char *what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  const std::string reason_;
};

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() : reason_("Wrong stack size") { }
  const char *what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  const std::string reason_;
};

#endif