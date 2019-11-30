#include <iostream>

using namespace std;

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
struct ListNode
{
	int key;
	unique_ptr<ListNode> next;
};
void Print(unique_ptr<ListNode> const& head)
{
	if (head)
	{
		if (head->next)
			Print(head->next);
		else
			cout << head->key << " ";
	}
}

int main()
{
	return 0;
}