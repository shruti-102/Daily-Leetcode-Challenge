class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0;
        int ans=INT_MIN;
        
        //calculate max ele of the array
        for(int i=0;i<n;i++)
        {
            ans=max(ans,nums[i]);
        }
        
        //pq for getting max previous dp soln in window k
        priority_queue <pair<int,int>> pq;
        pq.push({nums[0],0});
        
        for(int i=1;i<n;i++)
        {
            //pop until the window sie is not satisfy
            while(i-pq.top().second>k)
            {
                pq.pop();
            }
            dp[i]=max(nums[i],nums[i]+pq.top().first);
            pq.push({dp[i],i});
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};