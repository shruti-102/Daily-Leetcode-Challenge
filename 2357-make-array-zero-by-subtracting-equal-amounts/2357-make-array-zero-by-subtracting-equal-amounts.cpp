class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minop=0,minval=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && nums[i]<minval) minval=nums[i];
        }
        cout<<minval;
        while(true){
            int count=0;
            for(int i=0;i<n;i++){
                if(nums[i]!=0) count++;
            }
            if(count==0) break;
            int newmin=INT_MAX;
            for(int i=0;i<n;i++){
                if(nums[i]>0) {
                    nums[i]=nums[i]-minval;
                    if(nums[i]>0) newmin=min(newmin,nums[i]);
                }
            }
            minval=newmin;
            minop++;
        }
        return minop;
    }
};