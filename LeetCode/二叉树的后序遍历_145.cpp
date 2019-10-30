/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return v;
    }
    
    void postOrder(TreeNode *root)
    {
        if(root)
        {
            postOrder(root->left);
            postOrder(root->right);    
            v.push_back(root->val);
        }
    }
};  