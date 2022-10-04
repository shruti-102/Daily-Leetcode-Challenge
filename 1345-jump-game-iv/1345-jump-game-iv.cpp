class Solution {
public:
    int solve(vector<int>& arr,int i,unordered_map<int,vector<int>>& mp,vector<int>& visited){
        int n=arr.size();
        queue<int> q;
        q.push(0);
        visited[0]=1;
        int level=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                
                int indx=q.front();
                q.pop();
                
                if(indx==n-1) return level;
                
                if(indx-1>=0 && visited[indx-1]==0) {
                    q.push(indx-1);
                    visited[indx-1]=1;
                }
                if(indx+1<n && visited[indx+1]==0){
                    q.push(indx+1);
                    visited[indx+1]=1;
                }
                int val=arr[indx];
                if(mp.find(val) != mp.end()){
                    int sz=mp[val].size();
                    for(int i=sz-1;i>=0;i--){
                        if(visited[mp[val][i]]==0){
                            q.push(mp[val][i]);
                            visited[mp[val][i]]=1;
                        }
                    }
                }
                mp.erase(arr[indx]);
            }
            level++;
        }
         return 0;
    }
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
            
        }
        vector<int> visited(n,0);
        return solve(arr,0,mp,visited);
    }
};