class Solution {
public:
    void solve(set<vector<int>>& ans,vector<int>& temp,vector<int>& nums,int i){
        if(i>=nums.size()){
            if(temp.size()>=2) ans.insert(temp);
            return;
        }
        if(temp.size()==0 || nums[i]>=temp.back()){
            temp.push_back(nums[i]);
            solve(ans,temp,nums,i+1);
            temp.pop_back();
        }
        solve(ans,temp,nums,i+1);
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,nums,0);
        return vector(ans.begin(),ans.end());
    }
};