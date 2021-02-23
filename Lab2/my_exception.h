#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include<string>
#include<exception>

class StackOverflow :public std::exception
{
public:
	StackOverflow()
	{
		reason_ = "Stack overflow.";
	}
	std::string what();
private:
	std::string reason_;
};

class StackUnderflow :public std::exception
{
private:
	std::string reason_;
public:
	StackUnderflow()
	{
		reason_ = "Stack underflow.";
	}
	std::string what();
};

class WrongStackSize :public std::exception
{
private:
	std::string reason_;
public:
	WrongStackSize()
	{
		reason_ = "Wrong stack size.";
	}
	std::string what();
};

#endif 
