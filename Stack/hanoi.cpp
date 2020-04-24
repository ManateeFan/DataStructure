//============================================================================
// Name        : learn.cpp
// Author      : vlyf
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class Stack {
 public:
  Stack() : _capacity(100), _size(0), _data(new T[_capacity]) {}

  ~Stack() {
    if (_data) {
      delete[] _data;
    }
  }

 public:
  void Push(const T& x) {
    _CheckCapacity();
    _data[_size++] = x;
  }

  T Pop() {
    --_size;
    return _data[_size - 1];
  }

  T Top() { return _data[_size - 1]; }

  size_t Size() { return _size; }

  bool Empty() { return _size == 0; }

  void Print() {
    for (size_t i = 0; i < _size; ++i) {
      cout << _data[i] << "->";
    }
  }

 private:
  void _CheckCapacity() {
    if (_capacity == _size) {
      T* tmp = new T[_capacity];
      for (size_t i = 0; i < _size; ++i) {
        tmp[i] = _data[i];
      }
      _capacity *= 2;

      delete[] _data;
      _data = tmp;
    }
  }

 private:
  size_t _size;      // 数据的个数
  size_t _capacity;  // 容量

  T* _data;  // 指向数据的指针
};

struct Node {
  int n;
  char a, b, c;
  Node() = default;
  Node(int _n, char _a, char _b, char _c) : n(_n), a(_a), b(_b), c(_c) {}
  Node operator=(const Node& node) {
    n = node.n;
    a = node.a;
    b = node.b;
    c = node.c;
  }
};
int main() {
  int n;
  cin >> n;
  Node node(n, 'a', 'b', 'c');
  Stack<Node> s;
  s.Push(node);
  while (!s.Empty()) {
    node = s.Top();
    s.Pop();
    if (1 == node.n)
      printf("%c -> %c\n", node.a, node.c);
    else {
      s.Push(Node(node.n - 1, node.b, node.a, node.c));
      s.Push(Node(1, node.a, node.b, node.c));
      s.Push(Node(node.n - 1, node.a, node.c, node.b));
    }
  }

  return 0;
}
