class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v(strs.size(),vector<int>(2));
        int x=strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            int count0=0,count1=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='0') count0++;
                else count1++;
            }
            v[i][0]=count0;
            v[i][1]=count1;
        }
        
        for(int i=0;i<x;i++)
        {
            int countzero=v[i][0];
            int countone=v[i][1];
            
            for(int zero=m;zero>=countzero;zero--)
            {
                for(int one=n;one>=countone;one--)
                {
                    dp[zero][one]=max(dp[zero-countzero][one-countone]+1,dp[zero][one]);
                }
            }
        }
        return dp[m][n];
    }
};