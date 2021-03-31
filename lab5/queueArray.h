#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>

#include "myException.h"
#include "queue.h"

template<class T>
class QueueArray : public Queue<T>
{
private:
	T* array_;
	size_t size_;
	size_t tail_ =0;
public:
	QueueArray(size_t);
	QueueArray(const QueueArray<T>&);
	QueueArray(QueueArray<T>&&) noexcept;
	~QueueArray();
	QueueArray<T>& operator=(const QueueArray<T>&) = delete;
	QueueArray<T>& operator=(QueueArray<T>&&) noexcept;
	void enQueue(const T&) override;
	T deQueue() override;
	T& getHead();
	bool isEmpty() override;
};

template<class T>
QueueArray<T>::QueueArray(size_t size):
	tail_(0)
{
	if (size == 0 || size >= 10000)
	{
		size_ = 0;
		array_ = nullptr;
		throw WrongQueueSize();
	}
	array_ = new T[size];
	size_ = size;
}

template<class T>
QueueArray<T>::QueueArray(const QueueArray<T>& arr)
{
	array_ = new T[arr.size_];
	size_ = arr.size_;
	tail_ = arr.tail_;
	for (size_t i = 0; i < arr.tail_; i++)
	{
		array_[i] = arr[i];
	}
}

template<class T>
QueueArray<T>::QueueArray(QueueArray<T>&& arr) noexcept
{
	array_ = new T[arr.size_];
	size_ = arr.size_;
	tail_ = arr.tail_;
	for (size_t i = 0; i < arr.tail_; i++)
	{
		array_[i] = arr[i];
	}
	arr.size_ = 0;
	arr.tail_ = 0;
}

template<class T>
QueueArray<T>::~QueueArray()
{
	delete[] array_;
}

template<class T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& arr) noexcept
{
	if (this == &arr)
	{
		return *this;
	}
	if (size_ != arr.size_)
	{
		array_ = new T[arr.size_];
		size_ = arr.size_;
	}
	for (size_t i = 0; i < arr.size_; i++)
	{
		array_[i] = arr.array_[i];
	}
	tail_ = arr.tail_;
	arr.size_ = 0;
	arr.tail_ = 0;
	return *this;
}

template<class T>
void QueueArray<T>::enQueue(const T& data)
{
	if (array_ == nullptr)
	{
		throw WrongQueueSize();
	}
	if (tail_ == size_)
	{
		throw QueueOverflow();
	}
	else
	{
		array_[++tail_ - 1] = data;
	}
}

template<class T>
T QueueArray<T>::deQueue()
{
	if (array_ == nullptr)
	{
		throw WrongQueueSize();
	}
	if (tail_ == 0)
	{
		throw QueueUnderflow();
	}
	else
	{
		T temp = array_[0];
		for (size_t i = 0; i < tail_ - 1; i++)
		{
			array_[i] = array_[i + 1];
		}
		--tail_;
		return temp;
	}
}

template<class T>
T& QueueArray<T>::getHead()
{
	if (array_ == nullptr)
	{
		throw WrongQueueSize();
	}
	return array_[0];
}

template<class T>
bool QueueArray<T>::isEmpty()
{
	if (array_ == nullptr)
	{
		throw WrongQueueSize();
	}
	return tail_ == 0;
}

#endif
