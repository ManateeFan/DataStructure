#include <iostream>

using namespace std;

// ������6����β��ͷ��ӡ����
// ��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
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