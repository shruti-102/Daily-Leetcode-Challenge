class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> w1(26,0);
        vector<int> w2(26,0);
        vector<int> s1(26,0);
        vector<int> s2(26,0);
        //string s1="",s2="";
        for(int i=0;i<word1.size();i++){
            w1[word1[i]-'a']++;
            if(s1[word1[i]-'a'] == 0 ) s1[word1[i]-'a'] ++;
        }
        
        for(int i=0;i<word2.size();i++){
            w2[word2[i]-'a']++;
          if(s2[word2[i]-'a'] == 0 ) s2[word2[i]-'a'] ++;
        }
        
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        
        
        
        if(w1==w2 && s1==s2) return true;
        return false;
    }
};