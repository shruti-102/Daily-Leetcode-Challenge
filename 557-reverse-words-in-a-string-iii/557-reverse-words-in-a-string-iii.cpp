class Solution {
public:
    string reverseWords(string s) {
        string ans="",temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') temp+=s[i];
            else
            {
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=" ";
                temp="";
            }
        }
        temp="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ') temp+=s[i];
            else break;
        }
        ans+=temp;
        return ans;
    }
};