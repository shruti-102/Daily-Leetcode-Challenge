class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        int j=0,maxwin=0;
        for(int i=0;i<n;i++)
        {
            while((target & nums[i]) != 0)
            {
                //we have to keep removing number from back till there is problem
                target^=nums[j++];
            }
            target |=nums[i];
            maxwin=max(maxwin,i-j+1);
        }
        return maxwin;
    }
};