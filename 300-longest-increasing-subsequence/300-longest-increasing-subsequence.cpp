class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            if(lower_bound(res.begin(),res.end(),nums[i])==res.end())
            {
                res.push_back(nums[i]);
            }
            else
            {
                auto it=lower_bound(res.begin(),res.end(),nums[i]);
                res[it-res.begin()]=nums[i];
                
            }
            
        }
        return res.size();
    }
};