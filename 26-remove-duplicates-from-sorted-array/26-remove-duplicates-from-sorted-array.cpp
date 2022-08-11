class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1,n=nums.size();
        if(n==1) return 1;
        
        while(j<n)
        {
            if(nums[j]==nums[i]) j++;
            else
            {
                nums[i+1]=nums[j];
                i=i+1;
                j+=1;
            }
        }
        return i+1;
    }
};