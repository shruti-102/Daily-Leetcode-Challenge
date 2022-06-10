class Solution {
public:
    bool possible(int row,int col,vector<string>& board,int n)
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
    void solve(int n,vector<string>& board,vector<vector<string>>& ans,int col)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        //traversing row-wise
        for(int row=0;row<n;row++)
        {
            if(possible(row,col,board,n))
            {
                board[row][col]='Q';
                solve(n,board,ans,col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        
        //n=4
        //s=. . . .
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
       // board= . . . .
      //         . . . .
      //         . . . .
      //         . . . .
        // putting queen colomn wise (0->n)
        solve(n,board,ans,0);
        return ans;
    }
};