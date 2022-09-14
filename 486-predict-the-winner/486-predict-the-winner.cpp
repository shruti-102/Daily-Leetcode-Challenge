class Solution {
public:
    
   // consider 1 -> player1
   // consider -1 -> player2
    int solve(vector<int>& nums,int s,int e,int player,vector<vector<int>>& dp)
    {
        if(s==e) return dp[s][e]=player*nums[s];
        
        if(dp[s][e]!=INT_MAX) return dp[s][e];
        
        int choice1=player* nums[s]+ solve(nums,s+1,e,player*-1,dp);
        int choice2=player*nums[e]+solve(nums,s,e-1,player*-1,dp);
        
        if(player<0) dp[s][e]=min(choice1,choice2);
        else dp[s][e]=max(choice1,choice2);
        
        return dp[s][e];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        if(solve(nums,0,n-1,1,dp)>=0) return true;
        return false;
    }
};