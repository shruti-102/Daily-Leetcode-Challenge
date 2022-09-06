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
    bool containone(TreeNode* root)
    {
        if(root==NULL) return false;
        
        bool leftone=containone(root->left);
        bool rightone=containone(root->right);
        
        if(leftone==false) root->left=NULL;
        if(rightone==false) root->right=NULL;
        
        return root->val==1 || leftone || rightone;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(containone(root)) return root;
        return NULL;
    }
};