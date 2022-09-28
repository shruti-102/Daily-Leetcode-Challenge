class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuel=0,dist=0,n=gas.size();
        for(int i=0;i<n;i++){
            fuel+=gas[i];
            dist+=cost[i];
        }
        
        if(fuel<dist) return -1;
        int ans=0,remain=0,total=0;
        
        for(int i=0;i<n;i++){
            remain+=gas[i]-cost[i];
            if(remain<0){
                ans=i+1;
                remain=0;
            }
            total+=gas[i]-cost[i];
        }
        return ans;
    }
};