#include<iostream>
using namespace std;
class List;
//结点定义
class ListNode
{
public:
    int data;       //数据域
    ListNode *next;//指针域
    ListNode(int e)
    {
        data=e;
        next=NULL;
    }
};
//链表定义
class List
{
private:
    ListNode *first; //头指针
public:
    List(ListNode *p=NULL)
    {
        first=p;
    }
    //拷贝构造
    List(const List &L)
    {
        first = NULL;
        CopyList(L);
    }
    ListNode *GetFirst()
    {
        return first;
    }
    //头插
    void InputFront(int elem)
    {
        ListNode *newNode = new ListNode(elem);
        if (first)
        {
            newNode->next = first;
            first = newNode;
        }
        else
        {
            first = newNode;
        }
    }
    //尾插
    void InputRear(int elem)
    {
        ListNode *newNode = new ListNode(elem);
        ListNode *rear;
        if (first)
        {
            rear = first;
            while (rear->next)
            {
                rear = rear->next;
            }
            rear->next = newNode;
        }
        else
        {
            first = newNode;
        }
    }
    //第i个结点插
    bool Insert(int i,int elem)
    {
        ListNode *newNode = new ListNode(elem);
        if (i < 1)
            return false;
        ListNode *pre = Locate(i - 1);
        newNode->next = pre->next;
        pre->next = newNode;
        return true;
    }
    //删除结点
    bool Remove(int i, int &elem)
    {
        if (i < 1)
            return false;
        if (1 == i)
        {
            ListNode *del = first;
            first = first->next;
            elem = del->data;
            delete del;
        }
        else
        {
            ListNode *del = Locate(i);
            ListNode *pre = Locate(i - 1);
            pre->next = del->next;
            elem = del->data;
            delete del;
        }
        return true;
    }
    //查找某个元素的位置
    ListNode *Search(const int &elem)
    {
        ListNode *p = first;
        while (p)
        {
            if (p->data == elem)
                return p;
            p = p->next;
        }
        return p;
    }
    //返回第i个结点的位置
    ListNode *Locate(int i)
    {
        ListNode *p = first;
        if (i < 1)
            return NULL;
        int j = 1;
        while (NULL != p && j < i)
        {
            p = p->next;
            j++;
        }
        return p;
    }
    //更新第i个位置的元素
    void SetData(int i, const int &x)
    {
        ListNode *p = Locate(i);
        if (NULL == p)
            return;
        p->data = x;
    }
    //返回第i个位置的元素
    bool GetData(int i, int &x)
    {
        ListNode *p = Locate(i);
        if (NULL == p)
            return false;
        x = p->data;
        return true;
    }
    //返回单链表长度
    int Length()
    {
        ListNode *p = first;
        int i = 0;
        while (p)
        {
            p = p->next;
            i++;
        }
        return i;
    }
    //判断链表是否为空
    bool IsEmpty()
    {
        return NULL == first;
    }
    //复制单链表
    void CopyList(const List &L)
    {
        List *T = new List();
        ListNode *p = L.first;
        while (p)
        {
            T->InputRear(p->data);
            p = p->next;
        }
        first = T->first;
    }
    //清空单链表
    bool MakeEmpty()
    {
        ListNode *p = NULL;
        while (first)
        {
            p = first;
            first = first->next;
            delete p;
        }
        return true;
    }
    //元素排序
    void UpSort()
    {
        int count = Length();
        ListNode *p = first;
        while (count > 1)
        {
            while (NULL != p->next)
            {
                if (p->data > p->next->data)
                {
                    int tmp = p->data;
                    p->data = p->next->data;
                    p->next->data = tmp;
                }
                p = p->next;
            }
            count--;
        }
    }
    //赋值运算符重载
    List &operator=(const List &L)
    {
        if (this == &L)
            return *this;
        else
        {
            MakeEmpty();
            CopyList(L);
            return *this;
        }
    }
    //销毁单链表
    ~List()
    {
        MakeEmpty();
    }
    //合并
    ListNode *Merge(ListNode *L)
    {
        ListNode *newnode = new ListNode(0);
        ListNode *flag = newnode;
        ListNode *p1 = first;
        ListNode *p2 = L;
        while (NULL != p1 && NULL != p2)
        {
            if (p1->data < p2->data)
            {
                newnode->next = p1;
                p1 = p1->next;
            }
            else
            {
                newnode->next = p2;
                p2 = p2->next;
            }
            newnode = newnode->next;
        }
        if (p1 == NULL)
            newnode->next = p2;
        else
            newnode->next = p1;
        return flag;
    }
    //按顺序输出
    void Output()
    {
        ListNode *p = first;
        while (p->next != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data;
    }
};

int main()
{
    List *A=new List();
    List* B=new List();
    int x=0;
    cin>>x;
    while(-1!=x)
    {
        A->InputRear(x);
    }
    cin>>x;
    while(-1!=x)
    {
        B->InputRear(x);
    }
    if(A->IsEmpty() && B->IsEmpty())
    {
        cout<<"NULL";
        return 0;
    }
    else if(A->IsEmpty())
    {
        B->Output();
        return 0;
    }
    else if(B->IsEmpty())
    {
        A->Output();
        return 0;
    }
    else
    {
        List *C=new List(A->Merge(B->GetFirst()));
        C->Output();
    }


    return 0;
}
