class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,h=n-1,mid;
        while(l<=h){
            mid=(l+h)/2;
            int val=arr[mid]-(mid+1);
            if(val<k) {
                l=mid+1;
            }
            else h=mid-1;
        }
        return l+k;
    }
};