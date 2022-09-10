class Solution {
public:
    bool solve(int r,int c,vector<vector<char>>& board,string word,int i)
    {
        if(i==word.size()) return true;
        
        if(r>=board.size() || r<0 || c>=board[0].size() || c<0 || board[r][c]!=word[i])
            return false;
        
        board[r][c]='$';
        
        bool status=solve(r+1,c,board,word,i+1) ||
                    solve(r,c+1,board,word,i+1) ||
                    solve(r,c-1,board,word,i+1) ||
                    solve(r-1,c,board,word,i+1);
        
        board[r][c]=word[i];
        return status;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0]) {
                    if(solve(i,j,board,word,0))
                        return true;
                }
            }
        }
        return false;
    }
};