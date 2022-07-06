class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int targetrow=n-1;
        for(int i=0;i<n;i++)
        {
            if(target==matrix[i][0]) return true;
            
            if(target<matrix[i][0]){
                targetrow=i-1;
                break;
            }
        }
        
        if(targetrow==-1) return false;
        
        for(int j=0;j<m;j++)
        {
            if(matrix[targetrow][j]==target) return true;
        }
        return false;
    }
};