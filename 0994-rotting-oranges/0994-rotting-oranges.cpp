class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        queue<pair<int,int>> q;
        bool mark=false;
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        
      if(q.empty()){
            if(fresh==0)
                return 0;
           else
               return -1;
        }
        
        while(!q.empty()){
            int len=q.size();
            count++;
            while(len--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++){
                    int ni=i+dir[k][0];
                    int nj=j+dir[k][1];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        fresh--;
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
        }
        if(fresh>0) return -1;
        return count-1;
    }
};