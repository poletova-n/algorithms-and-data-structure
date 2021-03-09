#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <iostream>
#include <stdexcept>

template<class T>
class StackArray
{
public:
	StackArray(int);
	StackArray(const StackArray<T>&) = delete;
	StackArray(StackArray<T>&&) = delete;
	~StackArray();
	StackArray& operator=(const StackArray&) = delete;
	StackArray& operator=(StackArray&&) = delete;
	T getTop();
	T pop();
	void push(const T&);
	bool isEmpty();
	int lengthStack();
private:
	T* array_;
	int size_;
	int top_;
};

template<class T>
StackArray<T>::StackArray(int size) :
	size_(size),
	top_(-1)
{
	if (size <= 0)
	{
		throw std::invalid_argument("Array stack size must be faulty.");
	}
	try
	{
		array_ = new T[size];
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << '\n';
	}
}
template<class T>
StackArray<T>::~StackArray()
{
	delete array_;
}
template<class T>
T StackArray<T>::getTop()
{
	if (top_ < 0)
	{
		throw std::out_of_range("The stack is empty.");
	}
	return array_[top_];
}
template<class T>
T StackArray<T>::pop()
{
	if (top_ < 0)
	{
		throw std::out_of_range("The stack is empty.");
	}
	return array_[top_--];
}
template<class T>
void StackArray<T>::push(const T& data)
{
	if (top_ >= (size_ - 1))
	{
		throw std::overflow_error("Stack overflow.");

	}
	array_[++top_] = data;
}

template<class T>
bool StackArray<T>::isEmpty()
{
	return top_ == -1;
}
template<class T>
int StackArray<T>::lengthStack()
{
	return top_ + 1;
}

#endif