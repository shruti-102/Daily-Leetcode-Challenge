/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root==NULL) return ans;
        q.push(root);
        
        while(!q.empty())
        {
            int len=q.size();
            vector<int> temp;
            while(len--)
            {
                Node* node=q.front();
                temp.push_back(node->val);
                q.pop();
                for(int i=0;i<node->children.size();i++)
                {
                    if(node->children[i]!=NULL) q.push(node->children[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};