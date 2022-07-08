class Solution {
public:
    int merge(vector<int> &nums,int low,int mid,int high)
    {
        int count=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]>2ll*nums[j]){
                j++;
            }
            count+=(j-(mid+1));
        }
        
        vector<int> temp;
        int i=low;
        j=mid+1;
        
        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
            
        }
        while(i<=mid)
        {
            temp.push_back(nums[i++]);
        }
        while(j<=high)
        {
            temp.push_back(nums[j++]);
        }
        
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
        return count;
    }
    int divide(vector<int>& nums,int low,int high)
    {
          if (low >= high) return 0;
          int mid = (low + high) / 2;
          int inv = divide(nums, low, mid);
          inv += divide(nums, mid + 1, high);
          inv += merge(nums, low, mid, high);
          return inv;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return divide(nums,0,n-1);
    }
};