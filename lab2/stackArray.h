#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "exceptions.h"
#include "stack.h"

template <class T>
class StackArray :public Stack<T>
{
public:
	StackArray(size_t size = 10);
	~StackArray();
	void push(const T& element) override;
	T pop() override;
	bool isEmpty() override;
private:
	T* array_;
	size_t top_;
	size_t size_;
};

template<class T>
StackArray<T>::StackArray(size_t size)
{
	size_ = size;
	array_ = new T[size + 1];
	top_ = 0;
}

template<class T>
StackArray<T>::~StackArray()
{
	delete[] array_;
}

template<class T>
void StackArray<T>::push(const T& element)
{
	if (top_ == size_)
	{
		throw StackOverFlow();
	}
	top_ += 1;
	array_[top_] = element;
}

template<class T>
T StackArray<T>::pop()
{
	if (isEmpty())
	{
		throw StackUnderFlow();
	}
	T temp = array_[top_];
	array_[top_] = 0;
	top_ -= 1;
	return temp;
}

template<class T>
bool StackArray<T>::isEmpty()
{
	if (top_ == 0)
	{
		return true;
	}
	return false;
}

#endif