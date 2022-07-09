class Solution {
public:
    #define lll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        
        for(lll i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            lll temp=target-nums[i];
            
            for(lll j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                lll s=temp-nums[j];
                
                lll l=j+1,h=n-1;
                while(l<h)
                {
                    lll sum=nums[l]+nums[h];
                    if(sum==s)
                    {
                        v.push_back({nums[i],nums[j],nums[l],nums[h]});
                        
                        while(l<n-1 && nums[l]==nums[l+1]) l++;
                        while(h>0 && nums[h]==nums[h-1]) h--;
												l++;
												h--;
												
                    }
                    else if(sum>s) h--;
                    else if(sum<s) l++;
                } 
            }
        }
        return v;
    }
    
};