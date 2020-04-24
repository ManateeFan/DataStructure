#include <iostream>

#include "Queue.hpp"

using namespace std;

int main() {
  Queue<int, 4> queue;
  cout << "Queuq is empty: " << queue.Empty() << endl;
  cout << "EnQueuq 1 2 3 4" << endl;
  queue.EnQueue(1);
  queue.EnQueue(2);
  queue.EnQueue(3);
  queue.EnQueue(4);
  cout << "queue.Length: " << queue.Length() << endl;
  cout << "Queue is full: " << queue.Full() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "queue is empty: " << queue.Empty() << endl;

  cout << "--------------------------------------" << endl;

  cout << "Deque is empty: " << queue.Empty() << endl;
  cout << "EnDeque 5 6 7 8 9" << endl;
  queue.EnQueue(5);
  queue.EnQueue(6);
  queue.EnQueue(7);
  queue.EnQueue(8);
  cout << "queue.Length: " << queue.Length() << endl;
  cout << "Queue is full: " << queue.Full() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "DeQueue: " << queue.DeQueue() << endl;
  cout << "queue is empty: " << queue.Empty() << endl;

  return 0;
}