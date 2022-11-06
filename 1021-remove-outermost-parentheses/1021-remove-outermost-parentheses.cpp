class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int st=0,score=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='(') score+=1;
            else if(s[i]=')') score-=1;
            
            if(score==0){
                for(int k=st+1;k<i;k++){
                    ans+=s[k];
                }
                st=i+1;
            }
        }
        return ans;
    }
};