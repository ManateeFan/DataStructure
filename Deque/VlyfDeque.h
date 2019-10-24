//双端队列
template<class T>
class VlyfDeque;

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

	friend VlyfDeque<T>;
};

template<class T>
class VlyfDeque
{
	Node<T>* head;
	Node<T>* tail;
	int length;
public:
	VlyfDeque()
	{
		head = new Node<T>;
		tail = new Node<T>;
		head->next = tail;
		length = 0;
	}
	~VlyfDeque()
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
	void PuhsFront(const T& d)
	{
		Node<T>* newnode = new Node<T>(d);
		newnode->next = head->next;
		head->next = newnode;
		length++;
	}
	//尾插
	void PushBack(const T& d)
	{
		Node<T>* newnode = new Node<T>(d);
		Node<T>* p = head;
		while (p->next != tail)
			p = p->next;
		p->next = newnode;
		newnode->next = tail;
		length++;
	}
	//头出
	void PopFront()
	{
		if (isEmpty()) return;
		Node<T>* p = head->next;
		head->next = p->next;
		delete p;
		length--;
	}
	//尾出
	void PopBack()
	{
		if (isEmpty()) return;
		Node<T>* p = head;
		while (p->next->next != tail)
			p = p->next;
		delete p->next;
		p->next = tail;
		length--;
	}
	//清空
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
		delete head;
		delete tail;
	}
};
