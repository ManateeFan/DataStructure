/*
 * VlyfList.h
 *
 *  Created on: 2019年10月23日
 *      Author: vlyf
 */

#ifndef VLYFLIST_H_
#define VLYFLIST_H_
namespace vlyflist
{

//带头尾节点的双向链表
template <typename T>
class VlyfList
{
public:
	frind class iterator;
	//双向节点
	struct Node
	{
	    Node(T &x) : data(x), prev(nullptr), next(nullptr) {}

	    T data;
	    Node *prev;
	    Node *next;
	};
    VlyfList() : theSize(0) { init(); }
    VlyfList(const VlyfList &l)
    {
        init();
        this->operator=(l);
    }
    ~VlyfList()
    {
        Node *tmp = head->next;
        Node *tmpnext = tmp->next;
        while (tmp != tail)
        {
            delete tmp;
            tmp = tmpnext;
            tmpnext = tmp->next;
        }
        delete head;
        delete tail;
    }
    //拷贝赋值
    VlyfList &operator=(const VlyfList &l)
    {
        if (*this == l)
            return *this;
        else
        {
            for (auto it = this->begin(); it != this->end(); ++it)
                push_back(*it);
        }
        return *this;
    }
    //==
    bool operator==(const VlyfList &l)
    {
        return head == l.head && tail == l.tail && theSize == l.theSize;
    }
    //头插
    void push_front(T &x)
    {
        insert(1, x);
    }
    //尾插
    void push_back(T &x)
    {
        insert(size, x);
    }
    //访问第一个元素
    T &front()
    {
        return *(begin());
    }
    const T &front() const
    {
        return *(begin());
    }
    //访问最后一个元素
    T &back()
    {
        return *(--end());
    }
    const T &back() const
    {
        return *(--end());
    }
    //头删
    void push_back()
    {
        Node *p = tail->prev;
        p->prev->next = tail;
        tail->prev = p->pre;
        delete p;
        theSize--;
    }
    //尾删
    void push_front()
    {
        Node *p = head->next;
        p->next->prev = head;
        head->next = p->next;
        delete p;
        theSize--;
    }
    //删第i个节点
    void deleteI(size_t i)
    {
        Node *p = head;
        for (int i = 0; i < theSize; i++)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
    }
    //第一个节点迭代器
    iterator begin()
    {
        return iteretor(head->next);
    }
    //tail的迭代器
    iterator end()
    {
        return iteretor(tail);
    }
    //向第i个位置插入节点i>0,返回新节点的迭代器
    iteretor insert(size_t i, T &x)
    {
        Node *p = head;
        for (int i = 0; i < theSize; i++)
            p = p->next;
        Node *newnode = new Node(x, p->prev, p);
        p->prev->next = newnode;
        p->prev = newnode;
        theSize++;
        return iteretor(newnode);
    }
    //链表初始化
    void init()
    {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    size_t size() const { return theSize; }
    bool empty() const { return theSize == 0; }
    //迭代器
    class iteretor
    {
    public:
        iteretor(Node *node = nullptr) : current(node) {}

        //前置++
        iteretor &operator++()
        {
            current = current->next;
            return *this;
        }
        //后置++
        iteretor &operator++(int)
        {
            iteretor tmp = *this;
            ++*this;
            return tmp;
        }
        //前置--
        iteretor &operator--()
        {
            current = current->prev;
            return *this;
        }
        //后置--
        iteretor &operator--(int)
        {
            iteretor tmp = *this;
            --*this;
            return tmp;
        }
        //解引用
        T &operator*() const
        {
            return current->data;
        }
        //==
        bool operator==(const iteretor &it) const
        {
            return current == it.current;
        }
        //!=
        bool operator!=(const iteretor &it) const
        {
            return current != it.current;
        }

    private:
        Node *current; //当前所指数据
    }


private:
    Node *head;
    Node *tail;
    size_t theSize;
}
} // namespace vlyflist

#endif /* VLYFLIST_H_ */
