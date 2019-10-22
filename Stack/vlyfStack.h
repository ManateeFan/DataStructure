#ifndef _VLYFDEQUE_H
#define _VLYFDEQUE_H

template <typename T>
class vlyfStack
{
public:
    vlyfStack(int _capacity = 10) : size(0), capacity(_capacity), data(new T[capacity]) {}
    ~vlyfStack() { delete[] data; }

    void push(const T& x)
    {
        checkCapacity();
        data[size++] = x;
    }

    T& pop()
    {

        return data[--size];
    }

    T& top()
    {
        return data[size - 1];
    }

    size_t size()
    {
        return size;
    }

    bool empty()
    {
        return size == 0;
    }

    void print()
    {
        for (auto &i : data)
            cout << i << " ";
    }
	
    void chekcCapacity()
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
    }

private:
    size_t size;     //数据个数
    size_t capacity; //容量
    T *data;         //数据指针
}

#endif
