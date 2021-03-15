#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>

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

class StackOverFlow: public std::exception
{
public:
	StackOverFlow() : reason_("Stack Overflow")
	{}

	const char* what() const noexcept override
	{
		return reason_.c_str();
	}

private:
	std::string reason_;
};

class StackUnderFlow: public std::exception
{
public:
	StackUnderFlow() : reason_("Stack Underflow")
	{}

	const char* what() const noexcept override
	{
		return reason_.c_str();
	}

private:
	std::string reason_;
};

class StackWrongSize: public std::exception
{
public:
	StackWrongSize() : reason_("Stack wrong size")
	{}

	const char* what() const noexcept override
	{
		return reason_.c_str();
	}

private:
	std::string reason_;
};

#endif