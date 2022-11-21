class Solution {
public:
    vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(i>n || i<0 || j>m || j<0) return;
        if(grid[i][j]=='0' || grid[i][j]=='2') return;
        grid[i][j]='2';
        for(int k=0;k<4;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='1')
                dfs(ni,nj,n,m,grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
};