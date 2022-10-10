class Solution {
public:
    bool ispallindrome(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    string breakPalindrome(string palin) {
        int n=palin.size();
        if(n==1) return "";
        int i;
        string newpalin=palin;
        for(i=0;i<n;i++){
            if(palin[i]!='a'){
                newpalin[i]='a';
                break;
            }
        }
        if(ispallindrome(newpalin) || i==n) {
            palin[n-1]='b';
            newpalin=palin;
        }
        return newpalin;
    }
};