class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& board){
        board[i][j]='$';
        if(i+1<n && board[i+1][j]=='O') dfs(i+1,j,n,m,board);
        if(i-1>=0 && board[i-1][j]=='O') dfs(i-1,j,n,m,board);
        if(j+1<m && board[i][j+1]=='O') dfs(i,j+1,n,m,board);
        if(j-1>=0 && board[i][j-1]=='O') dfs(i,j-1,n,m,board);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(i,0,n,m,board);
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O')
                dfs(i,m-1,n,m,board);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O')
                dfs(0,j,n,m,board);
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O')
                dfs(n-1,j,n,m,board);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(board[i][j]=='$') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
        return;
    }
};