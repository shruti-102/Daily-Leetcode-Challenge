class Solution {
public:
   
    int solve(int floors,int eggs,vector<int>& dp)
    {
        if(floors==0) return dp[floors]=0;
        if(floors==1) return dp[floors]=1;
         int ans=INT_MAX;
        
        if(dp[floors] != -1) return dp[floors];
        
        for(int i=1;i<=floors;i++)
        {
            int val= max(i-1,solve(floors-i,2,dp))+1;
            ans=min(ans,val);
            
        }
        return dp[floors]=ans;
    }
    int twoEggDrop(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,2,dp);
    }
};