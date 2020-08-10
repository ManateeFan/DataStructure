//
// Created by liuyifan on 2020/8/10.
//
#ifndef GRAPHLIST_LIST_H
#define GRAPHLIST_LIST_H
#include <iostream>
#include <vector>

struct Node;
using pNode = Node*;
struct Node
{

    int val;
    pNode next = nullptr;
    Node(int v = 0) : val{ v } {}
};


class List
{
private:
    int nNode = 0;
    pNode head;

public:
    List() : head(nullptr) {}
    void Add(int v);	//头插v顶点
    void Remove(int v);	// 删除v顶点
    pNode Get(int v) const;	// 获取v顶点的节点指针
    std::vector<int> Values() const;	// 返回链表所有的值
    int Size() const	// 链表大小
    {
        return nNode;
    }
    bool Empty() const { return nNode == 0; }
    ~List();
};

void List::Add(int v)
{
    if (head == nullptr)
    {
        head = new Node(v);
    }
    else
    {
        pNode old = head;
        head = new Node(v);
        head->next = old;
    }
    ++nNode;
}

void List::Remove(int v)
{
    // 链表为空
    if (Empty())
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        pNode del = head;
        pNode next = del->next;
        pNode prev = del;
        while (del->val != v && del != nullptr)
        {
            prev = del;
            del = next;
            next = del->next;
        }
        if (del == nullptr)
        {
            std::cout << "don't have v:" << v << std::endl;
        }
        else
        {
            delete del;
            prev->next = next;
            --nNode;
        }
    }
}

pNode List::Get(int v) const
{
    if (Empty())
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    else
    {
        pNode cur = head;
        while (cur != nullptr)
        {
            if (cur->val == v)
            {
                return cur;
            }
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            std::cout << "don't have v: " << v << std::endl;

        }
        return nullptr;
    }
}

List::~List()
{
    if (!Empty())
    {
        pNode del = head;
        pNode next = del->next;
        if (next == nullptr)
        {
            delete del;
        }
        else
        {
            while (next != nullptr)
            {
                delete del;
                del = next;
                next = next->next;
            }
        }
    }
}

std::vector<int> List::Values() const
{
    if (Empty()) return {};
    std::vector<int> res;
    pNode cur = head;
    while (cur != nullptr)
    {
        res.push_back(cur->val);
        cur = cur->next;
    }
    return std::move(res);
}


#endif //GRAPHLIST_LIST_H
