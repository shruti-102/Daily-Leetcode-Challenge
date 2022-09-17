class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int range=0+nums[0];
        
        for(int i=0;i<=range;i++)
        {
            range=max(range,nums[i]+i);
            if(range>=nums.size()-1) return true;
        }
        if(range>=nums.size()-1) return true;
        return false;
    }
};