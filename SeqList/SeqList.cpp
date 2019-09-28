#include <iostream>
#include "seqlist.h"
using namespace std;
SeqList::SeqList(int size)
{
    this->_size = size;
    this->_length = 0;
    this->data = new int[_size];
}
SeqList::~SeqList()
{
    delete[] data;
    data = NULL;
}
void SeqList::ClearList()
{
    this->_length = 0;
}
bool SeqList::ListEmpty()
{
    if (this->_length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int SeqList::ListLength()
{
    return this->_length;
}
bool SeqList::GetElem(int i, int *e)
{
    if (i < 0 || i > this->_length)
    {
        return false;
    }
    else
    {
        *e = data[i - 1];
        return true;
    }
}
int SeqList::LocateElem(int *e)
{
    for (int i = 0; i < this->_length; i++)
    {
        if (*e == data[i])
            return i;
    }
    return -1;
}
bool SeqList::PriorElem(int *cur, int *pre)
{
    int temp = LocateElem(cur);
    if (-1 == temp)
    {
        return false;
    }
    else
    {
        if (0 == temp)
        {
            return false;
        }
        else
        {
            *pre = data[temp - 1];
            return true;
        }
    }
}
bool SeqList::NextElem(int *cur, int *next)
{
    int temp = LocateElem(cur);
    if (-1 == temp || temp == _length - 1)
    {
        return false;
    }
    else
    {
        *next = data[temp + 1];
        return true;
    }
}
void SeqList::ListTraverse()
{
    for (int i = 0; i < _length; i++)
    {
        cout << data[i] << endl;
    }
}
bool SeqList::ListInsert(int i, int *e)
{
    if (i < 1 || i > _size)
    {
        return false;
    }
    int k;
    for (k = _length - 1; k >= i - 1; k--)
    {
        data[k + 1] = data[k];
    }
    data[k + 1] = *e;
    _length++;
    return true;
}
bool SeqList::ListDelete(int i, int *e)
{
    if (i < 1 || i > _length)
    {
        return false;
    }
    *e = data[i - 1];
    if (i != _length)
    {
        for (int k = i; i < _length; k++)
        {
            data[k - 1] = data[k];
        }
        _length--;
        return true;
    }
    else
    {
        _length--;
        return true;
    }
}

int main(void)
{
    return 0;
}
