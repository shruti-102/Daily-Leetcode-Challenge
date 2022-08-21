class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& a) {
        int n=s.size();
        vector<int>pre(n+1,0);
        for(auto it:a)
        {
            if(it[2])   //backward direction
            {
                pre[it[0]]++;
                pre[it[1]+1]--;
            }
            else
            {
                 pre[it[0]]--;
                pre[it[1]+1]++;
            }
        }
        for(int i=1;i<n;i++){
            pre[i] +=pre[i-1];
        }
        for(int i=0;i<s.size();i++){
            int j=s[i]-'a';
            
            j=(j+pre[i])%26;
            j=(j+26)%26;
            s[i] = ('a'+j);
        }
        return s;
    }
};