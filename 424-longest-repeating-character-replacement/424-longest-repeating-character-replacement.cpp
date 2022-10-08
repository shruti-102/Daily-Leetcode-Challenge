class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i=0,j=0,ans=-1,maxfreq=0,n=s.length();
        while(j<n){
            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);
            int len=j-i+1;
            if(i<j && len-maxfreq>k){
                mp[s[i]]--;
                i++;
            }
            len=j-i+1;
            ans=max(ans,len);
            j++;
        }
        return ans;
    }
};