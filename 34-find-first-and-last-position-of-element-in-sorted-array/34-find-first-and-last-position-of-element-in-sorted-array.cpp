class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0]=INT_MAX;
        res[1]=INT_MIN;
        
        //first indx
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                if(res[0]>mid) res[0]=mid;
                h=mid-1;
            }
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        
        l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                if(res[1]<mid)
                {
                    res[1]=mid;
                    l=mid+1;
                }
            }
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        
        if(res[0]==INT_MAX && res[1]==INT_MIN)
        {
            return {-1,-1};
        }
        return res;
    }
};