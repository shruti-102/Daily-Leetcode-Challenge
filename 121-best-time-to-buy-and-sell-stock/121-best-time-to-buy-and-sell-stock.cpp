class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,minbuy=prices[0];
        int n=prices.size();
        vector<int> dp(n,0);
        
        for(int i=1;i<n;i++)
        {
            minbuy=min(minbuy,prices[i]);
            dp[i]=max(dp[i-1],prices[i]-minbuy);
        }
        return dp[n-1];
    }
};