#pragma once
#include <stdexcept>

enum class Color { RED, BLACK };

template <typename Key, typename Value>
class RedBlackBST {
 private:
  class Node {
   public:
    Node(Key const& k, Value const& v)
        : key(k),
          value(v),
          left(nullptr),
          right(nullptr),
          N(1),
          color(Color::BLACK) {}
    Key key;
    Value value;
    Node* left;
    Node* right;
    Color color;
    int N;
  };
  Node* root;

 public:
  RedBlackBST() : root(nullptr) {}

  // ���ڸ�key����½ڵ㣬�������ڵ�
  void put(Key const& k, Value const& v) {
    root = put(root, k, v);
    root->color = Color::BLACK;
  }

  int size() const {
    if (root)
      return size(root);
    else
      return 0;
  }

  // ������������ü�ֵ
  Key select(int const& i) const { return select(root, i)->key; }
  // ����С�ڸü�ֵ�Ľڵ����
  int rank(Key const& k) { return rank(root, k); }

  Value get(Key const& k) const { return get(root, k); }

 private:
  // �жϽڵ���ɫ�Ƿ�Ϊ��ɫ
  bool isRed(Node const* const& h) const {
    if (!h)
      return false;
    else
      return h->color == Color::RED;
  }

  // ����
  Node* rotateLeft(Node* const& h) {
    Node* x = h->right;
    h->right = x->left;
    x->left = h;
    x->N = h->N;
    x->color = h->color;
    h->color = Color::RED;
    h->N = size(h->left) + size(h->right) + 1;
    return x;
  }

  // ����
  Node* rotateRight(Node* const& h) {
    Node* x = h->left;
    h->left = x->right;
    x->right = h;
    x->N = h->N;
    x->color = h->color;
    h->color = Color::RED;
    h->N = size(h->left) + size(h->right) + 1;
    return x;
  }

  // �Ըýڵ�Ϊ�������Ĵ�С
  int size(Node* h) const {
    if (!h) return 0;
    return h->N;
  }

  // �ڵ�������Ů��Ϊ��ɫ����ת����ɫ
  void flipColors(Node* h) {
    h->color = Color::RED;
    h->left->color = Color::BLACK;
    h->right->color = Color::BLACK;
  }
  Node* put(Node* h, Key const& k, Value const& v) {
    if (!h) return new Node(k, v);
    if (k < h->key) {
      h->left = put(h->left, k, v);
    } else if (k > h->key) {
      h->right = put(h->right, k, v);
    } else {
      h->value = v;
    }

    // �ж��Ƿ���Ҫ��ת

    // �ýڵ�����ŮΪ��ɫ������ŮΪ��ɫ��������
    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);

    // �ýڵ�����ŮΪ��ɫ������Ů������ŮҲΪ��ɫ��������
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);

    // �ýڵ�������Ů��Ϊ��ɫ������ת����ɫ
    if (isRed(h->left) && isRed(h->right)) flipColors(h);

    h->N = size(h->left) + size(h->right) + 1;
    return h;
  }

  Node* select(Node* node, int i) const {
    if (!node) throw std::out_of_range("root is null");

    if (i > size(node))
      return select(node->right, i);
    else if (i < size(node))
      return select(node->left, i);
    else
      return node;
  }

  int rank(Node* const& node, Key const& k) {
    if (!node) return 0;
    if (k < node->key)
      return rank(node->left, k);
    else if (k > node->key)
      return rank(node->right, k);
    else
      return size(node);
  }

  Value get(Node* node, Key const& k) const {
    if (!node)
      throw std::out_of_range("root is null");
    else {
      if (k < node->key)
        get(node->left, k);
      else if (k > node->key)
        get(node->right, k);
      else
        return node->value;
    }
  }
};
