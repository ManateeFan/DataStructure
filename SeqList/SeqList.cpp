#include <iostream>
#include "seqlist.h"
using namespace std;
template <typename T>
SeqList<T>::SeqList(int size)
{
    this->_size = size;
    this->_length = 0;
    this->data = new T[_size];
};
template <typename T>
SeqList<T>::~SeqList()
{
    delete[] data;
    data = NULL;
};
template <typename T>
void SeqList<T>::ClearList()
{
    this->_length = 0;
};
template <typename T>
bool SeqList<T>::ListEmpty()
{
    if (this->_length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};
template <typename T>
int SeqList<T>::ListLength()
{
    return this->_length;
};
template <typename T>
bool SeqList<T>::GetElem(int i, T *e)
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
};
template <typename T>
int SeqList<T>::LocateElem(T *e)
{
    for (int i = 0; i < this->_length; i++)
    {
        if (*e == data[i])
            return i;
    }
    return -1;
};
template <typename T>
bool SeqList<T>::PriorElem(T *cur, T *pre)
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
};
template <typename T>
bool SeqList<T>::NextElem(T *cur, T *next)
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
};
template <typename T>
void SeqList<T>::ListTraverse()
{
    for (int i = 0; i < _length; i++)
    {
        cout << data[i] << endl;
    }
};
template <typename T>
bool SeqList<T>::ListInsert(int i, T *e)
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
};
template <typename T>
bool SeqList<T>::ListDelete(int i, T *e)
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
};

int main(void)
{
    return 0;
}
