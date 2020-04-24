#include "RedBlackBST.h"

#include <iostream>

using namespace std;

int main() {
  RedBlackBST<int, string> tree;
  tree.put(1, "lyf");
  tree.put(2, "vlyf");
  tree.put(3, "13333");
  return 0;
}