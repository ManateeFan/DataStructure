#pragma once

#include <stdexcept>

/* ѧϰ�����͵���ģ����������Զ���һ��ջ��Ϊ��ϰ*/
/* �����С����Ϊ�����͵�ģ����� */

template <typename T, int MAXSIZE>
class Stack
{
private:
	T elems[MAXSIZE];
	int numElem;

public:
	Stack();
	void push(T const&);
	void pop();
	T top() const;

	bool empty() const
	{
		return numElem == 0;
	}

	bool full() const
	{
		return MAXSIZE == numElem;
	}
};

template <typename T, int MAXSIZE>
inline Stack<T, MAXSIZE>::Stack()
	: numElem(0)
{

}

template <typename T, int MAXSIZE>
inline void Stack<T, MAXSIZE>::push(T const& elem)
{
	if (numElem == MAXSIZE)
		throw std::out_of_range("Stack<>::push(): stack is full");
	elems[numElem++] = elem;
}

template <typename T, int MAXSIZE>
inline void Stack<T, MAXSIZE>::pop()
{
	if (numElem <= 0)
		throw std::out_of_range("Stack<>::pop(): stack is empty");
	numElem--;
}

template <typename T, int MAXSIZE>
inline T Stack<T, MAXSIZE>::top() const
{
	if (numElem <= 0)
		throw std::out_of_range("Stack<>::top(): stack is empty");
	return elems[numElem - 1];
}