class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int val;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) val=nums[i]*-1;
            else val=nums[i];
            nums[val]=nums[val]*-1;
            if(nums[val]>0)
            {
                if(nums[i]>0) return nums[i];
                else return nums[i]*-1;
            }
        }
        return 0;
    }
};