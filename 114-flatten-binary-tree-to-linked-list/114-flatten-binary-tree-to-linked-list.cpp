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
    //time o(n)
    //space o(n)
//     TreeNode* prev=NULL;
//     void flatten(TreeNode* root) {
//         if(root==NULL) return;
        
//         flatten(root->right);
//         flatten(root->left);
        
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
//     }
    stack<TreeNode*> st;
        void flatten(TreeNode* root) {
            if(root==NULL) return;
            
            st.push(root);
            //TreeNode* cur;
            while(!st.empty())
            {
                TreeNode* cur=st.top();
                st.pop();
                
                if(cur->right) st.push(cur->right);
                if(cur->left) st.push(cur->left);
                
                if(!st.empty()) cur->right=st.top();
                cur->left=NULL;
            }
        }
};