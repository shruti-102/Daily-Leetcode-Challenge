class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> dp(n,1);
        int leftsum=0;
        for(int i=0;i<n;i++)
        {
            int l=1,r=1;
            if(i+1<n && ratings[i]>ratings[i+1])
            {
                r=dp[i+1]+1;
            }
            if(i-1>=0 && ratings[i]>ratings[i-1])
            {
                l=dp[i-1]+1;
            }
            dp[i]=max(l,r);
            leftsum+=dp[i];
        }
       // for(int i=0;i<n;i++) dp[i]=1;
        int rightsum=0;
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
            rightsum+=dp[i];
        }
        
        return max(leftsum,rightsum);
    }
};