#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class QueueOverflow : public std::exception
{
public:
  QueueOverflow() : reason("Queue Overflow") {}
  const char* what() const 
  { 
	return reason; 
  }
private:
  const char* reason; 
};

class QueueUnderflow : public std::exception
{
public:
  QueueUnderflow() : reason("Queue Underflow") {}
  const char* what() const 
  { 
	return reason; 
  }
private:
  const char* reason;
};

class WrongQueueSize : public std::exception
{
public:
  WrongQueueSize() : reason("Wrong Queue Size") {}
  const char* what() const 
  { 
	return reason; 
  }
private:
  const char* reason; 
};

class StackOverflow : public std::exception
{
public:
  StackOverflow() : reason("Stack Overflow") {}
  const char* what() const
  {
	return reason;
  }
private:
  const char* reason;
};

class StackUnderflow : public std::exception
{
public:
  StackUnderflow() : reason("Stack Underflow") {}
  const char* what() const
  {
	return reason;
  }
private:
  const char* reason;
};

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() : reason("Wrong Stack Size") {}
  const char* what() const
  {
	return reason;
  }
private:
  const char* reason;
};

#endif 
