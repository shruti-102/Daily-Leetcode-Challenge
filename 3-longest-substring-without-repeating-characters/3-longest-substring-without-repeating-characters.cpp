class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> mp(256,-1);
        int start=-1,maxlen=0;
        if(s.length()==1)
            return 1;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]>start)
            {
                start=mp[s[i]];
            }
            mp[s[i]]=i;
            maxlen=max(maxlen,i-start);
        }
        return maxlen;
    }
};