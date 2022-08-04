class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        
        int left=0,right=0,len=0;
        int maxlen=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]]!=-1)  //means already exist
            {
                left=max(mp[s[i]]+1,left);
            }
            mp[s[i]]=i;
            maxlen=max(maxlen,i-left+1);
        }
        return maxlen;
    }
};