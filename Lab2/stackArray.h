#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include<iostream>
#include"my_exception.h"
#include"stack.h"

template <class T>
class StackArray :public Stack<T>
{
public:
	StackArray(size_t size) :
		top_(-1),
		size_(size)
	{
		try
		{
			if (size_ <= 0 || size_ >= 10000)
			{
				throw WrongStackSize();
			}
			array_ = new T[size_];
		}
		catch (WrongStackSize& exp)
		{
			std::cout << exp.what() << '\n';
			exit(0);
		}
	}
	StackArray(const StackArray& src) :
		top_(src.top_),
		size_(src.size_)
	{
		try
		{
			if (size_ <= 0 || size_ >= 10000)
			{
				throw WrongStackSize();
			}
			array_ = new T[size_];
		}
		catch (WrongStackSize& exp)
		{
			std::cout << exp.what() << '\n';
			exit(0);
		}
		for (size_t i = 0; i <= src.top_; ++i)
		{
			array_[i] = src.array_[i];
		}
	}
	StackArray(const StackArray&& src) :
		top_(src.top_),
		size_(src.size_)
	{
		try
		{
			if (size_ <= 0 || size_ >= 10000)
			{
				throw WrongStackSize();
			}
			array_ = new T[size_];
		}
		catch (WrongStackSize& exp)
		{
			std::cout << exp.what() << '\n';
			exit(0);
		}
		for (size_t i = 0; i <= src.top_; ++i)
		{
			array_[i] = src.array_[i];
		}
		src.top_ = 0;
		src.size_ = 0;
		delete[] src.array_;
	}
	~StackArray()
	{
		delete[] array_;
	}
	StackArray<T>& operator=(const StackArray<T>& src);
	StackArray<T>& operator=(StackArray<T>&& src);
	void push(const T& c) override;
	T pop() override;
	bool isEmpty() override;
private:
	T* array_;
	size_t top_;
	size_t size_;
};

template <class T>
StackArray<T>& StackArray<T>::operator=(const StackArray<T>& src)
{
	top_ = src.top_;
	if (size_ != src.size_)
	{
		size_ = src.size_;
		try
		{
			if (size_ <= 0 || size_ >= 10000)
			{
				throw WrongStackSize();
			}
			array_ = new T[size_];
		}
		catch (WrongStackSize& exp)
		{
			std::cout << exp.what() << '\n';
			exit(0);
		}
	}
	for (size_t i = 0; i <= src.top_; ++i)
	{
		array_[i] = src.array_[i];
	}
}
template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
	top_ = src.top_;
	if (size_ != src.size_)
	{
		size_ = src.size_;
		try
		{
			if (size_ <= 0 || size_ >= 10000)
			{
				throw WrongStackSize();
			}
			array_ = new T[size_];
		}
		catch (WrongStackSize& exp)
		{
			std::cout << exp.what() << '\n';
			exit(0);
		}
	}
	for (size_t i = 0; i <= src.top_; ++i)
	{
		array_[i] = src.array_[i];
	}
	src.top_ = 0;
	src.size_ = 0;
	delete[] src.array_;
}
template <class T>
void StackArray<T>::push(const T& c)
{
	if (top_ == size_ - 1)
	{
		throw StackOverflow();
	}
	else
	{
		array_[++top_] = c;
	}
}
template <class T>
T StackArray<T>::pop()
{
	if (top_ == -1)
	{
		throw StackUnderflow();
	}
	else
	{
		return array_[top_--];
	}
}

template <class T>
bool StackArray<T>::isEmpty()
{
	return(top_ == -1);
}

#endif 