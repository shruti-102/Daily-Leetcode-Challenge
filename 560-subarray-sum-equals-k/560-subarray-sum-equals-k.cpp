class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int prefix=nums[0];
        mp[prefix]++;
        int count=0;
        if(prefix==k) count++;
        for(int i=1;i<n;i++)
        {
            prefix=prefix+nums[i];
            if(prefix==k) count++;
            if(mp.find(prefix-k)!=mp.end())
            {
                count+=mp[prefix-k];
            }
            mp[prefix]++;
        }
        return count;
    }
};