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

/*bool cycle_dfs(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(cycle_dfs(it, vis, dfsvis, adj))
                    return true;
            }
            else if(dfsvis[it])
                return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);
        int edges = prerequisites.size();
        vector<int>adj[numCourses];// adj list
        
        for(int i = 0;i<edges;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i])
                if(cycle_dfs(i, vis, dfsvis, adj))
                    return false;
        }
        return true;
    }*/