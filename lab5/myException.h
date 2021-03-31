#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>

class QueueUnderflow : public std::exception
{
public:
	QueueUnderflow():
		reason_("Queue underflow.")
	{}
	const char* what()
	{
		return reason_;
	}
private:
	const char* reason_;
};


class QueueOverflow : public std::exception
{
public:
	QueueOverflow():
		reason_("Queue overflow.")
	{}
	const char* what()
	{
		return reason_;
	}
private:
	const char* reason_;
};

class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() :
		reason_("Wrong queue size.")
	{}
	const char* what()
	{
		return reason_;
	}
private:
	const char* reason_;
};


class StackOverflow :public std::exception
{
public:
	StackOverflow()
	{
		reason_ = "Stack overflow.";
	}
	const char* what()
	{
		return reason_;
	}
private:
	const char* reason_;
};

class StackUnderflow :public std::exception
{
private:
	const char* reason_;
public:
	StackUnderflow()
	{
		reason_ = "Stack underflow.";
	}
	const char* what()
	{
		return reason_;
	}
};

class WrongStackSize :public std::exception
{
private:
	const char* reason_;
public:
	WrongStackSize()
	{
		reason_ = "Wrong stack size.";
	}
	const char* what()
	{
		return reason_;
	}
};


#endif
