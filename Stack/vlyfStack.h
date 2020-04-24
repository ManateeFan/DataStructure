#pragma once

#include <iostream>
#include <stdexcept>

namespace vlyf {
template <typename T, int MAXSIZE>
class Stack {
 private:
  T elems[MAXSIZE];
  int numElems;

 public:
  vlyfStack() : numElems(0) {}
  void push(T const &);
  void pop();
  T top() const;
  bool empty() const { return numElems == 0; }
  int size() const { return numElems; }
};

template <T, MAXSIZE>
inline void Stack<T, MAXSIZE>::push(T const &elem) {
  if (numElems == MAXSIZE)
    throw std::out_of_range("Exception: Stack<>::push(): stack is full");
  data[numElems++] = elem;
}

template <T, MAXSIZE>
inline void Stack<T, MAXSIZE>::pop() {
  if (numElems == 0)
    throw std::out_of_range("Exception: Stack<>::push(): stack is empty");
  numElems--;
}

template <T, MAXSIZE>
inline T Stack<T, MAXSIZE>::top() {
  if (numElems == 0)
    throw std::out_of_range("Exception: Stack<>::push(): stack is empty");
  return data[size - 1];
}

template <T, MAXSIZE>
inline int Stack<T, MAXSIZE>::size() const {
  return numElems;
}

bool empty() { return numElems == 0; }
}  // namespace vlyf