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
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int h1=height(root->left);
        int h2=height(root->right);
        
        if(abs(h1-h2)>1) return -1;
        if(h1==-1) return -1;
        if(h2==-1) return -1;
        
        return max(h1,h2)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(height(root)==-1) return false;
        return true;
    }
};