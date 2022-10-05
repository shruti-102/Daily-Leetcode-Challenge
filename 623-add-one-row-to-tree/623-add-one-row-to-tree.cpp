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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int level=1;
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* prev=root;
        
        while(!q.empty()){
            int len=q.size();
            while(len--){
                TreeNode* node=q.front();
                //prev=node;
                
                if(level==depth-1){
                    int s=q.size();
                    while(s--){
                        //cout<<"##";
                       TreeNode* n= q.front();
                        cout<<n->val;
                        q.pop();
                        TreeNode* l=n->left;
                        TreeNode* r=n->right;
                        TreeNode* x=new TreeNode(val);
                        TreeNode* y=new TreeNode(val);
                        n->left=x;
                        n->right=y;
                        x->left=l;
                        x->right=NULL;
                        y->right=r; 
                        y->left=NULL;
                    }
                    //cout<<"!";
                    return root;
                }
                else{
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                q.pop();
            }
           level+=1; 
        }
        return root;
    }
};