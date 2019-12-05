#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct BinaryTreeNode
{
    int key;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int k) : left(nullptr), right(nullptr){}
};

BinaryTreeNode* ReConstructBinaryTree(vector<int> &prev, vector<int>& in)
{
    auto rootIt = find(in.begin(), in.end(), prev[0]);
    BinaryTreeNode *root = new BinaryTreeNode(*rootIt);
    int leftLength = rootIt - in.begin();
    int rightLength = in.end() - rootIt - 1;


    root->left = ReConstructBinaryTree()
}