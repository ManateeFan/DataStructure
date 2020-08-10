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
    int V;	//顶点数
    int E;	// 边数
    pList* vertexs;
    int* mark;  // 搜索用到的标记数组
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

    int SumV() const { return V; }	// 顶点数
    int SumE() const { return E; }	// 遍数

    void AddEdge(int v, int w);	// 将v与w相连
    void RemoveEdge(int v, int w);	// 将v与w断开
    std::vector<int> Adj(int v) const;	// 返回和v相连的所有节点
    int Count(int v) const; // 与v相连的总顶点数
    void DFS(int v);  // 深度优先遍历
    void DFSrecursion(int v); // 递归深度优先遍历
    void BFS(int v);  // 广度优先遍历

    void InitMark()  // 初始化mark数组
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
        auto adjVals = Adj(val);    // 与val连通的顶点

            for (auto idx : adjVals)
            {   // 该顶点未被访问
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
        //　存在与val连通的顶点
            for (auto idx : adjVals)
            {   //未被访问过，就放入队列
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
