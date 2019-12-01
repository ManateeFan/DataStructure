#pragma once


/* k % SIZE */
template<typename T, int SIZE = 22>
class ChainedHashTable
{
private:
	struct Node
	{
		unsigned key;
		T value;
		Node* prev;
		Node* next;
		Node() :prev(nullptr), next(nullptr) {}
		Node(int k, T const& v) :key(k), value(v), prev(nullptr), next(nullptr) {}
	};
	Node* elems[SIZE];

public:
	ChainedHashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			elems[i] = nullptr;
		}
	}
	~ChainedHashTable() = default;

	void Insert(unsigned k, T const& x);

	void Delete(unsigned k, T const& x);
};

template<typename T, int SIZE>
inline 
void ChainedHashTable<T, SIZE>::Insert(unsigned k, T const& x)
{
	unsigned index = k % size;
	Node* node = new Node(k, x);
	if (elems[index])
	{
		elems[index]->prev = node;
		node->next = elems[index];
		elems[index] = node;
	}
	else
	{
		elems[index] = node;
	}
}

template<typename T, int SIZE>
inline
void ChainedHashTable<T, SIZE>::Delete(unsigned k, T const& x)
{
	unsigned index = k % SIZE;
	if (elems[index])
	{
		Node* p = elems[index];
		while (p->key != k && p->value != x && p)
		{
			p = p->next;
		}
		if (p)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
		}
	}
}