#ifndef QUEUE_ARRAY_HPP
#define QUEUE_ARRAY_HPP

#include "Queue.hpp"
#include "Exception.hpp"

template <typename T> 
class QueueArray final : public Queue<T>
{
public:
	QueueArray(size_t size);
	QueueArray(const QueueArray<T>& src) = delete;
	QueueArray(QueueArray<T>&& src) noexcept;
	QueueArray<T>& operator= (const QueueArray<T>& src) = delete;
	QueueArray<T>& operator= (QueueArray<T>&& src) noexcept;
	virtual ~QueueArray() override { delete[] array_; }
	void enQueue(const T& e) override;
	T deQueue() override;
	bool isEmpty() const override { return head_ == tail_; }
	void printQueue(std::ostream&);
private: 
	T* array_;
	size_t head_ = -1;
	size_t tail_ = -1;
	size_t size_;
	void swap(QueueArray<T>&);
};

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
	std::swap(*this, right.head_);
	std::swap(*this, right.tail_);
	std::swap(*this, right.size_);
	std::swap(*this, right.array_);
}

template <typename T>
QueueArray<T>::QueueArray(size_t size) 
{
	size_ = size;
	head_ = -1;
	tail_ = -1;
	try {
		array_ = new T[size + 1]; 
	}
	catch (...) { 
		throw WrongQueueSize(); 
	}
}

template <typename T>
QueueArray<T>::QueueArray<T>(QueueArray<T>&& src) noexcept:
	size_(src.size_),
	head_(src.head_),
	tail_(src.tail_),
	array_(std::move(src.array_))
{
	src.size_ = 0;
	src.head_ = -1;
	src.tail_ = -1;
	src.array_ = nullptr;
}

template <typename T>
QueueArray<T>& QueueArray<T>:: operator=(QueueArray&& src) noexcept
{
	array_ = std::move(src.array_);
	size_ = src.size_;
	head_ = src.head_;
	tail_ = src.tail_;
	src.array_ = nullptr;
	src.size_ = 0;
	src.tail_ = -1;
	src.head_ = -1;
	return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
	if ((head_ == tail_ + 1) || (tail_ == size_ - 1 && head_ == 0))
	{
		throw QueueOverflow();
	}
	else if (head_ == -1)
	{
		head_ = tail_ = 0;
		array_[tail_] = e;
	}
	else if (tail_ == size_ - 1 && head_ != 0)
	{
		tail_ = 0;
		array_[tail_] = e;
	}
	else
	{
		tail_++;
		array_[tail_] = e;
	}
}

template <typename T>
T QueueArray<T>::deQueue()
{
	if (head_ == -1) 
	{
		throw QueueUnderflow();
	}

	T data = array_[head_];
	if (head_ == tail_)
	{
		head_ = -1;
		tail_ = -1;
	}
	else if (tail_ == size_ - 1)
	{
		head_ = 0;
	}
	else 
	{
		head_++;
	}
	return data;
}

template <typename T>
void QueueArray<T>::printQueue(std::ostream& os)
{
	if (this->isEmpty())
	{
		os << "Queue is empty!\n";
		return;
	}
	os << "Elements in Queue: ";
	if (tail_ >= head_)
	{
		for (size_t i = head_; i <= tail_; i++)
		{
			os << array_[i] << " ";
		}
	}
	else 
	{
		for (size_t i = head_; i < size_; i++)
		{
			os << array_[i] << " ";
		}

		for (size_t i = 0; i <= tail_; i++)
		{
			os << array_[i] << " ";
		}
	}
}
#endif