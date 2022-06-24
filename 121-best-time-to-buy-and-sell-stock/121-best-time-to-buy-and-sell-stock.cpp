class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int minbuy=prices[0];
        int maxprofit=0;
        
        for(int i=1;i<n;i++)
        {
            int profit=prices[i]-minbuy;
            if(maxprofit<profit)
            {
                maxprofit=profit;
            }
            minbuy=min(minbuy,prices[i]);
        }
        
        return maxprofit;
    }
};