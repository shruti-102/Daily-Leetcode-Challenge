class Solution {
public:
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=n || i<0 || j>=m || j<0) return 0;
        if(grid[i][j]==0 || grid[i][j]==2) return 0;
        grid[i][j]=2;
        return 1+dfs(i+1,j,n,m,grid)+dfs(i-1,j,n,m,grid)+dfs(i,j+1,n,m,grid)+dfs(i,j-1,n,m,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxarea=0;//area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    //area=;
                    maxarea=max(maxarea,dfs(i,j,n,m,grid));
                }
            }
        }
        return maxarea;
    }
};