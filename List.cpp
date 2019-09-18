class List;
//结点定义
class ListNode {
	int data;	//数据域
	ListNode* next;		//指针域
	friend List;
};
//链表定义
class List {
private:
	ListNode* first;	//头指针
public:
	List() {
		first = NULL;
	}
	//拷贝构造
	List(const List& L) {
		first = NULL;
		CopyList(L);
	}
	//头插
	void InputFront(const int& elem) {
		ListNode* newNode = new ListNode();
		newNode->data = elem;
		if (first) {
			newNode->next = first;
			first = newNode;
		}
		else {
			first = newNode;
			newNode->next = NULL;
		}
	}
	//尾插
	void InputRear(const int& elem) {
		ListNode* newNode = new ListNode();
		newNode->data = elem;
		ListNode* rear;
		if (first) {
			rear = first;
			while (rear->next) {
				rear = rear->next;
			}
			rear->next = newNode;
		}
		else {
			first = newNode;
		}
	}
	//第i个结点插
	bool Insert(int i, const int& elem) {
		ListNode* newNode = new ListNode();
		newNode->data = elem;
		if (i < 1) return false;
		ListNode* pre = Locate(i - 1);
		newNode->next = pre->next;
		pre->next = newNode;
		return true;
	}
	//删除结点
	bool Remove(int i, int& elem) {
		if (i < 1) return false;
		if (1 == i) {
			ListNode* del = first;
			first = first->next;
			elem = del->data;
			delete del;
		}
		else
		{
			ListNode* del = Locate(i);
			ListNode* pre = Locate(i - 1);
			pre->next = del->next;
			elem = del->data;
			delete del;
		}
		return true;
	}
	//查找某个元素的位置
	ListNode* Search(const int& elem) {
		ListNode* p = first;
		while (p) {
			if (p->data == elem)
				return p;
			p = p->next;
		}
		return p;
	}
	//返回第i个结点的位置
	ListNode* Locate(int i) {
		ListNode* p = first;
		if (i < 1) return NULL;
		int j = 1;
		while (NULL != p && j < i) {
			p = p->next;
			j++;
		}
		return p;
	}
	//更新第i个位置的元素
	void SetData(int i, const int& x) {
		ListNode* p = Locate(i);
		if (NULL == p)
			return;
		p->data = x;
	}
	//返回第i个位置的元素
	bool GetData(int i, int& x) {
		ListNode* p = Locate(i);
		if (NULL == p)
			return false;
		x = p->data;
		return true;
	}
	//返回单链表长度
	int Length() {
		ListNode* p = first;
		int i = 0;
		while (p) {
			p = p->next;
			i++;
		}
		return i;
	}
	//判断链表是否为空
	bool IsEmpty() {
		return NULL == first;
	}
	//复制单链表
	void CopyList(const List& L) {
		List* T = new List();
		ListNode* p = L.first;
		while (p) {
			T->InputRear(p->data);
			p = p->next;
		}
		first = T->first;
	}
	//清空单链表
	bool MakeEmpty() {
		ListNode* p = NULL;
		while (first) {
			p = first;
			first = first->next;
			delete p;
		}
		return true;
	}
	//元素排序
	void Sort() {
		ListNode* p = first;
		for (int i = 0; i < Length() - 1; i++)
		{
			for (int j = i + 1; j < Length() - 1; j++)
			{
				if (p->data > p->next->data) {
					int t = p->data;
					p->data = p->next->data;
					p->next->data = t;
				}
				p = p->next;
			}
		}
	}
	//赋值运算符重载
	List& operator=(const List& L) {
		if (this == &L)
			return *this;
		else {
			MakeEmpty();
			CopyList(L);
			return *this;
		}
	}
	//销毁单链表
	~List() {
		MakeEmpty();
	}
};
