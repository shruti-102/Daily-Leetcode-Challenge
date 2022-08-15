/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int d=INT_MIN;
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int h1=height(root->left);
        int h2=height(root->right);
        
        d=max(d,h1+h2);
        return max(h1,h2)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        height(root);
        
        return d;
    }
};