class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> mp(256,-1);
        int n=s.size();
        if(n==0 || n==1) return n;
        int left=-1,maxlen=0;
        for(int right=0;right<n;right++)
        {
            if(mp[s[right]] > left)  //means that repeated element is in the range[left,right]
            {
                left=mp[s[right]];
                
            }
            
            mp[s[right]]=right;
            maxlen=max(maxlen,right-left);
        }
        
        return maxlen;
    }
};