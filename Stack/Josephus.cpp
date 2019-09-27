

#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int data = 0, Node* next = NULL)
	{
		this->data = data;
		this->next = next;
	}
};
class CircList
{
public:
	CircList()
	{
		head = new Node();
		tail = head;
		head->next = head;
	}
	void InsertRear(int elem)
	{
		
		Node* newnode = new Node(elem);
		if (head->next == head)
		{
			head->next = newnode;
			newnode->next = head;
			tail = newnode;
		}
		newnode->next = tail->next;
		tail->next = newnode;
		tail = newnode;
	}
	Node* Locate(int i)
	{
		Node* p = head;
		if (i < 1) return NULL;
		int j = 0;
		while (p!=tail&&j<i)
		{
			p = p->next;
			j++;
		}
		return p;
	}
private:
	Node* head;
	Node* tail;
	
};
void Run(int N, int p)
{
	CircList cl;
	int i, j;
	for (i = 1; i <= N; i++)
	{
		cl.InsertRear(i);
	}
	Node* pr = cl.Locate(1);
	Node* pre=NULL;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 1; j < p; j++)
		{
			pre = pr;
			pr = pr->next;
			if (pr->data == 0)
			{
				j--;
			}
		}
		cout << pr->data << " ";
		pre->next = pr->next;
		delete pr;
		pr = pre->next;
	}
	cout << pre->data;
}
int main()
{
	int N, p;
	cin >> N >> p;
	Run(N, p);
}




