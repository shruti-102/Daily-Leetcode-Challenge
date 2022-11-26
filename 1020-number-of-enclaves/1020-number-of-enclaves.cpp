class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
       if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        if (grid[i][j]==0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(i-1,j,n,m,grid) 
                 + dfs(i+1,j,n,m,grid)
                 + dfs(i,j+1,n,m,grid)
                 + dfs(i,j-1,n,m,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
                {
                   c+=dfs(i,j,n,m,grid);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        //c=0;
        int eclaves=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    eclaves+=dfs(i,j,n,m,grid);
                }
            }
        }
        return eclaves;
    }
};