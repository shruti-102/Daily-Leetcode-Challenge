class Solution {
public:
    int ans = 0;
    
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
    

    void preorder(TreeNode* node, int cnt) {
       
        if (node == NULL) return;
        
        // e.g. 1 << 0 = 1 
        // e.g. 1 << 1 = 0b10 
        // e.g. 1 << 2 = 0b100 
        
        // x ^ x = 0 
       
        //digits 1 to 9 hoti h
        //to hm 1<<node->val kr k 1 to 9 le rhe h or us digit k value ko set kr rhe h
        
        // 9 8 7 6 5 4 3 2 1 0
        // 0 0 0 0 0 0 0 1 0 0   2
        // 0 0 0 0 0 0 1 1 0 0   3
        // 0 0 0 0 0 0 0 1 0 0   3
        
        //each tym hm xor krege jisse agr even occurence h to 0 bn jae
    
        cnt ^= (1 << node->val);
    
        if (!node->left && !node->right) {
            
            // if the result is 0, that means we have at most one digit that has an odd frequncy 
            // hence, add one to ans
			// alternatively, you can use __builtin_popcount(cnt) <= 1 to check
            ans += (cnt & (cnt - 1)) == 0;
        }
        // preorder traversal step 3: traverse the left node
        preorder(node->left, cnt);
        // preorder traversal step 4: traverse the right node
        preorder(node->right, cnt);
    }
};