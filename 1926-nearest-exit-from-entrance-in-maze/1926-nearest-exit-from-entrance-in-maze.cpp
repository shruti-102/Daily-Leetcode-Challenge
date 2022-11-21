class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int level=0;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int levellen=q.size();
            while(levellen--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
               // maze[i][j]='+';
                for(int k=0;k<4;k++)
                {
                    int r=i+dir[k][0];
                    int c=j+dir[k][1];
                    if(r<n && r>=0 && c<m && c>=0 && maze[r][c]=='.')
                    {
                        if(r==0 || r==n-1 || c==0 || c==m-1)
                            return level+1;
                        q.push({r,c});
                        maze[r][c]='+';
                    }
                }
            }
            level++;
        }
        return -1;
    }
};