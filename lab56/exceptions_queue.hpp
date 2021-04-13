#ifndef LAB56_EXCEPTIONS_QUEUE_HPP
#define LAB56_EXCEPTIONS_QUEUE_HPP
#include <exception>
#include <iostream>
#include <string>

class QueueOverflow : public std::exception {
public:
  QueueOverflow() : error_reason_("Queue Overflow"){}
  const char* reason() {
    return error_reason_.c_str();
  }
private:
  std::string error_reason_;
};

class QueueUnderflow : public std::exception {
public:
  QueueUnderflow() : error_reason_("Queue Underflow"){}
  const char* reason() {
    return error_reason_.c_str();
  }
private:
  std::string error_reason_;
};

class WrongQueueSize : public std::exception {
public:
  WrongQueueSize() : error_reason_("Wrong Size"){}
  const char* reason() {
    return error_reason_.c_str();
  }
private:
  std::string error_reason_;
};
#endif