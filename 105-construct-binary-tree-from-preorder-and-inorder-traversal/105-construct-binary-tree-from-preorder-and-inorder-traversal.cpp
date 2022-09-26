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
    TreeNode* solve(vector<int>& preorder,int &pre,vector<int>& inorder,int s,int e){
        if(s>e) return NULL;
        int i=s;
        while(inorder[i]!=preorder[pre]) i++;
        pre++;
        
        TreeNode* newnode=new TreeNode(preorder[pre-1]);
        newnode->left=solve(preorder,pre,inorder,s,i-1);
        newnode->right=solve(preorder,pre,inorder,i+1,e);
        return newnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre=0;
        return solve(preorder,pre,inorder,0,inorder.size()-1);
    }
};