#pragma once

#include <stdexcept>

template<typename T, int MAXSIZE>
class Deque
{
private:
	T elems[MAXSIZE + 1];
	int head;
	int tail;

public:
	Deque() :head(0), tail(head) {}

	void EnDeque(T const&);
	T DeDeque();
	bool Empty() const
	{
		return head == tail;
	}
	bool Full() const
	{
		return (head == tail + 1) || (tail == MAXSIZE && head == 0);
	}
};

template<typename T, int MAXSIZE>
inline void Deque<T, MAXSIZE>::EnDeque(T const& elem)
{
	if (Full())
		throw std::out_of_range("Deque is full");
	if (tail == MAXSIZE)
	{
		elems[tail] = elem;
		tail = 0;
	}
	else
	{
		elems[tail++] = elem;
	}
}

template<typename T, int MAXSIZE>
inline T Deque<T, MAXSIZE>::DeDeque()
{
	if (Empty())
		throw std::out_of_range("Deque is empty");
	if (head == MAXSIZE)
	{
		T temp = elems[head];
		head = 0;
		return temp;
	}
	else
	{
		return elems[head++];
	}
}