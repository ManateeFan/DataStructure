//*****************************************************************
//  LinkList.hpp
//  HashTable
//
//  Created by vlyf on December 2, 2019.
//
//  This header file contains the Link List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************
#pragma once
#include <iostream>

template<typename T>
struct Item
{
	std::string key;
	T value;
	Item* next;
	Item() :next(nullptr)
	{
	}
	Item(std::string const& k, T const& v) :key(k), value(v), next(nullptr)
	{

	}
};

template<typename T>
class LinkList
{
private:
	Item<T>* head;
	int length;

public:
	LinkList();
	~LinkList();

	// Insert an item at the begin of the list
	void InsertItem(Item<T>* newItem);

	// Remove item from list by its key
	void RemoveItem(std::string const& itemKey);

	// Searches for an item by its key.
	Item<T>* GetItem(std::string const& itemKey) const;

	// The length of list
	int Length() const;
};

template<typename T>
inline LinkList<T>::LinkList() :head(new Item<T>), length(0)
{
	head->next = nullptr;
}

template<typename T>
inline LinkList<T>::~LinkList()
{
	if (length != 0)
	{
		Item<T>* p = head->next;
		Item<T>* del = head->next;
		while (del)
		{
			del = p->next;
			delete p;
			p = del;
		}
	}
	delete head;
}

template<typename T>
inline void LinkList<T>::InsertItem(Item<T>* newItem)
{
	newItem->next = head->next;
	head->next = newItem;
	length++;
}

template<typename T>
inline void LinkList<T>::RemoveItem(std::string const& itemKey)
{
	Item<T>* del = head;
	Item<T>* p = head;
	while (del)
	{
		del = p->next;
		if (del->key == itemKey)
		{
			p->next = del->next;
			delete del;
			length--;
			break;
		}
		p = del;
	}
}

template<typename T>
inline Item<T>* LinkList<T>::GetItem(std::string const& itemKey) const
{
	Item<T>* p = head->next;
	while (p)
	{
		if (p->key == itemKey)
			return p;
	}
	return nullptr;
}

template<typename T>
inline int LinkList<T>::Length() const
{
	return length;
}
