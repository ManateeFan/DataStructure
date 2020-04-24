/*****BinarySearchTree*****/
//根节点左边的数据比根节点小，右边比根节点大，子树也一样
#include <iostream>
#include <stack>

using namespace std;

class BinarySearchTree {
 private:
  int data;
  BinarySearchTree* left;
  BinarySearchTree* right;

 public:
  BinarySearchTree(int x) : data(x), left(nullptr), right(nullptr) {}
  //插入
  void Insert(BinarySearchTree* root, int x) {
    if (root->data < x)  //根节点的data<x,则插入右子树
    {
      if (root->right == nullptr)
        root->right = new BinarySearchTree(x);
      else
        Insert(root->right, x);
    } else {
      if (root->left == nullptr)
        root->left = new BinarySearchTree(x);
      else
        Insert(root->left, x);
    }
  }
  //前序遍历
  void PreOrder(BinarySearchTree* root) {
    stack<BinarySearchTree*> s;
    BinarySearchTree* p = root;
    while (p || !s.empty()) {
      while (p) {
        visit(p);
        s.push(p);
        p = p->left;
      }
      if (!s.empty()) {
        p = s.top();
        s.pop();
        p = p->right;
      }
    }
  }
  //中序遍历
  void InOrder(BinarySearchTree* root) {
    stack<BinarySearchTree*> s;
    BinarySearchTree* p = root;
    while (p || !s.empty()) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      if (!s.empty()) {
        p = s.top();
        visit(p);
        s.pop();
        p = p->right;
      }
    }
  }
  //访问数据
  void visit(BinarySearchTree* root) { cout << root->data << " "; }

  void Delete(BinarySearchTree* root, int i) {
    if (!root) return;
    BinarySearchTree* p;
    if (i < root->data) {
      root = root->left;
      while (i != root->data) {
        p = root;
        root = root->left;
      }
      if (root->right == nullptr) {
        p->left = root->left;
        delete root;
      } else {
        root = root->right;
        while (root->left) root = root->left;
        p->left = root;
        root->left = p->left->left;
        root->right = p->left->right;
      }

    } else if (i > root->data) {
      root = root->right;
      while (i != root->data) {
        p = root;
        root = root->left;
      }
      if (root->right == nullptr) {
        p->left = root->left;
        delete root;
      } else {
        root = root->right;
        while (root->left) root = root->left;
        p->left = root;
        root->left = p->left->left;
        root->right = p->left->right;
      }
    } else {
      delete root;
    }
  }
};
int main() {
  int data[8] = {6, 3, 5, 1, 9, 10, 22, 33};
  BinarySearchTree* root = new BinarySearchTree(6);

  for (int i = 1; i < 8; i++) root->Insert(root, data[i]);
  cout << "中序遍历为：";
  root->InOrder(root);
  cout << endl;
  cout << "前序遍历为：";
  root->PreOrder(root);
  return 0;
}
