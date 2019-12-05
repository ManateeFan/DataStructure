#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
};
// 栈
void Fuck(ListNode *pHead)
{
	stack<ListNode *> s;
	ListNode *p = pHead;
	while (p)
	{
		s.push(p);
		p = p->m_pNext;
	}
	while (!s.empty())
	{
		cout << s.top()->m_nKey;
		s.pop();
	}
}
// 递归
void Shit(ListNode *pHead)
{
	ListNode *p = pHead;
	if (p)
	{
		if (!p->m_pNext)
			cout << p->m_pNext << " ";
		else
			Shit(p->m_pNext);
	}
}