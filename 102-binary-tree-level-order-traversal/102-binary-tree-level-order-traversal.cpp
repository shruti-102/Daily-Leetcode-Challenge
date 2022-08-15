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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        if(root->left==NULL && root->right==NULL) {
            res.push_back({root->val});
            return res;
        }
        vector<int> temp;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            
            while(len--)
            {
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
               if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};