#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <exception>

class QueueOverflow: public std::exception
{
public:
  QueueOverflow() : reason_("Queue Overflow")
  {}

  const char* what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  std::string reason_;
};

class QueueUnderflow: public std::exception
{
public:
  QueueUnderflow() : reason_("Queue Underflow")
  {}

  const char* what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  std::string reason_;
};

class WrongQueueSize: public std::exception
{
public:
  WrongQueueSize() : reason_("Wrong queue size")
  {}

  const char* what() const noexcept override
  {
    return reason_.c_str();
  }

private:
  std::string reason_;
};
class StackOverflow : public std::exception
{
public:
  StackOverflow() = default;
  const std::string& problem() const { return reason_; }
private:
  const std::string reason_ = "Stack Overflow";
};
class StackUnderflow : public std::exception
{
public:
  StackUnderflow()  = default;
  const std::string& problem() const { return reason_; }
private:
  const std::string& reason_ = "Stack Underflow";
};
class WrongStackSize : public std::exception
{
public:
  WrongStackSize() = default;
  const std::string& problem() const { return reason_; }
private:
  const std::string& reason_ = "Wrong stack size";
};

#endif