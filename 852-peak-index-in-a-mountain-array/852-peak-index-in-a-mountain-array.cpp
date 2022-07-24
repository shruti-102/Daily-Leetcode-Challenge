class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,h=arr.size()-1;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(mid-1>=0 && mid+1<arr.size() && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            //increasing
            else if(arr[mid]<arr[mid+1]) l=mid+1;
            else h=mid-1;
        }
        return 0;
    }
};