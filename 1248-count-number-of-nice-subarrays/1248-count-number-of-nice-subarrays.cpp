class Solution {
public:
    
    int atmost (vector<int>& arr, int k){
        if(arr.size()==0)
            return 0 ;
        int ans = 0;
        int j= 0;
        int count = 0;
        for ( int i =0;i<arr.size();i++){
            if(arr[i]&1){
                count++;
            }
            while(count>k){
                if(arr[j]&1)
                    count--;
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& v, int k) {
        return atmost(v,k)-atmost(v,k-1);
    }
};