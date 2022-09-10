class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        if(n<2) return 0;
        for(int i=1;i<=k;i++)
        {
            int maxprice=INT_MIN;
            for(int j=1;j<n;j++)
            {
                //minprice=min(minprice,prices[j]);
                int k=dp[i-1][j-1]-prices[j-1];
                if(k>maxprice)
                {
                    maxprice=k;
                }
                if(maxprice+prices[j]>dp[i][j-1])
                {
                    dp[i][j]=maxprice+prices[j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
       
        return dp[k][n-1];
    }
};