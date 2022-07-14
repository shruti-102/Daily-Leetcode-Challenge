class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        string ans="";
        int maxlen=INT_MIN;
        for(int diff=0;diff<n;diff++)
        {
            for(int i=0,j=i+diff;j<n;i++,j++)
            {
                if(i==j)    //diagonal;
                {
                    dp[i][j]=1;
                }
                
                else if(diff==1) //two elements can only be pallindrome if they both are same
                {
                   // dp[i][j]=s[i]==s[j]?2:0;
                    if(s[i]==s[j] && dp[i][j-1]!=0)
                    {
                        dp[i][j]=2;
                    }
                }
                else if(s[i]==s[j] && dp[i+1][j-1]!=0)
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                if(dp[i][j]!=0)
                {
                    if(dp[i][j]>maxlen)
                    {
                        maxlen=dp[i][j];
                        ans=s.substr(i,maxlen);
                    }
                }
            }
        }
        return ans;
        
    }
};