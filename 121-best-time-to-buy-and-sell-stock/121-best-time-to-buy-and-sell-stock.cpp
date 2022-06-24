class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n);
        dp[0]=0;
        int minbuy=prices[0];
        int maxprofit=INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            int profit=prices[i]-minbuy;
            if(profit<=dp[i-1])
            {
                dp[i]=dp[i-1];
            }
            else
            {
                dp[i]=profit;
            }
            minbuy=min(minbuy,prices[i]);
        }
        
        return dp[n-1];
    }
};