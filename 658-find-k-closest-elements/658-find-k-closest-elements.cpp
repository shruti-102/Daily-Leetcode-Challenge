class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        auto indx=arr.begin();
        indx=lower_bound(arr.begin(),arr.end(),x);
        int h=indx-arr.begin();
        //vector<int> ans;
        int l=h-1;
        cout<<h<<" "<<l;
        
        while(k--){
            if(h>=n || l>=0 && x-arr[l]<=arr[h]-x) l--;
            else h++;
        }
        return vector<int>(begin(arr) + l + 1, begin(arr) + h);
            
    }
};