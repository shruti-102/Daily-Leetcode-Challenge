class Solution {
public:
    
    bool possible(vector<string>& board,int row,int col,int n)
    {
        int tempr=row;
        int tempc=col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=tempr;
        col=tempc;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=tempc;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<string> &board,vector<vector<string>> &ans,int n,int c)
    {
        if(c==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int r=0;r<n;r++)
        {
            if(possible(board,r,c,n))
            {
                board[r][c]='Q';
                solve(board,ans,n,c+1);
                board[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        solve(board,ans,n,0);
        return ans;
    }
};