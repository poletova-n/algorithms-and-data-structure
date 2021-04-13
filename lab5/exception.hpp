#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include<exception>

class QueueOverFlow : public std::exception
{
public:
	QueueOverFlow() : reason("QueueOverflow") {}
	const char* what() const { return reason; }

private:
	const char* reason;
};

class QueueUnderFlow : public std::exception
{
public:
	QueueUnderFlow() : reason("QueueUnderflow") {}
	const char* what() const { return reason; }

private:
	const char* reason;
};

class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() : reason("WrongQueueSize") {}
	const char* what() const { return reason; }

private:
	const char* reason;
};
#endif
