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
    vector<vector<int>> res;
    void levelorder(TreeNode* root)
    {
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
             res.push_back(temp);
            temp.clear();
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        levelorder(root);
        vector<int> ans;
        
        if(root==NULL) return ans;
        
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i][0]);
        }
        return ans;
    }
};