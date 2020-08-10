//
// Created by liuyifan on 2020/8/10.
//
#ifndef GRAPHLIST_GRAPHLIST_H
#define GRAPHLIST_GRAPHLIST_H

#include "List.h"
#include <vector>
#include <stack>
#include <queue>

using pList = List*;
class GraphList
{
private:
    int V;	//������
    int E;	// ����
    pList* vertexs;
    int* mark;  // �����õ��ı������
public:
    GraphList(int v) : V{ v }, E{ 0 }, vertexs{ new pList[V] }, mark{ new int[V] }
    {
        for (int i = 0; i < V; ++i)
        {
            vertexs[i] = new List;
            mark[i] = 0;
        }
    }
    ~GraphList()
    {
        delete[] vertexs;
    }

    int SumV() const { return V; }	// ������
    int SumE() const { return E; }	// ����

    void AddEdge(int v, int w);	// ��v��w����
    void RemoveEdge(int v, int w);	// ��v��w�Ͽ�
    std::vector<int> Adj(int v) const;	// ���غ�v���������нڵ�
    int Count(int v) const; // ��v�������ܶ�����
    void DFS(int v);  // ������ȱ���
    void DFSrecursion(int v); // �ݹ�������ȱ���
    void BFS(int v);  // ������ȱ���

    void InitMark()  // ��ʼ��mark����
    {
        for (int i = 0; i < V; ++i)
        {
            mark[i] = 0;
        }
    }
};


void GraphList::AddEdge(int v, int w)
{
    if (v < 0 || w < 0 || v >= V || w >= V)
    {
        std::cout << "Add edge error" << std::endl;
    }
    else
    {
        vertexs[v]->Add(w);
        vertexs[w]->Add(v);
        std::cout << "Add " << v << "--" << w << " successfully" << std::endl;
    }
}

void GraphList::RemoveEdge(int v, int w)
{
    if (v < 0 || w < 0 || v >= V || w >= V)
    {
        std::cout << "Remove edge error" << std::endl;
    }
    else
    {
        vertexs[v]->Remove(w);
        vertexs[w]->Remove(v);
        std::cout << "Delete v--w successfully" << std::endl;
    }
}

std::vector<int> GraphList::Adj(int v) const
{
    std::vector<int> res;
    return std::move(vertexs[v]->Values());
}

int GraphList::Count(int v) const
{
    return Adj(v).size();
}

void GraphList::DFS(int v)
{
    std::stack<int> s;
    s.push(v);
    while (!s.empty())
    {
        auto val = s.top();
        std::cout << "-> " << val;
        mark[val] = 1;
        s.pop();
        auto adjVals = Adj(val);    // ��val��ͨ�Ķ���

            for (auto idx : adjVals)
            {   // �ö���δ������
                if (mark[idx] != 1)
                {
                    s.push(idx);
                }
            }
    
    }
}

void GraphList::DFSrecursion(int v)
{
    std::cout << "-> " << v;
    mark[v] = 1;
    auto adjVs = Adj(v);
    for (auto idx : adjVs)
    {
        if (mark[idx] == 0)
        {
            DFSrecursion(idx);
        }
    }
}

void GraphList::BFS(int v)
{
    std::queue<int> q;
    std::cout << "-> " << v;
    mark[v] = 1;
    q.push(v);
    while (!q.empty())
    {
        auto val = q.front();
        q.pop();
        auto adjVals = Adj(val);
        //��������val��ͨ�Ķ���
            for (auto idx : adjVals)
            {   //δ�����ʹ����ͷ������
                if (mark[idx] != 1)
                {
                    std::cout << "-> " << idx;
                    mark[idx] = 1;
                    q.push(idx);
                }
            }
    }
}

#endif //GRAPHLIST_GRAPHLIST_H
