class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<h)
        {
            int mid=(h+l)/2;
            if(nums[mid]==nums[mid-1])
            {
                if(abs(l-(mid-1))%2 != 0)
                {
                    h=mid-2;
                }
                else
                {
                    l=mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1])
            {
                if(abs(h-(mid+1))%2 != 0)
                {
                    l=mid+2;
                }
                else
                {
                    h=mid-1;
                }
            }
            else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
        }
        if(l==h) return nums[l];
        return 0;
    }
};