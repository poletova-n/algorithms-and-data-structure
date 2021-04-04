#ifndef STACK_ARRAY
#define STACK_ARRAY

#include "Stack.h"

template <typename T>
class StackArray : public Stack<T>
{
public:
	StackArray(size_t = 100);
	StackArray(const StackArray<T>& src) = delete;
	StackArray(StackArray<T>&& src);
	StackArray& operator=(const StackArray<T>& src) = delete;
	StackArray& operator=(StackArray<T>&& src);
	void push(const T& e) override;
	T pop() override;
	bool isEmpty() const override;
	void print() override;
	~StackArray();
private:
	T* array_;
	size_t top_;
	size_t size_;

};

template<typename T>
StackArray<T>::StackArray(size_t size) :
	size_(size),
	top_(0)
{
	try {
		array_ = new T[size + 1];
	}
	catch (...) {
		throw Stack<T>::WrongStackSize();
	}
}

template<class T>
StackArray<T>::StackArray(StackArray<T>&& src) :
	array_(src.array_),
	size_(src.size_),
	top_(src.top_)
{
	src.size_ = 0;
	src.top_ = 0;
	array_ = nullptr;
}

template<class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
	array_(src.array_);
	size_(src.size_);
	top_(src.top_);
	src.size_ = 0;
	src.top_ = 0;
	array_ = nullptr;
	return *this;
}

template <class T>
void StackArray<T>::push(const T& e)
{
	if (top_ == size_)
	{
		throw Stack<T>::StackOverflow();
	}
	array_[++top_] = e;
}

template<typename T>
T StackArray<T>::pop()
{
	if (top_ == 0) {
		throw Stack<T>::StackUnderflow();
	}
	return array_[top_--];
}

template <typename T>
bool StackArray<T>::isEmpty() const
{
	return top_ == 0;
}

template <typename T>
StackArray<T>::~StackArray()
{
	delete[] array_;
}

template <typename T>
void StackArray<T>::print()
{
	while (!isEmpty()) {
		std::cout << pop() << ' ';
	}
}


#endif