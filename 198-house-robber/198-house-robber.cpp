class Solution {
public:
    int rob(vector<int>& nums) {
        int take=nums[0];
        int nottake=0;
        
        for(int i=1;i<nums.size();i++)
        {
            int newnottake=max(take,nottake);
            int newtake=nottake+nums[i];
            take=newtake;
            nottake=newnottake;
        }
        return max(take,nottake);
    }
};