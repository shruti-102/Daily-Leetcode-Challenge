class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            if(i+1<n && ratings[i]>ratings[i+1])
            {
                dp[i]=dp[i+1]+1;
            }
            if(i-1>=0 && ratings[i]>ratings[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
        }
        
        int leftsum=0;
        for(int i=0;i<n;i++)
        {
            leftsum+=dp[i];
        }
        dp.clear();
        for(int i=n-1;i>=0;i--)
        {
            int left=1,right=1;
            if(i+1<n && ratings[i]>ratings[i+1])
            {
                right=dp[i+1]+1;
            }
            if(i-1>=0 && ratings[i]>ratings[i-1])
            {
                left=dp[i-1]+1;
            }
            
            dp[i]=max(left,right);
        }
        int rightsum=0;
        for(int i=0;i<n;i++)
        {
            rightsum+=dp[i];
        }
        return max(leftsum,rightsum);
    }
};