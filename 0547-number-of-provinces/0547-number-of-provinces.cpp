class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>& visited,int n){
        if(visited[i]==true) return;
        visited[i]=true;
        for(int k=0;k<n;k++){
            if(visited[k]==false && isConnected[i][k]==1){
                dfs(k,isConnected,visited,n);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                count++;
                dfs(i,isConnected,visited,n);
            }
        }
        return count;
    }
};