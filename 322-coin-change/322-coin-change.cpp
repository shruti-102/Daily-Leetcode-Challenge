class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1));
        
        if(n==1 && amount%coins[0]!=0) return -1;
            
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        
        
        for(int j=0;j<amount+1;j++)
        {
            if(j%coins[0]==0) dp[0][j]=j/coins[0];
            else dp[0][j]=INT_MAX-1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(j<coins[i]) dp[i][j]=dp[i-1][j];
                else
                {
                    dp[i][j]=min(0+dp[i-1][j],1+dp[i][j-coins[i]]);
                }
            }
        }
        
        int num=dp[n-1][amount];
        if(num==INT_MAX-1) return -1;
        return num;
    }
    
};