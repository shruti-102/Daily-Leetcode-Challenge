class Solution {
public:
    vector<vector<int>> res;
    
    void generate(int i,vector<int>& subset,vector<int>& nums,int n)
    {
        if(i==n)
        {
            res.push_back(subset);
            subset.pop_back();
            return;
        }
        subset.push_back(nums[i]);
        generate(i+1,subset,nums,n);
        generate(i+1,subset,nums,n);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        generate(0,temp,nums,nums.size());
        return res;
    }
};