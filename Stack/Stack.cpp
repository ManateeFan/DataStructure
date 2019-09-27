

#include <iostream>
using namespace std;
#include"ArrayStack.h"
#include "ListStack.h"

/*数组栈的实现*/
template<typename T>
ArrayStack<T>::ArrayStack(int s)
{
	array = new T[s];
	capacity = s;
};
template<typename T>
ArrayStack<T>::~ArrayStack()
{
	delete array;
};
//判空
template<typename T>
bool ArrayStack<T>::isEmpty()
{
	return count == 0;
};
//获取栈的大小
template<typename T>
int ArrayStack<T>::size()
{
	return count;
};
//入栈
template<typename T>
void ArrayStack<T>::push(T t)
{
	if (count != capacity)
	{
		array[count++] = t;
	}
};
//出栈
template<typename T>
T ArrayStack<T>::pop()
{
	if (count != 0)
	{
		return array[--count];
	}
};
//获取栈顶元素
template<typename T>
T ArrayStack<T>::top()
{
	if (count != 0)
	{
		return array[count - 1];
	}
};

/*链表栈的实现*/
//链表结点
template <typename T>
class Node
{
public:
	T data;
	Node* next;
	Node(T t)
	{
		data = t;
		next = NULL;
	}
	Node()
	{
		next = NULL;
	}
};
//构造
template <typename T>
ListStack<T>::ListStack()
{
	phead = new Node<T>();
	count = 0;
};
//析构
template <typename T>
ListStack<T>::~ListStack()
{
	if (count > 0)
	{
		Node <T>* pre = phead->next;
		Node <T>* succ = phead->next;
		for (int i = 0; i < count;i++)
		{
			succ = succ->next;
			delete pre;
			pre = succ;
		}
	}
	delete phead;
	
};
//返回栈的大小
template <typename T>
int ListStack<T>::size()
{
	return count;
};
//判空
template <typename T>
bool ListStack<T>::isEmpty()
{
	return count == 0;
};
//入栈
template <typename T>
void ListStack<T>::push(T t)
{
	Node <T>* pnode = new Node<T>(t);
	pnode->next = phead->next;
	phead->next = pnode;
	count++;
};
//出栈
template <typename T>
T ListStack<T>::pop()
{
	if (count>0)
	{
		Node <T>* pnode = phead->next;
		phead->next = pnode->next;
		T value = pnode->data;
		delete pnode;
		count--;
		return value;
	}
};
//获取栈顶元素
template <typename T>
T ListStack<T>::top()
{
	if (count > 0)
	{
		return phead->next->data;
	}
};
int main()
{
	/* ArratStack   Test
	ArrayStack<int> p(5);
	for (int i = 0; i < 5; i++)
	{
		p.push(i);
	}
	cout << "栈的大小:" << p.size() << endl;
	cout << "栈是否为空:" << p.isEmpty() << endl;
	cout << "栈顶元素：" << p.top() << endl;
	cout << "依次出栈:" << endl;
	while (!p.isEmpty())
	{
		cout << p.pop() << endl;
	}
	*/
  /* ListStack  Test */
	ListStack <string> lstack;
	lstack.push("hello");
	lstack.push("to");
	lstack.push("you！");

	cout << "栈的大小:" << lstack.size() << endl;
	cout << "栈顶元素:" << lstack.top() << endl;

	while (!lstack.isEmpty())
	{
		lstack.pop();
	}

	cout << "栈的大小:" << lstack.size() << endl;

	return 0;
}




