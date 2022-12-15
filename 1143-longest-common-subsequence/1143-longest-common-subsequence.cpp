class Solution {
public:
    int longestCommonSubsequence(string txt1, string txt2) {
        int n1=txt1.size();
        int n2=txt2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(txt1[i-1]==txt2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n1][n2];
    }
};