#pragma once

#include <stdexcept>
template <typename Key>
struct Node {
  using pointer = Node<Key>*;
  Key key;
  Node* prev;
  Node* next;
  Node(Key const& k) : key(k), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkList {
 private:
  typename Node<T>::pointer head;

 public:
  LinkList() : head(nullptr){};

  // 返回第一个值为k的节点地址
  typename Node<T>::pointer Search(T const&) const;

  // 头插
  void Insert(typename Node<T>::pointer const& x);

  void Delete(typename Node<T>::pointer const& x);
};

template <typename T>
inline typename Node<T>::pointer LinkList<T>::Search(T const& k) const {
  if (!head) throw std::out_of_range("LinkList is empty");
  typename Node<T>::pointer p = head;
  while (p->key != k) {
    p = p->next;
  }
  return p;
}

template <typename T>
inline void LinkList<T>::Insert(typename Node<T>::pointer const& x) {
  x.next = head;
  if (head) head->prev = x;
  head = x;
  x->prev = nullptr;
}

template <typename T>
inline void LinkList<T>::Delete(typename Node<T>::pointer const& x) {
  if (!x->prev)
    x->prev->next = x->next;
  else
    head->next = x->next;
  if (!x->next) x->next->prev = x->prev;
  delete x;
}