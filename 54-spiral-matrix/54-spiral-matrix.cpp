class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=0,rowe=matrix.size()-1;
        int cols=0,cole=matrix[0].size()-1;
        
        vector<int> ans;
        
        while(rows<=rowe && cols<=cole){
            for(int i=cols;i<=cole;i++)
            {
                ans.push_back(matrix[rows][i]);
            }
            rows++;
            for(int i=rows;i<=rowe;i++)
            {
                ans.push_back(matrix[i][cole]);
            }
            cole--;
            if(cols > cole || rows > rowe) break;
            for(int i=cole;i>=cols;i--)
            {
                ans.push_back(matrix[rowe][i]);
            }
            rowe--;
            for(int i=rowe;i>=rows;i--)
            {
                ans.push_back(matrix[i][cols]);
            }
            cols++;
        }
        return ans;
    }
};