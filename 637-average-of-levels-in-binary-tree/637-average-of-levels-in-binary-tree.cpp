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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        if(root==NULL) return ans;
        
        q.push(root);
        
        while(!q.empty())
        {
            int len=q.size();
            int temp=len;
            double sum=0;
            while(len--)
            {
                TreeNode* node=q.front();
                int val=node->val;
                q.pop();
                sum+=val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(sum/temp);
        }
        
        return ans;
    }
};