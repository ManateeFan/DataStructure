//
// Created by liuyifan on 2020/8/10.
//

#ifndef GRAPHMATRIX_GRAPHMATRIX_H
#define GRAPHMATRIX_GRAPHMATRIX_H

#include <array>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

template<int SIZE>
class GraphMatrix {
private:
    char vertexs[SIZE]; // 顶点的集合
    int nVertex = SIZE; // 顶点个数
    std::array<std::array<int, SIZE>, SIZE> matrix = {0}; // 邻接矩阵 j->i
    std::array<int, SIZE> mark = {0};
    int nEdge;  // 边的个数字

public:
    template<int N>
    GraphMatrix(char (&vtx)[SIZE], char (&edges)[N][2]);

    void Print() const; // 打印矩阵

    int GetIndex(char ch) const;    // 获取一个顶点的索引

    std::vector<char> Adjs(char ch) const;  // 获取顶点ch指向的顶点集合

    void InitMark() {
        std::for_each(std::begin(mark), std::end(mark), [](int &num) {
            num = 0;
        });
    }   // 初始化mark


    void DFS(char ch);  // 深度优先遍历

    void DFSrecursion(char ch); // 递归深度优先遍历

    void BFS(char ch);  // 广度优先遍历

};

template<int SIZE>
template<int N>
GraphMatrix<SIZE>::GraphMatrix(char (&vtx)[SIZE], char (&edges)[N][2]) {
    nEdge = N;
    // 顶点
    for (int i = 0; i < SIZE; ++i) {
        vertexs[i] = vtx[i];
    }
    // 边
    for (int i = 0; i < N; ++i) {
        int m = GetIndex(edges[i][0]);  // 获取第一个顶点在矩阵的索引
        int n = GetIndex(edges[i][1]);  // 获取第二个顶点在矩阵的索引
        matrix[n][m] = 1;
    }
}

template<int SIZE>
int GraphMatrix<SIZE>::GetIndex(char ch) const {
    for (int i = 0; i < SIZE; ++i) {
        if (ch == vertexs[i]) {
            return i;
        }
    }
    return -1;
}

template<int SIZE>
void GraphMatrix<SIZE>::Print() const {
    std::for_each(std::begin(vertexs), std::end(vertexs), [](char ch) {
        std::cout << " " << ch;
    });
    std::cout << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << vertexs[i] << " ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<int SIZE>
std::vector<char> GraphMatrix<SIZE>::Adjs(char ch) const {
    std::vector<char> res;  // 存放顶点集合
    auto idx = GetIndex(ch);    // 获取顶点的索引
    if (idx == -1) return {};
    for (int i = 0; i < SIZE; ++i) {
        if (matrix[i][idx] == 1) {
            res.push_back(vertexs[i]);
        }
    }
    return std::move(res);
}

template<int SIZE>
void GraphMatrix<SIZE>::DFSrecursion(char ch) {
    std::cout << " ->" << ch;
    auto idx = GetIndex(ch);
    mark[idx] = 1;
    auto adjs = Adjs(ch);   // 获取ch指向的所有顶点
    for(auto m :  adjs) {
        idx = GetIndex(m); // 获取当前顶点的索引
        if(mark[idx] == 0) {
            DFS(m);
        }
    }
}

template<int SIZE>
void GraphMatrix<SIZE>::DFS(char ch) {
    std::stack<char> s;
    s.push(ch);
    while(!s.empty())
    {
        auto chr = s.top();
        std::cout << " ->" << chr;
        auto idx = GetIndex(chr);
        mark[idx] = 1;
        s.pop();
        auto adjs = Adjs(chr);  // 顶点chr指向的顶点的集合
        for(auto m : adjs) {
            idx = GetIndex(m); // 获取该顶点索引
            if(mark[idx] == 0) {    // 未被访问过
                s.push(m);
            }
        }
    }
}

template<int SIZE>
void GraphMatrix<SIZE>::BFS(char ch) {
    std::queue<char> q;
    std::cout << " ->" << ch;
    auto idx = GetIndex(ch);
    mark[idx] = 1;
    q.push(ch);
    while (!q.empty()) {
        auto chr = q.front();
        q.pop();
        auto adjs = Adjs(chr);
        for(auto m : adjs) {
            idx = GetIndex(m);
            if(mark[idx] == 0) {
                std::cout << " ->" << m;
                mark[idx] = 1;
                q.push(m);
            }
        }
    }
}
#endif //GRAPHMATRIX_GRAPHMATRIX_H

