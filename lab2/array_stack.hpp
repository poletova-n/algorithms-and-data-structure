#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "exceptions.hpp"
#include "stack.hpp"

template<class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 5);
	~StackArray() override;
	void push(const T& arg) override;
	T pop() override;
	T get_top();
	bool is_empty() override;

private:
	int top_;
	int size_;
	T* array_;
};

template<class T>
StackArray<T>::StackArray(int size)
{
	if (size <= 0) {
		throw WrongStackSize();
	}
		array_ = new T[size + 1];
		top_ = 0;
		size_ = size;
}

template<class T>
StackArray<T>::~StackArray()
{
	delete[] array_;
}

template<class T>
void StackArray<T>::push(const T& arg) {
	if (top_ == size_ + 1) {
		throw StackOverflow();
	}
		top_++;
		array_[top_] = arg;
}

template<class T>
T StackArray<T>::pop(){
	if (top_ == 0){
		throw StackUnderflow();
	}
	T temp = array_[top_];
	top_--;
	return temp;
}

template <class T>
bool StackArray<T>::is_empty() {
	if (top_ == 0) {
		return true;
	}
	else {
		return false;
	}
}

 template <class T>
 T StackArray<T>::get_top() {
	 return array_[top_];
}

#endif