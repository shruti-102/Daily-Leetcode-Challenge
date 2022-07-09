class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
        unordered_set<int> hashset;
        int left=0;
        int maxlen=0;
        for(int right=0;right<n;right++)
        {
            if(hashset.count(s[right]))
            {
                while(left<right && hashset.find(s[right])!=hashset.end()) //jb tk wo repeated character remove n ho jata
                {
                    hashset.erase(s[left]);
                    left++;
                }
            }
            hashset.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};