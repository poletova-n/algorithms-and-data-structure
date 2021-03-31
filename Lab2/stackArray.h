#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>
#include "myException.h"

template <class T>
class StackArray
{
public:
	StackArray(size_t);
	StackArray(const StackArray<T>&);
	StackArray(StackArray<T>&&);
	~StackArray()
	{
		delete[] array_;
	}

	StackArray<T>& operator=(const StackArray<T>& src) = delete;
	StackArray<T>& operator=(StackArray<T>&& src);
	void push(const T& c);
	T pop();
	bool isEmpty();
private:
	T* array_;
	size_t top_;
	size_t size_;
};

template<class T>
StackArray<T>::StackArray(size_t size):
	top_(0)
{
	try
	{
		if (size == 0 || size >= 10000)
		{
			throw WrongStackSize();
		}
		array_ = new T[size];
		size_ = size;
	}
	catch (WrongStackSize& exp)
	{
		std::cout << exp.what() << '\n';
		exit(0);
	}
}

template<class T>
StackArray<T>::StackArray(const StackArray<T>& src)
{
	array_ = new T[src.size_];
	top_ = src.top_;
	size_ = src.size_;
	for (size_t i = 0; i <= src.top_; ++i)
	{
		array_[i] = src.array_[i];
	}
}


template<class T>
StackArray<T>::StackArray(StackArray<T>&& src)
{
	array_ = new T[src.size_];
	size_ = src.size_;
	top_ = src.top_;
	for (size_t i = 0; i <= src.top_; ++i)
	{
		array_[i] = src.array_[i];
	}
	src.top_ = 0;
	src.size_ = 0;
}

template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
	if (this == &src)
	{
		return *this;
	}
	if (size_ != src.size_)
	{
		array_ = new T[src.size_];
		size_ = src.size_;
		top_ = src.top_;
	}
	for (size_t i = 0; i <= src.top_; ++i)
	{
		array_[i] = src.array_[i];
	}
	src.top_ = 0;
	src.size_ = 0;
	return *this;
}
template <class T>
void StackArray<T>::push(const T& c)
{
	if (top_ == size_)
	{
		throw StackOverflow();
	}
	else
	{
		array_[++top_ - 1] = c;
	}
}
template <class T>
T StackArray<T>::pop()
{
	if (top_ == 0)
	{
		throw StackUnderflow();
	}
	else
	{
		return array_[--top_];
	}
}

template <class T>
bool StackArray<T>::isEmpty()
{
	return(top_ == 0);
}

#endif 
