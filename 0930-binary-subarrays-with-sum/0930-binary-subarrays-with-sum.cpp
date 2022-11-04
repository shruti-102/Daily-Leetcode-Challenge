class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        
        int start=0,end=0,pre=0,sum=0,ans=0;
        
        while(end<nums.size())
        {
            if(nums[end]==1)
            {
                sum++;
            }
            
            if(sum>goal)
            {
                while(nums[start]!=1)
                {
                    start++;
                }
                start++;
                pre=0;
                sum--;
            }
            
            while(start<end&&nums[start]==0)
            {
                pre++;
                start++;
            } 
            
            if(sum==goal&&start<=end)
               ans+=pre+1;
            end++;
        }
        
        
        return ans;
        
    }
    
};