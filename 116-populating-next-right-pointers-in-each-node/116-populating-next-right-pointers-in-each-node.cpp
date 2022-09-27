/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        
        queue<Node*> q;
        q.push(root);
        //root->next=NULL;
        vector<Node*> temp;
        while(!q.empty()){
            int len=q.size();
            
            while(len--){
                Node* node=q.front();
                temp.push_back(node);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            for(int i=0;i<temp.size();i++){
                if(i==temp.size()-1) {
                    temp[i]->next=NULL;
                    break;
                }
                temp[i]->next=temp[i+1];
            }
            temp.clear();
        }
        return root;
    }
};