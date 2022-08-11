class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans=0;
        int prefix=0,rem=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            rem=prefix%k;
            if(rem<0) rem+=k;
            
            if(mp.find(rem) != mp.end())
            {
                ans+=mp[rem];
                mp[rem]++;
            }
            else
            {
                mp[rem]++;
            }
        }
        return ans;
    }
};