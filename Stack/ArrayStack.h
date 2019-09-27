#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H


template<typename T>
class ArrayStack
{
private:
	int count;	//栈的元素数量
	int capacity;	//栈的容量
	T* array;	//数组
public:
	ArrayStack(int s = 10);
	~ArrayStack();
	T top();	//获取栈顶元素
	void push(T t);	//进栈
	T pop();	//出栈
	bool isEmpty();	//判空
	int size();	//栈的元素数量
};
#endif //
