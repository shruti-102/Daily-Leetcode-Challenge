class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        
        string ans="";
        if(n==1) return strs[0];
        
        sort(strs.begin(),strs.end());
        
        int i=0,j=0;
        
        while(i<strs[0].size() && j<strs[n-1].size())
        {
            if(strs[0][i]!=strs[n-1][j]) return ans;
            ans+=strs[0][i];
            i++;
            j++;
        }
        return ans;
    }
};