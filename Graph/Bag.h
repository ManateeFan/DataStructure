//*****************************************************************
//  Bag.h
//  Graph
//
//  Created by vlyf on December 3, 2019.
//
//*****************************************************************
#pragma once
#include <iostream>

enum class Color {
  WHITE,  // δ������
  GRAY,   // �ѱ����֣����ڽ�����δ�����
  BLACK,  // �ѱ����֣����ڽ����������
};
struct Item {
  int V;
  Color color;
  int depth;
  Item* parent;
  Item* next;
  Item() : parent(nullptr), next(nullptr), depth(0), color(Color::WHITE) {}
  Item(int v)
      : V(v), parent(nullptr), next(nullptr), depth(0), color(Color::WHITE) {}
};

class Bag {
 private:
  Item* head;
  int itemNum;

 public:
  friend class Graph;
  Bag();
  ~Bag();

  void Add(int v);
  void Remove(int v);
  int GetNum() const;
  Item* Get(int v);
};

Bag::Bag() : head(new Item), itemNum(0) {}

Bag::~Bag() {
  Item* p = head;
  Item* del = head->next;
  while (del) {
    p = del->next;
    delete del;
    del = p;
  }
  delete head;
}

void Bag::Add(int v) {
  Item* newItem = new Item(v);
  newItem->next = head->next;
  head->next = newItem;
  itemNum++;
}

void Bag::Remove(int v) {
  Item* p = head;
  Item* del = head->next;
  while (del && del->V != v) {
    p = p->next;
    del = del->next;
  }
  if (del) {
    p->next = del->next;
    delete del;
    itemNum--;
  }
}

inline int Bag::GetNum() const { return itemNum; }

Item* Bag::Get(int v) {
  Item* p = head->next;
  while (p && p->V != v) {
    p = p->next;
  }
  if (p) return p;
  return nullptr;
}
