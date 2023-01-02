class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int caps=0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z') caps++;
        }
        if(caps==n || n-caps==n) return true;
        if(word[0]>='A' && word[0]<='Z' && n-caps==n-1) return true;
        return false;
    }
};