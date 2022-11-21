class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int col=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        if(color==col)
            return image;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> dir{{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int len=q.size();
            int r=q.front().first;
                int c=q.front().second;
                q.pop();
            while(len--){
                
                for(int i=0;i<4;i++){
                    int nr=r+dir[i][0];
                    int nc=c+dir[i][1];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==col){
                        image[nr][nc]=color;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return image;
    }
};