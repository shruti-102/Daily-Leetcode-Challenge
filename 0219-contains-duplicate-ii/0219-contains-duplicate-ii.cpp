class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int i = 0, j = 0, sz = nums.size();
        unordered_set<int> uset ;
        
        while(j<sz)
        {   
            if(j-i > k){uset.erase(nums[i]) ; i++ ;}
            
            if(uset.count(nums[j]) > 0){return true ;}
            uset.insert(nums[j]) ;
            j++ ;
        }
        return false ;
    }
};