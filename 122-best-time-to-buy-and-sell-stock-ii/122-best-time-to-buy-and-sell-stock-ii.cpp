class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmoney=prices[0];
        int n=prices.size();
        vector<int> dp(n,0);
        
        for(int i=1;i<n;i++)
        {
            //agar mjh km paiso ka stock mil rha h to m usi ko khridugi na
            if(prices[i]<curmoney)
            {
                curmoney=prices[i];
                dp[i]=dp[i-1];
            }
            
            else
            {
               int newprofit = prices[i]-curmoney;
                dp[i]=dp[i-1]+newprofit;
                curmoney=prices[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<dp[i]<<" ";
        }cout<<endl;
        return dp[n-1];
    }
};