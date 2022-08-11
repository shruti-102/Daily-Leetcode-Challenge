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
    vector<int> inorder;
    void helper(TreeNode* root)
    {
        if(root==NULL)  return;
        helper(root->left);
        inorder.push_back(root->val);
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        vector<int> temp=inorder;
        sort(temp.begin(),temp.end());
        
        for(int i=1;i<inorder.size();i++)
        {
            if(inorder[i]==inorder[i-1]) return false;
        }
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]!=temp[i]) return false;
        }
        return true;
    }
};