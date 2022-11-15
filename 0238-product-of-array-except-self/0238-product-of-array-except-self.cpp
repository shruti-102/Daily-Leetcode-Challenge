class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long int pro=1;
        int newpro=1,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count++;
        }
        if(count==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0) newpro*=nums[i];
            }
        }
        
        for(int i=0;i<nums.size();i++){
            pro*=nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            if(count==1 && nums[i]==0) nums[i]=newpro;
            else if(nums[i]==0 && count>1) nums[i]=0;
            else nums[i]=pro/nums[i];
        }
        return nums;
    }
};