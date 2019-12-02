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