class Solution {
public:
    
    bool dfs(int node,vector<int>& visited,vector<int>& dfsvisited,vector<int> adjlist[]){
        visited[node]=1;
        dfsvisited[node]=1;
        
        for(int i=0;i<adjlist[node].size();i++){
            int it=adjlist[node][i];
            if(!visited[it]){
                if(dfs(it,visited,dfsvisited,adjlist)) return true;
            }
            if(dfsvisited[it]) return true;
        }
        dfsvisited[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> visited(numCourses,0);
        vector<int> adjlist[numCourses];
        vector<int> dfsvisited(numCourses,0);
        
        for(int i=0;i<pre.size();i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adjlist[v].push_back(u);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,dfsvisited,adjlist)) return false;
            }
            
        }
        return true;
        
    }
};

