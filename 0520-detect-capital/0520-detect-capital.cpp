class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int caps=0,lower=0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z') caps++;
            else lower++;
        }
        if(caps==n) return true;
        if(lower==n) return true;
        if(word[0]>='A' && word[0]<='Z' && lower==n-1) return true;
        return false;
    }
};