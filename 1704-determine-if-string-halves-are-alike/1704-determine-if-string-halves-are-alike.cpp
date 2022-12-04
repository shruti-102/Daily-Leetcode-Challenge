class Solution {
public:
    int countvow(string str){
        int n=str.size(),count=0;
        
        for(int i=0;i<n;i++){
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        if(n%2!=0) return false;
        string s1="",s2="";
        int i;
        for(i=0;i<n/2;i++){
            s1+=s[i];
        }
        for(i=n/2;i<n;i++){
            s2+=s[i];
        }
        if(countvow(s1)==countvow(s2)) return true;
        return false;
    }
};