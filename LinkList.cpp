#include<iostream>

using namespace std;

template<class T>
class LinkList;

template<class T>
class Node
{
	T data;
	Node* next;
public:
	Node() = default;
	Node(T d) :data(d)
	{
		next = nullptr;
	}

	friend LinkList<T>;
};

template<class T>
class LinkList
{
	Node<T>* head;
	int length;
public:
	LinkList() 
	{
		head = nullptr;
		length = 0;
	}
	~LinkList() = default;

	bool isEmpty()
	{
		return length == 0;
	}

	int getLength()
	{
		return length;
	}

	void insertFront(T d)
	{
		Node<T>* newnode = new Node<T>(d);
		if (isEmpty())
		{
			head->next = newnode;
		}
		else
		{
			newnode->next = head->next;
			head->next = newnode;
		}
		length++;
	}

	void insertRear(T d)
	{
		Node<T>* newnode = new Node<T>(d);
		Node<T>* p = head;

		while (p->next != nullptr)
			p = p->next;

		p->next = newnode;
		length++;
	}

	void insert(const int& i, T d)	//insert position i >0
	{
		if (i > length || i < 1) return;
		if (i == 1)
			insertFront(d);
		else
		{
			Node<T>* newnode = new Node<T>(d);
			Node<T>* p = head->next;

			int j = 2;
			while (j++ < i)
				p = p->next;
			newnode->next = p->next;
			p->next = newnode;
		}
		length++;
	}

	T& getNode(const int& i)
	{
		Node<T>* p = head;

		int j = 0;
		while (j != i)
		{
			p = p->next;
			j++;
		}
		return p->data;
	}

	void deleteData(const T& d)
	{
		Node<T>* p = head, * del = nullptr;

		while (p->next->data != d)
			p = p->next;
		del = p->next;
		p->next = del->next;
		length--;
		delete del;
	}

	void deleteIndex(const int& i)
	{
		if (i<1 || i>length) return;

		Node<T>* p = head, * del = nullptr;

		int j = 1;
		while (j != i)
		{
			p = p->next;
			j++;
		}
		del = p->next;
		p->next = del->next;
		length--;
		delete del;
	}

	void clear()
	{
		Node<T>* p = head->next, * del = head->next;
		while (del != nullptr)
		{
			p = p->next;
			delete del;
			del = p;
		}
		length = 0;
	}
};

int main() {
	LinkList<int> L;
	L.getLength();
	L.insertFront(3);
	L.insertFront(4);
	L.insertRear(2);
	L.getLength();
	L.insert(2, 3);
	return 0;
}
