class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> div(n,1);
        vector<int> prev(n,-1);
        vector<int> ans;
        int maxdivindx=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]%nums[i]==0)
                {
                    if(div[i]<div[j]+1) {
                        div[i]=div[j]+1;
                        prev[i]=j;
                    }
                }
            }
            
            if(div[maxdivindx]<div[i]) maxdivindx=i;
        }
        int i=maxdivindx;
        while(i>=0)
        {
            ans.push_back(nums[i]);
            i=prev[i];
        }
        return ans;
    }
};