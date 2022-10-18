class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int left=INT_MIN,right=INT_MIN;
            if(i==0){
                if(i+1<n) right=nums[i+1];
            }
            else if(i==n-1){
                if(i-1>=0) left=nums[i-1];
            }
            else{
                if(i-1>=0) left=nums[i-1];
                if(i+1<n) right=nums[i+1];
            }
            if(nums[i]>left && nums[i]>right) return i;
        }
        return 0;
    }
};