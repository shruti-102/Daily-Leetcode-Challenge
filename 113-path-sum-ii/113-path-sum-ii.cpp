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
    vector<vector<int>> ans;
    void solve(TreeNode* root,int targetsum,vector<int>& path){
        
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && targetsum==root->val){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        
        solve(root->left,targetsum-root->val,path);
        solve(root->right,targetsum-root->val,path);
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        vector<int> path;
        
        solve(root,targetsum,path);
        return ans;
    }
};