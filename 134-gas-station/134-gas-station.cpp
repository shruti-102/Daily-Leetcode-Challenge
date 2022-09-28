class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ans=0,remain=0,total=0;
        
        for(int i=0;i<n;i++){
            remain+=gas[i]-cost[i];
            if(remain<0){
                ans=i+1;
                remain=0;
            }
            total+=gas[i]-cost[i];
        }
        return total<0 ? -1 : ans;
    }
};