class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int n1=strs[0].size();
        int n2=strs[n-1].size();
        string s1=strs[0];
        string s2=strs[n-1];
        string ans="";
        for(int i=0;i<min(n1,n2);i++){
            if(s1[i]==s2[i]) ans+=s1[i];
            else break;
        }
        return ans;
    }
};