class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mp;
        int s1=0,s2=0;
        vector<int> ans;
        for(int i=0;i<b.size();i++){
            mp[b[i]]=i;
        }
        for(int i=0;i<a.size();i++){
            s1+=a[i];
        }
        for(int i=0;i<b.size();i++){
            s2+=b[i];
        }
        int t=(s1+s2)/2,flag=0;
        for(int i=0;i<a.size();i++){
            int rem=s1-a[i];
            rem=t-rem;
            if(mp.find(rem)!=mp.end()){
                int j=mp[rem];
                ans.push_back(a[i]);
                ans.push_back(b[j]);
                flag=1;
            }
            if(flag==1) break;
        }
        return ans;
    }
};