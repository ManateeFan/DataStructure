//*****************************************************************
//  ChainedHashTable.hpp
//  HashTable
//
//  Created by vlyf on December 2, 2019
//
//  This header file contains the Hash Table class.
//  Hash Table table elements consist of Linked List pointer.
//*****************************************************************

#pragma once

#include "LinkList.hpp"

using namespace std;

template <typename T, int MAXSIZE>
class ChainedHashTable {
 private:
  LinkList<T>* table;
  int length;

  int hash(string const& itemKey);

 public:
  ChainedHashTable();

  ~ChainedHashTable();

  void Insert(Item<T>* newItem);

  void Remove(string const& itemKey);

  Item<T>* Get(string const& itemKey);

  int Length() const { return length; }

  int GetNumberOfItems() const;
};

template <typename T, int MAXSIZE>
inline int ChainedHashTable<T, MAXSIZE>::hash(string const& itemKey) {
  int value = 0;
  for (std::size_t i = 0; i < itemKey.length(); i++) value += itemKey[i];
  return (itemKey.length() * value) % length;
}

template <typename T, int MAXSIZE>
inline ChainedHashTable<T, MAXSIZE>::ChainedHashTable()
    : table(new LinkList<T>[MAXSIZE]), length(MAXSIZE) {}

template <typename T, int MAXSIZE>
inline ChainedHashTable<T, MAXSIZE>::~ChainedHashTable() {
  delete[] table;
}

template <typename T, int MAXSIZE>
inline void ChainedHashTable<T, MAXSIZE>::Insert(Item<T>* newItem) {
  int index = hash(newItem->key);
  table[index].InsertItem(newItem);
}

template <typename T, int MAXSIZE>
inline void ChainedHashTable<T, MAXSIZE>::Remove(string const& itemKey) {
  int index = hash(itemKey);
  table[index].RemoveItem(itemKey);
}

template <typename T, int MAXSIZE>
inline Item<T>* ChainedHashTable<T, MAXSIZE>::Get(string const& itemKey) {
  int index = hash(itemKey);
  return table[index].GetItem(itemKey);
}

template <typename T, int MAXSIZE>
inline int ChainedHashTable<T, MAXSIZE>::GetNumberOfItems() const {
  int itemCount = 0;
  for (int i = 0; i < MAXSIZE; i++) {
    itemCount += table[i].Length();
  }
  return itemCount;
}
