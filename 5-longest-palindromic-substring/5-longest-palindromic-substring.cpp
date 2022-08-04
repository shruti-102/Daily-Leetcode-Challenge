class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(s.size(),vector<int>(n,0));
        int start=0,len=0;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(gap==0)
                {
                    start=i;
                    len=1;
                    dp[i][j]=1;
                }
                else if(gap==1 && s[i]==s[j])
                {
                    dp[i][j]=1;
                    start=i;
                    len=2;
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        start=i;
                        len=j-i+1;
                    }
                }
            }
        }
        return s.substr(start,len);
    }
};