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
#include "Bag.h"

class Graph
{
private:
	int V;									// Number of vertex
	int E;									// Number of edge
	Bag* bags;				// Adjacency list

public:
	// ������v�����㵫�����ߵ�ͼ
	Graph(int v);

	// ��������in ���붥������������Ȼ������ÿ����ͨ����
	Graph(std::istream& in);


	~Graph()
	{
		delete[]bags;
	}

	void AddEdge(int v1, int v2);

	// ���ض���v��list
	Bag* Adjs(int v) const;

	// The number of connected with v
	int Count(int v) const;

	// v is connected with start
	bool Connected(int v) const;

	// v1 is connected with v2
	bool Connected(int v1, int v2) const;

	// ����v�Ķ���
	int Degree(int v) const;

	// �����������
	int MaxDegree() const;

	// �Ի�����
	int SelfLoop() const;
};


Graph::Graph(int v) :V(v), E(0), bags(new Bag[V]) {}

Graph::Graph(std::istream& in) : V(0), E(0), bags(nullptr)
{
	int vertexNum = 0;					// Number of vertex
	int edgeNum = 0;					// Number of edge
	in >> vertexNum >> edgeNum;
	V = vertexNum;
	E = edgeNum;
	bags = new Bag[V];
	while (edgeNum--)
	{
		int v1, v2;
		in >> v1 >> v2;
		AddEdge(v1, v2);
	}
}

inline void Graph::AddEdge(int v1, int v2)
{
	bags[v1].Add(v2);
	bags[v2].Add(v1);
	E++;
}

inline Bag* Graph::Adjs(int v) const
{
	return &bags[v];
}

inline int Graph::Count(int v) const
{
	return bags[v].GetNum();
}

inline bool Graph::Connected(int v) const
{
	if (bags[0].Get(v) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


inline bool Graph::Connected(int v1, int v2) const
{
	if (bags[v1].Get(v2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Graph::Degree(int v) const
{
	return bags[v].GetNum();
}

inline int Graph::MaxDegree() const
{
	int max = 0;
	for (int i = 0; i < V; i++)
	{
		int num = bags[i].GetNum();
		if (num > max)
			max = num;
	}
	return max;
}

inline int Graph::SelfLoop() const
{
	int num = 0;
	for (int i = 0; i < V; i++)
	{
		if (bags[i].Get(i))
			num++;
	}
	return num;
}
