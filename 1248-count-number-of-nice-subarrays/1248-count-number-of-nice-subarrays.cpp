class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        int count = 0;
        unordered_map<int,int> mp;
        int prefSum = 0;
        mp[0] = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            prefSum += nums[i];
            if(mp[prefSum - k])
            {
                count += mp[prefSum - k];
            }
            mp[prefSum]++;
        }
        return count;
    }
};