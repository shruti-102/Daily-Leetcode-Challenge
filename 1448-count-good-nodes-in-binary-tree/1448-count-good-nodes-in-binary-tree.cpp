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
    int ans=0;
    void solve(TreeNode* root,int max_val)
    {
        if(root==NULL) return;
        
        if(root->val>=max_val)
        {
            ans++;
            max_val=root->val;
        }
        
        solve(root->left,max_val);
        solve(root->right,max_val);
    }
    int goodNodes(TreeNode* root) {
          solve(root,INT_MIN); 
        return ans;
    }
};