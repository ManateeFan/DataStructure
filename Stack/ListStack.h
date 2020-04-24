#pragma once
template <typename T>
class Node;
template <typename T>
class ListStack {
 public:
  ListStack();
  ~ListStack();
  bool isEmpty();
  int size();
  void push(T t);
  T pop();
  T top();

 private:
  Node<T>* phead;
  int count;
};
