#include <iostream>
#include "Deque.hpp"

using namespace std;

int main()
{
	Deque<int, 4> deque;
	cout << "Deque is empty: " << deque.Empty() << endl;
	cout << "EnDeque 1 2 3 4" << endl;
	deque.EnDeque(1);
	deque.EnDeque(2);
	deque.EnDeque(3);
	deque.EnDeque(4);
	cout << "Deque is full: " << deque.Full() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "Deque is empty: " << deque.Empty() << endl;

	cout << "--------------------------------------" << endl;

	cout << "Deque is empty: " << deque.Empty() << endl;
	cout << "EnDeque 5 6 7 8 9" << endl;
	deque.EnDeque(5);
	deque.EnDeque(6);
	deque.EnDeque(7);
	deque.EnDeque(8);
	cout << "Deque is full: " << deque.Full() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "DeDeque: " << deque.DeDeque() << endl;
	cout << "Deque is empty: " << deque.Empty() << endl;

	return 0;
}