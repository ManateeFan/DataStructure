//������ȫ�����������ȶ���
#include<iostream>

using namespace std;

template<typename T>
class MaxPQ
{
private:
	// ����pq[1...N]��pq[0]δʹ��
	int N;	
	int capacity;
	// ���ڶѵ���ȫ������
	T* pq;
public:
	MaxPQ(int maxN) :N(0), capacity(maxN), pq(new T[maxN + 1]) {}
	MaxPQ(T data[], int size) :N(size), capacity(size), pq(new T[size + 1])
	{
		for (size_t i = 0; i < size; i++)
		{
			pq[i + 1] = data[i];
		}
		// �ϸ�
		for (size_t i = N; i > 1; i--)
			Swim(i);
	}
	~MaxPQ() { delete[]pq; }

	// ����Ԫ�ص����һ��λ�ã����ϸ�
	void Insert(const T& x)
	{
		if (!Full())
		{
			pq[++N] = x;
			Swim(N);
		}
	}

	// �������Ԫ��
	T& GetMax()
	{
		if(!Empty())
			return pq[1];
	}

	// ɾ�����������Ԫ��
	T DelMax()
	{
		if (!Empty())
		{
			T max = pq[1];
			swap(pq[1], pq[N--]);
			Sink(1);
			return max;
		}
	}

	// empty
	bool Empty() { return 0 == N; }

	// full
	bool Full() { return N == capacity; }

	//Ԫ�ظ���
	int Size() { return N; }

private:
	// �ϸ�����
	void Swim(size_t k)
	{
		while (pq[k / 2] < pq[k] && k > 1)
		{
			swap(pq[k], pq[k / 2]);
			k /= 2;
		}
	}

	// �³�����
	void Sink(size_t k)
	{
		while (N >= k * 2)
		{
			//����Ů�±�
			size_t j = k * 2;
			if (j < N && pq[j] < pq[j + 1]) j++;
			if (pq[k] >= pq[j]) break;
			swap(pq[k], pq[j]);
			k = j;
		}
	}
};


int main()
{

	MaxPQ<int> test(5);

	test.Insert(1);
	test.Insert(2);
	test.Insert(3);
	test.DelMax();
	cout << test.GetMax();

	return 0;
}



