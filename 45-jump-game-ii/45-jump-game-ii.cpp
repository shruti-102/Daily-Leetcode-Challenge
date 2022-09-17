class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        
        int l=0,r=0,n=nums.size(),jump=0;
        if(nums[0]+0>=n-1) return 1;
        while(r<n-1)
        {
            int maxrange=0;
            for(int i=l;i<=r;i++)
            {
                maxrange=max(maxrange,nums[i]+i);
            }
            l=r+1;
            r=maxrange;
            jump++;
            
        }
        return jump;
        
    }
};