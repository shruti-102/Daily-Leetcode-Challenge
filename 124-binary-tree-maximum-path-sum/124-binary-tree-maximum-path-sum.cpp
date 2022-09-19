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
    int maxsum=INT_MIN;
    
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        
        int a=max(solve(root->left),0);
        int b=max(solve(root->right),0);
        
        int c=root->val+a+b;
        maxsum=max(maxsum,c);
        return root->val+max(a,b);
    }
    int maxPathSum(TreeNode* root) {
        int a=solve(root);
        return maxsum;
    }
};