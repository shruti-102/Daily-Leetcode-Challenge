class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int take=nums[0];
        int nottake=0;
        for(int i=1;i<n;i++)
        {
            int newtake=nottake+nums[i];
            int newnottake=max(take,nottake);
        
            take=newtake;
            nottake=newnottake;
        }
    
        return max(take,nottake);
    }
};