class Solution {
public:
    
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        if(i>=n || j>=m || i<0 || j<0) return 0;
        if(grid[i][j]==0) return 0;
        if(grid[i][j]==2) return 0;
        
        grid[i][j]=2;
        
        return 1+dfs(i+1,j,n,m,grid)+dfs(i,j+1,n,m,grid)+dfs(i-1,j,n,m,grid)+dfs(i,j-1,n,m,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int area,maxarea=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   area= dfs(i,j,n,m,grid);
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};