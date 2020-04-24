//*****************************************************************
//  Graph.h
//  Graph
//
//  Created by vlyf on December 3, 2019
//
//*****************************************************************
#pragma once

#include <array>
#include <iostream>
#include <iterator>
#include <queue>

#include "Bag.h"

class Graph {
 private:
  int V;      // Number of vertex
  int E;      // Number of edge
  Bag* bags;  // Adjacency list
  bool* marked;
  int count;

 public:
  Graph(int v);  // ������v�����㵫�����ߵ�ͼ

  Graph(std::istream& in);  // ��������in ���붥������������Ȼ������ÿ����ͨ����

  ~Graph() {
    delete[] bags;
    delete[] marked;
  }

  void AddEdge(int v1, int v2);

  Bag* Adjs(int v) const;  // ���ض���v��list

  int Count(int v) const;  // The number of connected with v

  bool Connected(int v) const;  // v is connected with start

  bool Connected(int v1, int v2) const;  // v1 is connected with v2

  int Degree(int v) const;  // ����v�Ķ���

  int MaxDegree() const;  // �����������

  int SelfLoop() const;  // �Ի�����

  int DepthFirstSearch(int v);  // �����������

  void BreadthFirstSearch(int v);  // �����������

 private:
  void dfs(int v);
  void bfs(int v);
};

Graph::Graph(int v)
    : V(v), E(0), bags(new Bag[V]), marked(new bool[V]), count(0) {
  for (int i = 0; i < V; i++) {
    bags[i].head->V = i;
    marked[i] = false;
  }
}

Graph::Graph(std::istream& in)
    : V(0), E(0), bags(nullptr), marked(nullptr), count(0) {
  int vertexNum = 0;  // Number of vertex
  int edgeNum = 0;    // Number of edge
  in >> vertexNum >> edgeNum;
  V = vertexNum;
  E = edgeNum;
  marked = new bool[V];
  bags = new Bag[V];
  while (edgeNum--) {
    int v1, v2;
    in >> v1 >> v2;
    AddEdge(v1, v2);
  }
}

inline void Graph::AddEdge(int v1, int v2) {
  bags[v1].Add(v2);
  bags[v2].Add(v1);
  E++;
}

inline Bag* Graph::Adjs(int v) const { return &bags[v]; }

inline int Graph::Count(int v) const { return bags[v].GetNum(); }

inline bool Graph::Connected(int v) const {
  if (bags[0].Get(v) != nullptr) {
    return true;
  } else {
    return false;
  }
}

inline bool Graph::Connected(int v1, int v2) const {
  if (bags[v1].Get(v2)) {
    return true;
  } else {
    return false;
  }
}

inline int Graph::Degree(int v) const { return bags[v].GetNum(); }

inline int Graph::MaxDegree() const {
  int max = 0;
  for (int i = 0; i < V; i++) {
    int num = bags[i].GetNum();
    if (num > max) max = num;
  }
  return max;
}

inline int Graph::SelfLoop() const {
  int num = 0;
  for (int i = 0; i < V; i++) {
    if (bags[i].Get(i)) num++;
  }
  return num;
}

inline int Graph::DepthFirstSearch(int v) {
  dfs(v);

  int tmp = count;
  count = 0;
  return tmp;
}

inline void Graph::BreadthFirstSearch(int v) { bfs(v); }

inline void Graph::dfs(int v) {
  marked[v] = true;
  count++;
  Bag* list = Adjs(v);
  Item* p = list->head->next;
  auto f = [&]() -> bool { return marked[p->V]; };
  while (p) {
    if (!f()) dfs(p->V);
    p = p->next;
  }
}

inline void Graph::bfs(int v) {
  Bag* list = Adjs(v);
  Item* p = list->head;
  list->head->color = Color::GRAY;
  std::queue<Item*> dq;
  dq.push(p);
  while (!dq.empty()) {
    Item* paren = dq.front();
    p = paren->next;

    while (p) {
      p->color = Color::GRAY;
      p->depth = dq.front()->depth + 1;
      p->parent = paren;
      dq.push(p);
      p = p->next;
    }
    dq.pop();
    paren->color = Color::BLACK;
  }
}
