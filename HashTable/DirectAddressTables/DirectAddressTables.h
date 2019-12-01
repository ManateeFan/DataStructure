#pragma once

#include <stdexcept>

template<typename T, int MAXSIZE>
class DirectAddressTable
{

private:
	struct Node
	{
		unsigned key;
		T value;
		Node() = default;
		Node(unsigned k, T const& v) :key(k), value(v) {}
	};
	Node* elems[MAXSIZE];
public:
	using pointer = Node*;
	void Insert(unsigned k, T const& v);
	pointer Search(unsigned k) const;
};

template<typename T, int MAXSIZE>
inline
void DirectAddressTable<T, MAXSIZE>::Insert(unsigned k, T const& v)
{
	if (k >= MAXSIZE)
		throw std::out_of_range("Table is full");
	elems[k] = new Node(k, v);
}

template<typename T, int MAXSIZE>
inline
typename DirectAddressTable<T, MAXSIZE>::pointer DirectAddressTable<T, MAXSIZE>::Search(unsigned k) const
{
	return elems[k];
}

