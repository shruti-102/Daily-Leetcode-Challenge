class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int cursum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cursum=max(cursum+nums[i],nums[i]);
            if(cursum>maxsum)
            {
                maxsum=cursum;
            }
            if(cursum<0)
            {
                cursum=0;
            }
        }
        return maxsum;
    }
};