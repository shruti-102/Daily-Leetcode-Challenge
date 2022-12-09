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
unordered_map<int,vector<int>> mp;

void makeancestor(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        mp[root->val].push_back(root->val);
        return;
    }
    makeancestor(root->left);
    makeancestor(root->right);
    if(root->left!=NULL){
        vector<int> v1 =mp[root->left->val];
       
        for(int i=0;i<v1.size();i++){
            mp[root->val].push_back(v1[i]);
        }
    }
    if(root->right!=NULL){
        vector<int> v2=mp[root->right->val];
        for(int i=0;i<v2.size();i++){
            mp[root->val].push_back(v2[i]);
        }
    }
    mp[root->val].push_back(root->val);
    return;
    }

    int maxAncestorDiff(TreeNode* root) {
        makeancestor(root);
        int maxval=INT_MIN;

        
        for(auto it:mp){
            int val=it.first;
            vector<int> v {it.second};
            for(int i=0;i<v.size();i++){
                maxval=max(maxval,abs(val-v[i]));
            }
        }
        return maxval;
    }
};