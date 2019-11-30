#pragma once

#include <stdexcept>
template<typename Key>
struct Node
{
	using pointer = Node<Key>*;
	Key key;
	Node* prev;
	Node* next;
	Node(Key const& k) :key(k), prev(nullptr), next(nullptr) {}
};
template<typename T>
class CircularList
{
private:
	using pointer = typename Node<T>::pointer;
	pointer nil;

public:
	CircularList() :nil(new Node<T>()) 
	{
		nil->next = nil;
		nil->prev = nil;
	}

	pointer Search(T const&) const;
	// Í·²å
	void Insert(typename CircularList<T>::pointer const&);

	void Delete(typename CircularList<T>::pointer const&);
};

template<typename T>
inline
typename CircularList<T>::pointer CircularList<T>::Search(T const& k) const
{
	typename CircularList<T>::pointer p = nil->next;
	while (p != nil && p->key != k)
		p = p->next;
	return p;
}

template<typename T>
inline
void CircularList<T>::Insert(typename CircularList <T>::pointer const& x)
{
	x->next = nil->next;
	nil->next->prev = x;
	nil->next = x;
	x->prev = nil;
}

template<typename T>
inline
void CircularList<T>::Delete(typename CircularList <T>::pointer const& x)
{
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}