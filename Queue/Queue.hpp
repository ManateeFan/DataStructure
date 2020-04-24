#pragma once

#include <stdexcept>

template <typename T, int MAXSIZE>
class Queue {
private:
    T elems[MAXSIZE + 1];
    int head;
    int tail;

public:
    Queue()
        : head(0)
        , tail(head)
    {
    }

    void EnQueue(T const&);
    T DeQueue();
    bool Empty() const
    {
        return head == tail;
    }
    bool Full() const
    {
        return (head == tail + 1) || (tail == MAXSIZE && head == 0);
    }
    int Length() const
    {
        if (head < tail)
            return tail - head;
        else
            return MAXSIZE + 1 - (head - tail);
    }
};

template <typename T, int MAXSIZE>
inline void Queue<T, MAXSIZE>::EnQueue(T const& elem)
{
    if (Full())
        throw std::out_of_range("Queue is full");
    if (tail == MAXSIZE) {
        elems[tail] = elem;
        tail = 0;
    } else {
        elems[tail++] = elem;
    }
}

template <typename T, int MAXSIZE>
inline T Queue<T, MAXSIZE>::DeQueue()
{
    if (Empty())
        throw std::out_of_range("Queue is empty");
    if (head == MAXSIZE) {
        T temp = elems[head];
        head = 0;
        return temp;
    } else {
        return elems[head++];
    }
}