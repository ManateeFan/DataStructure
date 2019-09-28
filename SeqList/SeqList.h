#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
template <typename T>
class SeqList //线性表类
{
public:
    SeqList(int size = 10);         //初始化
    ~SeqList();                     //删除线性表
    void ClearList();               //清空线性表
    bool ListEmpty();               //判空
    int ListLength();               //获取长度
    bool GetElem(int i, T *e);      //取出线性表第i个元素
    int LocateElem(T *e);           //定位元素
    bool PriorElem(T *cur, T *pre); //获取指定元素前驱
    bool NextElem(T *cur, T *next); //获取指定元素后继
    void ListTraverse();            //遍历线性表
    bool ListInsert(int i, T *e);   //在第i个位置插入元素(0<i<length+1)
    bool ListDelete(int i, T *e);   //删除第i个位置的元素

private:
    T *data;     //数据
    int _size;   //容量
    int _length; //大小
};

#endif // SEQLIST_H_INCLUDED
