#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include "exception.h"
#include "stack.h"

template <class T>
class StackArray : public Stack<T> {
public:
	StackArray(const StackArray<T>& src) = delete;
	StackArray(int size);
	StackArray(StackArray<T>&& src);
	StackArray& operator=(const StackArray<T>& src) = delete;
	StackArray& operator=(StackArray<T>&& src);
	virtual ~StackArray();
	void push(const T& e);
	T pop();
	bool isEmpty();
	void printAll();
	T getTop();
	size_t getSize();
private:
	T* array_; // массив элементов стека: !!! array_[0] – не используется, top_ от 1 до size_
	size_t top_; // вершина стека, элемент занесенный в стек последним
	size_t size_; // размер стека
	void swap(StackArray<T>& src);
};


template<class T>
StackArray<T>::StackArray(int size)
{
	if (size <= 0)
	{
		throw WrongStackSize();
	}
	else
	{
		array_ = new T[size + 1];
		top_ = 0;
		size_ = size;
	}
}

template <typename T>
StackArray<T>::StackArray(StackArray<T>&& src)
{
	array_ = src.array_;
	top_ = src.top_;
	size_ = src.size_;
	src.array_ = nullptr;
	src.top_ = 0;
	src.size_ = 0;
}

template <typename T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
	array_ = nullptr;
	top_ = 0;
	size_ = 0;
	array_ = src.array_;
	top_ = src.top_;
	size_ = src.size_;
	src.array_ = nullptr;
	src.top_ = 0;
	src.size_ = 0;
	return *this;
}

template<class T>
StackArray<T>::~StackArray()
{
	delete[] array_;
}

template<class T>
void StackArray<T>::push(const T& e)
{
	
	top_ = top_+1;
	array_[top_] = e;
	if (top_ > size_)
	{
		throw StackOverflow();
	}
}

template<class T>
T StackArray<T>::pop()
{
	if (top_ < 1)
	{
		throw StackUnderflow();
	}
	return array_[top_--];

}

template<class T>
bool StackArray<T>::isEmpty()
{
	if (top_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void StackArray<T>::swap(StackArray<T>& src)
{
	std::swap(array_, src.array_); 
	std::swap(top_, src.top_);
	std::swap(size_, src.size_);
}

template<class T>
size_t StackArray<T>::getSize()
{
	return this->top_;
}

template<class T>
T StackArray<T>::getTop()
{
	return array_[top_];
}
#endif