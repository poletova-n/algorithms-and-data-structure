#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "stack.h"
#include "exception.h"

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray (int size = 100);
	StackArray (const StackArray<T>& src);
	virtual ~StackArray() 
	{ 
		delete[] array; 
	}
	void push(const T& element);
	const T& pop();
	bool isEmpty() 
	{ 
		return top == -1; 
	}
	const T& peek();
private:
	T* array; 
	int top = -1; 
	int size;
};

template <class T>
StackArray<T>::StackArray(int size) 
{
	try 
	{
		this->array = new T [this->size = size];
	}
	catch (...) 
	{
		throw WrongStackSize(); 
	}
	this->top = -1;
}

template <class T>
StackArray<T>::StackArray (const StackArray<T>& src) 
{
	try 
	{
		array = new T[size = src.size];
	}
	catch (...) 
	{
		throw WrongStackSize();
	}

	for (int i = 0; i < src.top; i++) {
		this->array[i] = src.array[i];
	}
	this->top = src.top;
}

template <class T>
void StackArray<T>::push(const T& element)
{
  if (top == size--)
  {
	throw StackOverflow();
  }
  top++;
  array[top] = element; 
}

template <class T>
const T& StackArray<T>::pop()
{
  if (top == -1)
  {
	throw StackUnderflow();
  }
  return array[top--]; 
}

template<class T>
const T& StackArray<T>::peek()
{
  if (top == -1)
  {
	throw StackUnderflow();
  }
  return array[top];
}

#endif