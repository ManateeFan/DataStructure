#pragma once

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
};
template <typename T>
class CircList
{
public:
	CircList();
	~CircList();
	void CreatCircList(int n);            //创建循环链表
	void InsertNode(int position, int d); //在指定位置插入结点
	void TraverList();                    //遍历循环链表
	bool IsEmpty();                       //判空
	int GetLength();                      //获取长度
	T* DeleteNode(int position,T* d);        //删除指定位置结点
	void DeleteCircList();                //删除循环链表
	Node<T>* GetHead();
private:
	Node<T>* head;
};
