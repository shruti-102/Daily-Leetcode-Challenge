class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int totalsum=0,ksum=INT_MIN,csum=0;
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            if(csum>ksum) ksum=csum;
            if(csum<0) csum=0;
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) c++;
            totalsum+=nums[i];
        }
        int maxval=INT_MIN;
        if(c==nums.size()){
            for(int i=0;i<nums.size();i++){
                maxval=max(maxval,nums[i]);
            }
            return maxval;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*-1;
        }
        int cursum=0,maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(cursum>maxsum) maxsum=cursum;
            if(cursum<0) cursum=0;
        }
        cout<<maxsum;
        maxsum=maxsum*-1;
        return max(ksum,totalsum-(maxsum));
    }
};