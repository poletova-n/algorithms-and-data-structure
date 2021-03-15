#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack
{
public:
	virtual ~Stack() {};
	virtual void push(const T& rhs) = 0;
	virtual const T& pop() = 0;
	virtual bool isEmpty() = 0;
};
#endif