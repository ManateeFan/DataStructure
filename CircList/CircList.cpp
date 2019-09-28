#include<iostream>
#include"CircList.h"
using namespace std;
template <typename T>
CircList<T>::CircList()
{
	head = new Node<T>;
	head->data = 0;
	head->next = head;
};
template <typename T>
CircList<T>::~CircList()
{
	delete head;
};
template <typename T>
void CircList<T>::CreatCircList(int n)
{
	Node<T>* pnew = NULL;
	Node<T>* ptemp = head;
	while (n-- > 0)
	{
		pnew = new Node<T>;
		cin >> pnew->data;
		pnew->next = head;
		ptemp->next = pnew;
		ptemp = pnew;
	}
};
template<typename T>
void CircList<T>::InsertNode(int position, int d)
{
	if (position<0 || position>GetLength() + 1)
		exit(EXIT_FAILURE);
	else
	{
		Node<T>* pnew = NULL;
		Node<T>* ptemp = head;
		pnew = new Node<T>;
		pnew->data = d;
		while (position-- > 1)
			ptemp = ptemp->next;
		pnew->next = ptemp->next;
		ptemp->next = pnew;
	}
}
template <typename T>
void CircList<T>::TraverList()
{
	Node<T>* ptemp = head->next;
	while (ptemp!=head)
	{
		cout << ptemp->data << " ";
		ptemp = ptemp->next;
	}
	cout << endl;
};
template <typename T>
bool CircList<T>::IsEmpty()
{
	if (head->next == head)
		return true;
	else
		return false;
};
template <typename T>
int CircList<T>::GetLength()
{
	int n = 0;
	Node<T>* ptemp = head->next;
	while (ptemp != head)
	{
		ptemp = ptemp->next;
		n++;
	}
	return n;
};
template<typename T>
T* CircList<T>::DeleteNode(int position, T* d)
{
	if (position<1 || position>GetLength())
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		Node<T>* ptemp = head;
		Node<T>* pdel = NULL;
		while (position-- > 1)
			ptemp = ptemp->next;
		pdel = ptemp->next;
		ptemp->next = pdel->next;
		*d = pdel->data;
		delete pdel;
		pdel = NULL;
	}
};
template<typename T>
void CircList<T>::DeleteCircList()
{
	Node* pdel = head->next;
	Node* ptemp = NULL;
	while (pdel != head)
	{
		ptemp = pdel->next;
		head->next = ptemp;
		delete pdel;
		pdel = ptemp;
	}

};


template<typename T>
Node<T>* CircList<T>::GetHead()
{
	return head;
};
int main(void)
{
	CircList<int> c;
	int n, k;
	cin >> n >> k;
	c.CreatCircList(n);
	Node<int>* p=c.GetHead();
	Node<int>* ptemp=NULL;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			
			ptemp = p;
			p = p->next;
			if (p == c.GetHead())
			{
				ptemp = p;
				p = p->next;
			}
		}
		ptemp->next = p->next;
		cout << p->data << " ";
		delete p;
		p = ptemp;
	}
	c.TraverList();
	return 0;
}
