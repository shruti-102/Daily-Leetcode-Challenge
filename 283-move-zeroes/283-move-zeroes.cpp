class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=-1,e=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                s=i;
                break;
            }
        }
        if(s==-1) return;
        int i=0;
        while(i<nums.size() && s<nums.size())
        {
            if(nums[i]!=0 && s<i)
            {
                
                swap(nums[i],nums[s]);
                s++;
            }
            i++;
        }
    }
};