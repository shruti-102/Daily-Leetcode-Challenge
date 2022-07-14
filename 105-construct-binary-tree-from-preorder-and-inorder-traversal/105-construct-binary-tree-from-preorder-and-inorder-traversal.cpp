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
    TreeNode* solve(vector<int>& inorder,vector<int>& preorder,unordered_map<int,int>& mpinorder,int instart,int inend,int prestart,int preend)
    {
        //base case for index in range
        if(prestart>preend || instart>inend) return NULL;
        
        //making newnode with preorder
        TreeNode* newnode=new TreeNode(preorder[prestart]);
        
        //taking root node pinter in inorder
        int inroot=mpinorder[newnode->val];
        
        //calculating number of nodes in the left subtree
        int x=inroot-instart;
        
        //for left subtree
        //instart=0
        //inend=rootpointer(inroot)-1 
        //prestart=prestart+1
        //preend=prestart+x
        
        newnode->left=solve(inorder,preorder,mpinorder,instart,inroot-1,prestart+1,prestart+x);
        
        //for right subtree
        //instart=rootpointer(inroot)+1
        //inend=inend
        //prestart=prestart+x+1 (preveious strt + no of nodes + 1)
        //preend=preend
        newnode->right=solve(inorder,preorder,mpinorder,inroot+1,inend,prestart+x+1,preend);
        
        return newnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpinorder;
        for(int i=0;i<inorder.size();i++)
        {
            mpinorder[inorder[i]]=i;
        }
        
        return solve(inorder,preorder,mpinorder,0,inorder.size()-1,0,preorder.size()-1);
    }
};