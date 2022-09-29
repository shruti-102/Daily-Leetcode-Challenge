class Solution {
public:
    unordered_map<string,int> mp;
    
    
    bool solve(string s,unordered_map<string,bool>& dp){
        if(mp.find(s)!=mp.end()) return true;
        if(dp.find(s)!=dp.end()) return dp[s];
        int n=s.size();
        for(int i=1;i<=n;i++){
            string temp=s.substr(0,i);
            if(mp.find(temp)!=mp.end() && solve(s.substr(i,n-i),dp)) return dp[s]=true;
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict){
            mp[word]++;
        }
        unordered_map<string,bool> dp;
        return solve(s,dp);
    }
};