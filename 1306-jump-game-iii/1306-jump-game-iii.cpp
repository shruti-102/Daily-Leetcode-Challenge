class Solution {
public:
    bool solve(vector<int>& arr,int start){
        if(start<0) return false;
        if(start>=arr.size()) return false;
        if(arr[start]<0) return false;
        if(arr[start]==0) return true;
        int val=arr[start];
        arr[start]=-1;
        return solve(arr,start-val) || solve(arr,start+val);
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(arr,start);
    }
};