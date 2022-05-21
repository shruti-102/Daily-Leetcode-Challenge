class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,minbuy=prices[0];
        int n=prices.size();
        int prevprofit=0,curprofit=0;
        
        for(int i=1;i<n;i++)
        {
            minbuy=min(minbuy,prices[i]);
            curprofit=max(prevprofit,prices[i]-minbuy);
            prevprofit=curprofit;
        }
        return curprofit;;
    }
};