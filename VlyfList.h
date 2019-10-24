//带头尾结点的单链表
template<class T>
class VlyfList;	

template<class T>
class Node
{
	T data;
	Node* next;
public:
	Node():next(nullptr) {}
	Node(T d) :next(nullptr),data(d){}

	friend LinkList<T>;
};

template<class T>
class LinkList
{
	Node<T>* head;
	Node<T>* tail;
	int length;
public:
	LinkList()
	{
		head = new Node<T>;
		tail = new Node<T>;
		head->next = tail;
		length = 0;
	}
	~LinkList()
	{
		clear();
	}

	bool isEmpty()
	{
		return length == 0;
	}

	unsigned getLength()
	{
		return length;
	}
	//头插
	void insertFront(const T& d)
	{
		Node<T>* newnode = new Node<T>(d);
		newnode->next = head->next;
		head->next = newnode;
		length++;
	}
	//尾插
	void insertRear(const T& d)
	{
		Node<T>* newnode = new Node<T>(d);
		Node<T>* p = head;
		while (p->next != tail)
			p = p->next;
		p->next = newnode;
		newnode->next = tail;
		length++;
	}
	//按位置插入
	void insert(const int& i, const T& d)	//insert position i >0
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
	//返回指定位置结点的数据
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
	//删除结点中值为d的结点
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
	//按位置删除结点
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
	//清空链表
	void clear()
	{
		Node<T>* p = head->next, * del = head->next;
		while (del != tail)
		{
			p = p->next;
			delete del;
			del = p;
		}
		length = 0;
	}
};
