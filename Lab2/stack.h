#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
	virtual ~Stack<T>() {}
	virtual void push(const T&) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};

#endif 
